#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <unordered_map>
#include "student.h"
#include "teacher.h"
#include "lab.h"


class Admin : public Identity{
public:
	Admin();

	Admin(string User_Name, string Password);

	virtual void operMenu();

	void addAccount();

	void showAccount();

	void showLab();

	void emptyRecord();

	void init_hash();

	unordered_map<int, int> hash_stu;

	unordered_map<int, int> hash_tea;

	unordered_map<int, int> hash_lab;
};