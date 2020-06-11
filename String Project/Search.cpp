#include <iostream>
#include <string>
#include <fstream>
#include "Search.h"
using namespace std;

string results[100];

bool isInFoundPositions(int num,int arr[],int FoundPositionsCounter)
{
	for(int i=0;i<FoundPositionsCounter;i++)
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

int getPositionsOfFoundSentences(int* arr,string text,string toFind)
{
  int i=0;
  int foundPos=-1;
  while(true)
  {
    foundPos=text.find(toFind,foundPos+1);
    if(foundPos!=string::npos)
      arr[i++] = foundPos;
    else
      break;
  }
  return i;
}

void findSentence(string text, string word,string* resultSentences)
{
	int foundPositions[100];
	int positionCounter = getPositionsOfFoundSentences(foundPositions,text,word);
	int foundPosition = text.find(word);

	if (foundPositions[0] != string::npos)
	{
		for (int i = 0; i < positionCounter; i++)
		{
			int startSentencePosition = foundPositions[i];
			int endSentencePosition = foundPositions[i];
			while (true)
			{
				if (text[startSentencePosition] == '.' or text[startSentencePosition] == '!' or text[startSentencePosition] == '?' or startSentencePosition == 0)
					break;
				startSentencePosition--;
			}
			while (true)
			{
				if (text[endSentencePosition] == '.' or text[endSentencePosition] == '!' or text[endSentencePosition] == '?')
					break;				
				endSentencePosition++;
			}

			if (startSentencePosition == 0)
				resultSentences[i] = text.substr(startSentencePosition, endSentencePosition);
			else
				resultSentences[i] = text.substr(startSentencePosition + 2, endSentencePosition);
			/*return text.substr(startSentencePosition + 2, endSentencePosition);*/
		}

	}
	else
		cout << "No match";
}

void displaySentence(string *result) {
	for (int i = 0; i < result->size(); i++)
	{
		cout << result[i] << endl;
	}
}