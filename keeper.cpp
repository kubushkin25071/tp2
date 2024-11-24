#include "keeper.h"

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {
    cout << "������ ����������� ��� ���������� ��� Keeper ������\n";
}

Keeper::Keeper(Element* h, Element* t, int c) : head(h), tail(t), count(c) {
    cout << "������ ����������� � ����������� ��� Keeper ������\n";
}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "������ ����������� ����������� ��� Keeper ������\n";
}

Keeper::~Keeper() {
    cout << "������ ���������� ��� Keeper ������\n";
    delete_all();
}

// �������� ������
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

// �������� ����� ����� ������
void Keeper::delete_all() {
    while (head != 0)
        delete_head();

}

// ����� �� ����� �� ���������
void Keeper::display_keeper() {
    Element* temp = head;

    if (count == 0) {
        cout << "������ ���" << endl;
        return;
    }

    int i = 0;
    while (temp != 0) {
        cout << i + 1 << " - ";
        if (temp->data) {
            temp->data->display(); //����� ������� ������ �� ����� � ��������
        }
        else {
            cout << "������ ���";
        }
        cout << " " << endl;;
        temp = temp->next;
        i++;
    }
}

// ��������� ���-��
int Keeper::get_count() {
    return count;
}

// ���������� � ������
Keeper& Keeper::operator++() {
    string first_point;
    string last_point;
    int number;
    while (true) {
        cout << "������� ����� ��������: ";
        number = check_input();
        int flag = show_element(number);
        if (flag == 0) break;
        else {
            cout << "������� � ����� ������� ����������!" << endl;
        }
    }
    cout << "������� ��������� �����: ";
    getline(cin, first_point);
    cout << "������� �������� �����: ";
    getline(cin, last_point);
    Route* train = new Route(number, first_point, last_point);
    add_to_start(train);
    return *this;
}

// ���������� � �����
Keeper& operator++(Keeper& K, int) {

    string first_point;
    string last_point;
    int number;
    while(true){
        cout << "������� ����� ��������: ";
        number = check_input();
        int flag = K.show_element(number);
        if (flag == 0) break;
        else {
            cout << "������� � ����� ������� ����������!" << endl;
        }
    }
    
    cout << "������� ��������� �����: ";
    getline(cin, first_point);
    cout << "������� ��������� �����: ";
    getline(cin, last_point);
    Route* train = new Route(number, first_point, last_point);
    K.add(train);
    return K;
}

// �������� �������
Keeper& operator--(Keeper& K) {
    if (K.count == 0) {
        cout << "������ ���. ���������� ������� � ������" << endl;
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

// �������� � ����e
Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "������ ���." << endl;
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

// �������� ����������� ��������
Keeper& Keeper::delete_element(int n) {

    if (this->count == 0) {
        cout << "������ ���." << endl;
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

// ��������� ���������� ����������� ��������
Keeper& Keeper::edit_element(int n) {

    if (this->count == 0) {
        cout << "������ ���." << endl;
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
        cout << "������ ���" << endl;
    }

    return *this;
}

// ��������� ������
Element* Keeper::get_head() {
    return this->head;
}

// ��������� ������
Element* Keeper::get_tail() {
    return this->tail;
}

// ���������� � ����
void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    Element* current = head;
    while (current != nullptr) {
        current->data->save_to_file(out);   // ������ ������� ����������� ����������� 
        current = current->next;
    }
    out.close();
}

// �������� �� �����
void Keeper::load_from_file(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "������ �������� ����� ��� ��������!" << endl;
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
            cerr << "����������� ��� �������: " << marker << endl;
            continue;
        }

        if (mover) {
            mover->load_from_file(in);
            int res_of_searh = this->show_element(mover->getNumber());
            if (res_of_searh) {
                cout << "������� � ����� ������� ��� ����������!" << endl;
            }
            else {
                this->add(mover);
                cout << "������ �������� � ���������" << endl;
            }
        }
    }

    in.close();
}

// ���������� �������� � ������
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

// ���������� �������� � ������
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

// ����������

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

// ����� ��������
int Keeper::show_element(int n) {

    for (Element* i = head; i != nullptr; i = i->next) {
        if (i->data->getNumber() == n) {
            i->data->display();
            return 1;
        }
    }
    cout << "������ ���" << endl;
    return 0;
}