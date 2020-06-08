#include <iostream>
#include <string>
#include <ctime>
#include "Hangman.h"
using namespace std;

int findLength(string* arr)
{
	int i = 0;
	while (arr[i] != "\0")
		i++;
	return i;
}

string gameWords[50] = { "Banana", "Airplane", "Cousin", "Tree", "Computer", "Factory", "Pilot", "Yoghurt", "Orange", "Purple", "Apartment", "Programming",
						"Remote control", "Apple", "Peach", "Telepfone", "Microphone", "Truck", "Window", "Bottle", "Tiger","Aligator","Classroom", "Mother", 
						"Door", "Table", "Keyboard", "Mouse", "Cable", "Elephant", "Classmate", "Laptop", "School", "January", "America", "Bulgaria", "China",
						"Economy","Makeup","Ruller", "Pensil", "Cartoon","Planet","Dirt", "Mousepad","Notebook","Desk",};


void availableLetterCheck()
{
	string avLetters[26] = { "A","B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T","U","V","W","X","Y","Z" };
	//int randomNum = getRandom % (max - min) + min;
}

void displayEmpty()
{
	cout << "|                                 |" << endl;
}
void displayRope()
{
	cout << "|               |                 |" << endl;
	cout << "|               |                 |" << endl;
}

void displayHead()
{
	cout << "|               O                 |" << endl;
}

void displayHangman(bool rope)
{
	cout << "+---------------------------------+" << endl;
	cout << "|             HANG MAN            |" << endl;
	cout << "+---------------------------------+" << endl;
    cout << "|                                 |"<<endl;
}

void pickRandomWord() {
	int randomIndex;
	int getRandom = rand();
	randomIndex = getRandom % findLength(gameWords);
	cout << gameWords[randomIndex];
}

/*
+---------------------------------+
|             HANG MAN            |
+---------------------------------+
|               |                 |
|               |                 |
|               O                 |
|              /|\                |
|               |                 |
|              / \                |
|         +----------+            |
|         |          |            |
+---------------------------------+
|        Available letters        |
+---------------------------------+
|     A B C D E F G H I J K L M   |
|     N O P Q R S T U V W X Y Z   |
+---------------------------------+
|         Guess the word          |
+---------------------------------+
| _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |
+---------------------------------+
*/