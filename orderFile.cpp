#include "orderFile.h"

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string student_id;
	string name;
	string room_id;
	string status;

	this->size = 0;

	while (ifs >> date && ifs >> interval && ifs >> student_id && ifs >> name && ifs >> room_id && ifs >> status) {
		string key;
		string value;
		unordered_map<string, string> m;
		
		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = student_id.find(":");
		if (pos != -1) {
			key = student_id.substr(0, pos);
			value = student_id.substr(pos + 1, student_id.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = name.find(":");
		if (pos != -1) {
			key = name.substr(0, pos);
			value = name.substr(pos + 1, name.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = room_id.find(":");
		if (pos != -1) {
			key = room_id.substr(0, pos);
			value = room_id.substr(pos + 1, room_id.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}
		
		this->order_data.insert(make_pair(this->size, m));
		this->size++;

		//Test read in success
		/*for (auto o : this->order_data) {
			cout << o.first << "/" << endl;
			for (auto a : o.second) {
				cout << a.first << ":" << a.second << " ";
			}
			cout << endl;
		}*/
	}
}

void OrderFile::updateFile() {
	if (this->size == 0) {
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->size; i++) {
		ofs << "date:" << this->order_data[i]["date"] << " ";
		ofs << "interval:" << this->order_data[i]["interval"] << " ";
		ofs << "student_id:" << this->order_data[i]["student_id"] << " ";
		ofs << "name:" << this->order_data[i]["name"] << " ";
		ofs << "room_id:" << this->order_data[i]["room_id"] << " ";
		ofs << "status:" << this->order_data[i]["status"] << endl;
	}
	ofs.close();
}