#include <iostream>

char GetDNA(const char row, const char column)
{
    switch (row)
    {
    case 'A':
        switch (column)
        {
        case 'A': return 'A';
        case 'G': return 'C';
        case 'C': return 'A';
        case 'T': return 'G';
        }
        break;
    case 'G':
        switch (column)
        {
        case 'A': return 'C';
        case 'G': return 'G';
        case 'C': return 'T';
        case 'T': return 'A';
        }
        break;
    case 'C':
        switch (column)
        {
        case 'A': return 'A';
        case 'G': return 'T';
        case 'C': return 'C';
        case 'T': return 'G';
        }
        break;
    case 'T':
        switch (column)
        {
        case 'A': return 'G';
        case 'G': return 'A';
        case 'C': return 'G';
        case 'T': return 'T';
        }
        break;
    }
}

int main(void)
{
    int N;
    std::string input;

    std::cin >> N >> input;

    for (int i = 0; i < N - 1; ++i)
    {
        input[N - 2 - i] = GetDNA(input[N - 2 - i], input[N - 1 - i]);
    }

    std::cout << input[0];
}
