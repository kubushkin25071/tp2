#pragma once
#include "route.h"	// ������� �����


/* ��������� ��������*/
struct Element {
    Element* next;
    Route* data;
};

/* �����-���������*/
class Keeper {
    /*������ ����� ��������� � ���� ������*/
private:
    Element* head;
    Element* tail;
    int count;

public:
    Keeper(); // ����������� ��� ����������
    Keeper(Element* h, Element* t, int c); //����������� � �����������
    Keeper(Keeper& other); //����������� �����������
    ~Keeper(); //����������

    void delete_head(); // ������� �������
    void delete_all();  //������� ��
    void display_keeper();  //����� �� �����
    int get_count();    //�������� �����
    Element* get_head();    //�������� ������
    Element* get_tail();    // �������� �����

    // �������� ������� 
    Keeper& operator++(); // � ������
    friend Keeper& operator++(Keeper& K, int);  //� �����

    // ������� �������
    Keeper& operator--(int);    //� ������
    friend Keeper& operator--(Keeper& K);   //� �����

    // ������� ����� �������
    void add(Route* mover);
    void add_to_start(Route* mover);

    // �������/�������� �������
    Keeper& delete_element(int n);
    Keeper& edit_element(int n);

    //���������� � ����
    void save_to_file(const string& filename);
    // �������� �� �����
    void load_from_file(const string& filename);

    // ���������� ���������
    void sort_trains_by_number();
    // ����� 1 ����������� �������� �� ������ ��������
    int show_element(int n);
};