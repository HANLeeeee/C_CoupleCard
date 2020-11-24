#include<stdio.h>      //printf, scanf
#include<stdlib.h>      //rand함수 이용
#include<windows.h>      //system사용
#include<conio.h>      //키보드입력시 화면이 이동
#include<time.h>      //srand함수이용

//깃허브 

#define Esc 27
#define Enter 13
#define COL GetStdHandle(STD_OUTPUT_HANDLE)     //색깔지정
#define 녹색 SetConsoleTextAttribute(COL, 0x0002);
#define 밝은회색 SetConsoleTextAttribute(COL, 0x0007);
#define 회색 SetConsoleTextAttribute(COL, 0x0008);
#define 연두색 SetConsoleTextAttribute(COL, 0x000a);
#define 노란색 SetConsoleTextAttribute(COL, 0x000e);
#define 흰색 SetConsoleTextAttribute(COL, 0x00);

int key;
int score = 0;
int lastscore = 0;
int bestscore = 0;

void firstpage_draw();
void gameover_draw();
void levelup_draw(int(*card_b)[8]);

void firstpage();      //첫페이지화면
void gameover();      //게임끝날때
void Q();            //게임도중묻는창
void how();			 //조작법

void gamestart();      //게임시작
void game();         //게임함수

void xpage(int(*card_b)[8]);
void checkpage(int ix1, int iy1, int ix2, int iy2, int nn1, int nn2);
int re = 0;
int lv = 1;      //레벨
int a, b;      //가로와 세로
int inputx1, inputy1, inputx2, inputy2;   //입력값
int n1, n2;      //카드속 숫자
int timer = 1000;

int card_number[8][8] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main(void)
{
	firstpage();

	return 0;
}

void firstpage()
{
	int select = 0, ch = 0;
	while (1)
	{
		system("cls");

		if (select == 0)
		{
			노란색 firstpage_draw();
			연두색 printf("                                   ▶	GAME START\n");
			밝은회색 printf("                                   	조작법\n");
			밝은회색 printf("	                                나가기\n\n\n\n       ");
			밝은회색 printf("                       ⓦ : 메뉴 커서 위로 이동\n\n");
			밝은회색 printf("                              ⓢ : 메뉴 커서 아래로 이동\n\n");
			밝은회색 printf("                                   Enter : 메뉴 선택\n\n\n\n\n");
			노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");

		}
		else if (select == 1)
		{
			노란색 firstpage_draw();
			밝은회색 printf("                                   	GAME START\n");
			연두색 printf("                                   ▶	조작법\n");
			밝은회색 printf("	                                나가기\n\n\n\n       ");
			밝은회색 printf("                       ⓦ : 메뉴 커서 위로 이동\n\n");
			밝은회색 printf("                              ⓢ : 메뉴 커서 아래로 이동\n\n");
			밝은회색 printf("                                   Enter : 메뉴 선택\n\n\n\n\n");
			노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		}
		else if (select == 2)
		{
			노란색 firstpage_draw();
			밝은회색 printf("                                   	GAME START\n");
			밝은회색 printf("		                        조작법\n");
			연두색 printf("                                   ▶	나가기\n\n\n\n      ");
			밝은회색 printf("                        ⓦ : 메뉴 커서 위로 이동\n\n");
			밝은회색 printf("                              ⓢ : 메뉴 커서 아래로 이동\n\n");
			밝은회색 printf("                                   Enter : 메뉴 선택\n\n\n\n\n");
			노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		}



		ch = _getch();
		if (ch == 'w')
		{
			if (select == 0) select = 2;
			else select--;
		}
		else if (ch == 's')
		{
			if (select == 2) select = 0;
			else select++;
		}
		else if (ch == Enter && select == 0)
		{
			system("cls");
			gamestart();
		}
		else if (ch == Enter && select == 1)
		{
			how();
		}
		else if (ch == Enter && select == 2)
		{
			exit(0);
		}
	}
}

void firstpage_draw()
{
	노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n\n");
	printf("     ** ** ** **  ***********  *     ************* *       *************     ** ** ** **\n");
	printf("     ** ** ** **    * * * *    *        * * * *    *             *     *     ** ** ** **\n");
	printf(" **  ** ** ** **   *   **  *   ****    *   **  *   *             *     *     ** ** ** **  **\n");
	printf("  ** ** ** ** **  *    **   *  *      *    **   *  ****   *****************  ** ** ** ** **\n");
	printf("   *************               *     *      *    * *              *          *************\n");
	printf("    ************   *************                   *              *          ************\n");
	printf("    ************               *                   *             ***         ************\n");
	printf("     **********                *                   *            *   *         **********\n");
	printf("      ********                 *                   *             ***           ********\n\n\n\n\n");
}


void gamestart()
{
	int card_back[8][8] = { 88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
		88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
		88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,
		88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88 };
	int(*card_b)[8] = card_back;         //카드뒷면배열초기화

	int clear;
	int i, j;
	int fail = 0;
	while (1)
	{
		system("cls");
		game();
		Sleep((timer));
		system("cls");
		xpage(card_back);

		밝은회색 printf("\n\n\n < x좌표를 먼저입력한 후 y좌표를 입력하면 하나의 카드 좌표가 완성된다고 하네요 > \n");

		while (1)
		{

			re = 0;
			while (re == 0)
			{
				밝은회색 printf("\n# 첫번째 카드의 좌표를 입력하시오\n");
				scanf_s("  %d   %d", &inputx1, &inputy1);

				if (card_number[8 - inputy1][inputx1 - 1] != 0)
					re++;
				else
				{
					system("cls");
					xpage(card_back);
					노란색 printf("\n\n\n 삐익- 똑바로 보시게나");
				}

			}
			re = 0;
			while (re == 0)
			{
				밝은회색 printf("\n# 두번째 카드의 좌표를 입력하시오\n");
				scanf_s("  %d   %d", &inputx2, &inputy2);

				if (card_number[8 - inputy2][inputx2 - 1] != 0)
					re++;
				else
				{
					system("cls");
					xpage(card_back);
					노란색 printf("\n\n\n 삐익-삐이익--- 똑바로 보시게나");
				}

			}

			inputx1 = inputx1 - 1;
			inputy1 = 8 - inputy1;
			inputx2 = inputx2 - 1;
			inputy2 = 8 - inputy2;
			n1 = card_number[inputy1][inputx1];
			n2 = card_number[inputy2][inputx2];

			system("cls");

			checkpage(inputx1, inputy1, inputx2, inputy2, n1, n2);

			if (n1 == n2)
			{
				Sleep(2000);
				system("cls");
				card_back[inputy1][inputx1] = 79;
				card_back[inputy2][inputx2] = 79;

			}

			else
			{

				fail++;
				if (fail == 5)
				{
					Sleep(2500);
					system("cls");
					gameover();
				}
				else
				{
					Sleep(2500);
					system("cls");
				}
			}
			xpage(card_back);


			clear = 0;
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 8; j++)
				{
					if (card_back[i][j] == 79)
					{
						clear++;
						timer += 1000;
					}
				}
			}
			printf("\n\n\t               이번 레벨 짝 개수 : %d\n", lv);
			if (clear == (2 * lv))
			{
				Sleep(2000);
				lv++;


				system("cls");
				levelup_draw(card_b);
			}
			else if (clear == 65)
				gameover();
		}
	}
}



void game()
{
	int x, y;

	int done = 0;                                 //숫자를 입력하는 카드개수
	int cardnum = 65;                               //카드번호
	int cardtime = 0;                              //숫자가 2번 나왔는지

	while (done != (2 * lv))                        //done이 16이되면 끝
	{
		while (1)
		{
			srand(time(NULL));
			x = rand() % 8;
			y = rand() % 8;
			if (card_number[y][x] == 0)
			{
				card_number[y][x] = cardnum;
				done++;
				if (cardtime == 1)
				{
					cardtime = 0;
					cardnum++;
				}
				else
					cardtime = 1;
			}
			else break;
			if (done == (2 * lv))
				break;
		}
	}

	int num1 = 8;
	int num2 = 0;

	for (a = 0; a < 8; a++)
	{
		밝은회색 printf("%d│\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			printf("%c\t", card_number[a][b]);
		}
		printf("\n\n\n");
	}
	printf("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─\n");
	while (num2 <= 8)
	{
		printf("%d\t", num2);
		num2++;
	}
}


void xpage(int(*card_b)[8])         //카드의 뒷면
{
	int num1 = 8;
	int num2 = 0;

	for (a = 0; a < 8; a++)
	{
		printf("%d│\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			if (card_number[a][b] != 0)
				printf("%c\t", *(*(card_b + a) + b));
			else
				printf("\t");
		}
		printf("\n\n\n");
	}
	printf("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─\n");
	while (num2 <= 8)
	{
		printf("%d\t", num2);
		num2++;
	}
}



void checkpage(int ix1, int iy1, int ix2, int iy2, int nn1, int nn2)
{
	card_number[iy1][ix1] = nn1;
	card_number[iy2][ix2] = nn2;

	int num1 = 8;
	int num2 = 0;

	for (a = 0; a < 8; a++)
	{
		밝은회색 printf("%d│\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			if (card_number[a][b] != 0)
			{
				if ((a == iy1) && (b == ix1))
				{
					연두색 printf("%c\t", nn1);
				}
				else if ((a == iy2) && (b == ix2))
				{
					연두색 printf("%c\t", nn2);
				}
				else
					printf("%c\t", 88);
			}
			else
				printf("\t");
		}
		printf("\n\n\n");
	}
	밝은회색 printf("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─\n");
	while (num2 <= 8)
	{
		밝은회색 printf("%d\t", num2);
		num2++;
	}
}

void levelup_draw(int(*card_b)[8])
{
	system("cls");
	노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n\n");
	printf("   *                                            *                 *         *   **********\n");
	printf("   *                                            *                 *         *   *         *\n");
	printf("   *                                            *                 *         *   *         *\n");
	printf("   *            *******  *       *   *******    *                 *         *   **********\n");
	printf("   *           *********  *     *   *********   *                 *         *   *\n");
	printf("   *           *           *   *    *           *                  *       *    *\n");
	printf("   **********   *******      *       *******    *                   *******     *\n\n");
	연두색 printf("\n\n                         ㅊㅋㅊㅋㅊㅋ 레벨업이 되셨습니다 ㅊㅋㅊㅋㅊㅋㅊㅋ\n\n\n\n");
	밝은회색 printf("                              엔터를 누르면 다음 레벨로 넘어갑니다.\n\n");
	printf("                              ESC를 누르면 게임종료창으로 넘어갑니다.\n\n\n\n");
	노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");

	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			card_number[i][j] = 0;
			card_b[i][j] = 88;
		}
	}


	while (1) {
		if (_kbhit())
		{
			key = _getch();
			if (key == Enter)
				gamestart();
			else if (key == Esc)
				Q();
		}
	}


}


void gameover()
{
	int select = 0, ch = 0;

	while (1)
	{
		system("cls");


		if (select == 0)
		{
			gameover_draw();
			연두색 printf("                                   ▶	RESTART\n");
			밝은회색 printf("                                   	HOME\n");
			밝은회색 printf("	                                나가기\n\n\n\n       ");
			밝은회색 printf("                       ⓦ : 메뉴 커서 위로 이동\n\n");
			밝은회색 printf("                              ⓢ : 메뉴 커서 아래로 이동\n\n");
			밝은회색 printf("                                   Enter : 메뉴 선택\n\n\n\n\n");
			노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		}


		else if (select == 1)
		{
			gameover_draw();
			밝은회색 printf("                                   	RESTART\n");
			연두색 printf("                                   ▶	HOME\n");
			밝은회색 printf("	                                나가기\n\n\n\n       ");
			밝은회색 printf("                       ⓦ : 메뉴 커서 위로 이동\n\n");
			밝은회색 printf("                              ⓢ : 메뉴 커서 아래로 이동\n\n");
			밝은회색 printf("                                   Enter : 메뉴 선택\n\n\n\n\n");
			노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		}

		else if (select == 2)
		{
			gameover_draw();
			밝은회색 printf("                                   	RESTART\n");
			밝은회색 printf("		                        HOME\n");
			연두색 printf("                                   ▶	나가기\n\n\n\n      ");
			밝은회색 printf("                        ⓦ : 메뉴 커서 위로 이동\n\n");
			밝은회색 printf("                              ⓢ : 메뉴 커서 아래로 이동\n\n");
			밝은회색 printf("                                   Enter : 메뉴 선택\n\n\n\n\n");
			노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
		}


		ch = _getch();
		if (ch == 'w')
		{
			if (select == 0) select = 2;
			else select--;
		}
		else if (ch == 's')
		{
			if (select == 2) select = 0;
			else select++;
		}
		else if (ch == Enter && select == 0)
		{
			gamestart();
		}
		else if (ch == Enter && select == 1)
		{
			firstpage();
		}
		else if (ch == Enter && select == 2)
		{
			exit(0);
		}
	}
}

void gameover_draw()
{
	노란색 printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\n\n\n");
	printf("  ********       *        *        * ********        ********  *           * ******** *******\n");
	printf(" *              * *       * *    * * *              *        *  *         *  *        *      *\n");
	printf(" *             *   *      *  *  *  * *              *        *   *       *   *        *      *\n");
	printf(" *   *****    *     *     *   **   * ********       *        *    *     *    ******** *******\n");
	printf(" *       *   *********    *        * *              *        *     *   *     *        *     *\n");
	printf(" *       *  *         *   *        * *              *        *      * *      *        *      *\n");
	printf(" ********* *           *  *        * ********        ********        *       ******** *       *\n\n\n\n\n\n\n");
}




void how()
{
	system("cls");
	녹색  printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                         ");
	밝은회색 printf("[조작법]");
	녹색 printf("                                           ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                           ");
	밝은회색 printf("1. 같은 알파벳끼리 자리를 기억한다.");
	녹색 printf("                              ■\n");
	녹색 printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                           ");
	밝은회색 printf("2. 기억한 알파벳의 좌표를 입력한다.");
	녹색 printf("                              ■\n");
	녹색 printf("■                                                                                            ■\n");
	printf("■                            ");
	밝은회색 printf("- (x값y값)");
	녹색 printf("                                                      ■\n");
	printf("■                            ");
	밝은회색 printf("=> x = 오른쪽으로 커지는 값, y = 위쪽으로 커지는 값             ");
	녹색 printf("■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                           ");
	밝은회색 printf("3. 정답이면 입력한 알파벳 자리가 X => O로 바뀐다.                ");
	녹색 printf("■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                             ");
	밝은회색 printf("* Esc를 누르면 처음 화면으로 돌아갑니다.");
	녹색 printf("                       ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■                                                                                            ■\n");
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	while (1) {
		if (_kbhit())
		{
			key = _getch();
			if (key == Esc)
			{
				firstpage();
			}
		}
	}
}

void Q()
{
	int select = 0, ech = 0;

	while (1)
	{
		system("cls");

		if (select == 0)
		{
			printf("\n\n\n\n\n\n\n\n");
			녹색 printf("                                ■■■■■■■■■■■■■■■■■■■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■");
			밝은회색 printf("         ▶   CONTINUE");
			녹색 printf("            ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■          ");
			밝은회색 printf("    Exit         ");
			녹색 printf("       ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■■■■■■■■■■■■■■■■■■■\n");
			printf("                                       게임은 처음부터 시작됩니다.\nn");
		}
		else if (select == 1)
		{
			printf("\n\n\n\n\n\n\n\n");
			녹색 printf("                                ■■■■■■■■■■■■■■■■■■■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■            ");
			밝은회색 printf("  CONTINUE   ");
			녹색 printf("         ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■        ");
			밝은회색 printf(" ▶   Exit       ");
			녹색 printf("         ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■                                  ■\n");
			printf("                                ■■■■■■■■■■■■■■■■■■■\n");
			printf("                                       게임은 처음부터 시작됩니다.\n\n");
		}
		ech = _getch();
		if (ech == 'w')
		{
			if (select == 0) select = 1;
			else select--;
		}
		else if (ech == 's')
		{
			if (select == 1) select = 0;
			else select++;
		}
		else if (ech == Enter && select == 0)
		{
			gamestart();
		}
		else if (ech == Enter && select == 1)
		{
			exit(0);
		}
	}
}
