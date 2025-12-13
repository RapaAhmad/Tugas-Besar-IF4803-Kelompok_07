#include <iostream>
#include "header.h"
using namespace std;

void deleteFirstPegawai(adrDivisi &P, adrPegawai &Q) {
    Q = P->firstChild;
    if (P->firstChild == nullptr){
        cout<<"list pegawai kosong" ;
    }else if (Q ->next == nullptr){
        P->firstChild = nullptr;
        Q ->next = nullptr;
        Q ->prev = nullptr;
    }else {
        P ->firstChild = Q ->next ;
        Q ->next ->prev = nullptr ;
        Q ->next = nullptr ;
        Q ->prev = nullptr ;
    }
}
void deleteLastPegawai(adrDivisi &P, adrPegawai &Q){
    if (P->firstChild == nullptr){
        cout<<"list pegawai kosong" ;
    }else if (Q ->next == nullptr){
        P->firstChild = nullptr;
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
adrPegawai searchPegawai(adrDivisi P,  string NIK){
    adrPegawai  q ;
    if(P ->firstChild == nullptr){
        return nullptr ;
    } else {
        q = P ->firstChild ;
        while (q != nullptr){
            if (q->infoC.NIK == NIK){
                return q;
            }
            q  = q ->next ;
        }

    }
    return nullptr;
}
void viewPegawai(adrPegawai Q){
    if (Q == nullptr){
        cout<<"Informasi kosong" ;
    } else {
        cout << "Nama: " << Q ->infoC.namaPegawai << endl ;
        cout << "Jabatan: " << Q ->infoC.jabatanPegawai<<endl ;
        cout << "Gender: " << Q ->infoC.genderPegawai << endl;
        cout << "Umur: " << Q ->infoC.umurPegawai<<endl ;
        cout << "NIK: " << Q ->infoC.NIK <<endl;
    }

}
int hitungtotalpegawai(adrDivisi P){
    if(P ->firstChild == nullptr ){
        return 0 ;
    } else {
        adrPegawai q ;
        int total = 0 ;
        q = P ->firstChild ;
        while (q != nullptr){
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

int rataPerDivisi(adrDivisi P, listDivisi L){
    int tempPeg = 0 ;
    int tempDiv = 0 ;
    P = L.first;
    while (P != nullptr){
         tempPeg = hitungtotalpegawai(P) + tempPeg ;
         tempDiv = 1 + tempDiv ;
         P = P ->next ;

    }
    return tempPeg/tempDiv ;
}
