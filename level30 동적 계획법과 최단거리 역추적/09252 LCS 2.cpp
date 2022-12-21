#include <iostream>
#include <string>
#include <cstring>

#define MAX_LENGTH 1000

char* dpString[MAX_LENGTH + 1][MAX_LENGTH + 1];
int dpCount[MAX_LENGTH + 1][MAX_LENGTH + 1];

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	std::string input1;
	std::string input2;

	std::cin >> input1;
	std::cin >> input2;

	size_t input1Length = input1.length();
	size_t input2Length = input2.length();

	for (size_t i = 1; i <= input1Length; ++i)
	{
		for (size_t j = 1; j <= input2Length; ++j)
		{
			if (input1[i - 1] == input2[j - 1] && dpCount[i - 1][j - 1] + 1 > dpCount[i][j - 1] && dpCount[i - 1][j - 1] + 1 > dpCount[i - 1][j])
			{
				char* newString = (char*)malloc(sizeof(char) * (dpCount[i - 1][j - 1] + 2));

				if (dpString[i - 1][j - 1] != nullptr)
				{
					memcpy(newString, dpString[i - 1][j - 1], dpCount[i - 1][j - 1]);
				}

				newString[dpCount[i - 1][j - 1]] = input1[i - 1];
				newString[dpCount[i - 1][j - 1] + 1] = '\0';

				dpString[i][j] = newString;
				dpCount[i][j] = dpCount[i - 1][j - 1] + 1;
			}
			else
			{
				if (dpCount[i][j - 1] > dpCount[i - 1][j])
				{
					dpString[i][j] = dpString[i][j - 1];
					dpCount[i][j] = dpCount[i][j - 1];
				}
				else
				{
					dpString[i][j] = dpString[i - 1][j];
					dpCount[i][j] = dpCount[i - 1][j];
				}
			}
		}
	}

	int length = dpCount[input1Length][input2Length];
	printf("%d\n", length);

	if (length > 0)
	{
		printf("%s", dpString[input1Length][input2Length]);
	}
}
