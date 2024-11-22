#include "check.h"
#include "keeper.h"
#include <stdexcept>

void display_main_menu() {
    //system("cls");
    cout << "\n-- - Главное меню-- - " << endl;
    cout << "Все добавления и удаления элементов сопровождаются последующей сортировкой. \n " << endl;
    cout << "1 - Добавить новый маршрут в конец" << endl;
    cout << "2 - Добавить новый маршрут в начало" << endl;
    cout << "3 - Удалить маршрут по номеру" << endl;
    cout << "4 - Удалить маршрут c конца" << endl;
    cout << "5 - Удалить маршрут c начала" << endl;
    cout << "6 - Редактировать маршрут" << endl;
    cout << "7 - Отобразить список маршрутов" << endl;
    cout << "8 - Сохранить данные в файл" << endl;
    cout << "9 - Загрузить данные из файла" << endl;
    cout << "10 - Отобразить маршрут по номеру" << endl;
    cout << "0 - Выход" << endl;
    cout << "Выберите действие: ";
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
                cout << "Введите номер маршрута для удаления: ";
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
                cout << "Введите номер маршрута для редактирования: ";
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
                    cerr << "Ошибка при сохранении файла: " << e.what() << endl;
                }
                break;
            }
            case 9: {
                try {
                    keeper.load_from_file("in.txt");
                }
                catch (const runtime_error& e) {
                    cerr << "Ошибка при загрузке файла: " << e.what() << endl;
                }
                break;
            }
            case 10: {
                cout << "Введите номер маршрута для отображения: ";
                int index = check_input();
                keeper.show_element(index);
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
            }
        }
        catch (const invalid_argument& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
        catch (...) {
            cerr << "Неизвестная ошибка!" << endl;
        }
    }

    return 0;
}