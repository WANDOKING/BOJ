#include <iostream>
#include <cstring>

int main(void)
{
	const int MAX = 1000000;
	char input[MAX + 1];

	scanf("%s", input);

	int i = 0;

	int length = strlen(input);

	if (length == 1)
	{
		printf(input);
		return 0;
	}

	if (length % 3 == 2)
	{
		int temp = 0;
		if (input[i] == '1')
		{
			temp += 2;
		}
		i++;
		if (input[i] == '1')
		{
			temp += 1;
		}
		i++;

		printf("%d", temp);
	}
	else if (length % 3 == 1)
	{
		printf("1");
		i++;
	}

	int toSum = 4;
	int numToPrint = 0;

	while (input[i] != '\0')
	{
		if (input[i] == '1')
		{
			numToPrint += toSum;
		}

		toSum /= 2;

		if (toSum == 0)
		{
			printf("%d", numToPrint);
			toSum = 4;
			numToPrint = 0;
		}

		i++;
	}
}
