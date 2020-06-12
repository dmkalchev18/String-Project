#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Search.h"
#include "Hangman.h"

using namespace std;

string results[100];

bool isInFoundPositions(int num, int arr[], int FoundPositionsCounter)
{
	for (int i = 0; i < FoundPositionsCounter; i++)
	{
		if (num == arr[i])
			return true;
	}
	return false;
}

void extractData(string& data)
{
	ifstream file;
	file.open("searchData.txt");
	while (getline(file, data))
		file >> data;
	file.close();

}

void rewriteData(string data)
{
	ofstream file;
	file.open("searchData.txt");
	file << data;
	file.close();
}

void deleteData()
{
	ofstream file;
	file.open("searchData.txt");
}

void addToData(string data)
{
	ofstream file;
	file.open("searchData.txt", ios::out | ios::app);
	file << " "+data;
}

void displayFormatedText(string text)
{
	int lineCount = text.size()/100;
	int pos;
	for (int i = 0; i <= lineCount; i++)
	{
		pos = i * 100;
		while (text[pos] != ' ' and pos!=0)
		{
			pos++;
		}
		if(pos!=0)
			text[pos] = '\n';
	}
	if (text.size() != 0)
	{
		for (size_t i = 0; i < text.size(); i++)
		{
			cout << text[i];
		}
	}
	else
		cout << "No results found!";
	cout << endl;
	cout << endl;
}



int getPositionsOfFoundSentences(int* arr, string text, string toFind)
{
	int i = 0;
	size_t foundPos = -1;
	while (true)
	{
		foundPos = text.find(toFind, foundPos + 1);
		if (foundPos != string::npos)
			arr[i++] = foundPos;
		else
			break;
	}
	return i;
}

void findSentence(string text, string word)
{
	string realText = text;
	int index = 0;
	int startPos, endPos;
	text = stringToLower(text);
	word = stringToLower(word);
	int pos = text.find(word);
	if (pos != string::npos)
	{
		do
		{
			pos = text.find(word, index);
			if (pos != string::npos)
			{
				startPos = pos;
				endPos = pos;

				while (true)
				{
					if (text[startPos] == '.' or text[startPos] == '!' or text[startPos] == '?' or startPos == 0)
						break;
					startPos--;
				}
				while (true)
				{
					if (text[endPos] == '.' or text[endPos] == '!' or text[endPos] == '?')
						break;
					endPos++;
				}
				if (startPos == 0)
				{
					for (int i = startPos; i <= endPos; i++)
					{
						cout << realText[i];
					}
				}
				else
				{
					for (int i = startPos + 2; i <= endPos; i++)
					{
						cout << realText[i];
					}
				}
				cout << endl;
				index = endPos + 1;
			}
		} while (pos != string::npos);
	}
	else
		cout << "No results found!" << endl;
	cout << endl;
}
