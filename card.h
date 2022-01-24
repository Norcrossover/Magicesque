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
		card(const char* type, const std::string name);
		card(const card& new_card);  				// Copy Constructor
		virtual ~card();
		virtual void display() const;				// virtual display function that allows for the dynamic binding of the derived cards
		virtual void activate_card(); 				// virtual activate card function that will activate it 
		virtual void deactivate_card();
		bool compare_type(const char* type_comparison) const;	// It will compare the types, returns true if they're match or false otherwise
		bool is_active();					// checks if the card has been played
	protected:
		char* type;
		std::string name;
		bool active;						// new bool to check if the card is in play
};



class attack : public card
{
	public:
		attack(int new_attack_value, const char* type, const std::string new_name);
		//bool attack_player(player& player);
		bool attack_player(int& player_health);
		void activate_card(); 
		void deactivate_card();
		void display() const;
	protected:
		int damage;
};



class defense : public card
{
	public:
		defense(int new_defense_value, const char* type, const std::string new_name);
		bool heal_player(int& player_health);
		void activate_card(); 
		void deactivate_card();
		void display() const;
	protected:
		int shield;
};



class spell : public card
{
	public:
		spell();
		spell(int new_spell_card, int new_mana_cost, const char* type, const std::string new_name);
		~spell();
		bool cast_spell(int& player_health);
		void activate_card();
		void deactivate_card();
		void display() const;
	protected:
		int damage;
		int mana_cost;
		char * casting_quip;				       	// The phrase said by wizards when casting a spell XD 	
};



#endif
