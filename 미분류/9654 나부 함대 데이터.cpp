#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
    cout << setw(15) << left  << "SHIP NAME" << setw(15) << "CLASS" << setw(11) << "DEPLOYMENT" << setw(10) << "IN SERVICE" << '\n';
    cout << setw(15) << left << "N2 Bomber" << setw(15) << "Heavy Fighter" << setw(11) << "Limited" << setw(10) << "21" << '\n';
    cout << setw(15) << left << "J-Type 327" << setw(15) << "Light Combat" << setw(11) << "Unlimited" << setw(10) << "1" << '\n';
    cout << setw(15) << left << "NX Cruiser" << setw(15) << "Medium Fighter" << setw(11) << "Limited" << setw(10) << "18" << '\n';
    cout << setw(15) << left << "N1 Starfighter" << setw(15) << "Medium Fighter" << setw(11) << "Unlimited" << setw(10) << "25" << '\n';
    cout << setw(15) << left << "Royal Cruiser" << setw(15) << "Light Combat" << setw(11) << "Limited" << setw(10) << "4" << '\n';
}
