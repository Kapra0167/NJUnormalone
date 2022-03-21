#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt, jym = 1, h = 20, turn = 1;
int boomap[1000][1000], mx = 3, my = 3, yx = h - 3, yy = h - 3;








void deal_input1() {
	if (turn == 2)
		return;
	turn = 2;
	char ch;
	if (_kbhit()) {
		ch = _getch();
		if (ch == 'w')
			my--;
		else if (ch == 'd')
			mx++;
		else if (ch == 'a')
			mx--;
		else if (ch == 's')
			my++;
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
			yy--;
		else if (ch == 'M')
			yx++;
		else if (ch == 'K')
			yx--;
		else if (ch == 'P')
			yy++;
		int k = int(ch);
		if (k == 32)
			return;
	}
	return;
}








void display() {
	gotoxy(0, 0);
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

