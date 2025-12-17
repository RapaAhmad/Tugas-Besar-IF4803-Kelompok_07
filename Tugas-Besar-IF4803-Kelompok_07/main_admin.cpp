#include "header.h"
#include<iostream>
using namespace std ;


void pilihanMenuDivisi(listDivisi &L) {
    int pil = -1;
    string nama, id;
    adrDivisi P, prec;

    while (pil != 0) {
        cout << "\n=== KELOLA DIVISI ===" << endl;
        cout << "1. Tambah Divisi" << endl;
        cout << "2. Hapus Divisi Terlama" << endl;
        cout << "3. Hapus Divisi Terbaru" << endl;
        cout << "4. Cari Divisi" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1) {
            cout << "Masukkan ID Divisi: ";
            cin >> id;
            cout << "Masukkan Nama Divisi: ";
            cin>>nama ;
            P = createElmDivisi(nama, id);
            insertLastDivisi(L, P);
            cout << "Divisi berhasil ditambahkan!" << endl;
        } else if (pil == 2) {
            if (L.first != nullptr){
               cout << "Divisi Terlama dihapus." << endl;
            }
            deleteFirstDivisi(L, P);
        } else if (pil == 3) {
            if (L.first != nullptr){
                cout << "Divisi Terbaru dihapus." << endl;
            }
            deleteLastDivisi(L, P);

        } else if (pil == 4) {
            if (L.first != nullptr ){

                cout << "Masukkan ID yang dicari: ";
                cin >> id;
                P = searchDivisi(L, id);
                if (P != nullptr) {
                     cout << "Ditemukan: " << P->infoP.namaDivisi << endl;
                } else if (P == nullptr){
                    cout<<"Tidak ada Divisi dengan ID:  " << id <<endl ;
                }

            }else {
                cout << "Divisi Kosong." << endl ;
            }
        }
    }
}


void pilihanMenuPegawai(listDivisi &L) {
    int pil = -1;
    string idDiv, nama, jab, gen, nik;
    int umur;
    adrDivisi PDiv;
    adrPegawai Q, precPeg;

    cout << "Masukkan ID Divisi tempat Pegawai berada: ";
    cin >> idDiv;
    PDiv = searchDivisi(L, idDiv);

    if (PDiv == nullptr) {
        cout << "Divisi tidak ditemukan! Buat divisi terlebih dahulu." << endl;
        return;
    }

    while (pil != 0) {
        cout << "\n=== KELOLA PEGAWAI (Divisi: " << PDiv->infoP.namaDivisi << ") ===" << endl;
        cout << "1. Tambah Pegawai " << endl;
        cout << "2. Hapus Pegawai (Pegawai Pertama)" << endl;
        cout << "3. Hapus Pegawai (Pegawai Terakhir)" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1) {
            cout << "Nama: ";
            cin>> nama ;
            cout << "Jabatan: ";
            cin >> jab ;
            cout << "Gender (L/P): ";
            cin >> gen;
            cout << "Umur: ";
            cin >> umur;
            cout << "NIK: ";
            cin >> nik;

            Q = createElmPegawai(nama, jab, gen, umur, nik);
            insertLastPegawai(PDiv, Q);
            cout << "Pegawai berhasil ditambahkan." << endl;
        } else if (pil == 2) {
            if (PDiv->firstChild != nullptr){
               cout << "Pegawai pertama dihapus." << endl;
            }
            deleteFirstPegawai(PDiv, Q);

        } else if (pil == 3) {
            if (PDiv->firstChild != nullptr){
               cout << "Pegawai terakhir dihapus." << endl;
            }
            deleteLastPegawai(PDiv, Q);
        }
    }
}

void menuAdmin(listDivisi &L) {
    int pilihan = -1;
    while (pilihan != 0) {
        cout << "\n======= MENU ADMIN =======" << endl;
        cout << "1. Kelola Data Divisi" << endl;
        cout << "2. Kelola Data Pegawai" << endl;
        cout << "3. Lihat Semua Data" << endl;
        cout << "0. Logout / Kembali" << endl;
        cout << "Pilih: "; cin >> pilihan;

        switch(pilihan) {
            case 1:
                pilihanMenuDivisi(L);
                break;
            case 2:
                if (L.first == nullptr) {
                    cout<<"Tidak ada Divisi."<<endl ;
                }else {
                    pilihanMenuPegawai(L);
                }


                break;
            case 3:
                viewAll(L);
                break;
            case 0:
                cout << "Keluar dari mode Admin" << endl;
                break;
            default:
                cout << "Pilihan salah." << endl;
        }
    }
}
