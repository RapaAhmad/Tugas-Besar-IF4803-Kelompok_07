#ifndef PEGAWAI_H_INCLUDED
#define PEGAWAI_H_INCLUDED

struct Pegawai{
    string namaPegawai;
    string jabatanPegawai;
    string genderPegawai;
    int umurPegawai;
    string NIK;
};

typedef struct elmC *addresC;

struct elmC{
    Pegawai infoC;
    addresC next;
    addresC prev;
};

void createListPegawai(elmC &L);
addresC createElmPegawai(pegawai info);
void insertFirstPegawai(elmC &L, addresC P);
void insertAfterPegawai(elmC &L, addresC Prec, addresC P);
void insertLastPegawai(elmC &L, addresC P);
void deleteFirstPegawai(elmC &L, addresC &P);
void deleteLastPegawai(elmC &L, addresC &P);
void deleteAfterPegawai(elmC &L, addresC Prec, addresC &P);
addresC searchPegawai(elmC L, string nama,string NIK);
void viewPegawai(elmC L);
void viewAll(elmC L);


#endif // PEGAWAI_H_INCLUDED
