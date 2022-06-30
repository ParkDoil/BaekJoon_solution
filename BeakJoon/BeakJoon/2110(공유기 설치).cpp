#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll house[200000];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	ll houseCount, modemCount;
	cin >> houseCount >> modemCount;

	
	for (ll i = 0; i < houseCount; ++i)
	{
		cin >> house[i];
	}
	
	// 하우스 좌표를 순서대로 정렬
	std::sort(house, house + houseCount);

	// 거리를 이진 탐색
	ll s = 1;
	ll e = house[houseCount - 1] + 1;
	ll result = 0;
	
	while (s <= e)
	{
		// 공유기 개수와 거리 초기화 후
		ll iptimeCount = 1;
		ll prevhouse = house[0];
		ll m = (s + e) / 2;

		for (ll i = 0; i < houseCount; ++i)
		{
			if (house[i] - prevhouse >= m)
			{
				++iptimeCount;
				prevhouse = house[i];
			}
		}

		if (iptimeCount >= modemCount)
		{
			if (result < m)
			{
				result = m;
			}

			s = m + 1;
		}

		else
		{
			e = m - 1;
		}
	}

	cout << result << "\n";

	return 0;

}