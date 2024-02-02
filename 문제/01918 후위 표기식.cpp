#include <iostream>
#include <stack>
#include <string>

int main(void)
{
	std::string input;
	std::string result = "";

	std::cin >> input;

	std::stack<char> operators;

	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			result += input[i];
			continue;
		}

		switch (input[i])
		{
		case '(':
			operators.push(input[i]);
			break;
		case ')':
			while (operators.empty() == false)
			{
				char op = operators.top();
				operators.pop();

				if (op == '(')
				{
					break;
				}

				result += op;
			}
			break;
		case '*': case '/':
			while (operators.empty() == false)
			{
				char op = operators.top();

				if (op == '*' || op == '/')
				{
					result += op;
					operators.pop();
				}
				else
				{
					break;
				}
			}
			operators.push(input[i]);
			break;
		case '+': case '-':
			while (operators.empty() == false)
			{
				char op = operators.top();

				if (op == '+' || op == '-' || op == '*' || op == '/')
				{
					result += op;
					operators.pop();
				}
				else
				{
					break;
				}
			}
			operators.push(input[i]);
			break;
		}
	}

	// 스택에 남아있는 연산자들을 모두 꺼냄
	while (operators.empty() == false)
	{
		char op = operators.top();
		operators.pop();

		if (op == '(' || op == ')')
		{
			continue;
		}

		result += op;
	}

	std::cout << result;
}
