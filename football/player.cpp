#include "player.h"
#include <fstream>
using namespace std;

Player::Player(const string& name,
	const string& club,
	int goals)
	: player_name(name)
	, player_club(club)
	, player_goals(goals)
{}

Player::Player(const Player& P)
	: player_name(P.player_name)
	, player_club(P.player_club)
	, player_goals(P.player_goals)
{}

Player::~Player()
{}


string Player::getClub() const
{
	return player_club;
}

int Player::getGoals() const
{
	return player_goals;
}

void Player::setClub(const string& newClub)
{
	player_club = newClub;
}

void Player::addGoals(int newGoals)
{
	if (newGoals < 0)
		return;
	player_goals += newGoals;
}

void Player::print() const
{
	cout << "Player: " << player_name
		<< ". Club: " << player_club
		<< ". Total: " << player_goals << " goals\n";
	cout << "\tReward: " << getReward() << " usd\n";
}

void Player::readFrom(istream& in)
{
	// Lionell Messi*Real Madrid*37
	getline(in, player_name, '*');
	getline(in, player_club, '*');
	in >> player_goals;
}

void Player::writeTo(ostream& out) const
{
	out << player_name << '*'
		<< player_club << '*'
		<< player_goals;
}

bool Player::operator<(Player& P)
{
	return getGoals() < P. getGoals();
}

istream& operator>>(istream& in, Player& P)
{
	P.readFrom(in);
	return in;
}

ostream& operator<<(ostream& out, const Player& P)
{
	P.writeTo(out);
	return out;
}

Player* createTeam(const std::string& teamName, size_t& teamSize)
{
	ifstream fin(teamName);
	fin >> teamSize;

	Player* team = new Player[teamSize];
	for (size_t i = 0; i < teamSize; ++i)
	{
		fin.get();
		fin >> team[i];
	}

	fin.close();
	return team;
}

void printTeam(Player* team, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		team[i].print();
	}
	cout << endl;
}

Player* maxPlayer(Player* team, size_t n)
{
	Player* max = &team[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (*max < team[i])
		{
			max = &team[i];
		}


	}
	return max;
}

void sortTeam(Player* team, size_t n)
{

	for (size_t i = 0; i < n; ++i)
	{

		size_t min = i;
		for (size_t j = i + 1; j < n; ++j)
		{
			if (team[j] < team[min])
			{
				min = j;
		   }

		}
		if (min != i)
		{
			Player temp = team[i];
			team[i] = team[min];
			team[min] = temp;
		}
	}
}

void sortTeamBy(Player* team, size_t n, bool(*compare)(Player&, Player&))
{
	for (size_t i = 0; i < n; ++i)
	{
			size_t min = i;
			for (size_t j = i + 1; j < n; ++j)
			{
				if (compare(team[j], team[min]))
				{
					min = j;
				}
			}



			if (min != i)
			{
				Player temp = team[i];
				team[i] = team[min];
				team[min] = temp;
			}
	}
}

void writeTeam(Player* team, size_t n, const std::string& filename)
{
	ofstream fout(filename);
	fout << n << '\n';
	for (size_t i = 0; i < n; ++i)
	{
		
		fout << team[i] << '\n';
		
	}
	fout.close();
}

bool byClub(Player& A, Player& B)
{
	return A.getClub() < B.getClub();
}

bool byReward(Player& A, Player& B)
{
	return A.getReward() < B.getReward();
}

Player* selectPlayers(Player* team, size_t n, size_t& newN)
{
	Player* selected = new Player[n];
	for (size_t i = 0; i < n; ++i)
	{

		if (team[i].getGoals() < 35)
		{
			selected[newN] = team[i];
			++newN;
		}
	}


	return selected;
}

int Player::getReward() const
{
	return 100 * player_goals;
}