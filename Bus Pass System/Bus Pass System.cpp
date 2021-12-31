//
//  Bus Pass System
//
//  Created by 137220 - Amani Shaka Chege
//
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

static int x=1;
#define pos gotoxy(33,x++) /*for cursor movement*/
#define ln  printf(".......................");

//Section for Cursor Movements

COORD coord={0,0};
 void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//function for delaying time for certain action aka goal
void dt(unsigned int mseconds)
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}

//function to change color
void changecolor(int ForgC) 
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }

//Initial Variables and Voids needed for this program:

int st = 0;
char name[5000];
char route[5000];
char dedate[5000];
char redate[5000];
char reason[5000];

//Voids for the program actions

void bookbus();
void inbus(int id);
void outbus(int id);
void admin();
void user();
void getbus(int id);
void viewbusa();
void viewbusu();  
void viewbookingsa();
void viewbookingsu(); 
void addbus();
void removebus();

//Other Voids

void aboutsection();
void helpsection();

void splashscreen()
{
	system("cls");
	char t;
	//Print Welcome Message
	changecolor(37);
	printf("\t\t\t\t\t Welcome To The Bus Booking System");
	printf("\n\n \t\t\t\t\t Created by (137220) Amani Shaka Chege \n");
	
	//Ask for input if user wishes to skip the waiting screen
	printf("\n\n\t\t\t\t\t Type C To Continue...");
	changecolor(35);
	cin>>t;
	//If t is C	
    if (t == 'C'){
    system("cls");
    //Return to int main() from the splashscreen void.
	return;
	}else{
		cout<<"Wrong key pressed, kindly try again!!!";
		exit(1);
	}
	//Delay for 20 seconds = 20,000 miliseconds then clear screen and return to int main().
	dt(20000);
	system("cls");
	
	return;
}

//Main function starts here:

int main()
{   
int ch;    
	    if(st==0)
       {    
	   splashscreen(); 
}
	int choice, pass;
	string name;
    
    x=1;
    system("cls");
    
    changecolor(37) ;
    printf("\t\t\t\t - Welcome To Bus Booking System - ");
    pos;
    pos;
    ln pos;
	printf(" Enter Name - ");
	changecolor(35);
	    cin>>name;
	changecolor(37);
	printf("\t\t\t\t Enter Passcode - ");
	changecolor(35);
	    cin>>pass;
	    
	if(name == "Amani" && pass == 137220){
	
	admin();
	
    }else if(name == "User01" && pass == 123456){
		
		user();
		
}
else{
	
	cout<<"\n\n Login Details are incorrect, kindly try again with proper credentials!!!"<<endl;
	exit(1);
}
}

//Administrator Main Menu

void admin(){
	
		int choice;
		system("cls");
    changecolor(37);
    pos;
     	
        printf("--- Administrator Menu ---");pos;
        ln
        pos;
        printf("1 - View Bus");
        pos;
        printf("2 - Add Bus");
        pos;
        printf("3 - Remove Bus");
        pos;
		printf("4 - View Bookings");
        pos;
        printf("5 - Logout");
        pos;
        printf("Kindly Select An Option [1,2,3,4,5] --- ");
        changecolor(35) ;
        cin>>choice;
        pos;
        //Using a Switch Case the void fhunctions are selected from user input.
        switch(choice)
        {       
            case 1:viewbusa();
			break;
            case 2:addbus();
			break;
            case 3:removebus();
			break;
			case 4:viewbookingsa();
			break;
			case 5: main();
			break;
            default:main();
            break;
        }
	
}

//User Main Menu

void user(){
	int choice;
	system("cls");

    pos;
     changecolor(37);
     	
        printf("--- Main Menu ---");pos;
        ln;
        pos;
        printf("1 - Book Bus");
        pos;
        printf("2 - View Bus");
        pos;
        printf("3 - View Bookings");
        pos;
        printf("4 - Help");
        pos;
		printf("5 - About");
        pos;
        printf("6 - Logout");
        pos;
        printf("Kindly Select An Option [1,2,3,4,5,6] --- ");
        changecolor(35) ;
        cin>>choice;
        pos;
        //Using a Switch Case the void fhunctions are selected from user input.
        switch(choice)
        {       
			case 1:bookbus();
			break;
            case 2:viewbusu();
			break;
            case 3:viewbookingsu();
			break;
            case 4:helpsection();
			break;
			case 5:aboutsection();
			break;
			case 6:main();
			break;
            default:main();
            break;
        }
	
}

//Book Bus Section 

void bookbus()
{ 
   dt(180);
   system("cls");
   //Variables
   int choice, id, uid;			 

  //Input Booking Details
    changecolor(37);
  	printf("\t\t\t\t --- Book Bus ---\n");
    cout << "\t  Enter Booking ID (any integer from 1 to infinity) : \n";
    changecolor(35);
	cin >> id;
	cout <<"\n\n"; 
  	changecolor(37);
    cout << " \t  Enter Bus Name (select one from the 'View Bus' Section) : \n";
    changecolor(35);
	cin >> name;
	cout <<"\n\n";
	changecolor(37);
    cout << " \t  Enter Bus Route (select the corresponding one for the bus from the 'View Bus' Section) : \n";
    changecolor(35);
	cin >> route;
	cout <<"\n\n";
	changecolor(37);
    cout << " \t  Enter Depature Date (ensure the date is in the future, in dd/MM/YYYY format with time alongside) : \n";
    changecolor(35);
	cin >> dedate;
	cout <<"\n\n"; 
	changecolor(37);
    cout << " \t  Enter Return Date (ensure the date is in the future, in dd/MM/YYYY format with time alongside) : \n";
    changecolor(35);
	cin >> redate;
	cout <<"\n\n";
	changecolor(37);
    cout << " \t  Enter User ID to complete process : \n";
    changecolor(35);
	cin >> uid;
	cout <<"\n\n";  
if(uid == 123456){
  	system("cls");
  	changecolor(37);
			printf("\t\t\t\t Thank you for Booking with us!");
			pos;
			
		//Saves the inputted booking data to a reciept text type file
		
		getbus(id);
		++x;
		pos;
		printf(" 1 - Book Again - ");
		pos;
		printf(" 2 - Main menu - ");pos;
		printf(" 3 - Exit - "); pos;
		printf(" Enter your choice --- ");
		changecolor(35) ;
		cin >> choice;
		switch(choice)
		{
		      case 1:bookbus();
			  break;
		      case 2:user();
			  break;
		      case 3:exit(1);
		      break;
			  default:main();
		}
	}
	else{
		cout<<"Kindly try again, ensure the User ID inputted is correct!!!";
	} 
  }	
  
//Add Bus Section   
void addbus(){
	
	dt(180);
	system("cls");
	
	//Variables
	int choice, id, aid;			 
   
   //Input Bus Details
    changecolor(37);
  	printf("\t --- Add Bus ---\n\n");

    cout << "\t  Enter Bus ID (any integer from 1 to infinity) : \n";
    changecolor(35);
	cin >> id;
	cout <<"\n\n"; 
	changecolor(37);
    cout << "\t  Enter Bus Name (Do not space the name or split it) : \n";
    changecolor(35);
	cin >> name;
	cout <<"\n\n";
	changecolor(37);
    cout << "\t  Enter Bus Route (Do not space the route or split it) : \n";
    changecolor(35);
	cin >> route;
	cout <<"\n\n";
	changecolor(37);
    cout << " \t  Enter Administrator ID : \n";
    changecolor(35);
	cin >> aid;
	cout <<"\n\n";
	if(aid == 137220){
  	system("cls");
  	changecolor(40);
			printf("\t\t\t\t Bus successfully added!");
			pos;
			
		//Saves the inputted bus data to a bus list text type file
		
		inbus(id);
		++x;
		pos;
		printf(" 1 - Add Another Bus - ");
		pos;
		printf(" 2 - Administrator Menu - ");pos;
		printf(" 3 - Exit - "); pos;
		printf(" Enter your choice --- ");
		cin >> choice;
		switch(choice)
		{
		      case 1:addbus();
			  break;
		      case 2:admin();
			  break;
		      case 3:exit(1);
		      break;
			  default:main();
		}
	}
	else{
		cout<<"Kindly try again, ensure the User ID inputted is correct!!!";
	}    
}

//Remove Bus Section
void removebus(){
	
	dt(180);
	system("cls");
	
	//Variables
	int choice, id, aid;			 

   //Input Bus Details
    changecolor(41);
  	printf("\t\t\t\t --- Remove Bus ---\n\n");
  	changecolor(41);
    cout << " \t  Enter Bus ID (ensure it corresponds to the correct bus from bus list) : \n";
    changecolor(40);
	cin >> id;
	cout <<"\n\n"; 
	changecolor(41);
    cout << " \t  Enter Reason for Removing Bus : \n";
    changecolor(40);
	cin >> reason;
	cout <<"\n\n";
	changecolor(41);
    cout << " \t  Enter Administrator ID : \n";
    changecolor(40);
	cin >> aid;
	cout <<"\n\n";
	if(aid == 137220){
  	system("cls");
  	changecolor(41);
			printf("\t\t\t\t Bus successfully removed!");
			pos;
			
		//Saves the inputted bus data to a busremoved list text type file
		
		outbus(id);
		++x;
		pos;
		printf(" 1 - Remove Another Bus - ");
		pos;
		printf(" 2 - Administrator Menu - ");
		pos;
		printf(" 3 - Exit - "); 
		pos;
		printf(" Enter your choice --- ");
		changecolor(40);
		cin >> choice;
		switch(choice)
		{
		      case 1:removebus();
			  break;
		      case 2:admin();
			  break;
		      case 3:exit(1);
		      break;
			  default:main();
		}
	}
	else{
		cout<<"Kindly try again, ensure the Administrator ID inputted is correct!!!";
	}    
}

void viewbusu(){
	system("cls");
	int choice, ch;
	changecolor(41);
  	printf("\t\t\t\t --- View Bus ---\n");
	
	printf("\t\t\t\t -Buses in Use \n\n");
	
	FILE *fp;

        fp=fopen("buslist.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {    printf("%c",ch);
    }
    cout<<"\n\n";
    printf("\t\t\t\t -Buses Not in Use \n\n");
	pos;
        fp=fopen("busremoved.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {    printf("%c",ch);
    }
	cout<<"\n\n";
		printf(" 1 - Main Menu - ");
		pos;
		printf(" 2 - Exit - "); 
		pos;
		printf(" Enter your choice --- ");
		changecolor(40);
		cin >> choice;
		switch(choice)
		{
		      case 1:user();
			  break;
		      case 2:exit(1);
		      break;
			  default:main();
		}
}

void viewbusa(){
	system("cls");
	int choice, ch;
	changecolor(41);
  	printf("\t\t\t\t --- View Bus ---\n\n");
	
	printf("\t\t\t\t -Buses in Use \n\n");
	
    FILE *fp;
        fp=fopen("buslist.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {    printf("%c",ch);
    }
    cout<<"\n\n";
    printf("\t\t\t\t -Buses Not in use \n\n");
	
        fp=fopen("busremoved.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {    printf("%c",ch);
    }
	cout<<endl;
		printf("\t\t\t\t1 - Administrator Menu - \n");
		pos;
		printf(" 2 - Exit - "); 
		pos;
		printf(" Enter your choice --- ");
		changecolor(40);
		cin >> choice;
		switch(choice)
		{
		      case 1:admin();
			  break;
		      case 2:exit(1);
		      break;
			  default:main();
		}
}

void viewbookingsu(){
	system("cls");
	int choice, ch;
	changecolor(41);
  	printf("\t\t\t\t --- View Bookings ---\n");
	
	FILE *fp;
        fp=fopen("bookinglist.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {    printf("%c",ch);
    }
    	cout<<"\n\n";
    	pos;
		printf(" 1 - Main Menu - ");
		pos;
		printf(" 2 - Exit - "); 
		pos;
		printf(" Enter your choice --- ");
		changecolor(40);
		cin >> choice;
		switch(choice)
		{
		      case 1:user();
			  break;
		      case 2:exit(0);
		      break;
			  default:main();
		}
}

void viewbookingsa(){
	system("cls");
	int choice, ch;
	changecolor(41);
  	printf("\t\t\t\t --- View Bookings ---\n");
	
	FILE *fp;
        fp=fopen("bookinglist.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {    printf("%c",ch);
    }
    cout<<"\n\n";
    pos;
		printf(" 1 - Main Menu - ");
		pos;
		printf(" 2 - Exit - "); 
		pos;
		printf(" Enter your choice --- ");
		changecolor(40);
		cin >> choice;
		switch(choice)
		{
		      case 1:admin();
			  break;
		      case 2:exit(0);
		      break;
			  default:main();
		}
}


//Help Section
void helpsection()
{
    system("cls");
    //rectangle(0,0,70,15);
    gotoxy(7,5);
    changecolor(41);
    char cont;

   printf("\t\t\t\t\t - Welcome To the Bus Booking System -");
    printf("\n\n \t\t\t\t\t--- To Book A Bus ---");
    printf("\n -Select 1 on Main Menu and fill fields appropriately; ensure the bus chosen is in use.");
    printf("\n\n \t\t\t\t\t--- To View Buses ---");
    printf("\n -Select 2 on Main Menu and there will be a list of both buses that are in use and not in use at the moment.");
    printf("\n\n \t\t\t\t\t--- To View Bookings ---");
    printf("\n -Select 3 on Main Menu and view the bookings outputted, do not account for bookings which the current date has passed.");
	printf("\n\n\t\t\t\t\t Type B To Continue...");
       changecolor(40);
       cin >> cont;
	   if(cont == 'B'){
	   	 user();
	   }else{
	   	cout<<"Kindly input proper key 'B'.";
	   }
}

//About Section
void aboutsection()
{       system("cls");

    char cont;
    changecolor(41);
    printf("- The Bus Pass System is able to run any Windows Computer. \n\n- This system has been done in C++ using OOAD.\n\n-This system is very useful as it enables users to save time and make the bus ticket process much easier and more efficient.\n\n- Created by (137220) Amani Shaka Chege, thank you for your time.");
       printf("\n\n\t\t\t\t\t Type B To Continue...");
       changecolor(40);
       cin >> cont;
	   if(cont == 'B'){
	   	 user();
	   }else{
	   	cout<<"Kindly input proper key 'B'.";
	   }
}

//Get or Book Bus Section
void getbus(int id)
{
    FILE *fp;
    fp=fopen("bookinglist.txt","a");
    pos;
    if(fp==NULL)
    printf("Error in opening file, ensure file exists in same directory.");
    fprintf(fp,"\nid:%d   name:%s  route:%s   dedate:%s   redate:%s",id, name, route, dedate, redate);
    fclose(fp);
    pos;
    printf("Booking List Updated");
}

void inbus(int id)
{
    FILE *fp;
    fp=fopen("buslist.txt","a");
    pos;
    if(fp==NULL)
    printf("Error in opening file, ensure file exists in same directory.");
    fprintf(fp,"\nid:%d   name:%s  route:%s",id, name, route);
    fclose(fp);
    pos;
    printf("Bus List Updated.");
}

void outbus(int id)
{
    FILE *fp;
    fp=fopen("busremoved.txt","a");
    pos;
    if(fp==NULL)
    printf("Error in opening file, ensure file exists in same directory.");
    fprintf(fp,"\nid:%d   reason:%s",id, reason);
    fclose(fp);
    pos;
    printf("Buses not in use List Updated");
}

//  Created by 137220 - Amani Shaka Chege
