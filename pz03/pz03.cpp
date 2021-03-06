#include "pz03.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

namespace task3 {
   // string path="/home/user/timp/pz03/data/";
    int copier(char *mas, char *mas2) {
        int k = 0;                      //Выводное знаение: кол-во скопированных строк
        string line;                    //Пустая строка, считывающая строчки входного файла
        ifstream fin(mas);
        char ch;
        if(!fin){
            return -2;                  //-2, если не существует
        }
        else {
            if(fin.peek()==EOF){
                return -1;               //-1, если пустой
            }
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
    }
    double summ(char* mas) {
        double k = 0;                   //Выводное значение: сумма чисел
        string line = "";
        fstream temp;
        char ch;
        temp.open(mas, fstream::in);
        if(!temp){
            return -2;                  //-2, если не существует
        }
        else {
            if (temp.peek() == EOF) {
                return -1;              //-1, если пустой
            }
            temp.close();
            string st = "";                 //Строка 1
            string s = "";                  //Строка 2
            temp.open(mas, fstream::in);
            while (getline(temp, line)) {   //Помещение всех чисел файла построчно в строку 1
                replace(line.begin(), line.end(), ',', '.');
                st += line;
                st += " ";
            }
            temp.close();
            temp.open(mas, fstream::out | fstream::trunc);
            temp << st;                     //Перезаписывание файла: строка 1
            temp.close();
            temp.open(mas, fstream::in);
            while (getline(temp, line)) {   //Помещение всех чисел файла построчно с переносом строки в строку 2
                replace(line.begin(), line.end(), ' ', '\n');
                s += line;
            }
            temp.close();
            temp.open(mas, fstream::out | fstream::trunc);
            temp << s;                      //Перезаписывание файла: строка 2
            temp.close();
            temp.open(mas, fstream::in);
            while (getline(temp, line)) {   //Суммирование чисел
                double d = strtod(line.c_str(), NULL);

                k += d;
            }
            temp.close();
            return k;
        }
    }
    int crypto(char* mas, char* mas2, char *mas3) {
        int k = 0;                      //Выводное значение: число байт
        ifstream fin(mas);
        char ch;
        if(!fin){
            return -2;                  //-2, если не существует
        }
        else {
            if (fin.peek() == EOF) {
                return -1;              //-1, если пустой
            }
            ofstream fout(mas2, ios::trunc);
            string line;
            while (getline(fin, line)) {
                int f = 0;
                for (int i = 0; i < line.length(); i++) {
                    if (f > strlen(mas3)) f = 0;
                    char l;
                    l = line[i] ^ mas3[f];  //Шифрование XOR
                    f++;
                    fout << l;
                    k++;
                }
                fout << '\n';
            }
            fin.close();
            fout.close();
            return k;
        }
    }
}
