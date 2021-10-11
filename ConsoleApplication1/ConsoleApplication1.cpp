#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>



//vector,��� ����� ������,�������� �� ������ � ��������,
//�������� �����,���������� � �������� � �� �����
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
	cout<<"  id: " << n.id_nps << "  |  " << "Name: " << n.name_nps << "  |  " << "gotovnost': " << n.ready_nps << endl;
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
	cout << "Vvedite status nps";
	cin >> n.ready_nps;
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
			 cout << "Vvedite novi' status nps: " << endl;
			 cin >> nps.ready_nps;
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
				fstream file_out;			
				file_out.open("All_objects.txt",fstream::in | fstream::out);
				if (!file_out.is_open()) 
					{
					cout << "Error!!!" << endl;
					}
				else
				{
					
				}
				file_out.close();
				break;
			}
		case 7:			
			break;
		}
		if (variant != 8)
			system("pause");
	} while (variant != 8);
} 