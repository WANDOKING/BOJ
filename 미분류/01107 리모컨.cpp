#include <iostream>
#include <cmath>

bool CanGoChannel(int channel, bool bBroken[], int* Out_ChannelLength)
{
	if (channel == 0)
	{
		*Out_ChannelLength = 1;
		return !bBroken[0];
	}

	*Out_ChannelLength = 0;

	while (channel > 0)
	{
		(* Out_ChannelLength)++;

		int num = channel % 10;
		channel /= 10;

		if (bBroken[num] == true)
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	int N;
	int M;
	bool bBroken[10] = { 0, };

	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int input;
		scanf("%d", &input);
		bBroken[input] = true;
	}

	int countButtonOnlyPlusMinus = abs(N - 100);

	int distance = 0;
	int nearestChannel = -1;
	int nearestChannelLength;
	while (distance < countButtonOnlyPlusMinus)
	{
		if (N - distance >= 0 && CanGoChannel(N - distance, bBroken, &nearestChannelLength) == true)
		{
			nearestChannel = N - distance;
			break;
		}

		if (CanGoChannel(N + distance, bBroken, &nearestChannelLength) == true)
		{
			nearestChannel = N + distance;
			break;
		}

		distance++;
	}

	if (countButtonOnlyPlusMinus < nearestChannelLength + distance)
	{
		printf("%d", countButtonOnlyPlusMinus);
	}
	else
	{
		printf("%d", distance + nearestChannelLength);
	}
}
