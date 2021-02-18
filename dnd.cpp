#include <iostream>
#include <random>
#include <ctime>
#include <vector>
/*
Rewrite program using maps for better performance
FINISH: getWeight, getHeight, getAge

Written by: Erik C Sanders
*/

//"Rolls" 4 times and sums the top 3
int rollDice() {

	int stat[4] = {0,0,0,0};

	//roll four dice : WORKS
	for (int i = 0; i < 4; i++)
		stat[i] += 1 + rand() % 6;

	//find the smallest number : WORKS
	int smallestNum = 6;
	for (int i = 0; i < 4; i++) 
		if (stat[i] < smallestNum) 
			smallestNum = stat[i];
	
	//sum other numbers
	int sum = 0;
	for (int i = 0; i < 4; i++)		
			sum += stat[i];
	sum -= smallestNum;
	
	return sum;
}

//Generates your initial stats
int* generateStats() {

	static int stats[5];
	for (int i = 0; i < 5; i++)
		stats[i] = rollDice();
	
	return stats;
}

//Generates your race
std::string* generateRace() {
	std::vector<std::string> raceVector = { "Dwarf", "Halfling", "Human", "Gnome",
	"Teifling", "Dragonborn", "Elf", "Orc", "Half-elf", "Half-orc" };

	static std::string race = raceVector.at(rand() % 10);

	return &race;
}

//Generates your hair color
std::string* generateHair() {
	std::vector<std::string> normHairVector = { "Blonde", "Brown", "Black", "Red",
	"Gray", "White", "Bald" };
	static std::string hair = normHairVector.at(rand() % 7);

	return &hair;
}

//Generates your class
std::string* generateClss() {
	std::vector<std::string> clssVector = { "Bard", "Barbarian", "Druid", "Cleric",
	"Monk", "Paladin", "Rogue", "Ranger", "Fighter", "Sorcerer", "Warlock", "Wizard" };

	static std::string clss = clssVector.at(rand() % 12);

	return &clss;
}

//Generates your eye color
std::string* generateEye() {
	std::vector<std::string> eyeVector = { "Blue", "Brown", "Green", "Hazel", "Gray" };
	static std::string eye = eyeVector.at(rand() % 5);
	return &eye;
}
//Generates your skin color
std::string* generateSkin() {
	std::vector<std::string> skinVector = { "White", "Black", "Tan", "Pale" };
	static std::string skin = skinVector.at(rand() % 4);
	return &skin;
}



void startingPage() {
	std::cout << "=================================================================================\n";
	std::cout << "           WELCOME TO THE DUNGEON AND DRAGONS CHARACTER GENERATOR\n";
	std::cout << "=================================================================================\n";
}

void generatePlayer()  {
	int* stats = NULL;
	std::string* race = NULL;
	std::string* clss = NULL;
	std::string* hair = NULL;
	std::string* eye = NULL;
	std::string* skin = NULL;

	int weight = 0;
	int height = 0;
	int age = 0;
	
	srand(time(0));

	stats = generateStats();
	race = generateRace();
	clss = generateClss();
	hair = generateHair();
	eye = generateEye();		
	skin = generateSkin();

	std::cout << "Stats: ";
	for (int i = 0; i < 5; i++)
		std::cout << *(stats + i) << " ";
	std::cout << "\nRace: " << *race << std::endl;
	std::cout << "Class: " << *clss << std::endl;
	std::cout << "Hair Color: " << *hair << std::endl;
	std::cout << "Eye Color: " << *eye << std::endl;
	std::cout << "Skin Color: " << *skin << std::endl;	
}

int main() {

	startingPage();
	generatePlayer();
	std::cout << std::endl;
	return 0;
}