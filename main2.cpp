#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	system("cls");
	setlocale(LC_ALL, "Russian");
	ifstream in;       // ����� ��� ������
	in.open("test2.txt"); // �������� ���� ��� ������

	if (!in) {
		cerr << "������ �������� ����� ��� ��������!" << endl;
		return 0;
	}

	string line;
	string vowels = "aeiouyAEIOUY";

	while (getline(in, line)) {		// ������ �� ����� ����� � ��������� ���������
		stringstream s;
		for (int i = 0; i < line.size(); i++) {
			char c = line[i];
			if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || c == ' ') s.put(c);
			else continue;
		}

		string word;
		while (s >> word) {
			char first = word[0];
			char last = word[word.size()-1];
			if (vowels.find_first_of(last) != -1 && vowels.find_first_of(first) != -1) cout << word << ' ' << word.size() << endl;
			}
		}
	in.close();
	return 0;
}