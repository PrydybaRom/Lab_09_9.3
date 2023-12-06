#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

// ��� �������ֲ�
struct Employee {
    string name;
    string phoneNumber;
};

// ��� ���̲�����
struct Room {
    string phoneNumber;
    Employee employees[4]; 
};




// ��������� ==========================================================================================================
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




// ��������� ==========================================================================================================
void deleteEntry(Room directory[], int roomIndex) {
    directory[roomIndex].phoneNumber = "";
    for (int i = 0; i < 4; ++i) {
        directory[roomIndex].employees[i].name = "";
        directory[roomIndex].employees[i].phoneNumber = "";
    }
}



// ��������� ==========================================================================================================

void updateEntry(Room directory[], int roomIndex, string phoneNumber, string employeeNames) {
    if (directory[roomIndex].phoneNumber == "") {
        cout << "ʳ����� �� ����. �������������� ������� ���������." << endl;
        return;
    }

    // �������� ������ ���
    directory[roomIndex].phoneNumber = "";
    for (int i = 0; i < 4; ++i) {
        directory[roomIndex].employees[i].name = "";
        directory[roomIndex].employees[i].phoneNumber = "";
    }

    // ������ ��� ���
    addEntry(directory, roomIndex, phoneNumber, employeeNames);
}





// �������ֲ� �� ������� �������� =====================================================================================
void getInfoByPhoneNumber(Room directory[], string phoneNumber) {
    for (int i = 0; i < 100; ++i) {
        if (directory[i].phoneNumber == phoneNumber) {
            cout << "ʳ�����: " << i + 1 << "\n���������: ";
            for (int j = 0; j < 4; ++j) {
                if (!directory[i].employees[j].name.empty()) {
                    cout << directory[i].employees[j].name << " ";
                }
            }
            cout << endl;
            return;
        }
    }
    cout << "���������� ����� �� ��������." << endl;
}





// ��������� ������ �������� �� ������� ʲ����� =======================================================================
void getPhoneNumberByRoom(Room directory[], int roomIndex) {
    if (directory[roomIndex].phoneNumber != "") {
        cout << "����� ��������: " << directory[roomIndex].phoneNumber << endl;
    }
    else {
        cout << "ʳ����� �� �������." << endl;
    }
}




// ��������� �������ֲ� �� �в������ =======================================================================
void getInfoByEmployeeName(Room directory[], string employeeName) {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (directory[i].employees[j].name == employeeName) {
                cout << "����� ��������: " << directory[i].employees[j].phoneNumber << "\nʳ�����: " << i + 1 << endl;
                return;
            }
        }
    }
    cout << "��������� �� ��������." << endl;
}




// ��²� �����ֲ ============================================================================================
void displayTable(Room directory[]) {
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "|   ʳ�����   | ����� �������� |         ���������         |" << endl;
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
        cout << "1. ������\n2. ��������\n3. �������\n4. ��������� ���������� �� ������� ��������\n5. ��������� ����� �������� �� �������\n6. �������� ���������� �� ������ ����������\n7. ������� ��� ����������\n8. �����\n" << endl;
        int choice;

        // ��������� ������ ������������
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "������ ����� ������ (1-100): ";
            int roomIndex;
            cin >> roomIndex;

            if (roomIndex < 1 || roomIndex > 100) {
                cout << "�������� ����� ������. ���� �����, ������ ����� �� 1 �� 100." << endl;
                break;
            }

            cout << "������ ����� ��������: ";
            string phoneNumber;
            cin >> phoneNumber;
            if (phoneNumber.length() != 2) {
                cout << "������� ������ ������� ������ �� �����" << endl;
                break;
            }

            cout << "������ ����� ����������� (����� ����): ";
            string employeeNames;
            cin.ignore();
            getline(cin, employeeNames);
            addEntry(directory, roomIndex - 1, phoneNumber, employeeNames);
            break;
        }
        case 2: {
            cout << "������ ����� ������ ��� ���������: ";
            int roomIndex;
            cin >> roomIndex;

            if (roomIndex < 1 || roomIndex > 100) {
                cout << "�������� ����� ������. ���� �����, ������ ����� �� 1 �� 100." << endl;
                break;
            }

            deleteEntry(directory, roomIndex - 1);
            break;
        }
        case 3: {
            cout << "������ ����� ������ ��� ���������: ";
            int roomIndex;
            cin >> roomIndex;

            if (roomIndex < 1 || roomIndex > 100) {
                cout << "�������� ����� ������. ���� �����, ������ ����� �� 1 �� 100." << endl;
                break;
            }

            cout << "������ ����� ����� ��������: ";
            string phoneNumber;
            cin >> phoneNumber;
            if (phoneNumber.length() != 2) {
                cout << "������� ������ ������� ������ �� �����" << endl;
                break;
            }

            cout << "������ ��� ����� ����������� (����� ����): ";
            string employeeNames;
            cin.ignore();
            getline(cin, employeeNames);
            updateEntry(directory, roomIndex - 1, phoneNumber, employeeNames);
            break;
        }
        case 4: {
            cout << "������ ����� ��������: ";
            string phoneNumber;
            cin >> phoneNumber;
            if (phoneNumber.length() != 2) {
                cout << "������� ������ ������� ������ �� �����" << endl;
                break;
            }
            getInfoByPhoneNumber(directory, phoneNumber);
            break;
        }
        case 5: {
            cout << "������ ����� ������: ";
            int roomIndex;
            cin >> roomIndex;
            getPhoneNumberByRoom(directory, roomIndex - 1);
            break;
        }
        case 6: {
            cout << "������ ��'� ���������: ";
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
            cout << "������� ����. ���� �����, ������ ����� �� 1 �� 8." << endl;
        }
    }

    return 0;
}
