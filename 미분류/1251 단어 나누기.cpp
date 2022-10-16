#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string input;
    
    cin >> input;
    
    int div1 = 0;
    int div2 = 1;

    set<string> transformed;
    
    for (int div1 = 0; div1 < input.length() - 2; div1++)
    {
        for (int div2 = div1 + 1; div2 < input.length() - 1; div2++)
        {
            string str1 = "";
            string str2 = "";
            string str3 = "";
            
            int i = 0;
            
            for (; i <= div1; i++)
            {
                str1 += input[i];
            }
            
            for (; i <= div2; i++)
            {
                str2 += input[i];
            }
            
            for (; i < input.length(); i++)
            {
                str3 += input[i];
            }
            
            reverse(str1.begin(), str1.end());
            reverse(str2.begin(), str2.end());
            reverse(str3.begin(), str3.end());
            
            string str4 = str1 + str2 + str3;
            
            transformed.insert(str4);
        }
    }
    
    cout << *transformed.begin();

    return 0;
}
