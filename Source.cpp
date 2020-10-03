#include "Graph.h"
#include "Utility.h"
#include "Trie.h"
#include "Interface.h"

int main() {
	system("color F0");
	graph g;

	Date dt(2019, 12, 3);
	g.DisplayDirectFlight(0, 4, dt,"ANA");
	g.scenerio1(0,9,dt,"Emirates");
	cout << "\n\n\n\n\n";
	g.scenerio4(0, 9, dt);
	g.scenerio1(0,2,dt,"Emirates");
	g.scenerio5(0,4,dt,"Emirates");

	//cout << abs(dt.getDifference(dt, dt1));


	TRIE t("Dictionary.txt");
	cout << t.SpellChecker("islamayad");


	Interface();

	system("pause");
	return 0;
}
