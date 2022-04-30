// code to game snake modified by students of CUFE ,as a project of data structure course
// this game is based on doubly linked list as data structure
// simple note : this game is one or two players ,so any var. is defined twice for two players we put 2 at end of its name
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h> // to measure time.
time_t start ,endi; // start and endi are var. to measure time
int height=25;// height of window of game
int width=100;//width of the window

int gameover=0,counter,gameover2=0,choice,counter2;
int lflag=0,rflag=0,uflag=0,dflag=0;
int lflag2=0,rflag2=0,uflag2=0,dflag2=0;
short fcount;

using namespace std;
class Snake
{
   // x and y are coordinate of head of snake
   // fx and fy are coordinate of fruit
	int x,y,fx,fy,x2,y2;
	char playername[50],playername2[50];

	struct node // doubly linked list
	{
		int nx,ny;
		struct node *next;
		struct node *back;
	};

	struct node *head=NULL;
	struct node *head2=NULL;

	void gotoxy(int x,int y)// function to go to any coordinate of command window
	{
		COORD pos={x,y};
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	}

	void nameandscore()// to calculate score and print score and name
	{
		gotoxy(101,0);
		textcolour(10);
		textcolour(6);
		gotoxy(101,2);
		cout<<playername<<"'s SCORE = "<<counter*100;
		if(choice==2)
		{
			gotoxy(101,4);
			cout<<playername2<<"'s SCORE = "<<counter2*100;
			gotoxy(101,6);
			cout<<"Remained Fruit :";
			gotoxy(117,6);
			cout<<"  ";
			gotoxy(117,6);
			cout<<fcount;
		}
	}



	void textcolour(int k)
	{
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,k);
	}

	public:

	void window() // to make the window of game which contain snake .
	{
		if(choice==1)
		textcolour(4);
		else
		textcolour(1);
			for(int i=0;i<=width;i++)
		{
			gotoxy(i,0);
			cout<<"Û";
			gotoxy(i,height);
			cout<<"Û";
		}

		for(int i=0;i<=height;i++)
		{
			gotoxy(0,i);
			cout<<"Û";
			gotoxy(width,i);
			cout<<"Û";
		}
	}


	void setup() // function to call function window() and design whole setup of game in command window
	{
		counter=0;
		gameover=0;
		window();
		resetflag();
		nameandscore();
		head=new node;
		head->nx=width/2;
		head->ny=height/2;
		head->next=NULL;
		head->back=NULL;
		x=width/2;
		y=height/2;
		label1:
		fx=rand()%width;
		if(fx==0||fx==width)
		goto label1;
		label2:
		fy=rand()%height;
		if(fy==0||fy==height)
		goto label2;
	}

	void setup2()
	{
		resetflag2();
		gameover2=0;
		counter2=0;
		fcount=25;
		head2=new node;
		head2->nx=width/2+5;
		head2->ny=height/2+5;
		head2->next=NULL;
		head2->back=NULL;
		x2=width/2+5;
		y2=height/2+5;

	}

	void drawlist(struct node *h,int k)
	{
		textcolour(k);
		struct node *ptr;
		ptr=h;
		while(ptr!=NULL)
		{
			gotoxy(ptr->nx,ptr->ny);
			cout<<"Û";
			ptr=ptr->next;
		}
	}


	void destroylist(struct node *h)
	{
		struct node *ptr;
		ptr=h;
		while(ptr!=NULL)
		{
			gotoxy(ptr->nx,ptr->ny);
			cout<<" ";
			ptr=ptr->next;
		}
	}



	void draw() // draw fruit in random places in window
	{

		drawlist(head,2);
		drawlist(head2,5);
		gotoxy(fx,fy);
		textcolour(4);
		cout<<"@";
		Sleep(70);
		destroylist(head);
		destroylist(head2);
	}
   // flags refer to direction of movements

	void resetflag()
	{
		uflag=0; // for up
		dflag=0;// for down
		lflag=0;//for left
		rflag=0;//for right
	}

		void resetflag2()
	{
		uflag2=0;
		dflag2=0;
		lflag2=0;
		rflag2=0;
	}

	void play() //  set flags and direction of movement
	{
		int h;
		char ch;
		if(kbhit())
		{

			ch=getch();
			h=ch;
			switch(h)
			{
				case 72:if(dflag!=1){resetflag();uflag=1;}
				break;
				case 80:if(uflag!=1){resetflag();dflag=1;}
				break;
				case 75:if(rflag!=1){resetflag();lflag=1;}
				break;
				case 77:if(lflag!=1){resetflag();rflag=1;}
				break;

				case 119:if(dflag2!=1){resetflag2();uflag2=1;}
				break;
				case 115:if(uflag2!=1){resetflag2();dflag2=1;}
				break;
				case 97:if(rflag2!=1){resetflag2();lflag2=1;}
				break;
				case 100:if(lflag2!=1){resetflag2();rflag2=1;}
				break;

				default:break;
			}
		}
	}

	void box(int m1,int n1,int m2,int n2)
	{
			for(int i=m1;i<=m2;i++)
		{
			gotoxy(i,n1);
			cout<<"//";
			gotoxy(i,n2);
			cout<<"//";
		}

		for(int i=n1;i<=n2;i++)
		{
			gotoxy(m1,i);
			cout<<"//";
			gotoxy(m2,i);
			cout<<"//";
		}
	}

	void welcome()
	{
		textcolour(5);
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
		textcolour(10);
		gotoxy(width/2-20,height/2-10);
		cout<<"*** WELCOME TO OUR GAME *** ";
		textcolour(9);
		gotoxy(width/2-16,height/2-3);
		cout<<"Press 1 For Single player \n";
		gotoxy(width/2-16,height/2-1);
		cout<<"Press 2 For Multiplayer \n";
		gotoxy(width/2-16,height/2);
		cin>>choice;
		system("cls");
	}



	void welcome1()
	{
		textcolour(5);
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
		textcolour(6);
		gotoxy(width/2-18,height/2-3);
		cout<<"WELCOME TO SNAKE GAME SINGLE PLAYER MODE ";
		textcolour(8);
		gotoxy(width/2-13,height/2);
		cout<<"Enter Your Name : ";
		cin>>playername;
		system("cls");
	}

	void welcome2()
	{
		textcolour(5);
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);
		textcolour(6);
		gotoxy(width/2-18,height/2-3);
		cout<<"WELCOME TO SNAKE GAME MULTIPLAYER MODE ";
		textcolour(8);
		gotoxy(width/2-13,height/2);
		cout<<"Enter Player1 Name : ";
		gotoxy(width/2-13,height/2+2);
		cout<<"Enter Player2 Name : ";
		gotoxy(width/2+7,height/2);
		cin>>playername;
		gotoxy(width/2+7,height/2+2);
		cin>>playername2;
		system("cls");
	}




		char end()
	{
		char c;
		gotoxy(width/2-5,height/2-4);
		cout<<"GAME OVER \n";
		textcolour(5);
		box(width/2-width/4,height/2-height/4,width/2+width/4,height/2+height/4);

		textcolour(1);
		gotoxy(width/2-15,height/2-2);
		cout<<playername<<" You Scored : "<<counter*100;
		if(choice==2)
		{
			gotoxy(width/2-15,height/2);
			cout<<playername2<<" You Scored : "<<counter2*100;
			textcolour(4);
			if(gameover!=0)
			{
				gotoxy(width/2-15,height/2+2);
				cout<<playername<<" has lost !";
			}
			else
			{
				gotoxy(width/2-15,height/2+2);
				cout<<playername2 <<" has lost !";
			}
			if(fcount==0)
			{
				textcolour(4);
				gotoxy(width/2-15,height/2+2);
				if(counter>counter2)
				{
					cout<<playername<<" has WON !";
				}
				else
				{
					cout<<playername2<<" has WON !";
				}
			}
		}
		textcolour(6);
		gotoxy(width/2-15,height/2+4);
		cout<<"Want To Play Again ? (Y/N) : ";
		cin>>c;
		system("cls");
		return c;

	}



	void run() //x and y are coordinate which head will go through
	{
		if(uflag==1)
		y--;
		else if(dflag==1)
		y++;
		else if(lflag==1)
		x--;
		else if(rflag==1)
		x++;


			if(uflag2==1)
		y2--;
		else if(dflag2==1)
		y2++;
		else if(lflag2==1)
		x2--;
		else if(rflag2==1)
		x2++;

	}

	void dolist(struct node *h,int pp,int qq) // move the snake to new coordinate x and y
	{
		struct node *ptr,*prev;
		ptr=h;
		prev=h;

		while(ptr->next!=NULL)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		while(prev!=h)
		{
			ptr->nx=prev->nx;
			ptr->ny=prev->ny;
			prev=prev->back;
			ptr=ptr->back;
		}
		ptr->nx=prev->nx;
		ptr->ny=prev->ny;
		prev->nx=pp;
		prev->ny=qq;
	}




	void drawagain() //// make snake cross borders when two players play
	{
		if(x==width)
		{
			x=1;
		}
		if(x==0)
		{
			x=width-1;
		}
		if(y==0)
		{
			y=height-1;
		}
		if(y==height)
		{
			y=1;
		}
	}


	void drawagain2()
	{
		if(x2==width)
		{
			x2=1;
		}
		if(x2==0)
		{
			x2=width-1;
		}
		if(y2==0)
		{
			y2=height-1;
		}
		if(y2==height)
		{
			y2=1;
		}
	}

	void generatefruit() // generate fruits in random places
	{
			label1:
			fx=rand()%width;
			if(fx==0||fx==width)
			goto label1;
			label2:
			fy=rand()%height;
			if(fy==0||fy==height)
			goto label2;
	}

	void checkfcount() // count of fruits when two players play
	{
		if(fcount==0)
		{
			gameover=1;
			gameover2=1;
		}
	}

	void checkup() // check for end of game
	{
		if(choice==1)
		{
			if(x==width||x==0)
			gameover=1;
			if(y==height||y==0)
			gameover=1;
		}
		drawagain();

		struct node *h;
		h=head->next;
		while(h!=NULL)
		{
			if(x==h->nx&&y==h->ny)
			{
				gameover=1;
				break;
			}
			h=h->next;
		}

		if(x==fx&&y==fy)
		{
			if(choice==2)
			{
				fcount--;
				checkfcount();
			}
			struct node *t,*ptr,*prev; // add one node at end of linked list when snake eats fruit
			t=new node;
			t->next=NULL;
			t->back=NULL;
				ptr=head;
				prev=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=t;
				t->back=ptr;
				generatefruit();
			counter++;
			nameandscore();
		}
			dolist(head,x,y);
		}


		void checkup2()
	{
		drawagain2();
		struct node *h;
		h=head2->next;
		while(h!=NULL)
		{
			if(x2==h->nx&&y2==h->ny)
			{
				gameover2=1;
				break;
			}
			h=h->next;
		}

		if(x2==fx&&y2==fy)
		{
			fcount--;
			checkfcount();
			struct node *t,*ptr,*prev;
			t=new node;
			t->next=NULL;
			t->back=NULL;
				ptr=head2;
				prev=head2;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=t;
				t->back=ptr;
				generatefruit();
				counter2++;
				nameandscore();
		}
			dolist(head2,x2,y2);
		}


	void game1() // call all above functions and run the game
	{
		char ch;
		welcome1();
		do{
			setup();
			window();
			while(!gameover)
			{
				draw();
				play();
				run();
				checkup();
			}
			ch=end();
			}while(ch=='y'||ch=='Y');
	}

	void game2()
	{
		char ch;
		welcome2();
		do{

			setup2();
			setup();
			window();
		while(gameover!=1&&gameover2!=1)
			{
				draw();
				play();
				run();
				checkup();
				checkup2();
			}ch=end();
		}while(ch=='y'||ch=='Y');
	}

};
int main()
{
	Snake s;
	s.welcome();
	if(choice==1)
	{
	     time(&start);
		s.game1();
		time(&endi);

	}
	if(choice==2)
	{
		s.game2();
	}
	system("exit");
	double time_taken = double(endi - start);
    cout << "Time taken by program is : " << fixed
         << time_taken ;
    cout << " sec " << endl;
}
