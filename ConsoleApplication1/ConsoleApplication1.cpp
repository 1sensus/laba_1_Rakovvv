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
???????? ????????? ?? ?????????? ??????:

1)???????? ?????? ? ??????????? ????????? (????????? ????, ????????? ??, ? ???????????? ??????????, ??????????????, ????????);
2)?????????? ?????????? ????????????? ????????;
3)????? ???????? ?? ????????? ???????:
a)?????: ?? ????????, ?? ???????? ?? ????????;
b)??: ?? ????????, ?? ???????? ????????????????? ?????;
4)???????? ?????????????? ???? (?.?. ?????????????? ??? ???? ?????????, ??? ?? ?????? ????????????)
 UPD: ???????? ?????? ??? ??????????/???????? ???????? ?????????????.
???????? ?????????????? - ??? ??????????????? ??? ???????? ?? ????????? (????????, ??? ?????????) ??? ???????????? (???????????? ?????????, ????? ??????).

??? ???????????? ?? ??????? ????: ???????? ????????????? ????????, ????????? ??????????? ????
(?????? ???????? ???????????? ????, ?????? ??????? ????????? ?????????, ????????? ??????????? ????????).
?????????????????? ?????? ? ????????? ?????? ? ????????, ????????, ???????? ?????/??????.*/
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
	while (true)
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
	cout << "4. Change pipe" << endl;
	cout << "5. Change nps" << endl;
	cout << "6. Save in file" << endl;
	cout << "7. Load from file" << endl;
	cout << "8. Delete nps " << endl;
	cout << "9. Delete pipe " << endl;
	cout << "10. Filters" << endl;
	cout << "0. Exit" << endl;
}
void Print_menu_for_filter()
{
	system("cls");
	cout << "Searching by filter" << endl;
	cout << "1.Vozrastanie" << endl;
	cout << "2.Ubivanie" << endl;
	cout << "3.Nps po imeny" << endl;
	cout << "4.KPD" << endl;
	cout << "5." << endl;
	cout << "0. Back" << endl;

}
void Print_pipe(const standart_of_pipe& s)
{
	cout << "  id: " << s.id_pipe << " \t |  " << "deametr: " << s.diameter_pipe << "\t  |  " << "dlina: " << s.long_pipe << " \t |  "
		<< "  gotovnost': " << s.ready_pipe << endl;
}
void Print_nps(const standart_of_nps& n)
{
	cout << "  id: " << n.id_nps << " \t |  " << "Name: " << n.name_nps << "\t  |  " << "zagrughennost': " << n.kpd
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
void Change_by_id_nps(vector <standart_of_nps>& nps_vector,int search_id)
{	
	bool check = false;
	auto i = 0;	
	for (auto& nps : nps_vector)
	{
		++i;
		if (nps.id_nps == search_id)
		{
			check = true;
			cout << "Chto izmenit'?" << endl;
			int variant;
			do {
				system("cls");				
				cout << "Izmenyaem nps s Id: " <<search_id<<endl ;
				cout << "1.Kol-vo rabotauhsih" << endl;
				cout << "2.Imya" << endl;
				cout << "0.Exit" << endl;
				variant = get_variant();
				switch (variant) {
				case 1: 
					{
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
				case 2:
					{
						cout << "Vvedite novoe imya" << endl;
						cin.ignore();
						getline(cin, nps.name_nps);
						while (nps.name_nps == "") {
							cout << "VbI ne vveli imya" << endl;
							getline(cin, nps.name_nps);
						}
						break;
					}
				}if (variant != 0)system("pause");
			} while (variant != 0);
		}
	} if (check == false)cout << "ID ne naiden";
	else { cout << "Izmeneniya sohraneni'"; }
}
void Change_by_id_pipe(vector <standart_of_pipe>& pipe_vector)
{
	cout << "Vvedite ID trubi', kotoryu hotite izmenit'" << endl;
	int search_id;
	bool check = false;
	auto i = 0;	
	cin >> search_id;
	for (auto& pipe : pipe_vector)
	{
		++i;
		if (pipe.id_pipe == search_id)
		{
			check = true;
			int variant;
			do {
				system("cls");

				cout << "Izmenyaem pipe s Id: " << search_id << endl;
				cout << "1.Dliny" << endl;
				cout << "2.Diameter" << endl;
				cout << "3.Status" << endl;
				cout << "0.Exit" << endl;
				variant = get_variant();
				switch (variant) {
				case 1:					
				{	
					Print_pipe(pipe);
					cout << "Vvedite dliny";
					cin >> pipe.long_pipe;
					while (pipe.long_pipe == 0) { cout << "VbI ne vveli dlinny" << endl; cin >> pipe.long_pipe;}
					cout << "Novaya truba:" << endl;
					Print_pipe(pipe);
					break;
				}
				case 2:
				{
					Print_pipe(pipe);
					cout << "Vvediter diametr" << endl;
					cin >> pipe.diameter_pipe;
					while (pipe.diameter_pipe == 0) {
						cout << "VbI ne vveli diameter" << endl; cin >> pipe.diameter_pipe;}
					cout << "Novaya truba:" << endl;
					Print_pipe(pipe);
					break;

				}
				case 3:
				{
					Print_pipe(pipe);
					cout << "Vvedite noviy status" << endl;
					cin >> pipe.ready_pipe;
					cout << "Novaya truba:" << endl;
					Print_pipe(pipe);
					break;
				}
				}if (variant != 0)system("pause");
			} while (variant != 0);
		}
	} if (check == false)cout << "ID ne naiden";
	else { cout << "Izmeneniya sohraneni'"; }
}
void Change_many_by_id_nps(vector <standart_of_nps>& nps_vector) 
{

	int left_s,right_s;
	cout << "Vvedite levyu granicu" << endl;
	cin >> left_s;
	cout << "Vvedite pravyu granicu" << endl;
	cin >> right_s;
	while((left_s>nps_vector.size())||(right_s>nps_vector.size())||(right_s<left_s)
		|| (right_s == left_s))
	{
		cout <<"ERROR INPUT!!!"<<endl << "Vvedite levyu granicu" << endl;
		cin >> left_s;
		cout << "Vvedite pravyu granicu" << endl;
		cin >> right_s;
	}
	for (left_s; left_s < right_s+1; left_s++)
	{
		Change_by_id_nps(nps_vector,left_s);
	}

}

void file_outer(const vector <standart_of_pipe>& pipe_vector, const vector<standart_of_nps>& nps_vector)
{
	fstream file_out;
	cout<<"Vvedite nazvanie faila dlya sohraneniya"<<endl;
	string file;	
	cin.ignore();
	getline(cin, file);
	size_t cheke = file.find(".txt");
	if (cheke == -1) file += ".txt";
	file_out.open(file, fstream::out);
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
	cout << "Vvedite nazvanie faila dlya chtenia" << endl;
	string file;
	cin.ignore();
	getline(cin, file);
	size_t cheke = file.find(".txt");
	if (cheke == -1) file += ".txt";
	read_file.open(file, ifstream::in);
	if (!read_file.is_open()) { cout << "Error!!!"; }
	else
	{
		pipe_vector.clear();
		nps_vector.clear();
		int kol_vo_pipes, kol_vo_npss;
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
		}cout << "file read" << endl; read_file.close();
	}
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
void Delete_nps(vector<standart_of_nps>& nps_vector)
{
	if (nps_vector.size() == 0) { cout << "Error!!!Spisok pust" << endl; }
	else {
		int variant;
		do
		{
			system("cls");
			cout <<"Delete:"<<endl<< "1.By name"<<endl<<"2.By ID"<<endl<<"0.Exit"<<endl ;
			variant = get_variant();
			switch (variant) 
			{
			case 1: 
				{
					string name_of_nps;
					cout << "Vvedite imya elemeta" << endl;
					cin.ignore();
					getline(cin, name_of_nps);
					int id_of_delete_element = Search_by_name_nps(nps_vector, name_of_nps);
					if (id_of_delete_element == -1) { cout << "Error!!!" << endl; }
					else
					{
						nps_vector.erase(nps_vector.begin() + id_of_delete_element);
						cout << "Deleted!" << endl << "Razmer spiska: " << nps_vector.size() << endl;
					}
					break;
				}
			case 2:
				{
					int search_id;
					int i = -1;
					cout << "Vvedite ID" << endl;
					cin >> search_id;
					while (nps_vector.size() < search_id)
					{
						cout << "Takogo Id ne sushestvuet" << endl;
						cin >> search_id;
					}
					for (auto nps : nps_vector)
					{
						++i;
						if (nps.id_nps == search_id) {
							nps_vector.erase(nps_vector.begin() + i);
							cout << "Deleted!" << endl << "Razmer spiska: " << nps_vector.size() << endl; break;
						}
					}
					break;
				}
			}if (variant != 0)system("pause");
		} while (variant != 0);
	}
}
void Delete_pipe(vector<standart_of_pipe>& pipe_vector)
{
	if (pipe_vector.size() == 0) { cout << "Error!!!Spisok pust" << endl; }
	else {
		cout << "Vvedite ID" << endl;
		int search_id;
		int i = -1;
		cin >> search_id;
		while(pipe_vector.size()< search_id)
		{
			cout << "Takogo Id ne sushestvuet" << endl;
			cin >> search_id;
		}
		for (auto pipe : pipe_vector)
		{
			++i;
			if (pipe.id_pipe == search_id) {
				pipe_vector.erase(pipe_vector.begin() + i);
				cout << "Deleted!" << endl << "Razmer spiska: " << pipe_vector.size() << endl; break;
			}
		}
	}
}
int _Counter(vector<standart_of_pipe>& pipe_vector)
{
	if (pipe_vector.size() != 0)
	{
		int i = 0;
		for (auto pipe : pipe_vector)
		{
			if (pipe.id_pipe > i) { i = pipe.id_pipe; }
		}
		return i+1;
	}
	else { return 0;}
}
int _Counter(vector<standart_of_nps>& nps_vector)
{
	if (nps_vector.size() != 0)
	{
		int i = 0;
		for (auto nps : nps_vector)
		{
			if (nps.id_nps > i) { i = nps.id_nps; }
		}
		return i+1;
	}
	else { return 0; }
}
void Print_change_menu()
{
	cout << "1.Izmenit' 1 element" << endl << "2.Izmenit' neskol'ko" << endl << "0.Exit"<<endl;
}
int main()
{
	vector < standart_of_nps > nps_vector = {};
	vector <standart_of_pipe> pipe_vector = {};	
	int variant;
	int pipe_counter;
	int nps_counter;
	do 
	{
		Print_menu();
		variant = get_variant();
		switch (variant) {
		case 1:
		{	
			pipe_counter = _Counter(pipe_vector);
			auto pipe = Create_pipe(pipe_counter);
			if (pipe.diameter_pipe == 0 || pipe.long_pipe == 0) { cout << " !!Error input,retry!!"; break; }
			pipe_vector.push_back(pipe);
			pipe_counter++;
			break;
		}
		case 2:
		{
			nps_counter = _Counter(nps_vector);
			auto nps = Create_nps(nps_counter);
			if (nps.all_parts == 0) { cout << " !!Error input,retry!!"; break; }
			nps_vector.push_back(nps);
			nps_counter++;
			break;
		}
		case 3:
		{
			
			cout << "List of all objects" << endl;
			Print_all_objects(nps_vector, pipe_vector);
			break;
		}
		case 4:
		{
			if (pipe_vector.size() != 0) {
				Change_by_id_pipe(pipe_vector);
				break;
			}else { cout << "Spisok pust" << endl; break; }
		}
		case 5:
		{
			if (nps_vector.size() != 0)
			{
			
				int variant;			
				do {
					Print_change_menu();
					variant = get_variant();
					switch (variant)
					{
						case 1:
						{
							cout << "Vvedite id nps" << endl;
							int search_id;
							cin >> search_id;
							Change_by_id_nps(nps_vector,search_id);
							break;
						}
						case 2:
						{
							Change_many_by_id_nps(nps_vector);
							break;
						}
					}if (variant != 0)system("pause");
				} while (variant != 0);break;				
			}
			else { cout << "Spisok pust" << endl; break;}
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
			Delete_nps(nps_vector);
			break;
		}
		case 9:
		{
			cout << "Delete:" << endl;

			Delete_pipe(pipe_vector);
			break;
		}
		case 10:
			{
				int variant;
				do {
						Print_menu_for_filter();
						variant = get_variant();
						switch (variant)
						{
							case 1:
							{
								sort(nps_vector.begin(), nps_vector.end(), [](const standart_of_nps& nps1, const standart_of_nps& nps2)
								{
									return nps1.id_nps < nps2.id_nps;
								});
								sort(pipe_vector.begin(), pipe_vector.end(), [](const standart_of_pipe& pipe1, const standart_of_pipe& pipe2)
								{
									return pipe1.id_pipe < pipe2.id_pipe;
								});
								cout << "Otsortirovano +" << endl;
								break;
							}				
							case 2:
							{	sort(nps_vector.begin(), nps_vector.end(), [](const standart_of_nps& nps1, const standart_of_nps& nps2)
								{
								return nps1.id_nps > nps2.id_nps;
								});
								sort(pipe_vector.begin(), pipe_vector.end(), [](const standart_of_pipe& pipe1, const standart_of_pipe& pipe2)
								{
									return pipe1.id_pipe > pipe2.id_pipe;
								});
								cout << "Otsortirovano -" << endl;
								break;
							}
							case 3:
							{
								cout << "Kak sortirovat'?" << endl << "1.+" << endl << "2.-"<<endl;
								int x = get_variant();
								sort(nps_vector.begin(), nps_vector.end(), [&x](const standart_of_nps& nps1, const standart_of_nps& nps2)
								{
									if (x == 1)
										return nps1.name_nps < nps2.name_nps;
									else if (x == 2) { return nps1.name_nps > nps2.name_nps; }									
								});
								break;
							}
							case 4:
							{								
								sort(nps_vector.begin(), nps_vector.end(), [](const standart_of_nps& nps1, const standart_of_nps& nps2)
								{
									return nps1.kpd > nps2.kpd ;
								});
								break;
							}

						}
					if (variant != 0)system("pause");
				} while (variant != 0);
			}
		}
		if (variant != 0)system("pause");
	} while (variant != 0);
}