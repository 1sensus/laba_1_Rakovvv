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
	cout << "6. EPrint all nps list" << endl;
	cout << "8. Exit" << endl;
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
void Print_nps_list(list<standart_of_nps>nps_list, int size_nps_list)
{	 
	for (int i = 0; i < size_nps_list; ++i)
	{
		Print_nps(nps_list[i]);
	}
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
/*standart_of_nps Search_by_id(list<standart_of_nps> list_nps, int id)
{
	int size_nps_list = sizeof(list_nps) / sizeof(standart_of_nps);
	for (int i = 0; i <size_nps_list; ++i)
	{
		if (list_nps[i].id_nps == id) { cout << list_nps[i]; }
	}
	cout << "ID ne naiden";
}*/
int main()
{
	list <standart_of_pipe> pipe_list = {};
	list <standart_of_nps> nps_list = {};
	int variant;
	int size_nps_list = sizeof(nps_list) / sizeof(standart_of_nps);
	standart_of_pipe pipe;
	standart_of_nps nps;
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
			cout << "Status of pipe number" << endl;
			break;
		case 4:
			nps = Create_nps();
			nps_list.push_back(nps);
			break;
		case 5:
			Print_nps(nps);
			break;
		case 6:
			Print_nps_list(nps_list, size_nps_list);
			break;
		}
		if (variant != 8)
			system("pause");
	} while (variant != 8);
}

