#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N;
    int M;

    cin >> N >> M;

    unordered_map<string, string> passwords;
    for (int i = 0; i < N; i++)
    {
        string siteAddress;
        string password;

        cin >> siteAddress >> password;

        passwords.insert(make_pair(siteAddress, password));
    }

    for (int i = 0; i < M; i++)
    {
        string siteAddress;

        cin >> siteAddress;

        auto password = passwords.find(siteAddress);
        
        cout << password->second << '\n';
    }
}
