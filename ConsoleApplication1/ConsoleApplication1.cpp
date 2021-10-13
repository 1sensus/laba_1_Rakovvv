#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

/*ЛР 1
Создать консольное приложение, описывающая базовые сущности трубопроводного транспорта 
газа или нефти: труба и КС или НПС (в сильно упрощенном варианте).
Свойства трубы: идентификатор, длина, диаметр, признак "в ремонте". 
Свойства КС: идентификатор, название, количество цехов, количество цехов в работе,
эффективность (некий показатель, обобщающий различные специфические характеристики)
Для каждой структуры реализовать операции: считывание с консоли или из файла,
вывод на консоль или в файл, редактирование признака "в ремонте" для трубы, запуск и останов цеха в КС,
сохранение всей информации в файл, загрузка информации из файла.
При запуске программы выводится меню, запрашивающее в бесконечном цикле действие
от пользователя. 
Пример меню: 1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Редактировать трубу 5. Редактировать КС 6. Сохранить 7. Загрузить 0. Выход
Поддержка русского языка не обязательна.
Обязательно: проверка корректности совершаемых действий.
Программа должна быть устойчива к любым действиям пользователя.
Повод для снижения балла: бессмысленное наименование переменных и функций, 
необоснованное использование глобальных переменных, неструктурированный код.
Ход выполнения работы фиксируется коммитами в github (с осмысленными комментариями).
К ответу прикрепляется ссылка на финальный коммит! */

//vector,имя через пробел,передача по ссылке и значению,
//проверка ввода,сохранение и загрузка в из файла
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
	double all_parts;
	double warking_parts;
	double kpd; 
}standart_of_nps;
int get_variant(int a)
{
	int number;
	while (1)
	{
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input " << endl;
		}
		else
			break;
		cout << "Try again" << endl;
	}
	return number;
}
void Print_menu() {
	system("cls");	
	cout << "What do we want to do?" << endl;
	cout << "1. Add pipe" << endl;
	cout << "2. Add nps" << endl;
	cout << "3. Print all objects" <<endl;
	cout << "4. Change status pipe" << endl;
	cout << "5. Change status nps" << endl;
	cout << "6. Save in file" << endl;
	cout << "7. Load from file" << endl;
	cout << "8. Exit" << endl;
}
void Print_pipe(standart_of_pipe& s)
{
		cout << "  id: " << s.id_pipe << "  |  " << "deametr: " << s.deametr_pipe << "  |  " << "  dlina: " << s.long_pipe << "  |  "
		<< "  gotovnost': " << s.ready_pipe << endl;
}
void Print_nps(standart_of_nps n)
{	
	cout << "  id: " << n.id_nps << "  |  " << "Name: " << n.name_nps << "  |  " << "efectivnost'': " << n.kpd
		<< " %(" << n.warking_parts << " / " << n.all_parts << ")" << endl;
}
void Print_all_objects(vector <standart_of_nps> nps_vector,
	vector<standart_of_pipe> pipe_vector)
{	
	cout << "Npss: "<<endl;
	for (auto& nps : nps_vector) 
	{
		Print_nps(nps);
	}
	cout << "Pipes: "<<endl;
	for (auto& pipe : pipe_vector)
	{
		Print_pipe(pipe);
	}
}
int Cheke_ID_pipe(int s_id, vector<standart_of_pipe> pipe_vector)
{
	int cheker = 0;
	for (auto& pipe : pipe_vector)
	{
		if (pipe.id_pipe == s_id)
		{
			++cheker;
		}
	}
	return cheker;
}
int Cheke_ID_nps(int n_id, vector <standart_of_nps>nps_vector) 
{
	int cheker = 0;
	for (auto& nps : nps_vector)
	{
		if (nps.id_nps == n_id)
		{
			++cheker;
		}
	}
	return cheker;
}
standart_of_nps Create_nps(vector<standart_of_nps> nps_vector)
{
	standart_of_nps n = {};
	cout << "Vvedite ID nps";
	cin >> n.id_nps;	
	int cheke_id = Cheke_ID_nps(n.id_nps, nps_vector);
		while (cheke_id != 0)
		{
			cout << "Danni' ID zanyat, vvedite drugoi'" << endl;
			cin >> n.id_nps;
			cheke_id = Cheke_ID_nps(n.id_nps, nps_vector);
		}
	cout << "Vvedite imya nps";
	cin.ignore();
	getline(cin, n.name_nps);
	cout << "Vvedite kol-vo rabotaushih cehov" << endl;
	cin >> n.warking_parts;
	cout << "Vvedite obshee kol-vo cehov "<<endl;
	cin >> n.all_parts;
	while (n.all_parts < n.warking_parts)
	{
		cout << "Oshibka vvoda. Vvedite korrektnii dannii"<<endl;

		cout << "Vvedite kol-vo rabotaushih cehov" << endl;
		cin >> n.warking_parts;
		cout << "Vvedite obshee kol-vo cehov" << endl;
		cin >> n.all_parts;
	}
	n.kpd = n.warking_parts / n.all_parts * 100;
	return n;
}
standart_of_pipe Create_pipe(vector<standart_of_pipe> pipe_vector)
{
	standart_of_pipe s = {};
	cout << "Vvedite ID trubi'";
	cin >> s.id_pipe;
	int cheke_id = Cheke_ID_pipe(s.id_pipe,pipe_vector);
		while (cheke_id!=0)
		{
			cout << "Danni' ID zanyat, vvedite drugoi'"<<endl;
			cin >> s.id_pipe;
			cheke_id = Cheke_ID_pipe(s.id_pipe, pipe_vector);
		}
	cout << "Vvedite deametr trubi'";
	cin >> s.deametr_pipe;
	cout << "Vvedite dliny trubi'";
	cin >> s.long_pipe;
	cout << "Vvedite status trubi'";
	cin >> s.ready_pipe;
	return s;
}
void Chenge_status_search_by_id_nps(vector <standart_of_nps>& nps_vector)
{
	int search_id;
	int cheker=0;
	auto i = 0;
	cout << "Vvedite ID"<<endl;
	cin >> search_id;
	for (auto& nps : nps_vector)
	{
		++i;
		if (nps.id_nps == search_id) 
		{
			 ++cheker;			
			 cout << "Vvedite novoe kol-vo rabotaushih cehov: " << endl;
			 cin >> nps.warking_parts;
			 while (nps.all_parts < nps.warking_parts)
			 {			 

				 cout << "Vvedite kol-vo rabotaushih cehov" << endl;
				 cin >> nps.warking_parts;
				 cout << "Vvedite obshee kol-vo cehov " << endl;
				 cin >> nps.all_parts;
			 }
			 nps.kpd = nps.warking_parts / nps.all_parts * 100;
			 break;
		}
	} if(cheker == 0)cout << "ID ne naiden";
	else { cout << "Izmeneniya sohraneni'"; }
}
void Chenge_status_search_by_id_pipe(vector <standart_of_pipe>& pipe_vector)
{
	int search_id;
	int cheker = 0;
	auto i = 0;
	cout << "Vvedite ID" << endl;
	cin >> search_id;
	for (auto& pipe : pipe_vector)
	{
		++i;
		if (pipe.id_pipe == search_id)
		{
			++cheker;			
			cout << "Vvedite novi' status: " << endl;
		    cin >> pipe.ready_pipe;
		}
	} if (cheker == 0)cout << "ID ne naiden";
	else { cout << "Izmeneniya sohraneni'"; }
}
void file_nps(vector<standart_of_nps>& nps_vector)
{	
	fstream file_out;
	file_out.open("Npss.txt", fstream::out);
	if (!file_out.is_open())
	{
		cout << "Error!!!" << endl;
	}
	else
	{
		for (auto& nps : nps_vector)
		{
			file_out << nps.id_nps << "|" << nps.name_nps << "|"<<nps.kpd<<
				"|"<<nps.warking_parts<<"|"<<nps.all_parts<<"|" << endl;
		}
	}
	file_out.close();
}
void file_pipe(vector<standart_of_pipe>& pipe_vector)
{
	fstream file_out;
	file_out.open("Pipes.txt", fstream::out);
	if (!file_out.is_open())
	{
		cout << "Error!!!" << endl;
	}
	else
	{
		for (auto& pipe : pipe_vector)
		{
			file_out << pipe.id_pipe << "|" << pipe.deametr_pipe << "|"
				<< pipe.long_pipe << "|" << pipe.ready_pipe << "|"<<endl;
		}
	}
	file_out.close();
}
void read_nps(vector <standart_of_nps>& nps_vector)
{
	standart_of_nps nps = {};
	ifstream read_file;
	read_file.open("Npss.txt");
		if (!read_file.is_open()) { cout << "Error!!!"; }
		else
		{
			string  part_of_line,id_s,name_s,kpd_s,works_s,all_s;
			cout << "opened"<<endl;	
			int i = 0;
			while (!read_file.eof())
			{
				++i;
				getline(read_file, part_of_line);
				size_t _1st;
				_1st= part_of_line.find('|');
				id_s = part_of_line.substr(0,_1st);
				part_of_line.erase(0, _1st+1);
				_1st = part_of_line.find('|');
				nps.name_nps= part_of_line.substr(0, _1st);
				part_of_line.erase(0, _1st + 1);
				_1st = part_of_line.find('|');
				kpd_s = part_of_line.substr(0, _1st);
				part_of_line.erase(0, _1st + 1);
				_1st = part_of_line.find('|');
				works_s = part_of_line.substr(0, _1st);
				part_of_line.erase(0, _1st + 1);
				_1st = part_of_line.find('|');
				all_s = part_of_line.substr(0, _1st);
				part_of_line.erase(0, _1st + 1);

				nps.id_nps = stoi(id_s);
				nps.kpd = atof(kpd_s.c_str());
				nps.warking_parts = atof(works_s.c_str());
				nps.all_parts = atof(all_s.c_str());
				nps_vector.push_back(nps);

				/*_2nd = part_of_line.find('|');
				name_s = part_of_line.substr(_1st,_2nd);
				part_of_line.erase(_2nd);
				_1st = part_of_line.find('|');
				kpd_s = part_of_line.substr(0, _1st);
				part_of_line.erase(0, _1st+1);
				nps.id_nps = stoi(id_s);
				nps.name_nps = name_s;
				nps.kpd = atof(kpd_s.c_str());
				nps_vector.push_back(nps);*/										
			}
		}
	read_file.close();
	/*	
	nps.id_nps = stoi(part_of_line);
	nps.name_nps = part_of_line;
	nps.kpd = atof(part_of_line.c_str())
	nps_vector.push_back(nps);;
	*/
}

int main()
{	
	vector < standart_of_nps > nps_vector = {};
	vector <standart_of_pipe> pipe_vector = {};	
	int size_nps_vector = sizeof(nps_vector) / sizeof(standart_of_nps);
	standart_of_pipe pipe;
	standart_of_nps nps;
	int variant;
	do {
		Print_menu();
		variant = get_variant(2);
		switch (variant) {
		case 1:
			pipe = Create_pipe(pipe_vector);
			pipe_vector.push_back(pipe);
			break;
		case 2:
			nps = Create_nps(nps_vector);
			nps_vector.push_back(nps);
			break;			
		case 3:
			cout << "List of all objects" << endl;
			Print_all_objects(nps_vector, pipe_vector);
			break;
		case 4:
			cout << "Vvedite ID trubi', kotoryu hotite izmenit'"<<endl;
			Chenge_status_search_by_id_pipe(pipe_vector);
			break;
		case 5:
			cout << "Vvedite ID nps, kotoryu hotite izmenit'" << endl;
			Chenge_status_search_by_id_nps(nps_vector);
			break;
		case 6:
			{
			cout << "1.Zapisat' pipes" << endl << "2.Zapisat' npss"<<endl;
			int x;
				cin >> x;
			while ((x != 1) && (x != 2)) 
			{
				cout << "Vvedite correktni otvet";
			}
			if (x == 1) { file_pipe(pipe_vector); }
			else { file_nps(nps_vector); }
			
			break;
			}
		case 7:
			read_nps(nps_vector);
			break;
		}
		if (variant != 8)
			system("pause");
	} while (variant != 8);
} 