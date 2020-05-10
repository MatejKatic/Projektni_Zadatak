#include "Player.h"
#include  <sstream>


Player::Player()
{

}


Player::Player(int roundID, int matchID, string team_initials, string coach_name, char line_up, int shirt_number, string player_name, string position, string eventi)
{
	this->RoundID = roundID;
	this->MatchID = matchID;
	this->Team_Initials = team_initials;
	this->Coach_Name = coach_name;
	this->Line_UP = line_up;
	this->shirt_number= shirt_number;
	this->Player_name = player_name;
	this->position = position;
	this->eventi = eventi;
}



string Player::ispis()
{
	stringstream ss;
	ss << RoundID << " " << MatchID << " " << Team_Initials << " " << Coach_Name << " " << Line_UP << " " << shirt_number << " " << Player_name << " " << position << " " << eventi << endl;
	return ss.str();
}

void Player::eve(string eventi)
{
	this->eventi = eventi;
}

string Player::eve()
{
	return eventi;
}

void Player::get_roundID(int RoundID)
{
	this->RoundID = RoundID;
}

int Player::set_roundID()
{
	return RoundID;
}

void Player::get_MatchID(int MatchID)
{
	this->MatchID = MatchID;
}

int Player::set_MatchID()
{
	return MatchID;
}

void Player::get_Team_Initials(string Team_Initials)
{
	this->Team_Initials = Team_Initials;
}

string Player::set_Team_Initials()
{
	return Team_Initials;
}

void Player::get_Coach_name(string Coach_Name)
{
	this->Coach_Name = Coach_Name;
}

string Player::set_Coach_name()
{
	return Coach_Name;
}

void Player::get_Line_UP(char Line_UP)
{
	this->Line_UP = Line_UP;
}

char Player::set_Line_UP()
{
	return Line_UP;
}

void Player::get_shirt_number(int shirt_number)
{
	this->shirt_number = shirt_number;
}

int Player::set_shirt_number()
{
	return shirt_number;
}

void Player::get_Player_Name(string Player_Name)
{
	this->Player_name = Player_Name;
}

string Player::set_Player_Name()
{
	return Player_name;
}

void Player::set_position(string position)
{
	this->position = position;
}

string Player::get_position()
{
	return position;
}



