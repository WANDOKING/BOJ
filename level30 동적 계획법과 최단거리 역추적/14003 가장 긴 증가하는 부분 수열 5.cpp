#include <iostream>
#include <vector>

#define MAX_N 1000000

int g_nums[MAX_N];    // 입력값
int g_dpIndex[MAX_N]; // LIS 길이를 구하면서 어떤 색인에 들어갔는지 기록

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> g_nums[i];
    }

    std::vector<int> dpNums; // LIS 길이를 구하기 위한 벡터
    dpNums.reserve(N);

    dpNums.push_back(g_nums[0]);
    g_dpIndex[0] = 0;

    for (int i = 1; i < N; ++i)
    {
        int start = 0;
        int end = dpNums.size() - 1;

        if (g_nums[i] > dpNums.back())
        {
            g_dpIndex[i] = dpNums.size();
            dpNums.push_back(g_nums[i]);
            continue;
        }

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (dpNums[mid] == g_nums[i])
            {
                start = mid;
                break;
            }
            else if (dpNums[mid] > g_nums[i])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        dpNums[start] = g_nums[i];
        g_dpIndex[i] = start;
    }

    std::cout << dpNums.size() << '\n';

    std::vector<int> lis;
    lis.reserve(dpNums.size());

    // 역순회하면서 뒤집어진 LIS를 획득한다
    int dpNumIndex = dpNums.size() - 1;
    for (int i = N - 1; i >= 0; --i)
    {
        if (g_dpIndex[i] == dpNumIndex)
        {
            lis.push_back(g_nums[i]);
            --dpNumIndex;
        }

        if (dpNumIndex < 0)
        {
            break;
        }
    }

    // 위에서 얻어낸 것을 거꾸로 출력
    for (int i = lis.size() - 1; i >= 0; --i)
    {
        std::cout << lis[i] << ' ';
    }
}
