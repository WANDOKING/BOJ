#include <iostream>

int main(void)
{
    int L;
    int A;
    int B;
    int C;
    int D;

    std::cin >> L >> A >> B >> C >> D;

    int needDayForKorean = A / C + (A % C == 0 ? 0 : 1);
    int needDayForMath = B / D + (B % D == 0 ? 0 : 1);
    
    int result = L - std::max(needDayForKorean, needDayForMath);

    std::cout << result;
}
