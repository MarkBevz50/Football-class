#include <iostream>
#include "player.h"
using namespace std;

int main()
{
	size_t n;
	Player* arr = createTeam("player.txt", n);
	printTeam(arr, n);
	Player* maxP = maxPlayer(arr, n);
	cout << "Best player\n";
	maxP->print();
	cout << endl;
	sortTeam(arr, n);
	cout << "Sorted team : \n";
	printTeam(arr, n);
	cout << endl;
	writeTeam(arr, n, "sorted.txt");
	cout << "Check your files...\n\n";
	arr[n - 1].setClub("Barselona");
	arr[n - 2].setClub("Barselona");
	arr[n - 3].setClub("Barselona");
	sortTeamBy(arr, n, byClub);
	cout << "New team \n";
	printTeam(arr, n);
	cout << endl;
	size_t m;
	Player* selected = selectPlayers(arr, n, m);
	writeTeam(selected, m, "Selected.txt");
	cout << "Selection is done, check your files.";
		cout << endl;
	char choice;
	cout << "Sort by Club (C), by Reward (R) :";
	cin >> choice;
	if (choice == 'C')
		sortTeamBy(arr, n, byClub);
	else if (choice == 'R')
		sortTeamBy(arr, n, byReward);

	printTeam(arr, n);
	cout << endl;

	return 0;
}