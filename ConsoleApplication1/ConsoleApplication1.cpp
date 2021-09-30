#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<list>

using namespace std;

typedef struct standart_of_pipe
<<<<<<< HEAD
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
=======
{
	int id1;
	int deametr1;
	double long1;
	bool ready1;
}standart_of_pipe;
>>>>>>> 1ccdb3c6428a2bae03f040821baea3fa4e90430d

void Print_menu() {
	system("cls");
	cout << "What do we want to do?" << endl;
	cout << "1. Add pipe" << endl;
	cout << "2. Print pipe" << endl;
	cout << "3. Print status of pipe" << endl;
<<<<<<< HEAD
	cout << "4. Add nps" << endl;
	cout << "5. Print nps" << endl;
	cout << "6. Exit" << endl;
	cout << ">";
}
=======
	cout << "4. Exit" << endl;
	cout << ">";
}

>>>>>>> 1ccdb3c6428a2bae03f040821baea3fa4e90430d
int get_variant(int count) {
    int digit{0};
    cin >> digit;
    if(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Not num" << endl;
    } else {
        cout << digit <<endl;
    }
    return digit;
<<<<<<< HEAD
}  
void Print_pipe(standart_of_pipe& s)
{
	cout <<"++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout <<"+                                          +"<< endl;
	cout <<"  id: " << s.id_pipe << "    " <<"deametr: " << s.deametr_pipe <<endl
		 <<"  dlina: " <<s.long_pipe <<"  gotovnost': " << s.ready_pipe << endl;
	cout << "+                                          +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
void Print_nps(standart_of_nps n)
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+                                          +" << endl;
	cout << "  id: " <<n.id_nps << "    " << "Name: " << n.name_nps<< endl
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
=======
}
  
void Print(standart_of_pipe& s)
{
	cout <<"++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout <<"+                                          +"<< endl;
	cout<<"  id: " << s.id1 << "    " <<"deametr: " << s.deametr1 <<endl
		<<" dlina: " <<s.long1 <<"  gotovnost': " << s.ready1 << endl;
	cout << "+                                          +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
>>>>>>> 1ccdb3c6428a2bae03f040821baea3fa4e90430d
}
standart_of_pipe Create_pipe()
{	
	standart_of_pipe s = {};
<<<<<<< HEAD
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
standart_of_nps Search_by_id(list<standart_of_nps> list_nps, int id)
{
	for (int i = 0; i != &list_nps.size;++i)
	{
		if (list_nps[i].id_nps == id) { return list_nps[i]; break; }

	}
	cout << "ID ne naiden";
=======
	cout << "Vvedite deametr trubi'";
	cin >> s.deametr1;
	cout << "Vvedite dliny trubi'";
	cin >> s.long1;
	cout << "Vvedite gotovnost' trubi'";
	cin >> s.ready1;
	return s;
>>>>>>> 1ccdb3c6428a2bae03f040821baea3fa4e90430d
}


int main()
{
<<<<<<< HEAD
	list <standart_of_pipe> pipe_list = {};
	list <standart_of_nps> nps_list = {};
=======
	list <int> list_off_all_objs = {};
>>>>>>> 1ccdb3c6428a2bae03f040821baea3fa4e90430d
	int variant;
	int size = 0;
	int list_capacit = 1;
	standart_of_pipe pipe;
<<<<<<< HEAD
	standart_of_nps nps;
=======
>>>>>>> 1ccdb3c6428a2bae03f040821baea3fa4e90430d
	Print_menu();	
	do {		
		Print_menu();
		variant = get_variant(5);
		switch (variant) {
		case 1:
			pipe = Create_pipe();
			break;
		case 2:
<<<<<<< HEAD
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
=======
			Print(pipe);
			break;
		case 3:
			cout << "Status of pipe number" /*Vedetsya ID*/ << endl;
		}		
		if (variant != 4)
			system("pause");
	} while (variant != 4);
>>>>>>> 1ccdb3c6428a2bae03f040821baea3fa4e90430d
}

