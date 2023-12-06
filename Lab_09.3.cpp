#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

// ДЛЯ СЛУЖБОВЦІВ
struct Employee {
    string name;
    string phoneNumber;
};

// ДЛЯ ПРЕМІЩЕННЯ
struct Room {
    string phoneNumber;
    Employee employees[4]; 
};




// ДОДАВАННЯ ==========================================================================================================
void addEntry(Room directory[], int roomIndex, string phoneNumber, string employeeNames) {
    directory[roomIndex].phoneNumber = phoneNumber;

    size_t pos = 0;
    string token;
    int employeeCount = 0;
    while ((pos = employeeNames.find(',')) != string::npos) {
        token = employeeNames.substr(0, pos);
        directory[roomIndex].employees[employeeCount].name = token;
        directory[roomIndex].employees[employeeCount].phoneNumber = phoneNumber;
        employeeNames.erase(0, pos + 1);
        employeeCount++;
    }

    directory[roomIndex].employees[employeeCount].name = employeeNames;
    directory[roomIndex].employees[employeeCount].phoneNumber = phoneNumber;
}




// ВИДАЛЕННЯ ==========================================================================================================
void deleteEntry(Room directory[], int roomIndex) {
    directory[roomIndex].phoneNumber = "";
    for (int i = 0; i < 4; ++i) {
        directory[roomIndex].employees[i].name = "";
        directory[roomIndex].employees[i].phoneNumber = "";
    }
}



// ОНОВЛЕННЯ ==========================================================================================================

void updateEntry(Room directory[], int roomIndex, string phoneNumber, string employeeNames) {
    if (directory[roomIndex].phoneNumber == "") {
        cout << "Кімната не існує. Використовуйте функцію додавання." << endl;
        return;
    }

    // Очистити поточні дані
    directory[roomIndex].phoneNumber = "";
    for (int i = 0; i < 4; ++i) {
        directory[roomIndex].employees[i].name = "";
        directory[roomIndex].employees[i].phoneNumber = "";
    }

    // Додати нові дані
    addEntry(directory, roomIndex, phoneNumber, employeeNames);
}





// ІНФОРМАЦІЯ ЗА НОМЕРОМ ТЕЛЕФОНА =====================================================================================
void getInfoByPhoneNumber(Room directory[], string phoneNumber) {
    for (int i = 0; i < 100; ++i) {
        if (directory[i].phoneNumber == phoneNumber) {
            cout << "Кімната: " << i + 1 << "\nСлужбовці: ";
            for (int j = 0; j < 4; ++j) {
                if (!directory[i].employees[j].name.empty()) {
                    cout << directory[i].employees[j].name << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    cout << "Телефонний номер не знайдено." << endl;
}





// ОТРИМАННЯ НОМЕРА ТЕЛЕФОНУ ЗА НОМЕРОМ КІМНАТИ =======================================================================
void getPhoneNumberByRoom(Room directory[], int roomIndex) {
    if (directory[roomIndex].phoneNumber != "") {
        cout << "Номер телефону: " << directory[roomIndex].phoneNumber << endl;
    }
    else {
        cout << "Кімнату не зайдено." << endl;
    }
}




// ОТРИМАННЯ ІНФОРМАЦІЇ ЗА ПРІЗВИЩЕМ =======================================================================
void getInfoByEmployeeName(Room directory[], string employeeName) {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (directory[i].employees[j].name == employeeName) {
                cout << "Номер телефону: " << directory[i].employees[j].phoneNumber << "\nКімната: " << i + 1 << endl;
                return;
            }
        }
    }
    cout << "Службовця не знайдено." << endl;
}




// ВИВІД ТАБЛИЦІ ============================================================================================
void displayTable(Room directory[]) {
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "|   Кімната   | Номер телефону |         Службовці         |" << endl;
    cout << "------------------------------------------------------" << endl;

    for (int i = 0; i < 100; ++i) {
        if (directory[i].phoneNumber != "") {
            cout << "|" << setw(13) << right << i + 1 << " ";
            cout << "|" << setw(15) << left << directory[i].phoneNumber;
            cout << "|" << setw(15);

            for (int j = 0; j < 4; ++j) {
                if (!directory[i].employees[j].name.empty()) {
                    cout << directory[i].employees[j].name << " ";
                }
            }

            cout << setw(2) << "|" << endl;
        }
    }
    cout << "------------------------------------------------------" << endl;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Room directory[100]; 

    while (true) {
        cout << endl;
        cout << "1. Додати\n2. Вилучити\n3. Оновити\n4. Отримайте інформацію за номером телефону\n5. Отримайте номер телефону за номером\n6. Отримати інформацію за іменем працівника\n7. Вивести усю інформацію\n8. Вихід\n" << endl;
        int choice;

        // Здійснення команд користувачем
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Введіть номер кімнати (1-100): ";
            int roomIndex;
            cin >> roomIndex;

            if (roomIndex < 1 || roomIndex > 100) {
                cout << "Недійсний номер кімнати. Будь ласка, введіть число від 1 до 100." << endl;
                break;
            }

            cout << "Введіть номер телефону: ";
            string phoneNumber;
            cin >> phoneNumber;
            if (phoneNumber.length() != 2) {
                cout << "Довжина номеру повинна містити дві цифри" << endl;
                break;
            }

            cout << "Введіть імена співробітників (через кому): ";
            string employeeNames;
            cin.ignore();
            getline(cin, employeeNames);
            addEntry(directory, roomIndex - 1, phoneNumber, employeeNames);
            break;
        }
        case 2: {
            cout << "Введіть номер кімнати для вилучення: ";
            int roomIndex;
            cin >> roomIndex;

            if (roomIndex < 1 || roomIndex > 100) {
                cout << "Недійсний номер кімнати. Будь ласка, введіть число від 1 до 100." << endl;
                break;
            }

            deleteEntry(directory, roomIndex - 1);
            break;
        }
        case 3: {
            cout << "Введіть номер кімнати для оновлення: ";
            int roomIndex;
            cin >> roomIndex;

            if (roomIndex < 1 || roomIndex > 100) {
                cout << "Недійсний номер кімнати. Будь ласка, введіть число від 1 до 100." << endl;
                break;
            }

            cout << "Введіть новий номер телефону: ";
            string phoneNumber;
            cin >> phoneNumber;
            if (phoneNumber.length() != 2) {
                cout << "Довжина номеру повинна містити дві цифри" << endl;
                break;
            }

            cout << "Введіть нові імена співробітників (через кому): ";
            string employeeNames;
            cin.ignore();
            getline(cin, employeeNames);
            updateEntry(directory, roomIndex - 1, phoneNumber, employeeNames);
            break;
        }
        case 4: {
            cout << "Введіть номер телефону: ";
            string phoneNumber;
            cin >> phoneNumber;
            if (phoneNumber.length() != 2) {
                cout << "Довжина номеру повинна містити дві цифри" << endl;
                break;
            }
            getInfoByPhoneNumber(directory, phoneNumber);
            break;
        }
        case 5: {
            cout << "Введіть номер кімнати: ";
            int roomIndex;
            cin >> roomIndex;
            getPhoneNumberByRoom(directory, roomIndex - 1);
            break;
        }
        case 6: {
            cout << "Введіть ім'я службовця: ";
            string employeeName;
            cin.ignore();
            getline(cin, employeeName);
            getInfoByEmployeeName(directory, employeeName);
            break;
        }
        case 7: {
            displayTable(directory);
            break;
        }
        case 8:
            return 0;
        default:
            cout << "Невірний вибір. Будь ласка, введіть число від 1 до 8." << endl;
        }
    }

    return 0;
}
