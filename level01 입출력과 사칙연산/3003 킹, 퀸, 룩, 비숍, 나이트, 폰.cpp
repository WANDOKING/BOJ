#include <iostream>

int main()
{
    const int KING_PIECE_COUNT = 1;
    const int QUEEN_PIECE_COUNT = 1;
    const int ROOK_PIECE_COUNT = 2;
    const int BISHOP_PIECE_COUNT = 2;
    const int KNIGHT_PIECE_COUNT = 2;
    const int PAWN_PIECE_COUNT = 8;
    
    int input;
    
    scanf("%d", &input);
    printf("%d ", KING_PIECE_COUNT - input);
    
    scanf("%d", &input);
    printf("%d ", QUEEN_PIECE_COUNT - input);
    
    scanf("%d", &input);
    printf("%d ", ROOK_PIECE_COUNT - input);
    
    scanf("%d", &input);
    printf("%d ", BISHOP_PIECE_COUNT - input);
    
    scanf("%d", &input);
    printf("%d ", KNIGHT_PIECE_COUNT - input);
    
    scanf("%d", &input);
    printf("%d ", PAWN_PIECE_COUNT - input);
    
    return 0;
}
