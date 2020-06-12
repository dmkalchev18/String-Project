#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include "Hangman.h"
#include "Search.h"
#include "helperFunctions.h"
#include <vector>
using namespace std;

int main()
{
	system("color 0b");

	srand(time(NULL));
	string results[100];
	init();
	int mistakes = 0;
	bool isRunning = true;
	
	do{
		isRunning = mainMenu();
	} while(isRunning);
}