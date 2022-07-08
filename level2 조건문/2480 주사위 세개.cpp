#include <iostream>

using namespace std;

int main()
{
    int num1;
    int num2;
    int num3;
    int price;
    
    cin >> num1 >> num2 >> num3;
    
    if (num1 == num2 && num2 == num3) {
        price = 10000 + num1 * 1000;
    } else if (num1 == num2 || num1 == num3) {
        price = 1000 + 100 * num1;
    } else if (num2 == num3) {
        price = 1000 + 100 * num2;
    } else {
        if (num1 > num2 && num1 > num3) {
            price = num1 * 100;
        } else if (num2 > num1 && num2 > num3) {
            price = num2 * 100;
        } else {
            price = num3 * 100;
        }
    }

    cout << price;
    
    return 0;
}
