#include <iostream>
#include <algorithm>
#include <limits.h>


using namespace std;

using ll = long long; // 오버플로우 방지 long long타입 사용

ll K, N, moon = 0;

ll lan[10000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	//1. K와 N을 입력
	cin >> K >> N;

	//2. K줄에 걸쳐 랜선의 길이 입력

	for (ll i = 0; i < K; ++i)
	{
		cin >> lan[i];

		if (lan[i] > moon)
		{
			moon = lan[i];
		}
	}

	//3. 처리(이진검색)
	// 범위 : 자를 수 있는 랜선의 길이
	// [1, 458)
	ll s = 1;
	ll e = moon + 1;

	//문제에 대한 해
	ll result = 0;

	while (s < e)
	{
		// 해가 될 수 있는 후보
		ll m = (s + e) / 2;

		ll count = 0;

		for (ll i = 0; i < K; ++i)
		{
			count += (lan[i] / m);
		}

		// 해가 된 경우
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