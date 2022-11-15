#include "teacher.h";

Teacher::Teacher() {

}

Teacher::Teacher(int id, string User_Name, string Password) {
	this->User_Id = id;
	this->User_Name = User_Name;
	this->Password = Password;
}

void Teacher::operMenu() {
    cout << "Welcome teacher: " << this->User_Name << " " << "login!" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "                                             " << endl;
    cout << "                1.Check reservation              " << endl;
    cout << "                                             " << endl;
    cout << "                2.Review reservation             " << endl;
    cout << "                                             " << endl;
    cout << "                0.Log out              " << endl;
    cout << "                                             " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Please select:" << endl;
}

void Teacher::showAllOrder() {
    OrderFile of;
    if (of.size == 0) {
        cout << "No reservation record" << endl;
        system("pause");
        system("cls");
        return;
    }
    for (int i = 0; i < of.size; i++) {
        cout << i + 1 << ". ";
        cout << "Reservation  Date: Day " << of.order_data[i]["date"];
        cout << " Time interval: " << (of.order_data[i]["interval"] == "1" ? "Morning" : "Afternoon");
        cout << " Student id: " << of.order_data[i]["student_id"];
        cout << " Name: " << of.order_data[i]["name"];
        cout << " Lab: " << of.order_data[i]["room_id"];
        string status = "Status: ";
        if (of.order_data[i]["status"] == "1") {
            status += "Reviewing";
        }
        else if (of.order_data[i]["status"] == "2") {
            status += "Success";
        }
        else if (of.order_data[i]["status"] == "-1") {
            status += "Deny";
        }
        else {
            status += "Reservation cancel";
        }
        cout << status << endl;
    }

    system("pause");
    system("cls");
}

void Teacher::reviewOrder(){
    OrderFile of;
    if (of.size == 0) {
        cout << "No reservation record" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "All reservations needed to be reviewed has shown below: " << endl;
    vector<int> v;
    int index = 0;
    for (int i = 0; i < of.size; i++) {
        if (of.order_data[i]["status"] == "1") {
            v.push_back(i);
            cout << ++index << ". ";
            cout << "Reservation Date: Day " << of.order_data[i]["date"];
            cout << " Time interval: " << (of.order_data[i]["interval"] == "1" ? "Morning" : "Afternoon");
            cout << " Lab: " << of.order_data[i]["room_id"];
        }
    }

    cout << "Please enter the reservation record needed to review (0 represent exit)" << endl;
    int select = 0;
    int ret = 0;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            }
        }
        else {
            cout << "Please enter the review result" << endl;
            cout << "1. Success" << endl;
            cout << "2. Deny" << endl;
            cin >> ret;

            if (ret == 1) {
                of.order_data[v[select]]["status"] = "2";
            }
            else {
                of.order_data[v[select]]["status"] = "-1";
            }
            of.updateFile();
            cout << "Review finished!" << endl;
            break;
        }
        system("pause");
        system("cls");
    }

}

