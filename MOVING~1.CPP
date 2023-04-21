#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#define SOUND 3500
/* 3d Ball */
char ball[20][20]=
{
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,12,12,12,12,12,12,12,12,0,0,0,0,0,0},
{0,0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0,0},
{0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0},
{0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0},
{0,0,12,12,12,12,12,15,15,12,12,12,12,12,12,12,12,12,0,0},
{0,12,12,12,12,12,15,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,15,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,15,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0},
{0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0},
{0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0},
{0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0},
{0,0,0,0,12,12,12,12,12,12,12,12,12,12,12,12,0,0,0,0},
{0,0,0,0,0,0,12,12,12,12,12,12,12,12,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
void *ptr1[4],*ptr2[4];
/* Condition to check out of range */
int COND(int x,int y)
{
	if (x>10 && x<getmaxx()-10 && y>10 && y<getmaxy()-10)
		return 1;  //unsucessfull
	else
		return 0;  //sucessfull
}
/* This sub-routine will check which path to follow on stiking the wall
of
the container */
void state(int x,int y,int mode)
{
	while(COND(x,y)&&!kbhit())
	{
		//lefttop
		putimage(x+50,y+30,ptr1[4],COPY_PUT);
		putimage(x+70,y+50,ptr1[4],COPY_PUT);
		putimage(x+180,y+20,ptr1[4],COPY_PUT);
		putimage(x+200,y+170,ptr1[4],COPY_PUT);
		putimage(x+130,y+200,ptr1[4],COPY_PUT);
		//leftbottom
		putimage(x,getmaxy()-y,ptr1[4],COPY_PUT);
		putimage(x,getmaxy()-y-250,ptr1[4],COPY_PUT);
		putimage(x+130,getmaxy()-y,ptr1[4],COPY_PUT);
		putimage(x+180,getmaxy()-y-170,ptr1[4],COPY_PUT) ;
		putimage(x+180,getmaxy()-y-140,ptr1[4],COPY_PUT);
		//righttop
		putimage(getmaxx()-x,y+20,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x,y+250,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x-250,y+250,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x-250,y+200,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x-100,y+40,ptr1[4],COPY_PUT);
		//rightbottom
		putimage(getmaxx()-x,getmaxy()-y,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x-100,getmaxy()-y-230,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x-200,getmaxy()-y-170,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x-250,getmaxy()-y,ptr1[4],COPY_PUT);
		putimage(getmaxx()-x-150,getmaxy()-y-20,ptr1[4],COPY_PUT);
		//extra
		putimage(x,y,ptr1[4],COPY_PUT);
		putimage(x,getmaxy(),ptr1[4],COPY_PUT);
		putimage(getmaxx(),y,ptr1[4],COPY_PUT);
		putimage(getmaxx(),getmaxy(),ptr1[4],COPY_PUT);
		switch(mode)
		{
			case 0:
				x++;
				y++;
				break;
			case 1:
				x++;
				y--;
				break;
			case 2:
				x--;
				y++;
				break;
			case 3:
				x--;
				y--;
				break;
		}
		nosound();
	}
	cleardevice();
	if(x>=(getmaxx()-10)||x<=10)
	{
		sound(SOUND);
		switch(mode)
		{
			case 0:
				state(--x,--y,2);
				break;
			case 1:
				state(--x,++y,3);
				break;
			case 2:
				state(++x,--y,0);
				break;
			case 3:
				state(++x,++y,1);
				break;
		}
	}
	else
	if(y>=getmaxy()-10||y<=10)
	{
		sound(SOUND);
		switch(mode)
		{
			case 0:
				state(--x,--y,1);
				break;
			case 1:
				state(--x,++y,0);
				break;
			case 2:
				state(++x,--y,3);
				break;
			case 3:
				state(++x,++y,2);
				break;
		}
	}
	else
		exit(0);
}
void main()
{
	int gm,gd=DETECT;
	int i,j;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			if(ball[i][j]!='0')
				putpixel(10+i,10+j,ball[j][i]);
	getimage(10,10,30,30,ptr1[4]);
	cleardevice();
	getimage(10,10,30,30,ptr2[4]);
	cleardevice();
	/* start with (20,20) */
	state(20,20,0);
	getch();
}
