#include "Match.h"
#include <sstream>

Match::Match()
{

}

void Match::set_year(int year)
{
	this -> Year = year;
}

int Match::get_year()
{
	return Year;
}

void Match::set_datetime(string Datetime)
{
	this->Datetime = Datetime;
}

string Match::get_datetime()
{
	return Datetime;
}

void Match::set_stage(string Stage)
{
	this -> Stage = Stage;
}

string Match::get_stage()
{
	return Stage;
}

void Match::set_stadium(string Stadium)
{
	this->Stadium = Stadium;
}

string Match::get_stadium()
{
	return Stadium;
}

void Match::set_city(string City)
{
	this->City = City;
}

string Match::get_city()
{
	return City;
}

void Match::set_home_team_name(string Home_Team_Name)
{
	this->Home_Team_Name = Home_Team_Name;
}

string Match::get_home_team_name()
{
	return Home_Team_Name;
}

void Match::set_home_team_goals(int Home_Team_Goals)
{
	this->Home_Team_Goals = Home_Team_Goals;
}

int Match::get_home_team_goals()
{
	return Home_Team_Goals;
}

void Match::set_away_team_goals(int Away_Team_Goals)
{
	this->Away_Team_Goals = Away_Team_Goals;
}

int Match::get_away_team_goals()
{
	return Away_Team_Goals;
}

void Match::set_away_team_name(string Away_Team_Name)
{
	this -> Away_Team_Name = Away_Team_Name;
}

string Match::get_away_team_name()
{
	return Away_Team_Name;
}

void Match::set_win_conditions(string Win_Conditions)
{
	this->Win_Conditions = Win_Conditions;
}

string Match::get_win_conditions()
{
	return Win_Conditions;
}

void Match::set_attendance(long Attendance)
{
	this->Attendance = Attendance;
}

long Match::get_attendance()
{
	return Attendance;
}

void Match::set_half_time(int Half_Time)
{
	this -> Half_time = Half_Time;
}

int Match::get_half_time()
{
	return Half_time;
}

void Match::set_half_time_away_goals(int Half_time_away_goals)
{
	this->Half_time_away_goals = Half_time_away_goals;
}

int Match::get_half_time_away_goals()
{
	return Half_time_away_goals;
}

void Match::set_referre(string Reffere)
{
	this->Referee = Referee;
}

string Match::get_referre()
{
	return Referee;
}

void Match::set_assistant_1(string Assistant_1)
{
	this->Assistant_1 = Assistant_1;
}

string Match::get_assistant_1()
{
	return Assistant_1;
}

void Match::set_Assistant_2(string Assistant_2)
{
	this->Assistant_2 = Assistant_2;
}

string Match::get_Assistant_2()
{
	return Assistant_2;
}

void Match::set_roundid(int RoundID)
{
	this->RoundID = RoundID;
}

int Match::get_roundid()
{
	return RoundID;
}

void Match::set_matchid(int MatchID)
{
	this->MatchID = MatchID;
}

int Match::get_matchid()
{
	return MatchID;
}

void Match::set_home_team_tnitials(string Home_Team_Initials)
{
	this->Home_Team_Initials = Home_Team_Initials;
}

string Match::get_home_team_initials()
{
	return Home_Team_Initials;
}

void Match::set_away_team_initials(string Away_Team_Initials)
{
	this->Away_Team_Initials = Away_Team_Initials;
}

string Match::get_away_team_initials()
{
	return Away_Team_Initials;
}

Match::Match(int year, string datetime, string stage, string stadium, string city, string home_team_name, int home_team_goals, int away_team_goals, string away_team_name, string win_condition, int attedance, int half_time, int half_time_away_goals, string reffere, string assistant_1, string assistant_2, int roundid, int matchid, string home_team_initials, string away_team_initials)
{
	Year = year;
	Datetime = datetime;
	Stage = stage;
	Stadium = stadium;
	City = city;
	Home_Team_Name = home_team_name;
	Home_Team_Goals = home_team_goals;
	Away_Team_Goals = away_team_goals;
	Away_Team_Name = away_team_name;
	Win_Conditions = win_condition;
	Attendance = attedance;
	Half_time = half_time;
	Half_time_away_goals = half_time_away_goals;
	Referee = reffere;
	Assistant_1 = assistant_1;
	Assistant_2 = assistant_2;
	RoundID = roundid;
	MatchID = matchid;
	Home_Team_Initials = home_team_initials;
	Away_Team_Initials = away_team_initials;
}

Match::Match(int year, string datetime, string stage, string stadium, string city, string home_team_name, int home_team_goals, int away_team_goals, string away_team_name, string win_condition, int attedance, int half_time, int half_time_away_goals, string reffere, string assistant_1, string assistant_2, int roundid, int matchid, string home_team_initials, string away_team_initials, string home_player, string away_player)
{
	Year = year;
	Datetime = datetime;
	Stage = stage;
	Stadium = stadium;
	City = city;
	Home_Team_Name = home_team_name;
	Home_Team_Goals = home_team_goals;
	Away_Team_Goals = away_team_goals;
	Away_Team_Name = away_team_name;
	Win_Conditions = win_condition;
	Attendance = attedance;
	Half_time = half_time;
	Half_time_away_goals = half_time_away_goals;
	Referee = reffere;
	Assistant_1 = assistant_1;
	Assistant_2 = assistant_2;
	RoundID = roundid;
	MatchID = matchid;
	Home_Team_Initials = home_team_initials;
	Away_Team_Initials = away_team_initials;
	this->Home_player = home_player;
	this->Away_player = away_player;

}





Match::Match(vector<Player> home_team, vector<Player> away_team)
{
	this->Home_team = home_team;
	this->Away_team = away_team;
}



string Match::ispis()
{
	stringstream ss;
	ss << get_datetime() << ", " << get_stadium() << ", " << get_home_team_name() << " " << get_home_team_goals() << ":" << get_away_team_goals() << " " << get_away_team_name() <<  endl;
	return ss.str();
}





string Match::provjera()
{
	stringstream ss;
	ss << Year << " " << Datetime << " " << Stage << " " << Stadium << " " << City << " " << Home_Team_Name << " " << Home_Team_Goals << " " << Away_Team_Goals << " " << Away_Team_Name << " " << Win_Conditions << " " << Attendance << " " << Half_time << " " << Half_time_away_goals << " " << Referee << " " << Assistant_1 << " " << Assistant_2 << " " << RoundID << " " << MatchID << " " << Home_Team_Initials << " " << Away_Team_Initials  << endl;
	return ss.str();
}


string Match::zadatak_4()
{
	stringstream ss;
	ss << Year << " " << Datetime << " " << Stage << " " << Stadium << " " << City << " " << Home_Team_Name << " " << Home_Team_Goals << " " << Away_Team_Goals << " " << Away_Team_Name << " " << Win_Conditions << " " << Attendance << " " << Half_time << " " << Half_time_away_goals << " " << Referee << " " << Assistant_1 << " " << Assistant_2 << " " << RoundID << " " << MatchID << " " << Home_Team_Initials << " " << Away_Team_Initials << " " << Igraci << " " << Home_player << " " << Away_player << " " <<  endl;
	return ss.str();
}

string Match::zadatak_9()
{
	stringstream ss;
	ss << Stage << " " << Stadium << " " << City << " " << Home_Team_Name << " " << Home_Team_Goals << " " << Away_Team_Goals << " " << Away_Team_Name << " " << Win_Conditions << " " << Attendance << " " << Half_time << " " << Half_time_away_goals << " " << Referee << " " << Assistant_1 << " " << Assistant_2 << " " << RoundID << " " << MatchID << " " << Home_Team_Initials << " " << Away_Team_Initials << " " << Igraci << " " << endl;
	return ss.str();
}



