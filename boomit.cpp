#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt, jym = 1, h = 20;
int boomap[1000][1000], mx = 3, my = 3;



void deal_input() {
	char ch;
	if (_kbhit()) {
		ch = _getch();
		if (ch == 'w' || ch == 'H')
			my--;
		if (ch == 'd' || ch == 'M')
			mx++;
		if (ch == 'a' || ch == 'K')
			mx--;
		if (ch == 's' || ch == 'P')
			my++;
		int k = int(ch);
		if (k == 10 || k == 32)
			return;
	}
	return;
}



void display() {
	gotoxy(0, 0);
	ffor(i, 1, h) {
		ffor(j, 1, 2 * h) {
			if (mx == j && my == i)
				cout << "s";
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
		deal_input();
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

