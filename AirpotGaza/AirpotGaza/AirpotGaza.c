#include <stdio.h>
int LCount, RCount = 0;
int x, y = 0;
void N(int L, int R) //자동차 앞 부분이 위쪽을 향함
{
		y++;
	printf("N방향\t(%d, %d)\n", x, y);
}
void W(int L, int R) //자동차 앞 부분이 왼쪽을 향함
{
		x--;
	
	printf("W방향\t(%d, %d)\n", x, y);
}
void E(int L, int R) //자동차 앞 부분이 오른쪽을 향함
{
	x++;
	printf("E방향\t(%d, %d)\n", x, y);
}
void S(int L, int R) //자동차 앞 부분이 아래쪽을 향함
{
		y--;
	printf("S방향\t(%d, %d)\n", x, y);
}
void Direction(int L, int R) // 왼쪽 회전 오른쪽 회전의 횟수로 차량의 앞부분의 방향을 구별하는 함수
{
	int Left = L;
	int Right = R;
	LCount = LCount % 4;
	RCount = RCount % 4;
	if (Left - Right == 1 || Left - Right == -3)
		W(x, y);
	else if (Right - Left == 1 || Right - Left == -3)
		E(x, y);
	else if (Left - Right == 2 || Left - Right == - 2)
		S(x, y);
	else
		N(x, y);
}
int main()
{
	FILE *pFile = NULL;

	pFile = fopen("c://move.txt", "r"); // 텍스트 파일 가져오기
	if (pFile == NULL)
	{
		printf("에러입니다.\n");// 에러 처리
	}
	else
	{
		char direction;

		while (!feof(pFile))
		{
			direction = fgetc(pFile);
			if (direction == 'L') // L방향일 경우
				Direction(++LCount, RCount);
			else if (direction == 'R') // R방향일 경우
				Direction(LCount, ++RCount);
			else if (direction == 'F') // F방향일 경우
				Direction(LCount, RCount);
		}
		printf("\n최종 위치: ( %d, %d )\n", x, y);
		//printf("LCount: %d \nRCount: %d \n", LCount, RCount);
		fclose(pFile);
	}

	return 0;
}