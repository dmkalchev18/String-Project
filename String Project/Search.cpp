#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Search.h"
#include "Hangman.h"

using namespace std;

//This function is used for checking if  a certain number is in the foundPositionsArray
bool isInFoundPositions(int num, int arr[], int FoundPositionsCounter) 
{
	for (int i = 0; i < FoundPositionsCounter; i++)
	{
		if (num == arr[i])
			return true;
	}
	return false;
}

//This function opens the "searchData.txt" file and extracts all of its contents in the data string
void extractData(string& data)
{
	ifstream file;
	file.open("searchData.txt");
	while (getline(file, data))
		file >> data;
	file.close();
}

//This function opens the "searchData.txt" and puts data's value in the file, completely overriding any previous content
void rewriteData(string data)
{
	ofstream file;
	file.open("searchData.txt");
	file << data;
	file.close();
}

//This function opens the "searchData.txt" and deleted all present data in the document
void deleteData()
{
	ofstream file;
	file.open("searchData.txt");
}

//This function opens the "searchData.txt" and Appends extra information entered by the user at the end of the previous information
void addToData(string data)
{
	ofstream file;
	file.open("searchData.txt", ios::out | ios::app);
	file << " "+data;
}

//This function makes it so the text argument displayed will be around 100 chars long on each line, of course not interrupting any 
//existing data, if there happens to be any
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

//This function finds sentences, which contain a certain keyword. These sentences are later displayed via the function
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
			// getting the index of the keyword
			pos = text.find(word, index);
			if (pos != string::npos)
			{
				startPos = pos;
				endPos = pos;

				// find the left delimiter of the sentence
				while (true)
				{
					if (text[startPos] == '.' or text[startPos] == '!' or text[startPos] == '?' or startPos == 0)
						break;
					startPos--;
				}

				//find the right delimiter of the sentence
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
