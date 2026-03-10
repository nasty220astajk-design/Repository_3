
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
struct About {
	string Name;
	int Number;
	string Job;
	string Date;
};
//функция считывания файла;
void FileData(vector<About>& database) {
	setlocale(LC_ALL, "ru");
	ifstream file("text1.txt");
	string line;
	while (getline(file, line)) {
		About element;
		element.Name = line;
		if (getline(file, line)) {
			element.Number = stoi(line);
		}
		if (getline(file, line)) {
			element.Job = line;
		}
		if (getline(file, line)) {
			element.Date = line;
		}
		database.push_back(element);

	}
	file.close();
	cout << "данные загружены";
}
//функция из даты рождения в число;
int dateToInt(string strDate) {
	setlocale(LC_ALL, "ru");
	stringstream ss(strDate);
	string day, month, year;
	getline(ss, day, '.');
	getline(ss, month, '.');
	getline(ss, year);
	int birthNumber = 10000 * stoi(year) + 100 * stoi(month) + stoi(day);
	return birthNumber;
}
// шейкерная сортировка;
void Sort(vector<About>& database) {
	setlocale(LC_ALL, "ru");
	int left = 0;
	int right = database.size() - 1;
	while (left < right) {
		for (int i = 0; i < right; i++) {
			if (dateToInt(database[i].Date) < dateToInt(database[i + 1].Date)) {
				About dop = database[i];
				database[i] = database[i + 1];
				database[i + 1] = dop;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (dateToInt(database[i].Date) > dateToInt(database[i - 1].Date)) {
				About dop = database[i];
				database[i] = database[i - 1];
				database[i - 1] = dop;
			}
		}
		left++;
	}
}
// Функция для вывода списка сотрудников;
void OutputInfo(const vector<About>& database) {
	if (database.empty()) {
		cout << "База данных пуста. Сначала загрузите данные" << endl;
	}
	for (const auto& element : database) {
		cout << "ФИО:" << " " << element.Name << endl
			<< "Отдел:" << " " << element.Number << endl
			<< "Должность:" << " " << element.Job << endl
			<< "Дата рождения:" << " " << element.Date << endl
			<< "------------------------------------------------" << endl;
	}
}
int main() {
	setlocale(LC_ALL, "ru");
	vector<About> Database;
	int a;
	do {
		cout << "Выберите вариант действия:" << endl <<
			"1) Загрузить базу данных из файла" << endl<<
			"2) Шейкерная сортировка" << endl <<
			"3) Список сотрудников" << endl <<
			"4) Выход" << endl;
		cin >> a;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (a) {
		case 1:
			FileData(Database);
			break;
		case 2:
			Sort(Database);
			cout << "Сортировка выполена" << endl;
			break;
		case 3:
			OutputInfo(Database);
			break;
		case 4:
			cout << "Конец связи";
			break;
		default:
			cout << "Ошибка";
		}
	} while (a != 4);
}
