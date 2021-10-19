#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

/*�� 1
������� ���������� ����������, ����������� ������� �������� ��������������� ����������
���� ��� �����: ����� � �� ��� ��� (� ������ ���������� ��������).
�������� �����: �������������, �����, �������, ������� "� �������".
�������� ��: �������������, ��������, ���������� �����, ���������� ����� � ������,
������������� (����� ����������, ���������� ��������� ������������� ��������������)
��� ������ ��������� ����������� ��������: ���������� � ������� ��� �� �����,
����� �� ������� ��� � ����, �������������� �������� "� �������" ��� �����, ������ � ������� ���� � ��,
���������� ���� ���������� � ����, �������� ���������� �� �����.
��� ������� ��������� ��������� ����, ������������� � ����������� ����� ��������
�� ������������.
������ ����: 1. �������� ����� 2. �������� �� 3. �������� ���� �������� 4. ������������� ����� 5. ������������� �� 6. ��������� 7. ��������� 0. �����
��������� �������� ����� �� �����������.
�����������: �������� ������������ ����������� ��������.
��������� ������ ���� ��������� � ����� ��������� ������������.
����� ��� �������� �����: ������������� ������������ ���������� � �������,
�������������� ������������� ���������� ����������, ������������������� ���.
��� ���������� ������ ����������� ��������� � github (� ������������ �������������).
� ������ ������������� ������ �� ��������� ������! */

//vector,��� ����� ������,�������� �� ������ � ��������,
//�������� �����,���������� � �������� � �� �����
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
	cout << "8. Exit" << endl;
}
void Print_pipe(const standart_of_pipe& s)/////////////////////////
{
	cout << "  id: " << s.id_pipe << "  |  " << "deametr: " << s.diameter_pipe << "  |  " << "  dlina: " << s.long_pipe << "  |  "
		<< "  gotovnost': " << s.ready_pipe << endl;
}
void Print_nps(const standart_of_nps& n)//////////////////////////////
{
	cout << "  id: " << n.id_nps << "  |  " << "Name: " << n.name_nps << "  |  " << "zanyatost': " << n.kpd
		<< " %(" << n.working_parts << " / " << n.all_parts << ")" << endl;
}
void Print_all_objects(const vector <standart_of_nps>& nps_vector,const	vector<standart_of_pipe>& pipe_vector)//////////////////////////////////////
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
bool Check_ID_pipe(int s_id,const vector<standart_of_pipe>& pipe_vector)//////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	for (auto& pipe : pipe_vector)
		if (pipe.id_pipe == s_id)
			return false;
	return true;
}
bool Check_ID_nps(int n_id,const vector <standart_of_nps>& nps_vector)/////////////////////////////////////
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
	cout << "Vvedite imya nps";
	cin.ignore();
	getline(cin, n.name_nps);
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
	s.id_pipe=pipe_id;	
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
	bool check;
	auto i = 0;
	cout << "Vvedite ID" << endl;
	cin >> search_id;
	for (auto& nps : nps_vector)
	{
		++i;
		if (nps.id_nps == search_id)
		{
			check=true;
			cout << "Vvedite novoe kol-vo rabotaushih cehov: " << endl;
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
	bool check;
	auto i = 0;
	cout << "Vvedite ID" << endl;
	cin >> search_id;
	for (auto& pipe : pipe_vector)
	{
		++i;
		if (pipe.id_pipe == search_id)
		{
			check=true;
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
		file_out << a<<endl;
		file_out << b << endl;

		for (auto& pipe : pipe_vector)
		{
			file_out<< pipe.id_pipe << endl << pipe.diameter_pipe << endl << pipe.long_pipe << endl << pipe.ready_pipe << endl;
		}
		for (auto& nps : nps_vector)
		{
			file_out << nps.id_nps << endl << nps.name_nps << endl << nps.working_parts << endl << nps.all_parts << endl << nps.kpd<<endl;
		}
		cout << "writen";

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
			for(int i=0;i<kol_vo_pipes;++i)
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
int main()
{
	vector < standart_of_nps > nps_vector = {};
	vector <standart_of_pipe> pipe_vector = {};

	int pipe_counter = 0;
	int nps_counter = 0;
	int variant;
	do {
		Print_menu();
		variant = get_variant();
		switch (variant) {
		case 1:			
			auto pipe = Create_pipe(pipe_counter);
			if (pipe.diameter_pipe == 0 || pipe.long_pipe == 0) { cout << " !!Error input,retry!!"; break; }
			pipe_vector.push_back(pipe);
			pipe_counter++;
			break;
		case 2:
		{
			auto nps = Create_nps(nps_counter);
			if (nps.all_parts == 0) { cout << " !!Error input,retry!!"; break; }
			nps_vector.push_back(nps);
			nps_counter++;
			break;
		}
		case 3:
			cout << "List of all objects" << endl;
			Print_all_objects(nps_vector, pipe_vector);
			break;
		case 4:
			cout << "Vvedite ID trubi', kotoryu hotite izmenit'" << endl;
			Chenge_status_search_by_id_pipe(pipe_vector);
			break;
		case 5:
			cout << "Vvedite ID nps, kotoryu hotite izmenit'" << endl;
			Chenge_status_search_by_id_nps(nps_vector);
			break;
		case 6:

			file_outer(pipe_vector, nps_vector);
			break;

		case 7:
			read_file(pipe_vector, nps_vector);
			break;
		}
		if (variant != 8)
			system("pause");
	} while (variant != 8);
}