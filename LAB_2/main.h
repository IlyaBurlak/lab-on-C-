//
// Created by Илья Бурлак on 27.02.2023.
//
#ifndef LAB_2_MAIN_H
#define LAB_2_MAIN_H

#include <iostream>
#include "main.h"
#include <fstream>

using namespace std;

class File {
public:
    ofstream file;
    string name_f = "";
    void start(){
        int a;
        bool While=true;
        while (While) {
            menu();
            line();
            cin >> a;
            switch (a){
                case 1:
                    open();
                    line();
                    break;
                case 2:
                    line();
                    close();
                    line();
                    break;
                case 3:
                    line();
                    get_name();
                    line();
                    break;
                case 4:
                    line();
                    open_file();
                    line();
                    break;
                case 5:
                    line();
                    write_file();
                    line();
                    break;
                case 6:
                    line();
                    write_numbers();
                    line();
                    break;
                case 0:
                    line();
                    cout << "The program has been closed.\nGood luck!\n";
                    line();
                    While = false;
                    break;
                default:
                    line();
                    cout << "Нет такой команды.\n";
                    line();
                    break;
            }
        }
    };
    void open(){
        cout << "Введите название файла: ";
        cin >> name_f;
        file.open(name_f , ios::app);

    };
    void close(){
        file.close();
    };
    int  open_file(){
        if (!file.is_open()){
            cout << "File closed \n";
            return -1;
        }
        else{
            cout << "File open \n";
            return 1;
        }
    }
    void get_name(){
        if (name_f != "") {
            cout << "Name file: " << name_f << "\n";
        }else{
            cout << "Файл не открыт\n";
        }
    }
    void write_file(){
        string s1;
        cout << "Вводите: ";
        cin >> s1;

        if (file.is_open()){
            file << s1 << endl;
        } else{
            cout << "Файл не открыт !";
        }
    }
    void write_numbers(){
        int kol_n , n;
        if (file.is_open()) {
            cout << "Сколько цифр ? " << "\n";
            cin >> kol_n;
            for (int i = 0; i < kol_n; i++) {
                cin >> n;
                file << n << " ";
            }
            file << "\n";
        }else{
            cout << "Фаил не открыт !";
        }
    }
    void menu(){
        cout <<"Выберите пункт:" << "\n";
        cout << "1 Открытие файла." << "\n";
        cout << "2 Закрытие файла." << "\n";
        cout << "3 Получение имени файла." << "\n";
        cout << "4 Проверка, открыт ли файл." << "\n";
        cout << "5 Запись в файл строки." << "\n";
        cout << "6 Запись в файл целого числа." << "\n";
        cout << "0 Завершение программы." << "\n";
    }

    void line(){
        cout << "--------------------------------\n" ;
    }

};
#endif //LAB_2_MAIN_H
