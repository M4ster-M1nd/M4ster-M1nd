#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <io.h>
#include <conio.h>
#include <stdio.h>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#define MAX_LEN 9
#define INT_SIZE 4
#define X_POSITION (7 + (i*3)
#define Y_POSITION (6 + (j*2))

using namespace std;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

class Sudoku {
    int i, j;
    int** field;
    int** check_field; //поле, которое запомнит введенные значения
public:
    Sudoku() {
        i = j = 0;
        field = new int* [MAX_LEN];
        check_field = new int* [MAX_LEN];
        for (int i = 0; i < MAX_LEN; ++i) {
            field[i] = new int[MAX_LEN];
            check_field[i] = new int[MAX_LEN];
        }
        for (int i = 0; i < MAX_LEN; ++i) {
            for (int j = 0; j < MAX_LEN; ++j) {
                field[i][j] = 0;
                check_field[i][j] = 0;
            }
        }

    }
    void GotoXY(int X, int Y) {
        if ((X >= 6) && (i <= 34) || ((j >= 5) && (j <= 24))) {
            COORD place = { X, Y };
            SetConsoleCursorPosition(hStdOut, place);
        }
    }
    void SetColor(int text, int background) {
        SetConsoleTextAttribute(hStdOut, background * 16 + text);
    }
    void show() {
        GotoXY(5, 0);
        SetColor(15, 0);
        cout << "Для поиска решений нажмите [Space]. Для возврата в меню нажмите [Esc]";
        cout <<endl<< "Чтобы изменить значение - выберите элемент и нажмите [Enter]";
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j) {

                GotoXY(X_POSITION - 1), Y_POSITION);
                cout << "|";
                GotoXY(X_POSITION), Y_POSITION);
                cout << field[i][j];
                GotoXY(X_POSITION + 1), Y_POSITION);
                cout << "|";
            }
        }
    }
    
    void set_value() {
        int count = 0;
        i = 0, j = 0;
        int f = 1;
        bool flag;
        char key;
        GotoXY(X_POSITION), Y_POSITION);    //
        SetColor(14, 0);                    // выделение желтым похиции курсора
        cout << field[i][j];                //
        GotoXY(X_POSITION), Y_POSITION);    //
        do {
            flag = false;
            key = _getch();

            switch (key) {
            case 32:
                for (i = 0; i < 9; ++i)
                {
                    for (j = 0; j < 9; ++j) {
                        Solve();
                    }
                }
                i = 0; j = 0;
                break;

            case 77:
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(15, 0);            // выделение белым предыдущей позиции курсора
                cout << field[i][j];
                if (i <= 7) {
                    ++i;
                }
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(14, 0);            // выделение желтым
                cout << field[i][j];        //
                GotoXY(X_POSITION), Y_POSITION);
                break;
            case 75:
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(15, 0);            // выделение белым предыдущей позиции курсора
                cout << field[i][j];
                if (i >= 1) {
                    --i;
                }
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(14, 0);            // выделение желтым
                cout << field[i][j];
                GotoXY(X_POSITION), Y_POSITION);
                break;
            case 80:
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(15, 0);            // выделение белым предыдущей позиции курсора
                cout << field[i][j];
                if (j <= 7) {
                    ++j;
                }
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(14, 0);            // выделение желтым
                cout << field[i][j];
                GotoXY(X_POSITION), Y_POSITION);
                break;
            case 72:
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(15, 0);            // выделение белым предыдущей позиции курсора
                cout << field[i][j];
                if (j >= 1) {
                    --j;
                }
                GotoXY(X_POSITION), Y_POSITION);
                SetColor(14, 0);            // выделение желтым
                cout << field[i][j];
                GotoXY(X_POSITION), Y_POSITION);
                break;
            case 13:
                GotoXY(7, 29);
                cout << "               ";
                GotoXY(7, 28);
                cout << "Введите новое значение 0 - 9: ";
                int num;
                cin >> num;
                if (num >= 0 && num <= 9)
                {
                    field[i][j] = num;
                    check_field[i][j] = num;    //Запись в поле сравнения
                    GotoXY(7, 28);
                    cout << "                                    ";
                    GotoXY(X_POSITION), Y_POSITION);
                    SetColor(15, 0);            // выделение белым предыдущей позиции курсора
                    cout << field[i][j];
                    SetColor(14, 0);            // выделение желтым
                    GotoXY(X_POSITION), Y_POSITION);
                    break;
                }
                else
                {
                    GotoXY(7, 29);
                    cout << "Неверное число!";
                    GotoXY(7, 28);
                    cout << "                                    ";
                    GotoXY(X_POSITION), Y_POSITION);
                    SetColor(15, 0);
                    cout << field[i][j];
                    SetColor(14, 0);
                    GotoXY(X_POSITION), Y_POSITION);
                    break;
                }
            case 27:
                flag = true;
                break;

            }
        } while (!flag);
    }

    bool Check_Conflicts(int num, int i, int j) {
        for (int m = 0; m < 9; m++) {//проверка по строке
            if (m != i) {
                if (field[m][j] == num) return false;
            }
        }
        for (int n = 0; n < 9; n++) {//проверка по столбцу
            if (n != i) {
                if (field[i][n] == num) return false;
            }
        }
        if ((i < 3) && (j < 3)) {//проверка по квадранту левый верхний
            for (int m = 0; m < 3; m++) {
                for (int n = 0; n < 3; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i >= 3) && (i < 6) && (j < 3)) {//средний верхний
            for (int m = 3; m < 6; m++) {
                for (int n = 0; n < 3; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i >= 6) && (j < 3)) {//правый верхний
            for (int m = 6; m < 9; m++) {
                for (int n = 0; n < 3; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i < 3) && (j < 6) && (j >= 3)) {//левый средний
            for (int m = 0; m < 3; m++) {
                for (int n = 3; n < 6; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i >= 3) && (i < 6) && (j < 6) && (j >= 3)) {//средний
            for (int m = 3; m < 6; m++) {
                for (int n = 3; n < 6; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i >= 6) && (j < 6) && (j >= 3)) {//правый средний
            for (int m = 6; m < 9; m++) {
                for (int n = 3; n < 6; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i < 3) && (j >= 6)) {//левый нижний
            for (int m = 0; m < 3; m++) {
                for (int n = 6; n < 9; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i >= 3) && (i < 6) && (j >= 6)) {//средний нижний
            for (int m = 3; m < 6; m++) {
                for (int n = 6; n < 9; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        if ((i >= 6) && (j >= 6)) {//правый нижний
            for (int m = 6; m < 9; m++) {
                for (int n = 6; n < 9; n++) {
                    if (field[m][n] == num) return false;
                }
            }
        }
        return true;
    }



    void Solve(int i = 0, int j = 0, int num = 9) 
    {

        if ((num == 0) && (i > 0)) {
            field[i][j] = 0;
            --i;
            Solve(i, j,(field[i][j]-1));
        }
        else if ((num == 0) && (j > 0)) {
            field[i][j] = 0;
            i = 8;
            --j;
            Solve(i, j, (field[i][j] - 1));
        }
        else {//выход из рекурсии есть не нашлось решение
            if ((num == 0) && (i == 0) && (j == 0)) {
                return; //решения нет
            }
        }
        
        while (j != 9) {
            if (!(check_field[i][j])) {         //если клетка не заполнена вручную

                if (Check_Conflicts(num, i, j)) //если проверки пройдены
                {
                    field[i][j] = num;
                    GotoXY(X_POSITION), Y_POSITION);
                    SetColor(15, 0);            // выделение белым предыдущей позиции курсора
                    cout << field[i][j];
                    SetColor(14, 0);            // выделение желтым
                    GotoXY(X_POSITION), Y_POSITION);
                    

                } //если проверки не пройдены
                else if (num > 0) {
                    Solve(i, j, num - 1); //пробуем число на единицу меньшее
                }
                else {
                    field[i][j] = 0; //ставим в это место 0 и возвращаемся назад

                    if (i > 0) {//возврат на строку назад если дошли до нуля и не нашли решения

                        if (!check_field[i - 1][j]) { //если в начальном поле с этими индексами пусто
                            --i;
                            Solve(i, j, (field[i][j] - 1));
                        }
                        else {//если это поле заполнено вручную то пропускаем
                            --i;
                            if (i > 0) {
                                --i;
                                Solve(i, j,(field[i][j]-1)); //продолжить с числа меньше на 1
                            }
                            else {
                                i = 8;
                                --j;
                                Solve(i, j, (field[i][j] - 1)); //продолжить с числа меньше на 1
                            }
                        }
                    }
                    else {
                        if (j > 0) { //возврат на столбец назад если дошли до начала строки и до нуля и не нашли решения
                            i = 8;

                            if (!check_field[i][j - 1]) {//если в начальном поле с этими индексами пусто
                                --j;
                                Solve(i, j, (field[i][j] - 1));//продолжить с числа меньше на 1
                            }
                            else {
                                if (i > 0) {//если это поле заполнено вручную то пропускаем
                                    --i;
                                    Solve(i, j, (field[i][j] - 1));//продолжить с числа меньше на 1
                                }
                            }
                        }
                    }
                }
            }
            if (i < 8) { 
                ++i;
                Solve(i, j);
            }
            else {
                i = 0;
                ++j;
                Solve(i, j);
            }
        }
        return; //выход из рекурсии если j=9 есть решение
    }

    ~Sudoku() {
        for (int i = 0; i < MAX_LEN; ++i) {
            delete [] field[i];
            delete [] check_field[i];
        }
    }

};

class Game {
    char key;
public:
    Game() {
        SetConsoleTitle(L"РЕШАТЕЛЬ СУДОКУ");
    }

    void GotoXY(int X, int Y) {
        COORD place = { X, Y };
        SetConsoleCursorPosition(hStdOut, place);
    }

    void SetColor(int text, int background) {
        SetConsoleTextAttribute(hStdOut, background * 16 + text);
    }

    void gamefunc()
    {
        system("cls");
        Sudoku sudoku;
        sudoku.show();
        sudoku.set_value();

    }
    void Menu() {
        int f = 1;
        bool flag;
        SetColor(0, 0);
        GotoXY(10, 1);
        SetColor(14, 0);
        cout << "-->Решить судоку<--";
        GotoXY(13, 3);
        SetColor(15, 0);
        cout << "   Выход   ";
        do {
            flag = false;
            key = _getch();

            if (key == 224 || key == 0)
                cin >> key;
            switch (key) {
            case 80:
                f = f * (-1);
                if (f == 1) {
                    GotoXY(10, 1); SetColor(14, 0); cout << "-->Решить судоку<--";
                    GotoXY(13, 3); SetColor(15, 0); cout << "   Выход   ";
                }
                else {
                    GotoXY(10, 1); SetColor(15, 0); cout << "   Решить судоку   ";
                    GotoXY(13, 3); SetColor(14, 0); cout << "-->Выход<--";
                }
                break;
            case 72:
                f = f * (-1);
                if (f == 1) {
                    GotoXY(10, 1); SetColor(14, 0); cout << "-->Решить судоку<--";
                    GotoXY(13, 3); SetColor(15, 0); cout << "   Выход   ";
                }
                else {
                    GotoXY(10, 1); SetColor(15, 0);  cout << "   Решить судоку   ";
                    GotoXY(13, 3); SetColor(14, 0); cout << "-->Выход<--";
                }
                break;
            case 13:
                flag = true;
                break;
            }
        } while (!flag);
        if (f != 1) {
            system("cls");
            exit(0);
        }
        gamefunc();

    }
};






int main() { //тестирование

    setlocale(LC_ALL, "Ru");

    ///////////////////////////////////////////////////////////////////////
    Game sud;
    while (true) {
        sud.Menu();
    }



    ///////////////////////////////////////////////////////////////////////

    return 0;

}