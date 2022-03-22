#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt,putmouse;//时间相关量，必须全局定义
class boomap
{
	public:
		int mp[500][500]={
			{0,0,2,1,1,1,2,2,0,1,1,1,0,2,2,1,},
			{2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,},
			{0,1,0,1,2,1,1,0,0,1,1,1,2,0,1,0,},
			{0,2,0,0,2,1,2,0,0,2,0,1,2,1,1,0,},
			{0,1,1,1,2,1,0,2,0,1,1,1,2,1,0,2,},
			{2,2,2,2,2,1,2,0,2,2,2,2,2,1,2,0,},
			{1,1,2,2,2,2,2,1,1,1,2,2,2,1,2,1,},
			{0,0,2,1,1,1,2,1,1,1,1,2,0,2,2,1,},
			{0,0,2,1,1,1,2,1,1,1,1,0,0,2,2,1,},
			{2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,},
			{0,1,0,1,2,1,1,0,0,1,1,1,2,1,1,0,},
			{0,2,0,1,2,1,2,0,0,2,0,1,2,1,2,0,},
			{0,1,1,1,2,1,0,2,0,1,1,1,0,1,0,2,},
			{2,2,2,2,2,1,2,0,2,2,2,2,0,0,2,0,},
			{1,1,2,2,2,2,2,1,1,1,2,2,2,1,2,1,},
			{1,1,2,2,2,2,2,1,1,1,2,2,2,1,2,1,},
			{0,0,2,1,1,1,2,2,0,1,1,1,0,2,2,1,}};
		int hl;
		void set_boomap(int x)
		{
			hl=x;
			ffor(i,1,hl)mp[1][i]=mp[i][1]=mp[i][hl]=mp[hl][i+1]=1;
			return;
		}
		bool move_able(int x,int y)
		{return mp[y][x]==0;}
		void putit(int a,int b,int c,int d)
		{
			ffor(i,1,hl)
			{
				ffor(j,1,hl)
				{
					 if(a==j&&b==i){putchar('■');putchar('■');}
				else if(c==j&&d==i){putchar('@');putchar('@');}
				else if(mp[i][j]==1){putchar('#');putchar('#');}
				else if(mp[i][j]==2){putchar('[');putchar(']');}
				else {putchar(' ');putchar(' ');}
				}putchar('\n');
			}
		}
		void breakwall(int x,int y)
		{
			return;
		}
}mymap;
class player
{
	public: 
		int px,py;
		int speed,moveturn;
		int type;
		int power;
		void set_player(int x,int y,int z=5,int pw=1)
		{
			px=x;
			py=y;
			speed=z;
			power=pw;
			return;
		}
		void move(int x=0)
		{
			x=type;
			
			if(moveturn<10-speed){moveturn++;return;}else moveturn=0;
			if (x == 1&&mymap.move_able(px,py-1))py--;
			else if (x == 2&&mymap.move_able(px+1,py))px++;
			else if (x == 3&&mymap.move_able(px-1,py))px--;
			else if (x == 4&&mymap.move_able(px,py+1))py++;
			else return;
		}
		void putboom(int x=0)
		{
			return;
		}
};
class boom
{
	public:
		int px,py;
		int power;
		int boomclock;
		void boomit()
		{
			return;
		}
};

//class props

//class bots
player player1;
player player2;
void deal_with_input()
{
	if(_kbhit())
	{
			char ch = _getch();
			//玩家1键入
			 if (ch == 'w')player1.type=1;
		else if (ch == 'd')player1.type=2;
		else if (ch == 'a')player1.type=3;
		else if (ch == 's')player1.type=4;
		else if (ch == 'q')player1.type=0;
		else if (ch == 'e')player1.px=3,player1.py=3;
		else if(int(ch)==10)player1.putboom();
			//玩家2键入
			 if (ch == 'i')player2.type=1;
		else if (ch == 'l')player2.type=2;
		else if (ch == 'j')player2.type=3;
		else if (ch == 'k')player2.type=4;
		else if (ch == 'o')player2.type=0;
		else if (ch == 'u')player2.px=mymap.hl-3,player2.py=mymap.hl-3;
		else if(int(ch)==32)player2.putboom();
	}
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = 1;    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}
void init()
{
	system("color 0B");
	HideCursor();
	mymap.set_boomap(15);
	player1.set_player(3,3);
	player2.set_player(mymap.hl-3,mymap.hl-3);
}
void playscreen()
{
	if(putmouse>10){HideCursor();putmouse=0;}else putmouse++;//清除光标
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 相当于函数gotoxy (0,0);

	player1.move();
	player2.move();
	mymap.putit(player1.px,player1.py,player2.px,player2.py);
}
int main() {
	init();
	while(true)
	{
		deal_with_input();
		playscreen();

	}
	return 0;
}