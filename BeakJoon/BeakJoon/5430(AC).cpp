#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

vector<int> arr;

int main()
{
	int testCase;
	cin >> testCase;

	for (int test = 0; test < testCase; ++test)
	{
		bool isError = false;
		bool isReverse = false;
		// ��ɾ� �Էº�
		string order;
		cin >> order;

		// �迭 ���� �Էº�
		int numCount;
		int size;
		cin >> numCount;
		size = numCount;

		// ���ڿ� �Է�&ó����
		string A;
		cin >> A;

		deque<int> dq;

		int i = 0;
		while (A[i] != '\0')
		{
			int num = 0;
			while (A[i] >= '0' && A[i] <= '9')
			{
				num *= 10;
				num += int(A[i] - '0');
				++i;
			}
			if (num != 0)
			{
				dq.push_back(num);
			}
			++i;
		}

		// ��ɾ� ó����
		int j = 0;
		while (order[j] != '\0')
		{
			if (order[j] == 'R')
			{
				isReverse = !isReverse;
			}
			else if (order[j] == 'D')
			{
				if (isReverse)
				{
					if (dq.empty() == false)
					{
						dq.pop_back();
					}
					--size;
					if (size < 0)
					{
						isError = true;
					}
				}
				else
				{
					if (dq.empty() == false)
					{
						dq.pop_front();
					}
					--size;
					if (size < 0)
					{
						isError = true;
					}
				}
			}
			++j;
		}

		// ��º�
		if (isError)
		{
			cout << "error\n";
		}
		else
		{
			if (isReverse)
			{
				cout << "[";
				while (dq.empty() == false)
				{
					cout << dq.back();
					dq.pop_back();
					if (dq.begin() != dq.end())
					{
						cout << ",";
					}
				}
				cout << "]\n";
			}
			else
			{
				cout << "[";
				while (dq.empty() == false)
				{
					cout << dq.front();
					dq.pop_front();
					if (dq.begin() != dq.end())
					{
						cout << ",";
					}
				}
				cout << "]\n";
			}
		}
	}
	


	return 0;
}