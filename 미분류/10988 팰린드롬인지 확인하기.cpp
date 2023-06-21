#include <iostream>
#include <string>

int main(void)
{
	std::string word;
	std::cin >> word;

	bool bIsPalindrome = true;

	for (int i = 0; i < word.size() / 2; ++i)
	{
		if (word[i] != word[word.size() - 1 - i])
		{
			bIsPalindrome = false;
			break;
		}
	}

	if (bIsPalindrome)
	{
		std::cout << 1;
	}
	else
	{
		std::cout << 0;
	}
}
