#include <iostream>
#include <vector>
#include <algorithm>

#define NAME_MAX_LENGTH 100

using namespace std;

bool compare(pair<int, string>a, pair<int, string>b)
{
    return a.first < b.first;
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    // input
    vector<pair<int, string>> members;
    for (int i = 0; i < N; i++) {
        int age;
        char* name = new char[NAME_MAX_LENGTH + 1];
        
        scanf("%d %s", &age, name);
        
        members.push_back(make_pair(age, name));
    }
    
    // stable sort
    stable_sort(members.begin(), members.end(), compare);
    
    // print
    for (int i = 0; i < N; i++) {
        cout << members[i].first << ' ' << members[i].second << '\n';
    }

    return 0;
}
