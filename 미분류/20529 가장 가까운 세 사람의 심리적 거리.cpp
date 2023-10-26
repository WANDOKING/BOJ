#include <iostream>
#include <string>
#include <vector>
#include <climits>

int GetDistance(const std::string& mbti1, const std::string& mbti2)
{
    int result = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (mbti1[i] != mbti2[i])
        {
            result++;
        }
    }

    return result;
}

int main(void)
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T;
    
    std::cin >> T;

    for (int testCount = 0; testCount < T; ++testCount)
    {
        int N;

        std::cin >> N;

        std::vector<std::string> mbtis;
        mbtis.reserve(N);

        for (int i = 0; i < N; ++i)
        {
            std::string mbti;

            std::cin >> mbti;

            mbtis.push_back(std::move(mbti));
        }

        if (N > 32)
        {
            std::cout << 0 << '\n';
            continue;
        }

        int minDistance = INT_MAX;

        for (int i = 0; i < N - 2; ++i)
        {
            for (int j = i + 1; j < N - 1; ++j)
            {
                for (int k = j + 1; k < N; ++k)
                {
                    int distance = GetDistance(mbtis[i], mbtis[j]) + GetDistance(mbtis[j], mbtis[k]) + GetDistance(mbtis[i], mbtis[k]);
                
                    if (distance < minDistance)
                    {
                        minDistance = distance;
                    }
                }
            }
        }

        std::cout << minDistance << '\n';
    }
}
