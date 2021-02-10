/*
Main File

Amy Nguyen
CS223 FALL 2020
PA 1
*/

#include "PA1.h"


int main(void) {
	srand(time(NULL));
	int gameStatus = 1, playerOption = 0;
	LinkedList commandList, profileList;
	fstream commandFile, profiles;
	commandFile.open("commands.csv");
	profiles.open("profiles.csv");

	if (!commandFile.is_open()) {
		cout << "Command File Has Failed To Open! The Program Will Now Terminate" << endl;
		return 0;
	}
	if (!profiles.is_open()) {
		cout << "Profile File Has Failled to Open! The Program Will Now Terminate" << endl;
		return 0;
	}

	while (!profiles.eof()) {
		string name; int score;
		listNode* newProfile = new listNode;
		newProfile->next = nullptr;
		getline(profiles, name, ',');
		profiles >> score;
		newProfile->name = name;
		newProfile->score = score;
		profileList.insert(newProfile);
	}
	profiles.close();
	profiles.open("profiles.csv");
	int count = 0; 
	
	//while !eof, read file and assign to the corresponding variables
	while (!commandFile.eof()) {
		string newCommand;
		string newDescription;
		listNode* newData = new listNode;
		newData->next = nullptr;

		getline(commandFile, newCommand, ',');
		getline(commandFile, newDescription,'\n');

		//skip adding the first line into the list
		if (newCommand == "Command") {
			getline(commandFile, newCommand, ',');
			getline(commandFile, newDescription, '\n');
		}
		
		newData->name = newCommand;
		newData->description = newDescription;
		//cout << newData->command << "		" << newData->description << endl;			//used to make sure command and description was reading into its correct variables
		commandList.insert(newData);

		/*count++;
		cout << count << endl;*/
	}
	/* // checks to make sure list populated properly
	cout << "list population successful.";
	commandList.printList();
	*/
	commandFile.close();	//close file bc eof makes it unable to write in file
	commandFile.open("commands.csv",ios::app); //reopen file with 'ios::app" to be able to write at the end of the file
	listNode* head = commandList.getHead();
	while (gameStatus == 1) {
		displayMainMenu();
		listNode* newData = new listNode;
		string targetCommand, targetDescription, playerName;
		int playerScore = 0;

		newData->next = nullptr;
		newData->name = targetCommand;
		newData->description = targetDescription;

		cout << endl << endl;
		playerOption = getPlayerOption();
		switch (playerOption) {

		case 1:
			cout << "--Game Rules--" << endl << endl;
			gameRules();
			cout << endl << endl << endl;
			break;

		case 2:
			cout << "--Play Game--" << endl <<endl;
			cout << "Please Enter Your Name:	";
			cin >> playerName;
			playGame(commandList,&playerName, &playerScore);
			profiles << playerName << "," << playerScore;
			break;

		case 3: {
			int playersChoice = 0, tempChoice = 0;
			cout << "--Load Previous Game--" << endl;
			cout << "Which Profile Would You Like to Use:" << endl;
			profileList.printList();
			while (playersChoice == 0) {
				cout << endl << endl << "Please Enter Your Choice:	";
				cin >> tempChoice;
				if (playersChoice <= 0 || playersChoice > profileList.countItems()) {
					cout << "You've entered an invalid option. Please try again.";
				}
				else {
					playersChoice == tempChoice;
				}

			}
			listNode* playerProfile = profileList.searchIndex(playersChoice) ;
			playerName = playerProfile->name;
			playerScore = playerProfile->score;
			playGame(commandList, &playerName, &playerScore);
			profiles << playerName << "," << playerScore;
			break;
		}

		case 4:
			cout << "--Add Command--" << endl<<endl;
			cout << "Please enter in the command you would like to add: ";
			cin >> targetCommand;
			cout << "Please enter in the discription you would like to add:\n\t";
			cin >> targetDescription;

			targetCommand = tolowercase(targetCommand);
			newData->name = targetCommand;
			newData->description = targetDescription;

			commandList.insert(newData);
			commandFile << targetCommand << "," << targetDescription <<endl;
	
			
			free(newData);
			cout << "Command has been added to list.";
			break;

		case 5:
			cout << "--Remove Command--" << endl<<endl;
			cout << "Please type in the command you wish to remove:	";
			cin >> targetCommand;
			commandList.remove(targetCommand);
			break;

		case 6:
			commandFile.close();
			profiles.close();
			cout << "Exit" << endl;
			gameStatus = 0;
			break;

		default:
			cout << "An Error Has Occured. Ending Program Now." << endl;
			gameStatus = 0;
			break;
		}
	}

	cout << "Thank You for Playing! GoodBye!" << endl;

	return 0;
}