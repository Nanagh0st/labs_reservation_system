#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include "unordered_map"
#include "lab.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"

class Student : public Identity{
public:
	Student();

	Student(int id, string User_Name, string Password);

	virtual void operMenu();

	void applyorder();

	void showMyOrder();

	void cancelOrder();

	int User_Id;

	unordered_map<int, int> hash_lab;
};