#ifndef DIVISI_H_INCLUDED
#define DIVISI_H_INCLUDED
#include "Pegawai.h"

struct Divisi{
    string idDivisi;
    string namaDivisi;
};
typedef struct elmP *addressP;

struct elmP{
    divisi infoP;
    addressP next;
    addressC firstChild;
};

struct listParent{
    addressP first;
};

void createListDivisi(listParent &L);
addressP createElmDivisi(string namaDivisi, string idDivisi);
void insertFirstDivisi(listParent &L, addressP P);
void insertAfterDivisi(listParent &L, addressP Prec, addressP P);
void insertLastDivisi(listParent &L, addressP P);
void deleteFirstDivisi(listParent &L, addressP &P);
void deleteLastDivisi(listParent &L, addressP &P);
void deleteAfterDivisi(listParent &L, addressP Prec, addressP &P);
addressP searchDivisi(listParent L, string idDivisi);
void viewDivisi(listParent L);
void viewAll(listParent L);


#endif // DIVISI_H_INCLUDED
