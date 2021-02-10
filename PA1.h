#ifndef PA1_H
#define PA1_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <time.h>
#include "list.h"

using namespace std;


void displayMainMenu(void);
int getPlayerOption(void);
void gameRules(void);
string tolowercase(string target);


void playGame(LinkedList& commandList, string *playerName, int *playerScore);

/*Attempt grave yard*/
//string getRandomDescription(LinkedList& commandList);
//void playGame(listNode* root, string playerName);
/*
void previousGame(listNode* profileRoot, listNode* commandRoot);

*/




#endif