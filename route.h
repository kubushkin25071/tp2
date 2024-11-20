#pragma once
#include <fstream>	// ввод-вывод в файл
#include "check.h"

using namespace std; // для строк и ввода-вывода

/* Базовый класс Оркестр*/

class Route {
protected:
	string first_point;
	string last_point;
	int number;
public:
	Route(); // конструктор без параметров
	Route(const int& number, const string& first_point, const string& last_point);//конструктор с параметрами
	Route(const Route& scr); // конструктор копирования
	~Route();  // виртуальный деструткор

	string getFirst_point();
	void setFirst_point(const string& first_point);

	string getLast_point();
	void setLast_point(const string& last_point);

	int getNumber();
	void setNumber(int number);

	void display();		// вывод на экран
	void change_info() ;	// поменять информацию
	void save_to_file(ostream&) ;	// сохранить в файл
	void load_from_file(istream&) ;	// загрузть в файл
};

