#include "keeper.h"

void display_add_menu();

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
    int add_choice = -1;
    while (add_choice != 0) {
        display_add_menu();
        add_choice = check_input();

        // ���� ��������� ����������
        if (add_choice >= 1 && add_choice <= 3) {
            string name;
            int count;
            string fio;
            int cost;
            cout << "������� �������� �����������: ";
            getline(cin, name);
            cout << "������� ��������� �����������: ";
            getline(cin, fio);
            cout << "������� ����������� �����������: ";
            count = check_input();
            cout << "������� ��������� �����������: ";
            cost = check_input();

            // ���� �������� ����������
            if (add_choice == 1) {
                string producer;	// �������������
                string description;	// ������� ��������
                cout << "������� ������������� �����������: ";
                getline(cin, producer);
                cout << "������� ������� �������� �����������: ";
                getline(cin, description);
                String* instrument = new String(producer, description, name, count, fio, cost);
                add_to_start(instrument);
            }

            // ���� ������� ����������
            else if (add_choice == 2) {
                string type_d;	// ��� ��������
                cout << "������� ��� �������� �����������: ";
                getline(cin, type_d);
                Drum* instrument = new Drum(type_d, name, count, fio, cost);
                add_to_start(instrument);
            }

            // ���� ������� ���������� 
            else {
                string producer;		// �������������
                string defects;			// �������
                cout << "������� ������������� �����������: ";
                getline(cin, producer);
                cout << "������� ������� �����������: ";
                getline(cin, defects);
                Brass* instrument = new Brass(producer, defects, name, count, fio, cost);
                add_to_start(instrument);
            }
        }

        // �� �����
        else if (add_choice == 0) {
            break;
        }

        // ��������� ����
        else {
            cout << "������� ���������� ��������" << endl;
            continue;
        }
    }
    return *this;
}

// ���������� � �����
Keeper& operator++(Keeper& K, int) {
    int add_choice = -1;
    while (add_choice != 0) {
        display_add_menu();
        add_choice = check_input();

        // ���� ��������� ����������
        if (add_choice >= 1 && add_choice <= 3) {
            string name;    // ��������
            int count;      // �����
            string fio;     // ��������
            int cost;       // ���������
            cout << "������� �������� �����������: ";
            getline(cin, name);
            cout << "������� ��������� �����������: ";
            getline(cin, fio);
            cout << "������� ����������� �����������: ";
            count = check_input();
            cout << "������� ��������� �����������: ";
            cost = check_input();

            // ���� �������� ����������
            if (add_choice == 1) {
                string producer;	// �������������
                string description;	// ������� ��������
                cout << "������� ������������� �����������: ";
                getline(cin, producer);
                cout << "������� ������� �������� �����������: ";
                getline(cin, description);
                String* instrument = new String(producer, description, name, count, fio, cost);
                K.add(instrument);
            }

            // ���� ������� ����������
            else if (add_choice == 2) {
                string type_d;	// ��� ��������
                cout << "������� ��� �������� �����������: ";
                getline(cin, type_d);
                Drum* instrument = new Drum(type_d, name, count, fio, cost);
                K.add(instrument);
            }

            // ���� ������� ���������� 
            else {
                string producer;		// �������������
                string defects;			// �������
                cout << "������� ������������� �����������: ";
                getline(cin, producer);
                cout << "������� ������� �����������: ";
                getline(cin, defects);
                Brass* instrument = new Brass(producer, defects, name, count, fio, cost);
                K.add(instrument);
            }
        }

        // �� �����
        else if (add_choice == 0) {
            break;
        }

        // ��������� ����
        else {
            cout << "������� ���������� ��������" << endl;
            continue;
        }
    }
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

// �������� � �����
Keeper& Keeper::operator--(int) {
    if (this->count == 0) {
        cout << "������ ���. ���������� ������� � �����" << endl;
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
    if (n < 1 || n > count) {
        cout << "������������ ������ ��������" << endl;
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

// ��������� ���������� ����������� ��������
Keeper& Keeper::edit_element(int n) {
    if (n < 1 || n > count) {
        cout << "������������ ������ ��������" << endl;
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
            cerr << "����������� ��� �������: " << marker << endl;
            continue;
        }

        if (mover) {
            mover->load_from_file(in);
            cout << "������ �������� � ���������" << endl;
            this->add(mover);
        }
    }

    in.close();
}

// ���������� �������� � ������
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

// ���������� �������� � ������
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

// ���������� ��������
void display_add_menu() {
    cout << "\n--- �������� ���������� ---" << endl;
    cout << "1 - �������� " << endl;
    cout << "2 - �������" << endl;
    cout << "3 - �������" << endl;
    cout << "0 - �����" << endl;
    cout << "�������� ��������: ";
}