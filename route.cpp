#include "route.h"

Route::Route() {
    cout << "������ ����������� ��� ���������� ��� Base ������\n";
} // ����������� ��� ����������

Route::Route(const int& number, const string& first_point, const string& last_point): number(number), first_point(first_point), last_point(last_point) {
    cout << "������ ����������� � ����������� ��� Base ������\n";
} //����������� � �����������

Route::Route(const Route& scr) : number(scr.number), first_point(scr.first_point), last_point(scr.last_point) {
    cout << "������ ����������� ����������� ��� Base ������\n";
} // ����������� �����������

Route::~Route() {
    cout << "������ ����������� ���������� ��� Base ������\n";
}  // ����������� ����������

string Route::getFirst_point() {
    return first_point;
};
void Route::setFirst_point(const string& first_point) {
    this->first_point = first_point;
}

string Route::getLast_point() {
    return last_point;
}

void Route::setLast_point(const string& last_point) {
    this->last_point = last_point;
}

int Route::getNumber() {
    return number;
}

void Route::setNumber(int number) {
    this->number = number;
}

// ����� �� �����
void Route::display() {
    cout << "����� ��������: " << this->number << endl;
    cout << "��������� �����: " << this->first_point << endl;
    cout << "��������� �����: " << this->last_point << endl;
}

// �������� ��������
void Route::change_info() {
    string newfirst_point, newlast_point;
    int newnumber, choice;

    cout << "�������� ���������� ��� ���������:" << endl;
    cout << "1 - ����� ��������" << endl;
    cout << "2 - ��������� �����" << endl;
    cout << "3 - �������� �����" << endl;
    cout << "0 - �����" << endl;
    choice = check_input();

    switch (choice) {
    case 1:
        cout << "������� ����� ����� ��������: " << endl;
        newnumber = check_input();
        setNumber(newnumber);
        cout << "������ ������� ��������" << endl;
        break;
    case 2:
        cout << "������� ����� ��������� �����: " << endl;
        getline(cin, newfirst_point);
        setFirst_point(newfirst_point);
        cout << "������ ������� ��������" << endl;
        break;
    case 3:
        cout << "������� ����� �������� �����: " << endl;
        getline(cin, newlast_point);
        setLast_point(newlast_point);
        cout << "������ ������� ��������" << endl;
        break;
    case 0:
        cout << "����� �� ��������������" << endl;
        break;
    default:
        cout << "�������� �����. ���������� �����" << endl;
        break;
    }
}

void Route::save_to_file(ostream& out) {
    out << "-1" << '\n';
    out << first_point << '\n' << last_point << '\n' << number << '\n';
}

void Route::load_from_file(istream& in) {
    getline(in, first_point);
    getline(in, last_point);
    in >> number;
}