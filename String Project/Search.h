#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void extractData(string& data);
void findSentence(string text, string word, vector <string>& resultSentences);
void displaySentence(vector <string> result);
