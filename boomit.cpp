#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#define ffor(i, a, n) for (long long i = a; i <= n; i++)
using namespace std;
int cnt,putmouse;//ʱ�������������ȫ�ֶ���
int boomid;//ʵʱ��ը��ը��id
class boomap
{
	public:
		int mp[500][500]=
			{//��ʼ��һ�������ĵ�ͼ
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
		int hl;//�����α߳�
		void set_boomap(int x)//��ʼ����ͼ
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
		int boooomit(int y,int x,int power)//booooom����
		{
			int score=0;
			mp[x][y]=0;
			//ȷ����ը��Χ
			int up=x-power;
			int down=x+power;
			int lf=y-power;
			int rt=y+power;
			if(up<=1)up=2;
			if(down>=hl)down=hl-1;
			if(lf<=1)lf=2;
			if(rt>=hl)rt=hl-1;

			ffor(i,x,down)//�ֿ����˹�����ʹ����Ӳǽ�Ͽ�
			{
				if(mp[i][y]==2)score++;//�������Ӽӷ֡�
				if(mp[i][y]==0)mp[i][y]=198;
				else if(mp[i][y]==1)break;
				else if(mp[i][y]==2&&(rand()%4==1))mp[i][y]=202;//��������
				else if(mp[i][y]==2&&(rand()%9==1))mp[i][y]=203;//��������
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
		void set_boom(int a,int b,int c,int d=1)//����ը��
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
			if(boomclock>0&&boomclock<100-rand()%70)boomclock++;//ը������ʱ,���㲻ȷ����
			else if(boomclock>0){boomclock=0;int x=px,y=py;px=mymap.hl+1;py=mymap.hl+1;return mymap.boooomit(x,y,power);}//���ر�ը���õķ�����
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
		void move(int x=0)//����typeֵ�ж�
		{
			if(moveturn<300/speed-5){moveturn++;return;}else moveturn=1;//�����ƶ�����������ٶȡ�

				 if (type == 1&&mymap.move_able(px,py-1)){py--;type=0;if(lastype=1)lastype=11;else lastype=1;}
			else if (type == 2&&mymap.move_able(px+1,py)){px++;type=0;if(lastype=2)lastype=12;else lastype=2;}
			else if (type == 3&&mymap.move_able(px-1,py)){px--;type=0;if(lastype=3)lastype=13;else lastype=3;}
			else if (type == 4&&mymap.move_able(px,py+1)){py++;type=0;if(lastype=4)lastype=14;else lastype=4;}
			else if (type == 5&&mymap.move_able(px,py-1))py--;
			else if (type == 6&&mymap.move_able(px+1,py))px++;
			else if (type == 7&&mymap.move_able(px-1,py))px--;
			else if (type == 8&&mymap.move_able(px,py+1))py++;//�����Զ�
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
			//�򵥴ֱ����㷨��˭����ץ˭��ͬʱ������ʮ�㡣
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
			//���ը����
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
	if(x==1)printf("��");
	else if(x==2) printf("��");
	else if(x==3) printf("��");
	else printf("��");
	SetConsoleTextAttribute(handle, colorOld);
}
int boomap::put_screen(int a,int b,int c,int d,int ba,int bb,int bc,int bd)
//�ؼ����裺��ӡ��Ļ
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
			 	else if(mp[i][j]==4){cputchar('P',110);cputchar('1',110);player1.speed+=3;mp[i][j]=0;}//�Ե���
			 	else if(mp[i][j]==5){cputchar('P',120);cputchar('1',120);player1.power++;mp[i][j]=0;}
			 	else {cputchar('P',91);cputchar('1',91);return 1;}//���뱬ը������
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
		//������Ч�Ĺ�����
		//mpֵÿ��-6��ͨ�����ñ�ը�����Ĳ�ͬ��6������ȷ�����µ����塣
		}putchar('\n');
	}
	putchar('\n');
	//�Ʒְ�
		
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
			//���1����
			//lastype�����ʹ����Ϸ֧�������Զ���ʻ
			 if (ch == 'w'){if(player1.lastype==11)player1.type=5;else player1.type=1;}
		else if (ch == 'd'){if(player1.lastype==12)player1.type=6;else player1.type=2;}
		else if (ch == 'a'){if(player1.lastype==13)player1.type=7;else player1.type=3;}
		else if (ch == 's'){if(player1.lastype==14)player1.type=8;else player1.type=4;}
		else if (ch == 'e'){if(boom1.boomclock>0)boom1.boomclock+=150;}
		else if (ch == 'q')player1.type=0;
		else if (ch == 'c')player1.px=3,player1.py=3;//һ��СС�ĺ���
		else if(int(ch)==32&&boom1.boomclock==0)boom1=player1.putboom();
			//���2����
			 if (ch == 'i'){if(player2.lastype==11)player2.type=5;else player2.type=1;}
		else if (ch == 'l'){if(player2.lastype==12)player2.type=6;else player2.type=2;}
		else if (ch == 'j'){if(player2.lastype==13)player2.type=7;else player2.type=3;}
		else if (ch == 'k'){if(player2.lastype==14)player2.type=8;else player2.type=4;}
		else if (ch == 'u'){if(boom2.boomclock>0)boom2.boomclock+=150;}
		else if (ch == 'o')player2.type=0;
		else if (ch == 'p')player2.px=mymap.hl-3,player2.py=mymap.hl-3;//һ��СС�ĺ���
		else if(int(ch)==13&&boom2.boomclock==0)boom2=player2.putboom();
	}
}
void HideCursor()
{//������
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = 1;    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}
void init()
{
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */
    LONG l_WinStyle = GetWindowLong(hwnd,GWL_STYLE);   /* ��ȡ������Ϣ */
    /* ���ô�����Ϣ ��� ȡ�����������߿� */
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
void end_game(int x)//��Ϸ����
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
	SetConsoleCursorPosition(hOut, pos);// ����
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
	SetConsoleCursorPosition(hOut, pos);// �൱�ں���gotoxy (0,0);

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
	if(death>0){end_game(death);return false;}//����false����Ϸ�رա�
	return true;
}
void introduction()
{
	putchar('\n');
	putchar('\n');
	putchar('\n');
	printf("                         ");cout<<" boomit ��Ϸ���� "<<endl;
	printf("                         ");cout<<" ���P1 ʹ��wasd�ƶ�,q��վ��������\n";
	printf("                         ");cout<<" �ո�ը���� "<<endl;
	printf("                         ");cout<<" ���P2 ʹ��ijkl�ƶ�,o��վ��������\n";
	printf("                         ");cout<<" �س�ը���� "<<endl;
	printf("                         ");cout<<" ��ը���ƻ�[]����,��üӷ֣�"<<endl;
	printf("                         ");cout<<" ��ը�ᱻӲǽ##��ס"<<endl;
	printf("                         ");cout<<" ��ҿ�˫��������Զ���ʻ "<<endl;
	printf("                         ");cout<<" �������Ӽӷֲ��Ҹ��ʵ�����ߣ�\n";
	printf("                         ");cout<<" ����(S+)������ը������(P+) "<<endl;
	printf("                         ");cout<<" ��������2��������B1B2,������5�����Ҿ��й�����:\n";
	printf("                         ");cout<<" ը�����ǻ�þ޶������"<<endl;
	printf("                         ");cout<<" ���ȵ���300�ֻ�ʤ��\n";
	printf("                         ");cout<<" 300s����Ϸ����,�ָ���ʤ��"<<endl;
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