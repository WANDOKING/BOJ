#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>*>* MultiplyMatrix(const vector<vector<int>*>* dest, const vector<vector<int>*>* source)
{
    int n = dest->size();

    vector<vector<int>*>* temp = new vector<vector<int>*>();
    temp->reserve(n);

    for (int i = 0; i < n; ++i)
    {
        temp->push_back(new vector<int>(n));
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            long long sum = 0;
            for (int k = 0; k < n; ++k)
            {
                sum += (dest->at(i)->at(k)) * (source->at(k)->at(j));
            }

            temp->at(i)->at(j) = sum % 1000;
        }
    }

    return temp;
}

vector<vector<int>*>* PowerMatrixRecursive(vector<vector<int>*>* matrix, long long n)
{
    if (n == 1)
    {
        return matrix;
    }

    if (n % 2 == 0)
    {
        return PowerMatrixRecursive(MultiplyMatrix(matrix, matrix), n / 2);
    }
    else
    {
        return MultiplyMatrix(PowerMatrixRecursive(MultiplyMatrix(matrix, matrix), n / 2), matrix);
    }
}

int main(void)
{
    int N;
    long long B;

    cin >> N >> B;

    vector<vector<int>*>* matrix = new vector<vector<int>*>();
    matrix->reserve(N);

    for (int i = 0; i < N; ++i)
    {
        matrix->push_back(new vector<int>(N));
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix->at(i)->at(j);
        }
    }

    vector<vector<int>*>* result = PowerMatrixRecursive(matrix, B);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << (result->at(i)->at(j) % 1000) << ' ';
        }
        cout << '\n';
    }
}
