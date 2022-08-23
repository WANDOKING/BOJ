#include <iostream>
#include <map>

using namespace std;

int main()
{
    const int NAME_MAX_LEN = 20;
    
    int N;
    int M;
    scanf("%d", &N);
    scanf("%d", &M);
    
    map<string, int> pokemons;
    char pokemonsArr[N + 1][NAME_MAX_LEN + 1];
    for (int i = 1; i <= N; i++) {
        string input;
        
        cin >> input;
        
        pokemons.insert(pair<string, int>(input, i));
        sprintf(pokemonsArr[i], "%s", input.c_str());
    }
    
    for (int i = 0; i < M; i++) {
        char input[NAME_MAX_LEN + 1];
        
        scanf("%s", input);

        if (input[0] >= '0' && input[0] <= '9') {
            // question is number
            int num;
            sscanf(input, "%d", &num);
            
            printf("%s\n", pokemonsArr[num]);
        } else {
            // question is string
            map<string, int>::iterator itFind = pokemons.find(input);
            
            printf("%d\n", itFind->second);
        }
    }
    
    return 0;
}
