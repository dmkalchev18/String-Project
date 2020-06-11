#pragma once
#include <iostream>
#include <string>
using namespace std;

enum GAME_STATUS {
	RUNNING,
	HUNG,
	WON
};

string pickRandomWord();
GAME_STATUS displayHangman(int& mistakes, string word);
void init();
void mainHangmanMenu();
  