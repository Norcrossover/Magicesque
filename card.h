// Kobe Norcross CS 202 card.h
/*
 *
 * This file is to represent the various cards. The classes included are card, attack, defense, and spell.
 * Planning on using Dynamic Binding in order to allow for one Deck of cards
 *
 */



#ifndef CARD_H
#define CARD_H
//#include "game.h"
#include <string>
#include <iostream>
#include <cstring>

class card
{
	public:
		card();
		card(char* new_type, std::string new_name, std::string new_description);
		card(const card& new_card);  				// Copy Constructor
		~card();
		bool compare_type(char* type_comparison) const;	// It will compare the types, returns true if they're match or false otherwise
	protected:
		char* type;
		std::string name;
		std::string description;
};



class attack : public card
{
	public:
		attack(int new_attack_value, char* type, const std::string new_name, const std::string new_description);
		attack(const attack& new_attack_card);
		//bool attack_player(player& player);
		bool attack_player(int& player_health);
		void display() const;
	protected:
		int damage;
};



class defense : public card
{
	public:
		defense(int new_defense_value, char* type, const std::string new_name, const std::string new_description);
		defense(const defense& new_defense_card);
		bool heal_player(int& player_health);
		void display() const;
	protected:
		int shield;
};



class spell : public card
{
	public:
		spell();
		spell(int new_spell_card, char* type, const std::string new_name, const std::string new_description, char* quip, int mana);
		spell(const spell& new_card);
		~spell();
		bool cast_spell(int& player_health);
		void break_spell(bool& status);
		void display() const;
	protected:
		int damage;
		int mana_cost;
		char * casting_quip;				       	// The phrase said by wizards when casting a spell XD 	
};



#endif
