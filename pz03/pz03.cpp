#include "task03.h"
#include <iostream>

using namespace std;

namespace task3 {
    int copier(char *mas, char *mas2) {
        int k = 0;      //Выводное знаение: кол-во скопированных строк
        string line;    //Пустая строка, считывающая строчки входного файла
        ifstream fin(mas);
        ofstream fout(mas2, ios::app);
        while (fin) {
            getline(fin, line);
            fout << line << '\n';
            k++;
        }
        fin.close();
        fout.close();
        return k;
    }
    double summ(char* mas) {
        double k = 0;
        return k;
    }
    int crypto(char* mas, char* mas2, char *mas3) {
        int k = 0;
        return k;
    }
}
