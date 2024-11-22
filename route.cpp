#include "route.h"

Route::Route() {
    cout << "Вызван конструктор без параметров для Base класса\n";
} // конструктор без параметров

Route::Route(const int& number, const string& first_point, const string& last_point): number(number), first_point(first_point), last_point(last_point) {
    cout << "Вызван конструктор с параметрами для Base класса\n";
} //конструктор с параметрами

Route::Route(const Route& scr) : number(scr.number), first_point(scr.first_point), last_point(scr.last_point) {
    cout << "Вызван конструктор копирования для Base класса\n";
} // конструктор копирования

Route::~Route() {
    cout << "Вызван виртуальный деструктор для Base класса\n";
}  // виртуальный деструткор

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

// вывод на экран
void Route::display() {
    cout << "Номер маршрута: " << this->number << endl;
    cout << "Начальный пункт: " << this->first_point << endl;
    cout << "Конецчный пункт: " << this->last_point << endl;
}

// поменять название
void Route::change_info() {
    string newfirst_point, newlast_point;
    int newnumber, choice;

    cout << "Выберите информацию для изменения:" << endl;
    cout << "1 - номер маршрута" << endl;
    cout << "2 - начальный пункт" << endl;
    cout << "3 - конечный пункт" << endl;
    cout << "0 - Выход" << endl;
    choice = check_input();

    switch (choice) {
    case 1:
        cout << "Введите новый номер маршрута: " << endl;
        newnumber = check_input();
        setNumber(newnumber);
        cout << "Данные успешно изменены" << endl;
        break;
    case 2:
        cout << "Введите новый начальный пункт: " << endl;
        getline(cin, newfirst_point);
        setFirst_point(newfirst_point);
        cout << "Данные успешно изменены" << endl;
        break;
    case 3:
        cout << "Введите новый конечный пункт: " << endl;
        getline(cin, newlast_point);
        setLast_point(newlast_point);
        cout << "Данные успешно изменены" << endl;
        break;
    case 0:
        cout << "Выход из редактирования" << endl;
        break;
    default:
        cout << "Неверный выбор. Попробуйте снова" << endl;
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