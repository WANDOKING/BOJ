#include <iostream>
#include <string>

#define MAX_SUBJECT_NAME_LENGTH 50

int main(void)
{
    double sumSubject = 0.0; // 학점 X 과목평점의 합
    double sumCredit = 0.0;  // 학점의 총합

    for (int i = 0; i < 20; ++i)
    {
        std::string subjectName;
        double credit;
        std::string grade;
        int count = 0;
        std::cin >> subjectName >> credit >> grade;

        double gradeCredit;

        if (grade == "P")
        {
            continue;
        }
        else if (grade == "A+")
        {
            gradeCredit = 4.5;
        }
        else if (grade == "A0")
        {
            gradeCredit = 4.0;
        }
        else if (grade == "B+")
        {
            gradeCredit = 3.5;
        }
        else if (grade == "B0")
        {
            gradeCredit = 3.0;
        }
        else if (grade == "C+")
        {
            gradeCredit = 2.5;
        }
        else if (grade == "C0")
        {
            gradeCredit = 2.0;
        }
        else if (grade == "D+")
        {
            gradeCredit = 1.5;
        }
        else if (grade == "D0")
        {
            gradeCredit = 1.0;
        }
        else
        {
            gradeCredit = 0.0;
        }

        sumSubject += gradeCredit * credit;
        sumCredit += credit;

        count++;
    }

    std::cout << sumSubject / sumCredit;
}
