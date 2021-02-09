#include "PA1.h"
using namespace std;
void displayMainMenu(void) {
	cout << endl<<"--MAIN MENU--" << endl;
	cout << "1. Game Rules" << endl;
	cout << "2. Play Game" << endl;
	cout << "3. Load Previous" << endl;
	cout << "4. Add Command" << endl;
	cout << "5. Remove Command" << endl;
	cout << "6. Exit" << endl;
}
int getPlayerOption(void) {
	int choice_current = 0, choice_player = 0;
	while (choice_current == 0) {
		cout << "Please Enter Your Choice:  ";
		cin >> choice_player;
		if (choice_player < 0 || choice_player > 6) {
			cout << "You've Entered an Invalid Choice" << endl;
			choice_player = 0;
		}
		else {
			choice_current = choice_player;
		}
	}

	return choice_current;
}
void gameRules(void) {
	cout << " You will be presented with a Linux Command \n and 3 command descriptions. You need to match the command \n to the correct description. 2 points will be awarded for \n every correct answeer and 1 point will be lost for incorrect answer." << endl;
}

string tolowercase(string target)
{
	string lowerTarget;

	for (int i = 0; i < target.length(); i++) {
		
		char targetCurrent = tolower(target.at(i));

		lowerTarget += targetCurrent;
	}

	return lowerTarget;
}

void playGame(LinkedList &commandList,string *playerName, int *playerScore)
{

	int gameStatus = 0;	// 0 -> game will continue, 1 -> game will end, player will be taken back in the main menu
	while (gameStatus != 1) {
		int playerAnswer = 0, correctAnswer = 0;
		cout << "Player:  " << playerName << "		Score:	" << playerScore << endl << endl;
		listNode* command = commandList.randomCommandandDesc();
		string descArray[3];

		// put descriptions into array and then shuffle, keep track of where correct answer ends up
		descArray[0] = command->description;
		descArray[1] = commandList.randoDesc();
		descArray[2] = commandList.randoDesc();

		random_shuffle(descArray[0], descArray[2]);

		cout << "Command:	" << command->name <<endl;
		for (int i = 0; i < 3; i++) {
			if (descArray[i] == command->description) {
				correctAnswer = i;
			}
			cout << i + 1 << ".	" << descArray[i] << endl;
		}
		cout << "Please enter in the option with the correct description for the command:	";
		cin >> playerAnswer;
		if (playerAnswer == correctAnswer) {
			cout << "You've chose the correct answer!";
			*playerScore++;
		}
		else
			cout << "You've chosen an incorrect answer." << endl << endl;

		cout << "Do you wish to continue the game?		"<< endl << "Enter 0 to continue the game." << endl << "Enter 1 to end the game." << endl << endl << "Your Choice:	";
		cin >> gameStatus;
		while (gameStatus < 0 || gameStatus > 1) {
			cout << "You have not enter a valid option." << endl << endl;
			cout << "Do you wish to continue the game?		" << endl << "Enter 0 to continue the game." << endl << "Enter 1 to end the game." << endl << endl << "Your Choice:	";
			cin >> gameStatus;
		}

		if (gameStatus == 1)
			cout << "Thank you for playing. You will now be taken to the main menu." << endl << endl;
	}
}

void removeCommand(listNode* commandRoot, string targetCommand)
{
	string current = commandRoot->name;
	listNode* temp = new listNode;
	temp = commandRoot;
	while (current != targetCommand) {
		temp = temp->next;
		current = temp->name;
	}

}
