#pragma once
#include "route.h"	// базовый класс


/* Структура элемента*/
struct Element {
    Element* next;
    Route* data;
};

/* Класс-контейнер*/
class Keeper {
    /*Данные будут храниться в виде списка*/
private:
    Element* head;
    Element* tail;
    int count;

public:
    Keeper(); // Конструктор без параметров
    Keeper(Element* h, Element* t, int c); //Конструктор с параметрами
    Keeper(Keeper& other); //Конструктор копирования
    ~Keeper(); //Деструктор

    void delete_head(); // удалить сначала
    void delete_all();  //удалить всё
    void display_keeper();  //вывод на экран
    int get_count();    //получить длину
    Element* get_head();    //получить голову
    Element* get_tail();    // получить хвост

    // добавить элемент 
    Keeper& operator++(); // в начало
    friend Keeper& operator++(Keeper& K, int);  //в конец

    // удалить элемент
    Keeper& operator--(int);    //с начала
    friend Keeper& operator--(Keeper& K);   //с конца

    // создать новый элемент
    void add(Route* mover);
    void add_to_start(Route* mover);

    // удалить/добавить элемент
    Keeper& delete_element(int n);
    Keeper& edit_element(int n);

    //сохранение в файл
    void save_to_file(const string& filename);
    // загрузка из фалйа
    void load_from_file(const string& filename);

    // сортировка элементов
    void sort_trains_by_number();
    // показ 1 конкретного элемента по номеру маршрута
    int show_element(int n);
};