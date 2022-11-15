#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include "orderFile.h"

class Teacher : public Identity {
public:
	Teacher();

	Teacher(int id, string User_Name, string Password);

	virtual void operMenu();

	void showAllOrder();

	void reviewOrder();

	int User_Id;
};
