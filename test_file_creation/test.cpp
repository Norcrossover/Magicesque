//char* card_type;string card_name;string card_description;int value;int mana_cost
#include <random>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}
int main(){
	const char* attack = "atk";
	const char* defense =  "def";
	const char* spell = "spl";
	const char* types[3] = {attack, defense, spell};
	int damage_vals[3] = {5, 10, 15};
	int healing_vals[3] = {3, 5, 7};
	int spells[1] = {30};
	int mana_cost[3] = {0, 0, 20};
	string damage_names[3] = {"rusty sword", "iron sword", "MASTER SWORD"};
	string healing_names[3] = {"wooden shield", "iron shield", "MASTER SHIELD"};
	string spell_names[1] = {"FIREBALLLLLLLL"};
	int cards = 50, items = 0, element = 0;
	char del = ';';
	ofstream out;
	out.open("test.txt");
	if (out.good())
	{
		for (int i = 0; i < cards; i++)
		{
			element = random(0, 2); 
			if (element == 2) out << types[element] << del << spell_names[0] << del << spells[0] << del << mana_cost[2] << endl;
			else
			{
				items = random(0, 2);		
				out <<  types[element] << del;
				if (element == 0) out << damage_names[items] << del << damage_vals[items] << endl;
				else out << healing_names[items] << del << healing_vals[items] << endl;
			}
		}
	}
	
	return 0;
}
