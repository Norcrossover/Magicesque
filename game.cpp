// Kobe Norcross; CS 202; game.cpp
/*
 *
 */
#include "game.h"
using namespace std;



// Default constructor
//player::player() : hand(NULL), health(10), mana(5) {}


// Destructor
player::~player()
{
	if (hand) delete hand;
	hand = nullptr;
	health = 0;
	mana = 0;
}



/*
This function takes in a damage value and applies it to the player
*/
void player::take_damage(int damage)
{
	if (health - damage < 0) 
	{
		health = 0;
		return;
	}
	health -= damage;
	std::cout << " has taken " << damage << " damage!!!" << std::endl << std::endl;
}



/*
This function takes in a healing value and applies it to the player
*/
void player::heal(int heal)
{
	if (health + heal > maxHealth)
	{
		health = maxHealth;
		std::cout << "Healed to full health!" << std::endl << std::endl;
		return;
	}
	health += heal;
	std::cout << " has healed for " << heal << " points!!!" << std::endl << std:: endl;
}



/*
This function takes in a mana value to regen some mana for the player
*/
void player::gain_mana(const int& manaRegen)
{
	if (mana + manaRegen > maxMana)
	{
		mana = maxMana;
		return;
	}
	mana += manaRegen;
	std::cout << " gained " << mana << " mana!!!" << std::endl << std::endl;
}



// Wrapper function to display the player's hand
void player::display() const
{
	hand->display();
}

//-----------------------------------------
//		Game Implementation
//-----------------------------------------
// Default constructor
Game::Game() : one(NULL), two(NULL), deck(NULL), round(0), turn(0) {}



Game::Game(char* file_name)
{
	ifstream input;
	input(file_name);
	if (input.good())
	{
		
// Destructor
Game::~Game()
{
	if (one) delete one;
	one = NULL;
	if (two) delete two;
	two = NULL;
	if (deck) delete deck;
	deck = NULL:
	round = turn = 0;
}



// clears the terminal screen
void Game::clearScreen()
{
	for (int i = 0; i < 50; i++) cout << endl;
}



// what the function name says lol
void Game::outputWelcomeMessage()
{
	clearScreen();
	cout << "				WELCOME TOOOOOOOOOOOO"							  << std::endl;
	cout << "					..." 								  << std::endl;
	cout << "----------------------------------------------------------------------------------------------------   " << std::endl;
	cout << "_____ ______   ________  ________  ___  ________  _______   ________  ________  ___  ___  _______      " << std::endl;
	cout << "|\/   _ \  _   \|\   __  \|\   ____\|\  \|\   ____\|\  ___ \ |\   ____\|\   __  \|\  \|\  \|\  ___ \    " << std::endl; 
	cout << "\/ \  \\\__\ \  \ \  \|\  \ \  \___|\ \  \ \  \___|\ \   __/|\ \  \___|\ \  \|\  \ \  \\\  \ \   __/|   " << std::endl; 
 	cout << "\/ \  \\|__| \  \ \   __  \ \  \  __\ \  \ \  \    \ \  \_|/_\ \_____  \ \  \\\  \ \  \\\  \ \  \_|/__  " << std::endl;  
  	cout << "\/ \  \    \ \  \ \  \ \  \ \  \|\  \ \  \ \  \____\ \  \_|\ \|____|\  \ \  \\\  \ \  \\\  \ \  \_|\ \  " << std::endl; 
   	cout << "\/ \__\    \ \__\ \__\ \__\ \_______\ \__\ \_______\ \_______\____\_\  \ \_____  \ \_______\ \_______\  " << std::endl;
    	cout << "\/|__|     \|__|\|__|\|__|\|_______|\|__|\|_______|\|_______|\_________\|___| \__\|_______|\|_______|   " << std::endl;
        cout << "                                              \/|_________|     \|__|                   		" << std::endl;
        cout << " 					       \/|_________|     \|__|                   		" << std::endl;
	cout << "----------------------------------------------------------------------------------------------------   " << std::endl;
}



// Initializes each player with the starting amount of cards.
// It'll go through that amount and call a wrapper function to the hand class and add a new Node in.
// The Node will be received from the Deck class
void Game::initplayers()
{
	int starting = 10;
	for (int i = 0; i < starting; i++)
	{
		// need to call a wrapper function as the argument from deck
		one->addCard(deck->drawCard());
		two->addCard(deck->drawCard());
	}
	// function to choose who goes first
	flipCoin();
}




returns a random value, 1 or 0 to choose the player
bool Game::flipCoin()
{
	return false;
}



Displays the hand of a player
void Game::display(int player) const
{
	if (player == 0) one->display();
	else two->display;	
}



Synopsis: The function that runs the game 
Output a statement that welcomes the users to the game

bool Game::gamePlay()
{
