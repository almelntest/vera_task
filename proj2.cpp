// proj2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//
//int main()
//{
//    std::cout << "Hello World!\n";
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <math.h> // fabs, pow, ceil\floor, log, log10, exp, sqrt
#include <stdlib.h> // randomize, rand
#include <windows.h> // SetConsoleOutputCP(1251); SetConsoleCP(1251);
#include <time.h>
#include "functions.h"
#pragma warning(disable: 4996)
//------------------------------------------------------------------------------
int main() {
    TElem* StackTop1 = NULL, *StackTop2 = NULL, *StackTop3 = NULL;
    SetConsoleOutputCP(1251);
    char ch;
    int kol;
    //начало ци.ла
    do {
        printf("\nN - создать новый сте.;\
\nV - вывод;\
\nD - решение;\
\nF - освободить;\
\nE - .онец.\
\nВаш выбор?");
        fflush(stdin);
        ch = getchar();
        fflush(stdin);
        ch = toupper(ch);
        switch (ch) {
            //------------------------------------------------------------------------------
        case 'N':
            if (StackTop1 || StackTop2 || StackTop3)
            {
                printf("Error: сначала надо освободить память!");
                break;
            }
            char ch;
            ch = getchar();
            fflush(stdin);
            ch = toupper(ch);
            StackTop1 = CreateStack(StackTop1, 1);
            StackTop2 = CreateStack(StackTop2, 2);
            break;
            //------------------------------------------------------------------------------
        case 'V':
            printf("Первый сте.:\n");
            OutputStack(StackTop1);
            printf("Второй сте.:\n");
            OutputStack(StackTop2);
            printf("Третий сте.:\n");
            OutputStack(StackTop3);
            break;
            //------------------------------------------------------------------------------
        case 'D':
            if (StackTop3) {
                printf("Cначала надо освободить память под третий сте..\n");
            }
            else if (!StackTop1 || !StackTop2) {
                printf("Один из сте.ов пуст, сначала заполните все сте.и.\n");
            }
            else {
                StackTop3 = Decide(&StackTop1, &StackTop2);
                fflush(stdin);
                break;
                printf("Создан третий сте. \n");
            }
            printf("press enter\n");
            getch();
            break;
            //------------------------------------------------------------------------------
        case 'F':
            StackTop1 = FreeStack(StackTop1);
            StackTop2 = FreeStack(StackTop2);
            StackTop3 = FreeStack(StackTop3);
            printf("Вся память освобождена под новые сте.и.\n");
            break;
            //------------------------------------------------------------------------------
        default:
            printf("Та.ой .оманды нет, повторите попыт.у\n");
            //------------------------------------------------------------------------------
        }
    } while (ch != 'E');
    return 0;
}