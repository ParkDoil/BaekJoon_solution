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
		// 명령어 입력부
		string order;
		cin >> order;

		// 배열 숫자 입력부
		int numCount;
		int size;
		cin >> numCount;
		size = numCount;

		// 문자열 입력&처리부
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

		// 명령어 처리부
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

		// 출력부
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