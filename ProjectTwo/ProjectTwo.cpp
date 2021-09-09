#include <iostream>
#include "GraphM.h"
#include "GraphL.h"
#include "Timer.h"
using namespace std;

int main_menu() {
	cout << "<<<<<<<<<<<<<<<<<<<<<< MAIN MENU <<<<<<<<<<<<<<<<<<<<<<<" << endl;
	cout << "1.graph algorithms for exemplary data" << endl;
	cout << "2.time measurent for graph algorithms. Factors: represetnation of graph im memory, size of graph, density of graph" << endl;
	cout << "3.exit" << endl << endl;

	int x;
	while (true) {
		cout << "type '1' or '2' or '3'" << endl;
		cin >> x;
		if (x == 1 || x == 2 || x == 3)
			break;
	}
	cout << endl;
	return x;
}

void exemplary_menu() {
	GraphM m = GraphM(); // czy potrzebny destruktor zeby tu sie dobrze zniszczylo? - (wywolanie destruktora poprzez delete m) czy destruktor sam sie wywoluje jak koncza sie {}
	GraphL l;
	while (true) {
		cout << "<<<<<<<< GRAPH ALGORITHMS FOR EXEMPLARY DATA MENU (graph have to be connected) <<<<<<<<" << endl;
		cout << "1.read graph from file" << endl;
		cout << "2.show representation: weight matrix and neighbours list" << endl;;
		cout << "3.prim algorithm" << endl;
		cout << "4.dijikstra algorithm" << endl;
		cout << "5.exit" << endl << endl;

		int x;
		while (true) {
			cout << "type '1' or '2' or '3' or '4' or '5'" << endl;
			cin >> x;
			if (x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6 || x == 7)
				break;
		}

		int type;
		string file_name;
		switch (x) {
		case 1:
			cout << "give path to file" << endl;
			cin >> file_name;
			cout << "1.graph not directed" << endl;
			cout << "2.graph directed" << endl;
			while (true) {
				cout << "type '1' or '2'" << endl;
				cin >> type;
				if (type == 1 || type == 2 )
					break;
			}
			if (type == 1) {
				m.create_from_file(file_name, false);
				l.create_from_file(file_name, false);
			}
			else {
				m.create_from_file(file_name, true);
				l.create_from_file(file_name, true);
			}
			m.show();
			l.show();
			break;
		case 2:
			m.show();
			l.show();
			break;
		case 3:
			cout << "weight matrix" << endl;
			m.mst_prim(true);
			cout << "neighbourhs lists" << endl;
			l.mst_prim(true);
			break;
		case 4:
			cout << "weight matrix" << endl;
			m.path_dijikstra(true);
			cout << "neighbourhs lists" << endl;
			l.path_dijikstra(true);
			break;
		}

		if (x == 5)
			break;
	}
	cout << endl;
}

int main() {
	while (true) {
		int menu = main_menu();

		if (menu == 1) {
			exemplary_menu();
		}

		if (menu == 2) {
			Timer timer;
			timer.measure();
			//timer.test();

		}

		if (menu == 3) {
			break;
		}
	}
}
