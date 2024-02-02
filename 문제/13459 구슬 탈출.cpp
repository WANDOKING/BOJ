// 13460 구슬 탈출 2를 먼저 풀고 그 코드에서 출력만 1, 0으로 변경함
#include <iostream>
#include <queue>

#define MAX_N 10
#define MAX_M 10

// map info
#define WALL '#'
#define BLANK '.'
#define HOLE 'O'
#define RED 'R'
#define BLUE 'B'

// queue에 넣기 위해 값을 하나로 합치고 분리하는 매크로
#define TO_HASH(MC, RX, RY, BX, BY) ((MC) * 10000 + (RX) * 1000 + (RY) * 100 + (BX) * 10 + BY)
#define GET_MOVE_COUNT(H) ((H) / 10000)
#define GET_RED_X(H) ((H) / 1000 % 10)
#define GET_RED_Y(H) ((H) / 100 % 10)
#define GET_BLUE_X(H) ((H) / 10 % 10)
#define GET_BLUE_Y(H) ((H) % 10)

// Tilt() 함수들의 반환값
#define GAME_RESULT int
#define GAME_CLEAR 1 // 빨간 구슬이 구멍에 들어감
#define GAME_OVER -1 // 파란 구슬이 구멍에 들어감, 빨간 구슬과 동시에 들어가도 이 값이 반환됨
#define NONE 0       // 아직 게임이 끝나지 않음

char g_board[MAX_N][MAX_M];

GAME_RESULT RedMoveWhenTiltUp(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY);
GAME_RESULT BlueMoveWhenTiltUp(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY);

GAME_RESULT RedMoveWhenTiltDown(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY);
GAME_RESULT BlueMoveWhenTiltDown(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY);

GAME_RESULT RedMoveWhenTiltLeft(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY);
GAME_RESULT BlueMoveWhenTiltLeft(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY);

GAME_RESULT RedMoveWhenTiltRight(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY);
GAME_RESULT BlueMoveWhenTiltRight(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY);

GAME_RESULT TiltUp(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY);
GAME_RESULT TiltDown(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY);
GAME_RESULT TiltLeft(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY);
GAME_RESULT TiltRight(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY);

int main(void)
{
	std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	int N;
	int M;

	int redStartX = -1;
	int redStartY = -1;
	int blueStartX = -1;
	int blueStartY = -1;

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> g_board[i][j];

			if (g_board[i][j] == RED)
			{
				redStartX = j;
				redStartY = i;
				g_board[i][j] = BLANK;
			}
			else if (g_board[i][j] == BLUE)
			{
				blueStartX = j;
				blueStartY = i;
				g_board[i][j] = BLANK;
			}
		}
	}

	std::queue<int> q;
	q.push(TO_HASH(0, redStartX, redStartY, blueStartX, blueStartY));

	int result = 0;
	while (q.empty() == false)
	{
		int moveCount = GET_MOVE_COUNT(q.front());
		int redX = GET_RED_X(q.front());
		int redY = GET_RED_Y(q.front());
		int blueX = GET_BLUE_X(q.front());
		int blueY = GET_BLUE_Y(q.front());
		q.pop();

		if (moveCount == 10)
		{
			continue;
		}

		int redXAfterTilt;
		int redYAfterTilt;
		int blueXAfterTilt;
		int blueYAfterTilt;

		int gameResult;
		bool bNoChange;

		gameResult = TiltUp(redX, redY, blueX, blueY, &redXAfterTilt, &redYAfterTilt, &blueXAfterTilt, &blueYAfterTilt);
		bNoChange = redX == redXAfterTilt && redY == redYAfterTilt && blueX == blueXAfterTilt && blueY == blueYAfterTilt;
		if (gameResult == GAME_CLEAR)
		{
			result = 1;
			break;
		}
		else if (gameResult == NONE && !bNoChange)
		{
			q.push(TO_HASH(moveCount + 1, redXAfterTilt, redYAfterTilt, blueXAfterTilt, blueYAfterTilt));
		}

		gameResult = TiltDown(redX, redY, blueX, blueY, &redXAfterTilt, &redYAfterTilt, &blueXAfterTilt, &blueYAfterTilt);
		bNoChange = redX == redXAfterTilt && redY == redYAfterTilt && blueX == blueXAfterTilt && blueY == blueYAfterTilt;
		if (gameResult == GAME_CLEAR)
		{
			result = 1;
			break;
		}
		else if (gameResult == NONE && !bNoChange)
		{
			q.push(TO_HASH(moveCount + 1, redXAfterTilt, redYAfterTilt, blueXAfterTilt, blueYAfterTilt));
		}

		gameResult = TiltLeft(redX, redY, blueX, blueY, &redXAfterTilt, &redYAfterTilt, &blueXAfterTilt, &blueYAfterTilt);
		bNoChange = redX == redXAfterTilt && redY == redYAfterTilt && blueX == blueXAfterTilt && blueY == blueYAfterTilt;
		if (gameResult == GAME_CLEAR)
		{
			result = 1;
			break;
		}
		else if (gameResult == NONE && !bNoChange)
		{
			q.push(TO_HASH(moveCount + 1, redXAfterTilt, redYAfterTilt, blueXAfterTilt, blueYAfterTilt));
		}

		gameResult = TiltRight(redX, redY, blueX, blueY, &redXAfterTilt, &redYAfterTilt, &blueXAfterTilt, &blueYAfterTilt);
		bNoChange = redX == redXAfterTilt && redY == redYAfterTilt && blueX == blueXAfterTilt && blueY == blueYAfterTilt;
		if (gameResult == GAME_CLEAR)
		{
			result = 1;
			break;
		}
		else if (gameResult == NONE && !bNoChange)
		{
			q.push(TO_HASH(moveCount + 1, redXAfterTilt, redYAfterTilt, blueXAfterTilt, blueYAfterTilt));
		}
	}

	std::cout << result;
}

GAME_RESULT RedMoveWhenTiltUp(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY)
{
	*outRedX = redX;

	while (g_board[redY - 1][redX] != WALL && !(blueX == redX && blueY == redY - 1))
	{
		if (g_board[redY - 1][redX] == HOLE)
		{
			*outRedY = 0;
			return GAME_CLEAR;
		}

		redY--;
	}

	*outRedY = redY;
	return NONE;
}

GAME_RESULT BlueMoveWhenTiltUp(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY)
{
	*outBlueX = blueX;

	while (g_board[blueY - 1][blueX] != WALL && !(blueX == redX && blueY - 1 == redY))
	{
		if (g_board[blueY - 1][blueX] == HOLE)
		{
			*outBlueY = blueY - 1;
			return GAME_OVER;
		}

		blueY--;
	}

	*outBlueY = blueY;
	return NONE;
}

GAME_RESULT TiltUp(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY)
{
	int redXAfterMove;
	int redYAfterMove;
	int blueXAfterMove;
	int blueYAfterMove;

	bool bIsGameClear;
	bool bIsGameOver;

	if (redY < blueY)
	{
		bIsGameClear = RedMoveWhenTiltUp(redX, redY, blueX, blueY, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
		bIsGameOver = BlueMoveWhenTiltUp(redXAfterMove, redYAfterMove, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
	}
	else
	{
		bIsGameOver = BlueMoveWhenTiltUp(redX, redY, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
		bIsGameClear = RedMoveWhenTiltUp(redX, redY, blueXAfterMove, blueYAfterMove, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
	}

	*outRedX = redXAfterMove;
	*outRedY = redYAfterMove;
	*outBlueX = blueXAfterMove;
	*outBlueY = blueYAfterMove;

	if (bIsGameOver)
	{
		return GAME_OVER;
	}

	if (bIsGameClear)
	{
		return GAME_CLEAR;
	}

	return NONE;
}

GAME_RESULT RedMoveWhenTiltDown(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY)
{
	*outRedX = redX;

	while (g_board[redY + 1][redX] != WALL && !(blueX == redX && blueY == redY + 1))
	{
		if (g_board[redY + 1][redX] == HOLE)
		{
			*outRedY = 0;
			return GAME_CLEAR;
		}

		redY++;
	}

	*outRedY = redY;
	return NONE;
}

GAME_RESULT BlueMoveWhenTiltDown(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY)
{
	*outBlueX = blueX;

	while (g_board[blueY + 1][blueX] != WALL && !(blueX == redX && blueY + 1 == redY))
	{
		if (g_board[blueY + 1][blueX] == HOLE)
		{
			*outBlueY = blueY + 1;
			return GAME_OVER;
		}

		blueY++;
	}

	*outBlueY = blueY;
	return NONE;
}

GAME_RESULT TiltDown(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY)
{
	int redXAfterMove;
	int redYAfterMove;
	int blueXAfterMove;
	int blueYAfterMove;

	bool bIsGameClear;
	bool bIsGameOver;

	if (redY > blueY)
	{
		bIsGameClear = RedMoveWhenTiltDown(redX, redY, blueX, blueY, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
		bIsGameOver = BlueMoveWhenTiltDown(redXAfterMove, redYAfterMove, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
	}
	else
	{
		bIsGameOver = BlueMoveWhenTiltDown(redX, redY, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
		bIsGameClear = RedMoveWhenTiltDown(redX, redY, blueXAfterMove, blueYAfterMove, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
	}

	*outRedX = redXAfterMove;
	*outRedY = redYAfterMove;
	*outBlueX = blueXAfterMove;
	*outBlueY = blueYAfterMove;

	if (bIsGameOver)
	{
		return GAME_OVER;
	}

	if (bIsGameClear)
	{
		return GAME_CLEAR;
	}

	return NONE;
}

GAME_RESULT RedMoveWhenTiltLeft(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY)
{
	*outRedY = redY;

	while (g_board[redY][redX - 1] != WALL && !(blueX == redX - 1 && blueY == redY))
	{
		if (g_board[redY][redX - 1] == HOLE)
		{
			*outRedX = 0;
			return GAME_CLEAR;
		}

		redX--;
	}

	*outRedX = redX;
	return NONE;
}

GAME_RESULT BlueMoveWhenTiltLeft(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY)
{
	*outBlueY = blueY;

	while (g_board[blueY][blueX - 1] != WALL && !(blueX - 1 == redX && blueY == redY))
	{
		if (g_board[blueY][blueX - 1] == HOLE)
		{
			*outBlueX = blueX - 1;
			return GAME_OVER;
		}

		blueX--;
	}

	*outBlueX = blueX;
	return NONE;
}

GAME_RESULT TiltLeft(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY)
{
	int redXAfterMove;
	int redYAfterMove;
	int blueXAfterMove;
	int blueYAfterMove;

	bool bIsGameClear;
	bool bIsGameOver;

	if (redX < blueX)
	{
		bIsGameClear = RedMoveWhenTiltLeft(redX, redY, blueX, blueY, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
		bIsGameOver = BlueMoveWhenTiltLeft(redXAfterMove, redYAfterMove, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
	}
	else
	{
		bIsGameOver = BlueMoveWhenTiltLeft(redX, redY, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
		bIsGameClear = RedMoveWhenTiltLeft(redX, redY, blueXAfterMove, blueYAfterMove, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
	}

	*outRedX = redXAfterMove;
	*outRedY = redYAfterMove;
	*outBlueX = blueXAfterMove;
	*outBlueY = blueYAfterMove;

	if (bIsGameOver)
	{
		return GAME_OVER;
	}

	if (bIsGameClear)
	{
		return GAME_CLEAR;
	}

	return NONE;
}

GAME_RESULT RedMoveWhenTiltRight(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY)
{
	*outRedY = redY;

	while (g_board[redY][redX + 1] != WALL && !(blueX == redX + 1 && blueY == redY))
	{
		if (g_board[redY][redX + 1] == HOLE)
		{
			*outRedX = 0;
			return GAME_CLEAR;
		}

		redX++;
	}

	*outRedX = redX;
	return NONE;
}

GAME_RESULT BlueMoveWhenTiltRight(int redX, int redY, int blueX, int blueY, int* outBlueX, int* outBlueY)
{
	*outBlueY = blueY;

	while (g_board[blueY][blueX + 1] != WALL && !(blueX + 1 == redX && blueY == redY))
	{
		if (g_board[blueY][blueX + 1] == HOLE)
		{
			*outBlueX = blueX + 1;
			return GAME_OVER;
		}

		blueX++;
	}

	*outBlueX = blueX;
	return NONE;
}

GAME_RESULT TiltRight(int redX, int redY, int blueX, int blueY, int* outRedX, int* outRedY, int* outBlueX, int* outBlueY)
{
	int redXAfterMove;
	int redYAfterMove;
	int blueXAfterMove;
	int blueYAfterMove;

	bool bIsGameClear;
	bool bIsGameOver;

	if (redX > blueX)
	{
		bIsGameClear = RedMoveWhenTiltRight(redX, redY, blueX, blueY, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
		bIsGameOver = BlueMoveWhenTiltRight(redXAfterMove, redYAfterMove, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
	}
	else
	{
		bIsGameOver = BlueMoveWhenTiltRight(redX, redY, blueX, blueY, &blueXAfterMove, &blueYAfterMove) == GAME_OVER;
		bIsGameClear = RedMoveWhenTiltRight(redX, redY, blueXAfterMove, blueYAfterMove, &redXAfterMove, &redYAfterMove) == GAME_CLEAR;
	}

	*outRedX = redXAfterMove;
	*outRedY = redYAfterMove;
	*outBlueX = blueXAfterMove;
	*outBlueY = blueYAfterMove;

	if (bIsGameOver)
	{
		return GAME_OVER;
	}

	if (bIsGameClear)
	{
		return GAME_CLEAR;
	}

	return NONE;
}
