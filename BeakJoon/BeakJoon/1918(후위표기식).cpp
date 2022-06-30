#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    string expression;
    stack<char> MATH;
    cin >> expression;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= 'A' && expression[i] <= 'Z')
        {
            cout << expression[i];
        }
        else
        {
            if (expression[i] == '(')
            {
                MATH.push(expression[i]);
            }

            else if (expression[i] == '*' || expression[i] == '/')
            {
                while (!MATH.empty() && (MATH.top() == '*' || MATH.top() == '/'))
                {
                    cout << MATH.top();
                    MATH.pop();
                }
                MATH.push(expression[i]);
            }

            else if (expression[i] == '+' || expression[i] == '-')
            {
                while (!MATH.empty() && MATH.top() != '(')
                {
                    cout << MATH.top();
                    MATH.pop();
                }
                MATH.push(expression[i]);
            }

            else if (expression[i] == ')')
            {
                while (!MATH.empty() && MATH.top() != '(')
                {
                    cout << MATH.top();
                    MATH.pop();
                }
                MATH.pop();
            }
        }
    }

    while (!MATH.empty())
    {
        cout << MATH.top();
        MATH.pop();
    }

    return 0;
}