#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<long long> roadLens;
    vector<long long> oilPrices;
    roadLens.reserve(N);
    oilPrices.reserve(N);

    for (int i = 0; i < N - 1; i++)
    {
        long long roadLen;
        cin >> roadLen;
        roadLens.push_back(roadLen);
    }
    
    roadLens.push_back(0);

    for (int i = 0; i < N; i++)
    {
        long long oilPrice;
        cin >> oilPrice;
        oilPrices.push_back(oilPrice);
    }

    long long result = 0;
    int currentPos = 0;

    while (currentPos < N - 1)
    {
        int i = 1;
        long long goLen = roadLens[currentPos];
        int nextPos = currentPos + 1;
        while (currentPos + i < N)
        {
            if (oilPrices[currentPos] > oilPrices[currentPos + i])
            {
                break;
            }

            goLen += roadLens[currentPos + i];
            nextPos++;
            i++;
        }

        result += oilPrices[currentPos] * goLen;
        currentPos = nextPos;
    }

    cout << result;
}
