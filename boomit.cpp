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
			{//初始化一个精美的地图
			{1,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,},
			{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,0,2,0,2,1,2,2,2,2,2,2,1,2,2,2,2,2,0,0,0,0,1,},
			{1,0,0,0,2,1,1,1,2,2,2,2,1,2,2,2,2,2,0,0,0,0,1,},
			{1,2,0,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,0,0,0,2,1,},
			{1,2,0,2,2,2,1,1,1,1,1,2,2,2,1,1,1,1,1,2,2,2,1,},
			{1,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,2,2,2,1,1,1,1,1,0,0,0,0,0,2,1,1,1,1,2,2,2,1,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,1,1,1,2,1,},
			{1,2,1,1,2,2,1,2,2,1,1,2,1,1,2,2,2,2,2,2,2,2,1,},
			{1,2,1,1,2,1,1,2,2,1,1,1,1,1,2,2,2,2,2,2,1,1,1,},
			{1,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,2,2,2,2,2,2,2,2,0,0,0,0,0,2,2,2,1,1,2,2,2,1,},
			{1,2,2,1,1,1,1,1,2,2,0,0,0,2,2,2,2,2,2,1,2,2,1,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,1,},
			{1,2,2,0,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,2,2,0,1,1,1,1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,2,0,0,2,2,2,2,2,2,1,2,2,2,2,2,2,2,0,0,2,2,1,},
			{1,2,0,0,0,2,1,1,2,2,1,2,2,2,1,1,1,1,1,0,0,2,2,},
			{1,2,0,0,0,2,2,2,2,2,1,2,2,2,2,2,2,2,0,0,0,2,1,},
			{1,2,2,2,2,2,2,2,2,2,1,2,1,1,2,2,2,2,0,0,0,2,1,},
			{1,2,2,1,1,1,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,1,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,},};
			/*{
			{0,0,2,1,1,1,2,2,0,1,1,1,0,2,2,1,},
			{2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,},
			{0,1,0,1,2,1,1,0,0,1,1,2,0,0,1,0,},
			{0,2,0,0,2,2,2,0,0,2,0,0,0,0,1,0,},
			{0,2,1,2,2,2,0,2,0,2,1,0,0,2,0,2,},
			{2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,0,},
			{1,1,2,2,2,2,1,1,1,2,2,2,2,1,2,1,},
			{0,0,2,1,2,2,1,1,1,2,2,2,0,2,2,1,},
			{0,0,2,1,2,2,1,1,1,2,2,0,0,2,2,1,},
			{2,2,2,2,2,2,0,0,2,2,2,2,2,2,0,0,},
			{0,1,0,2,2,2,1,0,0,1,2,2,2,1,2,0,},
			{0,2,0,2,2,2,2,0,0,2,0,2,2,1,2,0,},
			{0,1,1,0,0,2,0,2,0,1,1,1,0,0,0,2,},
			{2,2,0,0,0,1,2,0,2,2,2,2,0,0,0,0,},
			{1,1,0,0,2,2,2,2,1,1,2,2,0,0,0,1,},
			{1,1,2,2,2,2,2,2,2,2,2,2,2,1,2,1,},
			{0,0,2,1,1,1,2,2,0,1,1,1,0,2,2,1,}};*/
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
		int boooomit(int y,int x,int power)//booooom！！
		{
			int score=0;
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
				if(mp[i][y]==2)score++;//打破箱子加分。
				if(mp[i][y]==0)mp[i][y]=198;
				else if(mp[i][y]==1)break;
				else if(mp[i][y]==2&&(rand()%3==1))mp[i][y]=202;//产生道具
				else if(mp[i][y]==2&&(rand()%6==2))mp[i][y]=203;//产生道具
				else if(mp[i][y]==2)mp[i][y]=198;
			}
			for(int i=x;i>=up;i--)
			{
				if(mp[i][y]==2)score++;
				if(mp[i][y]==0)mp[i][y]=198;
				else if(mp[i][y]==1)break;
				else if(mp[i][y]==2&&(rand()%3==1))mp[i][y]=202;
				else if(mp[i][y]==2&&(rand()%5==2))mp[i][y]=203;
				else if(mp[i][y]==2)mp[i][y]=198;
			}
			ffor(i,y,rt)
			{
				if(mp[x][i]==2)score++;
				if(mp[x][i]==0)mp[x][i]=198;
				else if(mp[x][i]==1)break;
				else if(mp[x][i]==2&&(rand()%3==1))mp[x][i]=202;
				else if(mp[x][i]==2&&(rand()%6==2))mp[x][i]=203;
				else if(mp[x][i]==2)mp[x][i]=198;
			}
			for(int i=y;i>=lf;i--)
			{
				if(mp[x][i]==2)score++;
				if(mp[x][i]==0)mp[x][i]=198;
				else if(mp[x][i]==1)break;
				else if(mp[x][i]==2&&(rand()%3==1))mp[x][i]=202;
				else if(mp[x][i]==2&&(rand()%5==2))mp[x][i]=203;
				else if(mp[x][i]==2)mp[x][i]=198;
			}
			return score;
		}
		int put_screen(int a,int b,int c,int d,int ba,int bb,int bc,int bd);
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
		bool danger(int x,int y)
		{
			if(mymap.mp[x][y]>5)return true;
			if(boomclock==0)return false;
			if(x==px){
				if(y>=py){if(power+py>=y)return true;}
				else if(y<py){if(py-power<=y)return true;}
			}else if(y==py){
				if(x>=px){if(power+px>=x)return true;}
				else if(x<px){if(px-power<=x)return true;}
			}return false;
		}
		int boomit()
		{
			if(boomclock>0&&boomclock<200-rand()%50)boomclock++;//炸弹倒计时,来点不确定性
			else if(boomclock>0){boomclock=0;return mymap.boooomit(px,py,power);}//返回爆炸所得的分数。
			return -1;
		}
}boom1,boom2,botboom1,botboom2;
class player
{
	public: 
		int px,py;
		int speed,moveturn;
		int type,lastype=0;
		int power;
		int score;
		void set_player(int x,int y,int z=15,int pw=1)
		{
			px=x;
			py=y;
			speed=z;
			power=pw;
			return;
		}
		void move(int x=0)//根据type值行动
		{
			if(moveturn<250/speed){moveturn++;return;}else moveturn=1;//设置移动间隔，控制速度。

				 if (type == 1&&mymap.move_able(px,py-1)){py--;type=0;if(lastype=1)lastype=11;else lastype=1;}
			else if (type == 2&&mymap.move_able(px+1,py)){px++;type=0;if(lastype=2)lastype=12;else lastype=2;}
			else if (type == 3&&mymap.move_able(px-1,py)){px--;type=0;if(lastype=3)lastype=13;else lastype=3;}
			else if (type == 4&&mymap.move_able(px,py+1)){py++;type=0;if(lastype=4)lastype=14;else lastype=4;}
			else if (type == 5&&mymap.move_able(px,py-1))py--;
			else if (type == 6&&mymap.move_able(px+1,py))px++;
			else if (type == 7&&mymap.move_able(px-1,py))px--;
			else if (type == 8&&mymap.move_able(px,py+1))py++;//连击击自动
			else return;
		}
		boom putboom()
		{
			boom newboom;
			newboom.set_boom(px,py,power);
			return newboom;
		}
}player1,player2;

class bot :public player
{
	public: 
		bool boomout=false;
		int boomputime;
		bool alive=true;
		int health=150;
		bool think()
		{
			int dis1=abs(px-player1.px)+abs(py-player1.py);
			int dis2=abs(px-player2.px)+abs(py-player2.py);
			//简单粗暴的算法，谁近就抓谁，同时攻击性十足。
			if(dis1<dis2)
			{
				if(px<player1.px)type=2;
				else if(px>player1.px)type=3;
				else if(py<player1.py)type=4;
				else type=1;
			}else{
				if(px<player2.px)type=2;
				else if(px>player2.px)type=3;
				else if(py<player2.py)type=4;
				else type=1;
			}
			//躲避炸弹.
			if(dis1>3&&dis2>3)
			ffor(i,1,5)
				{	
					 if (type == 1&&botboom1.danger(px,py-1)){type=2;}
					 if (type == 2&&botboom1.danger(px+1,py)){type=3;}
					 if (type == 3&&botboom1.danger(px-1,py)){type=4;}
					 if (type == 4&&botboom1.danger(px,py+1)){type=1;}
					 if (type == 1&&botboom2.danger(px,py-1)){type=2;}
					 if (type == 2&&botboom2.danger(px+1,py)){type=3;}
					 if (type == 3&&botboom2.danger(px-1,py)){type=4;}
					 if (type == 4&&botboom2.danger(px,py+1)){type=1;}
					 if (type == 1&&boom1.danger(px,py-1)){type=2;}
				 	 if (type == 2&&boom1.danger(px+1,py)){type=3;}
					 if (type == 3&&boom1.danger(px-1,py)){type=4;}
					 if (type == 4&&boom1.danger(px,py+1)){type=1;}
					 if (type == 1&&boom2.danger(px,py-1)){type=2;}
					 if (type == 2&&boom2.danger(px+1,py)){type=3;}
					 if (type == 3&&boom2.danger(px-1,py)){type=4;}
					 if (type == 4&&boom2.danger(px,py+1)){type=1;}
				}
				
			//防止卡墙不动。实际上，出乎意料的有用。
				 if (type == 1&&!mymap.move_able(px,py-1)){type=4;}
			else if (type == 2&&!mymap.move_able(px+1,py)){type=3;}
			else if (type == 3&&!mymap.move_able(px-1,py)){type=2;}
			else if (type == 4&&!mymap.move_able(px,py+1)){type=1;}
				 if (type == 1&&!mymap.move_able(px,py-1)){type=2;}
			else if (type == 2&&!mymap.move_able(px+1,py)){type=4;}
			else if (type == 3&&!mymap.move_able(px-1,py)){type=1;}
			else if (type == 4&&!mymap.move_able(px,py+1)){type=3;}
			if(dis1==0||dis2==0)type=0;

			if((dis1<3||dis2<3)&&!boomout){boomout=true;return true;}
			if(boomputime>300&&!boomout){boomout=true;boomputime=0;return true;}
			else boomputime++;
			return false;
		}
		void botdie()
		{
			health--;
			mymap.mp[px][py]=0;
			if(health<0)
			{
				alive=false;
				px=py=mymap.hl+2;
				type=0;
			}
		}
}bot1,bot2;

int boomap::put_screen(int a,int b,int c,int d,int ba,int bb,int bc,int bd)//关键步骤：打印屏幕
{
	ffor(i,1,hl)
	{
		ffor(j,1,hl)
		{
			if(a==j&&b==i)
			{
				if(mp[i][j]==0||mp[i][j]==3){putchar('P');putchar('1');}
			 	else if(mp[i][j]==4){player1.speed+=3;mp[i][j]=0;}//吃道具
			 	else if(mp[i][j]==5){player1.power++;mp[i][j]=0;}
			 	else return 1;//走入爆炸，死亡
			}
		else if(c==j&&d==i)
			{
				if(mp[i][j]==0||mp[i][j]==3){putchar('P');putchar('2');}
			 	else if(mp[i][j]==4){player2.speed+=3;mp[i][j]=0;}
			 	else if(mp[i][j]==5){player2.power++;mp[i][j]=0;}
			 	else return 2;
			}
		else if(ba==j&&bb==i)
			{
				if(mp[i][j]==0||mp[i][j]==3){putchar('B');putchar('1');}
			 	else if(mp[i][j]==4){bot1.speed+=2;mp[i][j]=0;}
			 	else if(mp[i][j]==5){bot1.power++;mp[i][j]=0;}
				else bot1.botdie();
			}
		else if(bc==j&&bd==i)
			{
				if(mp[i][j]==0||mp[i][j]==3){putchar('B');putchar('2');}
			 	else if(mp[i][j]==4){bot2.speed+=2;mp[i][j]=0;}
			 	else if(mp[i][j]==5){bot2.power++;mp[i][j]=0;}
				else bot2.botdie();
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
	ffor(i,1,hl-10){putchar(' ');}printf("player1 : %d         \n",player1.score);
	ffor(i,1,hl-10){putchar(' ');}printf("player2 : %d         \n",player2.score);
	if(bot1.alive)ffor(i,1,hl-8){putchar(' ');}printf("bot1 : %d         \n",bot1.score);
	if(bot2.alive)ffor(i,1,hl-8){putchar(' ');}printf("bot2 : %d         \n",bot2.score);
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	return 0;
}
void deal_with_input()
{
	if(_kbhit())
	{
			char ch = _getch();
			//玩家1键入
			//lastype的设计使得游戏支持连击自动行驶
			 if (ch == 'w'){if(player1.lastype==11)player1.type=5;else player1.type=1;}
		else if (ch == 'd'){if(player1.lastype==12)player1.type=6;else player1.type=2;}
		else if (ch == 'a'){if(player1.lastype==13)player1.type=7;else player1.type=3;}
		else if (ch == 's'){if(player1.lastype==14)player1.type=8;else player1.type=4;}
		else if (ch == 'q')player1.type=0;
		else if (ch == 'c')player1.px=3,player1.py=3;//一个小小的后门
		else if(int(ch)==32&&boom1.boomclock==0)boom1=player1.putboom();
			//玩家2键入
			 if (ch == 'i'){if(player2.lastype==11)player2.type=5;else player2.type=1;}
		else if (ch == 'l'){if(player2.lastype==12)player2.type=6;else player2.type=2;}
		else if (ch == 'j'){if(player2.lastype==13)player2.type=7;else player2.type=3;}
		else if (ch == 'k'){if(player2.lastype==14)player2.type=8;else player2.type=4;}
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
	mymap.set_boomap(24);
	int hl=mymap.hl;
	mymap.mp[hl-3][3]=mymap.mp[3][hl-3]=mymap.mp[hl-3][hl-3]=0;
	player1.set_player(3,3);
	player2.set_player(hl-3,hl-3);
	bot1.set_player(3,hl-3,10,2);
	bot2.set_player(hl-3,3,10,2);
}
void end_game(int x)//游戏结束
{
	system("color 90");
	Sleep(2000);
	system("color 0B");
	int hl=mymap.hl;
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 清屏
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	ffor(i,1,hl-8){putchar(' ');}printf("player %d is dead!",x);ffor(i,1,hl){putchar(' ');}putchar('\n');
	if(x==1)x=2;else x=1;
	ffor(i,1,hl-8){putchar(' ');}printf("player %d wins!",x);ffor(i,1,hl){putchar(' ');}putchar('\n');
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	ffor(i,1,hl-5)
	{ffor(j,1,hl){putchar(' ');putchar(' ');}
	putchar('\n');}
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	ffor(i,1,hl-10){putchar(' ');}printf("player1 : %d       ",player1.score);ffor(i,1,hl){putchar(' ');}putchar('\n');
	ffor(i,1,hl-10){putchar(' ');}printf("player2 : %d       ",player2.score);ffor(i,1,hl){putchar(' ');}putchar('\n');
	ffor(i,1,hl-8){putchar(' ');}printf("bot1 : %d         \n",bot1.score);
	ffor(i,1,hl-8){putchar(' ');}printf("bot2 : %d         \n",bot2.score);
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	return;
}
bool play()
{
	if(putmouse>10){HideCursor();putmouse=0;}else putmouse++;//清除光标，但是节省时间不用一直开启
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 相当于函数gotoxy (0,0);

	player1.move();
	player2.move();
	int score=boom1.boomit();
	if(score>0)player1.score+=score;
	score=boom2.boomit();
	if(score>0)player2.score+=score;
	score=botboom1.boomit();
	if(score>=0){bot1.boomout=false;bot1.score+=score;}
	score=botboom2.boomit();
	if(score>=0){bot2.boomout=false;bot2.score+=score;}
	if(bot1.alive)
	{
		if(bot1.think())botboom1=bot1.putboom();
		bot1.move();
	}
	if(bot2.alive)
	{
		if(bot2.think())botboom2=bot2.putboom();
		bot2.move();
	}
	int death=mymap.put_screen(player1.px,player1.py,player2.px,player2.py,bot1.px,bot1.py,bot2.px,bot2.py);
	if(death>0){end_game(death);return false;}//返回false则游戏关闭。
	return true;
}
void introduction()
{
	cout<<" boomit 游戏介绍 "<<endl;
	cout<<" 玩家P1 使用wasd移动,q键站立不动。 "<<endl;
	cout<<" 玩家P2 使用ijkl移动,o键站立不动。 "<<endl;
	cout<<" 玩家 双击方向键自动行驶 "<<endl;
	cout<<" 打破箱子加分并且概率掉落道具：\n 加速(GD)，或者炸弹升级(BM) "<<endl;
	cout<<" 场景中有2个机器人,\n 他们有大量的生命值且具有攻击性 "<<endl;
	putchar(' ');
	system("pause");
	
	ffor(i,1,100){
	ffor(j,1,100)putchar(' ');putchar('\n');}
}
int main() {
	introduction();
	init();
	do deal_with_input();
	while(play());
	system("pause");
	return 0;
}