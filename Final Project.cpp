/* Hello! I am Md Nashir Kazi, a student Department of Software Engineering at Daffodil International University.
This is my final project!
“DIU Employees Management System” 
It will help to manage the information of workers working in Daffodil International University.
We can insert, Edite,and delete employees information.*/

//ID:221-35-938

#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> //for windows related functions 
#include <string.h>  

COORD coord = {0,0}; 


void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
	int i;
	char admin_user[20],admin_password[20];
	for(i=1;i<=1;i++)
	{
		system("cls");
		gotoxy(30,6);printf("--------------------------------------------------");
		gotoxy(34,10);printf("WECLOME TO DIU EMPLOYEE MANAGEMENT SYSTEM");
		gotoxy(30,14);printf("-------------------------------------------------");
		fflush(stdin);
		gotoxy(30,18);printf("Enter User Name:");
		gets(admin_user);
		gotoxy(30,20);printf("Enter Password: ");
		gets(admin_password);
	
		if(strcmp(admin_user,"kazi35")!=0 || strcmp(admin_password,"nasir938")!=0){
			gotoxy(30,24);printf("Wrong User Name or Password\n");
			getch();
			i--;
		}
	}
	
    FILE *fp, *ft; 
    char another, choice;

    /** structure that represent a employee */
    struct emp
    {
        int id;//DIU id of employee
		char name[100]; ///name of employee
	    char fname[100];//father's name of employee
		char mname[100];//mother's name of employee
        int age; /// age of employee
        char bg[10];//Blood group of employee
        float bs; /// basic salary of employee
        char mail[100];//employee mail address
        
    };

    struct emp e; /// structure variable creation

    char empname[40]; /// string to store name of the employee

    long int recsize; /// size of each record of employee

    /* open the file in binary read and write mode*/
    
    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    
	 recsize = sizeof(e);

   
    while(1)
    {
        system("cls"); //clear the console window
        gotoxy(30,10); 
        printf("1. Add Record"); 
        gotoxy(30,12);
        printf("2. List Records"); 
        gotoxy(30,14);
        printf("3. Modify Records"); 
        gotoxy(30,16);
        printf("4. Delete Records"); 
        gotoxy(30,18);
        printf("5. Exit"); 
        gotoxy(30,20);
        printf("Your Choice: "); // enter the choice 1, 2, 3, 4, 5
        fflush(stdin); //flush the input buffer
        choice  = getche(); // get the input from keyboard
        switch(choice)
        {
        case '1':  
            system("cls");
            fseek(fp,0,SEEK_END); 
            

            another = 'y';
            while(another == 'y')  
            {
                printf("\nEnter DIU Employee ID: ");
            	scanf("%d",&e.id);
            	fflush(stdin);
                printf("\nEnter name: ");
                gets(e.name);
                printf("\nEnter Father's Name: ");
                gets(e.fname);
                printf("\nEnter Mother's Name: ");
                gets(e.mname);
                printf("\nEnter Age: ");
                scanf("%d", &e.age);
                fflush(stdin);
                printf("\nEnter Blood Groupe: ");
                gets(e.bg);
                printf("\nEnter Basic Salary: ");
                scanf("%f", &e.bs);
                printf("\nEnter Email Address: ");
                fflush(stdin);
                gets(e.mail);

                fwrite(&e,recsize,1,fp); /// write the record in the file

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");

            rewind(fp); 
            while(fread(&e,recsize,1,fp)==1)  
            {
            	printf("DIU Employee ID: %d\n",e.id);//print employee information
				printf("Name: %s\n",e.name);
				printf("Father's Name: %s\n",e.fname);
				printf("Mother's Name: %s\n",e.mname);
            	printf("Age: %d\n",e.age);
            	printf("Blood Group: %s\n",e.bg);
                printf("Salary: %.2f\n",e.bs); 
                printf("Mail Address: %s\n\n\n",e.mail);
			}
            getch();
            break;

        case '3': 
            system("cls");
            another = 'y';
            while(another == 'y')
            {
            	fflush(stdin);
                printf("Enter the employee name to modify: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1)  
                {
                    if(strcmp(e.name,empname) == 0)  
                    {
                printf("\nEnter DIU Employee ID: ");
            	scanf("%d",&e.id);
            	fflush(stdin);
                printf("\nEnter name: ");
                gets(e.name);
                printf("\nEnter Father's Name: ");
                gets(e.fname);
                printf("\nEnter Mother's Name: ");
                gets(e.mname);
                printf("\nEnter Age: ");
                scanf("%d", &e.age);
                fflush(stdin);
                printf("\nEnter Blood Groupe: ");
                gets(e.bg);
                printf("\nEnter Basic Salary: ");
                scanf("%f", &e.bs);
                printf("\nEnter Email Address: ");
                fflush(stdin);
                gets(e.mail);
                fseek(fp,-recsize,SEEK_CUR); 
                fwrite(&e,recsize,1,fp); 
                    break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
            	fflush(stdin);
                printf("\nEnter name of employee to delete: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb"); 
                rewind(fp); 
                while(fread(&e,recsize,1,fp) == 1)  
                {
                    if(strcmp(e.name,empname) != 0)  
                    {
                        fwrite(&e,recsize,1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT"); 
                rename("Temp.dat","EMP.DAT"); 
                fp = fopen("EMP.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);  
            exit(0); 
        }
    }
    return 0;
}
