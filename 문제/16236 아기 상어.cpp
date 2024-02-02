#include <iostream>
#include <queue>
#include <cassert>

#define MAX_N 20
#define EMPTY 0
#define BABY_SHARK 9
#define BABY_SHARK_DEFAULT_SIZE 2

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    short board[MAX_N][MAX_N];
    int countTotalFish = 0;
    int babySharkSize = BABY_SHARK_DEFAULT_SIZE;
    int countFishsBabySharkEat = 0;

    // input
    int N;
    std::cin >> N;

    int startX = -1;
    int startY = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            short input;
            std::cin >> input;

            board[i][j] = input;

            if (input == EMPTY)
            {
                continue;
            }
            else if (input == BABY_SHARK)
            {
                startX = j;
                startY = i;
                board[i][j] = EMPTY;
            }
            else
            {
                countTotalFish++;
            }
        }
    }

    int result = 0;
    int babySharkX = startX;
    int babySharkY = startY;

    while (countTotalFish > 0)
    {
        std::queue<int> q;
        // distance * 10000 | startX * 100 | startY 압축
        q.push(babySharkX * 100 + babySharkY); 

        bool bBabySharkCanEat = false;
        int minDistance = -1;
        int eatX = -1;
        int eatY = -1;

        bool bVisited[MAX_N][MAX_N] = { false, };

        // bfs
        while (q.empty() == false)
        {
            // distance * 10000 | startX * 100 | startY 압축 해제
            int distance = q.front() / 10000;
            int x = (q.front() % 10000) / 100;
            int y = q.front() % 100;
            q.pop();

            // 올바르지 않은 좌표
            if (x < 0 || x >= N || y < 0 || y >= N)
            {
                continue;
            }

            // 이미 물고기를 찾았으면 더 멀리 탐색하지 않는다
            if (bBabySharkCanEat == true && distance > minDistance)
            {
                continue;
            }

            if (bVisited[y][x] == true)
            {
                continue;
            }

            bVisited[y][x] = true;

            if (board[y][x] != EMPTY)
            {
                if (board[y][x] > babySharkSize)
                {
                    // can not go
                    continue;
                }
                else if (board[y][x] < babySharkSize)
                {
                    // eat, 이미 먹을 수 있는 물고기를 찾은 적 있다면 우선순위 결정
                    if (bBabySharkCanEat == true)
                    {
                        if (y < eatY || (y == eatY && x < eatX))
                        {
                            eatX = x;
                            eatY = y;
                        }
                    }
                    else
                    {
                        bBabySharkCanEat = true;
                        minDistance = distance;
                        eatX = x;
                        eatY = y;
                    }
                    continue;
                }
            }

            distance++;
            q.push(distance * 10000 + (x) * 100 + (y - 1));
            q.push(distance * 10000 + (x - 1) * 100 + (y));
            q.push(distance * 10000 + (x + 1) * 100 + (y));
            q.push(distance * 10000 + (x) * 100 + (y + 1));
        }

        // can not eat
        if (bBabySharkCanEat == false)
        {
            break;
        }

        // update result
        result += minDistance;

        // update baby shark size
        countFishsBabySharkEat++;
        if (countFishsBabySharkEat == babySharkSize)
        {
            babySharkSize++;
            countFishsBabySharkEat = 0;
        }

        // process eat
        countTotalFish--;
        board[eatY][eatX] = EMPTY;

        // update for next loop
        babySharkX = eatX;
        babySharkY = eatY;
    }

    std::cout << result;
}
