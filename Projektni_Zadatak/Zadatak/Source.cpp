#include <iostream>
#include <string>
#include "Match.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Player.h"
#include <chrono>
#include <stack>
#include <queue>
#include <iterator>
#include<list>

using namespace std;
using namespace std::chrono;


void naslov()
{
	cout << "__          __       _     _    _____" << endl
		<< "| |        / /      | |   | |  / ____|" << endl
		<< "| |  /|  / /__  _ __| | __| | | |" << endl
		<< " | |/  |/ / _ || '__| |/ _` | | |   | | | | '_ | " << endl
		<< "  |  /|  / (_) | |  | | (_| | | |___| |_| | |_)|" << endl
		<< "   |/  |/ |___/|_|  |_||__,_|  |_____|__,_| .__/" << endl
		<< "                                          | |" << endl
		<< "                                          |_|" << endl;


}

void upis(Match& m)
{ 
	string datetime;
	string Home_Team_Name;
	string Away_Team_Name;
	string Stadium;
	short Home_Team_Goals;
	short Away_Team_Goals;
	cout << "Datum: ";
	getline(cin, datetime);
	m.set_datetime(datetime);
	cout << endl;
	cout << "Stadion: ";
	getline(cin, Stadium);
	m.set_stadium(Stadium);
	cout << endl;
	cout << "Naziv domaceg tima: ";
	getline(cin, Home_Team_Name);
	m.set_home_team_name(Home_Team_Name);
	cout << endl;
	cout << "Naziv stranog tima: ";
	getline(cin, Away_Team_Name);
	m.set_away_team_name(Away_Team_Name);
	cout << endl;
	cout << "Rezultat domaceg tima: ";
	cin >> Home_Team_Goals;
	cin.ignore();
	m.set_home_team_goals(Home_Team_Goals);
	cout << endl;
	cout << "Rezultat stranog tima: ";
	cin >> Away_Team_Goals;
	m.set_away_team_goals(Away_Team_Goals);
	cout << endl;
}

void ispis(Match& m)
{
	cout << m.ispis() << endl;
}

void odabir()
{
	cout << "Unos osnovnih podataka o utakmici - 1" << endl;
	cout << "Unos putanje foldera - 2" << endl;
	cout << "Unos podataka iz datoteke - 3" << endl;
	cout << "Upisite MatchID - 4" << endl;
	cout << "Kopiranje Datoteke - 5" << endl;
	cout << "Odabir po godinama - 6" << endl;
	cout << "Iteratori - 7" << endl;
	cout << "Statistika pobjeda - 8" << endl;
	cout << "Zadavanje naredbi - 9" << endl;
	cout << endl;
}

void spremiste_putanja(ofstream& putanja)
{
	putanja.open("Spremiste.dat", ios::out | ios::binary);
	if (!putanja)
	{
		cout << "404 error" << endl;
	}
	string lokacija;
	getline(cin, lokacija);
	putanja << lokacija;
}

void ucitaj_putanju(ifstream& datoteka, string& line)
{
	if (datoteka.is_open())
	{
		while (!datoteka.eof())
		{
			getline(datoteka, line);
		}
	}
}


int convert(string& s)
{
	stringstream converter(s);
	int n;
	converter >> n;
	return n;
}



char char_convert(string& s)
{
	stringstream converter(s);
	char n;
	converter >> n;
	return n;
}




void unos_u_datoteku(ifstream& datoteka, vector<Match>& spa)
{
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
	int Attendance;
	int Half_time;
	int Half_time_away_goals;
	string Referee;
	string Assistant_1;
	string Assistant_2;
	int RoundID;
	int MatchID;
	string Home_Team_Initials;
	string Away_Team_Initials;
	if (!datoteka)
	{
		cout << "404 error" << endl;
	}
	int size = 851;
	string ispis;
	string broj;
	getline(datoteka, ispis);
	while (getline(datoteka, ispis))
	{
		stringstream ss(ispis);
		getline(ss, broj, ',');
		Year = convert(broj);
		getline(ss, Datetime, ',');
		getline(ss, Stage, ',');
		getline(ss, Stadium, ',');
		getline(ss, City, ',');
		getline(ss, Home_Team_Name, ',');
		getline(ss, broj, ',');
		Home_Team_Goals = convert(broj);
		getline(ss, broj, ',');
		Away_Team_Goals = convert(broj);
		getline(ss, Away_Team_Name, ',');
		getline(ss, Win_Conditions, ',');
		getline(ss, broj, ',');
		Attendance = convert(broj);
		getline(ss, broj, ',');
		Half_time = convert(broj);
		getline(ss, broj, ',');
		Half_time_away_goals = convert(broj);
		getline(ss, Referee, ',');
		getline(ss, Assistant_1, ',');
		getline(ss, Assistant_2, ',');
		getline(ss, broj, ',');
		RoundID = convert(broj);
		getline(ss, broj, ',');
		MatchID = convert(broj);
		getline(ss, Home_Team_Initials, ',');
		getline(ss, Away_Team_Initials);
		spa.emplace_back(Year, Datetime, Stage, Stadium, City, Home_Team_Name, Home_Team_Goals, Away_Team_Goals, Away_Team_Name, Win_Conditions, Attendance, Half_time, Half_time_away_goals, Referee, Assistant_1, Assistant_2, RoundID, MatchID, Home_Team_Initials, Away_Team_Initials);
		if (spa.size() > size)
			break;
	}
}



void unos_u_datoteku_2(ifstream& datoteka_2, vector<Player>& team)
{
	int RoundID;
	int MatchID;
	string Team_Initials;
	string Coach_Name;
	char Line_UP;
	int shirt_number;
	string player_name;
	string position;
	string event;
	if (!datoteka_2)
	{
		cout << "404 error" << endl;
	}
	int size = 37783;
	string ispis;
	string broj;
	getline(datoteka_2, ispis);
	while (getline(datoteka_2, ispis))
	{
		stringstream ss(ispis);
		getline(ss, broj, ',');
		RoundID = convert(broj);
		getline(ss, broj, ',');
		MatchID = convert(broj);
		getline(ss, Team_Initials, ',');
		getline(ss, Coach_Name, ',');
		getline(ss, broj, ',');
		Line_UP = char_convert(broj);
		getline(ss, broj, ',');
		shirt_number = convert(broj);
		getline(ss, player_name, ',');
		getline(ss, position, ',');
		getline(ss, event);
		team.emplace_back(RoundID, MatchID, Team_Initials, Coach_Name, Line_UP, shirt_number, player_name, position, event);
		if (team.size() > size)
			break;
	}
}


bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}



void unos_u_datoteku_posebno(ifstream& datoteka, vector<Match>& spa)
{
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
	int Attendance;
	int Half_time;
	int Half_time_away_goals;
	string Referee;
	string Assistant_1;
	string Assistant_2;
	int RoundID;
	int MatchID;
	string Home_Team_Initials;
	string Away_Team_Initials;
	if (!datoteka)
	{
		cout << "404 error" << endl;
	}
	int size = 851;
	string ispis;
	string broj;
	getline(datoteka, ispis);
	size_t index = 0;
	while (getline(datoteka, ispis))
	{
		stringstream ss(ispis);
		getline(ss, broj, ',');
		Year = convert(broj);
		getline(ss, Datetime, ',');
		Datetime.erase(12, 8);
		replace(Datetime, "Jul", "03");
		replace(Datetime, "May", "06");
		replace(Datetime, "Jun", "10");
		Datetime.erase(remove(Datetime.begin(), Datetime.end(), '\"'), Datetime.end());
		Datetime.erase(remove_if(Datetime.begin(), Datetime.end(), isspace), Datetime.end());
		getline(ss, Stage, ',');
		getline(ss, Stadium, ',');
		getline(ss, City, ',');
		getline(ss, Home_Team_Name, ',');
		getline(ss, broj, ',');
		Home_Team_Goals = convert(broj);
		getline(ss, broj, ',');
		Away_Team_Goals = convert(broj);
		getline(ss, Away_Team_Name, ',');
		getline(ss, Win_Conditions, ',');
		getline(ss, broj, ',');
		Attendance = convert(broj);
		getline(ss, broj, ',');
		Half_time = convert(broj);
		getline(ss, broj, ',');
		Half_time_away_goals = convert(broj);
		getline(ss, Referee, ',');
		getline(ss, Assistant_1, ',');
		getline(ss, Assistant_2, ',');
		getline(ss, broj, ',');
		RoundID = convert(broj);
		getline(ss, broj, ',');
		MatchID = convert(broj);
		getline(ss, Home_Team_Initials, ',');
		getline(ss, Away_Team_Initials);
		spa.emplace_back(Year, Datetime, Stage, Stadium, City, Home_Team_Name, Home_Team_Goals, Away_Team_Goals, Away_Team_Name, Win_Conditions, Attendance, Half_time, Half_time_away_goals, Referee, Assistant_1, Assistant_2, RoundID, MatchID, Home_Team_Initials, Away_Team_Initials);
		if (spa.size() > size)
			break;
	}
}



void vrijeme(ifstream& datoteka, vector<Match>& spa)
{
	auto begin = chrono::high_resolution_clock::now();
	unos_u_datoteku(datoteka, spa);
	auto end = chrono::high_resolution_clock::now();
	cout << endl;
	cout
		<< "Trajalo je: "
		<< chrono::duration_cast<chrono::milliseconds>(end - begin).count()
		<< " ms" << endl;
}


void odabir_naredbe(ifstream& datoteka, ifstream& igraci)
{
	char odabir;
	char odabir_2;
	cout << "Koju Datoteku zelite kopirati? (1 - SPA_PROJ_010_WORLD_CUP_data_1.csv, 2 - SPA_PROJ_010_WORLD_CUP_data_2.csv" << endl;
	cin >> odabir;

	if (odabir == '1')
	{
		ofstream datoteka_red("SPA_PROJ_010_WORLD_CUP_data_1(red).csv");
		cout << "U istom ili u obrnutom redoslijedu? (1 - isti, 2 - obrnuti) " << endl;
		cin >> odabir_2;
		if (odabir_2 == '1')
		{
			queue<string> q;
			string red;
			getline(datoteka, red);
			while (getline(datoteka, red))
			{
				q.push(red);

			}

			while (!q.empty())
			{
				datoteka_red << q.front() << endl;
				q.pop();
			}
		}

		if (odabir_2 == '2')
		{
			ofstream datoteka_stog("SPA_PROJ_010_WORLD_CUP_data_1(stog).csv");
			stack<string> s;
			string line;
			string broj;
			getline(datoteka, line);
			bool ima_podatak = true;
			while (getline(datoteka, line))
			{
				stringstream ss(line);
				bool nema_podataka = true;
				for (int i = 1; i == 18; i++)
				{
					getline(ss, line, ';');
					stringstream converter;
					converter << line;
					int broj;
					if (converter >> broj)
					{
						nema_podataka = false;
						break;
					}
				}
				if (nema_podataka)
				{
					s.push(line);
				}

			}

			while (!s.empty())
			{
				datoteka_stog << s.top() << endl;
				s.pop();
			}
		}

	}
	else if (odabir == '2')
	{
		cout << "U istom ili u obrnutom redoslijedu? (1 - isti, 2 -obrnuti)" << endl;
		cin >> odabir_2;
			if (odabir_2 == '1')
			{
				ofstream datoteka_red_2("SPA_PROJ_010_WORLD_CUP_data_2(red).csv");
				queue<string> q;
				string red;
				getline(igraci, red);
				while (getline(igraci, red))
				{
					q.push(red);

				}

				while (!q.empty())
				{
					datoteka_red_2 << q.front() << endl;
					q.pop();
				}
			}

			if (odabir_2 == '2')
			{
				ofstream datoteka_stog_2("SPA_PROJ_010_WORLD_CUP_data_2(stog).csv");
				stack<string> s;
				string line;
				string broj;
				getline(igraci, line);
				bool ima_podatak = true;
				while (getline(igraci, line))
				{
					stringstream ss(line);
					bool nema_podataka = true;
					for (int i = 1; i == 18; i++)
					{
						getline(ss, line, ';');
						stringstream converter;
						converter << line;
						int broj;
						if (converter >> broj)
						{
							nema_podataka = false;
							break;
						}
					}
					if (nema_podataka)
					{
						s.push(line);
					}

				}

				while (!s.empty())
				{
					datoteka_stog_2 << s.top() << endl;
					s.pop();
				}
			}
		
	}
	else
	{
	cout << "Greska" << endl;
	}
}


void zadatak_4(ifstream& datoteka, ifstream& igraci)
{
	vector<Match> spa;
	vector<Player> home;
	vector<Match> Utakmice;
	unos_u_datoteku(datoteka, spa);
	unos_u_datoteku_2(igraci, home);
	auto t = home.begin();
	auto k = home.begin();
	++k;
	spa.emplace_back(home, home);
	int MatchID;
	cout << "Upisi MatchID: ";
	cin >> MatchID;
	for (auto it = spa.begin(); it != spa.end(); ++it, ++t)
	{

		if (it->get_matchid() == MatchID)
		{
			if (it->get_home_team_initials() == t->set_Team_Initials())
			{
				Utakmice.emplace_back(it->get_year(), it->get_datetime(), it->get_stage(), it->get_stadium(), it->get_city(), it->get_home_team_name(), it->get_home_team_goals(), it->get_away_team_goals(), it->get_away_team_name(), it->get_win_conditions(), it->get_attendance(), it->get_half_time(), it->get_half_time_away_goals(), it->get_referre(), it->get_assistant_1(), it->get_Assistant_2(), it->get_roundid(), it->get_matchid(), it->get_home_team_initials(), it->get_away_team_initials(), t->set_Player_Name(), k->set_Player_Name());
			}
		}
	}
	for (auto it = Utakmice.begin(); it != Utakmice.end(); ++it)
	{
		cout << it->zadatak_4() << endl;
	}

}


void print(Match& unos)
{
	cout << unos.provjera() << endl;
}

void print_novi(string& unos)
{
	cout << unos << endl;
}

void izbor_po_godinama(ifstream& datoteka)
{
	int godina;
	string intials;
	cout << "Unesite godinu koju zelite obraditi: ";
	cin >> godina;
	cin.ignore();
	vector<Match> lista;
	list<Match> T;
	unos_u_datoteku(datoteka, lista);
	for (auto it = lista.begin(); it != lista.end(); ++it)
	{
		if (it->get_year() == godina)
		{
			T.emplace_back(it->get_year(), it->get_datetime(), it->get_stage(), it->get_stadium(), it->get_city(), it->get_home_team_name(), it->get_home_team_goals(), it->get_away_team_goals(), it->get_away_team_name(), it->get_win_conditions(), it->get_attendance(), it->get_half_time(), it->get_half_time_away_goals(), it->get_referre(), it->get_assistant_1(), it->get_Assistant_2(), it->get_roundid(), it->get_matchid(), it->get_home_team_initials(), it->get_away_team_initials());
		}
		
	}
	cout << "Unesite troslovnu oznaku reprezentacije:" << endl;
	getline(cin, intials);
	for (auto it = T.begin(); it != T.end(); ++it)
	{
		if (it->get_home_team_initials() == intials || it->get_away_team_initials() == intials )
		{
			it = T.erase(it);
		}
		else
			++it;
		
	}
	for_each(T.begin(), T.end(), print);
}


void zadatak_7(ifstream& datoteka)
{
	vector<Match> upis;
	vector<int> prva;
	vector<int> druga;
	unos_u_datoteku(datoteka, upis);
	stack<int> broj;
	int zbroj = 0;
	broj.push(zbroj);
	for (auto it = upis.rbegin(); it != upis.rend(); ++it)
	{
			prva.push_back(it->get_home_team_goals());
			druga.push_back(it->get_away_team_goals());
	}
	vector<int>::iterator d;
	vector<int>::iterator f;
	for (d = prva.begin(), f = druga.begin(); d != prva.end() && f != druga.end(); ++d, ++f)
	{
		if (*f > *d)
		{
			broj.pop();
			zbroj = zbroj + *f;
			broj.push(zbroj);
		}
	}
	cout << "Vrijendost na stogu: " << broj.top() << endl;
}



int count_found(vector<Match>& imena, string teamovi)
{
	int counter = 0;
	for (auto it = imena.begin(); it != imena.end(); ++it)
	{
		if (it->get_home_team_name() == teamovi || it->get_away_team_name() == teamovi)
		{
			auto home_team = it->get_home_team_goals() + it->get_half_time();
			auto away_team = it->get_away_team_goals() + it->get_away_team_goals();
			if(home_team > away_team)
				counter++;
			if(home_team < away_team)
				counter++;
		}
	}
	return counter;
}

void paint(string c, int n)
{
	cout << c << ": ";
	for (int i = 0; i < n; i++)
	{
		cout << "#";
	}
	cout << " (" << n << ")" << endl;
}



void pobjede(ifstream& datoteka)
{
	vector<Match> utakmice;
	vector<string> imena;
	unos_u_datoteku(datoteka, utakmice);
	int brojac = 0;
	for (auto it = utakmice.begin(); it != utakmice.end(); ++it)
	{
		imena.push_back(it->get_home_team_name());
	}

	for (int i = 0; i < imena.size(); i++)
	{
		paint(imena[i], count_found(utakmice, imena[i]));
	}
	
}

void naredbe(ifstream& datoteka)
{
	vector<Match> ispis;
	vector<Match> provjera;
	vector<Match> zadatak;
	vector<int> godine;
	vector<string> novi_ispis;
	unos_u_datoteku_posebno(datoteka, ispis);
	for (auto it = ispis.begin(); it != ispis.end(); ++it)
	{
		novi_ispis.push_back(it->get_datetime());
		provjera.emplace_back(it->get_year(), it->get_datetime(), it->get_stage(), it->get_stadium(), it->get_city(), it->get_home_team_name(), it->get_home_team_goals(), it->get_away_team_goals(), it->get_away_team_name(), it->get_win_conditions(), it->get_attendance(), it->get_half_time(), it->get_half_time_away_goals(), it->get_referre(), it->get_assistant_1(), it->get_Assistant_2(), it->get_roundid(), it->get_matchid(), it->get_home_team_initials(), it->get_away_team_initials());
	}
	for (int i = 0; i < novi_ispis.size(); i++)
	{
		godine.push_back(convert(novi_ispis[i]));
	}
	int upis_godine;
	int i = 0;
	for (auto it = provjera.begin(); it != provjera.end(); ++it)
	{
		upis_godine = godine[i];
		zadatak.emplace_back(upis_godine, it->get_datetime(), it->get_stage(), it->get_stadium(), it->get_city(), it->get_home_team_name(), it->get_home_team_goals(), it->get_away_team_goals(), it->get_away_team_name(), it->get_win_conditions(), it->get_attendance(), it->get_half_time(), it->get_half_time_away_goals(), it->get_referre(), it->get_assistant_1(), it->get_Assistant_2(), it->get_roundid(), it->get_matchid(), it->get_home_team_initials(), it->get_away_team_initials());
		i++;
	}
	int n1;
	int n2;
	cout << "DDMMYYYY" << endl;
	cout << "n1: ";
	cin >> n1;
	cout << "AND To = ";
	cout << "n2: " << endl;
	cin >> n2;
	for (auto it = zadatak.begin(); it != zadatak.end(); ++it)
	{
		if (it->get_year() >= n1 && it->get_year() <= n2)
			{
			cout << it->zadatak_9() << endl;

			}
	}






}

int main()
{
	naslov();
	odabir();
	ofstream putanja;
	ifstream ucitaj("Spremiste.dat", ios::in | ios::binary);
	ifstream igraci("SPA_PROJ_010_WORLD_CUP_data_2.csv");
	string linija;
	ucitaj_putanju(ucitaj, linija);
	ifstream datoteka(linija);
	Match m;
	vector<Match> spa;
	vector <Player> home;
	char unos;
	cout << "Odaberite opciju: ";
	cin >> unos;
	switch (unos)
	{
	case '1':
		cout << endl;
		cin.ignore();
		upis(m);
		ispis(m);
		break;
	case '2':
		cin.ignore();
		cout << "Putanja foldera: ";
		spremiste_putanja(putanja);
		break;
	case '3':
		vrijeme(datoteka, spa);
		break;
	case '4':
		zadatak_4(datoteka, igraci);
		break;
	case '5':
		odabir_naredbe(datoteka, igraci);
		break;
	case '6':
		izbor_po_godinama(datoteka);
		break;
	case '7':
		zadatak_7(datoteka);
		break;
	case '8':
		pobjede(datoteka);
		break;
	case '9':
		naredbe(datoteka);
		break;
	default:
		cout << "Greška" << endl;
		break;
	}

	putanja.close();
	datoteka.close();

	return 0;
}