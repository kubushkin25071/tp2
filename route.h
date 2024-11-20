#pragma once
#include <fstream>	// ����-����� � ����
#include "check.h"

using namespace std; // ��� ����� � �����-������

/* ������� ����� �������*/

class Route {
protected:
	string first_point;
	string last_point;
	int number;
public:
	Route(); // ����������� ��� ����������
	Route(const int& number, const string& first_point, const string& last_point);//����������� � �����������
	Route(const Route& scr); // ����������� �����������
	~Route();  // ����������� ����������

	string getFirst_point();
	void setFirst_point(const string& first_point);

	string getLast_point();
	void setLast_point(const string& last_point);

	int getNumber();
	void setNumber(int number);

	void display();		// ����� �� �����
	void change_info() ;	// �������� ����������
	void save_to_file(ostream&) ;	// ��������� � ����
	void load_from_file(istream&) ;	// �������� � ����
};

