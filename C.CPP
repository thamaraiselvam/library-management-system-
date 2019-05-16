#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<string.h>
char pass[40];
char name[20];
struct books
{
	char password[40];
	char user_name[20];
}b;
int resize=sizeof(b);
void main()
{
	clrscr();
	int l,k,i=0,c;
	FILE *fp;
	fp=fopen("admin.txt","rb+");
	if(fp==NULL)
	fp=fopen("admin.txt","wb+");
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
	clrscr();
	rewind(fp);
	fp=fopen("admin4.txt","rb+");
	while(fread(&b,resize,1,fp)==1)
	printf("%-20s \b%-20s",b.user_name,b.password);
	fclose(fp);
	getch();
	clrscr();
	fp=fopen("admin.txt","rb+");
	rewind(fp);
	cout<<"log in\n\n";
	cout<<"Enter the NAME :\t";
	cin>>name;
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
	cout<<"success";
	else
	cout<<"failed";





}

