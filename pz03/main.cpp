#include "pz03.h"
#include <iostream>

using namespace task3;
using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
   while (true) {       //Меню выбора действий
       cout << "Выберите дествие:" << endl;
       cout << "1. Копирование текстовых файлов" << endl << "2. Суммирование положительных чисел с плавающей точкой из файла" << endl << "3. Шифрование файла" << endl << "4. Выход из программы" << endl;
        int x;
        cin >> x;
        switch (x) {
            case (1) :      //Копирование файла
                char finame[50];
                printf("Введите название вводного файла \n");
                scanf("%s", finame);
                char finame2[50];
                printf("Введите название выводного файла \n");
                scanf("%s", finame2);
                cout << copier(finame, finame2) -1 <<" строк скопировано."<< endl;
                continue;
            case (2):       //Сумматор чисел с плавающей запятой
                char fname[50];
                printf("Введите название вводного файла \n");
                scanf("%s", fname);
                cout <<"Сумма чисел: "<< summ(fname)<<endl;
                continue;
            case (3) :      //Шифратор XOR
                char filename[50];
                printf("Введите название вводного файла \n");
                scanf("%s", filename);
                char filename2[50];
                printf("Введите название выводного файла \n");
                scanf("%s", filename2);
                char code[100];
                printf("Введите ключ шифрования \n");
                scanf("%s", code);
                cout << crypto(filename, filename2, code) <<" байт зашифровано."<<endl;
                continue;
            case (4):       //Выход из программы
                return false;
        }
    }
    return 0;
}