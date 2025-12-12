#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

typedef struct elmDivisi *adrDivisi;
typedef struct elmPegawai *adrPegawai;

struct Divisi{
    string idDivisi;
    string namaDivisi;
};
struct Pegawai{
    string namaPegawai;
    string jabatanPegawai;
    string genderPegawai;
    int umurPegawai;
    string NIK;
};

struct elmDivisi{
    Divisi infoP;
    adrDivisi next;
    adrPegawai firstChild;
};

struct elmPegawai{
    Pegawai infoC;
    adrPegawai next;
    adrPegawai prev;
};

struct listDivisi{
    adrDivisi first;
};

//Divisi
void createListDivisi(listDivisi &L);
adrDivisi createElmDivisi(string namaDivisi, string idDivisi);
void insertFirstDivisi(listDivisi &L, adrDivisi P);
void insertAfterDivisi(listDivisi &L, adrDivisi Prec, adrDivisi P);
void insertLastDivisi(listDivisi &L, adrDivisi P);
void deleteFirstDivisi(listDivisi &L, adrDivisi &P);
void deleteLastDivisi(listDivisi &L, adrDivisi &P);
void deleteAfterDivisi(listDivisi &L, adrDivisi Prec, adrDivisi &P);
adrDivisi searchDivisi(listDivisi L, string idDivisi);
void viewDivisi(listDivisi L);
void viewAll(listDivisi L);

//Pegawai
adrPegawai createElmPegawai(string nama, string jabatan, string gender, int umur, string NIK);
void insertFirstPegawai(adrDivisi &P, adrPegawai Q);
void insertAfterPegawai(adrPegawai Prec, adrPegawai Q);
void insertLastPegawai(adrDivisi &P, adrPegawai Q);
void deleteFirstPegawai(adrDivisi &P, adrPegawai &Q);
void deleteLastPegawai(adrDivisi &P, adrPegawai &Q);
void deleteAfterPegawai(adrPegawai Prec, adrPegawai &Q);
adrPegawai searchPegawai(adrDivisi P, string NIK);
void viewPegawai(adrPegawai Q) ;

//Komputing
int hitungtotalpegawai(adrDivisi P);
int rataPerDivisi(adrDivisi P) ;
void divisiTerbanyak(listDivisi L);

//Menu
void menuAdmin(listDivisi &L);
void menuUser(listDivisi L);
void pilihanMenuDivisi(listDivisi &L);
void pilihanMenuPegawai(listDivisi &L);

#endif // HEADER_H_INCLUDED


