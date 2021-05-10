#pragma once
#include <iostream>

class SaveLoad
{
	
public:
	static void Save(std::string filename, int* buffer, int X_COUNT, int Y_COUNT);
	static void Load(std::string filename, int* buffer, int size);
};

