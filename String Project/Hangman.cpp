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
						"Remote control", "Apple", "Peach", "Telepfone", "Microphone", "Truck", "Window", "Bottle", "Tiger", "Aligator", "Classroom", "Mother", 
						"Door", "Table", "Keyboard", "Mouse", "Cable", "Elephant", "Classmate", "Laptop", "School", "January", "America", "Bulgaria", "China",
						"Economy", "Makeup", "Ruller", "Pensil", "Cartoon", "Planet", "Dirt", "Mousepad", "Notebook", "Desk",};

string avLetters[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

/*!!!!!!!!!!!!!DISPLAY BODY PARTS!!!!!!!!!!!!!||*/
void displayEmpty()
{
	cout << "|                                 |" << endl;
}
void displayLine()
{
	cout << "|               |                 |" << endl;
}
void displayHead()
{
	cout << "|               O                 |" << endl;
}
void displayUpperTorso() {
	cout << "|              /|\\                |" << endl;
}
void displayLegs()
{
	cout << "|              / \\                |" << endl;
}
/*!!!!!!!!!!!!!DISPLAY BODY PARTS!!!!!!!!!!!!!*/

void displayHangman(int mistakes)
{
	 
	cout << "+---------------------------------+" << endl;
	cout << "|            HANG MAN             |" << endl;
	cout << "+---------------------------------+" << endl;

	if(mistakes>=1)
		displayLine();
	else
		displayEmpty();
	if(mistakes>=2)
		displayLine();
	else
		displayEmpty();
	if(mistakes>=3)
		displayHead();
	else
		displayEmpty();
	if(mistakes>=4)
		displayUpperTorso();
	else
		displayEmpty();
	if(mistakes>=5)
		displayLine();
	else
		displayEmpty();
	if(mistakes>=6)
		displayLegs();
	else
		displayEmpty();

	cout<<"|         +----------+            |"<<endl;
	cout<<"|         |          |            |"<<endl;
	cout<<"+---------------------------------+"<<endl;
	cout<<"|        Available letters        |"<<endl;
	cout<<"+---------------------------------+"<<endl;
	cout<<"|     ";

	for(int i = 0; i < 18; i++)
	{
		cout<<avLetters[i]<<" ";
	}

	cout<<"  |"<<endl;
	cout<<"|     ";

	for(int i = 18; i < 26; i++)
	{
		cout<<avLetters[i]<<" ";
	}

	cout<<"  |"<<endl;

	cout<<"+---------------------------------+"<<endl;
	cout<<"|         Guess the word          |"<<endl;
	cout<<"+---------------------------------+"<<endl;
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