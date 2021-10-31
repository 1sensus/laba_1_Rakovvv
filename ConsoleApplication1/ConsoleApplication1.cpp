#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include<algorithm>

/*
https://github.com/papilinatm/cpp_lessons_2020/blob/master/cpp_lessons/main.cpp
Изменить программу из предыдущей работы:

1)добавить работу с несколькими объектами (несколько труб, несколько КС, с возможностью добавления, редактирования, удаления);
2)обеспечить уникальную идентификацию объектов;
3)поиск объектов по заданному фильтру:
a)трубы: по названию, по признаку «в ремонте»;
b)КС: по названию, по проценту незадействованных цехов;
4)пакетное редактирование труб (т.е. редактирование или всех найденных, или по выбору пользователя)
 UPD: название файлов для сохранения/загрузки задаются пользователем.
Пакетное редактирование - это отредактировать все элементы во множестве (например, все найденные) или подмножество (пользователь указывает, какие именно).

Для претендующих на высокий балл: разумное использование ресурсов, грамотная организация кода
(убрать излишнее дублирование кода, каждая функция выполняет небольшое, логически законченное действие).
Продемонстрировать умение и понимание работы с классами, ссылками, потоками ввода/вывода.*/
using namespace std;
struct standart_of_pipe
{
	int id_pipe;
	int diameter_pipe;
	double long_pipe;
	bool ready_pipe;
};
struct standart_of_nps
{
	int id_nps;
	string name_nps;
	double all_parts;
	double working_parts;
	double kpd;
};
int get_variant()
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
	cout << "3. Print all objects" << endl;
	cout << "4. Change status pipe" << endl;
	cout << "5. Change status nps" << endl;
	cout << "6. Save in file" << endl;
	cout << "7. Load from file" << endl;
	cout << "8. Delete nps by name " << endl;
	cout << "9. Search by filter" << endl;
	cout << "0. Exit" << endl;
}
void Print_menu_for_filter()
{
	system("cls");
	cout << "Searching by filter" << endl;
	cout << "1." << endl;
	cout << "2." << endl;
	cout << "3." << endl;
	cout << "4." << endl;
	cout << "5." << endl;
	cout << "0. Back" << endl;

}
void Print_pipe(const standart_of_pipe& s)
{
	cout << "  id: " << s.id_pipe << "  |  " << "deametr: " << s.diameter_pipe << "  |  " << "  dlina: " << s.long_pipe << "  |  "
		<< "  gotovnost': " << s.ready_pipe << endl;
}
void Print_nps(const standart_of_nps& n)
{
	cout << "  id: " << n.id_nps << "  |  " << "Name: " << n.name_nps << "  |  " << "zagrughennost': " << n.kpd
		<< " %(" << n.working_parts << " / " << n.all_parts << ")" << endl;
}
void Print_all_objects(const vector <standart_of_nps>& nps_vector, const	vector<standart_of_pipe>& pipe_vector)
{
	cout << "Pipes: " << endl;
	for (auto& pipe : pipe_vector)
	{
		Print_pipe(pipe);
	}
	cout << "Npss: " << endl;
	for (auto& nps : nps_vector)
	{
		Print_nps(nps);
	}
}
bool Check_ID_pipe(int s_id, const vector<standart_of_pipe>& pipe_vector)
{
	for (auto& pipe : pipe_vector)
		if (pipe.id_pipe == s_id)
			return false;
	return true;
}
bool Check_ID_nps(int n_id, const vector <standart_of_nps>& nps_vector)
{
	for (auto& nps : nps_vector)
		if (nps.id_nps == n_id)
			return true;
	return false;
}
standart_of_nps Create_nps(int nps_id)
{
	standart_of_nps n = {};
	n.id_nps = nps_id;
	cout << "Vvedite imya nps"<<endl;
	cin.ignore();
	getline(cin, n.name_nps);
	while (n.name_nps == "") {
		cout<<"VbI ne vveli imya"<<endl;
		getline(cin, n.name_nps);
	}
	cout << "Vvedite kol-vo rabotaushih cehov" << endl;
	cin >> n.working_parts;
	cout << "Vvedite obshee kol-vo cehov " << endl;
	cin >> n.all_parts;
	while (n.all_parts < n.working_parts)
	{
		cout << "Oshibka vvoda. Vvedite korrektnii dannii" << endl;

		cout << "Vvedite kol-vo rabotaushih cehov" << endl;
		cin >> n.working_parts;
		cout << "Vvedite obshee kol-vo cehov" << endl;
		cin >> n.all_parts;
	}
	n.kpd = n.working_parts / n.all_parts * 100;
	return n;
}
standart_of_pipe Create_pipe(int pipe_id)
{
	standart_of_pipe s = {};
	s.id_pipe = pipe_id;
	cout << "Vvedite diameter trubi'";
	cin >> s.diameter_pipe;
	cout << "Vvedite dliny trubi'";
	cin >> s.long_pipe;
	cout << "Vvedite status trubi'";
	cin >> s.ready_pipe;
	return s;
}
void Chenge_status_search_by_id_nps(vector <standart_of_nps>& nps_vector)
{
	int search_id;
	bool check = false;
	auto i = 0;
	cout << "Vvedite ID" << endl;
	cin >> search_id;
	for (auto& nps : nps_vector)
	{
		++i;
		if (nps.id_nps == search_id)
		{
			check = true;
			cout << "Vvedite novoe kol-vo rabotaushih cehov " << endl;
			cin >> nps.working_parts;
			while (nps.all_parts < nps.working_parts)
			{

				cout << "Vvedite kol-vo rabotaushih cehov" << endl;
				cin >> nps.working_parts;
				cout << "Vvedite obshee kol-vo cehov " << endl;
				cin >> nps.all_parts;
			}
			nps.kpd = nps.working_parts / nps.all_parts * 100;
			break;
		}
	} if (check == false)cout << "ID ne naiden";
	else { cout << "Izmeneniya sohraneni'"; }
}
void Chenge_status_search_by_id_pipe(vector <standart_of_pipe>& pipe_vector)
{
	int search_id;
	bool check = false;
	auto i = 0;
	cout << "Vvedite ID" << endl;
	cin >> search_id;
	for (auto& pipe : pipe_vector)
	{
		++i;
		if (pipe.id_pipe == search_id)
		{
			check = true;
			cout << "Vvedite novi' status: " << endl;
			cin >> pipe.ready_pipe;
		}
	} if (check == false)cout << "ID ne naiden";
	else { cout << "Izmeneniya sohraneni'"; }
}
void file_outer(const vector <standart_of_pipe>& pipe_vector, const vector<standart_of_nps>& nps_vector)
{
	fstream file_out;
	file_out.open("All.txt", fstream::out);
	if (!file_out.is_open())
	{
		cout << "Error!!!" << endl;
	}
	else
	{
		size_t a = size(pipe_vector);
		size_t b = size(nps_vector);
		file_out << a << endl;
		file_out << b << endl;

		for (auto& pipe : pipe_vector)
		{
			file_out << pipe.id_pipe << endl << pipe.diameter_pipe << endl << pipe.long_pipe << endl << pipe.ready_pipe << endl;
		}
		for (auto& nps : nps_vector)
		{
			file_out << nps.id_nps << endl << nps.name_nps << endl << nps.working_parts << endl << nps.all_parts << endl << nps.kpd << endl;
		}
		cout << "writen"<<endl;

	}
	file_out.close();
}
void read_file(vector <standart_of_pipe>& pipe_vector, vector<standart_of_nps>& nps_vector)
{

	ifstream read_file;
	read_file.open("All.txt", ifstream::in);
	if (!read_file.is_open()) { cout << "Error!!!"; }
	else
	{
		pipe_vector.clear();
		nps_vector.clear();
		int kol_vo_pipes;
		int kol_vo_npss;
		read_file >> kol_vo_pipes;
		read_file >> kol_vo_npss;
		while (!read_file.eof())
		{
			for (int i = 0; i < kol_vo_pipes; ++i)
			{
				standart_of_pipe pipe = {};
				read_file >> pipe.id_pipe;
				read_file >> pipe.diameter_pipe;
				read_file >> pipe.long_pipe;
				read_file >> pipe.ready_pipe;
				pipe_vector.push_back(pipe);

			}
			for (int i = 0; i < kol_vo_npss; ++i)
			{
				standart_of_nps nps = {};
				read_file >> nps.id_nps;
				read_file.ignore();
				getline(read_file, nps.name_nps);
				read_file >> nps.working_parts;
				read_file >> nps.all_parts;
				read_file >> nps.kpd;
				nps_vector.push_back(nps);
			}break;
		}read_file.close();
	}cout << "file read" << endl;
}
int Search_by_name_nps(vector<standart_of_nps>& nps_vector, string name)
{
	int i = 0;
	for (auto nps : nps_vector)
	{
		++i;
		if (nps.name_nps == name) { return i-1; }
	}return -1;
}
void Delete_elem(vector<standart_of_nps>& nps_vector)
{
	if (nps_vector.size() == 0) { cout << "Error!!!Spisok pust" << endl; }
	else {
		string name_of_nps;
		cout << "Vvedite imya elemeta" << endl;
		cin.ignore();
		getline(cin, name_of_nps);
		int id_of_delete_element = Search_by_name_nps(nps_vector, name_of_nps);
		if (id_of_delete_element == -1){ cout << "Error!!!" << endl;}
		else 
		{ nps_vector.erase(nps_vector.begin() + id_of_delete_element);
		cout <<"Deleted!"<<endl <<"Razmer spiska: " << nps_vector.size()<< endl;
		}
	}
}
int Id_arr(vector <standart_of_nps> nps_vector) 
{
	int i = 0;
	for (auto nps : nps_vector)
	{
		if (nps.id_nps!= i) { return i; }
		++i;
	}
}

int main()
{
	vector < standart_of_nps > nps_vector = {};
	vector <standart_of_pipe> pipe_vector = {};

	int pipe_counter = 0;
	int nps_counter = 0;
	int variant;
	do 
	{
		Print_menu();
		variant = get_variant();
		switch (variant) {
		case 1:
		{
			pipe_counter = pipe_vector.size();
			auto pipe = Create_pipe(pipe_counter);
			if (pipe.diameter_pipe == 0 || pipe.long_pipe == 0) { cout << " !!Error input,retry!!"; break; }
			pipe_vector.push_back(pipe);
			pipe_counter++;
			break;
		}
		case 2:
		{

			nps_counter = Id_arr(nps_vector);
			if (nps_vector.size() + 2 < nps_counter) { nps_counter = nps_vector.size(); }
			auto nps = Create_nps(nps_counter);
			if (nps.all_parts == 0) { cout << " !!Error input,retry!!"; break; }
			nps_vector.push_back(nps);
			nps_counter++;
			break;
		}
		case 3:
		{
			sort(nps_vector.begin(), nps_vector.end(), [](const standart_of_nps& nps1, const standart_of_nps& nps2)
			{
				return nps1.id_nps < nps2.id_nps;
			});			
			cout << "List of all objects" << endl;
			Print_all_objects(nps_vector, pipe_vector);
			break;
		}
		case 4:
		{
			cout << "Vvedite ID trubi', kotoryu hotite izmenit'" << endl;
			Chenge_status_search_by_id_pipe(pipe_vector);
			break;
		}
		case 5:
		{
			cout << "Vvedite ID nps, kotoryu hotite izmenit'" << endl;
			Chenge_status_search_by_id_nps(nps_vector);
			break;
		}
		case 6:
		{
			file_outer(pipe_vector, nps_vector);
			break;

		}
		case 7:
		{
			read_file(pipe_vector, nps_vector);
			break;
		}
		case 8:
		{
			cout << "Delete:" << endl;
			Delete_elem(nps_vector);
			break;
		}
		case 9:
			{
				int variant2;
				do {
						Print_menu_for_filter();
						variant2 = get_variant();
						switch (variant2)
						{
							case 1:
							{
								cout << "1" << endl;
								break;
							}				
							case 2:
							{
								cout << "2" << endl;
								break;
							}

						}
					if (variant2 != 0)system("pause");
				} while (variant2 != 0);
			}
		}
		if (variant != 0)system("pause");
	} while (variant != 0);
}

