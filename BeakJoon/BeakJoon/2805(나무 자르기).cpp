#include <iostream>
#include <limits.h>

using namespace std;

using ll = long long;

// N : 나무의 수, M : 나무의 길이
ll N, moon, H = 0;

ll tree[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	//1. N, M입력
	cin >> N >> moon;

	//2. 나무의 높이 입력
	for (ll i = 0; i < N; ++i)
	{
		cin >> tree[i];
		
		if (H < tree[i])
		{
			H = tree[i];
		}
	}

	//3. 처리 이진탐색
	//범위 : 나무를 자를 수 있는 범위
	// [1, 나무의 최대높이]
	ll s = 0;
	ll e = H + 1;

	//문제의 결과값이 될 수 있는 것
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