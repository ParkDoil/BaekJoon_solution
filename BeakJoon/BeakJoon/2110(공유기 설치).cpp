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
	
	// �Ͽ콺 ��ǥ�� ������� ����
	std::sort(house, house + houseCount);

	// �Ÿ��� ���� Ž��
	ll s = 1;
	ll e = house[houseCount - 1] + 1;
	ll result = 0;
	
	while (s <= e)
	{
		// ������ ������ �Ÿ� �ʱ�ȭ ��
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