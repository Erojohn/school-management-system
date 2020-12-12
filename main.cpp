#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>//for system calls
#include <stdio.h>
#include <cwchar> //for fontsize+fontstyle
#include <sstream>

using namespace std;

class Management{
	private:
		string srCode, stName, yrLvl, cSection, sAddress, conNum;
	public:
		void setSrCode(string a){
			srCode = a;
		}
		void setStName(string b){
			stName = b;
		}
		void setYrLvl(string c){
			yrLvl = c;
		}
		void setCorSection(string d){
			cSection = d;
		}
		void setStAddress(string e){
			sAddress = e;
		}
		void setConNum(string f){
			conNum = f;
		}
		//Getting the values from private variables
		string getSrCode(){
			return srCode;
		}
		string getStName(){
			return stName;
		}
		string getYrLvl(){
			return yrLvl;
		}
		string getCorSection(){
			return cSection;
		}
		string getStAddress(){
			return sAddress;
		}
		string getConNum(){
			return conNum;
		}
		
};

class Teacher{
	private:
		string guroName, guroSubj, guroLoc, guroContact;
	public:
		void setGuroName(string t){
			guroName = t;
		}
		void setGuroSubj(string w){
			guroSubj = w;
		}
		void setGuroLoc(string x){
			guroLoc = x;
		}
		void setGuroContact(string y){
			guroContact = y;
		}
		//Getters
		string getGuroName(){
			return guroName;
		}
		string getGuroSubj(){
			return guroSubj;
		}
		string getGuroLoc(){
			return guroLoc;
		}
		string getGuroContact(){
			return guroContact;
		}
};

void addStudent(int counter);
void addTeacher(int tCounter);
void editStudent(int counter);
void editTeacher(int tCounter);
void searchStudent(int counter);
void searchTeacher(int tCounter);
void quit();

int counter = 0;
int tCounter = 0;
void increment(int j){
	j++;
	counter = j;
}
void decrement(int k){
	k--;
	counter = k;
}
void tIncrement(int j){
	j++;
	tCounter = j;
}
void tDecrement(int k){
	k--;
	tCounter = k;
}

	
Management student[500];
Teacher guro[20];


int main() {
	/* CONSOLE WINDOW COLOUR */
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
	/* FONT SIZE AND FONT STYLE */
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize=sizeof(cfi);
	cfi.nFont=0;
	cfi.dwFontSize.X=0;
	cfi.dwFontSize.Y=20;
	cfi.FontFamily=FF_DONTCARE;
	cfi.FontWeight=FW_NORMAL;
	wcscpy(cfi.FaceName, L"Arial");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	system("CLS");
	string choice;

	system("CLS");
	cout << "SCHOOL MANAGEMENT SYSTEM\n\n";
	cout << "[0]QUIT\n";
	cout << "[1]ADD STUDENT\n";
	cout << "[2]ADD TEACHER\n";
	cout << "[3]EDIT STUDENT\n";
	cout << "[4]EDIT TEACHER\n";
	cout << "[5]VIEW STUDENT\n";
	cout << "[6]VIEW TEACHER\n\n";
	
	cout << "ENTER CHOICE: ";
	cin >> choice;
	
	if(choice == "0"){
		quit();
	}
	else if(choice == "1"){
		addStudent(counter);
	}
	else if(choice == "2"){
		addTeacher(tCounter);
	}
	else if(choice == "3"){
		editStudent(counter);
	}
	else if(choice == "4"){
		editTeacher(tCounter);
	}
	else if(choice == "5"){
		searchStudent(counter);
	}
	else if(choice == "6"){
		searchTeacher(tCounter);
	}
	else{
		main();
	}
	_getch();
	
	return 0;
}

void addStudent(int counter){
	system("CLS");
	string st_Name, myYrLvl, stCorSection, myAddress;
	string myCon;
	string sr_Code;
	cout << "ADD STUDENT\n\n";
	if(counter < 500){
		cin.ignore();
		cout << "Enter SR - Code: ";
		getline(cin, sr_Code);
		cout << "Enter Name: ";
		getline (cin, st_Name);
		cout << "Enter year level: ";
		getline(cin, myYrLvl);
		cout << "Enter course & section: ";
		getline(cin, stCorSection);
		cout << "Enter address: ";
		getline(cin, myAddress);
		cout << "Enter contact #: ";
		getline(cin, myCon);
		
		
		student[counter].setSrCode(sr_Code);
		student[counter].setStName(st_Name);
		student[counter].setYrLvl(myYrLvl);
		student[counter].setCorSection(stCorSection);
		student[counter].setStAddress(myAddress);
		student[counter].setConNum(myCon);
		increment(counter);
		cout << "\nSTUDENT ADDED SUCCESSFULLY!!\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	else{
	
		cout << "YOU HAVE REACH THE MAXIMUM NUMBER OF STUDENTS!!\n\nPress any key to continue. . .";
		_getch();
		main();
	}
}
void addTeacher(int tCounter){
	string tName;
	string tSubj;
	string tLocation;
	string tContact;
	cin.ignore();
	system("CLS");
	cout << "ADD TEACHER\n\n";
	if(tCounter < 500){
		cout << "Enter full name: ";
		getline(cin, tName);
		cout << "Enter subject: ";
		getline(cin, tSubj);
		cout << "Enter address: ";
		getline(cin, tLocation);
		cout << "Enter contact #: ";
		getline(cin, tContact);

		
		guro[tCounter].setGuroName(tName);
		guro[tCounter].setGuroSubj(tSubj);
		guro[tCounter].setGuroLoc(tLocation);
		guro[tCounter].setGuroContact(tContact);
		tIncrement(tCounter);
		cout << "\nTEACHER ADDED SUCCESSFULLY!!\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	else{
		cout << "\nYOU'VE REACH THE MAXIMUM NUMBER OF TEACHER!!	\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	
}


void editStudent(int counter){
	system("CLS");
	cin.ignore();
	string studentCode, choices;
	string sCode, nameStud, yrLvlStud, sCourse, studentLoc, studentNum;
	cout << "\nEDIT STUDENT INFORMATION\n\n";
	if(counter == 0){
		cout << "THERE ARE NO INFORMATION TO EDIT\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	cout << "Enter SR - Code: ";
	getline(cin, studentCode);
	for(int i = 0; i < counter; i++){
		if(student[i].getSrCode() == studentCode){
			cout << "\nSTUDENT INFORMATION FOUND\n\n";
			cout << "SR - Code: " << student[i].getSrCode() << endl;
			cout << "Name: " << student[i].getStName() << endl;
			cout << "Year Level: " << student[i].getYrLvl() << endl;
			cout << "Course & Section: " << student[i].getCorSection() << endl;
			cout << "Address: " << student[i].getStAddress() << endl;
			cout << "Contact #: " << student[i].getConNum() << endl;
			cout << "Do you want to edit the information?\n[1] Yes\n[2] No\n\nEnter choice: ";
			cin >> choices;
			
			if(choices == "1"){
				cout << "Enter SR - Code: ";
				getline (cin, sCode);
				cin.ignore();
				cout << "Enter Name: ";
				getline(cin, nameStud);
				cin.ignore();
				cout << "Enter year level: ";
				getline(cin, yrLvlStud);
				cin.ignore();
				cout << "Enter course and section: ";
				getline(cin, sCourse);
				cin.ignore();
				cout << "Enter address: ";
				getline(cin, studentLoc);
				cin.ignore();
				cout << "Enter contact #: ";
				getline(cin, studentNum);
				cin.ignore();
				
				student[i].setSrCode(sCode);
				student[i].setStName(nameStud);
				student[i].setYrLvl(yrLvlStud);
				student[i].setCorSection(sCourse);
				student[i].setStAddress(studentLoc);
				student[i].setConNum(studentNum);
				cout << "\nINFORMATION EDITED SUCCESSFULLY!!\n\nPress any key top continue. . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout << "\nINFORMATION NOT FOUND!!\n\nPress any key to continue. . .";
	_getch();
	main();
}
void editTeacher(int tCounter){
	system("CLS");
	cin.ignore();
	string tName, picker;
	string gName, gSubj, gLoc, gNum;
	cout << "EDIT TEACHER INFORMATION\n\n";
	if(counter == 0){
		cout << "\n\nTHERE ARE NO INFORMATION TO EDIT!!\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	cout << "Enter the full name of the information you want to edit: ";
	getline(cin, tName);
	for(int l = 0; l < tCounter; l++){
		if(guro[l].getGuroName() == tName){
			cout << "\nTEACHER INFORMATION FOUND!!\n\n";
			cout << "Name: " << guro[l].getGuroName() << endl;
			cout << "Subject: " << guro[l].getGuroSubj() << endl;
			cout << "Address: " << guro[l].getGuroLoc() << endl;
			cout << "Contact #: " << guro[l].getGuroContact() << endl;
			cout << "\n\nDo you want to edit? [1] Yes\n[2] No\n\n";
			cin >> picker;
			
			if(picker == "1"){
			cout << "Enter name: ";
			getline(cin, gName);
			cout << "Enter subject: ";
			getline(cin, gSubj);
			cout << "Enter address: ";
			getline(cin, gLoc);
			cout << "Enter contact #: ";
			getline(cin, gNum);
			
			guro[l].setGuroName(gName);
			guro[l].setGuroSubj(gSubj);
			guro[l].setGuroLoc(gLoc);
			guro[l].setGuroContact(gNum);
			cout << "\nTEACHER INFORMATION EDITED\n\nPress any key to continue. . .";
			_getch();
			main(); 
			}
			else{
				main();
			}
		}
	}
	cout << "\nINFORMATION NOT FOUND!!\n\nPress any key to continue. . .";
	_getch();
	main();
}
void searchStudent(int counter){
	string stSrCode;
	cin.ignore();
	bool print = false;
	system("CLS");
	cout << "VIEW STUDENT\n\n";
	if(counter == 0){
		cout << "\nTHERE ARE NO INFORMATION TO VIEW OR TO BE SEARCH\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	cout << "Enter SR - Code of the student you want to search: ";
	getline(cin, stSrCode);
	for(int m = 0; m < counter; m++){
		if(student[m].getSrCode() == stSrCode){
			cout << "STUDENT INFORMATION FOUND!!\n\n";
			cout << "SR - Code: " << student[m].getSrCode() << endl;
			cout << "Name: " << student[m].getStName() << endl;
			cout << "Year Level: " << student[m].getYrLvl() << endl;
			cout << "Course & Section: " << student[m].getCorSection() << endl;
			cout << "Address: " << student[m].getStAddress() << endl;
			cout << "Contact #: " << student[m].getConNum() << endl;
			print = true;
		}
	}
	if(print){
		cout << "\n\nPress any key rto continue. . .";
		_getch();
		main();
	}
	else{
		cout << "\nTHERE ARE NO INFORMATION!!\n\nPress any key to continue. . .";
		_getch();
		main();
	}
}
void searchTeacher(int tCounter){
	system("CLS");
	cin.ignore();
	string tFullName;
	bool print = false;
	cout << "\nSEARCH TEACHER'S INFORMATION\n\n";
	if(tCounter == 0){
		cout << "THERE ARE NO INFORMATION TO BE SEARCH\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	cout << "Enter the full name that you wabt to search: ";
	getline(cin, tFullName);
	for(int u = 0; u < tCounter; u++){
		if(guro[u].getGuroName() == tFullName){
			cout << "TEACHER IBFORMATION FOUND!!\n\n";
			cout << "Name: " << guro[u].getGuroName() << endl;
			cout << "Subject: " << guro[u].getGuroSubj() << endl;
			cout << "Address: " << guro[u].getGuroLoc() << endl;
			cout << "Contact #: " << guro[u].getGuroContact() << endl;
			print = true;
		}
	}
	if(print){
		cout << "\n\nPress any key to continue. . .";
		_getch();
		main();
	}
	else{
		cout << "\nTHERE ARE NO INFORMATION!!\n\nPress any key to continue. . .";
		_getch();
		main();
	}
}

void quit(){
	
	main();
}






