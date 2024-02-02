#include <iostream>

bool IsLeapYear(int year)
{
    if (year % 4 != 0)
    {
        return false;
    }

    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return true;
}

long long int GetYearToDay(int year)
{
    long long int result = 0;

    for (int i = 1; i <= year; ++i)
    {
        if (IsLeapYear(i))
        {
            result += 366;
        }
        else
        {
            result += 365;
        }
    }

    return result;
}

int GetMonthToDay(int year, int month)
{
    int result = 0;

    for (int i = 1; i <= month; ++i)
    {
        switch (i)
        {
        case 2:
            if (IsLeapYear(year))
            {
                result += 29;
            }
            else
            {
                result += 28;
            }
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            result += 31;
            break;
        default:
            result += 30;
            break;
        }
    }

    return result;
}

int main(void)
{
    long long int todayYear;
    long long int todayMonth;
    long long int todayDay;
    long long int todayDaySum = 0;

    long long int ddayYear;
    long long int ddayMonth;
    long long int ddayDay;
    long long int ddayDaySum = 0;

    std::cin >> todayYear >> todayMonth >> todayDay;
    std::cin >> ddayYear >> ddayMonth >> ddayDay;

    if (ddayYear - todayYear > 1000)
    {
        std::cout << "gg";
        return 0;
    }
    else if (ddayYear - todayYear == 1000)
    {
        if (ddayMonth > todayMonth)
        {
            std::cout << "gg";
            return 0;
        }
        else if (ddayMonth == todayMonth)
        {
            if (ddayDay >= todayDay)
            {
                std::cout << "gg";
                return 0;
            }
        }
    }

    todayDaySum = GetYearToDay(todayYear - 1) + GetMonthToDay(todayYear, todayMonth - 1) + todayDay - 1;
    ddayDaySum = GetYearToDay(ddayYear - 1) + GetMonthToDay(ddayYear, ddayMonth - 1) + ddayDay - 1;

    std::cout << "D-" << ddayDaySum - todayDaySum;
}
