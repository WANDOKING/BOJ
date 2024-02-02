#include <iostream>
#include <string>

int main()
{
    std::string input;
    
    std::cin >> input;
    
    if (input == "A+")
    {
        printf("4.3");
    }
    if (input == "A0")
    {
        printf("4.0");
    }
    if (input == "A-")
    {
        printf("3.7");
    }
    if (input == "B+")
    {
        printf("3.3");
    }
    if (input == "B0")
    {
        printf("3.0");
    }
    if (input == "B-")
    {
        printf("2.7");
    }
    if (input == "C+")
    {
        printf("2.3");
    }
    if (input == "C0")
    {
        printf("2.0");
    }
    if (input == "C-")
    {
        printf("1.7");
    }
    if (input == "D+")
    {
        printf("1.3");
    }
    if (input == "D0")
    {
        printf("1.0");
    }
    if (input == "D-")
    {
        printf("0.7");
    }
    if (input == "F")
    {
        printf("0.0");
    }

    return 0;
}
