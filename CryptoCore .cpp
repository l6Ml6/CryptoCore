// ==================== Start ==================== //
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int Max = 100;
// ========== Set Color Function ========== //
void setcolor(const string& colorCode) 
{
	cout << "\033[" << colorCode << "m";
}
// ========== Puase Function ========== //
void puase()
{
	setcolor("30;3");
	cout << "Please press any key to continue...";
	_getch();
}
// ========== Replace Space Function ========== //
string Respace(const string& input, char temp)
{
	string output = input;
	for (char& c : output) 
	{
		if (c == ' ') 
		{
			c = temp;
		}
	}
	return output;
}
// ========== Back Space Function ========== //
string BackSpace(const string& input, char temp)
{
	string output = input;
	for (char& c : output)
	{
		if (c == temp) 
		{
			c = ' ';
		}
	}
	return output;
}
// ========== Encryption ========== //
string encryption(string st, char& key)
{
	string pass;
	for (int i = 0; st[i]; i++)
	{
		char encrypted = (st[i] ^ key) % 94 + 33;
		//char encrypted = (st[i] ^ key);
		pass += encrypted;
	}
	return pass;
}
// ========== Multi Encryption ========== //
string Multiencryption(string st, string key)
{
	string pass;
	int length = key.length();
	int cnt = 0;
	int i = 0, j = 0;
	while (st[i])
	{
		char encrypted = (st[i] ^ key[j]) % 94 + 33;
		pass += encrypted;
		i++; j++;
		if (j == length)
		{
			j = 0;
		}
	}
	return pass;
}
// ========== Decryption ========== //
string decryption(string pass, char& key)
{
	string st;
	char temp = '|';
	for (int i = 0; pass[i]; i++)
	{
		char decrypted = ((pass[i] - 33) ^ key);
		//char decrypted = (pass[i]^ key);
		st += decrypted;
	}
	st = BackSpace(st, temp);
	return st;
}
// ========== Multi Decryption ========== //
string Multidecryption(string pass, string key)
{
	string st;
	char temp = '|';
	int length = key.length();
	int i = 0, j = 0;
	while (pass[i])
	{
		char decrypted = ((pass[i] - 33) ^ key[j]);
		st += decrypted;
		i++; j++;
		if (j == length)
		{
			j = 0;
		}
	}
	st = BackSpace(st, temp);
	return st;
}
// ========== Decryption Handler ========== //
void DecryptionHandler()
{
	string st, pass; char key;
	system("color B0");

	system("cls");
	setcolor("30");
	cout << "*:=================================== Decryption Section ===================================:*" << endl;
	setcolor("34");
	cout << "\nPlease enter the key for decryption: ";
	cin >> key;

	system("cls");
	setcolor("30");
	cout << "*:=================================== Decryption Section ===================================:*" << endl;
	setcolor("34");
	cout << "\nThis is your key:" << key;
	cout << "\n\nPlease enter the string for decryption: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, pass);

	system("cls");
	setcolor("30");
	cout << "*:=================================== Decryption Section ===================================:*" << endl;
	setcolor("34");
	cout << "\nHere's the decrypted string: " << decryption(pass, key);
	cout << "\n\nThis is your string: " << pass;
	cout << "\n\nThis is your key: " << key << endl;
	cout << endl;

	puase();
	return;
}
// ========== Multi Decryption Handler ========== //
void MultiDecryptionHandler()
{
	string st, pass, key;
	system("color B0");

	system("cls");
	setcolor("30");
	cout << "*:=================================== Decryption Section ===================================:*" << endl;
	setcolor("34");
	cout << "\nPlease enter the stirng of key for decryption: ";
	getline(cin, key);

	system("cls");
	setcolor("30");
	cout << "*:=================================== Decryption Section ===================================:*" << endl;
	setcolor("34");
	cout << "\nThis is your key:" << key;
	cout << "\n\nPlease enter the string for decryption: ";
	getline(cin, pass);

	system("cls");
	setcolor("30");
	cout << "*:=================================== Decryption Section ===================================:*" << endl;
	setcolor("34");
	cout << "\nHere's the decrypted string: " << Multidecryption(pass, key);
	cout << "\n\nThis is your string: " << pass;
	cout << "\n\nThis is your key: " << key << endl;
	cout << endl;

	puase();
	return;
}
// ========== Encryption Handler ========== //
void EncryptionHandler() 
{
	string st, pass; char key; char temp = '|';
	system("color 17");
    system("cls");

	setcolor("33");
	cout << "*:=================================== Encryption Section ===================================:*" << endl;
	setcolor("37");
	cout << "\nPlease enter the key for encryption: ";
	cin >> key;

	system("cls");
	setcolor("33");
	cout << "*:=================================== Encryption Section ===================================:*" << endl;
	setcolor("37");
	cout << "This is your key:" << key;
	cout << "\n\nPlease enter the string for encryption: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, st);
	string st2 = Respace(st, temp);

	ofstream EncData("encryption.txt");
	EncData << "This is your encryption: " << encryption(st2, key) << "\nKey: " << key << "\nString: " << st;
	EncData.close();

	system("cls");
	setcolor("33");
	cout << "*:=================================== Encryption Section ===================================:*" << endl;
	setcolor("37");
	cout << "\nHere's the encrypted string: " << encryption(st2, key);
	cout << "\n\nThis is your string:" << st << endl;
	cout << "\n\nThis your key: " << key <<endl;
	cout << endl;

	puase();
	return;
}
// ========== Multi Encryption Handler ========== //
void MultiEncryptionHandler()
{
	string st, pass, key; char temp = '|';
	system("color 17");
	system("cls");

	setcolor("33");
	cout << "*:=================================== Encryption Section ===================================:*" << endl;
	setcolor("37");
	cout << "\nPlease enter the string of key for encryption: ";
	getline(cin, key);

	system("cls");
	setcolor("33");
	cout << "*:=================================== Encryption Section ===================================:*" << endl;
	setcolor("37");
	cout << "This is your key:" << key;
	cout << "\n\nPlease enter the string for encryption: ";
	getline(cin, st);
	string st2 = Respace(st, temp);

	ofstream EncData("encryption.txt");
	EncData << "This is your encryption: " << Multiencryption(st2, key) << "\nKey: " << key << "\nString: " << st;
	EncData.close();

	system("cls");
	setcolor("33");
	cout << "*:=================================== Encryption Section ===================================:*" << endl;
	setcolor("37");
	cout << "\nHere's the encrypted string: " << Multiencryption(st2, key);
	cout << "\n\nThis is your string:" << st << endl;
	cout << "\n\nThis your key: " << key << endl;
	cout << endl;

	puase();
	return;
}
// ========== Help Menu ========== //
void HelpMenu()
{
	while (true)
	{
		system("cls");
		system("color 07");
		int choise;

		setcolor("31;3");
		cout << ":================================= Encryption & Decryotion =================================:" << endl;

		setcolor("30;0");
		setcolor("32");
		cout << "\n\t\t\t\t\t[1] Encryption";
		cout << "\n\t\t\t\t\t[2] Decryption";
		cout << "\n\t\t\t\t\t[3] Multi Encryption";
		cout << "\n\t\t\t\t\t[4] Multi Decryption";
		cout << "\n\t\t\t\t\t[0] Main Menu\n\n";

		setcolor("31");
		cout << ":===========================================================================================:" << endl;

		setcolor("36;4");
		cout << "\n\nPress a key to select an option...";
		choise = _getch();

		switch (choise)
		{
		case '0':
			return;
		case '1':
			EncryptionHandler();
			break;
		case '2':
			DecryptionHandler();
			break;
		case'3':
			MultiEncryptionHandler();
			break;
		case'4':
			MultiDecryptionHandler();
			break;
		}
	}
}
// ========== About Dev ========== //
void AboutDev()
{
	system("cls");
	system("color 70");

	setcolor("30");
	cout << "< --------------------------------------------------------------------------------------- >\n";

	setcolor("34;3");
	cout << "Hello,\n\n"
		"This program was developed by Mohammadreza in 2024 as part of my university project.\n"
		"The project focuses on encryption and decryption techniques, aiming to explore and implement\n"
		"various cryptographic algorithms to ensure data security and privacy.\n\n"
		"This project is supervised by Dr. Reza Shamsaei,\n"
		"and is part of the curriculum for the Computer Engineering program.\n\n"
		"The goal of this project is to deepen my understanding of cryptography and its applications,\n"
		"as well as to contribute to the field of secure communication systems.\n\n"
		"Thank you for using this program!\n\n";
	setcolor("30");
	cout << "<< -------------------------------------------------------------------------------------- >>\n";

	setcolor("31;1");
	cout << "About Me:\n\n";

	setcolor("35");
	cout << "Dev: Mohammadreza\n";
	cout << "Email: twimmati@gmail.com\n";
	cout << "Telegram: @l6Ml6\n\n";

	puase();
	return;
}

// ========== Menu ========== //
void Menu()
{
	int choise;
	while (true)
	{
		system("cls");
		system("color F0");

		setcolor("31");
		cout << "\t << :===========================================================================: >>" << endl;

		setcolor("34");
		cout << "\t\tEncryption & Decryption [1]";
		cout << "\t About Dev [2]";
		cout << "\t\t Exit [0] \n";

		setcolor("31");
		cout << "\t << :===========================================================================: >>" << "\n\n";

		setcolor("30;3");
		cout << "Please enter a key to continue...";
		choise = _getch();

		switch (choise)
		{
		case '0':
			return;
		case '1':
			HelpMenu();
			break;
		case '2':
			AboutDev();
			break;
		}
	}
}
// ========== Main Function ========== //
int main()
{
	Menu();
	exit(0);
}
// ==================== End ==================== //