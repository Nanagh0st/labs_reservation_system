#pragma once
#include <iostream>
using namespace std;

// base identity class
class Identity {
public:

	//Operate menu;
	virtual void operMenu() = 0;


	// user_name
	string User_Name;
	// Password
	string Password;
};