#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string S;
    long long q;
    cin >> S >> q;

    vector<vector<int>> alphabetCountSum;

    for (char alphabet = 'a'; alphabet <= 'z'; alphabet++)
    {
        alphabetCountSum.push_back(vector<int>());

        int sum = 0;
        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == alphabet)
            {
                sum++;
            }

            alphabetCountSum[alphabet - 'a'].push_back(sum);
        }
    }

    for (long long i = 0; i < q; i++)
    {
        char alpha;
        int l;
        int r;
        cin >> alpha >> l >> r;

        int answer;
        if (l == 0)
        {
            answer = alphabetCountSum[alpha - 'a'][r];
        }
        else
        {
            answer = alphabetCountSum[alpha - 'a'][r] - alphabetCountSum[alpha - 'a'][l - 1];
        }

        cout << answer << '\n';
    }
}
