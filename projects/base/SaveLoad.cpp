#include "SaveLoad.h"
#include <iostream>
#include <fstream>
#include <string>
#include "example.h"

using namespace std;


void SaveLoad::Save(string filename, int* buffer, int X_COUNT, int Y_COUNT)
{
	ofstream mysave;
	mysave.open(filename);
	
	for (size_t y = 0; y < Y_COUNT; y++)
	{
		for (size_t x = 0; x < X_COUNT; x++)
		{
			int i = x + y * X_COUNT;
			mysave << buffer[i] << ", ";
		}

		mysave << std::endl;
	}

	mysave.close();
}

void SaveLoad::Load(string filename, int* buffer, int size)
{
	
	string line;
	ifstream mysave(filename);
	int i = 0;
	if (mysave.is_open())
	{
		while (getline(mysave, line))
		{
			int cutStart = 0;
			int commaIndex = -1;

			while (true)
			{
				cutStart = commaIndex + 1;
				commaIndex = line.find(',', commaIndex + 1);

				if (commaIndex < 0)
					break;
				
				string str = line.substr(cutStart, commaIndex - cutStart);
				buffer[i] = std::stoi(str);
				i++; 
			//   std::cout << i << str << std::endl;
			}
			
		}
		mysave.close();
	}
	
	else 
	{
		cout << "Unable to open save";
	}
	
	/*std::string line = "12353, 4536, 345, 2342, 3425";
	
	int cutStart = 0;
	int commaIndex = -2;

	while (true)
	{
		cutStart = commaIndex + 2;
		commaIndex = line.find(',', cutStart);

		string str = line.substr(cutStart, commaIndex - cutStart);
		int lood = std::stoi(str);
		cout << lood << std::endl;

		if (commaIndex < 0)
			break;
		
	}*/
	

}