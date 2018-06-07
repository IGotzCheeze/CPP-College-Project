#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string formatStats(string,string,string,string,string,string);

class menu {

private:
	int HP;
	int MP;
	int Attack;
	int Agility;
	int Armor;
	int Will;
	string charName;
	string charRace;
	string charClass;

public:
	int choice;
	int counter = 1;
	bool menuOn = true;
	string stringUserInput;
	string nameAr[4];
	string classAr[4];
	string raceAr[4];
	string statsAr[4];

	menu() {
	}

	void setName(string name) {

		charName = name;

	}

	void setRace(string race) {

		charRace = race;

	}

	void setClass(string Class) {

		charClass = Class;

	}
	//Changed the couts to just return the string
	string getName() {

		return charName;

	}

	string getRace() {

		return charRace;

	}

	string getClass() {

		return charClass;

	}

	void mainMenu() {

		do {

			cout << "CHARACTER CREATOR\n*************************\n";
			cout << "1. New Character\n";
			cout << "2. View Character\n";
			cout << "3. Import Character\n";
			cout << "4. Export Character\n";
			cout << "5. Exit\n";
			cout << "Please enter an option: ";
			cin >> choice;

			switch (choice)
			{
			default: "\nPlease enter a valid statement\n";
				break;
			case 1: HP = 10;
				MP = 10;
				Attack = 10;
				Agility = 10;
				Armor = 10;
				Will = 10; 
				newCharacter();
				menuOn = false;
				break;
			case 2: viewCharacters();
				menuOn = false;
				break;
			case 3: importCharacters();
				menuOn = false;
				break;
			case 4: exportCharacters();
				menuOn = false;
				break;
			case 5: cout << "\nGood bye!\n\n";
				menuOn = false;
				break;
			}

		} while (menuOn);

	}
	void viewCharacters() {

		do {
			cout << "\nCHARACTER SELECT\n*************************";
			cout << "\n1. " << nameAr[0];
			cout << "\n2. " << nameAr[1];
			cout << "\n3. " << nameAr[2];
			cout << "\n4. " << nameAr[3];
			cout << "\n5. Exit\n";
			cout << "Input your selection: ";
			cin >> choice;

			switch (choice)
			{
			default: "\nPlease enter a valid statement\n";
				break;
			case 1: 
				cout << "\nName: " << *nameAr;
				cout << "\nRace: " << *raceAr;
				cout << "\nClass: " << *classAr;
				cout << "\n" << statsAr[0] << "\n";
				menuOn = true;
				break;
			case 2:
				cout << "\nName: " << nameAr[1];
				cout << "\nRace: " << raceAr[1];
				cout << "\nClass: " << classAr[1];
				cout << "\n" << statsAr[1] << "\n";
				menuOn = true;
				break;
			case 3:
				cout << "\nName: " << nameAr[2];
				cout << "\nRace: " << raceAr[2];
				cout << "\nClass: " << classAr[2];
				cout << "\n" << statsAr[2] << "\n";
				menuOn = true;
				break;
			case 4:
				cout << "\nName: " << nameAr[3];
				cout << "\nRace: " << raceAr[3];
				cout << "\nClass: " << classAr[3];
				cout << "\n" << statsAr[3] << "\n";
				menuOn = true;
				break;
			case 5: 
				cout << "\nLoading Main Menu...\n\n";
				mainMenu();
				menuOn = false;
				break;
			}

		} while (menuOn);
	}

	void importCharacters() {
		ifstream dataIn;

		dataIn.open("characters.dat");
		if(!dataIn) {
			cout << "No Characters to import.\n";
			mainMenu();
		}
		else {
			cout << "\nCharacter Imported!\n\n";
			if(counter == 1) {
				for (int i = 0; i < counter; i++) {
					string statsAcc = "";
					string statsNew;
					dataIn >> nameAr[i];
					dataIn >> raceAr[i];
					dataIn >> classAr[i];
					for (int coun = 1; coun <= 12; coun++) {
						dataIn >> statsNew;
						statsNew += " ";
						if (coun % 2 == 0)
							statsNew += "\n";
						statsAcc += statsNew;
					}
					statsAr[i] = statsAcc;
				}
			}
			else {
				for (int i = 0; i < counter - 1; i++) {
					string statsAcc = "";
					string statsNew;
					dataIn >> nameAr[i];
					dataIn >> raceAr[i];
					dataIn >> classAr[i];
					for (int coun = 1; coun <= 12; coun++) {
						dataIn >> statsNew;
						if (coun % 2 == 0)
							statsNew += "\n";
						statsNew += " ";
						statsAcc += statsNew;
					}
					statsAr[i] = statsAcc;
				}
			}
			dataIn.close();
			mainMenu();
		}
	}

	void exportCharacters() {
		ofstream dataOut;

		dataOut.open("characters.dat");

		for (int i = 0; i < counter - 1; i++) {
			dataOut << nameAr[i] << " ";
			dataOut << raceAr[i] << " ";
			dataOut << classAr[i] << " ";
			dataOut << statsAr[i] << " ";
		}
		dataOut.close();
		cout << "\nCharacter Exported!\n\n";
		mainMenu();
	}
	void newCharacter() {
		
		cout << "\nNEW CHARACTER\n*************************";

		do {

			cout << "\n1. Character Name\n";
			cout << "2. Characters Race\n";
			cout << "3. Character Class\n";
			cout << "4. Back to main menu\n";
			cout << "Please enter an option: ";
			cin >> choice;

			switch (choice)
			{
			default: "Please enter a valid statement\n";
				break;
			case 1: cout << "Character name: ";
				cin.ignore();
				getline(cin, stringUserInput);
				setName(stringUserInput);
				menuOn = true;
				break;
			case 2: 
				charRaceList();
				menuOn = true;
				break;
			case 3:
				charClassList();
				menuOn = true;
				break;
			case 4: cout << "\nLoading Main Menu...\n\n";
				string HPs = to_string(HP);
				string MPs = to_string(MP);
				string Attacks = to_string(Attack);
				string Agilitys = to_string(Agility);
				string Armors = to_string(Armor);
				string Wills = to_string(Will);
				string stats = formatStats(HPs, MPs, Attacks, Agilitys, Armors, Wills);
				switch(counter) {
				case 1:
					nameAr[0] = getName();
					classAr[0] = getClass();
					raceAr[0] = getRace();
					statsAr[0] = stats;
					counter++;
					break;
				case 2:
					nameAr[1] = getName();
					classAr[1] = getClass();
					raceAr[1] = getRace();
					statsAr[1] = stats;
					counter++;
					break;
				case 3:
					nameAr[2] = getName();
					classAr[2] = getClass();
					raceAr[2] = getRace();
					statsAr[2] = stats;
					counter++;
					break;
				case 4:
					nameAr[3] = getName();
					classAr[3] = getClass();
					raceAr[3] = getRace();
					statsAr[3] = stats;
					counter++;
					break;
				default:
					cout << "Character could not be saved, max limit reached.\n\n";
					break;
				}
				mainMenu();
				menuOn = false;
				break;

			}

		} while (menuOn);
	}

	void charRaceList() {

		cout << "\nRACE SELECTION\n*************************";

		do {

			cout << "\n1. Human\n";
			cout << "2. Dwarf\n";
			cout << "3. Elf\n";
			cout << "4. Orc\n";
			cout << "5. Goblin\n";
			cout << "6. Exit\n";
			cout << "Please enter an option: ";
			cin >> choice;

			switch (choice)
			{
			default: "Please enter a valid statement\n";
				menuOn = true;
				break;
			case 1:
				setRace("Human");
				HP += 1;
				MP += 1;
				Attack += 1;
				Agility += 1;
				Armor += 1;
				Will += 1;
				menuOn = false;
				break;
			case 2:
				setRace("Dwarf");
				HP += 4;
				MP -= 2;
				Attack += 5;
				Agility -= 4;
				Armor += 3;
				Will;
				menuOn = false;
				break;
			case 3:
				setRace("Elf");
				HP -= 2;
				MP += 3;
				Attack -= 3;
				Agility += 5;
				Armor;
				Will += 3;
				menuOn = false;
				break;
			case 4:
				setRace("Orc");
				HP += 3;
				MP += 1;
				Attack += 4;
				Agility -= 3;
				Armor += 3;
				Will -= 2;
				menuOn = false;
				break;
			case 5:
				setRace("Goblin");
				HP -= 3;
				MP += 2;
				Attack += 1;
				Agility += 3;
				Armor += 1;
				Will += 2;
				menuOn = false;
				break;
			case 6: cout << "\nLoading Main Menu...\n\n";
				mainMenu();
				menuOn = false;
				break;

			}

		} while (menuOn);
	}
	void charClassList() {

		cout << "\nCLASS SELECTION\n*************************";

		if (getRace() == "Human") {
			do {

				cout << "\n1. Attack Type: Warrior\n";
				cout << "2. Magic Type: Magician\n";
				cout << "3. Speed Type: Archer\n";
				cout << "4. Healer Type: Priest\n";
				cout << "5. Exit\n";
				cout << "Please enter an option: ";
				cin >> choice;

				switch (choice)
				{
				default: "Please enter a valid statement\n";
					menuOn = true;
					break;
				case 1:
					setClass("Warrior");
					HP += 4;
					MP += 1;
					Attack += 5;
					Agility += 2;
					Armor += 3;
					Will += 0;
					menuOn = false;
					break;
				case 2:
					setClass("Magician");
					HP += 2;
					MP += 5;
					Attack += 0;
					Agility += 3;
					Armor += 1;
					Will += 4;
					menuOn = false;
					break;
				case 3:
					setClass("Archer");
					HP += 3;
					MP += 2;
					Attack += 4;
					Agility += 5;
					Armor += 0;
					Will += 1;
					menuOn = false;
					break;
				case 4:
					setClass("Priest");
					HP += 4;
					MP += 3;
					Attack += 0;
					Agility += 1;
					Armor += 2;
					Will += 5;
					menuOn = false;
					break;
				case 5: cout << "\nLoading Main Menu...\n\n";
					mainMenu();
					menuOn = false;
					break;

				}

			} while (menuOn);
		}
		else if (getRace() == "Dwarf") {
			do {

				cout << "\n1. Attack Type: Berserker\n";
				cout << "2. Magic Type: Mage\n";
				cout << "3. Speed Type: Scout\n";
				cout << "4. Healer Type: Cleric\n";
				cout << "5. Exit\n";
				cout << "Please enter an option: ";
				cin >> choice;

				switch (choice)
				{
				default: "Please enter a valid statement\n";
					menuOn = true;
					break;
				case 1:
					setClass("Berserker");
					HP += 4;
					MP += 1;
					Attack += 5;
					Agility += 2;
					Armor += 3;
					Will += 0;
					menuOn = false;
					break;
				case 2:
					setClass("Mage");
					HP += 2;
					MP += 5;
					Attack += 0;
					Agility += 3;
					Armor += 1;
					Will += 4;
					menuOn = false;
					break;
				case 3:
					setClass("Scout");
					HP += 3;
					MP += 2;
					Attack += 4;
					Agility += 5;
					Armor += 0;
					Will += 1;
					menuOn = false;
					break;
				case 4:
					setClass("Cleric");
					HP += 4;
					MP += 3;
					Attack += 0;
					Agility += 1;
					Armor += 2;
					Will += 5;
					menuOn = false;
					break;
				case 5: cout << "\nLoading Main Menu...\n\n";
					mainMenu();
					menuOn = false;
					break;

				}

			} while (menuOn);
		}
		else if (getRace() == "Elf") {
			do {

				cout << "\n1. Attack Type: Paladin\n";
				cout << "2. Magic Type: Wizard\n";
				cout << "3. Speed Type: Rogue\n";
				cout << "4. Healer Type: Druid\n";
				cout << "5. Exit\n";
				cout << "Please enter an option: ";
				cin >> choice;

				switch (choice)
				{
				default: "Please enter a valid statement\n";
					menuOn = true;
					break;
				case 1:
					setClass("Paladin");
					HP += 4;
					MP += 1;
					Attack += 5;
					Agility += 2;
					Armor += 3;
					Will += 0;
					menuOn = false;
					break;
				case 2:
					setClass("Wizard");
					HP += 2;
					MP += 5;
					Attack += 0;
					Agility += 3;
					Armor += 1;
					Will += 4;
					menuOn = false;
					break;
				case 3:
					setClass("Rogue");
					HP += 3;
					MP += 2;
					Attack += 4;
					Agility += 5;
					Armor += 0;
					Will += 1;
					menuOn = false;
					break;
				case 4:
					setClass("Druid");
					HP += 4;
					MP += 3;
					Attack += 0;
					Agility += 1;
					Armor += 2;
					Will += 5;
					menuOn = false;
					break;
				case 5: cout << "\nLoading Main Menu...\n\n";
					mainMenu();
					menuOn = false;
					break;

				}

			} while (menuOn);
		}
		else if (getRace() == "Orc") {
			do {

				cout << "\n1. Attack Type: Barbarian\n";
				cout << "2. Magic Type: Sorcerer\n";
				cout << "3. Speed Type: Beast Master\n";
				cout << "4. Healer Type: Monk\n";
				cout << "5. Exit\n";
				cout << "Please enter an option: ";
				cin >> choice;

				switch (choice)
				{
				default: "Please enter a valid statement\n";
					menuOn = true;
					break;
				case 1:
					setClass("Barbarian");
					HP += 4;
					MP += 1;
					Attack += 5;
					Agility += 2;
					Armor += 3;
					Will += 0;
					menuOn = false;
					break;
				case 2:
					setClass("Sorcerer");
					HP += 2;
					MP += 5;
					Attack += 0;
					Agility += 3;
					Armor += 1;
					Will += 4;
					menuOn = false;
					break;
				case 3:
					setClass("Beast Master");
					HP += 3;
					MP += 2;
					Attack += 4;
					Agility += 5;
					Armor += 0;
					Will += 1;
					menuOn = false;
					break;
				case 4:
					setClass("Monk");
					HP += 4;
					MP += 3;
					Attack += 0;
					Agility += 1;
					Armor += 2;
					Will += 5;
					menuOn = false;
					break;
				case 5: cout << "\nLoading Main Menu...\n\n";
					mainMenu();
					menuOn = false;
					break;

				}

			} while (menuOn);
		}
		else if (getRace() == "Goblin") {
			do {

				cout << "\n1. Attack Type: Fighter\n";
				cout << "2. Magic Type: Warlock\n";
				cout << "3. Speed Type: Thief\n";
				cout << "4. Healer Type: Shaman\n";
				cout << "5. Exit\n";
				cout << "Please enter an option: ";
				cin >> choice;

				switch (choice)
				{
				default: "Please enter a valid statement\n";
					menuOn = true;
					break;
				case 1:
					setClass("Fighter");
					HP += 4;
					MP += 1;
					Attack += 5;
					Agility += 2;
					Armor += 3;
					Will += 0;
					menuOn = false;
					break;
				case 2:
					setClass("Warlock");
					HP += 2;
					MP += 5;
					Attack += 0;
					Agility += 3;
					Armor += 1;
					Will += 4;
					menuOn = false;
					break;
				case 3:
					setClass("Thief");
					HP += 3;
					MP += 2;
					Attack += 4;
					Agility += 5;
					Armor += 0;
					Will += 1;
					menuOn = false;
					break;
				case 4:
					setClass("Shaman");
					HP += 4;
					MP += 3;
					Attack += 0;
					Agility += 1;
					Armor += 2;
					Will += 5;
					menuOn = false;
					break;
				case 5: cout << "\nLoading Main Menu...\n\n";
					mainMenu();
					menuOn = false;
					break;
				}

			} while (menuOn);
		}
		else {
			cout << "\nPlease input a race before selecting a class.\n\n";
			mainMenu();
		}
	}
};

string formatStats(string HP, string MP, string Attack, string Agility, string Armor, string Will) {

	string stats = "HP: " + HP;
	stats += "\nMP: " + MP;
	stats += "\nAttack: " + Attack;
	stats += "\nAgility: " + Agility;
	stats += "\nArmor: " + Armor;
	stats += "\nWill: " + Will;
	return stats;
}

int main() {

	menu a;
	a.mainMenu();

}