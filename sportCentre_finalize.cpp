#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<sstream>
#include<string>
using namespace std;
int forgot=0;
// all purchasement counter open
int allTrainer=0, allCourt=0, allEquipment=0;
int trainerCounter=0, courtCounter=0, equipmentCounter=0;
int purchaseCounter=0;
// all purchasement counter close

// initialization account login/menu interface open
void signUp(int count);
void saveFile(int studentCounter);
int loadFile();
void logIn(int count);
void menu();
void logOut();
// initialization account login/menu interface close

// initialization kemal open
int courtRow[6];
void courtReservation();
int file();
double duit(double total);
double Total=0;
// initialization kemal close

// initialization apikkk open
int equipmentRow[12];
int unitcounter (int price);
void RentTotal (int total);
int readFile();
void errorrental();
void equipmentReservation();
// initialization apikkk close

// initialization taqin open
void calculateAllReceipt();
int row[6];
void trainer();
void getTrainerData(struct trainerDetails listTrainer[][6], ifstream &getFile);
void displayTrainer();
void chooseTrainer(int &sports, int &coach);
void trainerFee(double salary);
void printReceipt();
// initialization taqin close

// struct kemal open
struct courtReceipt{
	string selectedCourt;
	double selectedHours;
}courtReceiptDetails[100];
struct court{
	string sukan;
	int price;
}sport[6];
// struct kemal close

// struct apikkk open 
struct equipmentReceipt{
	string selectedEquipment;
	int numUnit;
}equipmentReceiptDetails[100];
struct equipment{
	string name;
	int rental;
}eqp[12];
// struct apikkk close

// struct taqin open
struct invoice{
	double totalAll;
};
struct calcPayment{
	invoice receipt;
	double totalTrainer, totalEquipment, totalCourt;
}calcFee[100], calcAll;
struct trainerReceipt{
	string selectedTrainer;
	double selectedHours;
}trainerReceiptDetails[100];
struct trainerDetails{
	int trainerWage;
	string trainerName;
}trainers[6][6];
// struct taqin close

// account login/menu interface open
struct presentStudent{
	string *currentFname, *currentLname;
	int currentID;
	char currentKeyword[100];
}currentStudent;
struct scholarDetails{
	char Fname[100], Lname[100];
	int scholarID;
	char keyword[100];
}scholar[100];
struct primaryKey{
	char firstName[100], lastName[100];
	int studentID;
	char password[100];
}student[100];
int main(){	
	system("cls");
	ifstream checkFile;
	int studentCounter=0;	
	checkFile.open("password1.txt");
if(checkFile.is_open()){
	studentCounter=loadFile();	
}
	checkFile.close();
//	cout << studentCounter << endl; //to check the total student is correct or not
	int option;
	cout << "///////////////////////////////////" << endl;	
	cout << "//UiTM Perlis Online Sport Centre//" << endl;
	cout << "///////////////////////////////////" << endl;
	cout << "1. Sign up for new account\n2. Log in to existing account" << endl;
	cout << "Your option: ";
	cin >> option;
	do{
	switch(option){
		case 1:
			system("cls");
			signUp(studentCounter);
			break;
		case 2:
			logIn(studentCounter);
			break;
		default: 
			cout << "Invalid input! Please re-enter..." << endl;
			cout << "Your option: ";
			cin >> option;	
	}
}while(option<1 || option>2);
	
	return 0;	
}
void signUp(int count){	
	cin.ignore();	
	cout << "Enter your first name: ";
	cin.getline(student[count].firstName, 100);
	cout << "Enter your last name: ";
	cin.getline(student[count].lastName, 100);
	cout << "Enter your student ID: ";
	cin >> student[count].studentID;
	cin.ignore();	
	cout << "Enter your password (MUST EXCLUDE SPACE!): ";		
	cin.getline(student[count].password, 100);

	int accountCheck=0;	
	for(int i=0; i<count; i++){
		if(student[count].studentID==scholar[i].scholarID){
			cout << "This student ID already has an account! Please login...";
			++accountCheck;
			i=count;
			Sleep(3500);
			main();
		}
	}
	ifstream loadData1;
	loadData1.open("password1.txt");
	if(loadData1.is_open()){
		int i=0;
		while(!loadData1.eof()){
			loadData1 >> student[i].studentID;
			loadData1.getline(student[i].firstName, 100);	
			++i;
		}
	}
	loadData1.close();
	ifstream loadData2;
	loadData2.open("password2.txt");
	if(loadData2.is_open()){
		int i=0;
		while(!loadData2.eof()){
			loadData2.getline(student[i].lastName, 100, ',');
			loadData2.getline(student[i].password, 100);
			++i;			
		}
	}
	loadData2.close();
if(accountCheck==0){
	++count;
	saveFile(count);	
}	
} 
void saveFile(int studentCounter){ //save data to text file
	ofstream saveData1, saveData2;
	int endLine1=1, endLine2=1;
	saveData1.open("password1.txt");
	if(!saveData1.is_open()){
		cerr << "Unabled to open the file :(";
	}
for(int j=0; j<studentCounter; j++){	
	saveData1 << student[j].studentID << student[j].firstName;
	if(endLine1<studentCounter)
		saveData1 << endl;
	endLine1++;
}
	saveData1.close();
	saveData2.open("password2.txt");
	if(!saveData2.is_open()){
		cerr << "Unabled to open the file :(";
	}	
for(int i=0; i<studentCounter; i++){
	saveData2 << student[i].lastName << "," << student[i].password;
	if(endLine2<studentCounter)
		saveData2 << endl;
	endLine2++;
}
	saveData2.close();
	cout << "Sign up completed! Please login...";
	Sleep(3500);
	main();
} 
int loadFile(){ //load data from text file
	ifstream loadData1, loadData2;
	int i=0, j=0;
	loadData1.open("password1.txt");
	if(!loadData1.is_open()){
		cerr << "Unabled to open the file :(";
	}
while(!loadData1.eof()){
	loadData1 >> scholar[i].scholarID;
	loadData1.getline(scholar[i].Fname, 100);	
	++i;
}
	loadData1.close();	
	loadData2.open("password2.txt");
	if(!loadData2.is_open()){
		cerr << "Unabled to open the file :(";
	}		
while(!loadData2.eof()){
	loadData2.getline(scholar[j].Lname, 100, ',');
	loadData2.getline(scholar[j].keyword, 100);
	++j;
}
/* for(int i=0; i<j; i++){ //to check whether the read data is successfully running or not
	cout << scholar[i].scholarID << "," << scholar[i].Fname
		 << ",";
	cout << scholar[i].Lname << "," << scholar[i].keyword	
	     << endl;
}*/
	loadData2.close();	
	return j;
}
void logIn(int count){
	system("cls");
	cout << "Enter your student ID: ";
	cin >> currentStudent.currentID;
	cin.ignore();	
	cout << "Enter your password (MUST EXCLUDE SPACE!): ";	
	cin.getline(currentStudent.currentKeyword, 100);	
	
	int j=0, current, invalid=0;
	while(j<count){ //search student id(if not available then cout invalid command)
		if(currentStudent.currentID==scholar[j].scholarID){
			current=j;
			j=count;
		}
		else if(currentStudent.currentID!=scholar[j].scholarID){
			++j;
			if(j==count){
				invalid++;
			}
		}	
	}
	string compare=scholar[current].keyword;
	if(currentStudent.currentKeyword!=compare){
		invalid++;
	}
	string firstName=scholar[current].Fname, lastName=scholar[current].Lname;	
	switch(invalid){
		case 0:
			currentStudent.currentFname=&firstName;
			currentStudent.currentLname=&lastName;
			cout << "Login successfully!";
			Sleep(3500);
			menu();
			break;
		case 1:
		case 2:
			cout << "Incorrect student ID or password! Please login again...";
			Sleep(3500);
			main();
			break;
	}
}
void menu(){
	system("cls");
//	cout << "Forgot: " << forgot << endl;
	cout << "Welcome student, " << *currentStudent.currentFname << "!" << " To" << endl;
	cout << "///////////////////////////////////" << endl;	
	cout << "//UiTM Perlis Online Sport Centre//" << endl;
	cout << "///////////////////////////////////" << endl;	
	cout << "\nMain Menu >> " << endl;
	cout << "1.Court Reservation" << endl;
	cout << "2.Sport Equipments" << endl;
	cout << "3.Trainer Reservation" << endl;
	cout << "4.Print Receipt" << endl;
	cout << "5.Log Out" << endl;
	cout << "\nPlease select an option: ";
	int option;
	cin >> option;
	while(option<1 || option>5)
	{
		cout << "\nYou've entered an invalid input! Please re-enter..." << endl;
		cout << "Select a proper option: ";
		cin >> option;
	}	
	system("cls");
	switch(option)
	{
		case 1:
			courtReservation();
			break;
		case 2:
			equipmentReservation();
			break;
			
		case 3:
			trainer();
			displayTrainer();
			break;
			
		case 4:
			printReceipt();
			break;
			
		case 5:
			logOut();
			break;
	}	
}
void logOut(){
	int PrintReceipt;
if(forgot<1){
	cout << "Oops! Looks like you didn't print the receipt yet." << endl;
	cout << "Press 1 to print receipt or 2 to logout...";
	cin >> PrintReceipt;
	while(PrintReceipt<1 || PrintReceipt>2){
		cout << "You've entered an invalid input! Please re-enter...";
		cin >> PrintReceipt;
	}
	system("cls");
if(PrintReceipt==1){
	printReceipt();	
}
else{
	cout << "Logout successfully!" << endl;
	cout << "Thanks for using our service, wish you a great day! :)" << endl;	
}	
}
else{
	cout << "Logout successfully!" << endl;
	cout << "Thanks for using our service, wish you a great day! :)" << endl;	
}
}
// account login/menu interface close

// function kemal open
void courtReservation(){
	int option;
	forgot=0;
	float total, hours;
	if(allCourt>=1){
		cout << "Your next reservation made for this service will add up with the previous one...";
		Sleep(6000);
		system("cls");
	}	
	cout << "***********************************"<<endl
		 << "Welcome to UiTM Perlis Sport Centre"<<endl
		 << "         Court Reservation         "<<endl
		 << "***********************************"<<endl<<endl
		 <<"Please choose your sport today:"<<endl<<endl;
		 	
		file();
		cout << "\nEnter an option: "; 
		cin >> option;
		
		while(option<1 || option>6)
	{
		cout << "\nYou've entered invalid input! Please re-enter..." << endl;
		cout << "Please choose a proper option: "; 
		cin >> option;
	}
	if(option==1)
	{
		cout << "Enter how many hour(s) do you want: ";
		cin >> hours;
		courtReceiptDetails[courtCounter].selectedCourt=sport[0].sukan;
		courtReceiptDetails[courtCounter].selectedHours=hours;
		{
		total=sport[0].price*hours;
		}
		duit(total);
	}
	else if(option==2)
	{
		cout << "Enter how many hour(s) do you want: ";
		cin >> hours;
		courtReceiptDetails[courtCounter].selectedCourt=sport[1].sukan;
		courtReceiptDetails[courtCounter].selectedHours=hours;
		{
		total=sport[1].price*hours;
		}
		duit(total);
	}
	else if(option==3)
	{
		cout << "Enter how many hour(s) do you want: ";
		cin >> hours;
		courtReceiptDetails[courtCounter].selectedCourt=sport[2].sukan;
		courtReceiptDetails[courtCounter].selectedHours=hours;
		{
		total=sport[2].price*hours;
		}
		duit(total);
	}
	if(option==4)
	{
		cout << "Enter how many hour(s) do you want: ";
		cin >> hours;
		courtReceiptDetails[courtCounter].selectedCourt=sport[3].sukan;
		courtReceiptDetails[courtCounter].selectedHours=hours;
		{
		total=sport[3].price*hours;
		}
		duit(total);
	}
	if(option==5)
	{
		cout << "Enter how many hour(s) do you want: ";
		cin >> hours;
		courtReceiptDetails[courtCounter].selectedCourt=sport[4].sukan;
		courtReceiptDetails[courtCounter].selectedHours=hours;
		{
		total=sport[4].price*hours;
		}
		duit(total);
	}
	if(option==6)
	{
		cout << "Enter how many hour(s) do you want: ";
		cin >> hours;
		courtReceiptDetails[courtCounter].selectedCourt=sport[5].sukan;
		courtReceiptDetails[courtCounter].selectedHours=hours;
		{
		total=sport[5].price*hours;
		}
		duit(total);
	}
}		
double duit(double total){
	int sambung;
	++allCourt; // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	++purchaseCounter; // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	calcFee[courtCounter].totalCourt=total; // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	++courtCounter; // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Total+=total;
	cout << "\nTotal fees for court reservation: RM" << Total;
	total=0;	
	cout << "\nPress 1 to continue or press 2 to go back at main menu >> ";
	cin >> sambung;
	while(sambung<1 || sambung>2)
	{
		cout << "\nYou've entered invalid input! Please re-enter..." << endl;
		cout << "Choose a proper option: ";
		cin >> sambung;
}
	switch(sambung)
	{
		case 1:
			Sleep(1500);
			system("cls");	
			courtReservation();						
			return Total;	
			break;
		case 2:
			Sleep(1500);
			system("cls");
			menu();							
			return Total;		
			break;
	}		
	
}
int file(){
	ifstream courtReserve;
	courtReserve.open("court.txt");
	if(courtReserve.fail())
	{
		cerr<<"error opening file"<<endl;
		exit(1);	
	}
	
	int i=0;
 	while(!courtReserve.eof())
 	{
 	courtReserve >> sport[i].price;
	getline(courtReserve, sport[i].sukan,';');
	courtReserve >> courtRow[i]; // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	cout << i+1 <<"."<<sport[i].sukan << " " << sport[i].price << " per hour" <<endl; // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++
	cout << endl;
	i++;
	}
	courtReserve.close();
}
// function kemal close

// function apikkk open
void counterEquipment(){ // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	++allEquipment;   
	++equipmentCounter; 
	++purchaseCounter;  	
} 
int unitcounter (int price){	
	int total, n;
	cout << " how many would you like to rent :";
	cin >> n;
	equipmentReceiptDetails[equipmentCounter].numUnit=n;	
	total=price*n;
	calcFee[equipmentCounter].totalEquipment=total; // taqin tambah++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	return total;
}
void RentTotal (int total){
	cout << "\n## Accumulative Total = RM"<<total<< " ##" << endl; 
	cout << "\nIf you would like to continue...";
	cout << "\n Choose your next sport today or press 0 to show total\n" <<endl;			 			 
}
int readFile(){	
	
 	ifstream equipmentFile;
 	equipmentFile.open("equipments.txt");
 	if(equipmentFile.fail())
	{
		cerr<<"error opening file"<<endl;
		exit(1);
	}
	int i=0;
 	while(!equipmentFile.eof())
 	{
 	 	equipmentFile >> eqp[i].rental;	  		
 	 	getline(equipmentFile, eqp[i].name, ':'); 
		equipmentFile >> equipmentRow[i]; // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	cout<<eqp[i].name<<":";
 	//	cout<<eqp[i].rental<<endl;
 	 	i++;
 	}
 	equipmentFile.close();
}
void errorrental(){
	cout << "*ERROR* \nPlease re-enter selection\n";
}
void equipmentReservation(){
 
 int sport, choice, value, n, rent;
 forgot=0;
 	if(allEquipment>=1){
		cout << "Your next reservation made for this service will add up with the previous one...";
		Sleep(6000);
		system("cls");
	}
 cout << "\n## Welcome to UiTM Perlis Sport Centre ##" <<endl;
 cout << "\n Equipment Rental Service Department" <<endl ;
 cout << "\n Choose your sport today or press 0 to show total\n" <<endl;
 readFile();
 	string anyKEY; // taqin tambah
 do
 {
 	cout << " 1. Futsal\t 3. Volleyball\t 5. Badminton\n";
 	cout << " 2. Tennis\t 4. Takraw\t 6. Squash\n";
 	cin>>sport;

	// taqin baiki
	while(sport<0 || sport>6){
		errorrental();
		cout << "Select a proper option: ";
		cin >> sport;
	}
	// taqin baiki

 	switch (sport)
 	{
		case 1 : 								//futsal
		{
			 cout <<"\n Choose an item for rental:(1/2/3)"<<endl;
			 cout <<eqp[0].name<<"\t RM"<<eqp[0].rental<<" (1)"<<endl; 
			 cout <<eqp[1].name<<"\t\t RM"<<eqp[1].rental<<" (2)"<<endl;
			 cout <<eqp[2].name<<"\t RM"<<eqp[2].rental<<" (3)"<<endl;
			 cin>>choice;
		
			 if (choice == 1)
			 {
			 	value=eqp[0].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[0].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
		 	 else if (choice == 2)
			 {	
			 	value=eqp[1].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[1].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
			 else if (choice == 3)
			 {
			 	value=eqp[2].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[2].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 	 }
		 	 else		//error404
		 	 {
		 	 	errorrental();
			 } 
			RentTotal(rent);	 
		break;
		}
	
		case 2 : 								//tennis
		{
		 	cout <<"\n Choose an item for rental:(1/2)"<< endl;
		 	cout <<eqp[3].name<<"\t RM"<<eqp[3].rental<<" (1)"<<endl;
			cout <<eqp[4].name<<"\t RM"<<eqp[4].rental<<" (2)"<<endl;
		 	cin>>choice;
			 
			 if (choice == 1)
			 {
			 	value=eqp[3].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[3].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
			 else if (choice == 2)
			 {	
			 	value=eqp[4].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[4].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
		 	 else		//error404
		 	 {
		 	 	errorrental();
			 } 
			RentTotal(rent);
		break;
		}
		
		case 3 :								//volleyball
		{
		 	 cout <<"\n Choose an item for rental:(1/2)"<< endl;
			 cout <<eqp[5].name<<"\t RM"<<eqp[5].rental<<" (1)"<<endl;
			cout <<eqp[6].name<<"\t RM"<<eqp[6].rental<<" (2)"<<endl;
			 cin>>choice;
		 	
			 if (choice == 1)
			 {
			 	value=eqp[5].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[5].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
			 else if (choice == 2)
			 {	
			 	value=eqp[6].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[6].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
		 	 else		//error404
		 	 {
		 	 	errorrental();
			 } 
			RentTotal(rent);		 
		break;
 		}
 	
 		case 4 :								//takraw
 		{
 			cout <<"\n Choose an item for rental:"<< endl;
		 	cout <<eqp[7].name<<"\t RM"<<eqp[7].rental<<" (1)"<<endl;
 			cin>>choice;
			 
			 if (choice == 1)
			 {
			 	value=eqp[7].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[7].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
		 	 else		//error404
		 	 {
		 	 	errorrental();
			 } 
			
			RentTotal(rent);
	 	break;
	 	}
	 	
 		case 5 :								//badminton
 		{
 			cout <<"\n Choose an item for rental:(1/2)"<< endl;
		 	cout <<eqp[8].name<<"\t RM"<<eqp[8].rental<<" (1)"<<endl;
			cout <<eqp[9].name<<"\t RM"<<eqp[9].rental<<" (2)"<<endl;
 			cin>>choice;
		 	
			 if (choice == 1)
			 {
			 	value=eqp[8].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[8].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
			 else if (choice == 2)
			 {	
			 	value=eqp[9].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[9].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
		 	 else		//error404
		 	 {
		 	 	errorrental();
			 } 
		
			RentTotal(rent);
 		break;
		}
	
		case 6 :								//squash
		{
 			cout <<"\n Choose an item for rental:(1/2)"<< endl;
		 	cout <<eqp[10].name<<"\t RM"<<eqp[10].rental<<" (1)"<<endl;
			cout <<eqp[11].name<<"\t RM"<<eqp[11].rental<<" (2)"<<endl;
	 		cin>>choice;
		 	
			 if (choice == 1)
			 {
			 	value=eqp[10].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[10].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }
			 else if (choice == 2)
			 {	
			 	value=eqp[11].rental;
			 	equipmentReceiptDetails[equipmentCounter].selectedEquipment=eqp[11].name; // taqin tambah ++++++++++++++++++++++++++++++++++++++++++++++++
				rent+=unitcounter(value);
				counterEquipment(); // taqin tambah +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			 }	
		 	 else		//error404
		 	 {
		 	 	errorrental();
			 } 
			RentTotal(rent);	
 		break;
 		}
		case 0 :		//no choice
		{
			cout << " No sport selected"<< endl;
//			cout << "\n Please enter a valid number or press 0 to exit program" << endl; // no need(taqin)
		break;
		}
	}

 }while (sport !=0);
 {
 	cout << "--------------------------------";
	cout << "\nTotal rent = RM"<<rent<< endl;
 	cout << "Payment upon pick-up" << endl;
 	cout << "Press any key...";
 	cin >> anyKEY;
 	system("cls");
 	menu();
 }	
}
// function apikkk close

// function taqin open
void calculateAllReceipt(){
	calcAll.receipt.totalAll=0;
	if(allCourt!=0){
for(int i=0; i<allCourt; i++){
	calcAll.receipt.totalAll+=calcFee[i].totalCourt;
}
	}
	if(allEquipment!=0){
for(int i=0; i<allEquipment; i++){
	calcAll.receipt.totalAll+=calcFee[i].totalEquipment;
}		
	}
	if(allTrainer!=0){
for(int i=0; i<allTrainer; i++){
	calcAll.receipt.totalAll+=calcFee[i].totalTrainer;
}		
	}
}
void printReceipt(){
	if(purchaseCounter==0){
		cout << "Hmmm looks like you didn't made any reservation of our service yet." << endl;
		Sleep(5000);
		cout << "How about you have a look first? :)";
		Sleep(3000);
		menu();
	}
	else{
	++forgot;
	int num=1;
	string anyKEY;
	system("cls");
	cout << "##################################" << endl;
	cout << "## UiTM PERLIS OFFICIAL INVOICE ##" << endl;
	cout << "##################################" << endl;
	cout << endl;
	cout << "Student's Name: " << *currentStudent.currentFname
		 << " " << *currentStudent.currentLname << endl;
	cout << "Student's ID: " << currentStudent.currentID << endl;
	cout << endl;
	cout << "======================================================================================" << endl;
	cout << "==NO.==            DESCRIPTION            ==   QUANTITY   ==         AMOUNT         ==" << endl;

	// court reservation
	if(allCourt!=0){
for(int i=0; i<allCourt; i++){
	cout << "  " << num << ".   ";
	cout << " Court Reservation: " << "\t\t       " << courtReceiptDetails[i].selectedHours << " hours\t\tRM" << calcFee[i].totalCourt << endl;
	cout << "        " << courtReceiptDetails[i].selectedCourt << endl;
	++num;	
}
	}
	// court reservation

	// sport equipment reservation
	if(allEquipment!=0){
for(int i=0; i<allEquipment; i++){
	cout << "  " << num << ".   ";	
	cout << " Sport Equipment Reservation:" << "\t\t" << equipmentReceiptDetails[i].numUnit << "x\t\t\tRM" << calcFee[i].totalEquipment << endl;	
	cout << "        " << equipmentReceiptDetails[i].selectedEquipment << endl;	
	++num;
}
	}
	// sport equipment reservation
	
	// trainer reservation
	if(allTrainer!=0){
for(int i=0; i<allTrainer; i++){	
	cout << "  " << num << ".   ";
	cout << " Trainer Reservation: " << "\t\t       " << trainerReceiptDetails[i].selectedHours << " hours\t\tRM" << calcFee[i].totalTrainer << endl;
	cout << "        " << trainerReceiptDetails[i].selectedTrainer << endl;
	++num;
}		
	}
	calculateAllReceipt();
	cout << "======================================================================================" << endl;
	cout << "                                                 TOTAL    =="
	     << "\tRM" << calcAll.receipt.totalAll;
	// trainer reservation
	cout << endl;
	cout << "Press any key to continue: ";
	cin >> anyKEY;
menu();		
	}	
}
void trainer(){
	ifstream readFile;
	readFile.open("trainer.txt");
	if(!readFile.is_open()){
		cerr << "Unabled to open the file...";
	}
	else
		getTrainerData(trainers, readFile);
	readFile.close();
}
void getTrainerData(struct trainerDetails listTrainer[][6], ifstream &getFile){
	int i=0;
	while(!getFile.eof()){
		int j=0;
		if(i==0){
				while(j<6){
					getFile >> listTrainer[i][j].trainerWage;
					++j;
					getline(getFile, listTrainer[i][j].trainerName, ',');
					++j;	
					if(j==6){
						getFile >> row[0];
					}					 
				}
			}
		if(i==1){
				while(j<6){
					getFile >> listTrainer[i][j].trainerWage;
					++j;
					getline(getFile, listTrainer[i][j].trainerName, ',');
					++j;
					if(j==6){
						getFile >> row[1];
					}											 
				}
			}
		if(i==2){
				while(j<6){
					getFile >> listTrainer[i][j].trainerWage;
					++j;
					getline(getFile, listTrainer[i][j].trainerName, ',');
					++j;
					if(j==6){
						getFile >> row[2];
					}											 
				}
			}
		if(i==3){		
				while(j<6){
					getFile >> listTrainer[i][j].trainerWage;
					++j;
					getline(getFile, listTrainer[i][j].trainerName, ',');
					++j;
					if(j==6){
						getFile >> row[3];
					}											 
				}
			}
		if(i==4){
				while(j<6){
					getFile >> listTrainer[i][j].trainerWage;
					++j;
					getline(getFile, listTrainer[i][j].trainerName, ',');
					++j;	
					if(j==6){
						getFile >> row[4];
					}										 
				}	
			}
		if(i==5){	
				while(j<6){
					getFile >> listTrainer[i][j].trainerWage;
					++j;
					getline(getFile, listTrainer[i][j].trainerName, ',');
					++j;	 
					if(j==6){
						getFile >> row[5];
					}					
				}
			}
		i++;
	}	
}
void displayTrainer(){
	system("cls");
	forgot=0;	
	if(allTrainer>=1){
		cout << "Your next reservation made for this service will add up with the previous one...";
		Sleep(6000);
		system("cls");
	}
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "^^Welcome to Trainer Reservation of UiTM Perlis!^^" << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "\n1.Futsal" << endl;
	cout << "2.Tennis" << endl;
	cout << "3.Volleyball" << endl;
	cout << "4.Takraw" << endl;
	cout << "5.Badminton" << endl;
	cout << "6.Squasy" << endl;
	cout << "7.Back to main menu" << endl;
	cout << "\nChoose an option: ";
	int option;
	cin >> option;
	while(option<1 || option>7)
	{
		cout << "\nYou've entered invalid input! Please re-enter..." << endl;
		cout << "Please choose a proper option: "; 
		cin >> option;
	}
	system("cls");
	int i, counter=1, choose;
	switch(option){
		case 1:
			i=0;
			for(int j=0; j<6; j++){
				++j;
				if(j%2!=0){
					cout << counter << "."
					     << trainers[i][j].trainerName << " ";	
					counter++;			
				}
				--j;
				if(j%2==0){
					cout << "(RM" << trainers[i][j].trainerWage
						 << " per hour)" << endl; 					
				}
			}
			break;
		case 2:
			i=1;
			for(int j=0; j<6; j++){
				++j;
				if(j%2!=0){
					cout << counter << "."
					     << trainers[i][j].trainerName << " ";
					counter++;			
				}
				--j;
				if(j%2==0){
					cout << "(RM" << trainers[i][j].trainerWage
						 << " per hour)" << endl; 					
				}
			} 					
			break;
		case 3:
			i=2;
			for(int j=0; j<6; j++){
				++j;
				if(j%2!=0){
					cout << counter << "."
					     << trainers[i][j].trainerName << " ";	
					counter++;			
				}
				--j;
				if(j%2==0){
					cout << "(RM" << trainers[i][j].trainerWage
						 << " per hour)" << endl; 					
				}
			} 			
			break;
		case 4:
			i=3;
			for(int j=0; j<6; j++){
				++j;
				if(j%2!=0){
					cout << counter << "."
					     << trainers[i][j].trainerName << " ";	
					counter++;			
				}
				--j;
				if(j%2==0){
					cout << "(RM" << trainers[i][j].trainerWage
						 << " per hour)" << endl; 					
				}
			} 			
			break;
		case 5:
			i=4;
			for(int j=0; j<6; j++){
				++j;
				if(j%2!=0){
					cout << counter << "."
					     << trainers[i][j].trainerName << " ";	
					counter++;			
				}
				--j;
				if(j%2==0){
					cout << "(RM" << trainers[i][j].trainerWage
						 << " per hour)" << endl; 					
				}
			} 			
			break;
		case 6:
			i=5;
			for(int j=0; j<6; j++){
				++j;
				if(j%2!=0){
					cout << counter << "."
					     << trainers[i][j].trainerName << " ";	
					counter++;			
				}
				--j;
				if(j%2==0){
					cout << "(RM" << trainers[i][j].trainerWage
						 << " per hour)" << endl; 					
				}
			} 			
			break;
		case 7:
			menu();
			break;
	}
			cout << endl;
			cout << "Please choose your trainer: ";
			cin >> choose;
		while(choose<1 || choose>3)
		{
			cout << "\nYou've entered invalid input! Please re-enter..." << endl;
			cout << "Choose a proper option: ";
			cin >> choose;
		}			
			chooseTrainer(i, choose);	
}
void chooseTrainer(int &sports, int &coach){
	string trainer;
	double wage;
	switch(coach){
		case 1:
			--coach; //trainer wage
			wage=trainers[sports][coach].trainerWage;
			//cout << wage;
			++coach; //trainer name
			trainer=trainers[sports][coach].trainerName;
			trainerReceiptDetails[trainerCounter].selectedTrainer=trainer;
			break;
		case 2:
					 //trainer wage
			wage=trainers[sports][coach].trainerWage;
			//cout << wage;
			++coach; //trainer name
			trainer=trainers[sports][coach].trainerName;
			trainerReceiptDetails[trainerCounter].selectedTrainer=trainer;				
			break;
		case 3:
			++coach; //trainer wage
			wage=trainers[sports][coach].trainerWage;
			//cout << wage;
			++coach; //trainer name
			trainer=trainers[sports][coach].trainerName;
			trainerReceiptDetails[trainerCounter].selectedTrainer=trainer;				
			break;
	}
	trainerFee(wage);
}
void trainerFee(double salary){
	++allTrainer;
	++purchaseCounter;
	double hours;
	cout << "Enter how many hour(s) do you want: ";
	cin >> hours;
	trainerReceiptDetails[trainerCounter].selectedHours=hours;
	calcFee[trainerCounter].totalTrainer=hours*salary;
	cout << endl;
	cout << "Your total pay would be RM" << calcFee[trainerCounter].totalTrainer
		 << endl;
	cout << "Press any key to continue: ";
	string anyKEY;
	cin >> anyKEY;
	++trainerCounter;
	menu();	
}
// function taqin close
