// 12015 가장 긴 증가하는 부분 수열 2과 거의 같은 문제 (소스코드도 같음)
#include <iostream>
#include <vector>

#define MAX_N 1000000

int g_nums[MAX_N];

int main(void)
{
	int N;

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> g_nums[i];
	}

	// binary search를 이용한 풀이
	// 이 때 얻어지는 result vector는 LIS 결과 수열이 아니다
	// 단순하게 result.size()로 길이만 보장하는 알고리듬

	std::vector<int> result;
	result.reserve(N);
	result.push_back(g_nums[0]);
	
	for (int i = 1; i < N; ++i)
	{
		int num = g_nums[i];

		int start = 0;
		int end = result.size() - 1;

		// 마지막 원소보다 새로운 값이 더 크면 맨 뒤에 삽입 (LIS 길이 += 1)
		if (result[end] < num)
		{
			result.push_back(num);
			continue;
		}

		// binary search로 교환할 위치를 찾는다
		bool bFind = false; // 같은 원소가 있다면 아무것도 하지 않을 것
		while (start <= end)
		{
			int mid = (start + end) / 2;

			if (result[mid] == num)
			{
				bFind = true;
				break;
			}
			else if (result[mid] > num)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		if (bFind == false)
		{
			result[start] = num;
		}
	}

	std::cout << result.size();
}
