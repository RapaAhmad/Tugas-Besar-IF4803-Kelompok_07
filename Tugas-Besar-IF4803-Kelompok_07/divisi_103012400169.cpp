#include <iostream>
#include "header.h"
using namespace std;


void createListDivisi(listDivisi &L){
    L.first = nullptr;
}
adrDivisi createElmDivisi(string namaDivisi, string idDivisi){
    adrDivisi p;

    p = new elmDivisi;
    p->infoP.namaDivisi = namaDivisi;
    p->infoP.idDivisi = idDivisi;
    p->next = nullptr;
    p->firstChild = nullptr;

    return p;
}
void insertFirstDivisi(listDivisi &L, adrDivisi P){
    if (L.first == nullptr){
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}
void insertAfterDivisi(listDivisi &L, adrDivisi Prec, adrDivisi P){
    if (Prec->next = nullptr){
        Prec->next = P;
    } else {
        P->next = Prec->next;
        Prec->next = P;
    }
}
void insertLastDivisi(listDivisi &L, adrDivisi P){
    adrDivisi Q;

    if (L.first == nullptr){
        L.first = P;
    } else {
        Q = L.first;
        while (Q != nullptr){
            Q = Q->next;
        }
        Q->next = P;
    }
}
adrDivisi searchDivisi(listDivisi L, string idDivisi){
    adrDivisi Q, ketemu;

    Q  = L.first;
    ketemu = nullptr;
    while (Q != nullptr){
        if (Q->infoP.idDivisi == idDivisi){
            ketemu = Q;
        }
        Q = Q->next;
    }
    return ketemu;
}

void viewDivisi(listDivisi L){
    adrDivisi Q;

    Q = L.first;
    while (Q != nullptr){
        cout << "ID Divisi: " << Q->infoP.idDivisi << endl;
        cout << "Nama Divisi: " << Q->infoP.idDivisi << endl;
        cout << endl;
        Q = Q->next;
    }
}

void viewAll(listDivisi L){
    adrDivisi P;
    adrPegawai Q;

    P = L.first;
    if (L.first == nullptr){
        cout << "Belum ada divisi" << endl;
    } else {
    while (P != nullptr){
        cout << "ID Divisi: " << P->infoP.idDivisi << endl;
        cout << "Nama Divisi: " << P->infoP.namaDivisi << endl;
        cout << "Daftar Pegawai: " << endl;
        Q = P->firstChild;
        if (Q == nullptr){
            cout <<"Tidak ada pegawai" << endl;
        } else {
            while (Q != nullptr){
                cout << "Nama: " << Q->infoC.namaPegawai << endl;
                cout << "Jabatan: " << Q->infoC.jabatanPegawai << endl;
                Q = Q->next;
            }
            cout << endl;
        }
        cout << endl;
        P = P->next;
        }
    }
}
