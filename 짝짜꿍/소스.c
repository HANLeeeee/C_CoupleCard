#include<stdio.h>      //printf, scanf
#include<stdlib.h>      //rand�Լ� �̿�
#include<windows.h>      //system���
#include<conio.h>      //Ű�����Է½� ȭ���� �̵�
#include<time.h>      //srand�Լ��̿�


#define Esc 27
#define Enter 13
#define COL GetStdHandle(STD_OUTPUT_HANDLE)     //��������
#define ��� SetConsoleTextAttribute(COL, 0x0002);
#define ����ȸ�� SetConsoleTextAttribute(COL, 0x0007);
#define ȸ�� SetConsoleTextAttribute(COL, 0x0008);
#define ���λ� SetConsoleTextAttribute(COL, 0x000a);
#define ����� SetConsoleTextAttribute(COL, 0x000e);
#define ��� SetConsoleTextAttribute(COL, 0x00);

int key;
int score = 0;
int lastscore = 0;
int bestscore = 0;

void firstpage_draw();
void gameover_draw();
void levelup_draw(int(*card_b)[8]);

void firstpage();      //ù������ȭ��
void gameover();      //���ӳ�����
void Q();            //���ӵ��߹���â
void how();			 //���۹�

void gamestart();      //���ӽ���
void game();         //�����Լ�

void xpage(int(*card_b)[8]);
void checkpage(int ix1, int iy1, int ix2, int iy2, int nn1, int nn2);
int re = 0;
int lv = 1;      //����
int a, b;      //���ο� ����
int inputx1, inputy1, inputx2, inputy2;   //�Է°�
int n1, n2;      //ī��� ����
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
			����� firstpage_draw();
			���λ� printf("                                   ��	GAME START\n");
			����ȸ�� printf("                                   	���۹�\n");
			����ȸ�� printf("	                                ������\n\n\n\n       ");
			����ȸ�� printf("                       �� : �޴� Ŀ�� ���� �̵�\n\n");
			����ȸ�� printf("                              �� : �޴� Ŀ�� �Ʒ��� �̵�\n\n");
			����ȸ�� printf("                                   Enter : �޴� ����\n\n\n\n\n");
			����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");

		}
		else if (select == 1)
		{
			����� firstpage_draw();
			����ȸ�� printf("                                   	GAME START\n");
			���λ� printf("                                   ��	���۹�\n");
			����ȸ�� printf("	                                ������\n\n\n\n       ");
			����ȸ�� printf("                       �� : �޴� Ŀ�� ���� �̵�\n\n");
			����ȸ�� printf("                              �� : �޴� Ŀ�� �Ʒ��� �̵�\n\n");
			����ȸ�� printf("                                   Enter : �޴� ����\n\n\n\n\n");
			����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
		}
		else if (select == 2)
		{
			����� firstpage_draw();
			����ȸ�� printf("                                   	GAME START\n");
			����ȸ�� printf("		                        ���۹�\n");
			���λ� printf("                                   ��	������\n\n\n\n      ");
			����ȸ�� printf("                        �� : �޴� Ŀ�� ���� �̵�\n\n");
			����ȸ�� printf("                              �� : �޴� Ŀ�� �Ʒ��� �̵�\n\n");
			����ȸ�� printf("                                   Enter : �޴� ����\n\n\n\n\n");
			����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
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
	����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�\n\n\n\n");
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
	int(*card_b)[8] = card_back;         //ī��޸�迭�ʱ�ȭ

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

		����ȸ�� printf("\n\n\n < x��ǥ�� �����Է��� �� y��ǥ�� �Է��ϸ� �ϳ��� ī�� ��ǥ�� �ϼ��ȴٰ� �ϳ׿� > \n");

		while (1)
		{

			re = 0;
			while (re == 0)
			{
				����ȸ�� printf("\n# ù��° ī���� ��ǥ�� �Է��Ͻÿ�\n");
				scanf_s("  %d   %d", &inputx1, &inputy1);

				if (card_number[8 - inputy1][inputx1 - 1] != 0)
					re++;
				else
				{
					system("cls");
					xpage(card_back);
					����� printf("\n\n\n ����- �ȹٷ� ���ðԳ�");
				}

			}
			re = 0;
			while (re == 0)
			{
				����ȸ�� printf("\n# �ι�° ī���� ��ǥ�� �Է��Ͻÿ�\n");
				scanf_s("  %d   %d", &inputx2, &inputy2);

				if (card_number[8 - inputy2][inputx2 - 1] != 0)
					re++;
				else
				{
					system("cls");
					xpage(card_back);
					����� printf("\n\n\n ����-������--- �ȹٷ� ���ðԳ�");
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
			printf("\n\n\t               �̹� ���� ¦ ���� : %d\n", lv);
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

	int done = 0;                                 //���ڸ� �Է��ϴ� ī�尳��
	int cardnum = 65;                               //ī���ȣ
	int cardtime = 0;                              //���ڰ� 2�� ���Դ���

	while (done != (2 * lv))                        //done�� 16�̵Ǹ� ��
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
		����ȸ�� printf("%d��\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			printf("%c\t", card_number[a][b]);
		}
		printf("\n\n\n");
	}
	printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	while (num2 <= 8)
	{
		printf("%d\t", num2);
		num2++;
	}
}


void xpage(int(*card_b)[8])         //ī���� �޸�
{
	int num1 = 8;
	int num2 = 0;

	for (a = 0; a < 8; a++)
	{
		printf("%d��\t", num1);
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
	printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
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
		����ȸ�� printf("%d��\t", num1);
		num1--;
		for (b = 0; b < 8; b++)
		{
			if (card_number[a][b] != 0)
			{
				if ((a == iy1) && (b == ix1))
				{
					���λ� printf("%c\t", nn1);
				}
				else if ((a == iy2) && (b == ix2))
				{
					���λ� printf("%c\t", nn2);
				}
				else
					printf("%c\t", 88);
			}
			else
				printf("\t");
		}
		printf("\n\n\n");
	}
	����ȸ�� printf("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
	while (num2 <= 8)
	{
		����ȸ�� printf("%d\t", num2);
		num2++;
	}
}

void levelup_draw(int(*card_b)[8])
{
	system("cls");
	����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�\n\n\n\n");
	printf("   *                                            *                 *         *   **********\n");
	printf("   *                                            *                 *         *   *         *\n");
	printf("   *                                            *                 *         *   *         *\n");
	printf("   *            *******  *       *   *******    *                 *         *   **********\n");
	printf("   *           *********  *     *   *********   *                 *         *   *\n");
	printf("   *           *           *   *    *           *                  *       *    *\n");
	printf("   **********   *******      *       *******    *                   *******     *\n\n");
	���λ� printf("\n\n                         ������������ �������� �Ǽ̽��ϴ� ����������������\n\n\n\n");
	����ȸ�� printf("                              ���͸� ������ ���� ������ �Ѿ�ϴ�.\n\n");
	printf("                              ESC�� ������ ��������â���� �Ѿ�ϴ�.\n\n\n\n");
	����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");

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
			���λ� printf("                                   ��	RESTART\n");
			����ȸ�� printf("                                   	HOME\n");
			����ȸ�� printf("	                                ������\n\n\n\n       ");
			����ȸ�� printf("                       �� : �޴� Ŀ�� ���� �̵�\n\n");
			����ȸ�� printf("                              �� : �޴� Ŀ�� �Ʒ��� �̵�\n\n");
			����ȸ�� printf("                                   Enter : �޴� ����\n\n\n\n\n");
			����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
		}


		else if (select == 1)
		{
			gameover_draw();
			����ȸ�� printf("                                   	RESTART\n");
			���λ� printf("                                   ��	HOME\n");
			����ȸ�� printf("	                                ������\n\n\n\n       ");
			����ȸ�� printf("                       �� : �޴� Ŀ�� ���� �̵�\n\n");
			����ȸ�� printf("                              �� : �޴� Ŀ�� �Ʒ��� �̵�\n\n");
			����ȸ�� printf("                                   Enter : �޴� ����\n\n\n\n\n");
			����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
		}

		else if (select == 2)
		{
			gameover_draw();
			����ȸ�� printf("                                   	RESTART\n");
			����ȸ�� printf("		                        HOME\n");
			���λ� printf("                                   ��	������\n\n\n\n      ");
			����ȸ�� printf("                        �� : �޴� Ŀ�� ���� �̵�\n\n");
			����ȸ�� printf("                              �� : �޴� Ŀ�� �Ʒ��� �̵�\n\n");
			����ȸ�� printf("                                   Enter : �޴� ����\n\n\n\n\n");
			����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�");
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
	����� printf("�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�\n\n\n\n");
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
	���  printf("�������������������������������������������������\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                         ");
	����ȸ�� printf("[���۹�]");
	��� printf("                                           ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                           ");
	����ȸ�� printf("1. ���� ���ĺ����� �ڸ��� ����Ѵ�.");
	��� printf("                              ��\n");
	��� printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                           ");
	����ȸ�� printf("2. ����� ���ĺ��� ��ǥ�� �Է��Ѵ�.");
	��� printf("                              ��\n");
	��� printf("��                                                                                            ��\n");
	printf("��                            ");
	����ȸ�� printf("- (x��y��)");
	��� printf("                                                      ��\n");
	printf("��                            ");
	����ȸ�� printf("=> x = ���������� Ŀ���� ��, y = �������� Ŀ���� ��             ");
	��� printf("��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                           ");
	����ȸ�� printf("3. �����̸� �Է��� ���ĺ� �ڸ��� X => O�� �ٲ��.                ");
	��� printf("��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                             ");
	����ȸ�� printf("* Esc�� ������ ó�� ȭ������ ���ư��ϴ�.");
	��� printf("                       ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("��                                                                                            ��\n");
	printf("�������������������������������������������������");
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
			��� printf("                                ��������������������\n");
			printf("                                ��                                  ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��");
			����ȸ�� printf("         ��   CONTINUE");
			��� printf("            ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��          ");
			����ȸ�� printf("    Exit         ");
			��� printf("       ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��������������������\n");
			printf("                                       ������ ó������ ���۵˴ϴ�.\nn");
		}
		else if (select == 1)
		{
			printf("\n\n\n\n\n\n\n\n");
			��� printf("                                ��������������������\n");
			printf("                                ��                                  ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��            ");
			����ȸ�� printf("  CONTINUE   ");
			��� printf("         ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��        ");
			����ȸ�� printf(" ��   Exit       ");
			��� printf("         ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��                                  ��\n");
			printf("                                ��������������������\n");
			printf("                                       ������ ó������ ���۵˴ϴ�.\n\n");
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
