#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


using namespace std;




struct customer
{
	char roll[40];
	char name[40];
	char nationality[40];
	char gender[6];
	char contact[40];
	char email[40];
	char password[40];


}user;
struct employee{
	char name[45];
	char gender[6];
	char contact[40];
	char address[40];
}emp;




void main_menu();

void user_menu();
void login();
void create_account();
void service();
void user_service();
void checkin();
void hotel_info();
void bill();
int get_id(const char *filename);
int checker(const char *filename, int no);

void managermenu();
void add_empinfo();
void acess_empinfo();
void acess_custinfo();

int main()
{
	cout<<"\n************************************************\n";
	cout<<"\n***********MARCEN ADDIS HOTEL ******************\n";
	cout<<"\n************************************************\n";
	cout<<"\n\n";
	system("cls");

		main_menu();

	return(0);
}

void main_menu()
{
	int choice;
labell:
	cout<<"\n************************************************\n";
	cout<<"\n********************MAIN MENU ******************\n";
	cout<<"\n************************************************\n";
	cout<<"\n\n";
	cout<<"\t 1. FOR USER\n";
	cout<<"\t 2. FOR MANAGER\n";
	cout<<"\t 3. EXIT \n";

	cout<<"ENTER YOUR CHOICE: ";
	cin>>choice;
	switch(choice)
	{
		case 1: system("cls");
				user_menu();
				break;
		case 2:
            managermenu();
			break;
		case 3:
			exit(0);
		     break;
		     default: cout<<"\nINVALID CHOICE\n";
		     cout<<"\nPRESS ANY KEY TO CONTINUE\n";
			char key;
			cin>>key;
						system("cls");
		                goto labell;

	}
}

void user_menu()
{
	int userchoice;
    labell:
	cout<<"\n************************************************\n";
	cout<<"\n******************** USER MENU******************\n";
	cout<<"\n************************************************\n";
	cout<<"\n\n";
	cout<<"1. LOGIN\n";
	cout<<"2. CREATE ACCOUNT\n";
	cout<<"3. BACK TO MENU\n\n";

	cout<<"ENTER YOUR CHOICE: ";
	cin>>userchoice;
	switch(userchoice)
	{
		case 1: system("cls");
				login();
				break;
		case 2:system("cls");
			 create_account();
				break;
		case 3:
			   main_menu();
			    break;
	    default: cout<<"\nINVALID CHOICE\n";
	    cout<<"\nPRESS ANY KEY TO CONTINUE\n";
			char key;
			cin>>key;

	             system("cls");
	            goto labell;
	}

}

void login()
{
	fstream file;
	char line[128];
	char *hold;
	int i = 0, j = 0;
	char email[40];
	char password[40];
	char email1[40];
	char passwordl[40];

	cout<<"\n************************************************\n";
	cout<<"\n******************** LOGIN *********************\n";
	cout<<"\n************************************************\n";

	cout<<endl<<endl;
	cout<<"\nENTER YOUR EMAIL: ";
	cin>>email1;
	cout<<"\nENTER YOUR PASSWORD: ";
	cin>>passwordl;


	file.open("user.txt", ios::in | ios::app);
	{
		if (file.is_open()){
			cout<<"\n FILE IS SUCCESSFULLY OPENED\n";
			}
		else cout<<"\n FILE IS UNABLE TO OPEN\n";
	}
	cout<<"\n **********************************\n";
	{
		if (file.is_open())
		{

			while(file)
			{

				i = 0;
				file.getline(line, 128);
				hold = strtok(line, " \t");
				while(hold)
				{
					if (i == 0)
						strcpy(user.roll, hold);
					if (i == 2)
						strcpy(email, hold);
					if (i == 3)
						strcpy(password, hold);
					hold = strtok(NULL, " \t");
					i++;
				}

				if (strcmp(email, email1) == 0)
				{
					if (strcmp(password, passwordl) == 0)
						system("cls");
						j = 1;

				cout<<"\nPRESS ANY KEY TO CONTINUE\n";
					char key;;
					cin>>key;
					user_service();
				}
			}
		}
		if (j == 0)


			cout<<"\nWRONG PASSWORD\n";
			cout<<"\nPRESS ANY KEY TO CONTINUE\n";
			char key;
			cin>>key;
			system("cls");
			main_menu();

	}

}
void create_account()
{
	cout<<"\n*****************************************************************\n";
	cout<<"\t\t\t***   CREATE ACCOUNT  ***************************************\n";
	cout<<"\n*****************************************************************\n\n\n";

	fstream file;
	int x, roll;

	roll = get_id("user.txt");
	file.open("user.txt", ios::out | ios::app | ios::in);
	if (file.is_open())
	{

		cin.ignore();
		cout<<"\nFULL NAME: ";
		cin.getline(user.name, 40);
		cout<<"\nCONTACT: ";
		cin>>user.contact;
		cout<<"\nEMAIL: ";
		cin>>user.email;
		cout<<"\nNEW PASSWORD: ";
		cin>>user.password;
		cout<<"\nNATIONALITY: ";
		cin>>user.nationality;
		cout<<"\nGENDER: ";
		cin>>user.gender;

         cout<<"YOUR ROLL NUMBER Is:"<<roll;

		file<<roll<<"\t"<<user.name<<"\t"<<user.email<<"\t"<<user.password<<"\t"<<user.nationality<<"\t"<<user.gender<<endl;
		cout<<"\n PRESS ANY KEY TO CONTINUE ";
		char key;
		cin>>key;
		system("cls");
		user_service();
		cout<<"\n";

	}
file.close();
}
int get_id(const char *filename)
{
	char str[128];
	char *hold;
	fstream file;
	int pprev = 0;

	file.open(filename, ios::in);
	if (file.is_open())
	{
		while(file.getline(str, 128))
		{
			hold = strtok(str, "\t ");
			if (hold == NULL)
				break;
			pprev = stoi(hold);
		}
		file.close();
	}
	return (pprev + 1);
}


void user_service()
{
	int choice;
	cout<<"\n************************************************\n";
	cout<<"\n******************** USER SERVICE***************\n";
	cout<<"\n************************************************\n";

	cout<<"1. FOR CHECKIN\n";
	cout<<"2. HOTEL INFORMATION \n";
	cout<<"3. CUSTOMER BILL\n";
	cout<<"4. EXIT \n";

	cout<<"\nENTER YOUR CHOICE: ";
	cin>>choice;
	switch(choice)
	{
		case 1: system("cls");
				checkin();
				break;

				break;
		case 2: system("cls");
				hotel_info();
				cout<<"\nPRESS ANY KEY TO CONTINUE\n";
			     char keys;
			      cin>>keys;
                system("cls");
                user_service();
				break;
		case 3: system("cls");
				bill();
				break;

		case 4: system("cls");
				main_menu();
				break;
			default: cout<<"\nINVALID CHOICE\n";
				cout<<"\nPRESS ANY KEY TO CONTINUE\n";
			     char key;
			      cin>>key;

	             system("cls");
	            user_service();
	}
}

void checkin()
{
	int i;
	char id[40];
	cout<<"\n************************************************\n";
	cout<<"\n********************CHECKIN*********************\n";
	cout<<"\n************************************************\n";

	cout<<"\n 1-30 FOR DELUXE ROOM";
	cout<<"\n 31-60 FOR JUNIOR DELUXE ROOM";
	cout<<"\n 61-90 FOR TWIN ROOM ";
	cout<<"\n 91-120 FOR STANDARD ROOM";
	labell:
	cout<<"\n\n ENTER YOUR ROOM CHOICE: ";
	cin>>i;
	fstream file;
	file.open("room.txt", ios::in | ios::out | ios::app);
	{
		if (file.is_open())
		{
			if (checker("room.txt", i) == 0)
			{
				cout<<"\n YOUR ROLL NUMBER IS:"<<user.roll;
				file<<i<<"\t"<<user.roll<<endl;
				cout<<"\n SUCCESSFULLY BOOKED";
				char x;
				cout<<"\n PRESS ANY KEY TO RETURN TO SERVICE MENU: ";
				cin>>x;
				system("clear");
				user_service();
			}
			else
			{
				cout<<"\n ROOM IS ALREADY BOOKED;\n";
				goto labell;
			}
			file.close();
		}
	}
}



int checker(const char *filename, int no)
{
	char *hold;
	char line[128];
	fstream file;
	int num;
	file.open(filename, ios::in);
	{
		if (file.is_open())
		{
			while(file)
			{
				file.getline(line, 128);
				hold = strtok(line, "\t");
				if (hold == NULL)
					break;
				num = stoi(hold);
				if (num == no)
				{
					return (1);
				}
			}
		}
	}
	return (0);
}



void hotel_info()
{
	cout<<"\n************************************\n";
	cout<<"\n**MARCEN ADDIS INTERNATIONAL HOTEL**\n";
	cout<<"\n************************************\n ";
	cout<<"\n TYPES OF ROOM\n";
	cout<<"\n  DELUXE ROOM\n";
	cout<<"\n  JUNIOR DELUXE ROOM\n";
	cout<<"\n  TWIN ROOM\n";
	cout<<"\n  STANDARD ROOM\n";
	cout<<"\n PHONE NUMBER:+251-635-41-01\n";
	cout<<"\n ADDRESS: MICKEY LELAND St.ADDIS ABABA, ETHIOPIA \n";
		cout<<"\nPRESS ANY KEY TO RETURN TO SERVICE MENU: ";
				char x;
				cin>>x;
				system("cls");
				user_service();

}




void bill(){

int roomnumber;
cout<<"\n ENTER YOUR ROOM NUMBER";
cin>>roomnumber;
if(roomnumber>=1&&roomnumber<=30){
	cout<<"\n  SERVICE CHARGE=4700 BIRR \n";
}

    else if (roomnumber>=31&&roomnumber<=60){
		cout<<"\n SERVICE CHARGE=3700 BIRR\n";
	}
	else if( roomnumber>=61&&roomnumber<=90){
		cout<<"\n SERVICE CHARGE=2700 BIRR\n";
	}
	else if (roomnumber>=91&&roomnumber<=120){
		cout<<"\n  SERVICE CHARGE=1700 BIRR\n";
	}
	else {
		cout<<"\n INVALID CHOICE\n";
		cout<<"\nPRESS ANY KEY TO CONTINUE\n";
			     char key;
			      cin>>key;

	             system("cls");
	             void bill();

	}






}


void managermenu(){
cout<<"WELCOME TO MANAGER MENU"<<endl;
cout<<"ENTER PASSWORD"<<endl;

int x;
cin>>x;
if(x==8765){
		int managerchoice;
		here:
	cout<<"\n 1.TO ADD EMPLOYEE INFORMATION\n"<<endl;
	cout<<"\n 2.TO ACCESS EMPLOYEE INFORMATION \n"<<endl;
	cout<<"\n 3.TO ACCESS CUSTOMER INFORMATION\n"<<endl;
	cout<<"\n 4.EXIT"<<endl;

	 cin>>managerchoice;


    switch(managerchoice){
	case 1:system("cls");
		add_empinfo();
		break;
	case 2:system("cls");
		acess_empinfo();
		break;
	case 3:system("cls");
		acess_custinfo();
		break;
	case 4:
		 main_menu();
		break;
		default: cout<<"\nINVALID CHOICE\n";
				cout<<"\nPRESS ANY KEY TO CONTINUE\n";
			     char key;
			      cin>>key;

	             system("cls");
	            goto here;


}





}


else {
	cout<<"WRONG PASSWORD"<<endl;
	cout<<"PLEASE ENTER YOUR PASSWORD AGAIN"<<endl;
	system("cls");
	managermenu;
}


}

void add_empinfo(){
	fstream file;

	file.open("employee.txt", ios::out| ios::app);{
if(file.is_open()){
    cout<<"\nSUCCESSFULLY OPENED";
    }
    else
        cout<<"\n UNABLE TO OPEN";




cout<<"\n ENTER EMPLOYEE NAME";
cin>>emp.name;
cout<<"\n ENTER EMPLOYEE GENDER";
cin>>emp.gender;
cout<<"\n ENTER CONTACT";
cin>>emp.contact;
cout<<"\n ENTER ADDRESS";
cin>>emp.address;


    file<<"\n"<<"\t"<<emp.name<<"\t"<<emp.gender<<"\t"<<emp.contact<<"\t"<<emp.address<<"\n";

}
file.close();

}









void acess_empinfo(){
	fstream file;
    file.open("employee.txt", ios::in);{
if(file.is_open()){
    cout<<"\n SUCCESSFULLY OPENED";
     cout<<"\n***MARCEN ADDIS INTERNATIONAL HOTEL***\n";
         cout<<"\n THIS IS LIST OF EMPLOYEE INFORMATION\n\n\n";
         cout<<"NAME"<<"\t"<<"GENDER"<<"\t"<<"CONTACT"<<"\t"<<"ADDRESS"<<endl;
         while(!file.eof()){
			file>>emp.name>>emp.gender>>emp.contact>>emp.address;
			cout<<emp.name<<"\t"<<emp.gender<<"\t"<<emp.contact<<"\t"<<emp.address<<endl;

         }

    }
    else
        cout<<"\n UNABLE TO OPEN";


}
file.close();

}


void acess_custinfo(){
	fstream file;
	file.open("user.txt",ios::in);
		if(file.is_open()){
    cout<<"\n SUCCESSFULLY OPENED";
    cout<<"\n***MARCEN ADDIS INTERNATIONAL HOTEL***\n";
       //cout<<"\n THIS IS LIST OF CUSTOMER INFORMATION\n";
        cout<<"NAME"<<"\t"<<""<<"CONTACT"<<"\t"<<"EMAIL"<<"\t"<<"PASSWORD"<<"\t"<<"NATIONALITY"<<"\t"<<"GENDER"<<"\t"<<endl;
         while(!file.eof()){
				file>>user.name>>user.contact>>user.email>>user.password>>user.nationality>>user.gender;
				cout<<user.name<<"\t"<<user.contact<<"\t"<<user.email<<"t"<<user.password<<"\t"<<user.nationality<<"\t"<<user.gender<<"\t"<<endl;




	       }
    }

    else
        cout<<"\n UNABLE TO OPEN";




	   file.close();

}








