#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> cards; // 카드, 개수
    
    // input
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        
        bool bSuccess = cards.insert(pair<int, int>(input, 1)).second;
        
        if (bSuccess == false) {
            cards[input]++;
        }
    }
    
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int target;
        scanf("%d", &target);
        
        map<int, int>::iterator it = cards.find(target);
        
        if (it != cards.end()) {
            printf("%d ", it->second);
        } else {
            printf("0 ");
        }
    }

    return 0;
}
