#include "admin.h"


Admin::Admin() {

}

Admin::Admin(string User_Name, string Password) {
	this->User_Name = User_Name;
	this->Password = Password;

    this->init_hash();

    ifstream ifs;
    ifs.open(LAB_FILE, ios::in);

    Lab l;
    while (ifs >> l.computer_id && ifs >> l.max_num) {
        hash_lab[l.computer_id] = l.max_num;
    }
    ifs.close();

}

void Admin::operMenu() {
    cout << "Welcome admin: " << this->User_Name <<" " << "login!" << endl;
    cout << "Lab number is: " << hash_lab.size() << endl;
    cout << "Current students number is: " << hash_stu.size() << endl;
    cout << "Current teachers number is: " << hash_tea.size() << endl;
    cout << "---------------------------------------------" << endl;
    cout << "                                             " << endl;
    cout << "                  1.Add account              " << endl;
    cout << "                                             " << endl;
    cout << "                  2.Check account              " << endl;
    cout << "                                             " << endl;
    cout << "                  3.Check lab               " << endl;
    cout << "                                             " << endl;
    cout << "                  4.Clear reservation              " << endl;
    cout << "                                             " << endl;
    cout << "                  0.Log out              " << endl;
    cout << "                                             " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Please select:" << endl;
}

void Admin::addAccount() {
    cout << "Please enter type of  account added" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;

    string fileName;
    string tip;
    ofstream ofs;

    int select = 0;
    cin >> select;
    string errorTip;

    if (select == 1) {
        fileName = STUDENT_FILE;
        tip = "Please enter student ID:";
        errorTip = "Student ID existed, please enter again";

    }
    else if (select == 2) {
        fileName = TEACHER_FILE;
        tip = "Please enter teacher ID:";
        errorTip = "Student ID existed, please enter again";
    }

    ofs.open(fileName, ios::out | ios::app);
    int id;
    string name;
    string password;

    cout << tip << endl;
    
    while (true) {
        cin >> id;
        if (select == 1) {
            if (hash_stu[id] == 1) {
                cout << errorTip << endl;
            }
            else {
                hash_stu[id] = 1;
                break;
            }
        }
        else if (select == 2) {
            if (hash_tea[id] == 1) {
                cout << errorTip << endl;
            }
            else {
                hash_tea[id] = 1;
                break;
            }
        }
    }

    cout << "Please enter the name" << endl;
    cin >> name;
    cout << "Please enter the password" << endl;
    cin >> password;

    ofs;
    ofs << id << " " << name << " " << password << " " << endl;
    cout << "Adding success" << endl;

    system("pause");
    system("cls");

    ofs.close();


}

void Admin::showAccount() {
    cout << "Please select account type" << endl;
    cout << "1. Student" << endl;
    cout << "2. Teacher" << endl;

    int select;
    cin >> select;
    if (select == 1) {
        if (hash_stu.size() == 0) {
            cout << "There are no students accounts in the system" << endl;
        }
        else {
            cout << "Students accounts are shown below:" << endl;
            ifstream ifs;
            ifs.open(STUDENT_FILE, ios::in);
            Student s;
            while (ifs >> s.User_Id && ifs >> s.User_Name && ifs >> s.Password) {
                cout << "Student ID: " << s.User_Id << "; " << "Name: " << s.User_Name << "; " << "Password: " << s.Password << ";" << endl;
            }
            ifs.close();
        }
    }
    else if (select == 2) {
        if (hash_tea.size() == 0) {
            cout << "There are no teachers accounts in the system" << endl;
        }
        else {
            cout << "Teachers accounts are shown below:" << endl;
            ifstream ifs;
            ifs.open(TEACHER_FILE, ios::in);
            Teacher t;
            while (ifs >> t.User_Id && ifs >> t.User_Name && ifs >> t.Password) {
                cout << "Teacher ID: " << t.User_Id << "; " << "Name: " << t.User_Name << "; " << "Password: " << t.Password << ";" << endl;
            }
            ifs.close();
        }
    }
    system("pause");
    system("cls");

}

void Admin::showLab() {
    cout << "Lab information shown below: " << endl;
    for (auto l : hash_lab) {
        cout << "Lab room number: " << l.first << " Lab maximum capacity: "<< l.second << endl;
    }
    system("pause");
    system("cls");
}

void Admin::emptyRecord() {
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.clear();

    cout << "Empty success" << endl;
    system("pause");
    system("cls");
}

void Admin::init_hash() {
    hash_stu.clear();
    hash_tea.clear();

    ifstream ifs;

    ifs.open(STUDENT_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "File read failed" << endl;
        return;
    }

    Student s;
    while (ifs >> s.User_Id && ifs >> s.User_Name && ifs >> s.Password) {
        hash_stu[s.User_Id] = 1;
    }
    ifs.close();


    ifs.open(TEACHER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "File read failed" << endl;
        return;
    }

    Teacher t;
    while (ifs >> t.User_Id && ifs >> t.User_Name && ifs >> t.Password) {
        hash_tea[t.User_Id] = 1;
    }
    
    ifs.close();

}