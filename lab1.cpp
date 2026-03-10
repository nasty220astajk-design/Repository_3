#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	string text = "Дело было в январе, стояла елка на горе, а возле этой елки бродили злые волки.";
	string finalText = "";
	int n = 6;
	vector <int> k = {2, 5, 1, 3, 4, 6};
	while (text.size() % n != 0) {
		text += " ";
	}
	for (int i = 0; i < text.size(); i += n) {
		string block = text.substr(i, n);
		string blocks = block;
		for (int j = 0; j < n; j++) {
			blocks[j] = block[k[j] - 1];
		}
		finalText += blocks;
	}
	cout << text << endl;
	cout<<finalText<<endl;

	ofstream out;
	out.open("text.txt");
	if (out.is_open()) {
		out << finalText << endl;
		out.close();
	}

}