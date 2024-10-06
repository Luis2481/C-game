//============================================================================
// Name        : Introduction to Programming Project (C++)
// Author      : Luis Y. Camacho Gonzalez
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

// clase para el jugador
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
    int hitpoints; // hp del jugador
    int attackBonus = 3; // siempre el attack bonus sera de tres

public:
    // declaro constructor en respecto al personaje
    Player(string namePlayer, int lvlPlayer) {

         name = namePlayer;
         level = lvlPlayer;
         xp = 0; // el jugador comenzara con 0 xp hasta que derrote futuros enemigos.

        rollStats();

        // calculo los hitpoints del jugador
        hitpoints = 10 + rollD6() + rollD6() + rollD6() + rollD6() + rollD6();
    }

    // declaro funcion para generar un numero aleatorio teniendo de valor maximo el 6
    int rollD6() {

        return rand() % 6 + 1; // formula aplicada
    }

    // declaro funcion para poner aleatoriamente los stats del jugador con el roll
    void rollStats() {

        strength = rollProcedure();
        dexterity = rollProcedure();
        constitution = rollProcedure();
        intelligence = rollProcedure();
        wisdom = rollProcedure();
        charisma = rollProcedure();
    }

    // funcion en donde me hace el procedimiento del void rollStats
    int rollProcedure() {

        int rolls[4];
        int total = 0;

        for (int count = 0; count < 4; count++) {

            rolls[count] = rollD6();
            total += rolls[count];
        }

        // añado el procedimiento en donde encuentro el menor valor y lo elimino
        int minRoll = rolls[0];

        for (int count = 1; count < 4; count++) {

            if (rolls[count] < minRoll) {
                minRoll = rolls[count];
            }
        }

        total -= minRoll;
        return total;
    }

    // para obtener los stats del jugador:
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

    // para obtener la vida del jugador:
    int getHitpoints()
    { return hitpoints; }

    // para obtener el bono de ataque del jugador:
    int getAttackBonus()
    { return attackBonus; }

     void addXP(int gainedXP) {

        xp += gainedXP;
        cout << "You have gained " << gainedXP << " XP!" << endl;
        cout << "The total that you have on XP is: " << xp << endl;
        upLevelPlayer();
    }

    void upLevelPlayer() {

        while (xp >= 200) { // while loop cuando el jugador obtiene cada vez 200 xp o mas.

        	xp -= 200; // se reseteara el xp por restarse en el mismo para que pueda seguir subiendo de nivel cada 200 xp que el jugador tenga.
            level++;

            cout << "You have leveled up! Your new level is: " << level << endl;

            int additionalHP = rollD10();
            hitpoints += additionalHP;
            cout << "You have gained " << additionalHP << " additional hitpoints. Your total of hitpoints is " << hitpoints << endl;
        }
    }

    int rollD10() {

        return rand() % 10 + 1; // formula aplicada
    }
};

// clase para el Goblin, Orc y para el Ogre (level 1, level 2 y level 3)
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
    // declaro el constructor del monstruo
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

    // declaro función para mostrar las estadísticas del goblin
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

class FightGoblin {
private:
    int playerHPLevel01;
    int goblinHP;

public:
    FightGoblin(int playerHPGoblin, int goblinHPMonster) { // constructor de la pelea del goblin

    	playerHPLevel01 = playerHPGoblin;
    	goblinHP = goblinHPMonster;
    }

    // funcion para el d20 para la dinamica de la pelea del jugador y el goblin
    int rollD20() {

        return rand() % 20 + 1;
    }

    // declaro funcion void para hacer la pelea del jugador y el goblin
    void goblinFight(Player& player) {

        // aplico while loop para iniciar la pelea
        while (playerHPLevel01 > 0 && goblinHP > 0) {

            // se lanzaran automaticamente los dados de iniciativa para saber quien atacara primero
            int playerInitiative = rollD20();
            int goblinInitiative = rollD20();

            // if statement por si el rolld20 del jugador es menor (el atacara primero en ese caso)
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

                else if (playerAttackRoll <= 14) { // 14 es el dexterity de los goblins

                    cout << "The Goblins evades the attack!" << endl;
                }

                else {

                    int dmgGoblin = player.getStrength() + player.getAttackBonus();
                    cout << "You hit the Goblins for " << dmgGoblin << " damage!" << endl;
                    goblinHP -= dmgGoblin;
                }
            }

            else { // si el goblin ataca primero (se hace lo mismo pero al revez)

                int goblinAttackRoll = rollD20();

                if (goblinAttackRoll == 20) {

                    cout << "Oh no! The Goblins rolled a 20! You will get hit by maximum damage!" << endl;
                    playerHPLevel01 = 0;
                }

                else if (goblinAttackRoll <= player.getDexterity()) {

                    cout << "Nice dodge! You evade the Goblins attack." << endl;
                }

                else {

                    cout << "Oh no! The Goblins hit you!" << endl;

                    playerHPLevel01 -= 5; // dmg de hits de los goblins son 5
                }
            }

            // estado actual de la pelea a medida que se hacen los rolls
             cout << "---------------------------" << endl;
             cout << "Player HP: " << playerHPLevel01 << " | Goblin HP: " << goblinHP << endl;
             cout << "---------------------------" << endl;


            // if statement por si el goblin esta muerto
            if (goblinHP <= 0) {

                cout << "Nice battle! You defeated the Goblins!" << endl;
                player.addXP(50);
                cout << "" << endl;
                cout << "Since you defeated the Goblins, you can keep searching for items in the map or you can access to the second level by pressing '2' (with enter)." << endl;
                cout << "NOTE: Once you go to the second level, you can't get back to the first level." << endl;
                cout <<	"Remember, you need to acquire sufficient XP to level up your player and also to gain more hitpoints." << endl;
                cout << "Take the Goblins symbol so that you don't need to fight him again." << endl;
                cout << "" << endl;
            }

            // if statement por si el jugador esta muerto
            if (playerHPLevel01 <= 0) {

                cout << "Game over! You were defeated by the Goblins!" << endl;
                cout << "" << endl;
                cout << "If you want to play again, run again the program." << endl;
                cout << "" << endl;
            }
        }
    }

};

class FightOrc {

private:
    int playerHPLevel02;
    int orcHP;

public:
    FightOrc(int playerHPOrc, int orcHPMonster) { // constructor para la pelea del Orc

    	playerHPLevel02 = playerHPOrc;
    	orcHP = orcHPMonster;
    }

    // funcion para el d20 para la dinamica de la pelea del jugador y el orc
    int rollD20() {

        return rand() % 20 + 1;
    }

    // declaro funcion void para hacer la pelea del jugador y el orc
    void orcFight(Player& player) {

        // aplico while loop para iniciar la pelea
        while (playerHPLevel02 > 0 && orcHP > 0) {

            // se lanzaran automaticamente los dados de iniciativa para saber quien atacara primero
            int playerInitiative = rollD20();
            int orcInitiative = rollD20();

            // if statement por si el rolld20 del jugador es menor (el atacara primero en ese caso)
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

                    cout << "The Orc evade the attack!" << endl;
                }

                else {

                    int dmgOrc = player.getStrength() + player.getAttackBonus();
                    cout << "You hit the Orc for " << dmgOrc << " damage!" << endl;
                    orcHP -= dmgOrc;
                }
            }

            else { // si el orc ataca primero (se hace lo mismo pero al revez)

                int orcAttackRoll = rollD20();

                if (orcAttackRoll == 20) {

                    cout << "Oh no! The Orc rolled a 20! You will get hit by maximum damage!" << endl;
                    playerHPLevel02 = 0;
                }

                else if (orcAttackRoll <= player.getDexterity()) {

                    cout << "Nice dodge! You evade the Orc attack." << endl;
                }

                else {

                    cout << "Oh no! The Orc hit you!" << endl;

                    playerHPLevel02 -= 9; // dmg de hits de los orcs son 9
                }
            }

            // estado actual de la pelea a medida que se hacen los rolls
             cout << "---------------------------" << endl;
             cout << "Player HP: " << playerHPLevel02 << " | Orc HP: " << orcHP << endl;
             cout << "---------------------------" << endl;

            // if statement por si el orc esta muerto
            if (orcHP <= 0) {

                cout << "Nice battle! You defeated the Orc!" << endl;
                player.addXP(100);
                cout << "" << endl;
                cout << "Since you defeated the Orc, you can keep searching for items in the map. You can also keep fighting more Orcs or you can access to the third level by pressing '3' (with enter)." << endl;
                cout << "NOTE: If you go to the third level map, you can't access to the first level and/or second level." << endl;
                cout <<	"Remember, you need to acquire sufficient XP to level up your player and also to gain more hitpoints." << endl;
                cout << "Take the Orc symbol so that you don't need to fight him again." << endl;
                cout << "" << endl;
            }

            // if statement por si el jugador esta muerto
            if (playerHPLevel02 <= 0) {

                cout << "Game over! You were defeated by the Orc." << endl;
                cout << "" << endl;
                cout << "If you want to play again, run again the program." << endl;
                cout << "" << endl;
            }
        }
    }
};

class FightOgre {

private:
    int playerHPLevel03;
    int ogreHP;

public:
    FightOgre(int playerHPOgre, int ogreHPMonster) {

    	playerHPLevel03 = playerHPOgre;
    	ogreHP = ogreHPMonster;
    }

    // funcion para el d20 para la dinamica de la pelea del jugador y el ogre
    int rollD20() {

        return rand() % 20 + 1;
    }

    // declaro funcion void para hacer la pelea del jugador y el ogre
    void ogreFight(Player& player) {

        // aplico while loop para iniciar la pelea
        while (playerHPLevel03 > 0 && ogreHP > 0) {

            // se lanzaran automaticamente los dados de iniciativa para saber quien atacara primero
            int playerInitiative = rollD20();
            int ogreInitiative = rollD20();

            // if statement por si el rolld20 del jugador es menor (el atacara primero en ese caso)
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

                    cout << "The Ogre evade the attack!" << endl;
                }

                else {

                    int dmgOgre = player.getStrength() + player.getAttackBonus();
                    cout << "You hit the Ogre for " << dmgOgre << " damage!" << endl;
                    ogreHP -= dmgOgre;
                }
            }

            else { // si el ogre ataca primero (se hace lo mismo pero al revez)

                int ogreAttackRoll = rollD20();

                if (ogreAttackRoll == 20) {

                    cout << "Oh no! The Ogre rolled a 20! You will get hit by maximum damage!" << endl;
                    playerHPLevel03 = 0;
                }

                else if (ogreAttackRoll <= player.getDexterity()) {

                    cout << "Nice dodge! You evade the Ogre attack." << endl;
                }

                else {

                    cout << "Oh no! The Ogre hit you!" << endl;
                    playerHPLevel03 -= 13; // hits del ogre son 13
                }
            }

            // estado actual de la pelea a medida que se hacen los rolls
             cout << "---------------------------" << endl;
             cout << "Player HP: " << playerHPLevel03 << " | Ogre HP: " << ogreHP << endl;
             cout << "---------------------------" << endl;


            // if statement por si el ogre esta muerto
            if (ogreHP <= 0) {

                cout << "Nice battle! You defeated the Ogre!" << endl;
                player.addXP(450);
                cout << "" << endl;
                cout << "You have survived all the levels defeating the enemies. The game is over." << endl;
                cout << "You can rest now for your long journey, fellow hunter." << endl;
                cout << "Take the Ogre symbol so that you don't need to fight him again." << endl;
                cout << "" << endl;
            }

            // if statement por si el jugador esta muerto
            if (playerHPLevel03 <= 0) {

                cout << "Game over! You were defeated by the Ogre." << endl;
                cout << "So far, but at the same time so close to finishing the game..." << endl;
                cout << "" << endl;
                cout << "If you want to play again, run again the program." << endl;
                cout << "" << endl;
            }
        }
    }
};

const int x = 23; // el largo en "x" del mapa
const int y = 29; // el largo en "y" del mapa

// declaro arreglo bidimensional
char level[x][y];

// declaro funcion para leer el archivo y para decodificar los numeros usando if y else if statements
void fileLevel(string filename) {

    ifstream inputLevelFile(filename);

    if (!inputLevelFile) {

        cout << "This is an error. The level file can't be found or opened..." << endl;
    }

    else { // aplico el procedimiento usando for loop para la x y la y

    for (int countX = 0; countX < y; countX++) {

        for (int countY = 0; countY < x; countY++) {

            char encodedChar;
            // la variable de caracter leera el archivo para cambiarlo con simbolos
            inputLevelFile >> encodedChar;

            // los simbolos se añaderan al arreglo en 2D
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

                 level[countX][countY] = '*'; // simbolo del goblin (level01)
            }
        }
     }
  }

    inputLevelFile.close(); // cierro el archivo
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

   			level02[countX2][countY2] = 'O'; // estos seran los simbolos de los enemigos del level02 (los orcs)
   		}
	  }
    }
  }

   inputLevelFile02.close(); // cierro el archivo
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

                 level03[countX3][countY3] = '$'; // simbolo del ogre (level03)
            }
        }
     }
  }

    inputLevel03File.close(); // cierro el archivo
}

// declaro funcion para poner en consola los niveles
void mapLevel() {

    for (int countX = 0; countX < y; countX++) {

        for (int countY = 0; countY < x; countY++) {

            cout << level[countX][countY];
        }

        cout << endl; // termino la linea del for loop
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

// esta funcion sera para colocar los items de manera aleatoria en el mapa
void randItems() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);

    // max items que el jugador puede tener son 10
    int maxItems = 10;

    // Coloco los objetos de manera aleatoria en el mapa con for loop
    for (int count = 0; count < maxItems; count++) {

        int itemsX = rand() % y + 1;
        int itemsY = rand() % x + 1;

        if (level[itemsX][itemsY] != '#' && level[itemsX][itemsY] != '*') { // para que los items no esten en las paredes ni en el Goblin

            level[itemsX][itemsY] = '/'; // simbolo de los items
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

        if (level02[itemsX2][itemsY2] != '#' && level02[itemsX2][itemsY2] != 'O') { // para que los items no esten en las paredes ni en el Orc

            level02[itemsX2][itemsY2] = '+'; // simbolo de los items
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

        if (level03[itemsX3][itemsY3] != '#' && level03[itemsX3][itemsY3] != '$') { // para que los items no esten en las paredes ni en el Ogre

            level03[itemsX3][itemsY3] = '.'; // simbolo de los items
        }
    }
}

// esta funcion sera para colocar los orcs de manera aleatoria en el mapa
void orcsLocation() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);

    int maxOrcs = 10; // numero maximo aleatorio

    // Coloco los orcs de manera aleatoria en el mapa con for loop
    for (int count = 0; count < maxOrcs; count++) {

        int itemsX2 = rand() % y2 + 1;
        int itemsY2 = rand() % x2 + 1;

        if (level02[itemsX2][itemsY2] != '#' && level02[itemsX2][itemsY2] != 'O') {

            level02[itemsX2][itemsY2] = '!'; // simbolo de los orcs
        }
    }
}

// esta funcion es para darle nombre a los items que estan aleatoriamente en los mapas. Aplico un string de vector
string stringItems() {

	  unsigned seed;
	  seed = time(0);
	  srand(seed);
                             // 0            // 1            // 2            // 3        // 4               // 5
	vector<string> items = {"Food.", "Healing Potion.", "Energy Potion.", "'e-Gold.'", "Coins.", "'Teleportation Stone.'"};

	int randItem = rand() % items.size(); // sin el +1 porque un vector empieza desde 0 y no desde el 1. (min valor es 0, no 1)

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
		cout << "You are going to be in different positions as you was in the level01 map or in the level02 map. There will be tougher enemies, be careful with the use of the " << endl;
	}

	return items[randItem];
}

// declaro funcion para que el jugador se mueva hacia arriba
void upPlayer(int& playerY, int& playerX) {

    int sevenRoomX1 = 19;
    int sevenRoomY1 = 11;

    int sixthRoomX1 = 9;
    int sixthRoomY1 = 3;

    if (playerY > 0 && level[playerY - 1][playerX] != '#') { // no va hacia una pared

        level[playerY][playerX] = ' ';
        playerY--;
        level[playerY][playerX] = '*';
    }

    else  {

    	cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // descripciones de los cuartos:
    if (playerX == sevenRoomX1 && playerY == sevenRoomY1) {

            cout << "In this room, a group of draconic faces has been carved into the west wall, and someone has scrawled 'The Guild of the Arrow and Lamp looted this place' on the west wall." << endl;
            cout << "Maybe this room will still have an item or not. Don't lose your hope!" << endl;
        }

        else if (playerX == sixthRoomX1 && playerY == sixthRoomY1) {

            cout << "This room have all the floor and walls color red along with torches in the walls. It could be... BLOOD?" << endl;
        }

    if (playerY > 0 && level[playerY - 1][playerX] == '/') {

    	cout << "You have found an item! It's " << stringItems() << endl;
        cout << "" << endl;
        cout << "If the item have an space, use '.'" << endl;
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

     if (playerY2 > 0 && level02[playerY2 - 1][playerX2] != '#') { // no va hacia una pared

        level02[playerY2][playerX2] = ' ';
        playerY2--;
        level02[playerY2][playerX2] = '*';
    }

    else  {

    	cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // descripciones de los cuartos:
     if (playerX2 == firstRoomX2222 && playerY2 == firstRoomY2222) {

            cout << "This room have torches in all the walls and it have a strong scent of BLOOD. Be careful out there!" << endl;
        }

         else if (playerX2 == secondRoomX2 && playerY2 == secondRoomY2) {

            cout << "The floor in this room have arrows pointing everywhere, it could be the location of the enemies." << endl;
        }

         else if (playerX2 == sixthRoomX2 && playerY2 == sixthRoomY2) {

            cout << "In a room covered with two torches of normal flames with the floor being covered with symbols everywhere, you found the reliable hunter for the second time." << endl;
            cout << "He saw strength and potential in yourself. He wish you the best luck fighting the Orcs." << endl;
        }

        else if (playerX2 == sevenRoomX22 && playerY2 == sevenRoomY22) {

            cout << "The walls of this room have been destroyed. The path is not very good to move on. Be careful while you are moving there." << endl;
        }

         else if (playerX2 == eightRoomX222 && playerY2 == eightRoomY222) {

            cout << "The room is illuminated very brightly, the floor and walls is pearl white and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

           else if (playerX2 == eightRoomX2222 && playerY2 == eightRoomY2222) {

            cout << "The room is illuminated very brightly, the floor and walls is pearl white and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

        else if (playerX2 == ninthRoomX22 && playerY2 == ninthRoomY22) {

            cout << "In this room there are torches with blue flames that are fading and the lighting is not good. Also there is also a lot of fog in the room." << endl;
            cout << "Be careful around you." << endl;
        }

           else if (playerX2 == tenthRoomX2 && playerY2 == tenthRoomY2) {

            cout << "In this room you heard sounds from everywhere. The floor have a lot of rocks and spikes. Be careful while you are moving in this room." << endl;
        }

    if (playerY2 > 0 && level02[playerY2 - 1][playerX2] == '+') {

     	cout << "You have found an item! It's " << stringItems() << endl;
     	cout << "" << endl;
     	cout << "If the item have an space, use '.'" << endl;
        cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
        cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
        cout << "Take the item symbol so that you don't need to take it up again." << endl;
     }

   else if ((playerY2 > 0 && level02[playerY2 - 1][playerX2] == 'O') || (playerY2 > 0 && level02[playerY2 - 1][playerX2] == '!')) {

            cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
            cout << "" << endl;
            cout << "This are the stats of the Orc:" << endl;

            // pongo los objetos de la clase de monster y orc para que salgan los stats del orc y la pelea completa
            Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
            orc.orcStats();

            FightOrc fight(player.getHitpoints(), 15);
            fight.orcFight(player);
          }
}

// declaro funcion para que el jugador se mueva hacia arriba
void upPlayer03(int& playerY3, int& playerX3, Player& player) {

    if (playerY3 > 0 && level03[playerY3 - 1][playerX3] != '#') { // no va hacia una pared

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
        	cout << "If the item have an space, use '.'" << endl;
            cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
            cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
            cout << "Take the item symbol so that you don't need to take it up again." << endl;
        }

       if (playerY3 > 0 && level03[playerY3 - 1][playerX3] == '$') {

               cout << "You have found the Ogre!! Prepare yourself for your final battle!!" << endl;
               cout << "" << endl;
               cout << "This are the stats of the Ogre:" << endl;

               Monster ogre("Ogre", 11, 59, 40, 19, 8, 16, 5, 7, 7, 2);
               ogre.ogreStats();

               FightOgre fight(player.getHitpoints(), 59);
               fight.ogreFight(player);
        }
}

// declaro funcion para que el jugador se mueva hacia abajo
void downPlayer(int& playerY, int& playerX) {

    int fourthRoomX1 = 9;
    int fourthRoomY1 = 25;

    int firstRoomX1 = 9;
    int firstRoomY1 = 15;

    int tenthRoomX1 = 1;
    int tenthRoomY1 = 17;

    if (playerY < y - 1 && level[playerY + 1][playerX] != '#') { // no va hacia una pared

        level[playerY][playerX] = ' ';
        playerY++;
        level[playerY][playerX] = '*';
    }

    else {

      	cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // descripciones de los cuartos:
    if (playerX == fourthRoomX1 && playerY == fourthRoomY1) {

           cout << "In this room, the walls that are part of the north direction has collapsed. The floor is covered with BLOODSTAINS and the lights in the room is often ON and OFF between an specific amount of seconds." << endl;
           cout << "MYSTERIOUS and SCARY, isn't it? Well, be careful when you are moving there." << endl;
        }

       else if (playerX == firstRoomX1 && playerY == firstRoomY1) {

            cout << "This room have numerous pillars lined to the south and east walls, and an iron ornaments are displayed in the north side of the room. The room is safe and you will have no issues when you are moving there." << endl;
        }

        else if (playerX == tenthRoomX1 && playerY == tenthRoomY1) {

            cout << "In this room, you have found the reliable hunter! He tells you the location of the enemy. The enemy is covering a portal in a dark, mysterious hallway." << endl;
            cout << "That hallway is covered with BLOOD, the floor and walls are color white." << endl;
        }

    if (playerY < y - 1 && level[playerY + 1][playerX] == '/') {

    	   cout << "You have found an item! It's " << stringItems() << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to take it up again." << endl;
       }
}

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

    if (playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] != '#') { // no va hacia una pared

        level02[playerY2][playerX2] = ' ';
        playerY2++;
        level02[playerY2][playerX2] = '*';
    }

    else {

      	cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // descripciones de los cuartos:
    if (playerX2 == fourthRoomX22 && playerY2 == fourthRoomY22) {

            cout << "In this room there are messages in the floor and in the walls. It is an unknown language and letter." << endl;
		    cout << "Maybe it is a sign of something important?" << endl;
        }

           else if (playerX2 == fourthRoomX222 && playerY2 == fourthRoomY222) {

            cout << "In this room there are messages in the floor and in the walls. It is an unknown language and letter." << endl;
		    cout << "Maybe it is a sign of something important?" << endl;
        }

        else if (playerX2 == thirdRoomX22 && playerY2 == thirdRoomY22) {

            cout << "This room have good lighting and there are symbols of faces in the walls along with a pair of torches on the sides." << endl;
		    cout << "Maybe those faces are from the enemies of this map?" << endl;
        }

        else if (playerX2 == thirdRoomX222 && playerY2 == thirdRoomY222) {

            cout << "This room have good lighting and there are symbols of faces in the walls along with a pair of torches on the sides." << endl;
		    cout << "Maybe those faces are from the enemies of this map?" << endl;
        }

         else if (playerX2 == secondRoomX22 && playerY2 == secondRoomY22) {

            cout << "The floor in this room have arrows pointing everywhere, it could be the location of the enemies." << endl;
        }

           else if (playerX2 == firstRoomX2 && playerY2 == firstRoomY2) {

            cout << "This room have torches in all the walls and it have a strong scent of BLOOD. Be careful out there!" << endl;
        }

          else if (playerX2 == firstRoomX22 && playerY2 == firstRoomY22) {

            cout << "This room have torches in all the walls and it have a strong scent of BLOOD. Be careful out there!" << endl;
        }

          else if (playerX2 == firstRoomX222 && playerY2 == firstRoomY222) {

            cout << "This room have torches in all the walls and it have a strong scent of BLOOD. Be careful out there!" << endl;
        }

          else if (playerX2 == thirdRoomX22 && playerY2 == thirdRoomY22) {

            cout << "This room have torches in all the walls and it have a strong scent of BLOOD. Be careful out there!" << endl;
        }

         else if (playerX2 == thirdRoomX222 && playerY2 == thirdRoomY222) {

            cout << "This room have torches in all the walls and it have a strong scent of BLOOD. Be careful out there!" << endl;
        }

        else if (playerX2 == sevenRoomX222 && playerY2 == sevenRoomY222) {

            cout << "The walls of this room have been destroyed. The path is not very good to move on. Be careful while you are moving there." << endl;
        }

        else if (playerX2 == eightRoomX22 && playerY2 == eightRoomY22) {

            cout << "The room is illuminated very brightly, the floor and walls is pearl white and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

        else if (playerX2 == ninthRoomX2 && playerY2 == ninthRoomY2) {

            cout << "In this room there are torches with blue flames that are fading and the lighting is not good. Also there is also a lot of fog in the room." << endl;
            cout << "Be careful around you." << endl;
        }

    if (playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] == '+') {

     	cout << "You have found an item! It's " << stringItems() << endl;
     	cout << "" << endl;
     	cout << "If the item have an space, use '.'" << endl;
        cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
        cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
        cout << "Take the item symbol so that you don't need to take it up again." << endl;
     }

       else if ((playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] == 'O') || (playerY2 < y2 - 1 && level02[playerY2 + 1][playerX2] == '!')) {

          cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
          cout << "" << endl;
          cout << "This are the stats of the Orc:" << endl;

          Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
          orc.orcStats();

          FightOrc fight(player.getHitpoints(), 15);
          fight.orcFight(player);
    }
}

// declaro funcion para que el jugador se mueva hacia abajo
void downPlayer03(int& playerY3, int& playerX3) {

    int fourthRoomX3 = 7;
    int fourthRoomY3 = 13;

    int fourthRoomX33 = 9;
    int fourthRoomY33 = 13;

    int firstRoomX3 = 17;
    int firstRoomY3 = 11;

    if (playerY3 < y3 - 1 && level03[playerY3 + 1][playerX3] != '#') { // no va hacia una pared

        level03[playerY3][playerX3] = ' ';
        playerY3++;
        level03[playerY3][playerX3] = '*';
    }

    else {

      	cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // descripciones de los cuartos:
       if (playerX3 == firstRoomX3 && playerY3 == firstRoomY3) {

        cout << "This room have a friendly atmosphere and there are torches illuminating all the room." << endl;
        cout << "For the last time, you have found the reliable hunter! He was waiting for your appearance in this final level." << endl;
        cout << "This time the reliable hunter will guide you to the final boss, and he will fight with you until the very end." << endl;
      }

      else if (playerX3 == fourthRoomX3 && playerY3 == fourthRoomY3) {

        cout << "The atmosphere in this room is very ominous. It is completely quiet, but who knows what can happen in the area..." << endl;
        cout << "Always be prepared for anything, you can't give up now in the final level." << endl;
      }

      else if (playerX3 == fourthRoomX33 && playerY3 == fourthRoomY33) {

        cout << "The atmosphere in this room is very ominous. It is completely quiet, but who knows what can happen in the area..." << endl;
        cout << "Always be prepared for anything, you can't give up now in the final level." << endl;
      }

        if (playerY3 < y3 - 1 && level03[playerY3 + 1][playerX3] == '.') {

            	cout << "You have found an item! It's " << stringItems() << endl;
            	cout << "" << endl;
            	cout << "If the item have an space, use '.'" << endl;
                cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
                cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
                cout << "Take the item symbol so that you don't need to take it up again." << endl;
        }
}

// declaro funcion para que el jugador se mueva hacia la izquierda
void leftPlayer(int& playerY, int& playerX) {

   int fourthRoomX11 = 9;
   int fourthRoomY11 = 25;

   int eightRoomX1 = 5;
   int eightRoomY1 = 7;

   int fifthRoomX1 = 19;
   int fifthRoomY1 = 1;

    if (playerX > 0 && level[playerY][playerX - 1] != '#') { // no va hacia una pared

        level[playerY][playerX] = ' ';
        playerX--;
        level[playerY][playerX] = '*';
    }

    else {

         cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // descripciones de los cuartos
        if (playerX == fourthRoomX11 && playerY == fourthRoomY11) {

           cout << "In this room, the walls that are part of the north direction has collapsed. The floor is covered with BLOODSTAINS and the lights in the room is often ON and OFF between an specific ammount of seconds." << endl;
           cout << "MYSTERIOUS and SCARY, isn't it? Well, be careful when you are moving there." << endl;
        }

        else if (playerX == eightRoomX1 && playerY == eightRoomY1) {

            cout << "In this room, someone has scrawled 'The enemy is closer between this room and the other room...' in draconic script on the south wall, and knocking can be faintly heard near the south wall as well." << endl;
		    cout << "Be aware of your surroundings!" << endl;
        }

         else if (playerX == fifthRoomX1 && playerY == fifthRoomY1) {

            cout << "In this room, some of the walls have BLOODSTAINS and there is no lighting." << endl;
		    cout << "Be careful out there!" << endl;
        }

    if (playerX > 0 && level[playerY][playerX - 1] == '/') {

    	   cout << "You have found an item! It's " << stringItems() << endl;
    	   cout << "" << endl;
    	   cout << "If the item have an space, use '.'" << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to take it up again." << endl;
     }
}

void leftPlayer02(int& playerY2, int& playerX2, Player& player) {

     int thirdRoomX2 = 7;
     int thirdRoomY2 = 25;

     int fifthRoomX2 = 7;
     int fifthRoomY2 = 3;

     int tenthRoomX22 = 19;
     int tenthRoomY22 = 11;

    if (playerX2 > 0 && level02[playerY2][playerX2 - 1] != '#') { // no va hacia una pared

        level02[playerY2][playerX2] = ' ';
        playerX2--;
        level02[playerY2][playerX2] = '*';
    }

    else {

         cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // descripciones de los cuartos
       if (playerX2 == thirdRoomX2 && playerY2 == thirdRoomY2) {

            cout << "This room have good lighting and there are symbols of faces in the walls along with a pair of torches on the sides." << endl;
            cout << "Maybe those faces are from the enemies of this map?" << endl;
        }

         else if (playerX2 == fifthRoomX2 && playerY2 == fifthRoomY2) {

            cout << "In this room there are sounds of echoes and whispers that go to the hallway of the east direction." << endl;
            cout << "Most probably in that hallway there are an Orc!" << endl;
        }

        else if (playerX2 == tenthRoomX22 && playerY2 == tenthRoomY22) {

            cout << "In this room you heard sounds from everywhere. The floor have a lot of rocks and spikes. Be careful while you are moving in this room." << endl;
        }

    if (playerX2 > 0 && level02[playerY2][playerX2 - 1] == '+') {

       	   cout << "You have found an item! It's " << stringItems() << endl;
       	   cout << "" << endl;
       	   cout << "If the item have an space, use '.'" << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to take it up again." << endl;
        }

    else if ((playerX2 > 0 && level02[playerY2][playerX2 - 1] == 'O') || (playerX2 > 0 && level02[playerY2][playerX2 - 1] == '!')) {

    	cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
    	cout << "" << endl;
        cout << "This are the stats of the Orc:" << endl;

        Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
        orc.orcStats();

    	FightOrc fight(player.getHitpoints(), 15);
    	fight.orcFight(player);
    }
}

// declaro funcion para que el jugador se mueva hacia la izquierda
void leftPlayer03(int& playerY3, int& playerX3) {

    int secondRoomX3 = 3;
    int secondRoomY3 = 17;

    int thirdRoomX3 = 15;
    int thirdRoomY3 = 7;

    if (playerX3 > 0 && level03[playerY3][playerX3 - 1] != '#') { // no va hacia una pared

        level03[playerY3][playerX3] = ' ';
        playerX3--;
        level03[playerY3][playerX3] = '*';
    }

    else {

         cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // descripciones de los cuartos:
    if (playerX3 == secondRoomX3 && playerY3 == secondRoomY3) {

            cout << "You can't enter to this room. The whole room and hallway was damaged. In this map there is a lot of destruction going on..." << endl;
        }

        else if (playerX3 == thirdRoomX3 && playerY3 == thirdRoomY3) {

            cout << "You can't enter to this room. The entrance is completely blocked and the floor has many holes." << endl;
        }

           if (playerX3 > 0 && level03[playerY3][playerX3 - 1] == '.') {

            cout << "You have found an item! It's " << stringItems() << endl;
            cout << "" << endl;
            cout << "If the item have an space, use '.'" << endl;
            cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
            cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
            cout << "Take the item symbol so that you don't need to take it up again." << endl;
        }
}

// declaro funcion para que el jugador se mueva hacia la derecha
void rightPlayer(int& playerY, int& playerX, Player& player) {

     int thirdRoomX1 = 13;
     int thirdRoomY1 = 25;

     int ninthRoomX1 = 17;
     int ninthRoomY1 = 19;

     int secondRoomX1 = 9;
     int secondRoomY1 = 9;

    if (playerX < x - 1 && level[playerY][playerX + 1] != '#') { // no va hacia una pared

        level[playerY][playerX] = ' ';
        playerX++;
        level[playerY][playerX] = '*';
    }

    else {

        cout << "You can't move in that direction. There is a wall there." << endl;
      }

    // descripciones de los cuartos:
        if (playerX == thirdRoomX1 && playerY == thirdRoomY1) {

            cout << "This room doesn't have bloodstains or fights. The walls in this room are pure violet and it's actually a safe room." << endl;
		    cout << "It have very good lighting and is not dark at all, you can move without worries there." << endl;
        }

        else if (playerX == ninthRoomX1 && playerY == ninthRoomY1) {

            cout << "The floor in this room is covered with square tiles, alternating white and black." << endl;
        }

         else if (playerX == secondRoomX1 && playerY == secondRoomY1) {

            cout << "The floor and walls in this room have a color of dark red-orange. There are CORPSES everywhere. Be prepare for the worst!" << endl;
            cout << "If you keep searching for the enemy, maybe a reliable hunter will tell you his location." << endl;
        }

    if (playerX < x - 1 && level[playerY][playerX + 1] == '/') {

        	cout << "You have found an item! It's " << stringItems() << endl;
        	cout << "" << endl;
        	cout << "If the item have an space, use '.'" << endl;
            cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
            cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
            cout << "Take the item symbol so that you don't need to take it up again." << endl;
         }

    else if (playerX < x - 1 && level[playerY][playerX + 1] == '*') {

    	cout << "You have found the Goblins!! Prepare yourself for the battle!!" << endl;
    	cout << "" << endl;
        cout << "This are the stats of the Goblins: " << endl;

         Monster goblin("Goblin", 15, 7, 30, 8, 14, 10, 10, 8, 8, 2);
         goblin.goblinStats();

    	FightGoblin fight(player.getHitpoints(), 7);
    	fight.goblinFight(player);
    }
}

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

if (playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] != '#') { // no va hacia una pared

        level02[playerY2][playerX2] = ' ';
        playerX2++;
        level02[playerY2][playerX2] = '*';
    }

    else {

        cout << "You can't move in that direction. There is a wall there." << endl;
    }

    // descripciones de los cuartos:
       if (playerX2 == fourthRoomX2 && playerY2 == fourthRoomY2) {

            cout << "In this room there are messages in the floor and in the walls. It is an unknown language and letter." << endl;
		    cout << "Maybe it is a sign of something important?" << endl;
        }

         else if (playerX2 == sixthRoomX22 && playerY2 == sixthRoomY22) {

            cout << "In a room covered with two torches of normal flames with the floor being covered with symbols everywhere, you found the reliable hunter for the second time." << endl;
            cout << "He saw strength and potential in yourself. He wish you the best luck fighting the Orcs." << endl;
        }

        else if (playerX2 == sevenRoomX2 && playerY2 == sevenRoomY2) {

            cout << "The walls of this room have been destroyed. The path is not very good to move on. Be careful while you are moving there." << endl;
        }

        else if (playerX2 == eightRoomX2 && playerY2 == eightRoomY2) {

            cout << "The room is illuminated very brightly, the floor and walls is pearl white and you found a letter saying: 'I hope that he made it through the first level'." << endl;
            cout << "It could be a letter from the reliable hunter from the first level. That means that he may be in a specific part of this level, trying to survive..." << endl;
        }

         else if (playerX2 == ninthRoomX222 && playerY2 == ninthRoomY222) {

            cout << "In this room there are torches with blue flames that are fading and the lighting is not good. Also there is also a lot of fog in the room." << endl;
            cout << "Be careful around you." << endl;
        }

         else if (playerX2 == tenthRoomX222 && playerY2 == tenthRoomY222) {

            cout << "You heard sounds from everywhere. The floor have a lot of rocks and spikes. Be careful while you are moving there." << endl;
        }

    if (playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] == '+') {

       	   cout << "You have found an item! It's " << stringItems() << endl;
       	   cout << "" << endl;
       	   cout << "If the item have an space, use '.'" << endl;
           cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
           cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
           cout << "Take the item symbol so that you don't need to take it up again." << endl;
        }

    else if ((playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] == 'O') || (playerX2 < x2 - 1 && level02[playerY2][playerX2 + 1] == '!')) {

    	cout << "You have found an Orc!! Prepare yourself for the battle!!" << endl;
    	cout << "" << endl;
        cout << "This are the stats of the Orc:" << endl;

        Monster orc("Orc", 13, 15, 30, 16, 12, 16, 7, 11, 10, 2);
        orc.orcStats();

    	FightOrc fight(player.getHitpoints(), 15);
    	fight.orcFight(player);
    }
}

// declaro funcion para que el jugador se mueva hacia la derecha
void rightPlayer03(int& playerY3, int& playerX3) {

    if (playerX3 < x3 - 1 && level03[playerY3][playerX3 + 1] != '#') { // no va hacia una pared

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
        cout << "If the item have an space, use '.'" << endl;
        cout << "Since you have found an item, you need to enter 'u' or 'U' to put the name of the item in your inventory." << endl;
        cout << "Remember, if you want to see the items that you have in the inventory, just enter 'i' or 'I'." << endl;
        cout << "Take the item symbol so that you don't need to take it up again." << endl;
    }
}

void showInventory(vector<string> &inventory) {

    if (inventory.empty()) {

        cout << "Your inventory is empty." << endl;
    }

    else {

        cout << "This is the list that you have in the inventory:" << endl;
        cout << "" << endl;

        for (int count = 0; count < inventory.size(); count++) {

            string& item = inventory[count];
            cout << "- " << item << endl;
        }
    }
}

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

        char decision; // variable para el usuario
        bool badChoiceKeybind;
        badChoiceKeybind = true;

        while (badChoiceKeybind) {

        cout << "Do you accept this challenge? (y/n): " << endl;
        cin >> decision;

        if (decision == 'y' || decision == 'Y') {

            cout << "You have accepted the challenge!" << endl;
            cout << "You find yourself dressed in strange clothes, with two (2) objects with which to help you along your journey: a sword and a shield." << endl;
            cout << "" << endl;

    // empiezo la posicion del jugador desde 0
    int playerX = 0;
    int playerY = 0;

    // abro el archivo en main llamando la funcion del level
    fileLevel("level01.csv");

    // posiciono el jugador en el nivel con for loop para x y para y
    for (int countX = 0; countX < y; countX++) {

        for (int countY = 0; countY < x; countY++) {

            if (level[countX][countY] == '*') { // el jugador empezara en este simbolo. En los otros mapas sera un simbolo distinto.

                playerY = countX;
                playerX = countY;
            }
        }
    }

        string userPlayer; // variable para el usuario

        cout << "Enter your name: " << endl;
        cin >> userPlayer;

        cout << "This are the stats that you have in this run: " << endl;
        cout << "" << endl;

        // se aplicara el objeto del jugador con sus stats
        Player player(userPlayer, 5);

        string extraAttack = "Yes"; // el jugador siempre tendra un ataque extra

        // output de los stats del jugador (llamo las funciones)
        cout << "Name: " << userPlayer << endl;
        cout << "Level: " << player.getLevel() << endl;
        cout << "Strength: " << player.getStrength() << endl;
        cout << "Dexterity: " << player.getDexterity() << endl;
        cout << "Constitution: " << player.getConstitution() << endl;
        cout << "Intelligence: " << player.getIntelligence() << endl;
        cout << "Wisdom: " << player.getWisdom() << endl;
        cout << "Charisma: " << player.getCharisma() << endl;

        // output de los puntos de golpe del jugador (llamo la funcion)
        cout << "Hitpoints: " << player.getHitpoints() << endl;

        // output del bono de ataque del jugador (llamo la funcion)
        cout << "Attack Bonus: " << player.getAttackBonus() << endl;

        // output del ataque extra del jugador
        cout << "Extra Attack: " << extraAttack << endl;
        cout << "" << endl;

        cout << "Welcome to the first level of the tower." << endl;
        cout << "You are going to start with the south symbol of '*'. That's the location of your player in the very first level." << endl;
        cout << "REMEMBER: Your player symbol is always going to be '*' in all the levels." << endl;
        cout << "The towers are lightly illuminated with non removable torches every 20 feet. Vision is not impaired in any way inside the towers. There are strange sounds all around you..." << endl;
        cout << "" << endl;

        cout << "Good luck out there, fellow hunter." << endl;
        cout << "May the sword and shield guide you to your journey." << endl;
        cout << "" << endl;

        cout << "This are the keybinds to move in the levels: " << endl;
        cout << "w or W (with Enter) = north // s or S (with Enter) = south // d or D (with Enter) = east // a or A (with Enter) = west." << endl;
        cout << "You can also left the game with this keybinds if you want: q or Q (with Enter)." << endl;
        cout << "NOTE: You need to press the 'q' and 'Enter' or 'Q' and 'Enter' three times to leave the game if you are on level01." << endl;
        cout << "Two times if you are on level02 and one time if you are on level03." << endl;
        cout << "You can see the items that you have in the inventory by pressing 'i' or 'I' (with Enter)" << endl;
        cout << "" << endl;
        cout << "Enter the corresponding keybinds to move in the levels: " << endl;
        cout << "" << endl;

    // llamo la funcion de randItems para colocar los objetos en el mapa
    randItems();

    // llamo la funcion de mapLevel para mostrar el mapa en consola
    mapLevel();

    // declaro un flag-controlled while loop para las direcciones del jugador
        bool continueLoop; // declaro variable con boolean para saber si el while loop va a continuar o no
        continueLoop = true;
        char directionAndMaps; // variable para el jugador en donde se movera en respecto a la tecla que use y tambien para abrir el mapa 2

        while (continueLoop) {

            cin >> directionAndMaps;

            if (directionAndMaps == 'q' || directionAndMaps == 'Q') {

                badChoiceKeybind = false;
                continueLoop = false; // el while loop se va a detener de ejecutarse ya que el jugador dejo de jugar

                cout << "You left the first level..." << endl;
            }

            else { // si se mantiene en cierto pues se ejecutara como el personaje se va a mover llamando las funciones

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

                string foundItem1; // variable para el usuario

                cout << "Enter the item name: " << endl;
                cin >> foundItem1;

                inventory.push_back(foundItem1);

                cout << "Now you added the " << foundItem1 << " in your inventory." << endl;
                cout << "REMEMBER: The maximum of items that you can have in your inventory is 10." << endl;
                cout << "You always needs to check how many items you have." << endl;
         }

                else {

                    cout << "" << endl;
                    cout << "Your inventory is already full. You can't add more than 10 items." << endl;
                }
            }

            else if (directionAndMaps == 'i' || directionAndMaps == 'I') {

                showInventory(inventory);
            }

                else if (directionAndMaps == '2') { // Cuando el jugador vaya de mapa 1 a mapa 2

                    continueLoop = false;
                	cout << "You are now in level02. You are going to fight with the Orcs to pass to the final level" << endl;
                    cout << "In this level your location is the 'O' that is in the middle of the map." << endl;
                	cout <<	"NOTE: If you want to fight more Orcs, you can press one, two or more times the following keybinds: 'o' or 'O' (with Enter)." << endl;
                    cout << "You also need to move so they can spawn on the map." << endl;
                	cout << "If you do so, the probabilities of your death is HIGHER than the usual." << endl;
                	cout << "But you will get more combat experience, XP and more prepared for the final boss in the final map." << endl;
                	cout << "Everything is up to you..." << endl;
                	cout << "" << endl;
                	fileLevel02("level02.csv");
                	randItemsLevel02();
                	mapLevel02();
                }

                 else {

                	cout << "You can't move with that keybind. Enter a correctly keybind to move." << endl;
                }
            }
        }

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

                string foundItem2; // variable para el usuario

                cout << "Enter the item name: " << endl;
                cin >> foundItem2;

                inventory.push_back(foundItem2);

                cout << "Now you added the " << foundItem2 << " in your inventory." << endl;
                cout << "REMEMBER: The maximum of items that you can have in your inventory is 10." << endl;
                cout << "You always needs to check how many items you have." << endl;
         }

                else {

                    cout << "" << endl;
                    cout << "Your inventory is already full. You can't add more than 10 items." << endl;
                }
            }

            else if (directionLevel02Map == 'i' || directionLevel02Map == 'I') {

                showInventory(inventory);
            }

                else if (directionLevel02Map == 'o' || directionLevel02Map == 'O') { // para que aparezcan mas orcs en el mapa

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

        	        cout << "You can't move with that keybind. Enter a correctly keybind to move." << endl;
        	    }
            }
        }

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

                string foundItem3; // variable para el usuario

                cout << "Enter the item name: " << endl;
                cin >> foundItem3;

                inventory.push_back(foundItem3);

                cout << "Now you added the " << foundItem3 << " in your inventory." << endl;
                cout << "REMEMBER: The maximum of items that you can have in your inventory is 10." << endl;
                cout << "You always needs to check how many items you have." << endl;
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

        	        cout << "You can't move with that keybind. Enter a correctly keybind to move." << endl;
        	    }
            }
        }
    }

        else if (decision == 'n' || decision == 'N') {

            badChoiceKeybind = false;
            cout << "You fall asleep, return to the place you were before all this, forgetting everything, but always having a nagging feeling that you had a brush with greatness, but decided to pass on it." << endl;
        }

          else {

            cout << "You enter an incorrect keybind. Enter a correctly keybind (between 'y' // 'Y' or 'n' // 'N')." << endl;
        }
    }

        return 0;
	}
