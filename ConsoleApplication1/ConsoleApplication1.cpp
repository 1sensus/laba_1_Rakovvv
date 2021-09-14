// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct standart_of_pipe
{
	int id1;
	int deametr1;
	double long1;
	bool ready1;
};
  
void Print(standart_of_pipe& s)
{
	std::cout << "id: " << s.id1 << " | " <<"deametr: " 
		<< s.deametr1 << " | "<<"dlina: " << s.long1<<"gotovnost': "<<s.ready1 <<" | ";
}
void Create_pipe(standart_of_pipe& s)
{	
	std::cout << "Vvedite deametr trubi'";
	std::cin >> s.deametr1;
	std::cout << "Vvedite dliny trubi'";
	std::cin >> s.long1;
	std::cout << "Vvedite gotovnost' trubi'";
	std::cin >> s.ready1;
}

int main()
{	
	//std::cout << "sozdat' novyu trbui'    :n:";
	//std::cout << "vivod                   :w:";
	standart_of_pipe s = {};
	Create_pipe(s);
	Print(s);
}

