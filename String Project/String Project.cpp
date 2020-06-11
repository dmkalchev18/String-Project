#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "Hangman.h"
#include "Search.h"
#include <vector>
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
	cout << endl;
}

bool mainMenu(string text,vector<string> results2) {
	int choice;

	cout << "|==========|";
	cout << "Menu choice\n";
	cout << "1. Play Hangman\n";
	cout << "2. neshto2\n";
	cout << "3. neshto3\n";
	cout << "4. neshto4\n";
	cout << "Enter your choice: ";
	choice = readInt("Enter your choice: ");

	switch (choice)
	{
		case 1:
		mainHangmanMenu();
		return true;
		case 2:
		findSentence(text,"elek",results2);
		displaySentence(results2);
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

int main()
{
	system("color 0b");

	srand(time(NULL));
	string results[100];
	vector<string> results2;
	init();
	int mistakes = 0;
	bool isRunning = true;
	string text;
	extractData(text);
	cout << text;
	
	
	do{
		isRunning = mainMenu(text,results2);
	} while(isRunning);
}