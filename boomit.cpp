#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt, jym = 1, h = 30, type1, type2, slowmove1, slowmove2, movespeed1 = 1, movespeed2 = 5,putmouse;
int boomap[1000][1000], mx = 3, my = 3, yx = h - 3, yy = h - 3;

void deal_input1() {
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
		else if (ch == 'q')
			type1=0;
		else if (ch == 'e')
			mx = my = 3;
		else if(int(ch)==10)
			return;
		if (ch == 'i')
			type2 = 5;
		else if (ch == 'l')
			type2 = 6;
		else if (ch == 'j')
			type2 = 7;
		else if (ch == 'k')
			type2 = 8;
		else if (ch == 'o')
			type2=0;
		else if (ch == 'u')
			yx = yy = h-3;
		else if(int(ch)==32)
			return;
	}
	return;
}
void deal_input2() {
	char ch;
	if (_kbhit()) {
		ch = _getch();
		if (ch == 'i')
			type2 = 5;
		else if (ch == 'l')
			type2 = 6;
		else if (ch == 'j')
			type2 = 7;
		else if (ch == 'k')
			type2 = 8;
		else if (ch == 'o')
			type2=0;
		else if (ch == 'p')
			yx = yy = h-3;
		int k = int(ch);
		if (k == 32)
			return;
	}
	return;
}
void HideCursor()
{
 CONSOLE_CURSOR_INFO cursor;    
 cursor.bVisible = FALSE;    
 cursor.dwSize = 1;    
 HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
 SetConsoleCursorInfo(handle, &cursor);
}
void display() {
	if(putmouse>20){HideCursor();putmouse=0;}else putmouse++;
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 相当于函数gotoxy (0,0);

	if (slowmove1 > 5 - movespeed1 ) {
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

	if (slowmove2 > 5 - movespeed2 ) {
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
		ffor(j, 1, h) {
			if (mx == j && my == i)
				{putchar('■');putchar('■');}
			else if (yx == j && yy == i)
				{putchar('$');putchar('&');}
			else if (i == 1 || i == h || j == 1 || j == h)
				{putchar('#');putchar('#');}
			else
				{putchar(' ');putchar(' ');}
		}
		putchar('\n');
	}
}


int main() {
	/*while (1)
	{
		Show();
		InputWithData();
		InputWithoutData();
		system("cls");			}*/
	system("color 0B");
	HideCursor();
	while (1) {
		display();
		//deal_input2();
		deal_input1();
		/*cnt++;
		if(cnt==jym)
		{
			deal_time();
			cnt=0;
		}cnt = 0;*/
		
	}
	return 0;
}

