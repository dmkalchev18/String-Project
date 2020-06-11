#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Hangman.h"
using namespace std;

vector<string> gameWords;
vector<char> avLetters;
vector<string> hangLines;
string usedLetters;
char correctLetters[26];
int correctLettersCounter = 0, usedLettersCounter = 0;

void initGameWord() {
	//int v1 = rand() % 100;
	gameWords.push_back("Banana");
	gameWords.push_back("Airplane");
	gameWords.push_back("Cousin");
	gameWords.push_back("Tree");
	gameWords.push_back("Computer");
	gameWords.push_back("Factory");
	gameWords.push_back("Pilot");
	gameWords.push_back("Yoghurt");
	gameWords.push_back("Orange");
	gameWords.push_back("Purple");
	gameWords.push_back("Apartment");
	gameWords.push_back("Programming");
	gameWords.push_back("Apple");
	gameWords.push_back("Peach");
	gameWords.push_back("Telephone");
	gameWords.push_back("Microphone");
	gameWords.push_back("Truck");
	gameWords.push_back("Window");
	gameWords.push_back("Bottle");
	gameWords.push_back("Tiger");
	gameWords.push_back("Aligator");
	gameWords.push_back("Classroom");
	gameWords.push_back("Mother");
	gameWords.push_back("Door");
	gameWords.push_back("Table");
	gameWords.push_back("Keyboard");
	gameWords.push_back("Mouse");
	gameWords.push_back("Cable");
	gameWords.push_back("Elephant");
	gameWords.push_back("Classmate");
	gameWords.push_back("Laptop");
	gameWords.push_back("School");
	gameWords.push_back("January");
	gameWords.push_back("America");
	gameWords.push_back("Bulgaria");
	gameWords.push_back("China");
	gameWords.push_back("Economy");
	gameWords.push_back("Makeup");
	gameWords.push_back("Ruller");
	gameWords.push_back("Pensil");
	gameWords.push_back("Cartoon");
	gameWords.push_back("Planet");
	gameWords.push_back("Dirt");
	gameWords.push_back("Mousepad");
	gameWords.push_back("Notebook");
	gameWords.push_back("Desk");
}

void clearVariables() {
	for (int i = 0; i < 26; i++)
	{
		correctLetters[i] = '\0';
	}

	usedLetters = "";
	correctLettersCounter = 0;
	usedLettersCounter = 0;
}

void initAvLetters() {
	for (char i = 'A'; i <= 'Z'; i++)
	{
		avLetters.push_back(i);
	}
}

void initHangLines() {
	hangLines.push_back("|               |                 |");
	hangLines.push_back("|               |                 |");
	hangLines.push_back("|               O                 |");
	hangLines.push_back("|              /|\\                |");
	hangLines.push_back("|               |                 |");
	hangLines.push_back("|              / \\                |");
}

void init() {
	initGameWord();
	initAvLetters();
	initHangLines();

}

string pickRandomWord() {
	int randomIndex;
	int getRandom = rand();
	randomIndex = getRandom % gameWords.size();
	return gameWords[randomIndex];
}

bool checkLetters(string word, char userChoice) {
	for (int i = 0; i < word.size(); i++)
	{
		if (userChoice == tolower(word[i]))
			return true;
	}
	return false;
}

void deleteLetters(char userChoice)
{
	for (int i = 0; i < avLetters.size(); i++)
	{
		if (tolower(avLetters[i]) == userChoice)
		{
			avLetters[i] = ' ';
			break;
		}
	}
}

bool displayLettersInWord(string word)
{
	int counter = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if (usedLetters.find(word[i]) != string::npos) {
			cout << word[i] << " ";
			counter++;
		}
		else
			cout << "_ ";
	}

	return (counter == word.length());

}

string stringTolower(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

void mainHangmanMenu() {
	int mistakes = 0;
	bool isWordGuessed = false;

	GAME_STATUS gs;

	string word = pickRandomWord();

	do {
		gs = displayHangman(mistakes, word);

		if (gs == GAME_STATUS::HUNG) {
			cout << "You lose!\nThe correct word was: " << word;
			clearVariables();
		}
		else if (gs == GAME_STATUS::WON)
			cout << "You win!";

	} while (gs == GAME_STATUS::RUNNING);

}

bool isLetterRepeated(char userChoice)
{
	return usedLetters.find(userChoice) != string::npos;
}

string getGuessedLetter(string word, char letters[])
{
	for (size_t i = 0; i < word.length(); i++)
	{
		if (word[i] == ' ')
			return "  ";
		for (int j = 0; j < word.length(); j++)
		{
			if (word[i] == letters[j])
				return letters[j] + " ";
		}
	}
	return "_ ";
}

GAME_STATUS displayHangman(int& mistakes, string word)
{
	int padLenght = (34 - (word.length() * 2 - 1)) / 2;
	bool isGameOver = false;
	bool isHung = false;
	bool isRepeated = false;
	char userChoice;


	word = stringTolower(word);
	system("cls");
	cout << "+---------------------------------+" << endl;
	cout << "|            HANG MAN             |" << endl;
	cout << "+---------------------------------+" << endl;

	for (int i = 0; i < 6; i++)
	{
		if (i < mistakes)
		{
			cout << hangLines[i] << endl;
		}
		else
		{
			cout << "|                                 |" << endl;
		}
	}

	cout << "|         +----------+            |" << endl;
	cout << "|         |          |            |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|        Available letters        |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|     ";

	for (int i = 0; i < 13; i++)
	{
		cout << avLetters[i] << " ";
	}

	cout << "  |" << endl;
	cout << "|     ";

	for (int i = 13; i < 26; i++)
	{
		cout << avLetters[i] << " ";
	}

	cout << "  |" << endl;

	cout << "+---------------------------------+" << endl;
	cout << "|         Guess the word          |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "|";

	for (int i = 0; i < padLenght; i++)
	{
		cout << " ";
	}

	isGameOver = displayLettersInWord(word);
	isHung = mistakes == 6;

	for (int i = 0; i < padLenght - 1; i++)
	{
		cout << " ";
	}

	cout << "|" << endl;
	cout << "+---------------------------------+" << endl;

	if (isGameOver)
	{
		return GAME_STATUS::WON;
	}
	else if (isHung)
	{
		return GAME_STATUS::HUNG;
	}

	do
	{
		cout << "Enter a letter: ";

		cin >> userChoice;
		userChoice = tolower(userChoice);
		isRepeated = isLetterRepeated(userChoice);
		if (isRepeated)
			cout << "\nYou have already used this letter!\nPlese try again!\n";

	} while (isRepeated);

	usedLetters += userChoice;
	if (checkLetters(word, userChoice))
	{
		correctLetters[correctLettersCounter++] = userChoice;
	}
	else
		mistakes++;

	deleteLetters(userChoice);

	//usedLetters[usedLettersCounter++] = userChoice;
	cout << mistakes;
	return GAME_STATUS::RUNNING;
}