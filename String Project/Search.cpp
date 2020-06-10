#include <iostream>
#include <string>
#include <fstream>
#include "Search.h"
using namespace std;

string results[100];

void extractData(string& data)
{
	ifstream file;
	file.open("searchData.txt");
	file >> data;
	file.close();
}

string findSentence(string text,string word)
{
	int foundPosition = text.find(word);
	if (foundPosition != string::npos)
	{
		int startSentencePosition = foundPosition;
		int endSentencePosition = foundPosition;
		while (true)
		{
			if (text[startSentencePosition] == '.')
				break;
			startSentencePosition--;
		}
		while (true)
		{
			if (text[endSentencePosition] == '.')
				break;
			endSentencePosition++;
		}

		return text.substr(startSentencePosition, endSentencePosition);
	}

	return "No match";
}