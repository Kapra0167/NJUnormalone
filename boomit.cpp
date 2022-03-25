#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt,putmouse;//时间相关量，必须全局定义
class boomap
{
	public:
		int mp[500][500]=
			{//初始化一个精美的16*16地图
			{0,0,2,1,1,1,2,2,0,1,1,1,0,2,2,1,},
			{2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,},
			{0,1,0,1,2,1,1,0,0,1,1,2,2,0,1,0,},
			{0,2,0,0,2,2,2,0,0,2,0,2,2,1,1,0,},
			{0,2,1,2,2,2,0,2,0,2,1,1,2,2,0,2,},
			{2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,0,},
			{1,1,2,2,2,2,1,1,1,2,2,2,2,1,2,1,},
			{0,0,2,1,2,2,1,1,1,2,2,2,0,2,2,1,},
			{0,0,2,1,2,2,1,1,1,2,2,0,0,2,2,1,},
			{2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,},
			{0,1,0,2,2,2,1,0,0,1,2,2,2,1,2,0,},
			{0,2,0,2,2,2,2,0,0,2,0,2,2,1,2,0,},
			{0,1,1,2,2,2,0,2,0,1,1,1,0,1,0,2,},
			{2,2,2,2,2,1,2,0,2,2,2,2,0,0,2,0,},
			{1,1,2,2,2,2,2,2,1,1,2,2,2,1,2,1,},
			{1,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,},
			{0,0,2,1,1,1,2,2,0,1,1,1,0,2,2,1,}};
		int hl;//正方形边长
		void set_boomap(int x)//初始化地图
		{
			hl=x;
			ffor(i,1,hl)
			mp[1][i]=mp[i][1]=
			mp[i][hl]=mp[hl][i+1]=1;
			return;
		}
		bool move_able(int x,int y)
		{return mp[y][x]!=1&&mp[y][x]!=2;}
		void boooomit(int y,int x,int power)//booooom！！
		{
			mp[x][y]=0;
			//确定爆炸范围
			int up=x-power;
			int down=x+power;
			int lf=y-power;
			int rt=y+power;
			if(up<=1)up=2;
			if(down>=hl)down=hl-1;
			if(lf<=1)lf=2;
			if(rt>=hl)rt=hl-1;

			ffor(i,x,down)//分开两端光束，使其在硬墙断开
			{
				if(mp[i][y]==0)mp[i][y]=198;
				else if(mp[i][y]==1)break;
				else if(mp[i][y]==2&&(rand()%3==1))mp[i][y]=202;//产生道具
				else if(mp[i][y]==2&&(rand()%5==2))mp[i][y]=203;//产生道具
				else if(mp[i][y]==2)mp[i][y]=198;
			}
			for(int i=x;i>=up;i--)
			{
				if(mp[i][y]==0)mp[i][y]=198;
				else if(mp[i][y]==1)break;
				else if(mp[i][y]==2&&(rand()%3==1))mp[i][y]=202;
				else if(mp[i][y]==2&&(rand()%5==2))mp[i][y]=203;
				else if(mp[i][y]==2)mp[i][y]=198;
			}
			ffor(i,y,rt)
			{
				if(mp[x][i]==0)mp[x][i]=198;
				else if(mp[x][i]==1)break;
				else if(mp[x][i]==2&&(rand()%3==1))mp[x][i]=202;
				else if(mp[x][i]==2&&(rand()%5==2))mp[x][i]=203;
				else if(mp[x][i]==2)mp[x][i]=198;
			}
			for(int i=y;i>=lf;i--)
			{
				if(mp[x][i]==0)mp[x][i]=198;
				else if(mp[x][i]==1)break;
				else if(mp[x][i]==2&&(rand()%3==1))mp[x][i]=202;
				else if(mp[x][i]==2&&(rand()%5==2))mp[x][i]=203;
				else if(mp[x][i]==2)mp[x][i]=198;
			}
			return;
		}
		int put_screen(int a,int b,int c,int d);
}mymap;
class boom
{
	public:
		int px,py;
		int power;
		int boomclock;
		void set_boom(int a,int b,int c,int d=1)//放置炸弹
		{
			px=a;py=b;power=c;boomclock=d;
			mymap.mp[b][a]=3;
			return;
		}
		void boomit()
		{
			if(boomclock>0&&boomclock<200)boomclock++;//炸弹倒计时
			else if(boomclock>0){mymap.boooomit(px,py,power);boomclock=0;}
			return;
		}
}boom1,boom2,boom3,boom4;
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
		void move(int x=0)//根据type值行动
		{
			if(moveturn<20-speed){moveturn++;return;}else moveturn=0;//设置移动间隔，控制速度
			if (type == 1&&mymap.move_able(px,py-1)){py--;type=0;}
			else if (type == 2&&mymap.move_able(px+1,py)){px++;type=0;}
			else if (type == 3&&mymap.move_able(px-1,py)){px--;type=0;}
			else if (type == 4&&mymap.move_able(px,py+1)){py++;type=0;}
			else return;
		}
		boom putboom()
		{
			boom newboom;
			newboom.set_boom(px,py,power);
			return newboom;
		}
}player1,player2;

//class bots

int boomap::put_screen(int a,int b,int c,int d)//关键步骤：打印屏幕
{
	ffor(i,1,hl)
	{
		ffor(j,1,hl)
		{
			if(a==j&&b==i)
			{
				if(mp[i][j]==0||mp[i][j]==3){putchar('■');putchar('■');}
			 	else if(mp[i][j]==4){player1.speed+=3;mp[i][j]=0;}//吃道具
			 	else if(mp[i][j]==5){player1.power++;mp[i][j]=0;}
			 	else return 1;//走入爆炸，死亡
			}
		else if(c==j&&d==i)
			{
				if(mp[i][j]==0||mp[i][j]==3){putchar('O');putchar('D');}
			 	else if(mp[i][j]==4){player2.speed+=2;mp[i][j]=0;}
			 	else if(mp[i][j]==5){player2.power++;mp[i][j]=0;}
			 	else return 2;
			}
		else if(mp[i][j]==0){putchar(' ');putchar(' ');}
		else if(mp[i][j]==1){putchar('#');putchar('#');}
		else if(mp[i][j]==2){putchar('[');putchar(']');}
		else if(mp[i][j]==3){putchar('!');putchar('!');}
		else if(mp[i][j]==4){putchar('G');putchar('D');}
		else if(mp[i][j]==5){putchar('B');putchar('M');}
		else {putchar(char(rand()%60+35));putchar(char(rand()%60+35));mp[i][j]-=6;}
		//乱码特效的光束！
		//mp值每次-6，通过设置爆炸光束的不同对6余数，确定留下的物体。
		}putchar('\n');
	}
	putchar('\n');
	//计分板
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	ffor(i,1,hl-4){putchar(' ');}printf("%d\n",100010);
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	return 0;
}
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
		else if (ch == 'c')player1.px=3,player1.py=3;//一个小小的后门
		else if(int(ch)==32&&boom1.boomclock==0)boom1=player1.putboom();
			//玩家2键入
			 if (ch == 'i')player2.type=1;
		else if (ch == 'l')player2.type=2;
		else if (ch == 'j')player2.type=3;
		else if (ch == 'k')player2.type=4;
		else if (ch == 'o')player2.type=0;
		else if (ch == 'p')player2.px=mymap.hl-3,player2.py=mymap.hl-3;//一个小小的后门
		else if(int(ch)==13&&boom2.boomclock==0)boom2=player2.putboom();
	}
}
void HideCursor()
{//清除光标
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
void end_game(int x)//游戏结束
{
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 清屏
	ffor(i,1,mymap.hl){putchar('=');putchar('=');}putchar('\n');
	ffor(i,1,mymap.hl-8){putchar(' ');}printf("player %d is dead!",x);ffor(i,1,mymap.hl){putchar(' ');}putchar('\n');
	if(x==1)x=2;else x=1;
	ffor(i,1,mymap.hl-8){putchar(' ');}printf("player %d wins!",x);ffor(i,1,mymap.hl){putchar(' ');}putchar('\n');
	ffor(i,1,mymap.hl){putchar('=');putchar('=');}putchar('\n');
	ffor(i,1,mymap.hl-1)
	{ffor(j,1,mymap.hl){putchar(' ');putchar(' ');}
	putchar('\n');}
	ffor(i,1,mymap.hl){putchar('=');putchar('=');}putchar('\n');
	return;
}
bool playscreen()
{
	if(putmouse>10){HideCursor();putmouse=0;}else putmouse++;//清除光标
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 相当于函数gotoxy (0,0);

	player1.move();
	player2.move();
	boom1.boomit();
	boom2.boomit();

	int death=mymap.put_screen(player1.px,player1.py,player2.px,player2.py);
	if(death>0){end_game(death);return false;}//返回false则游戏关闭。
	return true;
}
int main() {
	init();
	do deal_with_input();
	while(playscreen());
	return 0;
}