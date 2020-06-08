#include <iostream>
#include <string>
#include <Windows.h>
#include  <ctime>
#include "Hangman.h"
using namespace std;

int readInt(string s)
{
	int a;
	// Constantly make the user enter new input if the result is of type string
	while (!(cin >> a))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Incorrect value, try again!" << endl;
		// The argument "s" as the specific message, example: "Day: ", "Month: " 
		cout << s; 
	}
	return a;
}

void greetings() {
	cout << "Hello my friend\n";
	cout << "Welcome to our shitty bugged program called besenica";
    cout<<endl;
}

bool mainMenu() {
	int choice;

	cout << "|==========|";
	cout << "Menu choice\n";
	cout << "1. neshto1\n";
	cout << "2. neshto2\n";
	cout << "3. neshto3\n";
	cout << "4. neshto4\n";
	cout << "Enter your choice: ";
	choice = readInt("Enter your choice: ");

		
	switch (choice)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			return false;
			break;
	}
}

void hangman() {
}

int main()
{
	SetConsoleOutputCP(1251);
	system("color 0b");
	srand(time(NULL));
	//greetings();
	bool isRunning = true;
	displayHangman(6);
	//pickRandomWord();
	/*do{
		isRunning = mainMenu();
	} while(isRunning);*/
}