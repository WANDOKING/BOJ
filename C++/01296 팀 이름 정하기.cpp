#include <iostream>
#include <vector>

int main(void)
{
    int LCount = 0;
    int OCount = 0;
    int VCount = 0;
    int ECount = 0;

    std::string yeonduEnglishName;
    std::vector<std::string> teamNames;

    std::cin >> yeonduEnglishName;

    for (const char ch : yeonduEnglishName)
    {
        switch (ch)
        {
        case 'L':
            LCount++;
            break;
        case 'O':
            OCount++;
            break;
        case 'V':
            VCount++;
            break;
        case 'E':
            ECount++;
            break;
        default:
            break;
        }
    }

    int N;

    std::cin >> N;

    teamNames.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        std::string teamName;

        std::cin >> teamName;

        teamNames.push_back(teamName);
    }

    std::string result;
    int maxScore = -1;

    for (const std::string& teamName : teamNames)
    {
        int L = LCount;
        int O = OCount;
        int V = VCount;
        int E = ECount;

        for (const char ch : teamName)
        {
            switch (ch)
            {
            case 'L':
                L++;
                break;
            case 'O':
                O++;
                break;
            case 'V':
                V++;
                break;
            case 'E':
                E++;
                break;
            default:
                break;
            }
        }

        int score = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;

        if (score == maxScore)
        {
            if (result > teamName)
            {
                result = teamName;
            }
        }
        if (score > maxScore)
        {
            maxScore = score;
            result = teamName;
        }
    }

    std::cout << result;
}
