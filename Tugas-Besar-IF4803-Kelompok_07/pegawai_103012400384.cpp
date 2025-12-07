#include <iostream>
#include "header.h"
using namespace std;

void deleteFirstPegawai(adrDivisi &P, adrPegawai &Q) {
    if (P->firstChild == nullptr){
        cout<<"list pegawai kosong" ;
    }else if (Q ->next == nullptr){
        P->firstChild = nullptr;
        Q ->next = nullptr;
        Q ->prev = nullptr;
    }else {
        P ->firstChild = Q ->next ;
        Q ->next ->prev == nullptr ;
        Q ->next = nullptr ;
        Q ->prev = nullptr ;
    }
}
void deleteLastPegawai(adrDivisi &P, adrPegawai &Q){
    if (P->firstChild == nullptr){
        cout<<"list pegawai kosong" ;
    }else if (Q ->next == nullptr){
        P->firstChild= nullptr;
        Q ->next = nullptr;
        Q ->prev = nullptr;
    }else {
        adrPegawai R ;
        R = P ->firstChild ;
        while (R ->next != nullptr){
            R = R ->next ;
        }
        Q = R ;
        R ->prev->next = nullptr ;
        Q ->prev = nullptr ;
        Q ->next = nullptr ;

    }
}
void deleteAfterPegawai(adrPegawai Prec, adrPegawai &Q){
    Q = Prec ->next ;
    if(Prec == nullptr || Prec ->next == nullptr){
        cout<< "list pegawai kosong" ;
    } else if (Q ->next == nullptr){
        Prec ->next =   nullptr ;
        Q ->prev = nullptr ;
        Q ->next = nullptr ;
    } else {
        Prec ->next = Q ->next ;
        Q ->next->prev == Prec ;
        Q ->next = nullptr ;
        Q ->prev = nullptr ;
    }
}
adrPegawai searchPegawai(adrDivisi P, string nama, string NIK){
    adrPegawai  q ;
    if(P ->firstChild == nullptr ||!( P ->firstChild->infoC.namaPegawai == nama && P ->firstChild->infoC.NIK == NIK)   ){
        cout<<"List pegawai kosong" ;
    }else if ( P ->firstChild->infoC.namaPegawai == nama && P ->firstChild->infoC.NIK == NIK) {

        return nullptr ;
    }else {

        q = P ->firstChild ;
        while (q ->next != nullptr && (q ->infoC.namaPegawai == nama && q ->infoC.NIK == NIK)){
            q  = q ->next ;
        }
        return q ;
    }
}
void viewPegawai(adrPegawai Q){
    if (Q == nullptr){
        cout<<"Informasi kosong" ;
    } else {
        cout << Q ->infoC->namaPegawai ;

        cout << Q ->infoC->jabatanPegawai ;
        cout << Q ->infoC->genderPegawai ;
        cout << Q ->infoC->umurPegawai ;
        cout << Q ->infoC->NIK ;

    }

}
int hitungtotalpegawai(adrDivisi P){
    if(P ->firstChild == nullptr ){
        return 0 ;
    } else {
        adrPegawai q ;
        int total = 0 ;
        q = P ->firstChild ;
        while (q ->next == nullptr){
            total = total + 1 ;
            q = q ->next ;
        }
        return total ;
    }
}
void divisiTerbanyak(listDivisi L){
    adrDivisi P = L.first;
    int total = 0;

    while (P != nullptr ) {
        total = total + hitungtotalpegawai(P);
        P = P->next;
    }
}
