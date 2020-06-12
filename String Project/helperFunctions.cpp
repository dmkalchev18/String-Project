#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "Hangman.h"
#include "Search.h"
#include "helperFunctions.h"
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

bool textMenu()
{
	string text;
	extractData(text);
	int choice;
	string word;
	string newData;
	cout << "| ===== TEXT MENU ===== |" << endl;
	cout << "1. Display current text" << endl;
	cout << "2. Write / Rewrite the text" << endl;
	cout << "3. Add information to the text" << endl;
	cout << "4. Search information in the text" << endl;
	cout << "5. Delete all information in the text" << endl;
	cout << "6. Back" << endl;
	cout << endl;
textRetry:
	cout << "Enter your choice: ";
	choice = readInt("Enter your choice: ");
	cout << endl;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << "Current Text:" << endl;
		displayFormatedText(text);
		return true;
		break;
	case 2:
		system("cls");
		cout << "Please enter the new data: " << endl;
		cin.ignore();
		getline(cin, newData);
		rewriteData(newData);
		return true;
		break;
	case 3:
		system("cls");
		cout << "Please enter the data you want to add to the existing text: " << endl;
		cin.ignore();
		getline(cin, newData);
		addToData(newData);
		return true;
		break;
	case 4:
		system("cls");
		cout << "Please enter the word you want to search in the text: ";
		cin >> word;
		cout << "\nResults: " << endl;
		findSentence(text, word);
		return true;
		break;
	case 5:
		system("cls");
		deleteData();
		cout << "Data succesfully deleted!" << endl;
		cout << endl;
		return true;
		break;
	case 6:
		return false;
		break;
	default:
		goto textRetry;
		break;
	}

}

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