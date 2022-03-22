#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt, jym = 1, h = 20, turn = 1, type1, type2, slowmove1, slowmove2, movespeed1 = 7, movespeed2 = 7;
int boomap[1000][1000], mx = 3, my = 3, yx = h - 3, yy = h - 3;





void deal_input1() {
	if (turn == 2)
		return;
	turn = 2;
	char ch;
	if (_kbhit()) {
		ch = _getch();
		if (ch == 'w')
			type1 = 1;
		else if (ch == 'd')
			type1 = 2;
		else if (ch == 'a')
			type1 = 3;
		else if (ch == 's')
			type1 = 4;
		else if (ch == 'b')
			mx = my = 3;
		int k = int(ch);
		if (k == 10)
			return;
	}
	return;
}





void deal_input2() {
	if (turn == 1)
		return;
	turn = 1;
	char ch;
	if (_kbhit()) {
		ch = _getch();
		if (ch == 'H')
			type2 = 5;
		else if (ch == 'M')
			type2 = 6;
		else if (ch == 'K')
			type2 = 7;
		else if (ch == 'P')
			type2 = 8;
		else if (ch == '/')
			yx = yy = 3;
		int k = int(ch);
		if (k == 32)
			return;
	}
	return;
}





void display() {
	gotoxy(0, 0);
	if (slowmove1 > 15 - movespeed1 ) {
		if (type1 == 1)
			my--;
		else if (type1 == 2)
			mx++;
		else if (type1 == 3)
			mx--;
		else if (type1 == 4)
			my++;

		slowmove1 = 0;
	} else
		slowmove1++;

	if (slowmove2 > 15 - movespeed2 ) {
		if (type2 == 5)
			yy--;
		else if (type2 == 6)
			yx++;
		else if (type2 == 7)
			yx--;
		else if (type2 == 8)
			yy++;
		slowmove2 = 0;
	} else
		slowmove2++;

	ffor(i, 1, h) {
		ffor(j, 1, 2 * h) {
			if (mx == j && my == i)
				cout << "@";
			else if (yx == j && yy == i)
				cout << "&";
			else if (i == 1 || i == h || j == 1 || j == 2 * h)
				cout << "#";
			else
				cout << " ";
		}
		cout << "\n";
	}
}





void init() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);
}





int main() {
	/*while (1)
	{
		Show();
		InputWithData();
		InputWithoutData();
		system("cls");			}*/
	init();
	while (1) {
		display();
		deal_input1();
		deal_input2();
		/*cnt++;
		if(cnt==jym)
		{
			deal_time();
			cnt=0;
		}*/
		cnt = 0;
	}
	return 0;
}

