// Project_reichstag.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "modul.h"
#include <windows.h>
using namespace std;
int main()
{
    jk list; SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename = "MyFile.dat";
    int k=0;
    while (k != 10) {
        cout << "\n1-Створити новий файл\n2-Прочитати з файлу\n3-Дописати у файл\n4-Знайти за кінцевою станцією\n5-Визначити середню швидкість поїздів\n6-Знайти № поїзда за конкретною станцією відправлення\n7-Записи, в яких кінцева і початкові станції співпадають\n8-Знайти потяги, які прибувають в задану станцію одночасно\n9-Впорядкувати записи за початковою станцією у файл.тхт\n10-Закрити\n>>> ";
        cin >> k;
        switch (k)
        {
        case 1:
            create_file(filename, list); break;
        case 2:
            read_file(filename, list); break;
        case 3:
            add_file(filename, list); break;
        case 4:
            searchStation1(filename, list); break;
       case 5:
           
           vvedenyaTimeVidp(filename,list); break;
        case 6:
           
            searchStation2(filename, list);
            break;
        case 7:
            searchStation3(filename, list); break;
        case 8:
            trainsodnochasno(filename); break;
        case 9:
            sortinfile( filename); break;
        case 10: 
            cout << "Exit"; break;
        default:
            cout << "Ви ввели не вірну команду!";
            break;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
