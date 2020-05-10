#pragma once
#include <string>
using namespace std;
class Player
{
public:
	Player();
	string ispis();
	void eve(string eventi);
	string eve();
	void get_roundID(int RoundID);
	int set_roundID();
	void get_MatchID(int MatchID);
	int set_MatchID();
	void get_Team_Initials(string Team_Initials);
	string set_Team_Initials();
	void get_Coach_name(string Coach_Name);
	string set_Coach_name();
	void get_Line_UP(char Line_UP);
	char set_Line_UP();
	void get_shirt_number(int shirt_number);
	int set_shirt_number();
	void get_Player_Name(string Player_Name);
	string set_Player_Name();
	void set_position(string position);
	string get_position();
	Player(int roundID, int matchID, string team_initials, string coach_name, char line_up, int shirt_number, string player_name, string position, string event);

private:
	int RoundID;
	int MatchID;
	string Team_Initials;
	string Coach_Name;
	char Line_UP;
	int shirt_number;
	string Player_name;
	string position;
	string eventi;

};
