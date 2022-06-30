#include <iostream>
#include <limits.h>

using namespace std;

using ll = long long;

// N : ������ ��, M : ������ ����
ll N, moon, H = 0;

ll tree[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	//1. N, M�Է�
	cin >> N >> moon;

	//2. ������ ���� �Է�
	for (ll i = 0; i < N; ++i)
	{
		cin >> tree[i];
		
		if (H < tree[i])
		{
			H = tree[i];
		}
	}

	//3. ó�� ����Ž��
	//���� : ������ �ڸ� �� �ִ� ����
	// [1, ������ �ִ����]
	ll s = 0;
	ll e = H + 1;

	//������ ������� �� �� �ִ� ��
	ll result = 0;

	while (s < e)
	{
		ll m = (s + e) / 2;

		ll cutTree = 0;

		for (ll i = 0; i < N; ++i)
		{
			if (tree[i] - m >= 0)
			{
				cutTree += tree[i] - m;
			}
		}

		if (cutTree >= moon)
		{
			if (result < m)
			{
				result = m;
			}

			s = m + 1;
		}

		else
		{
			e = m;
		}
	}

	cout << result << "\n";

	return 0;
}