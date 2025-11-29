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

#endif // PEGAWAI_H_INCLUDED
