/* 
 * 이 문제의 벨만-포드 구현은 사실 올바르지 않음.
 * 최단 거리가 INF인 노드에 대한 처리를 다르게 해주어야 함
 * 이 문제에 대한 자세한 해설 : https://www.acmicpc.net/board/view/72995
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

#define MAX_N 500

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int TC;
    std::cin >> TC;

    for (int tc = 0; tc < TC; ++tc)
    {
        int N;
        int M;
        int W;

        std::cin >> N >> M >> W;

        std::vector<std::tuple<int, int, int>> edges;
        edges.reserve(M + W);

        int S;
        int E;
        int T;

        // 도로 입력
        for (int i = 0; i < M; ++i)
        {
            std::cin >> S >> E >> T;
            edges.push_back(std::make_tuple(S, E, T));
            edges.push_back(std::make_tuple(E, S, T));
        }

        // 웜홀 입력
        for (int i = 0; i < W; ++i)
        {
            std::cin >> S >> E >> T;
            edges.push_back(std::make_tuple(S, E, T * -1));
        }

        // 최소 거리 초기화
        int minDistances[MAX_N + 1];
        minDistances[1] = 0;
        for (int i = 2; i <= N; ++i)
        {
            minDistances[i] = INT_MAX / 2;
        }

        // bellman-ford
        for (int i = 0; i < N - 1; ++i)
        {
            for (const auto& edge : edges)
            {
                const int start = std::get<0>(edge);
                const int end = std::get<1>(edge);
                const int weight = std::get<2>(edge);

                if (minDistances[end] > minDistances[start] + weight)
                {
                    minDistances[end] = minDistances[start] + weight;
                }
            }
        }

        // 음수 간선 순환 확인
        for (int i = 0; i < N - 1; ++i)
        {
            for (const auto& edge : edges)
            {
                const int start = std::get<0>(edge);
                const int end = std::get<1>(edge);
                const int weight = std::get<2>(edge);

                if (minDistances[end] > minDistances[start] + weight)
                {
                    // detect
                    std::cout << "YES\n";
                    goto NEXT_TEST_CASE;
                }
            }
        }

        std::cout << "NO\n";
    NEXT_TEST_CASE:;
    }
}
