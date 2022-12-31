#include <iostream>
#include <vector>
#include <unordered_set>

#define MAX_N 500000

int B[MAX_N + 1];
int A[MAX_N + 1];

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int wireCount;
    std::cin >> wireCount;

    for (int i = 0; i < wireCount; ++i)
    {
        int start;
        int end;

        std::cin >> start >> end;

        A[start] = end;
        B[end] = start;
    }

    std::vector<int> lisQuestion;
    lisQuestion.reserve(wireCount);

    for (int i = 1; i <= MAX_N; ++i)
    {
        if (B[i] != 0)
        {
            lisQuestion.push_back(B[i]);
        }
    }

    std::vector<int> lisTemp;
    std::vector<int> lisTempIndex;
    lisTempIndex.reserve(lisQuestion.size());

    lisTemp.push_back(lisQuestion[0]);
    lisTempIndex.push_back(0);

    for (size_t i = 1; i < lisQuestion.size(); ++i)
    {
        int start = 0;
        int end = lisTemp.size() - 1;

        if (lisQuestion[i] > lisTemp.back())
        {
            lisTemp.push_back(lisQuestion[i]);
            lisTempIndex.push_back(lisTemp.size() - 1);
            continue;
        }

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (lisQuestion[i] == lisTemp[mid])
            {
                start = mid;
                break;
            }
            else if (lisQuestion[i] > lisTemp[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        lisTemp[start] = lisQuestion[i];
        lisTempIndex.push_back(start);
    }

    int lisIndexCount = lisTemp.size() - 1;
    std::unordered_set<int> lis;

    for (int i = lisTempIndex.size() - 1; i >= 0; --i)
    {
        if (lisTempIndex[i] == lisIndexCount)
        {
            lis.insert(lisQuestion[i]);
            --lisIndexCount;
        }

        if (lisIndexCount < 0)
        {
            break;
        }
    }

    std::cout << wireCount - lisTemp.size() << '\n';

    for (int i = 1; i <= MAX_N; ++i)
    {
        if (A[i] == 0)
        {
            continue;
        }

        if (lis.find(i) == lis.end())
        {
            std::cout << i << '\n';
        }
    }
}
