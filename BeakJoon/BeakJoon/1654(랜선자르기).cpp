#include <iostream>
#include <algorithm>
#include <limits.h>


using namespace std;

using ll = long long; // �����÷ο� ���� long longŸ�� ���

ll K, N, moon = 0;

ll lan[10000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	//1. K�� N�� �Է�
	cin >> K >> N;

	//2. K�ٿ� ���� ������ ���� �Է�

	for (ll i = 0; i < K; ++i)
	{
		cin >> lan[i];

		if (lan[i] > moon)
		{
			moon = lan[i];
		}
	}

	//3. ó��(�����˻�)
	// ���� : �ڸ� �� �ִ� ������ ����
	// [1, 458)
	ll s = 1;
	ll e = moon + 1;

	//������ ���� ��
	ll result = 0;

	while (s < e)
	{
		// �ذ� �� �� �ִ� �ĺ�
		ll m = (s + e) / 2;

		ll count = 0;

		for (ll i = 0; i < K; ++i)
		{
			count += (lan[i] / m);
		}

		// �ذ� �� ���
		if (count >= N)
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

}