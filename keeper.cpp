#include "keeper.h"

void display_add_menu();

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
    int add_choice = -1;
    while (add_choice != 0) {
        display_add_menu();
        add_choice = check_input();

        // если добавляем инструмент
        if (add_choice >= 1 && add_choice <= 3) {
            string name;
            int count;
            string fio;
            int cost;
            cout << "Введите название инструмента: ";
            getline(cin, name);
            cout << "Введите владельца инструмента: ";
            getline(cin, fio);
            cout << "Введите колличество инструмента: ";
            count = check_input();
            cout << "Введите стоимость инструмента: ";
            cost = check_input();

            // если струнный инструмент
            if (add_choice == 1) {
                string producer;	// производитель
                string description;	// краткое описание
                cout << "Введите производителя инструмента: ";
                getline(cin, producer);
                cout << "Введите краткое описание инструмента: ";
                getline(cin, description);
                String* instrument = new String(producer, description, name, count, fio, cost);
                add_to_start(instrument);
            }

            // если ударный инструмент
            else if (add_choice == 2) {
                string type_d;	// тип барабана
                cout << "Введите тип ударного инструмента: ";
                getline(cin, type_d);
                Drum* instrument = new Drum(type_d, name, count, fio, cost);
                add_to_start(instrument);
            }

            // если духовой инструмент 
            else {
                string producer;		// производитель
                string defects;			// дефекты
                cout << "Введите производителя инструмента: ";
                getline(cin, producer);
                cout << "Введите дефекты инструмента: ";
                getline(cin, defects);
                Brass* instrument = new Brass(producer, defects, name, count, fio, cost);
                add_to_start(instrument);
            }
        }

        // на выход
        else if (add_choice == 0) {
            break;
        }

        // ошибочный ввод
        else {
            cout << "Введите корректное значение" << endl;
            continue;
        }
    }
    return *this;
}

// добавление в конец
Keeper& operator++(Keeper& K, int) {
    int add_choice = -1;
    while (add_choice != 0) {
        display_add_menu();
        add_choice = check_input();

        // если добавляем инструмент
        if (add_choice >= 1 && add_choice <= 3) {
            string name;    // название
            int count;      // число
            string fio;     // владелец
            int cost;       // стоимость
            cout << "Введите название инструмента: ";
            getline(cin, name);
            cout << "Введите владельца инструмента: ";
            getline(cin, fio);
            cout << "Введите колличество инструмента: ";
            count = check_input();
            cout << "Введите стоимость инструмента: ";
            cost = check_input();

            // если струнный инструмент
            if (add_choice == 1) {
                string producer;	// производитель
                string description;	// краткое описание
                cout << "Введите производителя инструмента: ";
                getline(cin, producer);
                cout << "Введите краткое описание инструмента: ";
                getline(cin, description);
                String* instrument = new String(producer, description, name, count, fio, cost);
                K.add(instrument);
            }

            // если ударный инструмент
            else if (add_choice == 2) {
                string type_d;	// тип барабана
                cout << "Введите тип ударного инструмента: ";
                getline(cin, type_d);
                Drum* instrument = new Drum(type_d, name, count, fio, cost);
                K.add(instrument);
            }

            // если духовой инструмент 
            else {
                string producer;		// производитель
                string defects;			// дефекты
                cout << "Введите производителя инструмента: ";
                getline(cin, producer);
                cout << "Введите дефекты инструмента: ";
                getline(cin, defects);
                Brass* instrument = new Brass(producer, defects, name, count, fio, cost);
                K.add(instrument);
            }
        }

        // на выход
        else if (add_choice == 0) {
            break;
        }

        // ошибочный ввод
        else {
            cout << "Введите корректное значение" << endl;
            continue;
        }
    }
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

// удаление в конец
Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "Данных нет. Невозможно удалить с конца" << endl;
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
    if (n < 1 || n > count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }

    if (n == 1) {
        this->operator--(0);
        return *this;
    }

    Element* temp = head;
    for (int i = 1; i < n - 1; i++) {
        temp = temp->next;
    }

    Element* toDelete = temp->next;
    temp->next = toDelete->next;

    if (toDelete == tail) {
        tail = temp;
    }

    delete toDelete->data;
    delete toDelete;
    count--;

    return *this;
}

// изменение информации конкретного элемента
Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "Неправильный индекс элемента" << endl;
        return *this;
    }

    Element* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }

    if (temp->data) {
        temp->data->change_info();
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

        Orchestra* mover = nullptr;


        if (marker == "String") {
            mover = new String();
        }
        else if (marker == "Drum") {
            mover = new Drum();
        }
        else if (marker == "Brass") {
            mover = new Brass();
        }
        else {
            cerr << "Неизвестный тип объекта: " << marker << endl;
            continue;
        }

        if (mover) {
            mover->load_from_file(in);
            cout << "Объект добавлен в контейнер" << endl;
            this->add(mover);
        }
    }

    in.close();
}

// добавление элемента в список
void Keeper::add(Orchestra* mover) {
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
void Keeper::add_to_start(Orchestra* mover) {
    Element* newElement = new Element;
    newElement->data = mover;
    newElement->next = head;

    if (head == nullptr) {
        tail = newElement;
    }

    head = newElement;
    count++;
}

// добавление элемента
void display_add_menu() {
    cout << "\n--- Добавить инструмент ---" << endl;
    cout << "1 - Струнный " << endl;
    cout << "2 - Ударный" << endl;
    cout << "3 - Духовой" << endl;
    cout << "0 - Назад" << endl;
    cout << "Выберите действие: ";
}