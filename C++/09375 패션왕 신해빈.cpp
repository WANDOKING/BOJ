#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        int n;
        unordered_map<string, int> costumeCounts;
        scanf("%d", &n);

        for (int j = 0; j < n; j++)
        {
            string input;
            cin >> input;
            cin >> input;

            auto it = costumeCounts.find(input);
            if (it == costumeCounts.end())
            {
                costumeCounts.insert(make_pair(input, 1));
            }
            else
            {
                costumeCounts[input]++;
            }
        }

        int result = 1; // { (a + 1) * (b + 1) * ... } - 1
        for (auto it : costumeCounts)
        {
            result *= it.second + 1;
        }
        result--;

        printf("%d\n", result);
    }

    return 0;
}
