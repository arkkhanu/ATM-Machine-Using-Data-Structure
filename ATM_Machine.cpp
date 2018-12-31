#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <process.h>

using namespace std;
// create account through cnic no.
struct AccountMaking {
	// We only provide current account.
	long long cnic; // card no and cnic no is same
	int pinno;
	string fname;
	string lastname;
	string dob;
	long long amount;
	AccountMaking* next;
};

AccountMaking* head = NULL;
int counter = 4110; // for pin no which will increment by adding new account.
int oldcounter = 0;
long long atmamount = 0;

void printsliping(long long a, string b, string c, string d, long long e, long long f);
void Currentime();
void addAmountinAtm();
long long getAtmamountfromfile();
void gotoxy(int x, int y);
void admin(); // admin portion which get password and then call admininner
void admininner(); // admin choices
void createAccount();
void ATMPORTAL();
void loaddatafromfile(); // data load from file.
bool searchcnicno(long long cnicno); // verify dublicate cnic no or not
bool searchpincode(int pinno); // verify dublicate pin code or not
void mainpage(); // main menu where atm and admin
void DisplayedAll(); // Display which include multiple displays
bool matchingadmin(string id, string pass); // verifing admin id and pass from file
void resetpassadmin(); // it will reset the admin id and pass from file
bool isEmpty();
void UpdateMEnu(); // Update Menu contain multiple functions...
void ChangePinNo(); // here admin can change user pin no and check new pin if it exits or not.
void ChangeName();  // here admin can change user first name and last name.
void AddMoneytoPersonAccount(); // here user can add amount through admin.
void DisplayMenu();
void DisplayOneUser();
void ATMUSERMENU();
void ATMUSER(int pn , long long cn);  // ATM user Choices
void userCashWithdrawal(int pin , long long cnic);
void userinfoaccount(int pin, long long cnic);
void userfastwithdrawal(int pin, long long cnic);
void userTransection(int pin, long long cnic);
void userchoicewithdrawal(int pin, long long cnic);
void ingettingprice(int pin, long long cnic, long long amou);
void admintransect();
void inneradmintransect(int pin, long long cnic);
void userATMacco();
void deletinguser();
void userthroughcash();
void RecordingMenu();
void WithdrawalRec1();
void TransectionRec1();
void displaysingly();
void displaydoubly();
void withdrawalsingly(long long cnic);
void transectiondoubly(long long cnic);
void withdrawalsingly2(int pin, long long cnic);
void transectiondoubly2(int pin, long long cnic);

bool searchcnicno(long long cnicno) {
	bool found = false;
	string a, b, c;
	long long d;

	ifstream read("UserProfile.txt");
	if (read.is_open())
	{
		while (!read.eof()) {
			read >> a;
			read >> d;
			getline(read, c);
			if (d == cnicno)
			{
				found = true;
				//cout << c;
				break;
			}
		}
		/*if (found == true)
		{
			cout << "Already had this cnic no. in search cnic\n";
		}*/
	}
	else
	{
		cout << "\nProblem with file opening...\n";
	}
	return found;
}

bool searchpincode(int pinno) {
	bool found = false;
	string a, b, com;
	int c;
	stringstream geek;
	ifstream read("UserProfile.txt");
	if (read.is_open())
	{
		while (!read.eof()) {
			read >> a;
			/////////
			if (!a.empty())
			{
				com = a.substr(4);
				geek << com;
				geek >> c;
				getline(read, b);
				if (c == pinno)
				{
					found = true;
					break;
				}
				geek.clear();
			}

			//////////////
		}
		//if (found == true)
		//{
		////	cout << "Already had this pin no. in search pin\n";
		//}
	}
	else
	{
		cout << "\nProblem with file opening...\n";
	}
	return found;
}

void Currentime()
{
	string a, b, mer;
	time_t now;
	struct tm nowLocal_s;
	now = time(NULL);
	nowLocal_s = *localtime(&now);
	cout << "Date: " << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900 << endl;
	cout << "Time: " << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec << endl;
    
}

void addAmountinAtm() {
	    
	cout << "\n\t\t Adding Amount Rs : 500000 \n";
	long long inneamount = 0 ;
	ofstream write("AccountBalance.txt");
	if (write.is_open())
	 {
		inneamount = 500000;
		atmamount  = 500000;
		write << inneamount;
		write.close();
		cout << "\n\n\t\t Rs : 500000 Has been Added to ATM Machine.\n";
		Sleep(1000);
		admininner();
	 }
	else
	 {
		cout << "Sorry Problem with File....\n";
		Sleep(1000);
		admininner();
	 }
}

long long getAtmamountfromfile() {
	long long a = 0;
	ifstream read("AccountBalance.txt");
	if (read.is_open())
	{
		while (!read.eof())
		{
			read >> a;
		}
		read.close();
	}
	else
	{
		cout << "Problem with File....\n";
		Sleep(1000);
		admin();
	}
	return a;
}

void ATMPORTAL() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t ATM PORTAL \n";
	cout << "\n\n\n\t\t\t 1 -> Back  \n\t\t\t 2 -> ADD Amount  Amount\n\t\t\t 3 -> Remaining\n\t\t\t 0 -> Exit\n";
	char choice; cout << "\n\t\t Enter Choice : "; cin >> choice;
	switch (choice)
	{
	case'0': exit(0);
		break;
	case'1': admininner();
		break;
	case'2': addAmountinAtm();
			 break;
	case'3': {cout << "\n\t\tRemaining Amount : ";
		cout << "\n\t\tRs : " << atmamount << "    has been Remaining. ";
		Sleep(2500);
		admininner(); };
			 break;

	default:cout << "\n\t\tYou have entered wrong choice...\n";
		Sleep(1000);
		admininner();
		break;
	}
}

void mainpage() {
label1:;
	system("cls");
	cin.clear();
	char choice;
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\n\n\t\t\t1 -> Admin \n\t\t\t2 -> ATM (USER)\n\t\t\t0 -> Exit\n";
	cout << "\n\t\t\tPlease select choice : "; cin >> choice;
	switch (choice) {
	case'1':admin();
		break;
	case'2': {
		atmamount = getAtmamountfromfile();
		ATMUSERMENU();
	}	
		break;
	case'0':
		cin.clear();
		exit(0);
		break;
	default:cout << "Wrong input...\n";
		Sleep(1000);
		goto label1;
		break;
	}

}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool matchingadmin(string id, string pass) {
	bool found = false;
	string a, b;
	ifstream read("admin.txt");
	if (read.is_open())
	{
		while (!read.eof()) {
			read >> a;
			read >> b;
		}
	}
	else
	{
		cout << "File Error....\n";
	}
	if (a == id && b == pass)
	{
		found = true;
	}
	return found;

}

void resetpassadmin() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Reset Password \n";
	string id, pass;
	cout << "\n\n\n\t\t\tEnter ID : "; cin >> id;
	cout << "\t\t\tEnter Password : "; cin >> pass;
	if (matchingadmin(id, pass) == true)
	{
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t Reset Password \n";
		string newid, newpass;
		cout << "\n\n\n\t\t\tEnter new ID : "; cin >> newid;
		cout << "\t\t\tEnter new Password : "; cin >> newpass;
		ofstream write("admin.txt");
		write << endl << newid << "\t" << newpass;
		write.close();
		cout << "\n\t The ID and Password has been Changed.\n";
		Sleep(1000);
		admininner();
	}
	else {
		cout << "\n\tWrong ID or Password...\n";
		Sleep(1000);
		admininner();

	}
}

bool isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void ChangePinNo() {
	if (!isEmpty())
	{
		int innecou = 0;
		
	label8:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t  UPDATE MENU \n";
		AccountMaking* temp;
		temp = head;
		bool found = false;
		long long cn_no;
		int pin_no;
		int in1 = 0, in2 = 0;
		string cc, pp;
		stringstream geekcc, geekpp;
		cout << "\n\t\t Enter CNIC No : "; //cin >> cn_no;
		while (!(cin >> cn_no))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				UpdateMEnu();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		cout << "\n\t\t Enter Pin Code : "; //cin >> pin_no;
		while (!(cin >> pin_no))
		{
			if (in2 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in2 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				UpdateMEnu();
			}
			cout << "\t\t Enter Numeric PIN No : ";
			in2++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		geekcc << cn_no;
		geekcc >> cc;
		geekcc.clear();
		geekpp << pin_no;
		geekpp >> pp;
		geekpp.clear();
		
		if (cc.length() == 13 && pp.length()==4)
		{
			while (temp->next != NULL)
			{
				if (temp->cnic == cn_no && temp->pinno == pin_no)
				{
					found = true;
					ifstream read;
					ofstream write;
					read.open("UserProfile.txt");
					write.open("temp.txt");
					stringstream geek;
					string aa, bb, fullline;
					int pin;
					while (!read.eof())
					{
						read >> aa;
						getline(read, fullline);
						if (!aa.empty())
						{
							bb = aa.substr(4);
							geek << bb;
							geek >> pin;
							geek.clear();
							if (pin == pin_no)
							{
							label9:;
							label9a:;
								int inn3 = 0, inn4 = 0;
								string a1 = "pin:", b1,b2;
								stringstream geek2,geek3;
								int newpin;
								cout << "\n\t\t Enter New PIN No : "; //cin >> newpin;
								
								while (!(cin >> newpin))
								{
									if (inn3 == 3)
									{
										cout << "Sorry.... Come Back Again.\n";
										inn3 = 0;
										Sleep(1000);
										cin.clear();
										cin.ignore(100, '\n');
										UpdateMEnu();
									}
									cout << "\t\t Enter Numeric PIN No : ";
									inn3++;
									cin.clear();
									cin.ignore(100, '\n');

								}
								
								geek3 << newpin;
								geek3 >> b2;
								geek3.clear();
								if (b2.length() == 4)
								{
									if (!searchpincode(newpin))
									{
										temp->pinno = newpin;
										geek2 << newpin;
										geek2 >> b1;
										geek2.clear();
										a1.append(b1);
										write << endl << a1 << fullline;
										cout << "\n\t Done....";
										Sleep(1000);
										continue;
									}
									else
									{
										cout << "Already had this Pin Code ...Try Another one.\n";
										Sleep(1000);
										goto label9;
									}
								}
								else if (inn4 == 3)
								{
									cout << "\nSorry Come Back Again...\n";
									inn4 = 0;
									Sleep(1000);
									UpdateMEnu();
								}
								else
								{
									cout << "\nPlease put 4 digit Pin Code... Thanks.\n";
									inn4++;
									Sleep(1000);
									goto label9a;
								}

							}
						}

						write << endl << aa << fullline;
					}
					read.close();
					write.close();
					remove("UserProfile.txt");
					rename("temp.txt", "UserProfile.txt");

				}

				temp = temp->next;
			}

			if (temp->cnic == cn_no && temp->pinno == pin_no && found == false)
			{
				found = true;
				ifstream read;
				ofstream write;
				read.open("UserProfile.txt");
				write.open("temp.txt");
				stringstream geek;
				string aa, bb, fullline;
				int pin;
				while (!read.eof())
				{
					read >> aa;
					getline(read, fullline);
					if (!aa.empty())
					{
						bb = aa.substr(4);
						geek << bb;
						geek >> pin;
						geek.clear();
						if (pin == pin_no)
						{
						label10a:;
						label10:;
							string a1 = "pin:", b1,b2;
							stringstream geek2,geek3;
							int newpin;
							int inn3 = 0, inn4 = 0;
							cout << "\n\t\t Enter New PIN No : ";// cin >> newpin;
							while (!(cin >> newpin))
							{
								if (inn3 == 3)
								{
									cout << "Sorry.... Come Back Again.\n";
									inn3 = 0;
									Sleep(1000);
									cin.clear();
									cin.ignore(100, '\n');
									UpdateMEnu();
								}
								cout << "\t\t Enter Numeric PIN No : ";
								inn3++;
								cin.clear();
								cin.ignore(100, '\n');

							}

							geek3 << newpin;
							geek3 >> b2;
							geek3.clear();

							if (b2.length() == 4)
							{
								if (!searchpincode(newpin))
								{
									temp->pinno = newpin;
									geek2 << newpin;
									geek2 >> b1;
									geek2.clear();
									a1.append(b1);
									write << endl << a1 << fullline;
									cout << "\n\t Done....";
									Sleep(1000);
									continue;
								}
								else
								{
									cout << "Already had this Pin Code ...Try Another one.\n";
									Sleep(1000);
									goto label10;
								}
							}
							if (inn4 == 3)
							{
								cout << "Sorry Come Back Again...\n";
								inn4 = 0;
								Sleep(1000);
								UpdateMEnu();
							}
							else
							{
								cout << "Please put 4 digits PIN Code...Thanks.\n";
								inn4++;
								Sleep(1000);
								goto label10a;
							}
							

						}
					}

					write << endl << aa << fullline;
				}
				read.close();
				write.close();
				remove("UserProfile.txt");
				rename("temp.txt", "UserProfile.txt");

			}
			
			if (found == false)
			{
				cout << "Such User is not in our Database....\n";
				Sleep(1000);
				UpdateMEnu();
			}
		}

		else if (innecou == 2)
		{
			cout << "Sorry... Get back again ....\n";
			Sleep(1000);
			innecou = 0;
			UpdateMEnu();
		}
		else
		{
			cout << "Please Put 13 digits CNIC no and 4 digits Pin Code...Thanks. \n";
			Sleep(1000);
			innecou++;
     		goto label8;
		}

	}
	else
	{
		cout << "\n No data Present here .....\n";
		Sleep(1000);
		admininner();
	}
}

void ChangeName() {
	if (!isEmpty())
	{
		int innecou = 0;
	label8:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t  UPDATE MENU \n";
		AccountMaking* temp;
		temp = head;
		bool found = false;
		long long cn_no;
		int pin_no;
		string cc, pp;
		stringstream geekcc, geekpp;
		int in1 = 0, in2 = 0;

		cout << "\n\t\t Enter CNIC No : ";
		while (!(cin >> cn_no))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				UpdateMEnu();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		cout << "\n\t\t Enter Pin Code : ";
		while (!(cin >> pin_no))
		{
			if (in2 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in2 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				UpdateMEnu();
			}
			cout << "\t\t Enter Numeric PIN No : ";
			in2++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		geekcc << cn_no;
		geekcc >> cc;
		geekcc.clear();
		geekpp << pin_no;
		geekpp >> pp;
		geekpp.clear();

		if (cc.length() == 13 && pp.length() == 4)
		{
			while (temp->next != NULL)
			{
				if (temp->cnic == cn_no && temp->pinno == pin_no)
				{
					found = true;
					ifstream read;
					ofstream write;
					read.open("UserProfile.txt");
					write.open("temp.txt");
					stringstream geek;
					string aa, bb, cc,fn,ln,fullline;
					int pin;
					while (!read.eof())
					{
						read >> aa;
						read >> cc;
						read >> fn;
						read >> ln;
						getline(read, fullline);
						if (!aa.empty())
						{
							bb = aa.substr(4);
							geek << bb;
							geek >> pin;
							geek.clear();
							if (pin == pin_no)
							{
								string nfn, nln;
								cout << "\n\t\t Enter New First Name : "; cin >> nfn;
								cout << "\n\t\t Enter New Last Name : "; cin >> nln;
								
								    temp->fname = nfn;
								    temp->lastname = nln;
									write << endl << aa <<"\t"<< cc << "\t" << nfn << "\t" << nln << fullline;
									cout << "\n\t Done....";
									Sleep(1000);
									continue;
								

							}
						}

						write << endl << aa << "\t" << cc << "\t" << fn << "\t" << ln << fullline;
					}
					read.close();
					write.close();
					remove("UserProfile.txt");
					rename("temp.txt", "UserProfile.txt");

				}

				temp = temp->next;
			}

			if (temp->cnic == cn_no && temp->pinno == pin_no && found == false)
			{
				found = true;
				ifstream read;
				ofstream write;
				read.open("UserProfile.txt");
				write.open("temp.txt");
				stringstream geek;
				string aa, bb, cc, fn, ln, fullline;
				int pin;
				while (!read.eof())
				{
					read >> aa;
					read >> cc;
					read >> fn;
					read >> ln;
					getline(read, fullline);
					if (!aa.empty())
					{
						bb = aa.substr(4);
						geek << bb;
						geek >> pin;
						geek.clear();
						if (pin == pin_no)
						{
							string nfn, nln;
							cout << "\n\t\t Enter New First Name : "; cin >> nfn;
							cout << "\n\t\t Enter New Last Name : "; cin >> nln;

							temp->fname = nfn;
							temp->lastname = nln;
							write << endl << aa << "\t" << cc << "\t" << nfn << "\t" << nln << fullline;
							cout << "\n\t Done....";
							Sleep(1000);
							continue;


						}
					}

					write << endl << aa << "\t" << cc << "\t" << fn << "\t" << ln << fullline;
				}
				read.close();
				write.close();
				remove("UserProfile.txt");
				rename("temp.txt", "UserProfile.txt");

			}

			if (found == false)
			{
				cout << "Such User is not in our Database....\n";
				Sleep(1000);
				UpdateMEnu();
			}
		}

		else if (innecou == 2)
		{
			cout << "Sorry... Get back again ....\n";
			Sleep(1000);
			innecou = 0;
			UpdateMEnu();
		}
		else
		{
			cout << "Please Put 13 digits CNIC no and 4 digits Pin Code...Thanks. \n";
			Sleep(1000);
			innecou++;
			goto label8;
		}

	}
	else
	{
		cout << "\n No data Present here .....\n";
		Sleep(1000);
		admininner();
	}
}

void AddMoneytoPersonAccount() {
	if (!isEmpty())
	{
		int innecou = 0;
	label8:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t  UPDATE MENU \n";
		AccountMaking* temp;
		temp = head;
		bool found = false;
		long long cn_no;
		int pin_no;
		string cc, pp;
		stringstream geekcc, geekpp;
		int in1 = 0, in2 = 0;

		cout << "\n\t\t Enter CNIC No : ";
		while (!(cin >> cn_no))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				UpdateMEnu();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100,'\n');
			
		}

		cout << "\n\t\t Enter Pin Code : ";
		while (!(cin >> pin_no))
		{
			if (in2 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in2 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				UpdateMEnu();
			}
			cout << "\t\t Enter Numeric PIN No : ";
			in2++;
			cin.clear();
			cin.ignore(100, '\n');
		
		}

		geekcc << cn_no;
		geekcc >> cc;
		geekcc.clear();
		geekpp << pin_no;
		geekpp >> pp;
		geekpp.clear();

		if (cc.length() == 13 && pp.length() == 4)
		{
			while (temp->next != NULL)
			{
				if (temp->cnic == cn_no && temp->pinno == pin_no)
				{
					found = true;
					ifstream read;
					ofstream write;
					read.open("UserProfile.txt");
					write.open("temp.txt");
					stringstream geek;
					string aa, bb, cc, fn, ln,cont;
					long long  amount1;
					int pin;
					while (!read.eof())
					{
						read >> aa;
						read >> cc;
						read >> fn;
						read >> ln;
						read >> cont;
						read >> amount1;

						if (!aa.empty())
						{
							bb = aa.substr(4);
							geek << bb;
							geek >> pin;
							geek.clear();
							if (pin == pin_no)
							{
								long long amo,sum;
								cout << "\n\t\t Enter Amount : Rs  "; cin >> amo;
								sum = amo + amount1;
								temp->amount = sum;
								write << endl << aa << "\t" << cc << "\t" << fn << "\t" << ln << "\t" << cont << "\t" << sum;
								cout << "\n\t Done....";
								Sleep(1000);
								continue;
							}
						}

						write << endl << aa << "\t" << cc << "\t" << fn << "\t" << ln << "\t" << cont << "\t" << amount1;
					}
					read.close();
					write.close();
					remove("UserProfile.txt");
					rename("temp.txt", "UserProfile.txt");

				}

				temp = temp->next;
			}

			if (temp->cnic == cn_no && temp->pinno == pin_no)
			{
				found = true;
				ifstream read;
				ofstream write;
				read.open("UserProfile.txt");
				write.open("temp.txt");
				stringstream geek;
				string aa, bb, cc, fn, ln, cont;
				long long  amount1;
				int pin;
				while (!read.eof())
				{
					read >> aa;
					read >> cc;
					read >> fn;
					read >> ln;
					read >> cont;
					read >> amount1;

					if (!aa.empty())
					{
						bb = aa.substr(4);
						geek << bb;
						geek >> pin;
						geek.clear();
						if (pin == pin_no)
						{
							long long amo, sum;
							cout << "\n\t\t Enter Amount : Rs  "; cin >> amo;
							sum = amo + amount1;
							temp->amount = sum;
							write << endl << aa << "\t" << cc << "\t" << fn << "\t" << ln << "\t" << cont << "\t" << sum;
							cout << "\n\t Done....";
							Sleep(1000);
							continue;
						}
					}

					write << endl << aa << "\t" << cc << "\t" << fn << "\t" << ln << "\t" << cont << "\t" << amount1;
				}
				read.close();
				write.close();
				remove("UserProfile.txt");
				rename("temp.txt", "UserProfile.txt");

			}

			if (found == false)
			{
				cout << "Such User is not in our Database....\n";
				Sleep(1000);
				UpdateMEnu();
			}
		}

		else if (innecou == 2)
		{
			cout << "Sorry... Get back again ....\n";
			Sleep(1000);
			innecou = 0;
			UpdateMEnu();
		}
		else
		{
			cout << "Please Put 13 digits CNIC no and 4 digits Pin Code...Thanks. \n";
			Sleep(1000);
			innecou++;
			goto label8;
		}
		

		/////////////
	}
	else
	{
		cout << "\n No data Present here .....\n";
		Sleep(1000);
		admininner();
	}
}

void UpdateMEnu()
{
    label6:;
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t  UPDATE MENU \n";
	cout << "\n\t\t 1 -> Back  ";
	cout << "\n\t\t 2 -> Change Pin No  ";
	cout << "\n\t\t 3 -> Change Name ";
	cout << "\n\t\t 4 -> Add Money to Account ";
	cout << "\n\t\t 5 -> Exit \n";
	char choice; cout << "\n\t\t Enter Choice :  "; cin >> choice;
	switch (choice)
	{

	case'0': exit(0);
		break;
	case'1': admininner();
		break;
	case'2': ChangePinNo();
		     UpdateMEnu();
		break;
	case'3': ChangeName();
		     UpdateMEnu();
		break;
	case'4': AddMoneytoPersonAccount();
		     UpdateMEnu();
		break;
	default:cout << "\n\t Wrong choice Please enter Correct Choice...\n ";
		Sleep(1000);
		goto label6;
		break;
	}

}

void admininner() {
label2:;
	system("cls");
	cin.clear();
	char choice;
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\n\n\t\t\t1 -> Back";
	cout << "\n\t\t\t2 -> ATM PORTAL ";
	cout << "\n\t\t\t3 -> Create New Account";
	cout << "\n\t\t\t4 -> Update Account";
	cout << "\n\t\t\t5 -> Display";
	cout << "\n\t\t\t6 -> Reset Password";
	cout << "\n\t\t\t7 -> Delete User Account";
	cout << "\n\t\t\t8 -> Transection";
	cout << "\n\t\t\t0 -> Exit";
	cout << "\n\t\t\tPlease select choice : "; cin >> choice;
	switch (choice) {
	case'0':
		cin.clear();
		exit(0);
		break;
	case'1': mainpage();
		break;
	case'2':ATMPORTAL();
		break;
	case'3':createAccount();
		break;
	case'4': UpdateMEnu();
		break;
	case'5':DisplayMenu();
		break;
	case'6':resetpassadmin();
		break;
	case'7': deletinguser();
		break;
	case'8': admintransect();
		break;
	default:cout << "Wrong input...\n";
		Sleep(1000);
		goto label2;
		break;
	}

}

void createAccount()
{
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Create Account \n";
	if (isEmpty())
	{
	//		loaddatafromfile();
	
	    label3:;
		AccountMaking* obj = new AccountMaking;
		//	head = obj;
		stringstream geek;
		string cni;
		int in1 = 0, in2 = 0 , outer = 0;
		cout << "\n\t\t Enter 13 digits CNIC No without daches : "; //cin >> obj->cnic;
		
		while (!(cin >> obj->cnic))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				admininner();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		geek << obj->cnic;
		geek >> cni;
		geek.clear();

		if (cni.length() == 13)
		{
			if (!searchcnicno(obj->cnic))
			{
				cout << "\t\t Enter First Name : ";
				cin >> obj->fname;
				cout << "\t\t Enter Last Name : ";
				cin >> obj->lastname;
				cout << "\t\t Enter Contact No : ";
				cin >> obj->dob;
			label4:;
				cout << "\t\t Enter Pin No 4 digit : ";
				stringstream geek1;
				string pin;
				
				while (!(cin >> obj->pinno))
				{
					if (in2 == 3)
					{
						cout << "Sorry.... Come Back Again.\n";
						in2 = 0;
						Sleep(1000);
						cin.clear();
						cin.ignore(100, '\n');
						admininner();
					}
					cout << "\t\t Enter Numeric PIN No : ";
					in2++;
					cin.clear();
					cin.ignore(100, '\n');

				}
				
				geek1 << obj->pinno;
				geek1 >> pin;
				geek1.clear();

				if (pin.length() == 4)
				{
					if (!searchpincode(obj->pinno))
					{
						int in4 = 0;
						cout << "\t\t Enter Amount : ";
                        
						while (!(cin >> obj->amount))
						{
							if (in4 == 3)
							{
								cout << "Sorry.... Come Back Again.\n";
								in4 = 0;
								Sleep(1000);
								cin.clear();
								cin.ignore(100, '\n');
								admininner();
							}
							cout << "\t\t Enter Numeric Amount  : ";
							in4++;
							cin.clear();
							cin.ignore(100, '\n');

						}
						//////////////////////////////////////

						//cin >> obj->amount;
						ofstream write("UserProfile.txt", ios::app);
						if (write.is_open())
						{
							string mer = "pin:";
							write << endl << mer.append(pin) << "\t" << obj->cnic << "\t" << obj->fname;
							write << "\t" << obj->lastname << "\t" << obj->dob << "\t" << obj->amount;
							cout << "\n\tData Stored...\n";
							write.close();
							head = obj;
							obj->next = NULL;
							Sleep(1000);
							admininner();
						}
						else
						{
							cout << "\nError with Database...\nDo it Again...\n";
						}

						///////////////////////////////////
					}
					else
					{
						cout << "Already had, Please try another...\n";
						Sleep(1000);
						//system("cls");
						goto label4;
					}
				}
				else
				{
					cout << "\nPut 4 digits Pin Code... \n";
					Sleep(1000);
					goto label4;
				}
			}
			else
			{
				cout << "already had this cnic no...";
				Sleep(1000);
				goto label3;
			}
		}
		else if (outer == 3)
		{
			cout << "\n Sorry Come Back Again...\n";
			outer = 0;
			Sleep(1000);
			admininner();
		}
		else
		{
			cout << "Please Put 13 digits Correct CNIC NO ...";
			outer++;
			Sleep(1000);
			goto label3;
		}

	}

	else
	{
		AccountMaking* temp;
		temp = head;
		int in1 = 0, in2 = 0 , outer = 0;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	label5:;
		AccountMaking* obj = new AccountMaking;
		stringstream geek;
		string cni;
		cout << "\n\t\t Enter 13 digits CNIC No without daches : "; //cin >> obj->cnic;

		while (!(cin >> obj->cnic))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				admininner();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		geek << obj->cnic;
		geek >> cni;
		geek.clear();

		if (cni.length() == 13)
		{
			if (!searchcnicno(obj->cnic))
			{
				cout << "\t\t Enter First Name : ";
				cin >> obj->fname;
				cout << "\t\t Enter Last Name : ";
				cin >> obj->lastname;
				cout << "\t\t Enter Contact No : ";
				cin >> obj->dob;
			label6:;
				stringstream geek2;
				string pin;
				cout << "\t\t Enter Pin No 4 digit : "; //cin >> obj->pinno;

				while (!(cin >> obj->pinno))
				{
					if (in2 == 3)
					{
						cout << "Sorry.... Come Back Again.\n";
						in2 = 0;
						Sleep(1000);
						cin.clear();
						cin.ignore(100, '\n');
						createAccount();
					}
					cout << "\t\t Enter Numeric PIN No : ";
					in2++;
					cin.clear();
					cin.ignore(100, '\n');

				}

				geek2 << obj->pinno;
				geek2 >> pin;
				geek2.clear();

				if (pin.length() == 4)
				{
					if (!searchpincode(obj->pinno))
					{
						int in4 = 0;
						cout << "\t\t Enter Amount : ";
						/////////////////////////////////
						
						while (!(cin >> obj->amount))
						{
							if (in4 == 3)
							{
								cout << "Sorry.... Come Back Again.\n";
								in4 = 0;
								Sleep(1000);
								cin.clear();
								cin.ignore(100, '\n');
								admininner();
							}
							cout << "\t\t Enter Numeric Amount  : ";
							in4++;
							cin.clear();
							cin.ignore(100, '\n');

						}

						/////////////////////////////////
						//cin >> obj->amount;
						ofstream write("UserProfile.txt", ios::app);
						string mer = "pin:";
						if (write.is_open())
						{
							write << endl << mer.append(pin) << "\t" << obj->cnic << "\t" << obj->fname;
							write << "\t" << obj->lastname << "\t" << obj->dob << "\t" << obj->amount;
							cout << "\n\tData Stored...\n";
							temp->next = obj;
							obj->next = NULL;
							write.close();
							Sleep(1000);
							admininner();
						}
						else
						{
							cout << "\nError with Database...\nDo it Again...\n";
						}
					}
					else
					{
						cout << "Already had, Please try another...\n";
						Sleep(1000);
						goto label6;
					}
				}
				else
				{
					cout << "\nPut 4 digits Pin Code... \n";
					Sleep(1000);
					goto label6;
				}
			}
			else
			{
				cout << "already had this cnic no...";
				Sleep(1000);
				goto label5;
			}
		}
		else if (outer == 3)
		{
			cout << "\n Sorry Come Back Again...\n";
			Sleep(1000);
			admininner();
		}
		else
		{
			cout << "Please Put 13 digits Correct CNIC NO ...";
			outer++;
			Sleep(1000);
			goto label5;
		}

	}

}

void admin() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	string id, pass;
	cout << "\n\n\n\t\t\tEnter ID : "; cin >> id;
	cout << "\t\t\tEnter Password : "; cin >> pass;

	if (matchingadmin(id, pass) == true)
	{
		loaddatafromfile();
		atmamount = getAtmamountfromfile();
		admininner();
	}

	else
	{
		cout << "\n\tSorry Wrong ID or Password...\n";
		Sleep(1000);
		mainpage();
	}

}

void loaddatafromfile() {
	bool found = false;
	AccountMaking* temp1, temp2;
	ifstream read("UserProfile.txt");
	stringstream geek;
	string a,b;
	head = NULL;
	if (read.is_open()) {
		while (!read.eof())
		{
			AccountMaking* obj = new AccountMaking;
			read >> a;
			if (!a.empty())
			{
			found = true;
			b=a.substr(4);
			geek << b;
			geek >> obj->pinno;
			geek.clear();
			read >> obj->cnic;
			read >> obj->fname;
			read >> obj->lastname;
			read >> obj->dob;
			read >> obj->amount;
			
				if (isEmpty()) {
					head = obj;
					obj->next = NULL;
				}
				else {
					temp1 = head;
					while (temp1->next != NULL)
					{
						temp1 = temp1->next;
					}
					temp1->next = obj;
					obj->next = NULL;
				}
			}
		}
	}
	read.close();
}

void DisplayedAll() {

	if (!isEmpty()) {

		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t  DISPLAY MENU \n";
		AccountMaking* temp;
		cout << "_________________________________________________________________________________________________\n";
		cout << "First Name  |\t Last Name  | \t Contact No  | \t    CNIC NO     | \t Amount      | \t Pin No  |\n";
		cout << "-------------------------------------------------------------------------------------------------\n"; 
		temp = head;
		while (temp->next != NULL)
		{

			cout << setw(6) << temp->fname << setw(17) << temp->lastname << setw(20) << temp->dob << setw(20);
			cout << temp->cnic << setw(20) << temp->amount << setw(12) << temp->pinno;
			temp = temp->next;
			cout << endl;
		}

		cout << setw(6) << temp->fname << setw(17) << temp->lastname << setw(20) << temp->dob << setw(20);
		cout << temp->cnic << setw(20) << temp->amount << setw(12) << temp->pinno;
		cout << endl;

	}
	else {
		cout << "linked list is empty";
	}
	char choi;
	cout << "\n\n\t\t 1 -> Back \n\t\t 2 -> Exit \n\t\t Enter choice : "; cin >> choi;
	if (choi == '1')
	{
		DisplayMenu();
	}
	else if (choi == '2')
	{
		DisplayMenu();
	}
	else
	{
		cout << "\nWrong Choice....\n";
		Sleep(1000);
		admininner();
	}
}

void DisplayOneUser() {
	if (!isEmpty()) {
		int inner = 0;
	label11:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t  DISPLAY MENU \n\n";
		AccountMaking* temp;
		bool found = false;
		long long cnic;
		int pin;
		int in1 = 0, in2 = 0;
		cout << "\t\t Enter CNIC NO : "; //cin >> cnic;
		
		while (!(cin >> cnic))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				DisplayMenu();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		cout << "\t\t Enter Pin Code : "; //cin >> pin;
		while (!(cin >> pin))
		{
			if (in2 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in2 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				DisplayMenu();
			}
			cout << "\t\t Enter Numeric PIN No : ";
			in2++;
			cin.clear();
			cin.ignore(100, '\n');

		}

		stringstream geek1, geek2;
		string aa, bb;
		geek1 << cnic;
		geek1 >> aa;
		geek1.clear();
		geek2 << pin;
		geek2 >> bb;
		geek2.clear();

		if (aa.length() == 13 && bb.length() == 4)
		{
			cout << "_________________________________________________________________________________________________\n";
			cout << "First Name  |\t Last Name  | \t Contact No  | \t    CNIC NO     | \t Amount      | \t Pin No  |\n";
			cout << "-------------------------------------------------------------------------------------------------\n"; 
			temp = head;
			while (temp->next != NULL)
			{

				if (temp->cnic == cnic && temp->pinno == pin)
				{
					cout << setw(6) << temp->fname << setw(17) << temp->lastname << setw(20) << temp->dob << setw(20);
					cout << temp->cnic << setw(20) << temp->amount << setw(12) << temp->pinno;
					cout << endl;
					found = true;
					break;
				}
				
				temp = temp->next;
				cout << endl;
			}

			if (temp->cnic == cnic && temp->pinno == pin && found == false )
			{
				cout << setw(6) << temp->fname << setw(17) << temp->lastname << setw(20) << temp->dob << setw(20);
				cout << temp->cnic << setw(20) << temp->amount << setw(12) << temp->pinno;
				cout << endl;
			}
			
			if (found == false)
			{
				cout << "\nNot Found Such Data ...\n";
			}

			char choi;
			cout << "\n\n\t\t 1 -> Back \n\t\t 2 -> Exit \n\t\t Enter choice : "; cin >> choi;
			if (choi == '1')
			{
				DisplayMenu();
			}
			else if (choi == '2')
			{
				DisplayMenu();
			}
			else
			{
				cout << "\nWrong Choice....\n";
				Sleep(1000);
				admininner();
			}
		}
		else if (inner==2)
		{
			cout << "\nSorry come back again....\n";
			Sleep(1000);
			DisplayMenu();
		}
		else
		{
			cout << "Please Put 13 Digit CNIC No and 4 Digit Code....\n";
			inner++;
			Sleep(1000);
			goto label11;
		}
		

	}
	else {
		cout << "linked list is empty";
		Sleep(1000);
	}
	
}

void DisplayMenu() {
label6:;
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t  DISPLAY MENU \n";
	cout << "\n\t\t 1 -> Back  ";
	cout << "\n\t\t 2 -> User Account  ";
	cout << "\n\t\t 3 -> Display All ";
	cout << "\n\t\t 4 -> Record Menu ";
	cout << "\n\t\t 0 -> Exit \n";
	char choice; cout << "\n\t\t Enter Choice :  "; cin >> choice;
	switch (choice)
	{
	case'0': exit(0);
		break;
	case'1': admininner();
		break;
	case'2': DisplayOneUser();
		DisplayMenu();
		break;
	case'3': DisplayedAll();
		DisplayMenu();
		break;
	case'4': RecordingMenu();
		DisplayMenu();
		break;
	
	default:cout << "\n\t Wrong choice Please enter Correct Choice...\n ";
		Sleep(1000);
		goto label6;
		break;
	}
}

void ATMUSERMENU() {
	loaddatafromfile();
	if (!isEmpty())
	{
	int in1 = 0, in2 = 0;
	int ou1 = 0, ou2 = 0;
	label14:;
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	AccountMaking*  temp= head;
	string pin, cnic, aapin, bbcnic;
	int a;
	long long b;
	stringstream geek1, geek2;
	
	

	cout << "\n\n\n\t\t\tEnter CNIC No : ";// cin >> id;

	while (!(cin >> b))
	{
		if (in1 == 3)
		{
			cout << "Sorry.... Come Back Again.\n";
			in1 = 0;
			Sleep(1000);
			cin.clear();
			cin.ignore(100, '\n');
			mainpage();
		}
		cout << "\t\t Enter Numeric CNIC No : ";
		in1++;
		cin.clear();
		cin.ignore(100, '\n');
	}

	geek1 << b;
	geek1 >> cnic;
	geek1.clear();
	
	if (cnic.length()==13)
	{
	label14a:;
		cout << "\n\t\t\t Enter Pin Code : ";

		while (!(cin >> a))
		{
			if (in2 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in2 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				mainpage();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in2++;
			cin.clear();
			cin.ignore(100, '\n');
		}

		geek2 << a;
		geek2 >> pin;
		geek2.clear();

		if (pin.length()==4)
		{
			///
			bool found = false;
			
			while (temp->next != NULL)
			{
				if (temp->cnic == b && temp->pinno == a)
				{
					found = true;
					ATMUSER(a, b);
					break;
				}

				temp = temp->next;
			}
			
			if (temp->cnic == b && temp->pinno == a && found == false)
			{
				found = true;
				//atmamount = getAtmamountfromfile();
				ATMUSER(a,b);
			}

			if (found == false)
			{
				cout << "\n\t Sorry Such Data Not Found....";
				Sleep(1000);
				mainpage();
			}

			///
		}
		else if (ou2==3)
		{
			cout << "\n\t Sorry Come Back Again...\n";
			ou2 = 0;
			Sleep(1000);
			mainpage();
		}
		else
		{
			cout << "\n\t\t Please Enter 4 Digi Pin Code...";
			ou2++;
			Sleep(1000);
			goto label14a;
		}

	}
	else if (ou1==3)
	{
		cout << "\n\t\t Sorry Come Back Again...\n";
		ou1 = 0;
		Sleep(1000);
		mainpage();
	}
	else
	{
		cout << "\n\t\t Please Enter 13 Digit CNIC No...\n";
		ou1++;
		Sleep(1000);
		goto label14;
	}
	}
	else
	{
	cout << "\n\t\t Database is Empty...\n";
	Sleep(1000);
	mainpage();
	}
}

void ATMUSER(int pn, long long cn) {

	label15:;
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t 1 -> Back";
	cout << "\n\t\t\t 2 -> Cash Withdrawal";
	cout << "\n\t\t\t 3 -> Account Info";
	cout << "\n\t\t\t 4 -> Transection";
	cout << "\n\t\t\t 5 -> Withdrawal Record";
	cout << "\n\t\t\t 6 -> Transection Record";
	cout << "\n\t\t\t 0 -> Exit \n";
	char choi;
	cout << "\n\t\t\t Enter Choice : "; cin >> choi;
	switch (choi)
	{
	case'0': exit(0);
		break;
	case'1':mainpage();
		break;
	case'2': userCashWithdrawal(pn, cn); 
		break;
	case'3':userinfoaccount(pn, cn);
		break;
	case'4': userTransection(pn,cn);
		break;
	case'5':  withdrawalsingly2(pn, cn);
		break;
	case'6':  transectiondoubly2(pn, cn);
		break;
	default: {
		cout << "\n\t Sorry Wrong Choice Please put Correct Choice...\n";
		Sleep(1000);
		goto label15;
	}
		break;
	}
}

void userCashWithdrawal(int pin , long long cnic) {
label16:;
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t 1 -> Back";
	cout << "\n\t\t\t 2 -> Fast WithDrawal"; //
	cout << "\n\t\t\t 3 -> User Choice";
	cout << "\n\t\t\t 0 -> Exit \n";
	char choi;
	cout << "\n\t\t\t Enter Choice : "; cin >> choi;
	switch (choi)
	{
	case'0': exit(0);
		break;
	case'1':ATMUSER(pin , cnic);
		break;
	case'2':userfastwithdrawal(pin , cnic);
		break;
	case'3': userchoicewithdrawal(pin, cnic);
		break;
	default: {
		cout << "\n\t Sorry Wrong Choice Please put Correct Choice...\n";
		Sleep(1000);
		goto label16;
	}
		break;
	}

}

void ingettingprice(int pin, long long cnic, long long amou) {
	AccountMaking* temp;
	temp = head;
	bool found = false;
	bool inneee = false;
	string apn, aapn, bcn, bbcn, fname, lname, contact;
	long long cn, amo;
	int pn;
	stringstream geek1, geek2;
	ifstream read("UserProfile.txt");
	ofstream temper("temper.txt");
	
	while (temp->next != NULL)
	{
		if (temp->cnic == cnic && temp->pinno == pin)
		{
			found = true;

			if (read.is_open())
			{
				while (!read.eof())
				{
					read >> apn;
					read >> bcn;
					read >> fname;
					read >> lname;
					read >> contact;
					read >> amo;
					aapn = apn.substr(4);
					geek1 << aapn;
					geek1 >> pn;
					geek1.clear();
					geek2 << bcn;
					geek2 >> cn;
					geek2.clear();

					if (temp->cnic == cn && temp->pinno == pn)
					{
						if (amo > amou)
						{
							if (atmamount>amou && atmamount>0)
							{
								ofstream wri("AccountBalance.txt");
								ofstream reco("WithDrawalRecord.txt", ios::app);
								atmamount = atmamount - amou;
								wri << atmamount;
								wri.close();
								inneee = true;
								long long newamount = amo - amou;
								time_t now;
								struct tm nowLocal_s;
								now = time(NULL);
								nowLocal_s = *localtime(&now);
								
								temper << endl << apn << "\t" << bcn << "\t" << fname << "\t" << lname << "\t" << contact << "\t" << newamount;

								reco << endl << bcn << "\t" << fname << "\t" << lname << "\t" << contact << "\t" << newamount << "\t" << amou;
								reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
								reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
								temp->amount = newamount;
								reco.close();

								printsliping(cn, fname, lname, contact, amou, newamount);
								continue;
							}
							else
							{
								cout << "\n Sorry The ATM Machine have not such Amount...\n";
								cout << "You can cash out that amount Rs: " << atmamount;
								Sleep(1000);
								userCashWithdrawal(pin, cnic);
							}
							
						}
					}

					temper << endl << apn << "\t" << bcn << "\t" << fname << "\t" << lname << "\t" << contact << "\t" << amo;           
				}

			}
			else
			{
				cout << "\n\t Problem with File Error....";
			}
			read.close();
			temper.close();
			remove("UserProfile.txt");
			rename("temper.txt", "UserProfile.txt");

		}

		temp = temp->next;
	}


	if (temp->cnic == cnic && temp->pinno == pin && found == false)
	{
		found = true;
		if (read.is_open())
		{
			while (!read.eof())
			{
				read >> apn;
				read >> bcn;
				read >> fname;
				read >> lname;
				read >> contact;
				read >> amo;
				aapn = apn.substr(4);
				geek1 << aapn;
				geek1 >> pn;
				geek1.clear();
				geek2 << bcn;
				geek2 >> cn;
				geek2.clear();

				if (temp->cnic == cn && temp->pinno == pn)
				{
					if (amo >= amou)
					{
						if (atmamount>amou && atmamount>0)
						{
							ofstream wri("AccountBalance.txt");
							ofstream reco("WithDrawalRecord.txt", ios::app);
							atmamount = atmamount- amou;
							wri << atmamount;
							wri.close();
							long long newamount = amo - amou;
							inneee = true;
							time_t now;
							struct tm nowLocal_s;
							now = time(NULL);
							nowLocal_s = *localtime(&now);

							temper << endl << apn << "\t" << bcn << "\t" << fname << "\t" << lname << "\t" << contact << "\t" << newamount;
							temp->amount = newamount;

							reco << endl << bcn << "\t" << fname << "\t" << lname << "\t" << contact << "\t" << newamount << "\t" << amou;
							reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
							reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
							reco.close();

							printsliping(cn, fname, lname, contact, amou, newamount);
							continue;
						}
						else
						{
							cout << "\n Sorry The ATM Machine have not such Amount...\n";
							cout << "You can cash out that amount Rs: " << atmamount;
							Sleep(1000);
							userCashWithdrawal(pin, cnic);
						}

					}
					else
					{
						cout << "\n\t\t Sorry You have Insufficient Amount...";
						cout << "You can Cash Out only Rs. " << amo;
						amou = 0;
						Sleep(1000);
					}
				}
					temper << endl << apn << "\t" << bcn << "\t" << fname << "\t" << lname << "\t" << contact << "\t" << amo;
				
			}

		}
		else
		{
			cout << "\n\t Problem with File Error....";
		}
		read.close();
		temper.close();
		remove("UserProfile.txt");
		rename("temper.txt", "UserProfile.txt");
	}

	if (inneee == false)
	{
		cout << "\n Sorry You Have Insufficient Balance\n";
		Sleep(1000);
		userCashWithdrawal(pin, cnic);
	}

	else if (inneee == true)
	{
		cout << "\n\t\t Done....Thnks\n";
		Sleep(1000);
		ATMUSER(pin , cnic);
	}
}

void userfastwithdrawal(int pin, long long cnic) {

	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t 0 -> Back";
	cout << "\n\n\t\t\t 1 -> Rs.500";
	cout << "\t\t 2 -> Rs.1000";
	cout << "\n\n\t\t\t 3 -> Rs.5000";
	cout << "\t\t 4 -> Rs.10000";
	cout << "\n\n\t\t\t 5 -> Rs.15000";
	cout << "\t\t 6 -> Rs.20000";
	cout << "\n\n\t\t\t 7 -> Rs.25000";
	cout << "\t\t 8 -> Rs.30000";
	char choi;
	cout << "\n\n\t\t\t Enter Choice : "; cin >> choi;
	switch (choi)
	{
	case'0':userCashWithdrawal(pin, cnic);
		break;
	case'1':ingettingprice(pin, cnic, 500);
		break;
	case'2':ingettingprice(pin, cnic, 1000);
		break;
	case'3':ingettingprice(pin, cnic, 5000);
		break;
	case'4':ingettingprice(pin, cnic, 10000);
		break;
	case'5':ingettingprice(pin, cnic, 15000);
		break;
	case'6':ingettingprice(pin, cnic, 20000);
		break;
	case'7':ingettingprice(pin, cnic, 25000);
		break;
	case'8':ingettingprice(pin, cnic, 30000);
		break;
	default: {
		cout << "\n\t Sorry Wrong Choice ....\n";
		Sleep(1000);
		userCashWithdrawal(pin, cnic);
	}
		break;
	}


}

void userTransection(int pin , long long cnic) {
	if (!isEmpty())
	{

		int in1 = 0, in2 = 0;
	label17:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n\n\n";
		long long cn;
		stringstream geek1;
		string a;
		cout << "\n\t\t\t Enter CNIC No of A Person : ";
		while (!(cin >> cn))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				ATMUSER(pin, cnic);
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');
		}
		geek1 << cn;
		geek1 >> a;
		geek1.clear();
		if (a.length() == 13)
		{
			AccountMaking* temp1 = head;
			bool found1 = false;
			bool found2 = false;
			bool found3 = false;
			bool found4 = false;
			while (temp1->next != NULL)
			{
				if (temp1->cnic == cn && temp1->cnic != cnic)
				{
					found1 = true;
					AccountMaking* temp2 = head;

					while (temp2->next != NULL)
					{
						if (temp2->cnic == cnic)
						{
							found2 = true;
							long long amu1;
							int amuint1 = 0;
							cout << "\n\t\t\t Enter Amount Rs : ";
							while (!(cin >> amu1))
							{
								if (amuint1 == 3)
								{
									cout << "Sorry.... Come Back Again.\n";
									amuint1 = 0;
									Sleep(1000);
									cin.clear();
									cin.ignore(100, '\n');
									ATMUSER(pin, cnic);
								}
								cout << "\t\t Enter Numeric Amount Rs : ";
								amuint1++;
								cin.clear();
								cin.ignore(100, '\n');
							}
							if (temp2->amount > amu1 && amu1 > 0)
							{
								string a, c, d, e;
								long long b, f;
								ifstream read1("UserProfile.txt");
								ofstream writer1;
								writer1.open("temp1.txt");
								while (!read1.eof())
								{
									read1 >> a;
									read1 >> b;
									read1 >> c;
									read1 >> d;
									read1 >> e;
									read1 >> f;

									if (b == cnic)
									{
										long long newans1 = f - amu1;
										found3 = true;
										temp2->amount = newans1;

										writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans1;
										
										ofstream reco("TransectionRecord.txt", ios::app);
										reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
										reco.close();
										
										continue;
									}
									writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
								}
								writer1.close();
								read1.close();
								remove("UserProfile.txt");
								rename("temp1.txt", "UserProfile.txt");

								if (found3 == true)
								{
									string a1, c1, d1, e1;
									long long b1, f1;
									ifstream read2("UserProfile.txt");
									ofstream writer2;
									writer2.open("temp2.txt");
									while (!read2.eof())
									{
										read2 >> a1;
										read2 >> b1;
										read2 >> c1;
										read2 >> d1;
										read2 >> e1;
										read2 >> f1;
										if (b1 == cn)
										{
											long long newans2 = f1 + amu1;
											found4 = true;
											temp1->amount = newans2;
											writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans2;
											
											ofstream reco("TransectionRecord.txt", ios::app);
											time_t now;
											struct tm nowLocal_s;
											now = time(NULL);
											nowLocal_s = *localtime(&now);
											reco << "\t" << b1 << "\t" << c1;
											reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
											reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
											reco.close();
											continue;
										}
										writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
									}
									writer2.close();
									read2.close();
									remove("UserProfile.txt");
									rename("temp2.txt", "UserProfile.txt");
								}
							}
							else
							{
								cout << "\n\t\t\t Sorry unsufficient Amount...\n";
								Sleep(1000);
								ATMUSER(pin, cnic);
							}

						}

						temp2 = temp2->next;
					}
					if (temp2->cnic == cnic)
					{
						found2 = true;
						long long amu1;
						int amuint1 = 0;
						cout << "\n\t\t\t Enter Amount Rs : ";

						while (!(cin >> amu1))
						{
							if (amuint1 == 3)
							{
								cout << "Sorry.... Come Back Again.\n";
								amuint1 = 0;
								Sleep(1000);
								cin.clear();
								cin.ignore(100, '\n');
								ATMUSER(pin, cnic);
							}
							cout << "\t\t Enter Numeric Amount Rs : ";
							amuint1++;
							cin.clear();
							cin.ignore(100, '\n');
						}

						if (temp2->amount > amu1 && amu1 > 0)
						{
							string a, c, d, e;
							long long b, f;
							ifstream read1("UserProfile.txt");
							ofstream writer1;
							writer1.open("temp1.txt");
							while (!read1.eof())
							{
								read1 >> a;
								read1 >> b;
								read1 >> c;
								read1 >> d;
								read1 >> e;
								read1 >> f;
								if (b == cnic)
								{
									long long newans3 = f - amu1;
									found3 = true;
									temp2->amount = newans3;
									writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans3;
									
									ofstream reco("TransectionRecord.txt", ios::app);
									reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
									reco.close();

									continue;
								}
								writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
							}
							writer1.close();
							read1.close();
							remove("UserProfile.txt");
							rename("temp1.txt", "UserProfile.txt");

							if (found3 == true)
							{
								string a1, c1, d1, e1;
								long long b1, f1;
								ifstream read2("UserProfile.txt");
								ofstream writer2;
								writer2.open("temp2.txt");
								while (!read2.eof())
								{
									read2 >> a1;
									read2 >> b1;
									read2 >> c1;
									read2 >> d1;
									read2 >> e1;
									read2 >> f1;
									if (b1 == cn)
									{
										long long newans4 = f1 + amu1;
										found4 = true;
										temp1->amount = newans4;
										writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans4;
										
										ofstream reco("TransectionRecord.txt", ios::app);
										time_t now;
										struct tm nowLocal_s;
										now = time(NULL);
										nowLocal_s = *localtime(&now);
										reco << "\t" << b1 << "\t" << c1;
										reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
										reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
										reco.close();
										continue;
									}
									writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
								}
								writer2.close();
								read2.close();
								remove("UserProfile.txt");
								rename("temp2.txt", "UserProfile.txt");
							}
						}

						else
						{
							cout << "\n\t\t\t Sorry unsufficient Amount...\n";
							Sleep(1000);
							ATMUSER(pin, cnic);
						}
					}

				}

				temp1 = temp1->next;
			}

			if (temp1->cnic == cn && temp1->cnic != cnic && found1 == false)
			{
				found1 = true;
				AccountMaking* temp2 = head;

				while (temp2->next != NULL)
				{
					if (temp2->cnic == cnic)
					{
						found2 = true;
						long long amu1;
						int amuint1 = 0;
						cout << "\n\t\t\t Enter Amount Rs : ";
						while (!(cin >> amu1))
						{
							if (amuint1 == 3)
							{
								cout << "Sorry.... Come Back Again.\n";
								amuint1 = 0;
								Sleep(1000);
								cin.clear();
								cin.ignore(100, '\n');
								ATMUSER(pin, cnic);
							}
							cout << "\t\t Enter Numeric Amount Rs : ";
							amuint1++;
							cin.clear();
							cin.ignore(100, '\n');
						}
						if (temp2->amount > amu1 && amu1 > 0)
						{
							string a, c, d, e;
							long long b, f;
							ifstream read1("UserProfile.txt");
							ofstream writer1;
							writer1.open("temp1.txt");
							while (!read1.eof())
							{
								read1 >> a;
								read1 >> b;
								read1 >> c;
								read1 >> d;
								read1 >> e;
								read1 >> f;
								if (b == cnic)
								{
									long long newans5 = f - amu1;
									found3 = true;
									temp2->amount = newans5;
									writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans5;
									
									ofstream reco("TransectionRecord.txt", ios::app);
									reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
									reco.close();

									continue;
								}
								writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
							}
							writer1.close();
							read1.close();
							remove("UserProfile.txt");
							rename("temp1.txt", "UserProfile.txt");

							if (found3 == true)
							{
								string a1, c1, d1, e1;
								long long b1, f1;
								ifstream read2("UserProfile.txt");
								ofstream writer2;
								writer2.open("temp2.txt");
								while (!read2.eof())
								{
									read2 >> a1;
									read2 >> b1;
									read2 >> c1;
									read2 >> d1;
									read2 >> e1;
									read2 >> f1;
									if (b1 == cn)
									{
										long long newans6 = f1 + amu1;
										found4 = true;
										temp1->amount = newans6;
										writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans6;
										
										ofstream reco("TransectionRecord.txt", ios::app);
										time_t now;
										struct tm nowLocal_s;
										now = time(NULL);
										nowLocal_s = *localtime(&now);
										reco << "\t" << b1 << "\t" << c1;
										reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
										reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
										reco.close();

										continue;
									}
									writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
								}
								writer2.close();
								read2.close();
								remove("UserProfile.txt");
								rename("temp2.txt", "UserProfile.txt");
							}
						}
						else
						{
							cout << "\n\t\t\t Sorry unsufficient Amount...\n";
							Sleep(1000);
							ATMUSER(pin, cnic);
						}

					}

					temp2 = temp2->next;
				}

				if (temp2->cnic == cnic)
				{
					found2 = true;
					long long amu1;
					int amuint1 = 0;
					cout << "\n\t\t\t Enter Amount Rs : ";

					while (!(cin >> amu1))
					{
						if (amuint1 == 3)
						{
							cout << "Sorry.... Come Back Again.\n";
							amuint1 = 0;
							Sleep(1000);
							cin.clear();
							cin.ignore(100, '\n');
							ATMUSER(pin, cnic);
						}
						cout << "\t\t Enter Numeric Amount Rs : ";
						amuint1++;
						cin.clear();
						cin.ignore(100, '\n');
					}

					if (temp2->amount > amu1 && amu1 > 0)
					{
						string a, c, d, e;
						long long b, f;
						ifstream read1("UserProfile.txt");
						ofstream writer1;
						writer1.open("temp1.txt");
						while (!read1.eof())
						{
							read1 >> a;
							read1 >> b;
							read1 >> c;
							read1 >> d;
							read1 >> e;
							read1 >> f;
							if (b == cnic)
							{
								long long newans7 = f - amu1;
								found3 = true;
								temp2->amount = newans7;
								writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans7;
								
								ofstream reco("TransectionRecord.txt", ios::app);
								reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
								reco.close();
								
								continue;
							}
							writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
						}
						writer1.close();
						read1.close();
						remove("UserProfile.txt");
						rename("temp1.txt", "UserProfile.txt");

						if (found3 == true)
						{
							string a1, c1, d1, e1;
							long long b1, f1;
							ifstream read2("UserProfile.txt");
							ofstream writer2;
							writer2.open("temp2.txt");
							while (!read2.eof())
							{
								read2 >> a1;
								read2 >> b1;
								read2 >> c1;
								read2 >> d1;
								read2 >> e1;
								read2 >> f1;
								if (b1 == cn)
								{
									long long newans8 = f1 + amu1;
									found4 = true;
									temp1->amount = newans8;
									writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans8;

									ofstream reco("TransectionRecord.txt", ios::app);
									time_t now;
									struct tm nowLocal_s;
									now = time(NULL);
									nowLocal_s = *localtime(&now);
									reco << "\t" << b1 << "\t" << c1;
									reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
									reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
									reco.close();

									continue;
								}
								writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
							}
							writer2.close();
							read2.close();
							remove("UserProfile.txt");
							rename("temp2.txt", "UserProfile.txt");
						}
					}

					else
					{
						cout << "\n\t\t\t Sorry unsufficient Amount...\n";
						Sleep(1000);
						ATMUSER(pin, cnic);
					}
				}

			}

			if (found4 == true)
			{
				cout << "\n\t\t\t Done...Thanks...\n";
				Sleep(1000);
				ATMUSER(pin, cnic);
			}

			if (found1 == false)
			{
				cout << "\n\t\t\t Sorry Such user is not found....\n";
				Sleep(1000);
				ATMUSER(pin, cnic);
			}

		}
		else if (in2 == 3)
		{
			cout << "\n\t\t\t Sorry Come Back Again...\n";
			in2 = 0;
			Sleep(1000);
			ATMUSER(pin, cnic);
		}
		else
		{
			cout << "\n\t\t\t Please Put 13 Digit CNIC NO....\n";
			in2++;
			Sleep(1000);
			goto label17;
		}

	}
	else
	{
	cout << "\n\t\t\t Database is Empty...\n";
	Sleep(1000);
	admininner();
	}
}

void userinfoaccount(int pin, long long cnic) {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n\n\n";
	AccountMaking* temp;
	cout << "_________________________________________________________________________________________________\n";
	cout << "First Name  |\t Last Name  | \t Contact No  | \t    CNIC NO     | \t Amount      | \t Pin No  |\n";
	cout << "-------------------------------------------------------------------------------------------------\n";
	temp = head;
	bool found = false;
	while (temp->next != NULL)
	{

		if (temp->cnic == cnic && temp->pinno == pin)
		{
			cout << setw(6) << temp->fname << setw(17) << temp->lastname << setw(20) << temp->dob << setw(20);
			cout << temp->cnic << setw(20) << temp->amount << setw(12) << temp->pinno;
			cout << endl;
			found = true;
			break;
		}

		temp = temp->next;
	}

	if (temp->cnic == cnic && temp->pinno == pin && found==false)
	{
		cout << setw(6) << temp->fname << setw(17) << temp->lastname << setw(20) << temp->dob << setw(20);
		cout << temp->cnic << setw(20) << temp->amount << setw(12) << temp->pinno;
		cout << endl;
		found = true;
	}

	cout << "\n\t\t\t 1 -> Back ";
	cout << "\n\t\t\t 0 -> Exit ";
	char cc;
	cout << "\n\t\t\t Enter choice : "; cin >> cc;
	if (cc=='0')
	{
		exit(0);
	}
	else if (cc=='1')
	{
		ATMUSER(pin, cnic);
	}
	else
	{
		cout << "\n\t Sorry wrong choice...\n";

		Sleep(1000);
		ATMUSER(pin,cnic);
	}

}

void userchoicewithdrawal(int pin, long long cnic) {
	system("cls");
	long long amm;
	int in1 = 0;
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n\n";
	cout << "\n\t\t\t Enter Amount : Rs . "; 

	while (!(cin >> amm))
	{
		if (in1 == 3)
		{
			cout << "Sorry.... Come Back Again.\n";
			in1 = 0;
			Sleep(1000);
			cin.clear();
			cin.ignore(100, '\n');
			userCashWithdrawal(pin, cnic);
		}
		cout << "\t\t Enter Numeric Amount Rs : ";
		in1++;
		cin.clear();
		cin.ignore(100, '\n');
	}
	if (amm>=100 && amm<=30000)
	{
		ingettingprice(pin, cnic, amm);
	}
	else
	{
		cout << "\n Sorry cann't be Done...!\n Please Put greater Rs 100 or less than Rs 30,000 Thanks...\n";
		Sleep(1000);
		userCashWithdrawal(pin, cnic);
	}
}

void printsliping(long long a, string b, string c, string d, long long e , long long f) {
	ofstream file;
	time_t now;
	struct tm nowLocal_s;
	now = time(NULL);
	nowLocal_s = *localtime(&now);

	file.open("printing.txt");
	file << "\n\t Welcome To BUKC ATM\n";
	file << "\nCNIC No      : " << a;
	file << "\nFirst Name   : " << b;
	file << "\nLast Name    : " << c;
	file << "\nContact No   : " << d;
	file << "\nCash Out Rs  : " << e;
	file << "\nRemaining Rs : " << f;
	file << "\nDate: " << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
	file << "\nTime: " << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec << endl;
	file.close();
	cout << "Break....\n";
	system("notepad /p printing.txt");
	cout << "\n\nt\t\t Printing.....\n";
}

void admintransect() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n\n";
	cout << "\n\t\t\t 1 -> Back";
	cout << "\n\t\t\t 2 -> Through Account";
	cout << "\n\t\t\t 3 -> Through Cash";
	cout << "\n\t\t\t 0 -> Exit\n";
	char choi;
	cout << "\n\t\t\t Enter Choice : ";
	cin >> choi;
	switch (choi)
	{
	case'0':exit(0);
		break;
	case'1': admininner();
		break;
	case'2': userATMacco();
			break;
	case'3': userthroughcash();
		break;
	default: {
		cout << "\n\t\t\t Wrong input please try again...\n";
		Sleep(1000);
		admintransect();
	}
		break;
	}
}

void inneradmintransect(int pin, long long cnic) {

	int in1 = 0, in2 = 0;
label17:;
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n\n\n";
	long long cn;
	stringstream geek1;
	string a;
	cout << "\n\t\t\t Enter CNIC No of A Person : ";
	while (!(cin >> cn))
	{
		if (in1 == 3)
		{
			cout << "Sorry.... Come Back Again.\n";
			in1 = 0;
			Sleep(1000);
			cin.clear();
			cin.ignore(100, '\n');
			admininner();
		}
		cout << "\t\t Enter Numeric CNIC No : ";
		in1++;
		cin.clear();
		cin.ignore(100, '\n');
	}
	geek1 << cn;
	geek1 >> a;
	geek1.clear();
	if (a.length() == 13)
	{
		AccountMaking* temp1 = head;
		bool found1 = false;
		bool found2 = false;
		bool found3 = false;
		bool found4 = false;
		while (temp1->next != NULL)
		{
			if (temp1->cnic == cn && temp1->cnic != cnic)
			{
				found1 = true;
				AccountMaking* temp2 = head;

				while (temp2->next != NULL)
				{
					if (temp2->cnic == cnic)
					{
						found2 = true;
						long long amu1;
						int amuint1 = 0;
						cout << "\n\t\t\t Enter Amount Rs : ";
						while (!(cin >> amu1))
						{
							if (amuint1 == 3)
							{
								cout << "Sorry.... Come Back Again.\n";
								amuint1 = 0;
								Sleep(1000);
								cin.clear();
								cin.ignore(100, '\n');
								admininner();
							}
							cout << "\t\t Enter Numeric Amount Rs : ";
							amuint1++;
							cin.clear();
							cin.ignore(100, '\n');
						}
						if (temp2->amount > amu1 && amu1 > 0)
						{
							string a, c, d, e;
							long long b, f;
							ifstream read1("UserProfile.txt");
							ofstream writer1;
							writer1.open("temp1.txt");
							while (!read1.eof())
							{
								read1 >> a;
								read1 >> b;
								read1 >> c;
								read1 >> d;
								read1 >> e;
								read1 >> f;

								if (b == cnic)
								{
									long long newans1 = f - amu1;
									found3 = true;
									temp2->amount = newans1;
									writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans1;
									
									ofstream reco("TransectionRecord.txt", ios::app);
									reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
									reco.close();
									
									continue;
								}
								writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
							}
							writer1.close();
							read1.close();
							remove("UserProfile.txt");
							rename("temp1.txt", "UserProfile.txt");

							if (found3 == true)
							{
								string a1, c1, d1, e1;
								long long b1, f1;
								ifstream read2("UserProfile.txt");
								ofstream writer2;
								writer2.open("temp2.txt");
								while (!read2.eof())
								{
									read2 >> a1;
									read2 >> b1;
									read2 >> c1;
									read2 >> d1;
									read2 >> e1;
									read2 >> f1;
									if (b1 == cn)
									{
										long long newans2 = f1 + amu1;
										found4 = true;
										temp1->amount = newans2;
										writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans2;
										
										ofstream reco("TransectionRecord.txt", ios::app);
										time_t now;
										struct tm nowLocal_s;
										now = time(NULL);
										nowLocal_s = *localtime(&now);
										reco << "\t" << b1 << "\t" << c1;
										reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
										reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
										reco.close();

										continue;
									}
									writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
								}
								writer2.close();
								read2.close();
								remove("UserProfile.txt");
								rename("temp2.txt", "UserProfile.txt");
							}
						}
						else
						{
							cout << "\n\t\t\t Sorry unsufficient Amount...\n";
							Sleep(1000);
							admininner();
						}

					}

					temp2 = temp2->next;
				}
				if (temp2->cnic == cnic)
				{
					found2 = true;
					long long amu1;
					int amuint1 = 0;
					cout << "\n\t\t\t Enter Amount Rs : ";

					while (!(cin >> amu1))
					{
						if (amuint1 == 3)
						{
							cout << "Sorry.... Come Back Again.\n";
							amuint1 = 0;
							Sleep(1000);
							cin.clear();
							cin.ignore(100, '\n');
							admininner();
						}
						cout << "\t\t Enter Numeric Amount Rs : ";
						amuint1++;
						cin.clear();
						cin.ignore(100, '\n');
					}

					if (temp2->amount > amu1 && amu1 > 0)
					{
						string a, c, d, e;
						long long b, f;
						ifstream read1("UserProfile.txt");
						ofstream writer1;
						writer1.open("temp1.txt");
						while (!read1.eof())
						{
							read1 >> a;
							read1 >> b;
							read1 >> c;
							read1 >> d;
							read1 >> e;
							read1 >> f;
							if (b == cnic)
							{
								long long newans3 = f - amu1;
								found3 = true;
								temp2->amount = newans3;
								writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans3;
								
								ofstream reco("TransectionRecord.txt", ios::app);
								reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
								reco.close();

								continue;
							}
							writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
						}
						writer1.close();
						read1.close();
						remove("UserProfile.txt");
						rename("temp1.txt", "UserProfile.txt");

						if (found3 == true)
						{
							string a1, c1, d1, e1;
							long long b1, f1;
							ifstream read2("UserProfile.txt");
							ofstream writer2;
							writer2.open("temp2.txt");
							while (!read2.eof())
							{
								read2 >> a1;
								read2 >> b1;
								read2 >> c1;
								read2 >> d1;
								read2 >> e1;
								read2 >> f1;
								if (b1 == cn)
								{
									long long newans4 = f1 + amu1;
									found4 = true;
									temp1->amount = newans4;
									writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans4;
									
									ofstream reco("TransectionRecord.txt", ios::app);
									time_t now;
									struct tm nowLocal_s;
									now = time(NULL);
									nowLocal_s = *localtime(&now);
									reco << "\t" << b1 << "\t" << c1;
									reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
									reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
									reco.close();
									
									continue;
								}
								writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
							}
							writer2.close();
							read2.close();
							remove("UserProfile.txt");
							rename("temp2.txt", "UserProfile.txt");
						}
					}

					else
					{
						cout << "\n\t\t\t Sorry unsufficient Amount...\n";
						Sleep(1000);
						admininner();
					}
				}

			}

			temp1 = temp1->next;
		}

		if (temp1->cnic == cn && temp1->cnic != cnic && found1 == false)
		{
			found1 = true;
			AccountMaking* temp2 = head;

			while (temp2->next != NULL)
			{
				if (temp2->cnic == cnic)
				{
					found2 = true;
					long long amu1;
					int amuint1 = 0;
					cout << "\n\t\t\t Enter Amount Rs : ";
					while (!(cin >> amu1))
					{
						if (amuint1 == 3)
						{
							cout << "Sorry.... Come Back Again.\n";
							amuint1 = 0;
							Sleep(1000);
							cin.clear();
							cin.ignore(100, '\n');
							admininner();
						}
						cout << "\t\t Enter Numeric Amount Rs : ";
						amuint1++;
						cin.clear();
						cin.ignore(100, '\n');
					}
					if (temp2->amount > amu1 && amu1 > 0)
					{
						string a, c, d, e;
						long long b, f;
						ifstream read1("UserProfile.txt");
						ofstream writer1;
						writer1.open("temp1.txt");
						while (!read1.eof())
						{
							read1 >> a;
							read1 >> b;
							read1 >> c;
							read1 >> d;
							read1 >> e;
							read1 >> f;
							if (b == cnic)
							{
								long long newans5 = f - amu1;
								found3 = true;
								temp2->amount = newans5;
								writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans5;
								
								ofstream reco("TransectionRecord.txt", ios::app);
								reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
								reco.close();

								continue;
							}
							writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
						}
						writer1.close();
						read1.close();
						remove("UserProfile.txt");
						rename("temp1.txt", "UserProfile.txt");

						if (found3 == true)
						{
							string a1, c1, d1, e1;
							long long b1, f1;
							ifstream read2("UserProfile.txt");
							ofstream writer2;
							writer2.open("temp2.txt");
							while (!read2.eof())
							{
								read2 >> a1;
								read2 >> b1;
								read2 >> c1;
								read2 >> d1;
								read2 >> e1;
								read2 >> f1;
								if (b1 == cn)
								{
									long long newans6 = f1 + amu1;
									found4 = true;
									temp1->amount = newans6;
									writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans6;
									
									ofstream reco("TransectionRecord.txt", ios::app);
									time_t now;
									struct tm nowLocal_s;
									now = time(NULL);
									nowLocal_s = *localtime(&now);
									reco << "\t" << b1 << "\t" << c1;
									reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
									reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
									reco.close();

									continue;
								}
								writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
							}
							writer2.close();
							read2.close();
							remove("UserProfile.txt");
							rename("temp2.txt", "UserProfile.txt");
						}
					}
					else
					{
						cout << "\n\t\t\t Sorry unsufficient Amount...\n";
						Sleep(1000);
						admininner();
					}

				}

				temp2 = temp2->next;
			}

			if (temp2->cnic == cnic)
			{
				found2 = true;
				long long amu1;
				int amuint1 = 0;
				cout << "\n\t\t\t Enter Amount Rs : ";

				while (!(cin >> amu1))
				{
					if (amuint1 == 3)
					{
						cout << "Sorry.... Come Back Again.\n";
						amuint1 = 0;
						Sleep(1000);
						cin.clear();
						cin.ignore(100, '\n');
						admininner();
					}
					cout << "\t\t Enter Numeric Amount Rs : ";
					amuint1++;
					cin.clear();
					cin.ignore(100, '\n');
				}

				if (temp2->amount > amu1 && amu1 > 0)
				{
					string a, c, d, e;
					long long b, f;
					ifstream read1("UserProfile.txt");
					ofstream writer1;
					writer1.open("temp1.txt");
					while (!read1.eof())
					{
						read1 >> a;
						read1 >> b;
						read1 >> c;
						read1 >> d;
						read1 >> e;
						read1 >> f;
						if (b == cnic)
						{
							long long newans7 = f - amu1;
							found3 = true;
							temp2->amount = newans7;
							writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newans7;
							
							ofstream reco("TransectionRecord.txt", ios::app);
							reco << endl << b << "\t" << c << "\t" << d << "\t" << amu1;
							reco.close();

							continue;
						}
						writer1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
					}
					writer1.close();
					read1.close();
					remove("UserProfile.txt");
					rename("temp1.txt", "UserProfile.txt");

					if (found3 == true)
					{
						string a1, c1, d1, e1;
						long long b1, f1;
						ifstream read2("UserProfile.txt");
						ofstream writer2;
						writer2.open("temp2.txt");
						while (!read2.eof())
						{
							read2 >> a1;
							read2 >> b1;
							read2 >> c1;
							read2 >> d1;
							read2 >> e1;
							read2 >> f1;
							if (b1 == cn)
							{
								long long newans8 = f1 + amu1;
								found4 = true;
								temp1->amount = newans8;
								writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << newans8;
								
								ofstream reco("TransectionRecord.txt", ios::app);
								time_t now;
								struct tm nowLocal_s;
								now = time(NULL);
								nowLocal_s = *localtime(&now);
								reco << "\t" << b1 << "\t" << c1;
								reco << "\t" << "Date:" << nowLocal_s.tm_mday << "-" << nowLocal_s.tm_mon + 1 << "-" << nowLocal_s.tm_year + 1900;
								reco << "\t" << "Time:" << nowLocal_s.tm_hour << ":" << nowLocal_s.tm_min << ":" << nowLocal_s.tm_sec;
								reco.close();

								continue;
							}
							writer2 << endl << a1 << "\t" << b1 << "\t" << c1 << "\t" << d1 << "\t" << e1 << "\t" << f1;
						}
						writer2.close();
						read2.close();
						remove("UserProfile.txt");
						rename("temp2.txt", "UserProfile.txt");
					}
				}

				else
				{
					cout << "\n\t\t\t Sorry unsufficient Amount...\n";
					Sleep(1000);
					admininner();
				}
			}

		}

		if (found4 == true)
		{
			cout << "\n\t\t\t Done...Thanks...\n";
			Sleep(1000);
			admininner();
		}

		if (found1 == false)
		{
			cout << "\n\t\t\t Sorry Such user is not found....\n";
			Sleep(1000);
			admininner();
		}

	}
	else if (in2 == 3)
	{
		cout << "\n\t\t\t Sorry Come Back Again...\n";
		in2 = 0;
		Sleep(1000);
		admininner();
	}
	else
	{
		cout << "\n\t\t\t Please Put 13 Digit CNIC NO....\n";
		in2++;
		Sleep(1000);
		goto label17;
	}
}

void userATMacco()
{
	if (!isEmpty())
	{
	int in1 = 0, in2 = 0;
	int ou1 = 0, ou2 = 0;
label14:;
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	AccountMaking*  temp = head;
	string pin, cnic, aapin, bbcnic;
	int a;
	long long b;
	stringstream geek1, geek2;



	cout << "\n\n\n\t\t\tEnter CNIC No : ";// cin >> id;

	while (!(cin >> b))
	{
		if (in1 == 3)
		{
			cout << "Sorry.... Come Back Again.\n";
			in1 = 0;
			Sleep(1000);
			cin.clear();
			cin.ignore(100, '\n');
			admininner();
		}
		cout << "\t\t Enter Numeric CNIC No : ";
		in1++;
		cin.clear();
		cin.ignore(100, '\n');
	}

	geek1 << b;
	geek1 >> cnic;
	geek1.clear();

	if (cnic.length() == 13)
	{
	label14a:;
		cout << "\n\t\t\t Enter Pin Code : ";

		while (!(cin >> a))
		{
			if (in2 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in2 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				admininner();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in2++;
			cin.clear();
			cin.ignore(100, '\n');
		}

		geek2 << a;
		geek2 >> pin;
		geek2.clear();

		if (pin.length() == 4)
		{
			///
			bool found = false;

			while (temp->next != NULL)
			{
				if (temp->cnic == b && temp->pinno == a)
				{
					found = true;
					inneradmintransect(a, b);
					break;
				}

				temp = temp->next;
			}

			if (temp->cnic == b && temp->pinno == a && found == false)
			{
				found = true;
				//atmamount = getAtmamountfromfile();
				inneradmintransect(a, b);
			}

			if (found == false)
			{
				cout << "\n\t Sorry Such Data Not Found....";
				Sleep(1000);
				admininner();
			}

			///
		}
		else if (ou2 == 3)
		{
			cout << "\n\t Sorry Come Back Again...\n";
			ou2 = 0;
			Sleep(1000);
			admininner();
		}
		else
		{
			cout << "\n\t\t Please Enter 4 Digi Pin Code...";
			ou2++;
			Sleep(1000);
			goto label14a;
		}

	}
	else if (ou1 == 3)
	{
		cout << "\n\t\t Sorry Come Back Again...\n";
		ou1 = 0;
		Sleep(1000);
		admininner();
	}
	else
	{
		cout << "\n\t\t Please Enter 13 Digit CNIC No...\n";
		ou1++;
		Sleep(1000);
		goto label14;
	}
	}
	else
	{
	cout << "\n\t\t\t Database is Empty...\n";
	Sleep(1000);
	admininner();
	}
}

void userthroughcash() {

	if (!isEmpty())
	{
		int in1 = 0, in2 = 0;
	label41:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t Transection \n\n";
		cout << "\n\t\t\t Enter CNIC NO : ";
		long long cnic;
		stringstream geek1, geek2;
		string cn;
		bool found1 = false;
		bool found2 = false;
		while (!(cin >> cnic))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				admininner();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');
		}
		geek1 << cnic;
		geek1 >> cn;
		geek1.clear();
		if (cn.length()==13)
		{
			AccountMaking* temp1 = head;
			while (temp1->next != NULL)
			{
				if (temp1->cnic == cnic)
				{
					cout << "\n\t\t\t Account Name : " << temp1->fname << " " << temp1->lastname;
					cout << "\n\t\t\t CNIC No : " << temp1->cnic<<endl;
					found1 = true;
					int in4 = 0;
					cout << "\n\t\t\t Enter Amount Rs : ";
					long long amun;
					while (!(cin >> amun))
					{
						if (in4 == 3)
						{
							cout << "Sorry.... Come Back Again.\n";
							in4 = 0;
							Sleep(1000);
							cin.clear();
							cin.ignore(100, '\n');
							admininner();
						}
						cout << "\t\t Enter Numeric Amount Rs : ";
						in4++;
						cin.clear();
						cin.ignore(100, '\n');
					}

					ifstream read("UserProfile.txt");
					ofstream write;
					write.open("temper1.txt");
					
					
					if (read.is_open())
					{
						string a, c, d, e;
						long long b, f;
						while (!read.eof())
						{
							read >> a;
							read >> b;
							read >> c;
							read >> d;
							read >> e;
							read >> f;

							if (b == cnic)
							{
								found2 = true;
								long long newams = f + amun;
								temp1->amount = newams;
								write << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newams;

								continue;
							}
							write << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
						}

					}
					else
					{
						cout << "\n\t\t\t Error With Database...\n";
						Sleep(1000);
						admininner();
					}

					read.close();
					write.close();
					remove("UserProfile.txt");
					rename("temper1.txt", "UserProfile.txt");

				}
				
				temp1 = temp1->next;
			}
			if (temp1->cnic == cnic && found1 == false)
			{
				cout << "\n\t\t\t Account Name : " << temp1->fname << " " << temp1->lastname;
				cout << "\n\t\t\t CNIC No : " << temp1->cnic << endl;
				found1 = true;
				int in4 = 0;
				cout << "\n\t\t\t Enter Amount Rs : ";
				long long amun;
				while (!(cin >> amun))
				{
					if (in4 == 3)
					{
						cout << "Sorry.... Come Back Again.\n";
						in4 = 0;
						Sleep(1000);
						cin.clear();
						cin.ignore(100, '\n');
						admininner();
					}
					cout << "\t\t Enter Numeric Amount Rs : ";
					in4++;
					cin.clear();
					cin.ignore(100, '\n');
				}

				ifstream read("UserProfile.txt");
				ofstream write;
				write.open("temper1.txt");
				
				
				if (read.is_open())
				{	
					string a, c, d, e;
					long long b, f;
					while (!read.eof())
					{
						read >> a;
						read >> b;
						read >> c;
						read >> d;
						read >> e;
						read >> f;

						if (b == cnic)
						{
							found2 = true;
							long long newams = f + amun;
							temp1->amount = newams;
							write << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << newams;
							continue;
						}
						write << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
					}
				}
				else
				{
					cout << "\n\t\t\t Error With Database...\n";
					Sleep(1000);
					admininner();
				}

				read.close();
				write.close();
				remove("UserProfile.txt");
				rename("temper1.txt", "UserProfile.txt");
			}

			if (found2 == true)
			{
				cout << "\n\t\t\t Done....\n";
				Sleep(1000);
				admininner();
			}
			if (found1==false)
			{
				cout << "\n\t\t\t Sorry Not Found Such User...\n";
				Sleep(1000);
				admininner();
			}
			
		}
		else if (in2==3)
		{
  		    cout << "\n\t\t\t Sorry Come back again...\n";
			in2=0;
			Sleep(1000);
			admininner();
		}
		else
		{
		    cout << "\n\t\t\t Please put 13 digits CNIC No...\n";
			in2++;
			Sleep(1000);
			goto label41;
			
		}
	}
	else
	{
		cout << "\n\t\t\t Database is Empty...";
		Sleep(1000);
		admininner();
	}



}

void deletinguser() {

	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Deleting \n";
	if (!isEmpty())
	{
		int in1 = 0, in2 = 0;
	label41:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t Deleting \n";
		cout << "\n\t\t\t Enter CNIC No : ";
		long long cnic;
		bool found1 = false;
		bool found2 = false;
		while (!(cin >> cnic))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				admininner();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');
		}
		stringstream geek1, geek2;
		string cn;
		geek1 << cnic;
		geek1 >> cn;
		geek1.clear();

		if (cn.length() == 13)
		{
			int in4 = 0, in5 = 0;
		label42:;
			cout << "\n\t\t\t Enter Pin No :";
			int pin;
			string pn;
			while (!(cin >> pin))
			{
				if (in4 == 3)
				{
					cout << "Sorry.... Come Back Again.\n";
					in4 = 0;
					Sleep(1000);
					cin.clear();
					cin.ignore(100, '\n');
					admininner();
				}
				cout << "\n\t\t\t Enter Numeric Pin Code : ";
				in4++;
				cin.clear();
				cin.ignore(100, '\n');
			}
			geek2 << pin;
			geek2 >> pn;
			geek2.clear();

			if (pn.length() == 4)
			{
				AccountMaking* temp1;
				AccountMaking* temp3;
				temp1 = head;

				if (head->cnic && head->pinno == pin)
				{
					AccountMaking* temp;
					if (head->next==NULL)
					{
						ifstream read1("UserProfile.txt");
						ofstream write1;
						write1.open("temp1.txt");
						string a, aa, c, d, e;
						long long b, f;
						int p;
						stringstream gek;

						while (!read1.eof())
						{
							read1 >> a;
							read1 >> b;
							read1 >> c;
							read1 >> d;
							read1 >> e;
							read1 >> f;

							aa = a.substr(4);
							gek << aa;
							gek >> p;
							gek.clear();

							if (head->cnic == b && head->pinno == p)
							{
								found2 = true;
								continue;
							}

							write1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
						}
						write1.close();
						read1.close();
						remove("UserProfile.txt");
						rename("temp1.txt", "UserProfile.txt");

						temp = head;
						head = NULL;
						delete temp;
						found1 = true;
					}

					else
					{
						ifstream read1("UserProfile.txt");
						ofstream write1;
						write1.open("temp1.txt");
						string a, aa, c, d, e;
						long long b, f;
						int p;
						stringstream gek;

						while (!read1.eof())
						{
							read1 >> a;
							read1 >> b;
							read1 >> c;
							read1 >> d;
							read1 >> e;
							read1 >> f;

							aa = a.substr(4);
							gek << aa;
							gek >> p;
							gek.clear();

							if (head->cnic == b && head->pinno == p)
							{
								found2 = true;
								continue;
							}

							write1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
						}
						write1.close();
						read1.close();
						remove("UserProfile.txt");
						rename("temp1.txt", "UserProfile.txt");

						temp = head;
						head = temp->next;
						delete temp;
						found1 = true;
					}
				}
				
				else
				{
					while (temp1->next != NULL)
					{
						if (temp1->next->cnic == cnic && temp1->next->pinno == pin)
						{
							ifstream read1("UserProfile.txt");
							ofstream write1;
							write1.open("temp1.txt");
							string a, aa, c, d, e;
							long long b, f;
							int p;
							stringstream gek;

							while (!read1.eof())
							{
								read1 >> a;
								read1 >> b;
								read1 >> c;
								read1 >> d;
								read1 >> e;
								read1 >> f;

								aa = a.substr(4);
								gek << aa;
								gek >> p;
								gek.clear();

								if (temp1->next->cnic == b && temp1->next->pinno == p)
								{
									found2 = true;
									continue;
								}

								write1 << endl << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << f;
							}
							write1.close();
							read1.close();
							remove("UserProfile.txt");
							rename("temp1.txt", "UserProfile.txt");
							temp3 = temp1->next;
							temp1->next = temp3->next;
							delete temp3;
							found1 = true;
							continue;
						}

						temp1 = temp1->next;
					}
				}

				if (found2 == true)
				{
					cout << "\n\t\t\t Done Deleted....\n";
					Sleep(1000);
					admininner();
				}

				if (found1 == false)
				{
					cout << "\n\t\t\t Not Found Such User....\n";
					Sleep(1000);
					admininner();
				}

			}
			else if (in5 == 3)
			{
				cout << "\n\t\t\t Sorry Come Back Again...\n";
				in5 = 0;
				Sleep(1000);
				admininner();
			}
			else
			{
				cout << "\n\t\t\t Please Put 4 Digits Pin Code ...\n";
				in5++;
				Sleep(1000);
				goto label42;
			}

		}
		else if (in2 == 3)
		{
			cout << "\n\t\t\t Sorry Come Back Again...\n";
			in2 = 0;
			Sleep(1000);
			admininner();
		}
		else
		{
			cout << "\n\t\t\t Please Put 13 Digits CNIC No ...\n";
			in2++;
			Sleep(1000);
			goto label41;
		}


	}
	else
	{
		cout << "\n\t\t\t Database is Empty...\n";
		Sleep(1000);
		admininner();
	}
	
	
}

void RecordingMenu() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Record \n";
	cout << "\n\t\t\t 1 -> Back";
	cout << "\n\t\t\t 2 -> WithDrawal Record";
	cout << "\n\t\t\t 3 -> Transection Record";
	cout << "\n\t\t\t 0 -> Exit";

	char choic;
	cout << "\n\t\t\t Enter Choice : ";
	cin >> choic;
	switch (choic)
	{
	case'0': exit(0);
		break;
	case'1': DisplayMenu();
		break;
	case'2':WithdrawalRec1();
		break;
	case'3':TransectionRec1();
		break;
	default: {
		cout << "\n\t\t\t Sorry Wrong Input ...\n";
		Sleep(1000);
		RecordingMenu();
	}
		break;
	}
}

void WithdrawalRec1() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Withdrawal Record \n";
	cout << "\n\t\t\t 1 -> Back ";
	cout << "\n\t\t\t 2 -> Single Record  ";
	cout << "\n\t\t\t 3 -> All Record ";
	cout << "\n\t\t\t 0 -> Exit \n";
	cout << "\n\t\t\t Enter Choice : ";
	char choi; cin >> choi;
	switch (choi)
	{
	case'0': exit(0);
		break;
	case'1': RecordingMenu();
		break;
	case'2': {
		int in1 = 0, in2 = 0;
	label61:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t Withdrawal Record \n";
		cout << "\n\t\t\t Enter CNIC No : ";
		long long cnic;
		while (!(cin >> cnic))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				WithdrawalRec1();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');
		}

		string cn;
		stringstream geek;
		geek << cnic;
		geek >> cn;
		geek.clear();

		if (cn.length() == 13)
		{
			withdrawalsingly(cnic);
		}
		else if (in2 == 3)
		{
			in2 = 0;
			cout << "\n\t\t\t Sorry Come Back Again...\n";
			Sleep(1000);
			WithdrawalRec1();
		}
		else
		{
			cout << "\n\t\t\t Pleae Put 13 Digits CNIC No ... \n";
			in2++;
			Sleep(1000);
			goto label61;

		}
	}
		break;
	case'3': displaysingly();
		break;
	default: {
		cout << "\n\t\t\t Sorry Wrong Input ...\n";
		Sleep(1000);
		WithdrawalRec1();
	}
		break;
	}
}

void TransectionRec1() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Transection Record \n";
	cout << "\n\t\t\t 1 -> Back ";
	cout << "\n\t\t\t 2 -> Single Record  ";
	cout << "\n\t\t\t 3 -> All Record ";
	cout << "\n\t\t\t 0 -> Exit \n";
	cout << "\n\t\t\t Enter Choice : ";
	char choi; cin >> choi;
	switch (choi)
	{
	case'0': exit(0);
		break;
	case'1': RecordingMenu();
		break;
	case'2': {
		int in1 = 0, in2 = 0;
	label60:;
		system("cls");
		cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
		cout << "\n\t\t\t Transection Record \n";
		cout << "\n\t\t\t Enter CNIC No : ";
		long long cnic;
		while (!(cin >> cnic))
		{
			if (in1 == 3)
			{
				cout << "Sorry.... Come Back Again.\n";
				in1 = 0;
				Sleep(1000);
				cin.clear();
				cin.ignore(100, '\n');
				TransectionRec1();
			}
			cout << "\t\t Enter Numeric CNIC No : ";
			in1++;
			cin.clear();
			cin.ignore(100, '\n');
		}

		string cn;
		stringstream geek;
		geek << cnic;
		geek >> cn;
		geek.clear();

		if (cn.length()==13)
		{
			transectiondoubly(cnic);
		}
		else if (in2 == 3)
		{
			in2 = 0;
			cout << "\n\t\t\t Sorry Come Back Again...\n";
			Sleep(1000);
			TransectionRec1();
		}
		else
		{
			cout << "\n\t\t\t Pleae Put 13 Digits CNIC No ... \n";
			in2++;
			Sleep(1000);
			goto label60;

		}

	}
		break;
	case'3': displaydoubly();
		break;
	default: {
		cout << "\n\t\t\t Sorry Wrong Input ...\n";
		Sleep(1000);
		TransectionRec1();
	}
			 break;
	}
}

void displaysingly() {
	
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t WithDrwal Record \n\n";
	ifstream read("WithDrawalRecord.txt");

	cout << "\n______________________________________________________________________________________________________\n";
	cout << "| CNIC No\t| First Name  |  Last Name   |  Contact No |  Amount    |  Withdrawal | Duration      |\n";
	cout << "``````````````````````````````````````````````````````````````````````````````````````````````````````\n";
	string a, b, c, d, e, f, g, h;
	while (!read.eof())
	{
		read >> a;
		read >> b;
		read >> c;
		read >> d;
		read >> e;
		read >> f;
		read >> g;
		read >> h;

		cout << a << setw(10) << b << setw(15) << c << setw(15) << d << setw(15) << e << setw(10) << f << "\t  " << g << " " << h << endl;

	}
	read.close();

	cout << "\n\t\t\t 1 -> Back ";
	cout << "\n\t\t\t 0 -> Exit";
	cout << "\n\t\t\t Enter Choice : ";
	char choic;
	cin >> choic;
	switch (choic)
	{
	case'0':exit(0);
		break;
	case'1':RecordingMenu();
		break;
	default: {
		cout << "\n\t\t\t Sorry Wrong Input Please Try again....\n";
		Sleep(1000);
		displaydoubly();
	}
			 break;
	}
}

void displaydoubly() {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Transection Record \n";
	ifstream read("TransectionRecord.txt");
	cout << "\n______________________________________________________________________________________________________\n";
	cout << "| CNIC No\t| First Name  |  Last Name   |   Amount |  To CNIC No   | First Name | Duration      |\n";
	cout << "``````````````````````````````````````````````````````````````````````````````````````````````````````\n";
	string a, b, c, d, e, f, g, h;
	while (!read.eof())
	{
		read >> a;
		read >> b;
		read >> c;
		read >> d;
		read >> e;
		read >> f;
		read >> g;
		read >> h;

		cout << a << setw(10) << b << setw(20) << c << setw(10) << d << setw(20) << e << setw(10) << f<<"\t" << g << " " << h << endl;
		
	}
	read.close();
	cout << "\n\t\t\t 1 -> Back ";
	cout << "\n\t\t\t 0 -> Exit";
	cout << "\n\t\t\t Enter Choice : ";
	char choic;
	cin >> choic;
	switch (choic)
	{
	case'0':exit(0);
		break;
	case'1':RecordingMenu();
		break;
	default: {
		cout << "\n\t\t\t Sorry Wrong Input Please Try again....\n";
		Sleep(1000);
		displaydoubly();
	}
		break;
	}
}

void withdrawalsingly(long long cnic) {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Withdrawal Record \n";
	ifstream read("WithDrawalRecord.txt");

	cout << "\n______________________________________________________________________________________________________\n";
	cout << "| CNIC No\t| First Name  |  Last Name   |  Contact No |  Amount    |  Withdrawal | Duration      |\n";
	cout << "``````````````````````````````````````````````````````````````````````````````````````````````````````\n\n";

	bool found = false;
	if (read.is_open())
	{
		long long a;
		string b,c,d,e,f,g,h;
		while (!read.eof())
		{
			read >> a;
			read >> b;
			read >> c;
			read >> d;
			read >> e;
			read >> f;
			read >> g;
			read >> h;
			if (a == cnic)
			{
				found = true;
				cout << a << setw(10) << b << setw(15) << c << setw(15) << d << setw(15) << e << setw(10) << f << "\t  " << g << " " << h << endl;
			}
		}

		if (found == false)
		{
			cout << "\n\t\t\t Sorry Such User is not found...\n";
			Sleep(1000);
		}
		cout << "\n\t\t\t 1 -> Back ";
		cout << "\n\t\t\t 0 -> Exit \n";
		char ss;
		cout << "\n\t\t\tEnter Choice : ";
		cin >> ss;
		switch (ss)
		{
		case'0':exit(0);
			break;
		case'1':WithdrawalRec1();
			break;
		default:
		{
			cout << "\n\t\t\t Sorry Wrong Input...";
			Sleep(1000);
			WithdrawalRec1();
		}
			break;
		}
	}
	else
	{
		cout << "\n\t\t\t Error With File...\n";
		Sleep(1000);
	}

}

void transectiondoubly(long long cnic) {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Transection Record \n";
	ifstream read("TransectionRecord.txt");
	cout << "\n______________________________________________________________________________________________________\n";
	cout << "| CNIC No\t| First Name  |  Last Name   |   Amount |  To CNIC No   | First Name | Duration      |\n";
	cout << "``````````````````````````````````````````````````````````````````````````````````````````````````````\n\n";
	bool found = false;
	if (read.is_open())
	{
		long long a;
		string b,c,d,e,f,g,h;
		while (!read.eof())
		{
			read >> a;
			read >> b;
		    read >> c;
		    read >> d;
		    read >> e;
		    read >> f;
		    read >> g;
		    read >> h;
			if (a==cnic)
			{
				found = true;
				cout << a << setw(10) << b << setw(20) << c << setw(10) << d << setw(20) << e << setw(10) << f << "\t" << g << " " << h << endl;
			}
		}

		if (found == false)
		{
			cout << "\n\t\t\t Sorry Such User is not found...\n";
			Sleep(1000);
		}

		cout << "\n\t\t\t 1 -> Back ";
		cout << "\n\t\t\t 0 -> Exit \n";
		char ss;
		cout << "\n\t\t\tEnter Choice : ";
		cin >> ss;
		switch (ss)
		{
		case'0':exit(0);
			break;
		case'1':TransectionRec1();
			break;
		default:
		{
			cout << "\n\t\t\t Sorry Wrong Input...";
			Sleep(1000);
			TransectionRec1();
		}
		break;
		}
	}
	else
	{
		cout << "\n\t\t\t Error With File...\n";
		Sleep(1000);
	}
}

void withdrawalsingly2(int pin, long long cnic) {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Withdrawal Record \n";
	ifstream read("WithDrawalRecord.txt");

	cout << "\n______________________________________________________________________________________________________\n";
	cout << "| CNIC No\t| First Name  |  Last Name   |  Contact No |  Amount    |  Withdrawal | Duration      |\n";
	cout << "``````````````````````````````````````````````````````````````````````````````````````````````````````\n\n";

	bool found = false;
	if (read.is_open())
	{
		long long a;
		string b, c, d, e, f, g, h;
		while (!read.eof())
		{
			read >> a;
			read >> b;
			read >> c;
			read >> d;
			read >> e;
			read >> f;
			read >> g;
			read >> h;
			if (a == cnic)
			{
				found = true;
				cout << a << setw(10) << b << setw(15) << c << setw(15) << d << setw(15) << e << setw(10) << f << "\t  " << g << " " << h << endl;
			}
		}

		if (found == false)
		{
			cout << "\n\t\t\t Sorry You Haven't Withdrawal any Amount ...\n";
			Sleep(1500);
			ATMUSER(pin, cnic);
		}
		cout << "\n\t\t\t 1 -> Back ";
		cout << "\n\t\t\t 0 -> Exit \n";
		char ss;
		cout << "\n\t\t\tEnter Choice : ";
		cin >> ss;
		switch (ss)
		{
		case'0':exit(0);
			break;
		case'1':ATMUSER(pin,cnic);
			break;
		default:
		{
			cout << "\n\t\t\t Sorry Wrong Input...";
			Sleep(1000);
			ATMUSER(pin,cnic);
		}
		break;
		}
	}
	else
	{
		cout << "\n\t\t\t Error With File...\n";
		Sleep(1000);
		ATMUSER(pin, cnic);
	}

	}

void transectiondoubly2(int pin, long long cnic) {
	system("cls");
	cout << "\n\n\t\t\t Welcome To BUKC ATM \n";
	cout << "\n\t\t\t Transection Record \n";
	ifstream read("TransectionRecord.txt");
	cout << "\n______________________________________________________________________________________________________\n";
	cout << "| CNIC No\t| First Name  |  Last Name   |   Amount |  To CNIC No   | First Name | Duration      |\n";
	cout << "``````````````````````````````````````````````````````````````````````````````````````````````````````\n\n";
	bool found = false;
	if (read.is_open())
	{
		long long a;
		string b, c, d, e, f, g, h;
		while (!read.eof())
		{
			read >> a;
			read >> b;
			read >> c;
			read >> d;
			read >> e;
			read >> f;
			read >> g;
			read >> h;
			if (a == cnic)
			{
				found = true;
				cout << a << setw(10) << b << setw(20) << c << setw(10) << d << setw(20) << e << setw(10) << f << "\t" << g << " " << h << endl;
			}
		}

		if (found == false)
		{
			cout << "\n\t\t\t Sorry You Haven't Transection ...\n";
			Sleep(1500);
			ATMUSER(pin, cnic);
		}

		cout << "\n\t\t\t 1 -> Back ";
		cout << "\n\t\t\t 0 -> Exit \n";
		char ss;
		cout << "\n\t\t\tEnter Choice : ";
		cin >> ss;
		switch (ss)
		{
		case'0':exit(0);
			break;
		case'1': ATMUSER(pin, cnic);
			break;
		default:
		{
			cout << "\n\t\t\t Sorry Wrong Input...";
			Sleep(1000);
			ATMUSER(pin, cnic);
		}
		break;
		}
	}
	else
	{
		cout << "\n\t\t\t Error With File...\n";
		Sleep(1000);
		ATMUSER(pin, cnic);
	}
}

int main() {
	
	mainpage();

	system("pause");

}
