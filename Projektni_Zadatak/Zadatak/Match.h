#pragma once
#include <string>
#include <ctime>
#include "Player.h"
#include <vector>


using namespace std;



class Match
{
private:
	vector <Player> Home_team;
	vector <Player> Away_team;
	string Igraci;
	int Year;
	string Datetime;
	string Stage;
	string Stadium;
	string City;
	string Home_Team_Name;
	int Home_Team_Goals;
	int Away_Team_Goals;
	string Away_Team_Name;
	string Win_Conditions;
	long Attendance;
	int Half_time;
	int Half_time_away_goals;
	string Referee;
	string Assistant_1;
	string Assistant_2;
	int RoundID;
	int MatchID;
	string Home_Team_Initials;
	string Away_Team_Initials;
	string Home_player;
	string Away_player;
public:
	Match();
	void set_year( int year);
	int get_year();
	void set_datetime(string Datetime);
	string get_datetime();
	void set_stage(string Stage);
	string get_stage();
	void set_stadium(string Stadium);
	string get_stadium();
	void set_city(string City);
	string get_city();
	void set_home_team_name(string Home_Team_Name);
	string get_home_team_name();
	void set_home_team_goals(int Home_Team_Goals);
	int get_home_team_goals();
	void set_away_team_goals(int Away_Team_Goals);
	int get_away_team_goals();
	void set_away_team_name(string Away_Team_Name);
	string get_away_team_name();
	void set_win_conditions(string Win_Conditions);
	string get_win_conditions();
	void set_attendance(long Attendance);
	long get_attendance();
	void set_half_time(int Half_Time);
	int get_half_time();
	void set_half_time_away_goals(int Half_time_away_goals);
	int get_half_time_away_goals();
	void set_referre(string Reffere);
	string get_referre();
	void set_assistant_1(string Assistant_1);
	string get_assistant_1();
	void set_Assistant_2(string Assistant_2);
	string get_Assistant_2();
	void set_roundid(int RoundID);
	int get_roundid();
	void set_matchid(int MatchID);
	int get_matchid();
	void set_home_team_tnitials(string Home_Team_Initials);
	string get_home_team_initials();
	void set_away_team_initials(string Away_Team_Initials);
	string get_away_team_initials();
	string ispis();
	Match(int year, string datetime, string stage, string stadium, string city, string home_team_name, int home_team_goals, int away_team_goals, string away_team_name, string win_condition, int attedance, int half_time, int half_time_away_goals, string reffere, string assistant_1, string assistant_2, int RoundID, int MatchID, string home_team_initials, string away_team_initials);
	Match(int year, string datetime, string stage, string stadium, string city, string home_team_name, int home_team_goals, int away_team_goals, string away_team_name, string win_condition, int attedance, int half_time, int half_time_away_goals, string reffere, string assistant_1, string assistant_2, int RoundID, int MatchID, string home_team_initials, string away_team_initials, string home_player, string away_player);
	Match(vector<Player> home_team, vector<Player> away_team);
	string provjera();
	string zadatak_9();
	string zadatak_4();
};

