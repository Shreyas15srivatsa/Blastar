#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<fstream.h>

enum bool{false,true};

int col(int choi){
	int a;
	if(choi == 1){
		a=RED;
	}
	else if(choi==2){
		a=YELLOW;
	}
	else if(choi==3){
		a=BLUE;
	}
	return a;
}


int choice = 2;
int choice1 = 2;
int choice2 = 2;
int choice3 = 2;
int x, y;
int dmg = 10;
int cx,cy; // coords of crosshairs
char ch2='n';
bool boost = false;
bool sh = false;
bool shcheck;
bool shldcheck;
bool shield = false;
char name[20];
int b =0;
int score = 0;
int att = 0;//attack variable
int shcount;//count of shooting mechanism
int shldcount;
int hp = 5;
bool normal = true;



class scor
{
	public:
		char nam[20];
		int scor;
		void get(char n[20],int s){
			strcpy(nam,n);
			scor=s;
		}
		void out(){
			cout<<"Name:  "<<nam<<endl<<"Score:  "<<scor<<endl;
		}
}t1,t2,h1,h2,h3;


void highsc(char nam[20],int sc){
fstream f;
f.open("abc.dat",ios::app);
	t1.get(nam,sc);
	t1.out();
	f.write((char*)&t1,sizeof(t1));


}

void highdisplay(){
fstream f;
f.open("abc.dat",ios::in);
f.read((char*)&t2,sizeof(t2));
h1=t2;


while(!f.eof()){
	f.read((char*)&t2,sizeof(t2));
	if(t2.scor>h1.scor){
		h3 = h2;
		h2 = h1;
		h1 = t2;

	}
	else if(t2.scor>h2.scor){
		h3 = h2;
		h2 = t2;
	}
	else if(t2.scor>h3.scor){
		h3 = t2;
	}


}

int midx = getmaxx()/2;
int midy = getmaxy()/2;

	getch();
	cleardevice();
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
	setcolor(3);
	outtextxy(midx,midy-180,"HIGHSCORE");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx-150,midy-100,"POSITION");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx,midy-100,"NAME");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx+150,midy-100,"SCORE");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx-150,midy-60,"1)");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx-150,midy-30,"2)");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx-150,midy,"3)");
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx,midy-60,h1.nam);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx,midy-30,h2.nam);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx,midy,h3.nam);
	char sctemp[10];
	itoa(h1.scor,sctemp,10);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx+150,midy-60,sctemp);
	itoa(h2.scor,sctemp,10);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx+150,midy-30,sctemp);
	itoa(h3.scor,sctemp,10);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx+150,midy,sctemp);
	getch();

	cleardevice();
	fstream g;
	g.open("abc.dat",ios::in);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	setcolor(2);
	outtextxy(midx-100,midy-100,"Enter name to search for:");
	getch();
	char temp[20];
	gets(temp);
	while(!g.eof()){
	g.read((char*)&t2,sizeof(t2));
	if(strcmp(temp,t2.nam)==0)
	{
	 t2.out();
	 getch();
	}
}



}

class box{
	public:
		void init();
		void update();
		void display();
		void destroy();
		void kgboss();
		void kgbup();
		void attack();
	private:
		int bx;
		int by;
		int bz;
		bool des;
};

void box::init(){
	bx = random(getmaxx());
	by = random(getmaxy());
	bz = 1;
	des = false;
}

void box::display(){
	int left = bx - 20 - (bz*2);
	int top = by - 20 - (bz*2);
	int right = bx  + 20 + (bz*2);
	int bottom = by  + 20 + (bz*2);

	rectangle(left,top,right,bottom);
	rectangle(left + 4, top + 32, right - 4, bottom - 4);
	setfillstyle(1,5);
	fillellipse(left + 8,top + 8, 3, 3);
	fillellipse(right - 8,top + 8, 3 ,3);
	setfillstyle(1,15);
}


void box::attack(){
	setcolor(4);
	setfillstyle(1,4);
	fillellipse(bx,by+120,8,8);
	fillellipse(bx,((getmaxy()-by-120)/2)+by+120,4,((getmaxy()-by-120)/2)+by+120);
	setcolor(15);
	setfillstyle(1,15);
	if(x>(bx-60)&&x<(bx+60)  &&  shield == false){
		hp--;
	}
}

/* KLINGON BOSS */
void box::kgboss(){
   setcolor(2);
   int left = bx - 40;
   int top = by  - 40;
   int right = bx  + 40;
   int bottom = by  + 40;
   rectangle(left,top,right,bottom);
   rectangle(left + 4, top + 32, right - 4, bottom - 4);
   fillellipse(left + 15,top + 15, 5, 5);
   fillellipse(right - 15,top + 15, 5 ,5);
   setcolor(4);
   setfillstyle(1,4);
   fillellipse(left + 13,top + 16, 2, 2);
   fillellipse(right - 13,top + 16, 2 ,2);
   int poly[8];
   poly[0]= left+4;
   poly[1] = top+32;

   poly[2] = right-4;
   poly[3] = top+32;

   poly[4] = right-4;
   poly[5] = bottom-4;

   poly[6] = left + 4;
   poly[7] = bottom - 4;
   setfillstyle(5,5);
   fillpoly(4, poly);

   setcolor(2);
   setfillstyle(1,15);

   rectangle(left + 4, bottom, right - 4, bottom +40);
   rectangle(left + 4, bottom+40, left + 12, bottom +80);
   rectangle(left + 14, bottom+40, left + 22, bottom +80);
   rectangle(right - 4, bottom+40, right - 12, bottom +80);
   rectangle(right - 14, bottom+40, right - 22, bottom +80);

   rectangle(left - 36, bottom+20, left + 4, bottom +28);
   rectangle(left - 36, bottom+10, left + 4, bottom +18);
   rectangle(right - 4, bottom+20, right + 36, bottom + 28);
   rectangle(right - 4, bottom+10, right +36, bottom +18);
   setcolor(15);
}




void box::destroy(){
	init();
}

void box::update(){
	if(bx<(getmaxx()/2))
		{
			bx = bx - bz;
		}
		else
		{
			bx = bx + bz;
		}

		if(by<(getmaxy()/2))
		{
			by = by - bz;
		}
		else
		{
			by = by + bz;
		}

		if(bx<0||bx>getmaxx() || by>getmaxy()){
			init();
		}
		bz = bz + 1;


		if(des == true){
			des = false;
			destroy();
		}

		if((cx>bx-20-bz*2&&cx<bx+20+bz*2) && (cy>by-20-bz*2&&cy<by+20+bz*2) && sh==true){
			display();
			setcolor(4);
			setfillstyle(1,4);
			fillellipse(bx,by,18,18);
			fillellipse(bx,by-18,5,5);
			fillellipse(bx+18,by-8,5,5);
			setcolor(14);
			setfillstyle(1,14);
			fillellipse(bx,by,9,9);
			fillellipse(bx-5,by+8,4,4);
			setcolor(15);
			setfillstyle(1,15);

			score++;
			des = true;

		}
		else{
			display();
		}
}

void box::kgbup(){	//Boss update
	int a = random(4);
		if(att == (a + 1)){
			attack();
			att = 0;
		}
		if(att>5){
			att=0;
		}
	if(a==0)
		{
			bx = bx - bz;
		}
	else if(a==1)
		{
			bx = bx + bz;
		}

	else if(a==3)
		{
			by = by - bz;
		}
	else
		{
			by = by + bz;
		}

		if(bx<0||bx>getmaxx() || by>getmaxy()){
			init();
		}
		bz = bz + random(2);

		if(des == true){
			destroy();
		}

		if((cx>bx-60&&cx<bx+60) && (cy>by-40&&cy<by+120) && sh==true && normal == true){
			kgboss();
			setcolor(4);
			setfillstyle(1,4);
			fillellipse(bx,by,18,18);
			fillellipse(bx,by-18,5,5);
			fillellipse(bx+18,by-8,5,5);
			setcolor(14);
			setfillstyle(1,14);
			fillellipse(bx,by,9,9);
			fillellipse(bx-5,by+8,4,4);

			setcolor(4);
			setfillstyle(1,4);
			fillellipse(bx-30,by+60,18,18);
			fillellipse(bx-30,by+60,5,5);
			fillellipse(bx+28,by+45,5,5);
			setcolor(14);
			setfillstyle(1,14);
			fillellipse(bx-20,by+60,9,9);
			fillellipse(bx-25,by+58,4,4);

			setcolor(4);
			setfillstyle(1,4);
			fillellipse(bx+30,by-20,18,18);
			fillellipse(bx+30,by-38,5,5);
			fillellipse(bx+18,by-8,5,5);
			setcolor(14);
			setfillstyle(1,14);
			fillellipse(bx+30,by-20,9,9);
			fillellipse(bx+25,by+8,4,4);
			setfillstyle(1,15);
			setcolor(15);

			score+=5;
			dmg--;
			des = true;

		}
		else if((x>bx-60&&x<bx+60) && sh==true && normal == false){
			kgboss();
			setcolor(4);
			setfillstyle(1,4);
			fillellipse(bx,by,18,18);
			fillellipse(bx,by-18,5,5);
			fillellipse(bx+18,by-8,5,5);
			setcolor(14);
			setfillstyle(1,14);
			fillellipse(bx,by,9,9);
			fillellipse(bx-5,by+8,4,4);

			setcolor(4);
			setfillstyle(1,4);
			fillellipse(bx-30,by+60,18,18);
			fillellipse(bx-30,by+60,5,5);
			fillellipse(bx+28,by+45,5,5);
			setcolor(14);
			setfillstyle(1,14);
			fillellipse(bx-20,by+60,9,9);
			fillellipse(bx-25,by+58,4,4);

			setcolor(4);
			setfillstyle(1,4);
			fillellipse(bx+30,by-20,18,18);
			fillellipse(bx+30,by-38,5,5);
			fillellipse(bx+18,by-8,5,5);
			setcolor(14);
			setfillstyle(1,14);
			fillellipse(bx+30,by-20,9,9);
			fillellipse(bx+25,by+8,4,4);
			setfillstyle(1,15);
			setcolor(15);

			score+=5;
			dmg--;
			des = true;

		}
		else{
			kgboss();
		}

		att++;
}

class star{
	public:
	void init();
	void display();
	void update();
	private:
	int sx;
	int sy;
	int sz;
};


	void star::display(){
		fillellipse(sx, sy, sz/15, sz/15);

	}

	void star::init(){

		sx = random(getmaxx());
		sy = random(getmaxy());
		sz = 1;
	}

	void star::update(){
		if(sx<(getmaxx()/2))
		{
			sx = sx - sz;
		}
		else
		{
			sx = sx + sz;
		}

		if(sy<(getmaxy()/2))
		{
			sy = sy - sz;
		}
		else
		{
			sy = sy + sz;
		}

		if(sx<0||sx>getmaxx() || sy>getmaxy()){
			init();
		}
		sz = sz+3;
		sz = sz + b;
		if(boost == true){
			display();
			if(sx<(getmaxx()/2) && sy<(getmaxy()/2))
			{
				line(sx,sy,sx+b-2,sy+b);
			}
			else if(sx<(getmaxx()/2) && sy>(getmaxy()/2))
			{
				line(sx,sy,sx+b-2,sy-b);
			}

			else if(sx>(getmaxx()/2) && sy<(getmaxy()/2))
			{
				line(sx,sy,sx-b+2,sy+b);
			}
			else if(sx>(getmaxx()/2) && sy>(getmaxy()/2))
			{
				line(sx,sy,sx-b+2,sy-b);
			}

		}
		else{
			display();
		}
	}

void man(int x, int y){
	int left = x  - 20;
	int top = y - 40;
	int right = x + 20;
	int bottom = y + 40;
	int centre = x;

	   /* stickman */
	 fillellipse(centre,top,8,8);
	 line(centre,top+8,centre,bottom-30);
	 line(centre,top+20,right,top+40);
	 line(centre,top+20,left,top+40);
	 line(centre,bottom-30,right,bottom);
	 line(centre,bottom-30,left,bottom);

}

void gundam(int x, int y){

	int left = x - 40;
	int right = x + 40;


   /* gundam */
   rectangle(x-25,y-60,x+25,y+10);
   rectangle(x-5,y-70,x+5,y-60);
   rectangle(x-12,y-95,x+12,y-70);
   rectangle(x+12,y-100,x+15,y-90);
   rectangle(x-12,y-100,x-15,y-90);

   rectangle(x-20,y-50,x-5,y-10);
   rectangle(x+20,y-50,x+5,y-10);

   setfillstyle(1,14);
   setcolor(14);
   fillellipse(x-12.5,y-40 , 7, 5);
   fillellipse(x-12.5,y-36 , 6, 4);
   fillellipse(x-12.5,y-33, 5, 3);
   fillellipse(x-12.5,y-29, 4, 2);
   fillellipse(x-12.5,y-25 , 3, 1);
   fillellipse(x+12.5,y-40, 7, 5);
   fillellipse(x+12.5,y-36, 6, 4);
   fillellipse(x+12.5,y-33, 5, 3);
   fillellipse(x+12.5,y-29, 4, 2);
   fillellipse(x+12.5,y-25 , 3, 1);
   setcolor(15);
   setfillstyle(1,15);

   line(x+25,y+10,x+43,y+35);
   line(x+10,y+10,x+28,y+35);
   line(x+43,y+35,x+33,y+75);
   line(x+28,y+35,x+18,y+75);
   rectangle(x-25,y+10,x-10,y+75);
   rectangle(x-35,y+75,x-10,y+85);
   rectangle(x+18,y+75,x+43,y+85);

   setfillstyle(1,10);
   setcolor(2);
   pieslice(x-25,y-35,90,270,35);
   pieslice(x-25,y-60,0,90,10);
   setfillstyle(1,15);
   setcolor(15);

   rectangle(left,y-60,x-25,y-45);
   line(x+25,y-60,right,y-20);
   line(x+25,y-50,right,y-10);
   line(x+25,y-35,right-5,y-10);
   line(right-5,y-10,right,y-10);
   rectangle(right,y-20,right+30,y-10);
   rectangle(right+30,y-17,right+35,y-12);
   setfillstyle(1,5);
   setcolor(5);
   fillellipse(right+35,y-15,2,2);
   setcolor(15);
   setfillstyle(1,15);

   if(sh == true){
	setcolor(5);
	setfillstyle(1,5);
	fillellipse(x,y-110,5,5);
	fillellipse(x,(y-110)/2,5,(y-110)/2);
	setcolor(15);
	setfillstyle(1,15);
   }
   if(shield == true){
	setcolor(2);
	arc(x,y-60,0,180,60);
	setcolor(15);
   }

}

void ship(int x, int y){
	int left, top, right, bottom;
	left = x - 75;
	top = y - 5;
	right = x + 75;
	bottom = y + 25;


   /* draw the ship */

   setcolor(col(choice1));
   rectangle(left,top,right,bottom);
   line(left,top,left+40,top-15);
   line(right,top,right-40,top-15);
   line(left+40,top-15,right-40,top-15);
   line(right+50,top+15,right+40,top+10);

   setcolor(col(choice2)) ;
   rectangle(left-50,top+15,left,bottom);
   rectangle(right,top+15,right+50,bottom);
   setcolor(col(1));

 setcolor(7) ;
   line(right+40,top+10,right,top+10);
   line(left-50,top+15,left-40,top+10);
   line(left-40,top+10,left,top+10);

   setcolor(1);
   setfillstyle(1,9);
   fillellipse(right-30,bottom - 15, 7, 5);
   fillellipse(right-30,bottom - 11, 6, 4);
   fillellipse(right-30,bottom - 8, 5, 3);
   fillellipse(right-30,bottom - 4, 4, 2);
   fillellipse(right-30,bottom , 3, 1);
   fillellipse(left+30,bottom - 15, 7, 5);
   fillellipse(left+30,bottom - 11, 6, 4);
   fillellipse(left+30,bottom - 8, 5, 3);
   fillellipse(left+30,bottom - 4, 4, 2);
   fillellipse(left+30,bottom , 3, 1);
   setcolor(15);
   setfillstyle(1,15);
   rectangle(left-54,top+20,left-50,bottom);
   arc(left-52,top+20,0,180,2);
   rectangle(right+50,top+20,right+54,bottom);
   arc(right + 52,top+20,0,180,2);
   line(right+40,top+10,right+15,top-7);
   line(right+38,top+10,right+13,top-7);
   line(left-40,top+10,left-15,top-3);
   line(left-38,top+10,left-13,top-3);

   if(sh == true){
	setcolor(col(choice3));
	setfillstyle(1,col(choice3));
	fillellipse(left-40,top+10,3,3);
	fillellipse(right+40,top+10,3,3);
	line(left-41,top+13,left-20,top-10);
	line(right+41,top+13,right+20,top-10);
	setcolor(15);
	setfillstyle(1,15);
   }

   //Crosshairs
   setcolor(10);
   line(x,top-50,x,top-45);
   line(x,top-40,x,top-35);
   line(x-7.5,top-42.5,x-2.5,top-42.5);
   line(x+7.5,top-42.5,x+2.5,top-42.5);
   setcolor(15);

   cx = x;
   cy = top-42.5;

}
char ch='m';

void steer(){
	ch = getch();
	if(normal == true){
		if(ch=='w'){
			y-=10;
		}
		else if(ch=='a'){
			x-=10;
		}
		else if(ch=='s'){
			y+=10;
		}
		else if(ch=='d'){
			x+=10;
		}
	}
	else if(normal == false){
		if(ch=='w'){
			y-=20;
		}
		else if(ch=='a'){
			x-=20;
		}
		else if(ch=='s'){
			y+=20;
		}
		else if(ch=='d'){
			x+=20;
		}
	}

}
void kgboss(int bx, int by){
   setcolor(2);
   int left = bx - 40;
   int top = by  - 40;
   int right = bx  + 40;
   int bottom = by  + 40;
   rectangle(left,top,right,bottom);
   rectangle(left + 4, top + 32, right - 4, bottom - 4);
   fillellipse(left + 15,top + 15, 5, 5);
   fillellipse(right - 15,top + 15, 5 ,5);
   setcolor(4);
   setfillstyle(1,4);
   fillellipse(left + 13,top + 16, 2, 2);
   fillellipse(right - 13,top + 16, 2 ,2);
   int poly[8];
   poly[0]= left+4;
   poly[1] = top+32;

   poly[2] = right-4;
   poly[3] = top+32;

   poly[4] = right-4;
   poly[5] = bottom-4;

   poly[6] = left + 4;
   poly[7] = bottom - 4;
   setfillstyle(5,5);
   fillpoly(4, poly);

   setcolor(2);
   setfillstyle(1,15);

   rectangle(left + 4, bottom, right - 4, bottom +40);
   rectangle(left + 4, bottom+40, left + 12, bottom +80);
   rectangle(left + 14, bottom+40, left + 22, bottom +80);
   rectangle(right - 4, bottom+40, right - 12, bottom +80);
   rectangle(right - 14, bottom+40, right - 22, bottom +80);

   rectangle(left - 36, bottom+20, left + 4, bottom +28);
   rectangle(left - 36, bottom+10, left + 4, bottom +18);
   rectangle(right - 4, bottom+20, right + 36, bottom + 28);
   rectangle(right - 4, bottom+10, right +36, bottom +18);
   setcolor(15);
}


void start()
{
   /* request auto detection */
   int gdriver   = DETECT, gmode, errorcode;
   int left, top, right, bottom;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
	  printf("Graphics error: %s\n", grapherrormsg(errorcode));
	  printf("Press any key to halt:");
	  getch();
	  exit(1); /* terminate with an error code */
   }

	class star s[50];
	bool quit = false;
	int i = 0;
	 for(int k =0;k<20;k++){
		 s[k].init();
	 }
   left = getmaxx() / 2 - 50;
   top = getmaxy() / 2 - 25;
   right = getmaxx() / 2 + 50;
   bottom = getmaxy() / 2 + 25;
   int midx = getmaxx()/2;
   int midy = getmaxy()/2;

   char ch;
   int x = midx;
   int y = midy;

   for(int j = 1;j<7;j++){
		cleardevice();
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,j);
		setcolor(3);
		outtextxy(midx,midy,"BLASTARS");
		delay(200);
   }

   ch = getch();
		cleardevice();
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		setcolor(3);
		if(normal==true){
		outtextxy(midx,midy,"Enter Your Name:  ");
		gotoxy(58,16);
		gets(name);
		}




	sound(800);
	delay(100);
	nosound();

   while(ch!='s'){
   cleardevice();
	while(!kbhit()){
			cleardevice();
			setcolor(15);
			for(int j = 0;j<50;j++){
				s[j].update();
			}
			kgboss(midx-200,midy+100);
   setcolor(15);
   rectangle(left,top,right,bottom);
   rectangle(left-150,top,right-150,bottom);
   rectangle(left+150,top,right+150,bottom);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(WHITE);
   outtextxy(midx, midy-150, "BLASTARS");
   outtextxy(midx-150, midy, "Play");
   outtextxy(midx, midy, "Scoreboard");
   outtextxy(midx+150, midy, "Edit");

   setcolor(4);
   setfillstyle(1,4);
   rectangle(x-60,y-30,x+60,y+30);
   pieslice(x, y-40, 45, 135, 30);
   setcolor(15);
   setfillstyle(1,15);
   delay(50);

	}
	cleardevice();
   for(int j = 0;j<50;j++){
				s[j].update();
			}
   kgboss(midx-200,midy+100);
   setcolor(15);
   rectangle(left,top,right,bottom);
   rectangle(left-150,top,right-150,bottom);
   rectangle(left+150,top,right+150,bottom);
   outtextxy(midx, midy-150, "BLASTARS");
   outtextxy(midx-150, midy, "Play");
   outtextxy(midx, midy, "Scoreboard");
   outtextxy(midx+150, midy, "Edit");


   setcolor(4);
   setfillstyle(1,4);
   rectangle(x-60,y-30,x+60,y+30);
   pieslice(x, y-40, 45, 135, 30);
   setcolor(15);
   setfillstyle(1,15);


	ch = getch();

	sound(800);
	delay(100);
	nosound();
	if(ch=='a'&&choice!=1){
		x = x-150;
		choice--;
	}
	else if(ch=='d'&&choice!=3){
		x = x+150;
		choice++;
	}
	else if(ch=='s'){

	}
   }


   /* clean up */
   getch();
   closegraph();
}

void ed(){
	class star s[50];
	bool quit = false;

	 for(int k =0;k<20;k++){
		 s[k].init();
	 }
   int left = getmaxx() / 2 - 50;
   int top = getmaxy() / 2 - 25;
   int right = getmaxx() / 2 + 50;
   int bottom = getmaxy() / 2 + 25;
   int midx = getmaxx()/2;
   int midy = getmaxy()/2;

   char ch;
   int x = midx;
   int y = midy;

		cleardevice();
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
		setcolor(3);
		outtextxy(midx,midy,"Welcome To Edit, You Can Edit Your Ship Here.");

   ch = getch();

	sound(800);
	delay(100);
	nosound();

  for(int e = 0;e<3;e++){

   x = midx;
   y= midy;
   ch='h';
   while(ch!='s'){
   cleardevice();
	while(!kbhit()){
			cleardevice();
			ship(400,400);
			setcolor(15);
			for(int j = 0;j<50;j++){
				s[j].update();
			}
			kgboss(midx-200,midy+100);
   setcolor(15);
   rectangle(left,top,right,bottom);
   rectangle(left-150,top,right-150,bottom);
   rectangle(left+150,top,right+150,bottom);
		settextjustify(CENTER_TEXT,CENTER_TEXT);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		setcolor(WHITE);
		 setcolor(4);
   setfillstyle(1,4);
   rectangle(x-60,y-30,x+60,y+30);
   pieslice(x, y-40, 45, 135, 30);
   setcolor(15);
   setfillstyle(1,15);
   kgboss(midx-200,midy+100);
   if(e==0)
   outtextxy(midx, midy-150, "BODY");
   else if(e==1)
   outtextxy(midx, midy-150, "WINGS");
   else if(e==2)
   outtextxy(midx, midy-150, "LASERS");

   outtextxy(midx-150, midy, "RED");
   outtextxy(midx, midy, "YELLOW");
   outtextxy(midx+150, midy, "BLUE");


   setcolor(4);
   setfillstyle(1,4);
   rectangle(x-60,y-30,x+60,y+30);
   pieslice(x, y-40, 45, 135, 30);
   setcolor(15);
   setfillstyle(1,15);
   delay(50);
}
ch = getch();
	if(e==0){


	sound(800);
	delay(100);
	nosound();
	if(ch=='a'&&choice1!=1){
		x = x-150;
		choice1--;
	}
	else if(ch=='d'&&choice1!=3){
		x = x+150;
		choice1++;
	}
	else if(ch=='s'){

	}
	 }
   if(e==1){

	sound(800);
	delay(100);
	nosound();
	if(ch=='a'&&choice2!=1){
		x = x-150;
		choice2--;
	}
	else if(ch=='d'&&choice2!=3){
		x = x+150;
		choice2++;
	}
	else if(ch=='s'){

	}

		 setcolor(4);
   setfillstyle(1,4);
   rectangle(x-60,y-30,x+60,y+30);
   pieslice(x, y-40, 45, 135, 30);
   setcolor(15);
   setfillstyle(1,15);
   delay(50);




  }
   if(e==2){


	sound(800);
	delay(100);
	nosound();
	if(ch=='a'&&choice3!=1){
		x = x-150;
		choice3--;
	}
	else if(ch=='d'&&choice3!=3){
		x = x+150;
		choice3++;
	}
	else if(ch=='s'){

	}

		 setcolor(4);
   setfillstyle(1,4);
   rectangle(x-60,y-30,x+60,y+30);
   pieslice(x, y-40, 45, 135, 30);
   setcolor(15);
   setfillstyle(1,15);
   delay(50);

	}






   /* clean up */

	}
}

}

void main()
{
	for(int w=0;w<4;w++){
	choice = 2;
	start();
	class star s[50];
	class box bo[5];
	class box boss;
	class box boss2;
	class box boss3;
	clrscr();
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "c://tc//bgi");


	x = getmaxx()/2;
	y = getmaxy()/2;


	bool quit = false;
	if(choice == 1){
	int i = 0;
	 for(int k =0;k<20;k++){
		 s[k].init();
	 }
	 for(k=0;k<5;k++)
		 bo[k].init();

	 //initialising boss
	 boss.init();
	 boss2.init();
	 boss3.init
	 ();

	 outtextxy(getmaxx()/2-20,(getmaxy()/2)-20,"KLINGON WARS");
	 outtextxy(getmaxx()/2-20,(getmaxy()/2)-10,"INSTRUCTIONS:");
	 outtextxy(getmaxx()/2-20,(getmaxy()/2),"1) CLICK ENTER");
	 outtextxy(getmaxx()/2-20,(getmaxy()/2)+10,"2) KILL KLINGONS");
	 outtextxy(getmaxx()/2-20,(getmaxy()/2)+20,"TIP: Use j to shoot");

	 getch();
	 cleardevice();


	while(!quit && dmg>0){
		while(!kbhit()){
			cleardevice();
			for(int j = 0;j<50;j++){
				s[j].update();
			}

			if(score<10)
				for(j=0;j<5;j++)
					bo[j].update();

			if(score>=10){
				boss.kgbup();
				boss2.kgbup();
				boss3.kgbup();
			}

			if(normal==true)ship(x,y);
			else gundam(x,y);
			char str[10];
			itoa(score,str,10);
			outtextxy(540,400,"Score: ");
			outtextxy(620,400,str);
			if(score==10){
			outtextxy(getmaxx()/2,getmaxy()/2,"BOSS LEVEL");
			}
			setcolor(2);
			outtextxy(540,430,"HP: ");
			for(int u = hp;u>0;u--){
				rectangle(580+u*4,429,580+(u*4)+1,441);

			  }
			if(score>=10){
				setcolor(4);
				outtextxy(540,415,"BOSS: ");
				for(u = dmg;u>0;u--){
					rectangle(580+u*4,414,580+(u*4)+1,426);

				}
			}
			setcolor(15);
			delay(50);

		}
		steer();

		if(ch == 'q'){
				quit = true;
			}
		else if(ch == 'b'){
				boost = true;
				b++;
			}
		else if(ch == 'v'){
			b--;
			if(b==0){
				boost = false;
			}
		}
		else if(ch=='j'){
			if(sh == false){
				sh = true;
				shcheck = true;
			}
			else if(sh == true && shcount>4){
				sh = false;
				shcheck = false;
				shcount = 0;
			}
		}
		else if(ch=='k'){
			if(shield == false){
				shield = true;
				shldcheck = true;
			}
			else if(shield == true && shcount>4){
				shield = false;
				shldcheck = false;
				shldcount = 0;
			}
		}

		if(shcheck == true){
			shcount++;
		}
		if(shldcheck==true){
			shldcount++;
		}

		if(shcount>4){
			shcheck = false;
			sh = false;
			shcount = 0;
		}

		if(shldcount>4){
			shldcheck = false;
			shield = false;
			shldcount = 0;
		}

		if(hp<1&&dmg>0){  //Cutscene:
			cleardevice();
			delay(300);
			getch();
			ship(getmaxx()/2,getmaxy()-80);
			man(getmaxx()/2,55);
			setcolor(7);
			outtextxy(100,getmaxy()-140,"You Lost...");
			delay(300);
			getch();
			outtextxy(100,getmaxy()-130,"Too Bad, I expected more from you...");
			setcolor(2);
			delay(300);
			getch();
			outtextxy(100,80,"What else could I have done? I didn't have enough power...");
			delay(300);
			getch();
			cleardevice();
			setcolor(15);
			ship(getmaxx()/2,getmaxy()-80);
			man(getmaxx()/2,55);
			setcolor(7);
			outtextxy(100,getmaxy()-140,"What's that? Think you could have done better?");
			delay(300);
			getch();
			setcolor(2);
			outtextxy(100,80,"Of course! If only I was stronger...");
			delay(300);
			getch();
			setcolor(15);
			cleardevice();
			ship(getmaxx()/2,getmaxy()-80);
			man(getmaxx()/2,55);
			setcolor(7);

			outtextxy(100,getmaxy()-140,"Haha! You interest me human...");
			outtextxy(100,getmaxy()-130,"I'll show you my true power! Let's see how far you get...");
			delay(300);
			getch();
			cleardevice();
			setcolor(15);
			ship(getmaxx()/2,getmaxy()-80);
			man(getmaxx()/2,55);
			setcolor(7);
			sh = false;

			for(int i = 1;i<11;i++){   //transformation
				if(i%2==1){
					cleardevice();
					ship(getmaxx()/2,getmaxy()-100);
					man(getmaxx()/2,40);
					delay(250);
				}
				else{
					cleardevice();
					gundam(getmaxx()/2,getmaxy()-100);
					man(getmaxx()/2,40);
					delay(250);
				}
			}
			delay(300);
			getch();
			cleardevice();
			outtextxy(getmaxx()/2-50,getmaxy()/2,"Now Go Get Him!!!");
			outtextxy(getmaxx()/2-80,getmaxy()/2+20,"Tip: Try using k now.");


			getch();
			getch();
			if(normal == true){
				normal = false;
				hp = 10;
			}
			else{
				quit = true;
			}


			setcolor(15);

		}

		i++;
	}

	//GAME OVER
	cleardevice();
	outtextxy(getmaxx()/2,getmaxy()/2,"GAME OVER");
	if(dmg==0)
	{
		outtextxy(getmaxx()/2,(getmaxy()/2)+10,"YOU WIN!!!");
	}
	else{
		outtextxy(getmaxx()/2,(getmaxy()/2)+10, "YOU GAVE UP!!!");
	}
	char str[10];
	itoa(score,str,10);
	outtextxy(getmaxx()/2-20,(getmaxy()/2)+20,"Score: ");
	outtextxy(getmaxx()/2+25,(getmaxy()/2)+20,str);
	highsc(name,score);
	delay(2000);
	getch();
	}
	else if(choice == 2){
		highdisplay();
	}
	else if(choice == 3){
		ed();
	}
	}


	closegraph();
	getch();
}



