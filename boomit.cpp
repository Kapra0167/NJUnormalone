#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt,putmouse;//时间相关量，必须全局定义
int boomid;//实时爆炸的炸弹id
class boomap
{
	public:
		int mp[500][500]=
			{//初始化一个精美的地图
			{1,2,2,2,2,2,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,2,1,2,},
			{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
			{1,0,2,0,2,1,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,1,2,},
			{1,0,0,0,2,1,2,1,2,2,1,2,2,2,2,2,2,2,2,0,0,0,1,2,},
			{1,0,0,0,0,2,2,2,2,2,2,2,1,2,2,2,2,2,2,0,0,2,1,2,},
			{1,2,0,2,0,2,1,2,1,1,1,2,2,2,1,2,1,2,2,2,2,2,2,2,},
			{1,2,0,2,2,2,2,2,2,2,1,2,1,2,2,2,2,2,0,2,0,2,2,2,},
			{1,2,2,2,1,2,1,1,1,0,0,2,2,0,2,1,1,2,1,0,2,2,2,2,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,2,2,2,2,2,2,2,2,1,1,2,1,1,2,2,2,2,1,1,2,2,2,1,},
			{1,2,2,1,2,2,1,2,1,1,4,2,5,5,1,2,2,2,2,2,2,2,2,2,},
			{1,2,2,2,2,1,1,2,1,5,5,2,4,1,1,2,2,2,2,2,2,1,2,2,},
			{1,2,2,2,2,2,2,2,2,1,1,2,1,1,2,2,2,2,2,2,2,2,2,2,2,},
			{1,2,2,0,2,2,2,2,2,0,2,2,2,0,2,2,2,1,1,2,2,2,1,2,},
			{1,0,0,1,2,1,2,1,2,2,1,2,1,2,2,2,2,2,2,1,2,2,2,2,},
			{1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,1,},
			{1,2,2,0,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,1,},
			{1,2,2,0,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
			{1,2,2,0,2,2,2,2,2,2,1,2,2,2,2,2,2,2,0,2,2,2,1,2,},
			{1,2,0,0,2,2,2,1,2,2,2,2,1,2,1,1,1,1,2,0,0,2,2,2,},
			{1,2,2,0,2,2,2,2,2,2,1,2,2,2,2,2,2,2,0,2,0,2,1,1,},
			{1,2,2,2,2,2,2,2,2,2,1,2,1,1,2,2,2,2,2,0,0,2,1,2,},
			{1,2,2,1,2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,2,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,2,},
			{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,},};
			/*{{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,2,2,2,2,2,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,2,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,2,2,2,2,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,2,2,2,2,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},
			{1,0,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,0,2,0,2,0,0,0,},};*/
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
		bool move_able(int x,int y,int type=0)
		{
			if(type==0)return mp[y][x]!=1&&mp[y][x]!=2;
			else if (type == 1)y--;
			else if (type == 2)x++;
			else if (type == 3)x--;
			else if (type == 4)y++;
			return mp[y][x]!=1&&mp[y][x]!=2;
		}
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
				else if(mp[i][y]==2&&(rand()%4==1))mp[i][y]=202;//产生道具
				else if(mp[i][y]==2&&(rand()%9==1))mp[i][y]=203;//产生道具
				else if(mp[i][y]==2)mp[i][y]=198;
			}
			for(int i=x;i>=up;i--)
			{
				if(mp[i][y]==2)score++;
				if(mp[i][y]==0)mp[i][y]=198;
				else if(mp[i][y]==1)break;
				else if(mp[i][y]==2&&(rand()%4==2))mp[i][y]=202;
				else if(mp[i][y]==2&&(rand()%9==2))mp[i][y]=203;
				else if(mp[i][y]==2)mp[i][y]=198;
			}
			ffor(i,y,rt)
			{
				if(mp[x][i]==2)score++;
				if(mp[x][i]==0)mp[x][i]=198;
				else if(mp[x][i]==1)break;
				else if(mp[x][i]==2&&(rand()%4==3))mp[x][i]=202;
				else if(mp[x][i]==2&&(rand()%9==3))mp[x][i]=203;
				else if(mp[x][i]==2)mp[x][i]=198;
			}
			for(int i=y;i>=lf;i--)
			{
				if(mp[x][i]==2)score++;
				if(mp[x][i]==0)mp[x][i]=198;
				else if(mp[x][i]==1)break;
				else if(mp[x][i]==2&&(rand()%4==0))mp[x][i]=202;
				else if(mp[x][i]==2&&(rand()%9==4))mp[x][i]=203;
				else if(mp[x][i]==2)mp[x][i]=198;
			}
			return 2*score;
		}
		int put_screen(int a,int b,int c,int d,int ba,int bb,int bc,int bd);
}mymap;
int breath(int x,int y)
{
	int ans=0;
	if(mymap.mp[y+1][x]==0||mymap.mp[y+1][x]>3)ans++;
	if(mymap.mp[y-1][x]==0||mymap.mp[y-1][x]>3)ans++;
	if(mymap.mp[y][x+1]==0||mymap.mp[y][x+1]>3)ans++;
	if(mymap.mp[y][x-1]==0||mymap.mp[y][x-1]>3)ans++;
	return ans;
}
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
		int safeway_judge(int tx,int ty,int type)
		{
				int x=tx,y=ty;
			 	 if (type == 1)y--;
			else if (type == 2)x++;
			else if (type == 3)x--;
			else if (type == 4)y++;
			
			if(mymap.mp[y][x]==1||mymap.mp[y][x]==2){x=tx;y=ty;}
			if(mymap.mp[y][x]>5)return -100;
			int disx=px-x,disy=py-y;
			if(disx<0)disx=-disx;
			if(disy<0)disy=-disy;
			if(disy==0&&power>=disx)return 10*disx+breath(x,y);
			if(disx==0&&power>=disy)return 10*disy+breath(x,y);
			return 100;
		}
		int boomit()
		{
			if(boomclock>0&&boomclock<100-rand()%70)boomclock++;//炸弹倒计时,来点不确定性
			else if(boomclock>0){boomclock=0;int x=px,y=py;px=mymap.hl+1;py=mymap.hl+1;return mymap.boooomit(x,y,power);}//返回爆炸所得的分数。
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
		void set_player(int x,int y,int z=20,int pw=1)
		{
			px=x;
			py=y;
			speed=z;
			power=pw;
			return;
		}
		void move(int x=0)//根据type值行动
		{
			if(moveturn<300/speed-5){moveturn++;return;}else moveturn=1;//设置移动间隔，控制速度。

				 if (type == 1&&mymap.move_able(px,py-1)){py--;type=0;if(lastype=1)lastype=11;else lastype=1;}
			else if (type == 2&&mymap.move_able(px+1,py)){px++;type=0;if(lastype=2)lastype=12;else lastype=2;}
			else if (type == 3&&mymap.move_able(px-1,py)){px--;type=0;if(lastype=3)lastype=13;else lastype=3;}
			else if (type == 4&&mymap.move_able(px,py+1)){py++;type=0;if(lastype=4)lastype=14;else lastype=4;}
			else if (type == 5&&mymap.move_able(px,py-1))py--;
			else if (type == 6&&mymap.move_able(px+1,py))px++;
			else if (type == 7&&mymap.move_able(px-1,py))px--;
			else if (type == 8&&mymap.move_able(px,py+1))py++;//连击自动
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
		int health=3;
		bool think()
		{
			int try1,try2;
			int dis1=abs(px-player1.px)+abs(py-player1.py);
			int dis2=abs(px-player2.px)+abs(py-player2.py);
			//简单粗暴的算法，谁近就抓谁，同时攻击性十足。
			if(dis1<=dis2)
			{
				if(px<player1.px)try1=2;
				else if(px>player1.px)try1=3;
				else try1=rand()%2+2;
				if(py<player1.py)try2=4;
				else if(py>player1.px)try2=1;
				else try2=4;
			}else{
				if(px<player2.px)try1=2;
				else if(px>player2.px)try1=3;
				else try1=rand()%2+2;
				if(py<player2.py)try2=4;
				else if(py>player2.px)try2=1;
				else try2=1;
			}
			if(dis1>3&&dis2>3)
			{if(!mymap.move_able(px,py,try1))
				if(!mymap.move_able(px,py,try2))
					if(!mymap.move_able(px,py,5-try1))
						if(!mymap.move_able(px,py,5-try2))type=0;
						else type=5-try2;
					else type=5-try1;
				else type=try2;
			else type=try1;
			//躲避炸弹！
			int mmax=botboom1.safeway_judge(px,py,type);
			if(mmax<100)
			ffor(i,0,4)
			if(botboom1.safeway_judge(px,py,i)>mmax)
			{
				type=i;mmax=botboom1.safeway_judge(px,py,i);
			}
			mmax=botboom2.safeway_judge(px,py,type);
			if(mmax<100)
			ffor(i,0,4)
			if(botboom2.safeway_judge(px,py,i)>mmax)
			{
				type=i;mmax=botboom2.safeway_judge(px,py,i);
			}
			mmax=boom1.safeway_judge(px,py,type);
			if(mmax<100)
			ffor(i,0,4)
			if(boom1.safeway_judge(px,py,i)>mmax)
			{
				type=i;mmax=boom1.safeway_judge(px,py,i);
			}
			mmax=boom2.safeway_judge(px,py,type);
			if(mmax<100)
			ffor(i,0,4)
			if(boom2.safeway_judge(px,py,i)>mmax)
			{
				type=i;mmax=boom2.safeway_judge(px,py,i);
			}
			if(breath(px,py)==0)ffor(i,1,4)if(mymap.move_able(px,py,i))type=i;}
			if(dis1*dis2==0)type=0;
			if((dis1<3||dis2<3)&&!boomout){boomout=true;return true;}
			if(boomputime>70&&!boomout&&(mymap.mp[px+1][py]==2||mymap.mp[px-1][py]==2||mymap.mp[px][py+1]==2||mymap.mp[px][py-1]==2||boomputime>220))
			{boomout=true;boomputime=0;return true;}
			else boomputime++;
			return false;
		}
		void botdie()
		{
			health--;
			if(boomid==1)player1.score+=80;
			else if(boomid==2)player2.score+=80;
			mymap.mp[px][py]=0;
			if(health<0)
			{
				alive=false;
				px=py=mymap.hl+2;
				type=0;
			}
		}
}bot1,bot2;
void cputchar(char str, WORD color) {//colors!!!!!!!!
	WORD colorOld;
	HANDLE handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	colorOld = csbi.wAttributes;
	SetConsoleTextAttribute(handle, color);
	putchar(str);
	SetConsoleTextAttribute(handle, colorOld);
}
void cputhings(int x,WORD color) {//colors!!!!!!!!
	WORD colorOld;
	HANDLE handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	colorOld = csbi.wAttributes;
	SetConsoleTextAttribute(handle, color);
	if(x==1)printf("龘");
	else if(x==2) printf("〇");
	else if(x==3) printf("黑");
	else printf("白");
	SetConsoleTextAttribute(handle, colorOld);
}
int boomap::put_screen(int a,int b,int c,int d,int ba,int bb,int bc,int bd)
//关键步骤：打印屏幕
{
	putchar('\n');putchar('\n');putchar('\n');
	ffor(i,1,hl)
	{
		printf("                         ");
		ffor(j,1,hl)
		{
			if(a==j&&b==i)
			{
				if(mp[i][j]==0)cputhings(3,15);
				else if(mp[i][j]==3){cputchar('!',64);cputchar('!',64);}
			 	else if(mp[i][j]==4){cputchar('P',110);cputchar('1',110);player1.speed+=3;mp[i][j]=0;}//吃道具
			 	else if(mp[i][j]==5){cputchar('P',120);cputchar('1',120);player1.power++;mp[i][j]=0;}
			 	else {cputchar('P',91);cputchar('1',91);return 1;}//走入爆炸，死亡
			}
		else if(c==j&&d==i)
			{
				if(mp[i][j]==0)cputhings(4,112);
				else if(mp[i][j]==3){cputchar('!',64);cputchar('!',64);}
			 	else if(mp[i][j]==4){cputchar('P',110);cputchar('2',110);player2.speed+=3;mp[i][j]=0;}
			 	else if(mp[i][j]==5){cputchar('P',120);cputchar('2',120);player2.power++;mp[i][j]=0;}
			 	else {cputchar('P',128);cputchar('2',128);return 2;}
			}
		else if(ba==j&&bb==i)
			{
				if(mp[i][j]==0){cputchar(' ',160);cputchar(' ',160);}
				else if(mp[i][j]==3){cputchar('!',64);cputchar('!',64);}
			 	else if(mp[i][j]==4){cputchar('B',110);cputchar('1',110);bot1.speed+=2;mp[i][j]=0;}
			 	else if(mp[i][j]==5){cputchar('B',120);cputchar('1',120);bot1.power++;mp[i][j]=0;}
				else {mp[i][j]=0;cputchar('B',64);cputchar('1',64);bot1.botdie();}
			}
		else if(bc==j&&bd==i)
			{
				if(mp[i][j]==0){cputchar(' ',219);cputchar(' ',219);}
				else if(mp[i][j]==3){cputchar('!',64);cputchar('!',64);}
			 	else if(mp[i][j]==4){cputchar('B',110);cputchar('2',110);bot2.speed+=2;mp[i][j]=0;}
			 	else if(mp[i][j]==5){cputchar('B',120);cputchar('2',120);bot2.power++;mp[i][j]=0;}
				else {mp[i][j]=0;cputchar('B',64);cputchar('2',64);bot2.botdie();}
			}
		else if(mp[i][j]==0){cputchar(' ',255);cputchar(' ',255);}
		else if(mp[i][j]==1)cputhings(1,128);
		else if(mp[i][j]==2)cputhings(2,248);
		else if(mp[i][j]==3){cputchar('!',79);cputchar('!',79);}
		else if(mp[i][j]==4){cputchar('S',63);cputchar('+',63);}
		else if(mp[i][j]==5){cputchar('P',199);cputchar('+',199);}
		else {cputchar(char(rand()%80+35),rand()%350);cputchar(char(rand()%80+35),rand()%350);mp[i][j]-=6;}
		//乱码特效的光束！
		//mp值每次-6，通过设置爆炸光束的不同对6余数，确定留下的物体。
		}putchar('\n');
	}
	putchar('\n');
	//计分板
		
	printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	printf("                         ");ffor(i,1,hl-10){putchar(' ');}printf("player1 : %d         \n",player1.score);
	printf("                         ");ffor(i,1,hl-10){putchar(' ');}printf("player2 : %d         \n",player2.score);
	printf("                         ");ffor(i,1,hl-10){putchar(' ');}printf("  time :%d         \n",(3010-cnt)/10);
	printf("                         ");ffor(i,1,hl-8){putchar(' ');}if(bot1.alive)printf("bot1 : %d         \n",bot1.score);else printf("bot1 : dead!               \n");
	printf("                         ");ffor(i,1,hl-8){putchar(' ');}if(bot2.alive)printf("bot2 : %d         \n",bot2.score);else printf("bot2 : dead!               \n");
	printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
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
		else if (ch == 'e'){if(boom1.boomclock>0)boom1.boomclock+=150;}
		else if (ch == 'q')player1.type=0;
		else if (ch == 'c')player1.px=3,player1.py=3;//一个小小的后门
		else if(int(ch)==32&&boom1.boomclock==0)boom1=player1.putboom();
			//玩家2键入
			 if (ch == 'i'){if(player2.lastype==11)player2.type=5;else player2.type=1;}
		else if (ch == 'l'){if(player2.lastype==12)player2.type=6;else player2.type=2;}
		else if (ch == 'j'){if(player2.lastype==13)player2.type=7;else player2.type=3;}
		else if (ch == 'k'){if(player2.lastype==14)player2.type=8;else player2.type=4;}
		else if (ch == 'u'){if(boom2.boomclock>0)boom2.boomclock+=150;}
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
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */
    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* 获取窗口信息 */
    /* 设置窗口信息 最大化 取消标题栏及边框 */
    SetWindowLong(hwnd,GWL_STYLE,(l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
	system("color 0B");
	mymap.set_boomap(24);
	int hl=mymap.hl;
	mymap.mp[hl-3][3]=mymap.mp[3][hl-3]=mymap.mp[hl-3][hl-3]=0;
	player1.set_player(3,3);
	player2.set_player(hl-3,hl-3);
	bot1.set_player(3,hl-3,18,2);
	bot2.set_player(hl-3,3,18,2);
}
void end_game(int x)//游戏结束
{
	system("color 02");
	Sleep(200);
	system("color 04");
	Sleep(200);
	system("color 03");
	Sleep(200);
	system("color 04");
	Sleep(200);
	system("color 02");
	Sleep(200);
	system("color 04");
	Sleep(200);
	system("color 03");
	Sleep(200);
	system("color 04");
	Sleep(500);
	system("color 0B");
	int hl=mymap.hl;
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 清屏
	printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	if(x>0)
	{printf("                         ");ffor(i,1,hl-8){putchar(' ');}printf("player %d is dead!",x);ffor(i,1,hl){putchar(' ');}putchar('\n');
	if(x==1)x=2;else x=1;
	printf("                         ");ffor(i,1,hl-8){putchar(' ');}printf("player %d wins!",x);ffor(i,1,hl){putchar(' ');}putchar('\n');
	printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');}
	else {
		x=2;
		if(player1.score>player2.score)x=1;
		printf("                         ");ffor(i,1,hl-8){putchar(' ');}printf("player %d wins!",x);ffor(i,1,hl){putchar(' ');}putchar('\n');
		printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
		printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	}
	ffor(i,1,hl)
	{printf("                         ");ffor(j,1,hl){putchar(' ');putchar(' ');}
	putchar('\n');}
	printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	printf("                         ");ffor(i,1,hl-10){putchar(' ');}printf("player1 : %d       ",player1.score);ffor(i,1,hl){putchar(' ');}putchar('\n');
	printf("                         ");ffor(i,1,hl-10){putchar(' ');}printf("player2 : %d       ",player2.score);ffor(i,1,hl){putchar(' ');}putchar('\n');
	printf("                         ");ffor(i,1,hl-8){putchar(' ');}printf("bot1 : %d                               \n",bot1.score);
	printf("                         ");ffor(i,1,hl-8){putchar(' ');}printf("bot2 : %d                               \n",bot2.score);
	printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	printf("                         ");ffor(i,1,hl){putchar('=');putchar('=');}putchar('\n');
	printf("                         ");
	return;
}
bool play()
{
	if(cnt%20==1)HideCursor();
	COORD pos = {0, 0};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);// 相当于函数gotoxy (0,0);

	if(cnt++>3010||player1.score>300||player1.score>300)end_game(0);
	player1.move();
	player2.move();
	int score=boom1.boomit();
	if(score>0){player1.score+=score;boomid=1;}
	score=boom2.boomit();
	if(score>0){player2.score+=score;boomid=2;}
	score=botboom1.boomit();
	if(score>=0){bot1.boomout=false;bot1.score+=score;boomid=0;}
	score=botboom2.boomit();
	if(score>=0){bot2.boomout=false;bot2.score+=score;boomid=0;}
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
	putchar('\n');
	putchar('\n');
	putchar('\n');
	printf("                         ");cout<<" boomit 游戏介绍 "<<endl;
	printf("                         ");cout<<" 玩家P1 使用wasd移动,q键站立不动。\n";
	printf("                         ");cout<<" 空格炸弹！ "<<endl;
	printf("                         ");cout<<" 玩家P2 使用ijkl移动,o键站立不动。\n";
	printf("                         ");cout<<" 回车炸弹！ "<<endl;
	printf("                         ");cout<<" 爆炸会破坏[]箱子,获得加分！"<<endl;
	printf("                         ");cout<<" 爆炸会被硬墙##挡住"<<endl;
	printf("                         ");cout<<" 玩家可双击方向键自动行驶 "<<endl;
	printf("                         ");cout<<" 打破箱子加分并且概率掉落道具：\n";
	printf("                         ");cout<<" 加速(S+)，或者炸弹升级(P+) "<<endl;
	printf("                         ");cout<<" 场景中有2个机器人B1B2,他们有5条命且具有攻击性:\n";
	printf("                         ");cout<<" 炸到他们获得巨额分数！"<<endl;
	printf("                         ");cout<<" 率先到达300分获胜！\n";
	printf("                         ");cout<<" 300s后游戏结束,分高者胜！"<<endl;
	ffor(j,1,26)putchar(' ');system("pause");
}
int main() {
	introduction();
	init();

	do deal_with_input();
	while(play());
	
	system("pause");
	return 0;
}