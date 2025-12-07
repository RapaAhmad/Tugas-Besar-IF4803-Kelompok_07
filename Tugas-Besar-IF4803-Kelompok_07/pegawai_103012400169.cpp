#include <iostream>
#include "header.h"
using namespace std;

adrPegawai createElmPegawai(string nama, string jabatan, string gender, int umur, string NIK){
    adrPegawai q = new elmPegawai ;
    q ->next = nullptr ;
    q ->prev = nullptr ;
    q ->infoC.namaPegawai = nama ;
    q ->infoC.jabatanPegawai = jabatan ;
    q ->infoC.genderPegawai = gender ;
    q ->infoC.umurPegawai = umur ;
    q ->infoC.NIK =nik ;
}
void insertFirstPegawai(adrDivisi &P, adrPegawai Q){
    if (P ->firstChild == nullptr ){
        P ->firstChild = Q ;
    }else {
        Q ->next = P ->firstChild ;
        Q ->prev = nullptr ;
        p ->firstChild = Q ;
    }
}
void insertAfterPegawai(adrPegawai Prec, adrPegawai Q){
    if (Prec == nullptr) {
        cout << "list kosong"
    }
    if (Prec->next == nullptr) {
        Prec->next = Q;
        Q->prev = Prec;
        Q->next = nullptr;
    } else {
        Q->next = Prec->next;
        Q->prev = Prec;
        Prec->next->prev = Q;
        Prec->next = Q;
    }
}
void insertLastPegawai(adrDivisi &P, adrPegawai Q){
    if (P->firstChild == NULL) {
        P->firstChild = Q;
        Q->next = nullptr;
        Q->prev = nullptr;
    } else {
        adrPegawai R = P->firstChild;
        while (R->next != nullptr) {
            R = R->next;
        }
        R->next = Q;
        Q->prev = R;
        Q->next = nullptr;
    }
}
}

