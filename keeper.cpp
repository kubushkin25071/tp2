#include "keeper.h"

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {
    cout << "Вызван конструктор без параметров для Keeper класса\n";
}

Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {
    cout << "Вызван конструктор с параметрами для Keeper класса\n";
}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Вызван конструктор копирования для Keeper класса\n";
}

Keeper::~Keeper() {
    cout << "Вызван деструктор для Keeper класса\n";
    delete_all();
}

// удаление головы
void Keeper::delete_head() {
    if (head) {
        Element* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
    }
}

// удаление всего через голову
void Keeper::delete_all() {
    while (head != 0)
        delete_head();

}

// вывод на экран по элементам
void Keeper::display_keeper() {
    Element* temp = head;

    if (count == 0) {
        cout << "Данных нет" << endl;
        return;
    }

    int i = 0;
    while (temp != 0) {
        cout << i + 1 << " - ";
        if (temp->data) {
            temp->data->display(); //вызов функции вывода на экран у объектов
        }
        else {
            cout << "Данных нет";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}

// получение кол-ва
int Keeper::get_count() {
    return count;
}

// добавление в начало
Keeper& Keeper::operator++() {
    string first_point;
    string last_point;
    int number;
    while (true) {
        cout << "Введите номер маршрута: ";
        number = check_input();
        int flag = show_element(number);
        if (flag == 0) break;
        else {
            cout << "Маршрут с таким номером существует!" << endl;
        }
    }
    cout << "Введите начальный пункт: ";
    getline(cin, first_point);
    cout << "Введите конечный пункт: ";
    getline(cin, last_point);
    Route* train = new Route(number, first_point, last_point);
    add_to_start(train);
    return *this;
}

// добавление в конец
Keeper& operator++(Keeper& K, int) {

    string first_point;
    string last_point;
    int number;
    while(true){
        cout << "Введите номер маршрута: ";
        number = check_input();
        int flag = K.show_element(number);
        if (flag == 0) break;
        else {
            cout << "Маршрут с таким номером существует!" << endl;
        }
    }
    
    cout << "Введите начальный пункт: ";
    getline(cin, first_point);
    cout << "Введите начальный пункт: ";
    getline(cin, last_point);
    Route* train = new Route(number, first_point, last_point);
    K.add(train);
    return K;
}

// удаление сначала
Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "Данных нет. Невозможно удалить с начала" << endl;
        return K;
    }

    Element* temp = K.head;
    K.head = K.head->next;

    delete temp->data;
    delete temp;
    K.count--;

    if (K.count == 0) {
        K.tail = nullptr;
    }

    return K;
}

// удаление в концe
Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "Данных нет." << endl;
        return *this;
    }

    if (this->count == 1) {
        delete this->head;
        this->head = this->tail = nullptr;
    }
    else {
        Element* temp = this->head;
        while (temp->next != this->tail) {
            temp = temp->next;
        }
        delete this->tail->data;
        delete this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }

    this->count--;
    return *this;
}

// удаление конкретного элемента
Keeper& Keeper::delete_element(int n) {

    if (this->count == 0) {
        cout << "Данных нет." << endl;
        return *this;
    }

    Element* temp = head;
    Element* temp1;

    while (temp->data->getNumber() != n) {
        temp1 = temp;
        temp = temp->next;
    }

    if (temp == head) {
        this->operator--(0);
        return *this;
    }

    Element* toDelete = temp;
    temp1->next = toDelete->next;

    if (toDelete == tail) {
        tail = temp1;
    }

    delete toDelete->data;
    delete toDelete;
    count--;

    return *this;
}

// изменение информации конкретного элемента
Keeper& Keeper::edit_element(int n) {

    if (this->count == 0) {
        cout << "Данных нет." << endl;
        return *this;
    }

    Element* temp = head;
    while(temp->data->getNumber()!=n) {
        temp = temp->next;
    }

    if (temp->data) {
        temp->data->change_info();
        if (temp->data->getNumber() != n){
            this->sort_trains_by_number();
        }
    }
    else {
        cout << "Данных нет" << endl;
    }

    return *this;
}

// получение головы
Element* Keeper::get_head() {
    return this->head;
}

// получение хвоста
Element* Keeper::get_tail() {
    return this->tail;
}

// сохранение в файл
void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save_to_file(out);   // каждый элемент сохраняется поэлементно 
        current = current->next;
    }
    out.close();
}

// загрузка из файла
void Keeper::load_from_file(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Ошибка открытия файла для загрузки!" << endl;
        return;
    }

    string marker;
    while (getline(in, marker)) {
        if (!marker.empty() && marker.back() == '\r') {
            marker.pop_back();
        }

        Route* mover = nullptr;
        if (marker == "-1") mover = new Route();
        else {
            cerr << "Неизвестный тип объекта: " << marker << endl;
            continue;
        }

        if (mover) {
            mover->load_from_file(in);
            int res_of_searh = this->show_element(mover->getNumber());
            if (res_of_searh) {
                cout << "Маршрут с таким номером уже существует!" << endl;
            }
            else {
                this->add(mover);
                cout << "Объект добавлен в контейнер" << endl;
            }
        }
    }

    in.close();
}

// добавление элемента в список
void Keeper::add(Route* mover) {
    Element* newElement = new Element;
    newElement->data = mover;
    newElement->next = nullptr;

    if (head == nullptr) {
        head = tail = newElement;
    }
    else {
        tail->next = newElement;
        tail = newElement;
    }

    count++;
}

// Добавление элемента в начало
void Keeper::add_to_start(Route* mover) {
    Element* newElement = new Element;
    newElement->data = mover;
    newElement->next = head;

    if (head == nullptr) {
        tail = newElement;
    }

    head = newElement;
    count++;
}

// Сортировка

void Keeper::sort_trains_by_number() {
    if (count < 2) return;

    for (Element* i = head; i != nullptr; i = i->next) {
        for (Element* j = head; j->next != nullptr; j = j->next) {
            if (j->data->getNumber() > j->next->data->getNumber()) {
                Route* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

// поиск элемента
int Keeper::show_element(int n) {

    for (Element* i = head; i != nullptr; i = i->next) {
        if (i->data->getNumber() == n) {
            i->data->display();
            return 1;
        }
    }
    cout << "Данных нет" << endl;
    return 0;
}