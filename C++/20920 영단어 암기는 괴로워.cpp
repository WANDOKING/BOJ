#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::unordered_map<std::string, int> wordCount;

bool Compare(const std::string& a, const std::string& b)
{
    size_t lengthA = wordCount.find(a)->second;
    size_t lengthB = wordCount.find(b)->second;

    if (lengthA > lengthB)
    {
        return true;
    }
    else if (lengthA == lengthB)
    {
        if (a.length() == b.length())
        {
            return a < b;
        }
        else if (a.length() > b.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main(void)
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    int M;

    std::cin >> N >> M;

    std::vector<std::string> words;

    words.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        std::string word;

        std::cin >> word;

        if (word.length() < M)
        {
            continue;
        }

        auto found = wordCount.find(word);

        if (found == wordCount.end())
        {
            wordCount.insert(std::make_pair(word, 1));
            words.push_back(word);
        }
        else
        {
            found->second += 1;
        }
    }

    std::sort(words.begin(), words.end(), Compare);

    for (const std::string& word : words)
    {
        std::cout << word << '\n';
    }
}
