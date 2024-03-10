#include <iostream>
#include <fstream>
#include <algorithm>
#include "string"

using namespace std;



struct Student {
    string fullName;
    char gender;
    char status;
    int group;
    int groupNum;
    int marks[8];
    float average = 0;
    string universityFrom = "LETI";
    string theme = "";
};



struct Guest {
    string fullName;
    char status;
    char scientificsDegree;
    string universityFrom;
    string theme = "";
    string city = "Saint-Petersburg";
};

void createGuest(Guest guestMas[], int* pGuestNum) {
    Guest guest;
    cout << "ФИО гостя: ";
    getline(cin, guest.fullName);
    cout << endl;
    cout << "Статус гостя на конференции(A/L): ";
    cin >> guest.status;
    cout << endl;
    cout << "Научная степень(D/C): ";
    cin >> guest.scientificsDegree;
    cout << endl;
    cin.ignore();
    cout << "Университет гостя: ";
    getline(cin, guest.universityFrom);
    cout << endl;
    if (guest.status == 'A') {
        cout << "Тема выступления: ";
        getline(cin, guest.theme);
        cout << endl;
    }
    cout << "Город гостя: ";
    getline(cin, guest.city);
    cout << endl;

    guestMas[*pGuestNum] = guest;
    *pGuestNum += 1;
}

void createStudent(Student mas[], int groupMas[], const int size, int* p, int* pGroup, int groupNum[], int* pGroupNum) {
    Student student;
    cout << "ФИО студента: ";
    getline(cin, student.fullName);
    cout << endl;
    cout << "Пол студента(M/W): ";
    cin >> student.gender;
    cout << endl;
    cout << "Статус на конференции(A/L): ";
    cin >> student.status;
    cout << endl;
    cout << "Группа студента: ";
    cin >> student.group;
    cout << endl;
    cout << "Номер студента в группе: ";
    cin >> student.groupNum;
    cout << endl;
    cout << "Оценки: ";

    float sum = 0;

    for (int i = 0; i < 8; i++) {
        cin >> student.marks[i];
        sum += student.marks[i];
    }

    student.average = sum / 8;

    cout << endl;
    cout << "Университет: ";
    cin >> student.universityFrom;
    cout << endl;

    cin.ignore();

    if (student.status == 'A') {
        cout << "Тема выступления: ";
        getline(cin, student.theme);
        cout << endl;
    }

    if (!(count(groupMas, groupMas + size, student.group) > 0 && (count(groupNum, groupNum + size, student.groupNum) > 0))) {
        if (!(count(groupMas, groupMas + size, student.group) > 0)) {
            groupMas[*pGroup] = student.group;
            *pGroup += 1;
        }
        if (!(count(groupNum, groupNum + size, student.groupNum) > 0)) {
            groupNum[*pGroupNum] = student.groupNum;
            *pGroupNum += 1;
        }
        mas[*p] = student;
        *p += 1;
        cout << "\n\nСтудент сохранен\n";
    }
    else {
        cout << "\n\nСтудент с таким номером в группе уже существует\n";
    }


    system("pause");
    system("cls");
}

void changeStud(Student mas[], int choise, int studChoise, int groupMas[], int* pGroupMas, const int size, int groupNumMas[], int* pGroupNumMas) {
    switch (choise) {
    case(1):
        cout << "\n\nФио студента №" << studChoise << ": ";
        cin >> mas[studChoise - 1].fullName;
        cout << "\n\nИзменение применено\n";
        system("pause");
        system("cls");
        break;
    case(2):
        cout << "\n\nПол студента №" << studChoise << ": ";
        cin >> mas[studChoise - 1].gender;
        cout << "\n\nИзменение применено\n";
        system("pause");
        system("cls");
        break;
    case(3):
        cout << "\n\nГруппа студента №" << studChoise << ": ";
        cin >> mas[studChoise - 1].group;
        if (!(count(groupMas, groupMas + size, mas[studChoise - 1].group) > 0)) {
            groupMas[*pGroupMas] = mas[studChoise - 1].group;
            *pGroupMas += 1;
        }
        cout << "\n\nИзменение применено\n";
        system("pause");
        system("cls");
        break;
    case(4):
        cout << "\n\nНомер в группе студента №" << studChoise << ": ";
        cin >> mas[studChoise - 1].groupNum;
        if (!count(groupNumMas, groupNumMas + size, mas[studChoise - 1].groupNum) > 0) {
            groupNumMas[*pGroupNumMas] = mas[studChoise - 1].groupNum;
            *pGroupNumMas += 1;
        }
        cout << "\n\nИзменение применено\n";
        system("pause");
        system("cls");
        break;
    case(5):
        cout << "\n\nОценки студента №" << studChoise << ": ";
        for (int i = 0; i < 8; i++) {
            cin >> mas[studChoise - 1].marks[i];
        }
        cout << "\n\nИзменение применено\n";
        system("pause");
        system("cls");
        break;
    }
}

void studList(Student mas[], int* p) {
    for (int i = 0; i < *p; i++) {
        cout << "ФИО: " << mas[i].fullName << endl;
        cout << "Пол: " << mas[i].gender << endl;
        cout << "Группа: " << mas[i].group << endl;
        cout << "Номер студента в группе: " << mas[i].groupNum << endl;
        cout << "Оценки: ";
        for (int j = 0; j < 8; j++) {
            cout << mas[i].marks[j] << " ";
        }
        cout << endl << endl;
    }
    system("pause");
    system("cls");
}

void showGroup(int groupMas[], int groupNumber, int group, int studNumber, Student mas[]) {
    if (!count(groupMas, groupMas + groupNumber, group)) {
        cout << "Группа не найдена\n";
    }
    else {
        for (int i = 0; i < studNumber; i++) {
            if (mas[i].group == group) {
                cout << "ФИО: " << mas[i].fullName << endl;
                cout << "Пол: " << mas[i].gender << endl;
                cout << "Группа: " << mas[i].group << endl;
                cout << "Номер студента в группе: " << mas[i].groupNum << endl;
                cout << "Оценки: ";
                for (int j = 0; j < 8; j++) {
                    cout << mas[i].marks[j] << " ";
                }
                cout << endl << endl;
            }
        }
    }
}

void peopleCount(int studNumber, Student mas[]) {
    int countM = 0, countW = 0;
    for (int i = 0; i < studNumber; i++) {
        if (mas[i].gender == 'M') {
            countM += 1;
        }
        else {
            countW += 1;
        }
    }
    cout << "Студенты мужского пола: " << countM << "\n\nСтуденты женского пола: " << countW << endl << endl;
}

void richPeople(int studNumber, Student mas[]) {
    int s = 0, noMoney = 0, haveMoney = 0, haveMuchMoney = 0;
    for (int i = 0; i < studNumber; i++) {
        for (int j = 0; j < 8; j++) {
            s += mas[i].marks[j];
        }
        if (count(mas[i].marks, mas[i].marks + 8, 3) > 0) {
            noMoney += 1;
        }
        if (count(mas[i].marks, mas[i].marks + 8, 3) <= 0 && count(mas[i].marks, mas[i].marks + 8, 4) > 0) {
            haveMoney += 1;
        }
        if (count(mas[i].marks, mas[i].marks + 8, 3) <= 0 && count(mas[i].marks, mas[i].marks + 8, 4) <= 0 && count(mas[i].marks, mas[i].marks + 8, 5) > 0) {
            haveMuchMoney += 1;
        }
    }
    cout << "Студенты, не получающие стипендию: " << noMoney << "\n\nСтуденты, которые учатся на 'хорошо' и 'отлично': " << haveMoney << "\n\nСтуденты, которые учатся на 'отлично': " << haveMuchMoney << endl << endl;
}

bool compareByGrade(const Student& a, const Student& b) {
    return a.average > b.average;
}

int main()
{
    short int end = 1;
    const int size = 30;
    Student mas[size];

    const int guestSize = 100;
    Guest guestMas[size];

    int studNumber = 0;
    int* p = &studNumber;

    int guestNumber = 0;
    int* pGuest = &guestNumber;

    int groupMas[size] = {};
    int groupNumber = 0;
    int* pGroup = &groupNumber;

    int groupNumMas[size] = {};
    int groupNumNumber = 0;
    int* pGroupNum = &groupNumNumber;

    setlocale(LC_ALL, "RU");
    
    while (end) {
        cout << "ВСЕ ЗАПИСИ ДОЛЖНЫ БЫТЬ НА АНГЛИЙСКОМ ЯЗЫКЕ\n\n"
            "[1] Создание записи о студенте\n"
            "[2] Внесение изменений в уже имеющуюся запись\n"
            "[3] Список студентов\n"
            "[4] Вывод информации обо всех студентах группы\n"
            "[5] Вывод топа самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию\n"
            "[6] Вывод количества студентов мужского и женского пола\n"
            "[7] Вывод данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»\n"
            "[8] Вывод данных о студентах, имеющих номер в списке\n"
            "[9] Создание записи о госте\n"
            "[10] ИДЗ\n"
            "[0] Выход\n"
            "Команда: ";
        cin >> end;
        switch (end) {
        case(1):
            system("cls");
            cin.ignore();
            createStudent(mas, groupMas, size, p, pGroup, groupNumMas, pGroupNum);
            break;
        case(2):
            if (studNumber == 0) {
                system("cls");
                cout << "Студентов нет\n";
                system("pause");
                system("cls");
            }
            else {
                int choise;
                int studChoise;
                system("cls");
                cout << "Количество студентов: " << studNumber << endl << endl << "Выберите студента: ";
                cin >> studChoise;
                cout << "\nВыберите информацию для изменения:\n"
                    "[1]ФИО\n"
                    "[2]Пол\n"
                    "[3]Номер группы\n"
                    "[4]Номер в списке группы\n"
                    "[5]Оценки\n\n"
                    "Команда: ";
                cin >> choise;
                changeStud(mas, choise, studChoise, groupMas, pGroup, size, groupNumMas, pGroupNum);
            }
            break;
        case(3):
            system("cls");
            studList(mas, p);
            break;
        case(4):
            system("cls");
            if (studNumber == 0) {
                cout << "Студентов нет\n";
            }
            else {
                int group;
                cout << "Введите группу: ";
                cin >> group;
                cout << endl;
                showGroup(groupMas, groupNumber, group, studNumber, mas);
            }
            system("pause");
            system("cls");
            break;
        case(5):
            system("cls");
            if (studNumber < 3) {
                cout << "Студентов нет/недостаточно\n";
            }
            else {
                sort(mas, mas + size, compareByGrade);
                cout << "ТОП 3 СТУДЕНТОВ:\n";
                cout << "1. " << mas[studNumber - 1].fullName << ": " << mas[studNumber - 3].average << endl;
                cout << "2. " << mas[studNumber - 2].fullName << ": " << mas[studNumber - 2].average << endl;
                cout << "3. " << mas[studNumber - 3].fullName << ": " << mas[studNumber - 1].average << endl;
            }
            system("pause");
            system("cls");
            break;
        case(6):
            system("cls");
            if (studNumber == 0) {
                cout << "Студентов нет\n";
            }
            else {
                peopleCount(studNumber, mas);
            }
            system("pause");
            system("cls");
            break;
        case(7):
            system("cls");
            if (studNumber == 0) {
                cout << "Студентов нет\n";
            }
            else {
                richPeople(studNumber, mas);
            }
            system("pause");
            system("cls");
            break;
        case(8):
            system("cls");
            if (studNumber == 0) {
                cout << "Студентов нет\n";
            }
            else {
                int k, prov = 0;
                cout << "Введите номер студента: ";
                cin >> k;
                cout << endl << endl;
                for (int i = 0; i < studNumber; i++) {
                    if (mas[i].groupNum == k) {
                        prov += 1;
                        cout << "ФИО: " << mas[i].fullName << endl;
                        cout << "Пол: " << mas[i].gender << endl;
                        cout << "Группа: " << mas[i].group << endl;
                        cout << "Номер студента в группе: " << mas[i].groupNum << endl;
                        cout << "Оценки: ";
                        for (int j = 0; j < 8; j++) {
                            cout << mas[i].marks[j] << " ";
                        }
                        cout << endl << endl;
                    }
                }
                if (prov == 0) {
                    cout << "Студента с этим номером нет\n";
                }
            }
            system("pause");
            system("cls");
            break;
        case(9):
            system("cls");
            cin.ignore();
            createGuest(guestMas, pGuest);
            system("pause");
            system("cls");
            break;
        case(10):
            system("cls");
            cout << "ВЫСТУПАЮЩИЕ НА КОНФЕРЕНЦИИ: \n\n";
            for (int i = 0; i < studNumber; i++) {
                if (mas[i].status == 'A') {
                    cout << "ФИО: " << mas[i].fullName << endl;
                    cout << "Пол: " << mas[i].gender << endl;
                    cout << "Группа: " << mas[i].group << endl;
                    cout << "Номер студента в группе: " << mas[i].groupNum << endl;
                    cout << "Тема выступления: " << mas[i].theme << endl;
                    cout << endl << endl;
                }
            }

            for (int i = 0; i < guestNumber; i++) {
                if (guestMas[i].status == 'A') {
                    cout << "ФИО: " << guestMas[i].fullName << endl;
                    cout << "Статус: " << guestMas[i].status << endl;
                    cout << "Ученая степень: " << guestMas[i].scientificsDegree << endl;
                    cout << "Университет: " << guestMas[i].universityFrom << endl;
                    cout << "Тема выступления: " << guestMas[i].theme << endl;
                    cout << endl << endl;
                }
            }

            cout << "ИНОГОРОДНИЕ НА КОНФЕРЕНЦИИ: \n\n";

            for (int i = 0; i < guestNumber; i++) {
                if (!(guestMas[i].city == "Saint=Petersburg")) {
                    cout << "ФИО: " << guestMas[i].fullName << endl;
                    cout << "Статус: " << guestMas[i].status << endl;
                    cout << "Ученая степень: " << guestMas[i].scientificsDegree << endl;
                    cout << "Университет: " << guestMas[i].universityFrom << endl;
                    cout << "Тема выступления: " << guestMas[i].theme << endl;
                    cout << "Город:" << guestMas[i].city << endl;
                    cout << endl << endl;
                }
            }

            cout << "ПРИГЛАШЕННЫЕ СТУДЕНТЫ НА КОНФЕРЕНЦИИ: \n\n";

            for (int i = 0; i < studNumber; i++) {
                if ((mas[i].status == 'A')) {
                    cout << "ФИО: " << mas[i].fullName << endl;
                    cout << "Статус: " << mas[i].status << endl;
                    cout << "Университет: " << mas[i].universityFrom << endl;
                    cout << "Тема выступления: " << mas[i].theme << endl;
                    cout << endl << endl;
                }
            }

            string univ;
            cout << "ВУЗ, В КОТОРОМ ПРОВОДИТСЯ КОНФЕРЕНЦИЯ: ";
            cin.ignore();
            getline(cin, univ);
            cout << endl;

            cout << "СТУДЕНТЫ В ВУЗЕ: ";
            cout << endl;

            for (int i = 0; i < studNumber; i++) {
                if (mas[i].universityFrom == univ) {
                    cout << "ФИО: " << mas[i].fullName << endl;
                    cout << "Пол: " << mas[i].gender << endl;
                    cout << "Группа: " << mas[i].group << endl;
                    cout << "Номер студента в группе: " << mas[i].groupNum << endl;
                    cout << "Тема выступления: " << mas[i].theme << endl;
                    cout << endl << endl;
                }
            }

            for (int i = 0; i < guestNumber; i++) {
                if (guestMas[i].universityFrom == univ) {
                    cout << "ФИО: " << guestMas[i].fullName << endl;
                    cout << "Статус: " << guestMas[i].status << endl;
                    cout << "Ученая степень: " << guestMas[i].scientificsDegree << endl;
                    cout << "Университет: " << guestMas[i].universityFrom << endl;
                    cout << "Тема выступления: " << guestMas[i].theme << endl;
                    cout << endl << endl;
                }
            }

            system("pause");
            system("cls");
            break;
        }
    }
}

