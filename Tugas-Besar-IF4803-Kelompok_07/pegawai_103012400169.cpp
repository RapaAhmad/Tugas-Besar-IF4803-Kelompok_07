#include <iostream>
#include "header.h"
using namespace std;

//Pegawai
adrPegawai createElmPegawai(string nama, string jabatan, string gender, int umur, string NIK);
void insertFirstPegawai(adrDivisi &P, adrPegawai Q);
void insertAfterPegawai(adrPegawai Prec, adrPegawai Q);
void insertLastPegawai(adrDivisi &P, adrPegawai Q);
void deleteFirstPegawai(adrDivisi &P, adrPegawai &Q);
void deleteLastPegawai(adrDivisi &P, adrPegawai &Q);
void deleteAfterPegawai(adrPegawai Prec, adrPegawai &Q);
adrPegawai searchPegawai(adrDivisi P, string nama, string NIK);
void viewPegawai(adrPegawai Q);

//Komputing
int hitungtotalpegawai(adrDivisi P);
void divisiTerbanyak(listDivisi L);
