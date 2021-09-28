#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<list>

using namespace std;

typedef struct standart_of_pipe
{
	int id1;
	int deametr1;
	double long1;
	bool ready1;
}standart_of_pipe;

void Print_menu() {
	system("cls");
	cout << "What do we want to do?" << endl;
	cout << "1. Add pipe" << endl;
	cout << "2. Print pipe" << endl;
	cout << "3. Print status of pipe" << endl;
	cout << "4. Exit" << endl;
	cout << ">";
}

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
}
  
void Print(standart_of_pipe& s)
{
	cout <<"++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout <<"+                                          +"<< endl;
	cout<<"  id: " << s.id1 << "    " <<"deametr: " << s.deametr1 <<endl
		<<" dlina: " <<s.long1 <<"  gotovnost': " << s.ready1 << endl;
	cout << "+                                          +" << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
}
standart_of_pipe Create_pipe()
{	
	standart_of_pipe s = {};
	cout << "Vvedite deametr trubi'";
	cin >> s.deametr1;
	cout << "Vvedite dliny trubi'";
	cin >> s.long1;
	cout << "Vvedite gotovnost' trubi'";
	cin >> s.ready1;
	return s;
}

int main()
{
	list <int> list_off_all_objs = {};
	int variant;
	int size = 0;
	int list_capacit = 1;
	standart_of_pipe pipe;
	Print_menu();	
	do {		
		Print_menu();
		variant = get_variant(5);
		switch (variant) {
		case 1:
			pipe = Create_pipe();
			break;
		case 2:
			Print(pipe);
			break;
		case 3:
			cout << "Status of pipe number" /*Vedetsya ID*/ << endl;
		}		
		if (variant != 4)
			system("pause");
	} while (variant != 4);
}

