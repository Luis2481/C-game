//============================================================================
// Name        : Introduction to Programming Project (C++)
// Author      : Luis Y.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// class for the player
class Player {

private:
    string name;
    int level;
    int xp;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int hitpoints; // player hp
    int attackBonus = 3; // the attack bonus will always be three

public:
    // I declare the player constructor
    Player(string namePlayer, int lvlPlayer) {

         name = namePlayer;
         level = lvlPlayer;
         xp = 0; // The player will start with 0 xp until he defeats future enemies.

        rollStats();

        // calculate the player's hitpoints
        hitpoints = 10 + rollD6() + rollD6() + rollD6() + rollD6() + rollD6();
    }

    // I declare a function to generate a random number with a maximum value of 6
    int rollD6() {

        return rand() % 6 + 1; // applied formula
    }

    // I declare a function to randomly set the player's stats with the roll
    void rollStats() {

        strength = rollProcedure();
        dexterity = rollProcedure();
        constitution = rollProcedure();
        intelligence = rollProcedure();
        wisdom = rollProcedure();
        charisma = rollProcedure();
    }

    // function where I perform the void rollStats procedure
    int rollProcedure() {

        int rolls[4];
        int total = 0;

        for (int count = 0; count < 4; count++) {

            rolls[count] = rollD6();
            total += rolls[count];
        }

        // I add the procedure where I find the lowest value and delete it
        int minRoll = rolls[0];

        for (int count = 1; count < 4; count++) {

            if (rolls[count] < minRoll) {
                minRoll = rolls[count];
            }
        }

        total -= minRoll;
        return total;
    }

    // to get the player's stats:
     int getLevel()
    { return level; }

    int getStrength()
    { return strength; }

    int getDexterity()
    { return dexterity; }

    int getConstitution()
    { return constitution; }

    int getIntelligence()
    { return intelligence; }

    int getWisdom()
    { return wisdom; }

    int getCharisma()
    { return charisma; }

    // to get the player's hp:
    int getHitpoints()
    { return hitpoints; }

    // to get the player's attack bonus:
    int getAttackBonus()
    { return attackBonus; }

     void addXP(int gainedXP) {

        xp += gainedXP;
        cout << "You have gained " << gainedXP << " XP!" << endl;
        cout << "The total that you have on XP is: " << xp << endl;
        upLevelPlayer();
    }

    void upLevelPlayer() {

        while (xp >= 200) { // while loop when the player gets 200 xp or more.

        	xp -= 200; // the XP will be reset to allow the player to keep leveling up for every 200 XP they gain.
            level++;

            cout << "You have leveled up! Your new level is: " << level << endl;

            int additionalHP = rollD10();
            hitpoints += additionalHP;
            cout << "You have gained " << additionalHP << " additional hitpoints. Your total of hitpoints is " << hitpoints << endl;
        }
    }

    int rollD10() {

        return rand() % 10 + 1; // applied formula
    }
};

// class for Goblin, Orc, and Ogre (level 1, level 2, and level 3)
class Monster {

private:
    string name;
    int armorClass;
    int hitPoints;
    int speed;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int proficiencyBonus;

public:
    // I declare the constructor for the Monster class
    Monster(string nameMonster, int armorClassMonster, int hitPointsMonster, int speedMonster, int strMonster, int dexMonster, int conMonster, int intMonster, int wisMonster, int chaMonster, int proficiencyBonusMonster) {

        name = nameMonster;
        armorClass = armorClassMonster;
        hitPoints = hitPointsMonster;
        speed = speedMonster;
        strength = strMonster;
        dexterity = dexMonster;
        constitution = conMonster;
        intelligence = intMonster;
        wisdom = wisMonster;
        charisma = chaMonster;
        proficiencyBonus = proficiencyBonusMonster;
    }

    // I declare a function to show the stats of the Goblin
    void goblinStats() {

        cout << "Monster Name: " << name << endl;
        cout << "Armor Class: " << armorClass << endl;
        cout << "Hit Points: " << hitPoints << endl;
        cout << "Speed: " << speed << " ft." << endl;
        cout << "Strength: " << strength << endl;
        cout << "Dexterity: " << dexterity << endl;
        cout << "Constitution: " << constitution << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Wisdom: " << wisdom << endl;
        cout << "Charisma: " << charisma << endl;
        cout << "Proficiency Bonus: " << proficiencyBonus << endl;
        cout << "" << endl;
    }

    // I declare a function to show the stats of the Orc
    void orcStats() {

        cout << "Monster Name: " << name << endl;
        cout << "Armor Class: " << armorClass << endl;
        cout << "Hit Points: " << hitPoints << endl;
        cout << "Speed: " << speed << " ft." << endl;
        cout << "Strength: " << strength << endl;
        cout << "Dexterity: " << dexterity << endl;
        cout << "Constitution: " << constitution << endl;
        cout << "Intelligence: " << intelligence << endl;
        cout << "Wisdom: " << wisdom << endl;
        cout << "Charisma: " << charisma << endl;
        cout << "Proficiency Bonus: " << proficiencyBonus << endl;
        cout << "" << endl;
    }

    // I declare a function to show the stats of the Ogre
    void ogreStats() {

         cout << "Monster Name: " << name << endl;
         cout << "Armor Class: " << armorClass << endl;
         cout << "Hit Points: " << hitPoints << endl;
         cout << "Speed: " << speed << " ft." << endl;
         cout << "Strength: " << strength << endl;
         cout << "Dexterity: " << dexterity << endl;
         cout << "Constitution: " << constitution << endl;
         cout << "Intelligence: " << intelligence << endl;
         cout << "Wisdom: " << wisdom << endl;
         cout << "Charisma: " << charisma << endl;
         cout << "Proficiency Bonus: " << proficiencyBonus << endl;
         cout << "" << endl;
     }
};

// class for managing Goblin fights
class FightGoblin {
private:
    int playerHPLevel01;
    int goblinHP;

public:
    FightGoblin(int playerHPGoblin, int goblinHPMonster) { // constructor for the Goblin fight

    	playerHPLevel01 = playerHPGoblin;
    	goblinHP = goblinHPMonster;
    }

    // function for the d20 roll for the player and Goblin fight
    int rollD20() {

        return rand() % 20 + 1;
    }

    // declare a void function to execute the player and Goblin fight
    void goblinFight(Player& player) {

        // apply while loop to initiate the fight
        while (playerHPLevel01 > 0 && goblinHP > 0) {

            // automatically roll initiative dice to determine who attacks first
            int playerInitiative = rollD20();
            int goblinInitiative = rollD20();

            // if statement for when the player rolls lower (they attack first in that case)
            if (playerInitiative < goblinInitiative) {

                int playerAttackRoll = rollD20();

                if (playerAttackRoll == 1) {

                    cout << "Oh no! You rolled a 1. You hit yourself and take damage." << endl;
                    playerHPLevel01 -= 5;
                }

                else if (playerAttackRoll == 20) {

                    cout << "You rolled a 20! You are going to inflict maximum damage to the Goblins!" << endl;
                    goblinHP = 0;
                }

                else if (playerAttackRoll <= 14) { // 14 is the Goblin's dexterity

                    cout << "The Goblin evades the attack!" << endl;
                }

                else {

                    int dmgGoblin = player.getStrength() + player.getAttackBonus();
                    cout << "You hit the Goblin for " << dmgGoblin << " damage!" << endl;
                    goblinHP -= dmgGoblin;
                }
            }

            else { // if the Goblin attacks first (the same procedure but reversed)

                int goblinAttackRoll = rollD20();

                if (goblinAttackRoll == 20) {

                    cout << "Oh no! The Goblin rolled a 20! You will get hit by maximum damage!" << endl;
                    playerHPLevel01 = 0;
                }

                else if (goblinAttackRoll <= player.getDexterity()) {

                    cout << "Nice dodge! You evade the Goblin's attack." << endl;
                }

                else {

                    cout << "Oh no! The Goblin hit you!" << endl;

                    playerHPLevel01 -= 5; // Goblin's damage hits are 5
                }
            }

            // current status of the fight as rolls are made
             cout << "---------------------------" << endl;
             cout << "Player HP: " << playerHPLevel01 << " | Goblin HP: " << goblinHP << endl;
             cout << "---------------------------" << endl;

            // if statement for when the Goblin is dead
            if (goblinHP <= 0) {

                cout << "Nice battle! You defeated the Goblin!" << endl;
                player.addXP(50);
                cout << "" << endl;
                cout << "Since you defeated the Goblin, you can keep searching for items on the map or you can access the second level by pressing '2' (with Enter)." << endl;
                cout << "NOTE: Once you go to the second level, you can't go back to the first level." << endl;
                cout <<	"Remember, you need to acquire sufficient XP to level up your player and also to gain more hitpoints." << endl;
                cout << "Take the Goblin's symbol so that you don't need to fight him again." << endl;
                cout << "" << endl;
            }

            // if statement for when the player is dead
            if (playerHPLevel01 <= 0) {

                cout << "Game over! You were defeated by the Goblin!" << endl;
                cout << "" << endl;
                cout << "If you want to play again, run the program again." << endl;
                cout << "" << endl;
            }
        }
    }

};

// class for managing Orc fights
class FightOrc {

private:
    int playerHPLevel02;
    int orcHP;

public:
    FightOrc(int playerHPOrc, int orcHPMonster) { // constructor for the Orc fight

    	playerHPLevel02 = playerHPOrc;
    	orcHP = orcHPMonster;
    }

    // function for the d20 roll for the player and Orc fight
    int rollD20() {

        return rand() % 20 + 1;
    }

    // declare a void function to execute the player and Orc fight
    void orcFight(Player& player) {

        // apply while loop to initiate the fight
        while (playerHPLevel02 > 0 && orcHP > 0) {

            // automatically roll initiative dice to determine who attacks first
            int playerInitiative = rollD20();
            int orcInitiative = rollD20();

            // if statement for when the player rolls lower (they attack first in that case)
            if (playerInitiative < orcInitiative) {

                int playerAttackRoll = rollD20();

                if (playerAttackRoll == 1) {

                    cout << "Oh no! You rolled a 1. You hit yourself and take damage." << endl;
                    playerHPLevel02 -= 5;
                }

                else if (playerAttackRoll == 20) {

                    cout << "You rolled a 20! You are going to inflict maximum damage to the Orc!" << endl;
                    orcHP = 0;
                }

                else if (playerAttackRoll <= 12) {

                    cout << "The Orc evades the attack!" << endl;
                }

                else {

                    int dmgOrc = player.getStrength() + player.getAttackBonus();
                    cout << "You hit the Orc for " << dmgOrc << " damage!" << endl;
                    orcHP -= dmgOrc;
                }
            }

            else { // if the Orc attacks first (the same procedure but reversed)

                int orcAttackRoll = rollD20();

                if (orcAttackRoll == 20) {

                    cout << "Oh no! The Orc rolled a 20! You will get hit by maximum damage!" << endl;
                    playerHPLevel02 = 0;
                }

                else if (orcAttackRoll <= player.getDexterity()) {

                    cout << "Nice dodge! You evade the Orc's attack." << endl;
                }

                else {

                    cout << "Oh no! The Orc hit you!" << endl;

                    playerHPLevel02 -= 9; // Orc's damage hits are 9
                }
            }

            // current status of the fight as rolls are made
             cout << "---------------------------" << endl;
             cout << "Player HP: " << playerHPLevel02 << " | Orc HP: " << orcHP << endl;
             cout << "---------------------------" << endl;

            // if statement for when the Orc is dead
            if (orcHP <= 0) {

                cout << "Nice battle! You defeated the Orc!" << endl;
                player.addXP(100);
                cout << "" << endl;
                cout << "Since you defeated the Orc, you can keep searching for items on the map. You can also keep fighting more Orcs or access the third level by pressing '3' (with Enter)." << endl;
                cout << "NOTE: If you go to the third level map, you can't access the first level and/or second level." << endl;
                cout <<	"Remember, you need to acquire sufficient XP to level up your player and also to gain more hitpoints." << endl;
                cout << "Take the Orc's symbol so that you don't need to fight him again." << endl;
                cout << "" << endl;
            }

            // if statement for when the player is dead
            if (playerHPLevel02 <= 0) {

                cout << "Game over! You were defeated by the Orc." << endl;
                cout << "" << endl;
                cout << "If you want to play again, run the program again." << endl;
                cout << "" << endl;
            }
        }
    }
};

// class for managing Ogre fights
class FightOgre {

private:
    int playerHPLevel03;
    int ogreHP;

public:
    FightOgre(int playerHPOgre, int ogreHPMonster) { // constructor for the Ogre fight

    	playerHPLevel03 = playerHPOgre;
    	ogreHP = ogreHPMonster;
    }

    // function for the d20 roll for the player and Ogre fight
    int rollD20() {

        return rand() % 20 + 1;
    }

    // declare a void function to execute the player and Ogre fight
    void ogreFight(Player& player) {

        // apply while loop to initiate the fight
        while (playerHPLevel03 > 0 && ogreHP > 0) {

            // automatically roll initiative dice to determine who attacks first
            int playerInitiative = rollD20();
            int ogreInitiative = rollD20();

            // if statement for when the player rolls lower (they attack first in that case)
            if (playerInitiative < ogreInitiative) {

                int playerAttackRoll = rollD20();

                if (playerAttackRoll == 1) {

                    cout << "Oh no! You rolled a 1. You hit yourself and take damage." << endl;
                    playerHPLevel03 -= 5;
                }

                else if (playerAttackRoll == 20) {

                    cout << "You rolled a 20! You are going to inflict maximum damage to the Ogre!" << endl;
                    ogreHP = 0;
                }

                else if (playerAttackRoll <= 8) {

                    cout << "The Ogre evades the attack!" << endl;
                }

                else {

                    int dmgOgre = player.getStrength() + player.getAttackBonus();
                    cout << "You hit the Ogre for " << dmgOgre << " damage!" << endl;
                    ogreHP -= dmgOgre;
                }
            }

            else { // if the Ogre attacks first (the same procedure but reversed)

                int ogreAttackRoll = rollD20();

                if (ogreAttackRoll == 20) {

                    cout << "Oh no! The Ogre rolled a 20! You will get hit by maximum damage!" << endl;
                    playerHPLevel03 = 0;
                }

                else if (ogreAttackRoll <= player.getDexterity()) {

                    cout << "Nice dodge! You evade the Ogre's attack." << endl;
                }

                else {

                    cout << "Oh no! The Ogre hit you!" << endl;
                    playerHPLevel03 -= 13; // Ogre's damage hits are 13
                }
            }

            // current status of the fight as rolls are made
             cout << "---------------------------" << endl;
             cout << "Player HP: " << playerHPLevel03 << " | Ogre HP: " << ogreHP << endl;
             cout << "---------------------------" << endl;

            // if statement for when the Ogre is dead
            if (ogreHP <= 0) {

                cout << "Nice battle! You defeated the Ogre!" << endl;
                player.addXP(450);
                cout << "" << endl;
                cout << "You have survived all the levels, defeating the enemies. The game is over." << endl;
                cout << "You can rest now for your long journey, fellow hunter." << endl;
                cout << "Take the Ogre's symbol so that you don't need to fight him again." << endl;
                cout << "" << endl;
            }

            // if statement for when the player is dead
            if (playerHPLevel03 <= 0) {

                cout << "Game over! You were defeated by the Ogre." << endl;
                cout << "So far, but at the same time so close to finishing the game..." << endl;
                cout << "" << endl;
                cout << "If you want to play again, run the program again." << endl;
                cout << "" << endl;
            }
        }
    }
};

// constant dimensions for the map
const int x = 23; // the length in "x" for the map
const int y = 29; // the length in "y" for the map

// declare 2D array
char level[x][y];

// declare a function to read the file and decode the numbers using if and else if statements
void fileLevel(string filename) {

    ifstream inputLevelFile(filename);

    if (!inputLevelFile) {

        cout << "This is an error. The level file can't be found or opened..." << endl;
    }

    else { // apply the procedure using for loop for x and y

    for (int countX = 0; countX < y; countX++) {

        for (int countY = 0; countY < x; countY++) {

            char encodedChar;
            // the character variable will read the file to change it with symbols
            inputLevelFile >> encodedChar;

            // the symbols will be added to the 2D array
            if (encodedChar == '0') {

                level[countX][countY] = ' ';
            }

            else if (encodedChar == '1') {

                level[countX][countY] = '#';
            }

            else if (encodedChar == '2') {

                 level[countX][countY] = '@';
            }

            else if (encodedChar == '3') {

                 level[countX][countY] = '*'; // Goblin symbol (level01)
            }
        }
     }
  }

    inputLevelFile.close(); // close the file
}

const int x2 = 23;
const int y2 = 29;

char level02[x2][y2];

void fileLevel02(string filename) {

	ifstream inputLevelFile02(filename);

	if (!inputLevelFile02) {

		cout << "The level02 file can't be found or opened." << endl;
	}

	else {

		for (int countX2 = 0; countX2 < y2; countX2++) {

			for (int countY2 = 0; countY2 < x2; countY2++) {

			char encodedChar2;

			inputLevelFile02 >> encodedChar2;

   		if (encodedChar2 == '0') {

   			level02[countX2][countY2] = ' ';
   		}

   		else if (encodedChar2 == '1') {

   			level02[countX2][countY2] = '#';
   		}

   		else if (encodedChar2 == '2') {

   			level02[countX2][countY2] = '@';
   		}

   		else if (encodedChar2 == '3') {

   			level02[countX2][countY2] = 'O'; // these will be the enemy symbols for level02 (the Orcs)
   		}
	  }
    }
  }

   inputLevelFile02.close(); // close the file
}

const int x3 = 19;
const int y3 = 19;

char level03[x3][y3];

void fileLevel03(string filename) {

    ifstream inputLevel03File(filename);

    if (!inputLevel03File) {

        cout << "This is an error. The level03 file can't be found or opened..." << endl;
    }

    else {

    for (int countX3 = 0; countX3 < y3; countX3++) {

        for (int countY3 = 0; countY3 < x3; countY3++) {

            char encodedChar3;

            inputLevel03File >> encodedChar3;

            if (encodedChar3 == '0') {

                level03[countX3][countY3] = ' ';
            }

            else if (encodedChar3 == '1') {

                level03[countX3][countY3] = '#';
            }

            else if (encodedChar3 == '2') {

                 level03[countX3][countY3] = '@';
            }

            else if (encodedChar3 == '3') {

                 level03[countX3][countY3] = '$'; // Ogre symbol (level03)
            }
        }
     }
  }

    inputLevel03File.close(); // close the file
}

// declare a function to display levels in the console
void mapLevel() {

    for (int countX = 0; countX < y; countX++) {

        for (int countY = 0; countY < x; countY++) {

            cout << level[countX][countY];
        }

        cout << endl; // finish the line of the for loop
    }
}

void mapLevel02() {

    for (int countX2 = 0; countX2 < y2; countX2++) {

        for (int countY2 = 0; countY2 < x2; countY2++) {

            cout << level02[countX2][countY2];
        }

        cout << endl;
    }
}

void mapLevel03() {

    for (int countX3 = 0; countX3 < y3; countX3++) {

        for (int countY3 = 0; countY3 < x3; countY3++) {

            cout << level03[countX3][countY3];
        }

        cout << endl;
    }
}

// this function will randomly place items on the map
void randItems() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);

    // max items that the player can have are 10
    int maxItems = 10;

    // Place items randomly on the map using a for loop
    for (int count = 0; count < maxItems; count++) {

        int itemsX = rand() % y + 1;
        int itemsY = rand() % x + 1;

        if (level[itemsX][itemsY] != '#' && level[itemsX][itemsY] != '*') { // so that items are not in the walls or on the Goblin

            level[itemsX][itemsY] = '/'; // symbol of the items
        }
    }
}

void randItemsLevel02() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);

    int maxItems2 = 10;

    for (int count = 0; count < maxItems2; count++) {

        int itemsX2 = rand() % y2 + 1;
        int itemsY2 = rand() % x2 + 1;

        if (level02[itemsX2][itemsY2] != '#' && level02[itemsX2][itemsY2] != 'O') { // so that items are not in the walls or on the Orc

            level02[itemsX2][itemsY2] = '+'; // symbol of the items
        }
    }
}

void randItemsLevel03() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);

    int maxItems3 = 10;

    for (int count = 0; count < maxItems3; count++) {

        int itemsX3 = rand() % y3 + 1;
        int itemsY3 = rand() % x3 + 1;

        if (level03[itemsX3][itemsY3] != '#' && level03[itemsX3][itemsY3] != '$') { // so that items are not in the walls or on the Ogre

            level03[itemsX3][itemsY3] = '.'; // symbol of the items
        }
    }
}

// this function will randomly place orcs on the map
void orcsLocation() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);

    int maxOrcs = 10; // maximum random number

    // Place orcs randomly on the map using a for loop
    for (int count = 0; count < maxOrcs; count++) {

        int itemsX2 = rand() % y2 + 1;
        int itemsY2 = rand() % x2 + 1;

        if (level02[itemsX2][itemsY2] != '#' && level02[itemsX2][itemsY2] != 'O') {

            level02[itemsX2][itemsY2] = '!'; // symbol of the orcs
        }
    }
}

// this function is to name the items randomly in the maps. I use a string vector
string stringItems() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);
                             // 0            // 1            // 2            // 3        // 4               // 5
	vector<string> items = {"Food.", "Healing Potion.", "Energy Potion.", "'e-Gold.'", "Coins.", "'Teleportation Stone.'"};

	int randItem = rand() % items.size(); // no +1 because a vector starts from 0 and not from 1 (min value is 0, not 1)

	if (randItem == 3) {

		float eGoldxp = 0.500;
		cout << "a " << eGoldxp << " XP" << endl;
	}

	else if (randItem == 5) {

		cout << "a valuable item in which you can teleport to the level02 map (if you are in the level01 map) or to the level03 map (if you are in the level02 map)." << endl;
		cout << "You can use ONLY 1 teleportation item per level (if you have acquired more than 1, those items except the first teleportation will not be used at any moment)." << endl;
		cout << "If you want to teleport to the level02 map, you can use the '2' key." << endl;
		cout << "If you want to teleport to the level03 map, you can use the '3' key." << endl;
        	cout << "NOTE: if you teleport to the level02 map you can't teleport to the level01 map." << endl;
        	cout << "NOTE: if you teleport to the level03 map you can't teleport to the level01 or level02 map." << endl;
		cout << "" << endl;
		cout << "You are going to be in different positions as you were in the level01 map or in the level02 map. There will be tougher enemies, be careful with the use of the " << endl;
	}

	return items[randItem];
}

// declare function to move the player up
void upPlayer(int& playerY, int& playerX) {

    int sevenRoomX1 = 19;
    int sevenRoomY1 = 11;

    int sixthRoomX1 = 9;
    int sixthRoomY1 = 3;

    if (playerY > 0 && level[playerY - 1][playerX] != '#') { // does not move into a wall

        level[playerY][playerX] = ' ';
        playerY--;
        level[playerY][playerX] = '*';
    }

    else  {

    	cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // descriptions of rooms:
    if (playerX == sevenRoomX1 && playerY == sevenRoomY1) {

            cout << "In this room, a group of draconic faces has been carved into the west wall, and someone has scrawled 'The Guild of the Arrow and Lamp looted this place' on the west wall." << endl;
            cout << "Maybe this room will still have an item or not. Don't lose your hope!" << endl;
        }

        else if (playerX == sixthRoomX1 && playerY == sixthRoomY1) {

            cout << "This room has the entire floor and walls painted red along with torches in the walls. Could it be... BLOOD?" << endl;
        }

    if (playerY > 0 && level[playerY - 1][playerX] == '/') {

    	cout << "You have found an item! It's " << stringItems() << endl;
        cout << "" << endl;
        cout << "If the item has a space, use '.'" << endl;
        cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
        cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
        cout << "Also, take the item symbol so that you don't need to take it up again." << endl;
    }
}

void upPlayer02(int& playerY2, int& playerX2, Player& player) {

    int firstRoomX2222 = 7;
    int firstRoomY2222 = 23;

    int secondRoomX2 = 7;
    int secondRoomY2 = 9;

    int sixthRoomX2 = 15;
    int sixthRoomY2 = 3;

    int sevenRoomX22 = 7;
    int sevenRoomY22 = 17;

    int eightRoomX222 = 15;
    int eightRoomY222 = 17;

    int eightRoomX2222 = 19;
    int eightRoomY2222 = 17;

    int ninthRoomX22 = 7;
    int ninthRoomY22 = 13;

    int tenthRoomX2 = 19;
    int tenthRoomY2 = 13;

     if (playerY2 > 0 && level02[playerY2 - 1][playerX2] != '#') { // does not move into a wall

        level02[playerY2][playerX2] = ' ';
        playerY2--;
        level02[playerY2][playerX2] = '*';
    }

    else  {

    	cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // room descriptions:
     if (playerX2 == firstRoomX2222 && playerY2 == firstRoomY2222) {

            cout << "This room has torches in all the walls, and it has a strong scent of BLOOD. Be careful out there!" << endl;
        }

         else if (playerX2 == secondRoomX2 && playerY2 == secondRoomY2) {

            cout << "The floor in this room has arrows pointing everywhere; it could be the location of the enemies." << endl;
        }

         else if (playerX2 == sixthRoomX2 && playerY2 == sixthRoomY2) {

            cout << "In a room covered with two torches of normal flames with the floor being covered with symbols everywhere, you found the reliable hunter for the second time." << endl;
            cout << "He saw strength and potential in you. He wishes you the best of luck fighting the Orcs." << endl;
        }

        else if (playerX2 == sevenRoomX22 && playerY2 == sevenRoomY22) {

            cout << "The walls of this room have been destroyed. The path is not very good to move on. Be careful while you are moving there." << endl;
        }

         else if (playerX2 == eightRoomX222 && playerY2 == eightRoomY222) {

            cout << "The room is brightly illuminated; the floor and walls are pearl white, and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

           else if (playerX2 == eightRoomX2222 && playerY2 == eightRoomY2222) {

            cout << "The room is brightly illuminated; the floor and walls are pearl white, and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

        else if (playerX2 == ninthRoomX22 && playerY2 == ninthRoomY22) {

            cout << "In this room, there are torches with blue flames that are fading, and the lighting is not good. Also, there is a lot of fog in the room." << endl;
            cout << "Be careful around you." << endl;
        }

           else if (playerX2 == tenthRoomX2 && playerY2 == tenthRoomY2) {

            cout << "In this room, you heard sounds from everywhere. The floor has a lot of rocks and spikes. Be careful while you are moving in this room." << endl;
        }

    if (playerY2 > 0 && level02[playerY2 - 1][playerX2] == '+') {

     	cout << "You have found an item! It's " << stringItems() << endl;
     	cout << "" << endl;
     	cout << "If the item has a space, use '.'" << endl;
        cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
        cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
        cout << "Take the item symbol so that you don't need to pick it up again." << endl;
     }

   else if ((playerY2 > 0 && level02[playerY2 - 1][playerX2] == 'O') || (playerY2 > 0 && level02[playerY2 - 1][playerX2] == '!')) {

            cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
            cout << "" << endl;
            cout << "These are the stats of the Orc:" << endl;

            // create the monster object to display the stats of the Orc and the full fight
            Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
            orc.orcStats();

            FightOrc fight(player.getHitpoints(), 15);
            fight.orcFight(player);
          }
}

// declare function to move the player up in the third level
void upPlayer03(int& playerY3, int& playerX3, Player& player) {

    if (playerY3 > 0 && level03[playerY3 - 1][playerX3] != '#') { // does not move into a wall

        level03[playerY3][playerX3] = ' ';
        playerY3--;
        level03[playerY3][playerX3] = '*';
    }

    else  {

    	cout << "You can't move in that direction. There is a wall there." << endl;
    }

    if (playerY3 > 0 && level03[playerY3 - 1][playerX3] == '.') {

        	cout << "You have found an item! It's " << stringItems() << endl;
        	cout << "" << endl;
        	cout << "If the item has a space, use '.'" << endl;
            	cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
            	cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
            	cout << "Take the item symbol so that you don't need to pick it up again." << endl;
        }

       if (playerY3 > 0 && level03[playerY3 - 1][playerX3] == '$') {

               cout << "You have found the Ogre!! Prepare yourself for your final battle!!" << endl;
               cout << "" << endl;
               cout << "These are the stats of the Ogre:" << endl;

               Monster ogre("Ogre", 11, 59, 40, 19, 8, 16, 5, 7, 7, 2);
               ogre.ogreStats();

               FightOgre fight(player.getHitpoints(), 59);
               fight.ogreFight(player);
        }
}

// declare function to move the player down in the first level
void downPlayer(int& playerY, int& playerX) {

    int fourthRoomX1 = 9;
    int fourthRoomY1 = 25;

    int firstRoomX1 = 9;
    int firstRoomY1 = 15;

    int tenthRoomX1 = 1;
    int tenthRoomY1 = 17;

    if (playerY < y - 1 && level[playerY + 1][playerX] != '#') { // does not move into a wall

        level[playerY][playerX] = ' ';
        playerY++;
        level[playerY][playerX] = '*';
    }

    else {

      	cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // room descriptions:
    if (playerX == fourthRoomX1 && playerY == fourthRoomY1) {

           cout << "In this room, the walls in the north direction have collapsed. The floor is covered with BLOODSTAINS, and the lights in the room flicker ON and OFF between specific intervals of seconds." << endl;
           cout << "MYSTERIOUS and SCARY, isn't it? Well, be careful when you are moving there." << endl;
        }

       else if (playerX == firstRoomX1 && playerY == firstRoomY1) {

            cout << "This room has numerous pillars lined to the south and east walls, and iron ornaments are displayed on the north side of the room. The room is safe, and you will have no issues when you are moving there." << endl;
        }

        else if (playerX == tenthRoomX1 && playerY == tenthRoomY1) {

            cout << "In this room, you have found the reliable hunter! He tells you the location of the enemy. The enemy is covering a portal in a dark, mysterious hallway." << endl;
            cout << "That hallway is covered with BLOOD, and the floor and walls are white." << endl;
        }

    if (playerY < y - 1 && level[playerY + 1][playerX] == '/') {

    	   cout << "You have found an item! It's " << stringItems() << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to pick it up again." << endl;
       }
}

// declare function to move the player down in the second level
void downPlayer02(int& playerY2, int& playerX2, Player& player) {

    int fourthRoomX22 = 19;
    int fourthRoomY22 = 25;

    int fourthRoomX222 = 21;
    int fourthRoomY222 = 25;

    int thirdRoomX22 = 7;
    int thirdRoomY22 = 25;

    int thirdRoomX222 = 1;
    int thirdRoomY222 = 25;

    int firstRoomX2 = 15;
    int firstRoomY2 = 19;

    int firstRoomX22 = 7;
    int firstRoomY22 = 19;

    int firstRoomX222 = 9;
    int firstRoomY222 = 19;

    int secondRoomX22 = 15;
    int secondRoomY22 = 5;

    int sevenRoomX222 = 7;
    int sevenRoomY222 = 15;

    int eightRoomX22 = 19;
    int eightRoomY22 = 15;

    int ninthRoomX2 = 7;
    int ninthRoomY2 = 11;

    if (playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] != '#') { // does not move into a wall

        level02[playerY2][playerX2] = ' ';
        playerY2++;
        level02[playerY2][playerX2] = '*';
    }

    else {

      	cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // room descriptions:
    if (playerX2 == fourthRoomX22 && playerY2 == fourthRoomY22) {

            cout << "In this room, there are messages on the floor and on the walls. It is in an unknown language and lettering." << endl;
		    cout << "Maybe it is a sign of something important?" << endl;
        }

           else if (playerX2 == fourthRoomX222 && playerY2 == fourthRoomY222) {

            cout << "In this room, there are messages on the floor and on the walls. It is in an unknown language and lettering." << endl;
		    cout << "Maybe it is a sign of something important?" << endl;
        }

        else if (playerX2 == thirdRoomX22 && playerY2 == thirdRoomY22) {

            cout << "This room has good lighting, and there are symbols of faces on the walls along with a pair of torches on the sides." << endl;
		    cout << "Maybe those faces are from the enemies of this map?" << endl;
        }

        else if (playerX2 == thirdRoomX222 && playerY2 == thirdRoomY222) {

            cout << "This room has good lighting, and there are symbols of faces on the walls along with a pair of torches on the sides." << endl;
		    cout << "Maybe those faces are from the enemies of this map?" << endl;
        }

         else if (playerX2 == secondRoomX22 && playerY2 == secondRoomY22) {

            cout << "The floor in this room has arrows pointing everywhere; it could be the location of the enemies." << endl;
        }

           else if (playerX2 == firstRoomX2 && playerY2 == firstRoomY2) {

            cout << "This room has torches in all the walls, and it has a strong scent of BLOOD. Be careful out there!" << endl;
        }

          else if (playerX2 == firstRoomX22 && playerY2 == firstRoomY22) {

            cout << "This room has torches in all the walls, and it has a strong scent of BLOOD. Be careful out there!" << endl;
        }

          else if (playerX2 == firstRoomX222 && playerY2 == firstRoomY222) {

            cout << "This room has torches in all the walls, and it has a strong scent of BLOOD. Be careful out there!" << endl;
        }

          else if (playerX2 == thirdRoomX22 && playerY2 == thirdRoomY22) {

            cout << "This room has torches in all the walls, and it has a strong scent of BLOOD. Be careful out there!" << endl;
        }

         else if (playerX2 == thirdRoomX222 && playerY2 == thirdRoomY222) {

            cout << "This room has torches in all the walls, and it has a strong scent of BLOOD. Be careful out there!" << endl;
        }

        else if (playerX2 == sevenRoomX222 && playerY2 == sevenRoomY222) {

            cout << "The walls of this room have been destroyed. The path is not very good to move on. Be careful while you are moving there." << endl;
        }

        else if (playerX2 == eightRoomX22 && playerY2 == eightRoomY22) {

            cout << "The room is brightly illuminated; the floor and walls are pearl white, and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

        else if (playerX2 == ninthRoomX2 && playerY2 == ninthRoomY2) {

            cout << "In this room, there are torches with blue flames that are fading, and the lighting is not good. Also, there is a lot of fog in the room." << endl;
            cout << "Be careful around you." << endl;
        }

    if (playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] == '+') {

     	cout << "You have found an item! It's " << stringItems() << endl;
     	cout << "" << endl;
     	cout << "If the item has a space, use '.'" << endl;
        cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
        cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
        cout << "Take the item symbol so that you don't need to pick it up again." << endl;
     }

       else if ((playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] == 'O') || (playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] == '!')) {

          cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
          cout << "" << endl;
          cout << "These are the stats of the Orc:" << endl;

          Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
          orc.orcStats();

          FightOrc fight(player.getHitpoints(), 15);
          fight.orcFight(player);
    }
}

// declare function to move the player down in the third level
void downPlayer03(int& playerY3, int& playerX3) {

    int fourthRoomX3 = 7;
    int fourthRoomY3 = 13;

    int fourthRoomX33 = 9;
    int fourthRoomY33 = 13;

    int firstRoomX3 = 17;
    int firstRoomY3 = 11;

    if (playerY3 < y3 - 1 && level03[playerY3 + 1][playerX3] != '#') { // does not move into a wall

        level03[playerY3][playerX3] = ' ';
        playerY3++;
        level03[playerY3][playerX3] = '*';
    }

    else {

      	cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // room descriptions:
       if (playerX3 == firstRoomX3 && playerY3 == firstRoomY3) {

        cout << "This room has a friendly atmosphere, and there are torches illuminating all the room." << endl;
        cout << "For the last time, you have found the reliable hunter! He was waiting for your appearance in this final level." << endl;
        cout << "This time, the reliable hunter will guide you to the final boss, and he will fight with you until the very end." << endl;
      }

      else if (playerX3 == fourthRoomX3 && playerY3 == fourthRoomY3) {

        cout << "The atmosphere in this room is very ominous. It is completely quiet, but who knows what can happen in the area..." << endl;
        cout << "Always be prepared for anything; you can't give up now in the final level." << endl;
      }

      else if (playerX3 == fourthRoomX33 && playerY3 == fourthRoomY33) {

        cout << "The atmosphere in this room is very ominous. It is completely quiet, but who knows what can happen in the area..." << endl;
        cout << "Always be prepared for anything; you can't give up now in the final level." << endl;
      }

    if (playerY3 < y3 - 1 && level03[playerY3 + 1][playerX3] == '.') {

            	cout << "You have found an item! It's " << stringItems() << endl;
            	cout << "" << endl;
            	cout << "If the item has a space, use '.'" << endl;
                cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
                cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
                cout << "Take the item symbol so that you don't need to pick it up again." << endl;
        }
}

// declare function to move the player left in the first level
void leftPlayer(int& playerY, int& playerX) {

   int fourthRoomX11 = 9;
   int fourthRoomY11 = 25;

   int eightRoomX1 = 5;
   int eightRoomY1 = 7;

   int fifthRoomX1 = 19;
   int fifthRoomY1 = 1;

    if (playerX > 0 && level[playerY][playerX - 1] != '#') { // does not move into a wall

        level[playerY][playerX] = ' ';
        playerX--;
        level[playerY][playerX] = '*';
    }

    else {

         cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // room descriptions:
        if (playerX == fourthRoomX11 && playerY == fourthRoomY11) {

           cout << "In this room, the walls in the north direction have collapsed. The floor is covered with BLOODSTAINS, and the lights in the room flicker ON and OFF between specific intervals of seconds." << endl;
           cout << "MYSTERIOUS and SCARY, isn't it? Well, be careful when you are moving there." << endl;
        }

        else if (playerX == eightRoomX1 && playerY == eightRoomY1) {

            cout << "In this room, someone has scrawled 'The enemy is closer between this room and the other room...' in draconic script on the south wall, and knocking can be faintly heard near the south wall as well." << endl;
		    cout << "Be aware of your surroundings!" << endl;
        }

         else if (playerX == fifthRoomX1 && playerY == fifthRoomY1) {

            cout << "In this room, some of the walls have BLOODSTAINS, and there is no lighting." << endl;
		    cout << "Be careful out there!" << endl;
        }

    if (playerX > 0 && level[playerY][playerX - 1] == '/') {

    	   cout << "You have found an item! It's " << stringItems() << endl;
    	   cout << "" << endl;
    	   cout << "If the item has a space, use '.'" << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to pick it up again." << endl;
     }
}

// declare function to move the player left in the second level
void leftPlayer02(int& playerY2, int& playerX2, Player& player) {

     int thirdRoomX2 = 7;
     int thirdRoomY2 = 25;

     int fifthRoomX2 = 7;
     int fifthRoomY2 = 3;

     int tenthRoomX22 = 19;
     int tenthRoomY22 = 11;

    if (playerX2 > 0 && level02[playerY2][playerX2 - 1] != '#') { // does not move into a wall

        level02[playerY2][playerX2] = ' ';
        playerX2--;
        level02[playerY2][playerX2] = '*';
    }

    else {

         cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // room descriptions:
       if (playerX2 == thirdRoomX2 && playerY2 == thirdRoomY2) {

            cout << "This room has good lighting, and there are symbols of faces on the walls along with a pair of torches on the sides." << endl;
            cout << "Maybe those faces are from the enemies of this map?" << endl;
        }

         else if (playerX2 == fifthRoomX2 && playerY2 == fifthRoomY2) {

            cout << "In this room, there are sounds of echoes and whispers that go to the hallway in the east direction." << endl;
            cout << "Most probably in that hallway there is an Orc!" << endl;
        }

        else if (playerX2 == tenthRoomX22 && playerY2 == tenthRoomY22) {

            cout << "In this room, you hear sounds from everywhere. The floor has a lot of rocks and spikes. Be careful while you are moving in this room." << endl;
        }

    if (playerX2 > 0 && level02[playerY2][playerX2 - 1] == '+') {

       	   cout << "You have found an item! It's " << stringItems() << endl;
       	   cout << "" << endl;
       	   cout << "If the item has a space, use '.'" << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to pick it up again." << endl;
        }

    else if ((playerX2 > 0 && level02[playerY2][playerX2 - 1] == 'O') || (playerX2 > 0 && level02[playerY2][playerX2 - 1] == '!')) {

    	cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
    	cout << "" << endl;
        cout << "These are the stats of the Orc:" << endl;

        Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
        orc.orcStats();

    	FightOrc fight(player.getHitpoints(), 15);
    	fight.orcFight(player);
    }
}

// declare function to move the player left in the third level
void leftPlayer03(int& playerY3, int& playerX3) {

    int secondRoomX3 = 3;
    int secondRoomY3 = 17;

    int thirdRoomX3 = 15;
    int thirdRoomY3 = 7;

    if (playerX3 > 0 && level03[playerY3][playerX3 - 1] != '#') { // does not move into a wall

        level03[playerY3][playerX3] = ' ';
        playerX3--;
        level03[playerY3][playerX3] = '*';
    }

    else {

         cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // room descriptions:
    if (playerX3 == secondRoomX3 && playerY3 == secondRoomY3) {

            cout << "You can't enter this room. The whole room and hallway were damaged. In this map, there is a lot of destruction going on..." << endl;
        }

        else if (playerX3 == thirdRoomX3 && playerY3 == thirdRoomY3) {

            cout << "You can't enter this room. The entrance is completely blocked, and the floor has many holes." << endl;
        }

    if (playerX3 > 0 && level03[playerY3][playerX3 - 1] == '.') {

            cout << "You have found an item! It's " << stringItems() << endl;
            cout << "" << endl;
            cout << "If the item has a space, use '.'" << endl;
            cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
            cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
            cout << "Take the item symbol so that you don't need to pick it up again." << endl;
        }
}

// declare function to move the player right in the first level
void rightPlayer(int& playerY, int& playerX, Player& player) {

     int thirdRoomX1 = 13;
     int thirdRoomY1 = 25;

     int ninthRoomX1 = 17;
     int ninthRoomY1 = 19;

     int secondRoomX1 = 9;
     int secondRoomY1 = 9;

    if (playerX < x - 1 && level[playerY][playerX + 1] != '#') { // does not move into a wall

        level[playerY][playerX] = ' ';
        playerX++;
        level[playerY][playerX] = '*';
    }

    else {

        cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // room descriptions:
        if (playerX == thirdRoomX1 && playerY == thirdRoomY1) {

            cout << "This room doesn't have bloodstains or signs of fights. The walls in this room are pure violet, and it's actually a safe room." << endl;
		    cout << "It has very good lighting and is not dark at all. You can move without worries there." << endl;
        }

        else if (playerX == ninthRoomX1 && playerY == ninthRoomY1) {

            cout << "The floor in this room is covered with square tiles, alternating between white and black." << endl;
        }

         else if (playerX == secondRoomX1 && playerY == secondRoomY1) {

            cout << "The floor and walls in this room are dark red-orange. There are CORPSES everywhere. Be prepared for the worst!" << endl;
            cout << "If you keep searching for the enemy, maybe a reliable hunter will tell you his location." << endl;
        }

    if (playerX < x - 1 && level[playerY][playerX + 1] == '/') {

        	cout << "You have found an item! It's " << stringItems() << endl;
        	cout << "" << endl;
        	cout << "If the item has a space, use '.'" << endl;
            cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
            cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
            cout << "Take the item symbol so that you don't need to pick it up again." << endl;
         }

    else if (playerX < x - 1 && level[playerY][playerX + 1] == '*') {

    	cout << "You have found the Goblins!! Prepare yourself for the battle!!" << endl;
    	cout << "" << endl;
        cout << "These are the stats of the Goblins: " << endl;

         Monster goblin("Goblin", 15, 7, 30, 8, 14, 10, 10, 8, 8, 2);
         goblin.goblinStats();

    	FightGoblin fight(player.getHitpoints(), 7);
    	fight.goblinFight(player);
    }
}

// declare function to move the player right in the second level
void rightPlayer02(int& playerY2, int& playerX2, Player& player) {

     int fourthRoomX2 = 15;
     int fourthRoomY2 = 27;

     int sixthRoomX22 = 15;
     int sixthRoomY22 = 3;

     int sevenRoomX2 = 3;
     int sevenRoomY2 = 17;

     int eightRoomX2 = 15;
     int eightRoomY2 = 15;

     int ninthRoomX222 = 3;
     int ninthRoomY222 = 13;

     int tenthRoomX222 = 15;
     int tenthRoomY222 = 13;

if (playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] != '#') { // does not move into a wall

        level02[playerY2][playerX2] = ' ';
        playerX2++;
        level02[playerY2][playerX2] = '*';
    }

    else {

        cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // room descriptions:
       if (playerX2 == fourthRoomX2 && playerY2 == fourthRoomY2) {

            cout << "In this room, there are messages on the floor and walls. It is an unknown language and script." << endl;
		    cout << "Maybe it is a sign of something important?" << endl;
        }

         else if (playerX2 == sixthRoomX22 && playerY2 == sixthRoomY22) {

            cout << "In a room covered with two torches of normal flames with the floor being covered with symbols everywhere, you found the reliable hunter for the second time." << endl;
            cout << "He saw strength and potential in you. He wishes you the best luck fighting the Orcs." << endl;
        }

        else if (playerX2 == sevenRoomX2 && playerY2 == sevenRoomY2) {

            cout << "The walls of this room have been destroyed. The path is not very good to move on. Be careful while you are moving there." << endl;
        }

        else if (playerX2 == eightRoomX2 && playerY2 == eightRoomY2) {

            cout << "The room is brightly illuminated; the floor and walls are pearl white, and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

         else if (playerX2 == ninthRoomX222 && playerY2 == ninthRoomY222) {

            cout << "In this room, there are torches with blue flames that are fading, and the lighting is not good. Also, there is a lot of fog in the room." << endl;
            cout << "Be careful around you." << endl;
        }

         else if (playerX2 == tenthRoomX222 && playerY2 == tenthRoomY222) {

            cout << "You heard sounds from everywhere. The floor has a lot of rocks and spikes. Be careful while you are moving in this room." << endl;
        }

    if (playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] == '+') {

       	   cout << "You have found an item! It's " << stringItems() << endl;
       	   cout << "" << endl;
       	   cout << "If the item has a space, use '.'" << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to pick it up again." << endl;
        }

    else if ((playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] == 'O') || (playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] == '!')) {

    	cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
    	cout << "" << endl;
        cout << "These are the stats of the Orc:" << endl;

        Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
        orc.orcStats();

    	FightOrc fight(player.getHitpoints(), 15);
    	fight.orcFight(player);
    }
}

// declare function to move the player right in the third level
void rightPlayer03(int& playerY3, int& playerX3) {

    if (playerX3 < x3 - 1 && level03[playerY3][playerX3 + 1] != '#') { // does not move into a wall

        level03[playerY3][playerX3] = ' ';
        playerX3++;
        level03[playerY3][playerX3] = '*';
    }

    else {

        cout << "You can't move in that direction. There is a wall there." << endl;
    }

    if (playerX3 < x3 - 1 && level03[playerY3][playerX3 + 1] == '.') {

        cout << "You have found an item! It's " << stringItems() << endl;
        cout << "" << endl;
        cout << "If the item has a space, use '.'" << endl;
        cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
        cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
        cout << "Take the item symbol so that you don't need to pick it up again." << endl;
    }
}

// declare function to show the player's inventory
void showInventory(vector<string> &inventory) {

    if (inventory.empty()) {

        cout << "Your inventory is empty." << endl;
    }

    else {

        cout << "This is the list of items you have in your inventory:" << endl;
        cout << "" << endl;

        for (int count = 0; count < inventory.size(); count++) {

            string& item = inventory[count];
            cout << "- " << item << endl;
        }
    }
}

// main function to execute the game
int main() {

        // randomizer
        unsigned seed;
        seed = time(0);
        srand(seed);

        vector<string> inventory;

        cout << "Wake up! You have been given a chance to change your living existence!" << endl;
        cout << "If you accept this challenge, you will be transported to a three (3) level tower" << endl;
        cout << "where you must fight different creatures for your survival." << endl;
        cout << "If you accept this quest, you will be equipped appropriately for your journey." << endl;
        cout << "" << endl;

        char decision; // user variable for decision
        bool badChoiceKeybind;
        badChoiceKeybind = true;

        while (badChoiceKeybind) {

        cout << "Do you accept this challenge? (y/n): " << endl;
        cin >> decision;

        if (decision == 'y' || decision == 'Y') {

            cout << "You have accepted the challenge!" << endl;
            cout << "You find yourself dressed in strange clothes, with two (2) objects with which to help you along your journey: a sword and a shield." << endl;
            cout << "" << endl;

    // start player position from 0
    int playerX = 0;
    int playerY = 0;

    // open the file in the main function by calling the level function
    fileLevel("level01.csv");

    // place the player in the level using a for loop for x and y
    for (int countX = 0; countX < y; countX++) {

        for (int countY = 0; countY < x; countY++) {

            if (level[countX][countY] == '*') { // the player will start at this symbol. In the other maps, it will be a different symbol.

                playerY = countX;
                playerX = countY;
            }
        }
    }

        string userPlayer; // user variable for the player

        cout << "Enter your name: " << endl;
        cin >> userPlayer;

        cout << "These are the stats that you have in this run: " << endl;
        cout << "" << endl;

        // apply the player object with their stats
        Player player(userPlayer, 5);

        string extraAttack = "Yes"; // the player will always have an extra attack

        // output the player's stats (calling the functions)
        cout << "Name: " << userPlayer << endl;
        cout << "Level: " << player.getLevel() << endl;
        cout << "Strength: " << player.getStrength() << endl;
        cout << "Dexterity: " << player.getDexterity() << endl;
        cout << "Constitution: " << player.getConstitution() << endl;
        cout << "Intelligence: " << player.getIntelligence() << endl;
        cout << "Wisdom: " << player.getWisdom() << endl;
        cout << "Charisma: " << player.getCharisma() << endl;

        // output the player's hitpoints (calling the function)
        cout << "Hitpoints: " << player.getHitpoints() << endl;

        // output the player's attack bonus (calling the function)
        cout << "Attack Bonus: " << player.getAttackBonus() << endl;

        // output the player's extra attack
        cout << "Extra Attack: " << extraAttack << endl;
        cout << "" << endl;

        cout << "Welcome to the first level of the tower." << endl;
        cout << "You are going to start with the south symbol of '*'. That's the location of your player in the very first level." << endl;
        cout << "REMEMBER: Your player symbol is always going to be '*' in all the levels." << endl;
        cout << "The towers are lightly illuminated with non-removable torches every 20 feet. Vision is not impaired in any way inside the towers. There are strange sounds all around you..." << endl;
        cout << "" << endl;

        cout << "Good luck out there, fellow hunter." << endl;
        cout << "May the sword and shield guide you in your journey." << endl;
        cout << "" << endl;

        cout << "These are the keybinds to move in the levels: " << endl;
        cout << "w or W (with Enter) = north // s or S (with Enter) = south // d or D (with Enter) = east // a or A (with Enter) = west." << endl;
        cout << "You can also leave the game with these keybinds if you want: q or Q (with Enter)." << endl;
        cout << "NOTE: You need to press the 'q' and 'Enter' or 'Q' and 'Enter' three times to leave the game if you are on level01." << endl;
        cout << "Two times if you are on level02 and one time if you are on level03." << endl;
        cout << "You can see the items that you have in the inventory by pressing 'i' or 'I' (with Enter)" << endl;
        cout << "" << endl;
        cout << "Enter the corresponding keybinds to move in the levels: " << endl;
        cout << "" << endl;

    // call the randItems function to place items on the map
    randItems();

    // call the mapLevel function to display the map in the console
    mapLevel();

    // declare a flag-controlled while loop for player directions
        bool continueLoop; // declare boolean variable to determine if the while loop will continue or not
        continueLoop = true;
        char directionAndMaps; // player variable for moving and accessing the second map

        while (continueLoop) {

            cin >> directionAndMaps;

            if (directionAndMaps == 'q' || directionAndMaps == 'Q') {

                badChoiceKeybind = false;
                continueLoop = false; // the while loop will stop executing as the player left the game

                cout << "You left the first level..." << endl;
            }

            else { // if the player stays in, the corresponding movement functions will be executed

                if (directionAndMaps == 'w' || directionAndMaps == 'W') {

                    upPlayer(playerY, playerX);
                    mapLevel();
                }

                else if (directionAndMaps == 'a' || directionAndMaps == 'A') {

                    leftPlayer(playerY, playerX);
                    mapLevel();
                }

                else if (directionAndMaps == 's' || directionAndMaps == 'S') {

                    downPlayer(playerY, playerX);
                    mapLevel();
                }

                else if (directionAndMaps == 'd' || directionAndMaps == 'D') {

                    rightPlayer(playerY, playerX, player);
                    mapLevel();
                }

                else if (directionAndMaps == 'u' || directionAndMaps == 'U') {

                    if (inventory.size() < 10) {

                        string foundItem1; // user variable

                        cout << "Enter the item name: " << endl;
                        cin >> foundItem1;

                        inventory.push_back(foundItem1);

                        cout << "Now you added the " << foundItem1 << " in your inventory." << endl;
                        cout << "REMEMBER: The maximum number of items that you can have in your inventory is 10." << endl;
                        cout << "You always need to check how many items you have." << endl;
                    }

                    else {

                        cout << "" << endl;
                        cout << "Your inventory is already full. You can't add more than 10 items." << endl;
                    }
                }

                else if (directionAndMaps == 'i' || directionAndMaps == 'I') {

                    showInventory(inventory);
                }

                else if (directionAndMaps == '2') { // When the player moves from map 1 to map 2

                    continueLoop = false;
                    cout << "You are now in level02. You are going to fight the Orcs to pass to the final level." << endl;
                    cout << "In this level, your location is marked by the 'O' symbol in the middle of the map." << endl;
                    cout << "NOTE: If you want to fight more Orcs, you can press one, two, or more times the following keybinds: 'o' or 'O' (with Enter)." << endl;
                    cout << "You also need to move so they can spawn on the map." << endl;
                    cout << "If you do so, the probabilities of your death are HIGHER than usual." << endl;
                    cout << "But you will gain more combat experience, XP, and be better prepared for the final boss in the last map." << endl;
                    cout << "Everything is up to you..." << endl;
                    cout << "" << endl;
                    fileLevel02("level02.csv");
                    randItemsLevel02();
                    mapLevel02();
                }

                else {

                    cout << "You can't move with that keybind. Enter a correct keybind to move." << endl;
                }
            }
        }

        // Level 2 Gameplay Loop
        bool continueLoopLevel02;
        continueLoopLevel02 = true;
        char directionLevel02Map;

        int playerX2 = 0;
        int playerY2 = 0;

        fileLevel02("level02.csv");

        for (int countX2 = 0; countX2 < y2; countX2++) {

            for (int countY2 = 0; countY2 < x2; countY2++) {

                if (level02[countX2][countY2] == 'O') {

                    playerY2 = countX2;
                    playerX2 = countY2;
                }
            }
        }

        randItemsLevel02();

        while (continueLoopLevel02) {

            cin >> directionLevel02Map;

            if (directionLevel02Map == 'q' || directionLevel02Map == 'Q') {

                continueLoopLevel02 = false;
                badChoiceKeybind = false;
                cout << "You left the second level..." << endl;
            }

            else {

                if (directionLevel02Map == 'w' || directionLevel02Map == 'W') {

                    upPlayer02(playerY2, playerX2, player);
                    mapLevel02();
                }

                else if (directionLevel02Map == 'a' || directionLevel02Map == 'A') {

                    leftPlayer02(playerY2, playerX2, player);
                    mapLevel02();
                }

                else if (directionLevel02Map == 's' || directionLevel02Map == 'S') {

                    downPlayer02(playerY2, playerX2, player);
                    mapLevel02();
                }

                else if (directionLevel02Map == 'd' || directionLevel02Map == 'D') {

                    rightPlayer02(playerY2, playerX2, player);
                    mapLevel02();
                }

                else if (directionLevel02Map == 'u' || directionLevel02Map == 'U') {

                    if (inventory.size() < 10) {

                        string foundItem2; // user variable

                        cout << "Enter the item name: " << endl;
                        cin >> foundItem2;

                        inventory.push_back(foundItem2);

                        cout << "Now you added the " << foundItem2 << " in your inventory." << endl;
                        cout << "REMEMBER: The maximum number of items that you can have in your inventory is 10." << endl;
                        cout << "You always need to check how many items you have." << endl;
                    }

                    else {

                        cout << "" << endl;
                        cout << "Your inventory is already full. You can't add more than 10 items." << endl;
                    }
                }

                else if (directionLevel02Map == 'i' || directionLevel02Map == 'I') {

                    showInventory(inventory);
                }

                else if (directionLevel02Map == 'o' || directionLevel02Map == 'O') { // spawn more orcs on the map

                    orcsLocation();
                }

                else if (directionLevel02Map == '3') {

                    continueLoopLevel02 = false;
                    cout << "You are now in the final level." << endl;
                    cout << "This is the level03 map." << endl;
                    cout << "Your location in this map is the '$' symbol that is in the west direction." << endl;
                    fileLevel03("level03.csv");
                    randItemsLevel03();
                    mapLevel03();
                }

                else {

                    cout << "You can't move with that keybind. Enter a correct keybind to move." << endl;
                }
            }
        }

        // Final Level Gameplay Loop
        bool continueLoopFinalLevel;
        continueLoopFinalLevel = true;
        char directionFinalMap;

        int playerX3 = 0;
        int playerY3 = 0;

        fileLevel03("level03.csv");

        for (int countX3 = 0; countX3 < y3; countX3++) {

            for (int countY3 = 0; countY3 < x3; countY3++) {

                if (level03[countX3][countY3] == '$') {

                    playerY3 = countX3;
                    playerX3 = countY3;
                }
            }
        }

        randItemsLevel03();

        while (continueLoopFinalLevel) {

            cin >> directionFinalMap;

            if (directionFinalMap == 'q' || directionFinalMap == 'Q') {

                continueLoopFinalLevel = false;
                badChoiceKeybind = false;
                cout << "You left the final level..." << endl;
            }

            else {

                if (directionFinalMap == 'w' || directionFinalMap == 'W') {

                    upPlayer03(playerY3, playerX3, player);
                    mapLevel03();
                }

                else if (directionFinalMap == 'a' || directionFinalMap == 'A') {

                    leftPlayer03(playerY3, playerX3);
                    mapLevel03();
                }

                else if (directionFinalMap == 's' || directionFinalMap == 'S') {

                    downPlayer03(playerY3, playerX3);
                    mapLevel03();
                }

                else if (directionFinalMap == 'd' || directionFinalMap == 'D') {

                    rightPlayer03(playerY3, playerX3);
                    mapLevel03();
                }

                else if (directionFinalMap == 'u' || directionFinalMap == 'U') {

                    if (inventory.size() < 10) {

                        string foundItem3; // user variable

                        cout << "Enter the item name: " << endl;
                        cin >> foundItem3;

                        inventory.push_back(foundItem3);

                        cout << "Now you added the " << foundItem3 << " in your inventory." << endl;
                        cout << "REMEMBER: The maximum number of items that you can have in your inventory is 10." << endl;
                        cout << "You always need to check how many items you have." << endl;
                    }

                    else {

                        cout << "" << endl;
                        cout << "Your inventory is already full. You can't add more than 10 items." << endl;
                    }
                }

                else if (directionFinalMap == 'i' || directionFinalMap == 'I') {

                    showInventory(inventory);
                }

                else {

                    cout << "You can't move with that keybind. Enter a correct keybind to move." << endl;
                }
            }
        }
    }

    else if (decision == 'n' || decision == 'N') {

        badChoiceKeybind = false;
        cout << "You fall asleep, return to the place you were before all this, forgetting everything, but always having a nagging feeling that you had a brush with greatness, but decided to pass on it." << endl;
    }

    else {

        cout << "You entered an incorrect keybind. Enter a correct keybind (between 'y' // 'Y' or 'n' // 'N')." << endl;
    }
}

return 0;
}
