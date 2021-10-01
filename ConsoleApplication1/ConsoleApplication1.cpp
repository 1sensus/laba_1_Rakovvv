#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

typedef struct standart_of_pipe
{
	int id_pipe;
	int deametr_pipe;
	double long_pipe;
	bool ready_pipe;
}standart_of_pipe;
typedef struct standart_of_nps
{
	int id_nps;
	string name_nps;
	bool ready_nps;
}standart_of_nps;

void Print_menu() {
	system("cls");
	cout << "What do we want to do?" << endl;
	cout << "1. Add pipe" << endl;
	cout << "2. Print pipe" << endl;
	cout << "3. Print status of pipe" << endl;
	cout << "4. Add nps" << endl;
	cout << "5. Print nps" << endl;
	cout << "6. Exit" << endl;
	cout << ">";
}
int get_variant(int count) {
	int digit{ 0 };
	cin >> digit;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Not num" << endl;
	}
	else {
		cout << digit << endl;
	}
	return digit;
}
void Print_pipe(standart_of_pipe& s)
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+                                          +" << endl;
	cout << "  id: " << s.id_pipe << "    " << "deametr: " << s.deametr_pipe << endl
		<< "  dlina: " << s.long_pipe << "  gotovnost': " << s.ready_pipe << endl;
	cout << "+                                          +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
void Print_nps(standart_of_nps n)
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+                                          +" << endl;
	cout << "  id: " << n.id_nps << "    " << "Name: " << n.name_nps << endl
		<< "  gotovnost': " << n.ready_nps << endl;
	cout << "+                                          +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
standart_of_nps Create_nps()
{
	standart_of_nps n = {};
	cout << "Vvedite ID nps";
	cin >> n.id_nps;
	cout << "Vvedite imya nps";
	cin >> n.name_nps;
	cout << "Vvedite status nps";
	cin >> n.ready_nps;
	return n;
}
standart_of_pipe Create_pipe()
{
	standart_of_pipe s = {};
	cout << "Vvedite ID trubi'";
	cin >> s.id_pipe;
	cout << "Vvedite deametr trubi'";
	cin >> s.deametr_pipe;
	cout << "Vvedite dliny trubi'";
	cin >> s.long_pipe;
	cout << "Vvedite status trubi'";
	cin >> s.ready_pipe;
	return s;
}
standart_of_nps Search_by_id(list<standart_of_nps> list_nps, standart_of_nps id_nps)
{
	int id = id_nps.id_nps;
	for (unsigned int i = 0; i < unsigned( list_nps.size()); ++i)
	{
		if (list_nps[i].id_nps == id) { return list_nps[i]; }
	}
	cout << "ID ne naiden";
}
int main()
{
	list <standart_of_pipe> pipe_list = {};
	list <standart_of_nps> nps_list = {};
	int variant;
	int size = 0;
	int list_capacit = 1;
	standart_of_pipe pipe;
	standart_of_nps nps;
	Print_menu();
	do {
		Print_menu();
		variant = get_variant(5);
		switch (variant) {
		case 1:
			pipe = Create_pipe();
			break;
		case 2:
			Print_pipe(pipe);
			break;
		case 3:
			cout << "Status of pipe number" /*Vedetsya ID*/ << endl;
			break;
		case 4:
			nps = Create_nps();
			break;
		case 5:
			Print_nps(nps);
			break;
		}
		if (variant != 6)
			system("pause");
	} while (variant != 6);
}

