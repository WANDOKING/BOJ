#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    std::vector<std::tuple<int, int, int>> edges;
    edges.reserve(M);

    for (int i = 0; i < M; ++i)
    {
        int A;
        int B;
        int C;

        std::cin >> A >> B >> C;

        edges.push_back(std::make_tuple(A, B, C));
    }

    std::vector<long long> minDistances; // underflow 주의
    minDistances.reserve(N + 1);
    minDistances.push_back(0);
    minDistances.push_back(0);
    for (int i = 2; i <= N; ++i)
    {
        minDistances.push_back(INT_MAX);
    }

    bool bCanRewindTimeInfinity = false;
    for (int i = 0; i <= N; ++i)
    {
        for (auto& edge : edges)
        {
            int start = std::get<0>(edge);
            int end = std::get<1>(edge);
            int weight = std::get<2>(edge);

            if (minDistances[start] == INT_MAX)
            {
                continue;
            }

            if (minDistances[end] > minDistances[start] + weight)
            {
                minDistances[end] = minDistances[start] + weight;

                if (i >= N)
                {
                    bCanRewindTimeInfinity = true;
                    break;
                }
            }
        }
    }

    if (bCanRewindTimeInfinity == true)
    {
        std::cout << "-1\n";
    }
    else
    {
        for (int i = 2; i <= N; ++i)
        {
            if (minDistances[i] == INT_MAX)
            {
                minDistances[i] = -1;
            }

            std::cout << minDistances[i] << '\n';
        }
    }
}
