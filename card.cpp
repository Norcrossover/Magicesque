// Kobe Norcross; CS 202; card.cpp
/*
 *
 */


#include "card.h"
using namespace std;



// card card XD (Implementation) 
card::card() : type(nullptr), name(), description() {}



card::card(char* n_type, string n_name, string n_desc) : name(n_name), description(n_desc) 
{
	type = new char[strlen(n_type)+1];
	strcpy(type, n_type);
}



card::card(const card& new_card)
{
	this->type = new char[strlen(new_card.type)+1];
	strcpy(this->type, new_card.type);
	this->name = new_card.name;
	this->description = new_card.description;
}

	
	
bool card::compare_type(char* type_cmp) const
{
	return (strcmp(this->type, type_cmp));
}



card::~card()
{
	if (type) delete [] type;
	type = nullptr;
}



//-----------------------------------------------------------------------------------------------------------------
// attack card
attack::attack(int atk, char* type, string new_name, string new_description) : card(type, new_name, new_description), damage(atk) {}



attack::attack(const attack& new_card) : card(new_card), damage(new_card.damage) {}



//bool attack::attack_player(int& player_health);
void attack::display() const
{
	cout << "Card Name: " << name << endl;
	cout << "Attack Damage: " << damage << endl;
	cout << "Description: " << description << endl;
}
//-----------------------------------------------------------------------------------------------------------------
// defense card
defense::defense(int val, char* n_type, const string n_name, const string n_desc) : card(n_type, n_name, n_desc), shield(val) {}



defense::defense(const defense& new_defense_card) : card(new_defense_card), shield(new_defense_card.shield) {}



void defense::display() const
{
	cout << "Card Name: " << name << endl;
	cout << "Shield amount: " << shield << endl;
	cout << "Description: " << description << endl;
}



//-----------------------------------------------------------------------------------------------------------------
// spell card
spell::spell() : damage(0), mana_cost(0), casting_quip(nullptr) {}



spell::spell(const spell& new_card) : card(new_card), damage(new_card.damage), mana_cost(new_card.mana_cost), casting_quip(new_card.casting_quip) {}



spell::spell(int val, char* type, string new_name, string n_desc, char* quip, int mana) : card(type, new_name, n_desc), damage(val), mana_cost(mana) 
{
	casting_quip = new char[strlen(quip)+1];
	strcpy(casting_quip, quip);
} 



spell::~spell()
{
	if (casting_quip) delete casting_quip;
	casting_quip = nullptr;
	damage = 0;
	mana_cost = 0;
}



/*
bool spell::cast_spell(player& enemy)
{
	// check if it's the heal status spell
	// call enemy's damage function to attack them
}



bool break_spell(bool& status)
{
	status = false;
}
*/



void spell::display() const
{
	cout << "Card Name: " << name << endl;
	cout << "Spell damage: " << damage << endl;
	cout << "Description: " << description << endl;
}
