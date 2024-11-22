#include "check.h"
#include "keeper.h"
#include <stdexcept>

void display_main_menu() {
    //system("cls");
    cout << "\n-- - ������� ����-- - " << endl;
    cout << "��� ���������� � �������� ��������� �������������� ����������� �����������. \n " << endl;
    cout << "1 - �������� ����� ������� � �����" << endl;
    cout << "2 - �������� ����� ������� � ������" << endl;
    cout << "3 - ������� ������� �� ������" << endl;
    cout << "4 - ������� ������� c �����" << endl;
    cout << "5 - ������� ������� c ������" << endl;
    cout << "6 - ������������� �������" << endl;
    cout << "7 - ���������� ������ ���������" << endl;
    cout << "8 - ��������� ������ � ����" << endl;
    cout << "9 - ��������� ������ �� �����" << endl;
    cout << "10 - ���������� ������� �� ������" << endl;
    cout << "0 - �����" << endl;
    cout << "�������� ��������: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Keeper keeper;
    int choice = -1;

    while (choice != 0) {
        try {
            display_main_menu();
            choice = check_input();

            switch (choice) {
            case 1: {
                keeper++;
                keeper.sort_trains_by_number();
                break;
            }
            case 2: {
                ++keeper;
                keeper.sort_trains_by_number();
                break;
            }
            case 3: {
                cout << "������� ����� �������� ��� ��������: ";
                int index = check_input();
                keeper.delete_element(index);
                break;
            }
            case 4: {
                keeper--;
                break;
            }
            case 5: {
                --keeper;
                break;
            }
            case 6: {
                cout << "������� ����� �������� ��� ��������������: ";
                int index = check_input();
                keeper.edit_element(index);
                break;
            }
            case 7:
                keeper.display_keeper();
                break;
            case 8: {
                try {
                    keeper.save_to_file("out.txt");
                }
                catch (const runtime_error& e) {
                    cerr << "������ ��� ���������� �����: " << e.what() << endl;
                }
                break;
            }
            case 9: {
                try {
                    keeper.load_from_file("in.txt");
                }
                catch (const runtime_error& e) {
                    cerr << "������ ��� �������� �����: " << e.what() << endl;
                }
                break;
            }
            case 10: {
                cout << "������� ����� �������� ��� �����������: ";
                int index = check_input();
                keeper.show_element(index);
                break;
            }
            case 0:
                cout << "����� �� ���������." << endl;
                break;
            default:
                cout << "�������� �����! ���������� �����." << endl;
                break;
            }
        }
        catch (const invalid_argument& e) {
            cerr << "������: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cerr << "������: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cerr << "������: " << e.what() << endl;
        }
        catch (...) {
            cerr << "����������� ������!" << endl;
        }
    }

    return 0;
}