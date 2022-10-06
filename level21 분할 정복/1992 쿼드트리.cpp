#include <iostream>

#define MAX 64

using namespace std;

string EncodeRecurisve(char arr[][64], int N, int x = 0, int y = 0)
{

    if (N == 1)
    {
        if (arr[y][x] == '1')
        {
            return string("1");
        }
        else
        {
            return string("0");
        }
    }

    string qt1 = EncodeRecurisve(arr, N / 2, x, y);
    string qt2 = EncodeRecurisve(arr, N / 2, x + N / 2, y);
    string qt3 = EncodeRecurisve(arr, N / 2, x, y + N / 2);
    string qt4 = EncodeRecurisve(arr, N / 2, x + N / 2, y + N / 2);

    if (qt1 == qt2 && qt2 == qt3 && qt3 == qt4 && qt4 == "1")
    {
        return string("1");
    }

    if (qt1 == qt2 && qt2 == qt3 && qt3 == qt4 && qt4 == "0")
    {
        return string("0");
    }

    string result = "(" + qt1 + qt2 + qt3 + qt4 + ")";
    return result;
}

int main(void)
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    char arr[MAX][MAX];
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    string result = EncodeRecurisve(arr, N);

    cout << result;
}
