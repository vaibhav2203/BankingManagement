/*	PROGRAM ON BANKING OPERATIONS IN As NORMAL BANK

	THIS PROJECT INCLUDES ALL THE OPERATIONS LIKE DEPOSIT ,WITHDRAWL
	ACCOUNT STATEMENT AND MANY MORE...

	PROJECT IS PRESENTED BY:- VAIBHAV MITTAL
*/
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
union REGS i,o;//union to call for the user defined data type for initialising mouse
void write(int);
void box(int,int,int);
void border();
void transaction();
void mouse()
{  //Function to initialise mouse
	int a1=1;
	while(a1==1)
	{
		i.x.ax=1;
		int86(0x33,&i,&o);
		i.x.ax=3;
		int86(0x33,&i,&o);
		if(o.x.bx||kbhit())
			a1=5;
	}
}
int n=0;
void mcheck(int o1,int x,int y,int a)
{//Function to check for the position of the mouse pointer on the screen
	for(int i=0;i<a;i++)
	{
		if((x>=180&&x<=440)&&(y>=(100+60*i)&&y<=(140+60*i)))
		{
			if(n==i)
				return;
			for(int j=0;j<a;j++)
			{
				if(j!=i)
					box(j,3,o1);
			}
			box(i,15,o1);
			n=i;
		}
	}
}
int check(int o1,int x,int y)
{
	for(int i=0;i<o1;i++)
	{
		if((x>=180&&x<=440)&&(y>=(100+60*i)&&y<=(140+60*i)))
			return i+1;
	}
	return 0;
}
void initial1();
int z=1;
class userentry
{// Class to mantain the users and their details
	int eid;
	char name[50];
	char add[50];
	char phone[12];
	char usern[30];
	char passx[30];
	public :
	void create(int x);
	void show(int n,int x);
	int reteid()
	{
		return eid;
	}
	char* retpass()
	{
		return passx;
	}
	char* retlogin()
	{
		return usern;
	}
	friend void transaction();
}u1;
class customer
{// class to mantain the customers and their private details
	int account;
	char name[40];
	char add[40];
	char phone[12];
	char guarantee[40];
	char father[40];
	char occupation[20];
	char idproof[100];
	char addproof[100];
	long initial;
	long bal;
	public:
	char* retidproof()
	{
		return idproof;
	}
	char* retguarantee()
	{
		return guarantee;
	}
	char* retphone()
	{
		return phone;
	}
	void create(int a);
	long retinitial()
	{
		return initial;
	}
	void showdetails();
	void show1(int a, int x);
	int retaccount()
	{
		return account;
	}
	char* retfather()
	{
		return father;
	}
	char* retoccupation()
	{
		return occupation;
	}
	char* retadd()
	{
		return add;
	}
	char* retname()
	{
		return name;
	}
	void upba( long k4)
	{
		bal = k4;
	}
	long retbal()
	{
		return bal;
	}
	friend void transaction();
	void modify();
}c;
void customer::showdetails()
{// IN built function of the class customer
	border();
	for(int i=3;i<79;i++)
	{
		gotoxy(i,3);
		cout<<"Í";
		gotoxy(i,22);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,2);
		cout<<"Û";
	}
	gotoxy(30,2);
	textbackground(WHITE);
	textcolor(RED+BLINK);
	cprintf("DETAILS OF CUTOMER");
	gotoxy(5,2);
	struct date d;
	getdate(&d);
	gotoxy(68,4);
	printf("%d/", d.da_day);
	printf("%d/", d.da_mon);
	printf("%d", d.da_year);
	textcolor(MAGENTA);
	textbackground(BLACK);
	gotoxy(40,4);
	cout<<"Account no is: "<<account;
	textcolor(MAGENTA);
	textbackground(BLACK);
	gotoxy(4,4);
	cprintf("Name: ");
	gotoxy(4,6);
	cprintf("Address: ");
	gotoxy(4,8);
	cprintf("Father's Name: ");
	gotoxy(4,10);
	cprintf("Phone number: ");
	gotoxy(4,12);
	cprintf("Occupation: ");
	gotoxy(4,14);
	cprintf("Enter the ID proof given: ");
	gotoxy(4,16);
	cprintf("Enter the address proof given: ");
	gotoxy(4,18);
	cprintf("Guaranteer Name: ");
	gotoxy(4,20);
	cprintf("Initial deposit: ");
	gotoxy(40,13);
	cprintf("Current Balance is: ");
	textcolor(WHITE);
	gotoxy(60,13);
	cout<<bal;
	gotoxy(10,4);
	puts(name);
	gotoxy(13,6);
	puts(add);
	gotoxy(19,8);
	puts(father);
	gotoxy(18,10);
	puts(phone);
	gotoxy(16,12);
	puts(occupation);
	gotoxy(30,14);
	puts(idproof);
	gotoxy(35,16);
	puts(addproof);
	gotoxy(21,18);
	puts(guarantee);
	gotoxy(21,20);
	cout<<initial;
}
void customer::modify()
{ //IN built function of the class customer
	closegraph();
	clrscr();
	border();
	int account1;
	char name1[40];
	char add1[40];
	char phone1[12];
	char guarantee1[40];
	char father1[40];
	char occupation1[20];
	char idproof1[100];
	char addproof1[100];
	long int initial1;
	long int bal1;
	for(int i=3;i<79;i++)
	{
		gotoxy(i,3);
		cout<<"Í";
		gotoxy(i,22);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,2);
		cout<<"Û";
	}
	gotoxy(30,2);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	cprintf("MODIFY DETAILS");
	gotoxy(5,2);
	textcolor(BLACK);
	textbackground(WHITE);
	cprintf("PRESS . FOR OLD VALUE");
	struct date d;
	getdate(&d);
	gotoxy(68,4);
	printf("%d/", d.da_day);
	printf("%d/", d.da_mon);
	printf("%d", d.da_year);
	textcolor(MAGENTA);
	textbackground(BLACK);
	gotoxy(4,4);
	cprintf("Name: ");
	gotoxy(4,6);
	cprintf("Address: ");
	gotoxy(4,8);
	cprintf("Father's Name: ");
	gotoxy(4,10);
	cprintf("Phone number: ");
	gotoxy(4,12);
	cprintf("Occupation: ");
	gotoxy(4,14);
	cprintf("Enter the id proof given: ");
	gotoxy(4,16);
	cprintf("Enter the address proof given: ");
	gotoxy(4,18);
	cprintf("Guaranteer Name: ");
	textcolor(WHITE);
     q:	gotoxy(10,4);
	gets(name1);
	int e=0;
	while(name1[e]!='\0')
	{
		if(!(name1[e]>=65&&name1[e]<=90||name1[e]>=97&&name1[e]<=122)&&name1[e]!='.'&&name1[e]!=' ')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(10,4);
			cout<<"                                   ";
			gotoxy(10,4);
			gets(name1);
			e=0;
		}
		else
			e++;
	}
	if(name1[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(10,4);
		cout<<"                                   ";
		goto q;
	}
	gotoxy(5,23);
	cout<<"                                 ";
	if(strcmp(name1,".")!=0)
	{
		strcpy(name,name1);
	}
	gotoxy(13,6);
	gets(add1);
	if(strcmp(add1,".")!=0)
	{
		strcpy(add,add1);
	}
  w:	gotoxy(19,8);
	gets(father1);
	e=0;
	while(father1[e]!='\0')
	{
		if(!((father1[e]==' ')||(father1[e]>=65&&father1[e]<=90)||father1[e]>=97&&father1[e]<=122)&&father1[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(19,8);
			cout<<"                                  ";
			gotoxy(19,8);
			gets(father1);
			e=0;
		}
		else
			e++;
	}
	if(father1[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto w;
	}
	gotoxy(5,23);
			cout<<"                               ";
	if(strcmp(father1,".")!=0)
	{
		strcpy(father,father1);
	}
     asd :	gotoxy(18,10);
	gets(phone1);
	e=0;
	while(phone1[e]!='\0')
	{
		if(!(phone1[e]>=48&&phone1[e]<=57)&&phone1[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only numbers");
			gotoxy(18,10);
			cout<<"                                 ";
			gotoxy(18,10);
			gets(phone1);
			e=0;
		}
		else
			e++;
	}
	gotoxy(5,23);
	cout<<"                               ";
	if(e!=10&&phone1[0]!='.')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please enter a ten digit number");
		gotoxy(18,10);
		cout<<"                                         ";
		goto asd;
	}
	gotoxy(5,23);
	cout<<"                         ";
	if(strcmp(phone1,".")!=0)
	{
		strcpy(phone,phone1);
	}
   e:	gotoxy(16,12);
	gets(occupation1);
	e=0;
	while(occupation1[e]!='\0')
	{
		if(!(occupation1[e]==' '||occupation1[e]>=65&&occupation1[e]<=90||occupation1[e]>=97&&occupation1[e]<=122)&&occupation1[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(16,12);
			cout<<"                              ";
			gotoxy(16,12);
			gets(occupation1);
			e=0;
		}
		else
			e++;
	}
	if(occupation1[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto e;
	}
	gotoxy(5,23);
	cout<<"                               ";
	if(strcmp(occupation1,".")!=0)
	{
		strcpy(occupation,occupation1);
	}
 r:	gotoxy(30,14);
	gets(idproof1);
	e=0;
	while(idproof1[e]!='\0')
	{
		if(!(idproof1[e]==' '||idproof1[e]>=65&&idproof1[e]<=90||idproof1[e]>=97&&idproof1[e]<=122)&&idproof1[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(30,14);
			cout<<"                                 ";
			gotoxy(30,14);
			gets(idproof1);
			e=0;
		}
		else
			e++;
	}
	if(idproof1[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto r;
	}
	gotoxy(5,23);
	cout<<"                                ";
	if(strcmp(idproof1,".")!=0)
	{
		strcpy(idproof,idproof1);
	}
	gotoxy(35,16);
	gets(addproof1);
	if(strcmp(addproof1,".")!=0)
	{
		strcpy(addproof,addproof1);
	}
  t :	gotoxy(21,18);
	gets(guarantee1);
	e=0;
	while(guarantee1[e]!='\0')
	{
		if(!(guarantee1[e]==' '||guarantee1[e]>=65&&guarantee1[e]<=90||guarantee1[e]>=97&&guarantee1[e]<=122)&&guarantee1[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(21,18);
			cout<<"                                 ";
			gotoxy(21,18);
			gets(guarantee1);
			e=0;
		}
		else
			e++;
	}
	if(guarantee[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto t;
	}
	gotoxy(5,23);
			cout<<"                                ";
	if(strcmp(guarantee1,".")!=0)
	{
		strcpy(guarantee,guarantee1);
	}
	a:
	gotoxy(40,5);
	cout<<"Account No is: #"<<account;
	gotoxy(5,23);
	textcolor(YELLOW+BLINK);
	textbackground(BLACK);
	cprintf("ACCOUNT MODIFIED......");
	mouse();
}
void customer::create(int x)
{// IN built function of the class customer
	closegraph();
	border();
	for(int i1=3;i1<79;i1++)
	{
		gotoxy(i1,3);
		cout<<"Í";
		gotoxy(i1,22);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,2);
		cout<<"Û";
	}
	gotoxy(30,2);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	cprintf("OPEN NEW ACCOUNT");
	gotoxy(5,2);
	textcolor(BLACK);
	textbackground(WHITE);
	struct date d;
	getdate(&d);
	gotoxy(68,4);
	printf("%d/", d.da_day);
	printf("%d/", d.da_mon);
	printf("%d", d.da_year);
	textcolor(WHITE);
	gotoxy(4,4);
	cout<<"Name: ";
	gotoxy(4,6);
	cout<<"Address: ";
	gotoxy(4,8);
	cout<<"Father's Name: ";
	gotoxy(4,10);
	cout<<"Phone number: ";
	gotoxy(4,12);
	cout<<"Occupation: ";
	gotoxy(4,14);
	cout<<"Enter the id proof given: ";
	gotoxy(4,16);
	cout<<"Enter the address proof given: ";
	gotoxy(4,18);
	cout<<"Guaranteer Name: ";
	gotoxy(4,20);
	cout<<"Initial deposit: ";
    y :	gotoxy(10,4);
	gets(name);
	int e=0;
	while(name[e]!='\0')
	{
		if(!(name[e]==' '||name[e]>=65&&name[e]<=90||name[e]>=97&&name[e]<=122)&&name[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(10,4);
			cout<<"                               ";
			gotoxy(10,4);
			gets(name);
			e=0;
		}
		else
			e++;
	}
	if(name[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto y;
	}
	gotoxy(5,23);
			cout<<"                                ";
	gotoxy(13,6);
	gets(add);
	gotoxy(19,8);
     u :	gets(father);
     e=0;
	while(father[e]!='\0')
	{
		if(!(father[e]==' '||father[e]>=65&&father[e]<=90||father[e]>=97&&father[e]<=122)&&father[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(19,8);
			cout<<"                                 ";
			gotoxy(19,8);
			gets(father);
			e=0;
		}
		else
			e++;
	}
	if(father[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto u;
	}
	gotoxy(5,23);
			cout<<"                                 ";
ama:	gotoxy(18,10);
	gets(phone);
	e=0;
	while(phone[e]!='\0')
	{
		if(!(phone[e]>=48&&phone[e]<=57))
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only numbers");
			gotoxy(18,10);
			cout<<"                                 ";
			gotoxy(18,10);
			gets(phone);
			e=0;
		}
		else
			e++;
	}
	gotoxy(5,23);
			cout<<"                              ";
	if(e!=10)
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please enter a valid ten digit number");
		gotoxy(5,23);
		cout<<"                                       ";
		goto ama;
	}
	gotoxy(5,23);
			cout<<"                              ";
 i:	gotoxy(16,12);
	gets(occupation);
	e=0;
	while(occupation[e]!='\0')
	{
		if(!(occupation[e]==' '||occupation[e]>=65&&occupation[e]<=90||occupation[e]>=97&&occupation[e]<=122))
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(16,12);
			cout<<"                             ";
			gotoxy(16,12);
			gets(occupation);
			e=0;
		}
		else
			e++;
	}
	if(occupation[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto i;
	}
	gotoxy(5,23);
			cout<<"                                ";
   o:	gotoxy(30,14);
	gets(idproof);
	e=0;
	while(idproof[e]!='\0')
	{
		if(!(idproof[e]==' '||idproof[e]>=65&&idproof[e]<=90||idproof[e]>=97&&idproof[e]<=122))
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(30,14);
			cout<<"                              ";
			gotoxy(30,14);
			gets(idproof);
			e=0;
		}
		else
			e++;
	}
	if(idproof[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto o;
	}
	gotoxy(5,23);
			cout<<"                                ";
	gotoxy(35,16);
	gets(addproof);
	gotoxy(21,18);
p:	gets(guarantee);
	e=0;
	while(guarantee[e]!='\0')
	{
		if(!(guarantee[e]==' '||guarantee[e]>=65&&guarantee[e]<=90||guarantee[e]>=97&&guarantee[e]<=122))
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(21,18);
			cout<<"                             ";
			gotoxy(21,18);
			gets(guarantee);
			e=0;
		}
		else
			e++;
	}
	if(guarantee[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto p;
	}
	gotoxy(5,23);
			cout<<"                                 ";
	gotoxy(21,20);
	char ch=0;
	initial=0;
   c:	int abc=0;
	while(ch!=13)
	{
		gotoxy(21+abc,20);
		ch=getche();
		if((ch<48||ch>57)&&ch!=13)
		{
			gotoxy(21,10);
			cout<<"                           ";
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only numbers");
			gotoxy(21+abc,20);
			goto c;
		}
		else if(ch!=13)
		{
			initial=initial*10+ch-48;
			abc++;
			gotoxy(5,23);
			cout<<"                               ";
		}
	}
	if(initial<1000)
	{

		gotoxy(21,20);
		cout<<"             ";
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("SHOULD NOT BE LESS THAN 1000");
		initial=0;
		ch=1;
		goto c;
	}
	account=x;
	bal=initial;
	gotoxy(40,5);
	cout<<"Account No is: #"<<account;
	gotoxy(5,23);
	textcolor(YELLOW+BLINK);
	textbackground(BLACK);
	cprintf("PRESS ANY KEY TO CONTINUE....");
	mouse();
}
void smallborder();
void modify()
{// Function to modify the account details of a particular customer
	closegraph();
	border();
	fstream f1;
	int m=1,f=0;
	int account3;
	f1.open("customer.dat",ios::binary|ios::in|ios::out);
	gotoxy(6,6);
	cout<<"Enter the account no whose details are to be modified: ";
	cin>>account3;
	long pos=f1.tellg();
	while(f1.read((char*)&c,sizeof(c)))
	{
		if(c.retaccount()==account3)
		{
			f=1;
			c.modify();
			f1.seekg(pos);
			f1.write((char*)&c,sizeof(c));
			break;
		}
		pos=f1.tellg();
	}
	if(f==0&&m==1)
	{
		clrscr();
		border();
		gotoxy(10,8);
		cout<<"No records found    !!!";
		getch();
	}
	f1.close();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
}
void userentry::create(int x)
{// IN built function of the class userentry to create  A NEW USER
	clrscr();
	border();
	gotoxy(3,3);
	cout<<"Enter the name of new user: ";
	gotoxy(3,5);
	cout<<"Enter the address: ";
	gotoxy(3,7);
	cout<<"Enter the phone number:";
	strcpy(usern,name);
	strcpy(passx,name);
	gotoxy(35,3);
   a:	gets(name);
	int e=0;
	while(name[e]!='\0')
	{
		if(!(name[e]==' '||name[e]>=65&&name[e]<=90||name[e]>=97&&name[e]<=122)&&name[e]!='.')
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only characters");
			gotoxy(35,3);
			cout<<"                             ";
			gotoxy(35,3);
			gets(name);
			e=0;
		}
		else
			e++;
	}
	if(name[0]=='\0')
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please use some characters");
		gotoxy(19,8);
		cout<<"                                  ";
		goto a;
	}
	gotoxy(5,23);
	cout<<"                                           ";
	gotoxy(30,5);
	gets(add);
 ama :	gotoxy(30,7);
	gets(phone);
	int d=0;
	while(phone[d]!='\0')
	{
		if(!(phone[d]>=48&&phone[d]<=57))
		{
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Please use only numbers");
			gotoxy(30,7);
			cout<<"                               ";
			gotoxy(30,7);
			gets(phone);
			d=0;
		}
		else
			d++;
	}
	gotoxy(5,23);
	cout<<"                                ";
	if(d!=10)
	{
		gotoxy(5,23);
		textcolor(YELLOW+BLINK);
		textbackground(BLACK);
		cprintf("Please enter a valid ten digit number");
		gotoxy(30,7);
		cout<<"                                         ";
		goto ama;
	}
	gotoxy(5,23);
	cout<<"                            ";
	gotoxy(3,9);
	strcpy(usern,name);
	strcpy(passx,name);
	cout<<"User name is:"<<name;
	gotoxy(3,11);
	cout<<"Password is: "<<name;
	ifstream f1;
	eid=x;
	gotoxy(40,10);
	cout<<"E id is:"<<eid;
}
int z1=1;
void userbox()
{// Function to create theoutlines of the boxes made
	for(int i=3;i<79;i++)
	{
		gotoxy(i,3);
		cout<<"Í";
		gotoxy(i,22);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,2);
		cout<<"Û";
	}
	gotoxy(33,2);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	cprintf("USER DETAILS");
	gotoxy(5,2);
	textcolor(BLACK);
	textbackground(WHITE);
	cprintf("EXIT(ESC)");
	struct date d1;
	getdate(&d1);
	textbackground(WHITE);
	gotoxy(68,2);
	cprintf("%d/", d1.da_day);
	cprintf("%d/", d1.da_mon);
	cprintf("%d", d1.da_year);
	for(j=3;j<79;j++)
	{
		gotoxy(j,4);
		cout<<"Û";
	}
	textcolor(BLUE);
	textbackground(WHITE);
	gotoxy(10,4);
	cprintf("E-ID ");
	gotoxy(26,4);
	cprintf("NAME ");
	gotoxy(42,4);
	cprintf("USERNAME ");
	gotoxy(63,4);
	cprintf("PASSWORD ");
}
void customer::show1(int n,int x)
{// IN built function to display all the details of a customer
	int z=n;
	int a1=x;
	gotoxy(5,6+z);
	cout<<a1<<".";
	gotoxy(23,6+z);
	puts(name);
	gotoxy(45,6+z);
	cout<<bal;
	gotoxy(58,6+z);
	puts(phone);
	gotoxy(10,6+z);
	cout<<account;
	a1++;

}
void userentry::show(int n,int x)
{// In built function to display the details of the user
	int z=n;
	int a1=x;
	gotoxy(5,6+z);
	cout<<a1<<".";
	gotoxy(23,6+z);
	puts(name);
	gotoxy(45,6+z);
	puts(usern);
	gotoxy(58,6+z);
	puts(passx);
	gotoxy(10,6+z);
	cout<<eid;
	a1++;

}
char m[4][100]={"1. LOGIN AS ADMIN","2. LOGIN AS EMPLOYEE","3. VIEW NORMS","4. EXIT"};
char m1[6][100]={"1. CREATE NEW USER","2. SEE ALL USERS","3. CUTOMER RELATED","4. DELETE USER","5. PRIVACY SETTINGS","6. SIGN OUT"};
char m2[6][100]={"1. ACCOUNTS INFO","2. ADD A CUSTOMER","3. MODIFY ACCOUNT","4. TRANSACTION","5. CLOSE ACCOUNT","6. BACK"};
char m3[6][100]={"1. VIEW CUSTOMER","2. PRIVACY SETTINGS","3. TRANSACTION","4. ADD A CUSTOMER","5. CLOSE ACCOUNT","6. SIGN OUT"};
char m4[4][100]={"1. STATEMENT OF A/C","2. ALL ACCOUNTS","3. PRIVATE DETAILS","4. BACK"};
char m5[3][100]={"1. CHANGE USERNAME","2. CHANGE PASSWORD","3. BACK"};
void border();
void write(int o)
{// Function to write the content of the buttons created
	graphdefaults();
	setcolor(BLUE);
	if(o==1)
	{
		settextstyle(7,0,2);
		outtextxy(180,110+60*0,m[0]);
		outtextxy(180,110+60*1,m[1]);
		outtextxy(180,110+60*2,m[2]);
		outtextxy(180,110+60*3,m[3]);
	}
	else if(o==2)
	{
		settextstyle(7,0,2);
		outtextxy(180,110+60*0,m1[0]);
		outtextxy(180,110+60*1,m1[1]);
		outtextxy(180,110+60*2,m1[2]);
		outtextxy(180,110+60*3,m1[3]);
		outtextxy(180,110+60*4,m1[4]);
		outtextxy(180,110+60*5,m1[5]);
	 }
	 else if(o==3)
	{
		settextstyle(7,0,2);
		outtextxy(180,110+60*0,m2[0]);
		outtextxy(180,110+60*1,m2[1]);
		outtextxy(180,110+60*2,m2[2]);
		outtextxy(180,110+60*3,m2[3]);
		outtextxy(180,110+60*4,m2[4]);
		outtextxy(180,110+60*5,m2[5]);
	 }
	 else if(o==4)
	{
		settextstyle(7,0,2);
		outtextxy(180,110+60*0,m3[0]);
		outtextxy(180,110+60*1,m3[1]);
		outtextxy(180,110+60*2,m3[2]);
		outtextxy(180,110+60*3,m3[3]);
		outtextxy(180,110+60*4,m3[4]);
		outtextxy(180,110+60*5,m3[5]);
	 }
	 else if(o==5)
	 {
		settextstyle(7,0,2);
		outtextxy(180,110+60*0,m4[0]);
		outtextxy(180,110+60*1,m4[1]);
		outtextxy(180,110+60*2,m4[2]);
		outtextxy(180,110+60*3,m4[3]);
	 }
	 else if(o==6)
	 {
		settextstyle(7,0,2);
		outtextxy(180,110+60*0,m5[0]);
		outtextxy(180,110+60*1,m5[1]);
		outtextxy(180,110+60*2,m5[2]);
	 }
}
void smallborder()
{// Function to create small border outline
	for(int i=27;i<56;i++)
	{
		gotoxy(i,8);
		cout<<"Í";
	}
	for(int j=27;j<56;j++)
	{
		gotoxy(j,16);
		cout<<"Í";
	}
	for(i=9;i<16;i++)
	{
		gotoxy(26,i);
		cout<<"º";
	}
	for(j=9;j<16;j++)
	{
		gotoxy(56,j);
		cout<<"º";
	}
	gotoxy(56,8);
	cout<<"»";
	gotoxy(56,16);
	cout<<"¼";
	gotoxy(26,16);
	cout<<"È";
	gotoxy(26,8);
	cout<<"É";
}
int selection(int i,int o);
void box(int n);
void option5();
void del();
void option1();
void option2();
void option3()
{// function depicting the customer query menu
	cleardevice();
	setcolor(WHITE);
	line(600,65,30,65);
	settextstyle(8,0,2);
	outtextxy(80,25,"WELCOME ADMIN --> Customer Related");
	box(6);
	setcolor(BLUE);
	write(3);
	int c1=selection(6,3);
	switch(c1)
	{
		case 1: option5();
			break;
		case 2: closegraph();
			ifstream f3;
			ofstream f1;
			f1.open("customer.dat",ios::binary|ios::app);
			f3.open("customer.dat",ios::binary);
			f3.seekg(-sizeof(c),ios::end);
			f3.read((char*)&c,sizeof(c));
			int a=c.retaccount();
			c.create(++a);
			f1.write((char*)&c,sizeof(c));
			f1.close();
			f3.close();
			int gd=DETECT,gm;
			initgraph(&gd,&gm,"c:\\turboc3\\bgi");
			option3();
			break;
		case 3: modify();
			option3();
			break;
		case 4: transaction();
			option3();
			break;
		case 5: del();
			option3();
			break;
		case 6: option2();
			break;
	}
}
void initials()
{// function accounts for the display to recieve the inpiuts from the user
	clrscr();
	for(int i=3;i<79;i++)
	{
		gotoxy(i,3);
		cout<<"Í";
		gotoxy(i,22);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,2);
		textcolor(LIGHTGRAY);
		cprintf("Û");
	}
	gotoxy(33,2);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	cprintf("ACCOUNT DETAILS");
	gotoxy(5,2);
	textcolor(BLACK);
	textbackground(WHITE);
	cprintf("EXIT(ESC)");
	struct date d1;
	getdate(&d1);
	textbackground(WHITE);
	gotoxy(68,2);
	cprintf("%d/", d1.da_day);
	cprintf("%d/", d1.da_mon);
	cprintf("%d", d1.da_year);
	for(j=3;j<79;j++)
	{
		gotoxy(j,4);
		textcolor(LIGHTGRAY);
		cprintf("Û");
	}
	textcolor(BLUE);
	textbackground(WHITE);
	gotoxy(10,4);
	cprintf("ACCOUNT NO ");
	gotoxy(28,4);
	cprintf("NAME ");
	gotoxy(45,4);
	cprintf("BALANCE ");
	gotoxy(63,4);
	cprintf("MOBLIE NO ");
}
void initial1()
{
	clrscr();
	border();
	for(int i=3;i<79;i++)
	{
		gotoxy(i,3);
		cout<<"Í";
		gotoxy(i,22);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,2);
		textcolor(LIGHTGRAY);
		cprintf("Û");
	}
	gotoxy(33,2);
	textcolor(RED+BLINK);
	textbackground(WHITE);
	cprintf("ACCOUNT DETAILS");
	gotoxy(5,2);
	textcolor(BLACK);
	textbackground(WHITE);
	cprintf("EXIT(ESC)");
	struct date d1;
	getdate(&d1);
	textbackground(WHITE);
	gotoxy(68,2);
	cprintf("%d/", d1.da_day);
	cprintf("%d/", d1.da_mon);
	cprintf("%d", d1.da_year);
	for(j=3;j<79;j++)
	{
		gotoxy(j,4);
		textcolor(LIGHTGRAY);
		cprintf("Û");
	}
	textcolor(BLUE);
	textbackground(WHITE);
	gotoxy(7,4);
	cprintf("DATE ");
	gotoxy(15,4);
	cprintf("DETAILS");
	gotoxy(35,4);
	cprintf("DEPOSIT ");
	gotoxy(50,4);
	cprintf("WITHDRAW ");
	gotoxy(65,4);
	cprintf("BALANCE ");
	textcolor(WHITE);
	gotoxy(30,5);
	cout<<"Account Number: ";
}
void del()
{// Function to delete a user
	closegraph();
	border();
	char ch;
	ifstream f1;
	ofstream f2;
	int account4;
	char found='f',confirm='n';
	int m=1;
	f1.open("customer.dat",ios::binary);
	f2.open("temp.dat",ios::binary);
	gotoxy(6,6);
	cout<<"Enter the account no to be closed: ";
	cin>>account4;
	while(f1.read((char*)&c,sizeof(c)))
	{
		if(c.retaccount()==account4)
		{
			clrscr();
			border();
			c.showdetails();
			found='t';
			gotoxy(6,23);
			cout<<"Are you sure to delete this record: ";
			cin>>confirm;
			if(confirm=='n')
			f2.write((char*)&c,sizeof(c));
		}
		else
			f2.write((char*)&c,sizeof(c));
	}
	if(found=='f'&&m==1)
	{
		gotoxy(10,8);
		cout<<"Record Not Found...";
		mouse();
	}
	f1.close();
	f2.close();
	if(m==1)
	{
		remove("customer.dat");
		rename("temp.dat","customer.dat");
	}
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
}
class trans
{// class used to store the details of the transaction made
	long  deposit;
	long balance;
	long withdraw;
	int account;
	char description[100];
	public :
	void upde(char abp[])
	{
		strcpy(description,abp);
	}
	void upba(long k2)
	{
		balance =k2;
	}
	long retbalance()
	{
		return balance;
	}
	void inter();
	void upac(int acc)
	{
		account=acc;
	}
	void update(long a1,long a2,long a3,char a4[])
	{
		deposit=a1;
		withdraw=a2;
		balance=a3;
		strcpy(description,a4);
	}
	struct date d;
	long retdeposit()
	{
		return deposit;
	}
	long retwith()
	{
		return withdraw;
	}
	char* retdesc()
	{
		return description;
	}
	int retaccount()
	{
		return account;
	}
}t;
void trans::inter()
{// IN built function of class trans
	strcpy(description,"INTEREST");
	deposit=(long)balance*0.03;
	withdraw=0;
	balance+=deposit;
	getdate(&d);
}
void option5()
{// Function accounting for the Accounts query menu
	closegraph();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	graphdefaults();
	cleardevice();
	setcolor(WHITE);
	line(600,65,30,65);
	settextstyle(8,0,2);
	outtextxy(80,25,"WELCOME ADMIN --> Accounts Query");
	box(4);
	setcolor(BLUE);
	settextstyle(7,0,4);
	write(5);
	int c1=selection(4,5);
	switch(c1)
	{
		case 1: closegraph();
			border();
			int account,b=1;
			ifstream f7,f8;
			f7.open("customer.dat",ios::binary);
			f8.open("transaction.dat",ios::binary);
			int foundcust=1,founddata=1;
			if(!f7.read((char*)&c,sizeof(c)))
			{
				foundcust=0;
			}
			if(!f8.read((char*)&t,sizeof(t)))
			{
				founddata=0;
			}
			gotoxy(6,6);
			cout<<"Enter the Account no: ";
			cin>>account;
			f7.seekg(0,ios::beg);
			f8.seekg(0,ios::beg);
			while(f7.read((char*)&c,sizeof(c)) && foundcust==1)
			{
				if(c.retaccount()==account)
				{
					clrscr();
					initial1();
					gotoxy(45,5);
					cout<<c.retaccount();
					gotoxy(15,6);
					cout<<"Initial Deposit";
					gotoxy(35,6);
					cout<<c.retinitial();
					gotoxy(65,6);
					cout<<c.retinitial();
				}
			}
			while(f8.read((char*)&t,sizeof(t)) && founddata==1)
			{
				if(t.retaccount()==account)
				{
					gotoxy(5,6+b);
					printf("%d/",t.d.da_day);
					printf("%d/",t.d.da_mon);
					printf("%d",t.d.da_year);
					gotoxy(15,6+b);
					puts(t.retdesc());
					gotoxy(35,6+b);
					cout<<t.retdeposit();
					gotoxy(50,6+b);
					cout<<t.retwith();
					gotoxy(65,6+b);
					cout<<t.retbalance();
					b++;
				}

			}
			if(foundcust==0)
			{
				cprintf("Account Number Not Found");
			}
			textcolor(BLUE+BLINK);
			textbackground(BLACK);
			gotoxy(3,23);
			cprintf("PRESS ANY KEY TO CONTINUE...          ");
			mouse();
			option5();
			break;
		case 2: closegraph();
			border();
			initials();
			ifstream f2;
			int a=1,x=1;
			f2.open("customer.dat",ios::binary);
			while(f2.read((char*)&c,sizeof(c)))
			{
				border();
				c.show1(a,x);
				a++;
				x++;

			}
			gotoxy(5,23);
			textcolor(RED+BLINK);
			textbackground(BLACK);
			cprintf("Press any key");
			mouse();
			f2.close();
			option5();
			break;
		case 3: closegraph();
			textcolor(WHITE);
			textbackground(BLACK);
			clrscr();
			border();
			ifstream f1;
			int account1;
			f1.open("customer.dat",ios::binary);
			gotoxy(6,5);
			cout<<"Enter the Account No to see the details: ";
			cin>>account1;
			clrscr();
			int f=0,m=1;
			while(f1.read((char*)&c,sizeof(c)))
			{
				if(c.retaccount()==account1)
				{
					c.showdetails();
					f=1;
				}
			}
			if(f==0&&m==1)
			{
				clrscr();
				border();
				gotoxy(10,9);
				cprintf("No Records Found!!!");
			}
			gotoxy(5,23);
			textcolor(YELLOW+BLINK);
			textbackground(BLACK);
			cprintf("Press any key to continue...");
			mouse();
			f1.close();
			option5();
			break;
		case 4: option3();
			break;
	}
	closegraph();
}
void transaction()
{// Function accounting the transaction made by the user
	closegraph();
	border();
	fstream f3;
	ofstream f4;
	f3.open("customer.dat",ios::binary|ios::in|ios::out);
	f4.open("transaction.dat",ios::binary|ios::app);
	for(int i=3;i<79;i++)
	{
		gotoxy(i,3);
		cout<<"Í";
		gotoxy(i,22);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,2);
		cout<<"Û";
	}
	gotoxy(33,2);
	int account2,m=1,f=0;
	textbackground(WHITE);
	textcolor(RED+BLINK);
	cprintf("TRANSACTION");
	gotoxy(5,2);
	long pos;
	struct date d;
	getdate(&d);
	gotoxy(68,4);
	printf("%d/", d.da_day);
	printf("%d/", d.da_mon);
	printf("%d", d.da_year);
	gotoxy(6,6);
	long amount;
	cout<<"Enter the account no.: ";
	cin>>account2;
	pos=f3.tellg();
	while(f3.read((char*)&c,sizeof(c)))
	{
		if(c.retaccount()==account2)
		{
		f=1;
		gotoxy(6,6);
		cout<<"                                       ";
		textcolor(MAGENTA);
		textbackground(BLACK);
		gotoxy(6,8);
		cprintf("Account No.: ");
		cout<<c.retaccount();
		gotoxy(6,6);
		cprintf("Date: ");
		printf("%d/", d.da_day);
		printf("%d/", d.da_mon);
		printf("%d", d.da_year);
		for(i=30;i<70;i++)
		{
			textcolor(YELLOW);
			gotoxy(i,10);
			cprintf("Í");
			gotoxy(i,13);
			cprintf("Í");
		}
		for(i=11;i<13;i++)
		{
			gotoxy(29,i);
			cprintf("º");
			gotoxy(70,i);
			cprintf("º");
		}
		gotoxy(32,11);
		cout<<"Name: ";
		puts(c.retname());
		gotoxy(32,12);
		cout<<"Address: ";
		puts(c.retadd());
		char ch8;
		textcolor(MAGENTA);
		gotoxy(6,15);
		cprintf("Last Balance is: ");
		cout<<c.retbal();
		gotoxy(6,17);
		cprintf("Deposit OR Withdrawl(D/W)??: ");
		l:
		gotoxy(35,17);
		textcolor(WHITE);
		ch8=getche();
		if(ch8!='W'&&ch8!='w'&&ch8!='d'&&ch8!='D')
		{
			gotoxy(40,17);
			cout<<"                   ";
			gotoxy(6,23);
			textcolor(YELLOW+BLINK);
			cprintf("PLEASE WRITE CORRECTLY");
			goto l;
		}
		gotoxy(6,23);
		cprintf("                                  ");
		b:
		textcolor(MAGENTA);
		gotoxy(6,19);
		cprintf("Enter the amount: ");
		cin>>amount;
		if((ch8=='W'||ch8=='w')&&amount>c.bal)
		{
			textcolor(RED+BLINK);
			gotoxy(4,23);
			cprintf("Insufficient funds...");
			gotoxy(6,19);
			cout<<"                                     ";
			goto b;
		}
		t.upac(c.account);
		struct date d1;
		getdate(&d1);
		t.d=d1;
		if(ch8=='D'||ch8=='d')
		{
			t.update(amount,0,c.bal+amount,"DEPOSIT");
			c.upba(c.retbal()+amount);
		}
		if(ch8=='W'|| ch8=='w')
		{
			t.update(0,amount,c.bal-amount,"WITHDRAW");
			c.upba(c.retbal()-amount);
		}
		f3.seekg(pos);
		f3.write((char*)&c,sizeof(c));
		f4.write((char*)&t,sizeof(t));
		break;
		}
	pos=f3.tellg();
	}
	int a=1;
	if(f==0&&m==1)
	{
		clrscr();
		textcolor(RED);
		textbackground(BLACK);
		border();
		gotoxy(20,8);
		cout<<"No Records..";
		a=0;
	}
	gotoxy(4,23);
	textcolor(WHITE+BLINK);
	if(a)
	cprintf("Transaction Successful...             ");
	f3.close();
	f4.close();
	mouse();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
}
void option4(char* login1);
void changeuser(char* login1)
{// Function to change the username and password of the user
	closegraph();
	border();
	fstream f9;
	char usern1[20],usern2[20],usern3[20];
	f9.open("users.dat",ios::binary|ios::in|ios::out);
	long pos=f9.tellg();
	while(f9.read((char*)&u1,sizeof(u1)))
	{
		if(strcmp(u1.retlogin(),login1)==0)
		{
			clrscr();
			border();
			smallborder();
			gotoxy(28,10);
			cout<<"Old Username: ";
			gotoxy(28,12);
			cout<<"New Username: ";
			gotoxy(28,14);
			cout<<"Rewrite New Username:";
			gotoxy(45,10);
			gets(usern1);
			gotoxy(45,12);
			gets(usern2);
			gotoxy(50,14);
			gets(usern3);
			if((strcmp(u1.retlogin(),usern1)==0)&&(strcmp(usern2,usern3)==0))
			{
				strcpy(u1.retlogin(),usern2);
				f9.seekg(pos);
				f9.write((char*)&u1,sizeof(u1));
				gotoxy(30,20);
				textcolor(RED+BLINK);
				cprintf("Username changed.");
				delay(1000);
				f9.close();
				option4(login1);
			}
			else
			{
				if(!strcmp(u1.retlogin(),usern1))
				{
					gotoxy(30,20);
					textcolor(RED+BLINK);
					cprintf("Please retype the username correctly");
				}
				else
				{
					gotoxy(30,20);
					textcolor(RED+BLINK);
					cprintf("The Username you entered is incorect");
				}
				delay(1000);
				f9.close();
				option4(login1);
			}
		}
		pos=f9.tellg();
	}
}
void changepass(char* login1);
void option6(char* login1)
{// Function to alter the privacy seting of the user
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
	setcolor(WHITE);
	line(600,65,30,65);
	settextstyle(8,0,2);
	outtextxy(80,25,"EMPLOYEE --> PRIVACY SETTINGS");
	box(3);
	write(6);
	int c2=selection(3,6);
	switch(c2)
	{
		case 1: changeuser(login1);
			break;
		case 2: changepass(login1);
			break;
		case 3: option4(login1);
			break;
	}
	closegraph();
}
void option4(char* login1)
{// Function displaying the main menu of the employee menu
	closegraph();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
	setcolor(WHITE);
	line(600,65,30,65);
	settextstyle(8,0,4);
	outtextxy(170,25,"WELCOME EMPLOYEE");
	box(6);
	setcolor(BLUE);
	write(4);
	int c1=selection(6,4);
	switch(c1)
	{
		case 1: closegraph();
			border();
			int account,b=1;
			ifstream f7,f8;
			f7.open("customer.dat",ios::binary);
			f8.open("transaction.dat",ios::binary);
			gotoxy(6,6);
			cout<<"Enter the Account no: ";
			cin>>account;
			while(f7.read((char*)&c,sizeof(c)))
			{
				if(c.retaccount()==account)
				{
					clrscr();
					initial1();
					gotoxy(45,5);
					cout<<c.retaccount();
					gotoxy(15,6);
					cout<<"Initial Deposit";
					gotoxy(35,6);
					cout<<c.retinitial();
					gotoxy(65,6);
					cout<<c.retinitial();
				}
			}
			while(f8.read((char*)&t,sizeof(t)))
			{
				if(t.retaccount()==account)
				{
					gotoxy(5,6+b);
					printf("%d/",t.d.da_day);
					printf("%d/",t.d.da_mon);
					printf("%d",t.d.da_year);
					gotoxy(15,6+b);
					puts(t.retdesc());
					gotoxy(35,6+b);
					cout<<t.retdeposit();
					gotoxy(50,6+b);
					cout<<t.retwith();
					gotoxy(65,6+b);
					cout<<t.retbalance();
					b++;
				}
			}
			textcolor(BLUE+BLINK);
			textbackground(BLACK);
			gotoxy(3,23);
			cprintf("PRESS ANY KEY TO CONTINUE...          ");
			mouse();
			option4(login1);
			break;
		case 2: option6(login1);
			break;
		case 3: transaction();
			option4(login1);
			break;
		case 4: closegraph();
			ifstream f3;
			ofstream f1;
			f1.open("customer.dat",ios::binary|ios::app);
			f3.open("customer.dat",ios::binary);
			f3.seekg(-sizeof(c),ios::end);
			f3.read((char*)&c,sizeof(c));
			int a=c.retaccount();
			c.create(++a);
			f1.write((char*)&c,sizeof(c));
			f1.close();
			f3.close();
			option4(login1);
			break;
		case 5: del();
			option4(login1);
			break;
		case 6: option1();
			break;
	}
	closegraph();
}
class adminpass
{// Class to change for the admin and password and change them
	public:
	char admin[20];
	char pass[20];
	adminpass()
	{
		strcpy(admin,"vaibhav");
		strcpy(pass,"mittal");
	}
	char* retadmin()
	{
		return admin;
	}
	char* retpass()
	{
		return pass;
	}
}ad;
void passwordch()
{// Function to change the previously existng password
	ofstream f1;
	f1.open("adminpass.dat",ios::binary);
	closegraph();
	char pass1[20],pass2[20],pass3[20];
	border();
	smallborder();
	gotoxy(28,10);
	cout<<"Old Password: ";
	gotoxy(28,12);
	cout<<"New Password: ";
	gotoxy(28,14);
	cout<<"Rewrite New Password:";
	gotoxy(45,10);
	gets(pass1);
	gotoxy(45,12);
	gets(pass2);
	gotoxy(50,14);
	gets(pass3);
	if((strcmp(ad.retpass(),pass1)==0)&&(strcmp(pass2,pass3)==0))
	{

		strcpy(ad.pass,pass2);
		f1.write((char*)&ad,sizeof(ad));
		gotoxy(30,20);
		textcolor(RED+BLINK);
		f1.close();
		cprintf("Password changed.");
		delay(1000);
		option2();
	}
	else
	{
		if(!strcmp(ad.retpass(),pass1))
		{
			gotoxy(30,20);
			textcolor(RED+BLINK);
			cprintf("Please retype the password correctly");
		}
		else
		{
			gotoxy(30,20);
			textcolor(RED+BLINK);
			cprintf("The password you entered is incorect");
		}
		delay(1000);
		f1.close();
		option2();
	}
}
void adminch()
{// Function to change th eusername of admin
	ofstream f1;
	f1.open("adminpass.dat",ios::binary);
	closegraph();
	char admin1[20],admin2[20],admin3[20];
	border();
	smallborder();
	gotoxy(28,10);
	cout<<"Old Username: ";
	gotoxy(28,12);
	cout<<"New Username: ";
	gotoxy(28,14);
	cout<<"Rewrite New Username:";
	gotoxy(45,10);
	gets(admin1);
	gotoxy(45,12);
	gets(admin2);
	gotoxy(50,14);
	gets(admin3);
	if((strcmp(ad.retadmin(),admin1)==0)&&(strcmp(admin2,admin3)==0))
	{
		strcpy(ad.admin,admin2);
		f1.write((char*)&ad,sizeof(ad));
		gotoxy(30,20);
		textcolor(RED+BLINK);
		f1.close();
		cprintf("Username changed.");
		delay(1000);
		option2();
	}
	else
	{
		if(!strcmp(ad.retadmin(),admin1))
		{
			gotoxy(30,20);
			textcolor(RED+BLINK);
			cprintf("Please retype the username correctly");
		}
		else
		{
			gotoxy(30,20);
			textcolor(RED+BLINK);
			cprintf("The username you entered is incorect");
		}
		delay(1000);
		f1.close();
		option2();
	}
}
void changepass(char* login1)
{// Function to change the password
	closegraph();
	border();
	fstream f9;
	char pass1[20],pass2[20],pass3[20];
	f9.open("users.dat",ios::binary|ios::in|ios::out);
	long pos=f9.tellg();
	while(f9.read((char*)&u1,sizeof(u1)))
	{
		if(strcmp(u1.retlogin(),login1)==0)
		{
			clrscr();
			border();
			smallborder();
			gotoxy(28,10);
			cout<<"Old Password: ";
			gotoxy(28,12);
			cout<<"New Password: ";
			gotoxy(28,14);
			cout<<"Rewrite New Password:";
			gotoxy(45,10);
			gets(pass1);
			gotoxy(45,12);
			gets(pass2);
			gotoxy(50,14);
			gets(pass3);
			if((strcmp(u1.retpass(),pass1)==0)&&(strcmp(pass2,pass3)==0))
			{
				strcpy(u1.retpass(),pass2);
				f9.seekg(pos);
				f9.write((char*)&u1,sizeof(u1));
				gotoxy(30,20);
				textcolor(RED+BLINK);
				cprintf("Password changed.");
				delay(1000);
				f9.close();
				option4(login1);
			}
			else
			{
				if(!strcmp(u1.retpass(),pass1))
				{
				gotoxy(30,20);
				textcolor(RED+BLINK);
				cprintf("Please retype the password correctly");
			}
			else
			{
				gotoxy(30,20);
				textcolor(RED+BLINK);
				cprintf("The password you entered is incorect");
			}
			delay(1000);
			f9.close();
			option4(login1);
			}
		}
		pos=f9.tellg();
	}
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
}
void option7()
{// Function to call for the different privacy setings of the admin
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(WHITE);
	line(600,65,30,65);
	settextstyle(8,0,4);
	outtextxy(80,25,"Admin --> Privacy Settings");
	box(3);
	write(6);
	int c1=selection(3,6);
	switch(c1)
	{
		case 1: adminch();
			break;
		case 2: passwordch();
			break;
		case 3: option2();
			break;
	}
	closegraph();
}
void deluser()
{// Function to delete the user created
	closegraph();
	border();
	char ch,name[20];
	ifstream f1;
	ofstream f2;
	char found='f',confirm='n';
	int m=1;
	f1.open("users.dat",ios::binary);
	f2.open("temp.dat",ios::binary);
	gotoxy(6,6);
	cout<<"Enter the E-Name to be DELETED: ";
	gets(name);
	while(f1.read((char*)&u1,sizeof(u1)))
	{
		if(strcmp(u1.retlogin(),name)==0)
		{
			u1.show(1,1);
			found='t';
			gotoxy(6,23);
			cout<<"Are you sure to delete this record: ";
			cin>>confirm;
			if(confirm=='n')
			f2.write((char*)&u1,sizeof(u1));
		}
		else
		f2.write((char*)&u1,sizeof(u1));
	}
	if(found=='f'&&m==1)
	{
		gotoxy(10,8);
		cout<<"Record Not Found...";
		mouse();
	}
	f1.close();
	f2.close();
	if(m==1)
	{
		remove("users.dat");
		rename("temp.dat","users.dat");
	}
}
void option2()
{// Function to display the various options available for the admin to ponder over
	closegraph();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cleardevice();
	setcolor(WHITE);
	line(600,65,30,65);
	settextstyle(8,0,4);
	outtextxy(170,25,"WELCOME ADMIN");
	box(6);
	setcolor(BLUE);
	write(2);
	int c1=selection(6,2);
	switch(c1)
	{
		case 1:
			closegraph();
			border();
			ifstream f9;
			ofstream f11;
			f9.open("users.dat",ios::binary);
			f11.open("users.dat",ios::binary|ios::app);
			f9.seekg(-sizeof(u1),ios::end);
			f9.read((char*)&u1,sizeof(u1));
			int l=u1.reteid();
			u1.create(++l);
			gotoxy(5,13);
			textcolor(RED+BLINK);
			cprintf("New User Created...");
			cout<<"Press any key to Exit.";
			mouse();
			f11.write((char*)&u1,sizeof(u1));
			f11.close();
			f9.close();
			option2();
			break;
		case 2: closegraph();
			border();
			userbox();
			ifstream f2;
			char ch;
			int a=1,x=1;
			f2.open("users.dat",ios::binary);
			while(f2.read((char*)&u1,sizeof(u1)))
			{
				border();
				u1.show(a,x);
				a++;
				x++;
			}
			gotoxy(5,23);
			textcolor(RED+BLINK);
			textbackground(BLACK);
			cprintf("Press any key");
			mouse();
			f2.close();
			option2();
			break;
		case 3:	o.x.bx=0;option3();
			break;
		case 4: o.x.bx=0;deluser();
			option2();
			break;
		case 5: o.x.bx=0;option7();
			break;
		case 6:	o.x.bx=0;option1();
			break;
	}
	closegraph();
}
int count=0;
void admin()
{// Function to check the details entered by the admin
	cleardevice();
	closegraph();
	char ch=0;
	char login1[20],pass1[20];
	border();
	smallborder();
	ifstream f1;
	f1.open("adminpass.dat",ios::binary);
	gotoxy(35,7);
	textcolor(MAGENTA);
	cout<<"ADMIN LOGIN";
	textcolor(WHITE);
	gotoxy(30,10);
	cout<<"Username: ";
	gotoxy(30,13);
	cout<<"Password: ";
	gotoxy(40,10);
	gets(login1);
	gotoxy(40,13);
	int s=0,f=0;
	do
	{
		ch=getch();
		pass1[s]=ch;
		s++;
		cout<<"*";
	}while(ch!=13);
	pass1[s-1]='\0';
	f1.read((char*)&ad,sizeof(ad));
	if((strcmpi(pass1,ad.retpass())==0)&&(strcmpi(login1,ad.retadmin())==0))
	{
		f=1;
	}
	f1.close();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(BLUE);
	rectangle(10,10,630,470);
	rectangle(15,15,625,465);
	setcolor(BLUE);
	circle(320,240,30);
	setcolor(YELLOW);
	outtextxy(264,285,"Authenticating!");
	outtextxy(273,305,"Please wait...");
	for (int d=0,stangle=0,stangle1=180;d<300;d++,stangle++,stangle1--)
	{
		setcolor(RED);
		arc(320,240,stangle,stangle+50,30);
		setcolor(GREEN);
		arc(320,240,stangle1,stangle1+50,30);
		delay(9);
		setcolor(BLUE);
		arc(320,240,stangle-1,stangle+49,30);
		arc(320,240,stangle1-1,stangle1-49,30);
	}
	setcolor(WHITE);
	if(f)
	{
		outtextxy(256,370,"Access Granted...");
		delay(1500);
		option2();
	}
	else
	{
		outtextxy(256,370,"Access Denied...");
		delay(1500);
		option1();
	}
}
void user()
{// Function to check for the details entered by the user
	closegraph();
	ifstream f1;
	f1.open("users.dat",ios::binary);
	char login1[20],pass1[20];
	border();
	smallborder();
	textcolor(MAGENTA);
	gotoxy(35,7);
	cout<<"EMPLOYEE LOGIN";
	textcolor(WHITE);
	gotoxy(30,10);
	cout<<"Username: ";
	gotoxy(30,13);
	cout<<"Password: ";
	gotoxy(40,10);
	gets(login1);
	gotoxy(40,13);
	char ch;
	int s=0,f=0;
	do
	{
		ch=getch();
		pass1[s]=ch;
		s++;
		cout<<"*";
	}while(ch!=13);
	pass1[s-1]='\0';
	while(f1.read((char*)&u1,sizeof(u1)))
	{
		if((strcmp(pass1,u1.retpass())==0)&&(strcmp(login1,u1.retlogin())==0))
		{
			f=1;
		}
	}
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(BLUE);
	rectangle(10,10,630,470);
	rectangle(15,15,625,465);
	setcolor(BLUE);
	circle(320,240,30);
	setcolor(YELLOW);
	outtextxy(264,285,"Authenticating!");
	outtextxy(273,305,"Please wait...");
	for (int d=0,stangle=0,stangle1=180;d<300;d++,stangle++,stangle1--)
	{
		setcolor(RED);
		arc(320,240,stangle,stangle+50,30);
		setcolor(GREEN);
		arc(320,240,stangle1,stangle1+50,30);
		delay(9);
		setcolor(BLUE);
		arc(320,240,stangle-1,stangle+49,30);
		arc(320,240,stangle1-1,stangle1-49,30);
	}
	setcolor(WHITE);
	if(f==1)
	{
		outtextxy(256,370,"Access Granted...");
		delay(1500);
		f1.close();
		option4(login1);
	}
	else
	{
		outtextxy(256,370,"Access Denied...");
		delay(1500);
		f1.close();
		option1();
	}

}
void border()
{//Function to create border for the different screens appearing
	textcolor(WHITE);
	for(int i=3;i<79;i++)
	{
		gotoxy(i,1);
		cout<<"Í";
	}
	for(int j=3;j<79;j++)
	{
		gotoxy(j,24);
		cout<<"Í";
	}
	for(i=2;i<24;i++)
	{
		gotoxy(2,i);
		cout<<"º";
	}
	for(j=2;j<24 ;j++)
	{
		gotoxy(79,j);
		cout<<"º";
	}
	gotoxy(79,1);
	cout<<"»";
	gotoxy(79,24);
	cout<<"¼";
	gotoxy(2,24);
	cout<<"È";
	gotoxy(2,1);
	cout<<"É";
}
void box(int i,int color,int o)
{//functions to recreate the boxes after pessing the arrow keys
	setcolor(BROWN);
	line(180,100+60*i,440,100+60*i);
	line(180,140+60*i,440,140+60*i);
	line(180,100+60*i,170,120+60*i);
	line(170,120+60*i,180,140+60*i);
	line(440,100+60*i,450,120+60*i);
	line(450,120+60*i,440,140+60*i);
	setfillstyle(1,color);
	floodfill(270,120+60*i,BROWN);
	setcolor(BLUE);
	write(o);
}
void box(int a)
{// Function to print the number of the boxes initially
	for(int i=0;i<a;i++)
	{
		setcolor(BROWN);
		line(180,100+60*i,440,100+60*i);
		line(180,140+60*i,440,140+60*i);
		line(180,100+60*i,170,120+60*i);
		line(170,120+60*i,180,140+60*i);
		line(440,100+60*i,450,120+60*i);
		line(450,120+60*i,440,140+60*i);
		setfillstyle(1,CYAN);
		floodfill(270,120+60*i,BROWN);
	}
	line(180,100,440,100);
	line(180,140,440,140);
	line(180,100,170,120);
	line(170,120,180,140);
	line(440,100,450,120);
	line(450,120,440,140);
	setfillstyle(1,WHITE);
	floodfill(270,120,BROWN);
}
void norms()
{// Function to declare the norms of the bank
	closegraph();
	clrscr() ;
	border();
	textcolor(LIGHTBLUE) ;
	textbackground(WHITE);
	gotoxy(27,3); cprintf("WELCOME TO PROJECT BANKING") ;
	delay(10) ;
	gotoxy(10,5);  cout <<"   IN  THIS  PROJECT	YOU CAN  KEEP  RECORD FOR  DAILY ";
	delay(10) ;
	gotoxy(10,6);  cout <<"\t\tBANKING  TRANSACTIONS. 	     " ;
	delay(10) ;
	gotoxy(10,8);  cout <<"- THIS  PROGRAM IS CAPABLE OF HOLDING ANY No. OF ACCOUNTS";
	delay(10) ;
	gotoxy(10,10); cout <<"-1.) In the first option you can login as an ADMIN and can";
	delay(10) ;
	gotoxy(10,11); cout <<" have various accounting options related to  daily Banking." ;
	delay(10) ;
	gotoxy(10,13); cout <<"-2.) In second option you can login as an employee of the company." ;
	delay(10) ;
	gotoxy(10,15); cout <<"-3.) Employee of the company has some restricted entry" ;
	delay(10) ;
	gotoxy(10,16); cout <<"  that is, he cannot have access to all the features" ;
	delay(10) ;
	gotoxy(10,23); cout <<"-6.) In Fourth option you will quit from the program ." ;
	delay(10) ;
	gotoxy(10,19); cout <<"  (NOTE: Opening amount i.e. , the first deposit should not be " ;
	delay(10) ;
	gotoxy(10,20); cout <<" less than Rs.1000/-";
	delay(10);
	gotoxy(10,22); cout <<"-5.) Employee cannot modify the account. he cannot see all accounts" ;
	delay(10) ;
	gotoxy(10,18); cout <<"-4.) In third option the help menu is displayed ";
	delay(10) ;
	textcolor(RED+BLINK) ; textbackground(WHITE+BLINK) ;
	gotoxy(26,25) ; cprintf(" Press a key to continue ") ;
	textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
	gotoxy(25,2) ;
	mouse();
	for (int i=25; i>=1; i--)
	{
		delay(20) ;
		gotoxy(1,i) ; clreol() ;
	}
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	option1();
}
int selection(int n,int o1)
{ // Function to check for the selections made by the user
	settextstyle(8,0,2);
	setcolor(BLUE);
	int counter=0,g=0,c1,a=0;
	char ch=0;
	do
	{
		i.x.ax=1;
		int86(0x33,&i,&o);
		i.x.ax=3;
		int86(0x33,&i,&o);
		o.x.cx=1;
		o.x.dx=1;
		int86(0x33,&i,&o);
		i.x.ax=3;
		int86(0x33,&i,&o);
		if(o.x.bx)
		{
			a=check(n,o.x.cx,o.x.dx);
			if(a)
				return a;
		}
		mcheck(o1,o.x.cx,o.x.dx,n);
		if(kbhit())
		{
			ch=getch();
			c1=1;
		}
		if(ch==80&&c1)
		{
			g=1;
			if(counter==0)
				box(counter,3,o1);
			else
				box(counter-1,3,o1);
			if(counter==n)
			{
				counter=0;
				box(counter,15,o1);
			}
			else
				box(counter,15,o1);
			counter++;
		}
		else if(ch==72&&c1)
		{
			g=2;
			if(counter==n)
				box(counter-1,3,o1);
			else
				box(counter,3,o1);
			if(counter==0)
			{
				counter=n;
				box(counter-1,15,o1);
			}
			else
				box(counter-1,15,o1);
			counter--;
		}
		else if(ch==13)
			a=1;
		c1=0;
	}while(!a);
	if(g==0)
		return counter+1;
	if(g==1)
		return counter;
	if(g==2)
		return counter+1;
	else
		return 0;
}
void end()
{// Function to display the graphics that appear when we take leave from the program
	graphdefaults();
	closegraph();
	int gd=DETECT,gm;
	initgraph(&gd, &gm, "c:\\turboc3\\bgi");
	setcolor(GREEN);
	ellipse(320,240,0,360,300,150);
	settextstyle(10,0,4);
	settextjustify(1,1);
	setcolor(5);
	outtextxy(320,170,"PROJECT BANKING");
	delay(250);
	settextstyle(4,0,4);
	settextjustify(1,1);
	setcolor(20);
	outtextxy(320,220,"Presented By:");
	delay(250);
	settextstyle(10,0,4);
	settextjustify(1,1);
	setcolor(3);
	delay(250);
	outtextxy(320,265,"VAIBHAV MITTAL");
	int a=1,stangle=0;
	while(a!=0)
	{
		setcolor(BLUE);
		ellipse(320,240,stangle,stangle+20,300,150);
		ellipse(320,240,stangle+180,stangle+200,300,150);
		delay(9);
		setcolor(GREEN);
		ellipse(320,240,stangle-1,stangle+19,300,150);
		ellipse(320,240,stangle-1+180,stangle+199,300,150);
		i.x.ax=1;
		int86(0x33,&i,&o);
		i.x.ax=3;
		int86(0x33,&i,&o);
		if(o.x.bx)
			a=0;
		if(kbhit())
			a=0;
		stangle++;
	}
	closegraph();
}
void option1()
{// Function to display the most basic menu
	cleardevice();
	setcolor(WHITE);
	cleardevice();
	rectangle(10,10,630,470);
	rectangle(15,15,625,465);
	setcolor(LIGHTGRAY);
	settextstyle(8,0,4);
	outtextxy(190,25,"B A N K I N G");
	setcolor(8);
	line(600,65,30,65);
	settextstyle(7,1,5);
	outtextxy(45,80,"O P T I O N S");
	outtextxy(550,80,"O P T I O N S");
	graphdefaults();
	settextstyle(7,0,2);
	int c;
	box(4);
	setcolor(BLUE);
	outtextxy(180,110,"1. LOGIN AS ADMIN");
	outtextxy(180,170,"2. LOGIN AS EMPLOYEE");
	outtextxy(180,230,"3. VIEW NORMS");
	outtextxy(180,290,"4. EXIT");
	c=selection(4,1);
	switch(c)
	{
		case 1:o.x.bx=0;admin(); break;
			case 2:o.x.bx=0;user(); break;
		case 3:o.x.bx=0;norms(); break;
		case 4:o.x.bx=0;end(); exit(0);
		default:outtextxy(150,300,"Wrong entry.. Please try again.");
			delay(500);
			option1();
	}
	closegraph();
}
class in
{// Class to store the year whose interest has been credited
	public :
	int year;
}as;
void interest()
{// Function to credit the interest in incorporate it as a transaction
	struct date d;
	getdate(&d);
	int year;
	ifstream f;
	f.open("interest.dat",ios::binary);
	f.read((char*)&as,sizeof(as));
	f.close();
	if(d.da_day==31&&d.da_mon==12)
	{
		if(as.year==d.da_year)
			return;
		else
		{
			as.year=d.da_year;
			ofstream a3;
			a3.open("interest.dat",ios::binary);
			a3.write((char*)&as,sizeof(as));
			a3.close();
			customer k;
			ifstream a1;
			a1.open("customer.dat",ios::binary);
			ifstream b2;
			while(a1.read((char*)&k,sizeof(k)))
				continue;
			a1.close();
			int acc=k.retaccount();
			trans a9,a8;
			a9.upde("NULL");
			while(acc>0)
			{
				b2.open("transaction.dat",ios::binary);
				b2.read((char*)&a8,sizeof(a8));
				do
				{
					if(a8.retaccount()==acc)
						a9=a8;
				}while(b2.read((char*)&a8,sizeof(a8)));
				b2.close();
				if(strcmpi(a9.retdesc(),"NULL"))
				{
					a3.open("transaction.dat",ios::binary|ios::app);
					a9.inter();
					a3.write((char*)&a9,sizeof(t));
					a3.close();
				}
				else
				{
					a1.open("customer.dat",ios::binary);
					a1.seekg(0,ios::beg);
					while(a1.read((char*)&k,sizeof(k)))
					{
						if(k.retaccount()==acc)
						{
							a1.close();
							a3.open("transaction.dat",ios::binary);
							a9.upac(acc);
							a9.upba(k.retinitial());
							a9.inter();
							a3.write((char*)&a9,sizeof(a9));
							a3.close();
							break;
						}
					}
				}
				a9.upde("NULL");
				acc--;
			}
		}
	}
}
void main()
{// Main function
	customer ap;
	ifstream ks("customer.dat",ios::binary);
	if(ks.read((char*)&ap,sizeof(ap)))
		interest();
	ks.close();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	setcolor(RED);
	rectangle(10,10,630,470);
	rectangle(15,15,625,465);
	settextstyle(8,0,8);
	setcolor(BLUE);
	outtextxy(140,50,"WELCOME");
	outtextxy(260,120,"TO");
	outtextxy(210,190,"HDFC");
	settextstyle(2,0,6);
	setcolor(WHITE);
	outtextxy(180,318,"Loading..");
	rectangle(308,322,408,337);
	int n=0;
	for(int i1=0,j=0;i1<50,j<50;i1++,j+=2)
	{
		settextstyle(8,0,8);
		setcolor(i1);
		outtextxy(140,50,"WELCOME");
		delay(45);
		setcolor(i1+2);
		outtextxy(260,120,"TO");
		delay(45);
		setcolor(i1+4);
		outtextxy(210,190,"HDFC");
		delay(45);
		setcolor(WHITE);
		setfillstyle(8,RED);
		rectangle(310,324,310+2*j,335);
		floodfill(312,322,WHITE);
		delay(1);
		gotoxy(34,21);
		cout<<n*2<<"%";
		n+=2;
		if(n==20)
			n+=2;
	}
	settextstyle(4,0,2);
	int a1=1;
	while(a1==1)
	{
		setcolor(RED);
		outtextxy(130,350,"PRESS ANY KEY TO CONTINUE.");
		delay(300);
		setcolor(BLACK);
		outtextxy(130,350,"PRESS ANY KEY TO CONTINUE.");
		delay(300);
		i.x.ax=1;
		int86(0x33,&i,&o);
		i.x.ax=3;
		int86(0x33,&i,&o);
		if(o.x.bx)
			a1=0;
		if(kbhit())
			a1=0;
	}
	option1();
	closegraph();
}
