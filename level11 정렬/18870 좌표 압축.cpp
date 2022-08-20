#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int N;
    
    scanf("%d", &N);
    
    vector<pair<int, int>> numsSorted;
    int nums[N];
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        
        numsSorted.push_back(make_pair(i, num));
        nums[i] = num;
    }
    
    sort(numsSorted.begin(), numsSorted.end(), compare);
    
    int compressedNum = 0;
    for (int i = 0; i < N - 1; i++) {
        int temp = numsSorted[i].second;
        
        numsSorted[i].second = compressedNum;
        
        if (temp != numsSorted[i + 1].second) {
            compressedNum++;
        }
    }
    
    numsSorted[N - 1].second = compressedNum;
    
    for (int i = 0; i < N; i++) {
        nums[numsSorted[i].first] = numsSorted[i].second;
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
