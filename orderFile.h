#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <unordered_map>
#include <fstream>


class OrderFile {
public:

	//Constuctor
	OrderFile();

	//Update resveration record
	void updateFile();

	//Record container
	unordered_map<int, unordered_map<string, string>> order_data;

	//Size of record
	int size;
};
