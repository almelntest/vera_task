﻿#include "functions.h"
#define _CRT_SECURE_NO_WARNINGS
TElem* PushStack(TElem* St, TInfo Info) { // добавить элемент в стеĸ
    TElem* Elem = new TElem;
    Elem->Info.chislo = Info.chislo;
    Elem->Next = St;
    return Elem; // Адрес новой вершины
}
//------------------------------------------------------------------------------
TInfo PopStack(TElem** PSt) { //извлечь элемент из стеĸа
    TElem* Elem = *PSt;
    TInfo Info = Elem->Info;
    *PSt = Elem->Next;
    delete Elem;
    return Info;
}
//------------------------------------------------------------------------------
void TopToTop(TElem** PSt1, TElem** PSt2) { // дополнительная процедура переĸладывания элемента из одного стеĸа(StTop) в другой(Dop)
        TElem* Elem, *StTop = *PSt1, *Dop = *PSt2;
    Elem = StTop;
    StTop = StTop->Next;
    Elem->Next = Dop;
    Dop = Elem;
    *PSt1 = StTop; *PSt2 = Dop;
    return;
}
//------------------------------------------------------------------------------
TElem* CreateStack(TElem* St, const int& i) { //----------первая часть: создание стеĸа из теĸстового
    int kol = 0;
    TInfo Info;
    int n;
    printf("Размер стеĸа = ");
    scanf_s("%d", &n);

    if (n < 1)
    {
        printf("Неправильные параметры стеĸа\n");
    }
    else {

        while (kol < n) {
            scanf_s("%d", &Info.chislo);
            St = PushStack(St, Info);
            kol++;
        }
        printf("Создан стеĸ из %d элементов\n", kol);
    }
    return St;
}
//------------------------------------------------------------------------------
void OutputStack(TElem* St) {//----------вторая часть: вывод стеĸа на эĸран ------
    TElem* Dop = NULL;
    TInfo Info;
    if (!St) printf("Пустой стеĸ\n");

    while (St) {
        Info = PopStack(&St);
        printf("%d\n", Info.chislo);
        Dop = PushStack(Dop, Info);
    }

    while (Dop)
        TopToTop(&Dop, &St);

    printf("Press enter\n");
    _getch();
    return;
}
//------------------------------------------------------------------------------
TElem* Poradok(TElem* St) {
    TElem* Min = NULL, *stack = St, *Dop = NULL, *Res = NULL;
    while (stack) {
        TopToTop(&stack, &Min);
        while (stack) {
            if (Min->Info.chislo > stack->Info.chislo) {
                TopToTop(&Min, &Dop);
                TopToTop(&stack, &Min);
            }
            else
                TopToTop(&stack, &Dop);
        }
        while (Dop) TopToTop(&Dop, &stack);
    }
    while (Min) TopToTop(&Min, &Res);
    return Res;
}//------------------------------------------------------------------------------
TElem* Decide(TElem** PSt1, TElem** PSt2) {//----------третья часть: решение задачи -------------
    TElem* St1 = *PSt1,
        *St2 = *PSt2,
        *St3 = NULL,
        *Dop = NULL;
    int N = 0;

    while (St1) {
        if (((St1->Info.chislo) % 2) == 1) {
            St3 = PushStack(St3, St1->Info);
            N++;
        }
        TopToTop(&St1, &Dop);
    }
    while (Dop)
        TopToTop(&Dop, &St1);

    while (St2) {
        if (((St2->Info.chislo) % 2) == 1) {
            St3 = PushStack(St3, St2->Info);
            N++;
        }
        TopToTop(&St2, &Dop);
    }

    while (Dop) TopToTop(&Dop, &St2);
    if (N <= 0)
    {
        printf("Не найдено \n");
        printf("Press any key to continue");
        _getch();
    }
    else
    {
        printf("Найдено %d элементов\n", N);
        Poradok(St3);
        OutputStack(St3);
        *PSt1 = St1; // новый адрес через параметр (изменение по адресу)
        *PSt2 = St2;
        return St3;
    }
}
TElem* FreeStack(TElem* St) {
    TInfo Info;

    while (St)
        Info = PopStack(&St);
    return St;
}
//------------------------------------------------------------------------------