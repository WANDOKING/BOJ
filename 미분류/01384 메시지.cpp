#include <iostream>

#define MAX_KID_COUNT 20
#define MAX_NAME_LENGTH 60

char names[MAX_KID_COUNT][MAX_NAME_LENGTH + 1];
char messages[MAX_KID_COUNT][MAX_KID_COUNT - 1];

int main(void)
{
	int groupNumber = 1;
	while (true)
	{
		int n;

		scanf("%d", &n);

		if (n == 0)
		{
			break;
		}

		for (int i = 0; i < n; ++i)
		{
			scanf("%s", names[i]);

			for (int j = 0; j < n - 1; ++j)
			{
				getchar();
				scanf("%c", &messages[i][j]);
			}
		}

		printf("Group %d\n", groupNumber++);
		bool bNobodyWasNasty = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - 1; ++j)
			{
				if (messages[i][j] == 'N')
				{
					bNobodyWasNasty = false;
					int badKidIndex = (i - 1 - j + n) % n;

					printf("%s was nasty about %s\n", names[badKidIndex], names[i]);
				}
			}
		}

		if (bNobodyWasNasty == true)
		{
			printf("Nobody was nasty\n");
		}

		printf("\n");
	}
}
