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
	return 0;
}