#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <vector>

//vector,имя через пробел,передача по ссылке и значению, проверка ввода,сохранение и загрузка в из файла

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
int get_variant(int count) {
	int variant;
	char s[100]; // строка для считывания введённых данных
	sscanf("%s", s); // считываем строку

	// пока ввод некорректен, сообщаем об этом и просим повторить его
	while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
		printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
		sscanf("%s", s); // считываем строку повторно
	}
	return variant;
}
void Print_menu() {
	system("cls");	
	cout << "What do we want to do?" << endl;
	cout << "1. Add pipe" << endl;
	cout << "2. Print pipe" << endl;
	cout << "3. Print status of pipe" << endl;
	cout << "4. Add nps" << endl;
	cout << "5. Print nps" << endl;
	cout << "6. EPrint all nps list" << endl;
	cout << "7. Search by ID" << endl;
	cout << "8. Exit" << endl;
	cout << ">";
}
void Print_pipe(standart_of_pipe& s)
{
	cout << "  id: " << s.id_pipe << "  |  " << "deametr: " << s.deametr_pipe << "  |  " << "  dlina: " << s.long_pipe << "  |  "
		<< "  gotovnost': " << s.ready_pipe << endl;
}
void Print_nps(standart_of_nps n)
{	
	cout<<"  id: " << n.id_nps << "  |  " << "Name: " << n.name_nps << "  |  " << "gotovnost': " << n.ready_nps << endl;
}
void Print_nps_list(list <standart_of_nps> nps_list)
{	
	for (auto& nps : nps_list) 
	{
		Print_nps(nps);
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
void Search_by_id(list<standart_of_nps>nps_list)
{
	int search_id;
	cout << "Vvedite ID";
	cin >> search_id;
	for (auto& nps : nps_list)
	{
		if (nps.id_nps == search_id) 
		{
			 Print_nps(nps); 
		}
		else { cout << "ID ne naiden"; }

	}
	
}
int main()
{
	list <standart_of_pipe> pipe_list = {};
	list <standart_of_nps> nps_list = {};
	int variant=get_variant(5);
	int size_nps_list = sizeof(nps_list) / sizeof(standart_of_nps);
	standart_of_pipe pipe;
	standart_of_nps nps;
	do {
		Print_menu();
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
			Print_nps_list(nps_list);
			break;
		case 7:			
			Search_by_id(nps_list);
			break;
		}
		if (variant != 8)
			system("pause");
	} while (variant != 8);
}

