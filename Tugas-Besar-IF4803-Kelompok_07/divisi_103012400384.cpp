#include <iostream>
#include "header.h"
using namespace std;

void deleteFirstDivisi(listDivisi &L, adrDivisi &P){
    if (L.first == nullptr){
        cout << "Tidak ada divisi." << endl;
        P = nullptr;
    } else if (L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
    } else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}
void deleteLastDivisi(listDivisi &L, adrDivisi &P){
    adrDivisi Q;

    if (L.first == nullptr){
        cout << "Tidak ada divisi." << endl;
        P = nullptr;
    } else if (L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
    } else {
        Q = L.first;
        while (Q->next->next != nullptr){
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}
void deleteAfterDivisi(listDivisi &L, adrDivisi Prec, adrDivisi &P){
    if (L.first == nullptr || Prec->next == nullptr){
        cout << "Tidak ada divisi." << endl;
        P = nullptr;
    } else if (Prec->next->next == nullptr){
        P = Prec->next;
        Prec->next = nullptr;
    } else {
        P = Prec->next;
        Prec->next = nullptr;
        P->next = nullptr;
    }
}
