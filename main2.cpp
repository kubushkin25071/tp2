#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int count = 0;
	ifstream in;       // ����� ��� ������
	in.open("test2.txt"); // �������� ���� ��� ������

	if (!in) {
		cerr << "������ �������� ����� ��� ��������!" << endl;
		return 0;
	}

	string line, line_out;
	string vowels = "aeiouyAEIOUY";

	while (getline(in, line)) {		// ������ �� ����� ����� � ��������� ���������
		ostringstream ss(line);
		for (auto i = line.begin(); i != line.end(); i++) {
			cout << *i;
		}		// ����� �� �����
		bool start = false;
		cout << endl;
		/*for (int i = 0; i < line.size(); i++) {	// ������������ ��������� ������
			char s = line(i);	
			if (vowels.find_first_of(s) == -1) {

			}
			
			else {
				// ���� ������ �����
				if (i==0 || line(i-1) == ' ')
			}*/
		}
		//ostringstream ss(line);

		
	in.close();
	return 0;
}