#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
struct books
{
	char book_name[40];
	char user_name[20];
	char password[20];
	char auther_name[20];
	int book_id;
	int quantity;
}b;
void add();
void user();
void user_reg();
void user_login();
void admin_login();
void selection();
void del();
void edit();
void display();
long resize=sizeof(b);
FILE *fp;
int choice;
int l,k,i=0,c;
char pass[20],name[20];
void main()
{
	int ch1,ch,i;
	clrscr();
	gotoxy(27,2);
	printf("WELCOME TO LIBRARY MANAGEMENT");
	gotoxy(27,3);
	for(i=0;i<30;i++)
		printf("*");
	gotoxy(26,13);
	printf("Press Enter to further process !") ;
	if(getch()==13)
	clrscr();
	else
	clrscr();
	fault:
	gotoxy(27,2);
	printf("WELCOME TO LIBRARY MANAGEMENT");
	gotoxy(27,3);
	for(i=0;i<30;i++)
	printf("*");
	gotoxy(1,9);
	printf("1.ADMIN");
	gotoxy(35,9);
	printf("2.USER");
	gotoxy(70,9);
	printf("3.EXIT");
	gotoxy(27,12);
	printf("ENTER YOUR CHOICE:");
	cin>>ch1;
	switch(ch1)
	{
		case 1:
			clrscr();
			admin_login();
			clrscr();
			break;
		case 2:
				user:
				clrscr();
				gotoxy(27,2);
				printf("LIBRARY MANAGEMENT");
				gotoxy(27,3);
				for(i=0;i<18;i++)
				printf("-");
				gotoxy(1,9);
				printf("1.LOGIN");
				gotoxy(35,9);
				printf("2.REGISTER");
				gotoxy(70,9);
				printf("3.EXIT");
				gotoxy(27,12);
				printf("ENTER YOUR CHOICE:");
				cin>>ch1;
				if(ch1==1)
					user_login();
				else if(ch1==2)
					user_reg();
				else if(ch1==3)
					exit(1);
				else
					cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
					if(getch()==13)
					clrscr();
					goto user;
		case 3:
			exit(1);
		default:
			cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
			if(getch()==13)
			clrscr();
			goto fault;
	}

}
void selection()
{

	int ch1,ch,i;
	adminfault:
	gotoxy(35,2);
	printf("LIBRARY MANAGEMENT");
	gotoxy(35,3) ;
	for(i=0;i<18;i++)
		printf("*");
	gotoxy(70,5) ;
	cout<<"1.CSE ";
	gotoxy(70,7);
	cout<<"2.ECE";
	gotoxy(70,9);
	printf("3.EEE");
	gotoxy(70,11);
	printf("4.MECH");
	gotoxy(70,13);
	cout<<"5.CIVIL";
	gotoxy(70,15);
	cout<<"6.EXIT";
	cin>>choice;
	if(choice==6)
	exit(1);
	else if(choice>6)
	{
			cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
			if(getch()==13)
			clrscr();
			goto adminfault;
	}
	wrong:
	if(i==0)
	{
		while(1)
		{
			clrscr();
			gotoxy(35,2);
			printf("LIBRARY MANAGEMENT");
			gotoxy(35,3) ;
			for(i=0;i<18;i++)
			printf("-");
			printf("\n1.Add books\n\n");
			printf("2.Edit books\n\n");
			printf("3.Delete books\n\n");
			printf("4.Display books\n\n");
			printf("5.Exit\n\n");
			printf("Enter your choice\t");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					clrscr();
					add();
					break;
				case 2:
					clrscr();
					edit();
					break;
				case 3:
					clrscr();
					del();
					break;
				case 4:
					clrscr();
					display();
					break;
				case 5:
					exit(1);
				default:
					cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
					if(getch()==13)
					clrscr();
					goto wrong;
			}
		}
	}
	else
	user();
}



void add()
{
	adminfault:
	switch(choice)
	{
		case 1:
			fp=fopen("cse.txt","rb+");
			if(fp==NULL)
			fp=fopen("cse.txt","wb+");
			break;
		case 2:
			fp=fopen("ece.txt","rb+");
			if(fp==NULL)
			fp=fopen("ece.txt","wb+");
			break;
		case 3:
			fp=fopen("eee.txt","rb+");
			if(fp==NULL)
			fp=fopen("eee.txt","wb+");
			break;
		case 4:
			fp=fopen("mech.txt","rb+");
			if(fp==NULL)
			fp=fopen("mech.txt","wb+");
			break;
		case 5:
			fp=fopen("civil.txt","rb+");
			if(fp==NULL)
			fp=fopen("civil.txt","wb+");
			break;
		default:
			cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
			if(getch()==13)
			clrscr();
			goto adminfault;
	}

	cout<<"Enter the BOOK NAME :\t";
	cin>>b.book_name;
	cout<<"Enter the AUTHER NAME :\t";
	cin>>b.auther_name;
	cout<<"Enter the BOOK ID :\t";
	cin>>b.book_id;
	cout<<"Enter the BOOK quantity :\t";
	cin>>b.quantity;
	fseek(fp,0,2);
	fwrite(&b,resize,1,fp);
	fclose(fp);
}
void edit()
{
	int ch,id,new1;
	char name[20];
	adminfault:
	switch(choice)
	{
		case 1:
			fp=fopen("cse.txt","rb+");
			if(fp==NULL)
			fp=fopen("cse.txt","wb+");
			break;
		case 2:
			fp=fopen("ece.txt","rb+");
			if(fp==NULL)
			fp=fopen("ece.txt","wb+");
			break;
		case 3:
			fp=fopen("eee.txt","rb+");
			if(fp==NULL)
			fp=fopen("eee.txt","wb+");
			break;
		case 4:
			fp=fopen("mech.txt","rb+");
			if(fp==NULL)
			fp=fopen("mech.txt","wb+");
			break;
		case 5:
			fp=fopen("civil.txt","rb+");
			if(fp==NULL)
			fp=fopen("civil.txt","wb+");
			break;
		default:
			cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
			if(getch()==13)
			clrscr();
			goto adminfault;
	}

	rewind(fp);
	cout<<"Enter Id\n";
	cin>>id;
	while(fread(&b,resize,1,fp)==1)
	{
		if(b.book_id==id)
		{
			wrong:
			cout<<"1.BOOK NAME\n2.AUTHER NAME\n3.ID\n4.QUANTITY";
			cin>>ch;
			switch(ch)
			{
				case 1:
					fseek(fp,-resize,1);
					cout<<"\nEnter the new Name:\t";
					cin>>name;
					strcpy(b.book_name,name);
					fwrite(&b,resize,1,fp);
					fclose(fp);
					break;
				case 2:
					fseek(fp,-resize,1);
					cout<<"\nEnter the new Auther name:\t";
					cin>>name;
					strcpy(b.auther_name,name);
					fwrite(&b,resize,1,fp);
					fclose(fp);
					break;
				case 3:
					fseek(fp,-resize,1);
					cout<<"\nEnter the new ID:\t";
					cin>>new1;
					b.book_id=new1;
					fwrite(&b,resize,1,fp);
					fclose(fp);
					break;
				case 4:
					fseek(fp,-resize,1);
					cout<<"\nEnter the new Quantity:\t";
					cin>>new1;
					b.quantity=new1;
					fwrite(&b,resize,1,fp);
					fclose(fp);
					break;
				default:
					cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
					if(getch()==13)
					clrscr();
					goto adminfault;

			}

		}
	}

}
void display()
{
	int i;
	adminfault:
	switch(choice)
	{
		case 1:
			fp=fopen("cse.txt","rb+");
			if(fp==NULL)
			fp=fopen("cse.txt","wb+");
			break;
		case 2:
			fp=fopen("ece.txt","rb+");
			if(fp==NULL)
			fp=fopen("ece.txt","wb+");
			break;
		case 3:
			fp=fopen("eee.txt","rb+");
			if(fp==NULL)
			fp=fopen("eee.txt","wb+");
			break;
		case 4:
			fp=fopen("mech.txt","rb+");
			if(fp==NULL)
			fp=fopen("mech.txt","wb+");
			break;
		case 5:
			fp=fopen("civil.txt","rb+");
			if(fp==NULL)
			fp=fopen("civil.txt","wb+");
			break;
		default:
			cout<<"\a\aWrong choice !"<<"\nPress\"Enter\"to Re-Enter";
			if(getch()==13)
			clrscr();
			goto adminfault;
	}
	rewind(fp);
	gotoxy(1,1);
	cout<<"BOOK_NAME";
	gotoxy(1,2);
	for(i=1;i<10;i++)
	cout<<"-";
	gotoxy(21,1);
	cout<<"AUTHER_NAME";
	gotoxy(21,2);
	for(i=0;i<=10;i++)
	cout<<"-";
	gotoxy(41,1);
	cout<<"BOOK_ID";
	gotoxy(41,2);
	for(i=4;i<=10;i++)
	cout<<"-";
	gotoxy(61,1);
	cout<<"QUANTITY\n";
	gotoxy(61,2);
	for(i=3;i<=10;i++)
	cout<<"-";
	printf("\n");
	while(fread(&b,resize,1,fp)==1)
	printf("%-20s \b%-20s  %-5d \t\t\b%-3d\n",b.book_name,b.auther_name,b.book_id,b.quantity);
	fclose(fp);
	getch();
}
void del()
{
   FILE *tp;
   int i;
   char name[30];
   adminfault:
   switch(choice)
   {
	case 1:
		fp=fopen("cse.txt","rb+");
		break;
	case 2:
		fp=fopen("ece.txt","rb+");
		break;
	case 3:
		fp=fopen("eee.txt","rb+");
		break;
	case 4:
		fp=fopen("mech.txt","rb+");
		break;
	case 5:
		fp=fopen("civil.txt","rb+");
		break;
	}
	tp=fopen("temp.txt","wb+");
	if(fp!=NULL && tp!=NULL)
	{
		printf("Enter the Book name");
		scanf("%s",name);
		while(fread(&b,resize,1,fp)==1)
		{
			if(strcmp(name,b.book_name)!=0)
			   fwrite(&b,resize,1,tp);

			else
			{
				gotoxy(1,1);
				cout<<"BOOK_NAME";
				gotoxy(1,2);
				for(i=1;i<10;i++)
				cout<<"-";
				gotoxy(21,1);
				cout<<"AUTHER_NAME";
				gotoxy(21,2);
				for(i=0;i<=10;i++)
				cout<<"-";
				gotoxy(41,1);
				cout<<"BOOK_ID";
				gotoxy(41,2);
				for(i=4;i<=10;i++)
				cout<<"-";
				gotoxy(61,1);
				cout<<"QUANTITY\n";
				gotoxy(61,2);
				for(i=3;i<=10;i++)
				cout<<"-";
				printf("\n");
				while(fread(&b,resize,1,fp)==1)
				printf("%-20s \b%-20s  %-5d \t\t\b%-3d\n",b.book_name,b.auther_name,b.book_id,b.quantity);
				cout<<"\n\nThis book is deleted";

			}
		}
		 fclose(fp);
		 fclose(tp);
		switch(choice)
		{
		case 1:
			remove("cse.txt");
			rename("temp.txt","cse.txt");
			break;
		case 2:
			remove("ece.txt");
			rename("temp.txt","ece.txt");
			break;
		case 3:
			remove("eee.txt");
			rename("temp.txt","eee.txt");
			break;
		case 4:
			remove("mech.txt");
			rename("temp.txt","mech.txt");
			break;
		case 5:
			remove("civil.txt");
			rename("temp.txt","civil.txt");
			break;
	}



   }
}
void user_login()
{
	user:
	clrscr();
	gotoxy(27,2);
	cout<<"WELCOME USER";
	gotoxy(27,3);
	for(i=0;i<12;i++)
		printf("-");
	fp=fopen("user.txt","rb+");
	rewind(fp);
	gotoxy(20,10);
	cout<<"Enter the NAME :\t";
	cin>>name;
	gotoxy(20,12);
	cout<<"Enter the PASSWORD:\t";
	i=0;
	while((c=getch())!=13)
	{
	    pass[i++]=c;
	    printf("*");
	}
	cout<<"*";
	i=0;
	while(fread(&b,resize,1,fp)==1)
	{
		k=strcmp(b.password,pass);
		l=strcmp(b.user_name,name);
		if(k==0&&l==0)
		{
		i=1;
		break;
		}
	  }
	if(i==1)
	{
		cout<<"\n\n\nsuccess fully LOG IN";
		cout<<"\n\n\npress""\Enter\"to contineu process\t";
		if(getch()==13)
		{
			clrscr();
			selection();
		}
		else
		{
			clrscr();
			selection();
		}
	}
	else
	{
		cout<<"\n\nfailed\n\n\n";
		cout<<"do you want to re enter ..?";
		fflush(stdin);
		c=getch();
		if(c=='y'||c=='Y')
		goto user;
		else
		exit(1);
	}


}
void user_reg()
{
	cout<<"Welocome admin";
	FILE *fp;
	fp=fopen("user.txt","rb+");
	if(fp==NULL)
	fp=fopen("user.txt","wb+");
	cout<<"Enter the NAME :\t";
	cin>>b.user_name;
	cout<<"Enter the PASSWORD:\t";
	while((c=getch())!=13)
	{
	   b.password[i++]=c;
	    printf("*");
	}
	fseek(fp,0,2);
	fwrite(&b,resize,1,fp);
	fclose(fp);
	getch();
}
void admin_login()
{
	admin:
	clrscr();
	gotoxy(27,2);
	cout<<"WELCOME USER";
	gotoxy(27,3);
	for(i=0;i<12;i++)
	printf("-");
	fp=fopen("admin.txt","rb+");
	rewind(fp);
	gotoxy(20,10);
	cout<<"Enter the NAME :\t";
	cin>>name;
	gotoxy(20,12);
	cout<<"Enter the PASSWORD:\t";
	i=0;
	while((c=getch())!=13)
	{
	    pass[i++]=c;
	    printf("*");
	}
	cout<<"*";
	i=0;
	while(fread(&b,resize,1,fp)==1)
	{
		k=strcmp(b.password,pass);
		l=strcmp(b.user_name,name);
		if(k==0&&l==0)
		{
		i=1;
		break;
		}
	  }
	if(i==1)
	{
		cout<<"\n\n\nsuccess fully LOG IN";
		cout<<"\n\n\npress""\Enter\"to contineu process\t";
		if(getch()==13)
		{
			clrscr();
			selection();
		}
		else
		{
			clrscr();
			selection();
		}
	}
	else
	{
		cout<<"\n\nfailed\n\n\n";
		cout<<"do you want to re enter ..?";
		fflush(stdin);
		c=getch();
		if(c=='y'||c=='Y')
		goto admin;
		else
		exit(1);
	}

}
void book_search()
{
	FILE *p;
	char name[50];
	int  k,l,c=0;
	switch(choice)
	{
		case 1:
			fp=fopen("cse.txt","rb+");
			if(fp==NULL)
			fp=fopen("cse.txt","wb+");
			break;
		case 2:
			fp=fopen("ece.txt","rb+");
			if(fp==NULL)
			fp=fopen("ece.txt","wb+");
			break;
		case 3:
			fp=fopen("eee.txt","rb+");
			if(fp==NULL)
			fp=fopen("eee.txt","wb+");
			break;
		case 4:
			fp=fopen("mech.txt","rb+");
			if(fp==NULL)
			fp=fopen("mech.txt","wb+");
			break;
		case 5:
			fp=fopen("civil.txt","rb+");
			if(fp==NULL)
			fp=fopen("civil.txt","wb+");
			break;
	}

	printf("Enter the BOOK NAME or AUTHER NAME:");
	scanf("%s",name);
	strupr(name);
	rewind(fp);
	gotoxy(1,1);
	cout<<"BOOK_NAME";
	gotoxy(1,2);
	for(i=1;i<10;i++)
	cout<<"-";
	gotoxy(21,1);
	cout<<"AUTHER_NAME";
	gotoxy(21,2);
	for(i=0;i<=10;i++)
	cout<<"-";
	gotoxy(41,1);
	cout<<"BOOK_ID";
	gotoxy(41,2);
	for(i=4;i<=10;i++)
	cout<<"-";
	gotoxy(61,1);
	cout<<"QUANTITY\n";
	gotoxy(61,2);
	for(i=3;i<=10;i++)
	cout<<"-";
	printf("\n");
	printf("%-20s \b%-20s  %-5d \t\t\b%-3d\n",b.book_name,b.auther_name,b.book_id,b.quantity);
	fclose(fp);
	while(fread(&b,resize,1,fp)==1)
	       {
		  k=strcmp(name,b.book_name);
		  l=strcmp(name,b.auther_name);
		  if((k==0)||(l==0))
		  {     c++;
			printf("%-20s \b%-20s  %-5d \t\t\b%-3d\n",b.book_name,b.auther_name,b.book_id,b.quantity);
			fclose(fp);

		  }

	      }
	      fclose(p);
	      if(c==0)
	      {
		clrscr();
		cout<<"\n\nIteam not found.....";
	      }
	      if(getch()==13)
		clrscr();
	      else
		clrscr();
	      cout<<"\nDo you want to goto back..?";
	      fflush(stdin);
	      c=getchar();
	      if(c=='y'||c=='Y')
	      selection();
	      else
	      exit(1);
}
void user()
{

}
