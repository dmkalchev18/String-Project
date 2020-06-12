#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Search.h"
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
	int pos;
	int index = 0;
	int startPos, endPos;
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
			
			for (int i = startPos+2; i <= endPos; i++)
			{
				cout << text[i];
			}
			cout << endl;
			index = endPos + 1;
		}
	} while (pos != string::npos);
	cout << endl;
}
