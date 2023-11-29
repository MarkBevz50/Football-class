#pragma once
#include <iostream>
#include <string>

class Player
{
private:
	std::string player_name;
	std::string player_club;
	int player_goals;

public:
	Player(const std::string& name = "",
		const std::string& club = "",
		int goals = 0);
	Player(const Player& P);
	~Player();

	std::string getClub() const;
	int getGoals() const;
	int getReward() const;

	void setClub(const std::string& newClub);
	void addGoals(int newGoals);

	void print() const;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;
	bool operator < ( Player& P);

};

std::istream& operator>>(std::istream& in, Player& P);
std::ostream& operator<<(std::ostream& out, const Player& P);

Player* createTeam(const std::string& teamName, size_t& teamSize);
void printTeam(Player* team, size_t n);
Player* maxPlayer(Player* team, size_t n);
void sortTeam(Player* team, size_t n);
void writeTeam(Player* team, size_t n, const std::string& filename);