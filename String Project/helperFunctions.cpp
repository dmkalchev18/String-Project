#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "Hangman.h"
#include "Search.h"
#include "helperFunctions.h"
#include <vector>
using namespace std;

//readInt is used to make sure the user enters only int numbers, not letters
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

//This is the main menu for the the text operations and commands
bool textMenu()
{
	string text;
	extractData(text);
	int choice;
	string word;
	string newData;
	cout << "| ===== TEXT MENU ===== |" << endl;
	cout << "1. Display current text" << endl;
	cout << "2. Rewrite the text" << endl;
	cout << "3. Add information to the text" << endl;
	cout << "4. Search information in the text" << endl;
	cout << "5. Delete all information in the text" << endl;
	cout << "6. Back" << endl;
	cout << endl;
	cout << "Enter your choice: ";
	choice = readInt("Enter your choice: ");
	cout << endl;
	system("cls");
	switch (choice)
	{
	case 1:		
		cout << "Current Text:" << endl;
		displayFormatedText(text);
		return true;
	case 2:
		cout << "Please enter the new data: " << endl;
		cin.ignore();
		getline(cin, newData);
		rewriteData(newData);
		return true;
	case 3:
		cout << "Please enter the data you want to add to the existing text: " << endl;
		cin.ignore();
		getline(cin, newData);
		addToData(newData);
		return true;
	case 4:
		cout << "Please enter the word you want to search in the text: ";
		cin >> word;
		cout << "\nResults: " << endl;
		findSentence(text, word);
		return true;
	case 5:
		deleteData();
		cout << "Data succesfully deleted!" << endl;
		cout << endl;
		return true;
	case 6:
		return false;
	default:
		break;
	}

}

//This is the main menu function, which grants access to all the other functions
bool mainMenu() {
	int choice;
	string word;
	bool isRunningTextMenu = false;
	cout << "| ===== MAIN MENU ===== |" << endl;
	cout << "1. Play Hangman\n";
	cout << "2. Text Menu\n";
	cout << "3. Exit\n";
	cout << endl;
	cout << "Enter your choice: ";
	choice = readInt("Enter your choice: ");
	cout << endl;
	switch (choice)
	{
	case 1:
		mainHangmanMenu();
		return true;
	case 2:
		do
		{
			isRunningTextMenu = textMenu();
		} while (isRunningTextMenu);
		return true;
	case 3:
		cout << "Goodbye!" << endl;
		return false;
	default:
		break;
	}
}