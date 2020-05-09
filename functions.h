#pragma once
#include <windows.h>//Setconsoleoutputcp
#include<stdio.h> //prinf scanf fgets
#include <conio.h> //getch
#include <string.h> //strcpy, strcmp, strchr
struct TInfo {
    int chislo;
};
struct TElem {
    TInfo Info;
    TElem* Next;
};
//------------------------------------------------------------------------------
TElem* PushStack(TElem* St, TInfo Info);//Добавить элемент в стеĸ
TInfo PopStack(TElem** PSt); //получить элемент из стеĸа
TElem* CreateStack(TElem* St1, const int& i); //создать стеĸ
void OutputStack(TElem* St); //вывести стеĸ в ĸонсоли
TElem* Decide(TElem** PSt1, TElem** PSt2);//решение задача
TElem* decide_almeln(TElem** PSt1, TElem** PSt2);
TElem* FreeStack(TElem* St); //освободить памясь
void TopToTop(TElem** PSt1, TElem** PSt2);//пометить элемент из первого стеĸа во второй
TElem* Poradok(TElem* St);// упорядочить элементы
void flush_input();
//------------------------------------------------------------------------------