#include "header.h"
#include<iostream>
using namespace std ;


void pilihanMenuDivisi(listDivisi &L) {
    int pil = -1;
    string nama, id;
    adrDivisi P, prec;

    while (pil != 0) {
        cout << "\n=== KELOLA DIVISI ===" << endl;
        cout << "1. Insert First Divisi" << endl;
        cout << "2. Insert Last Divisi" << endl;
        cout << "3. Delete First Divisi" << endl;
        cout << "4. Delete Last Divisi" << endl;
        cout << "5. Cari Divisi" << endl;
        cout << "0. Kembali" << endl;
        cout << "Pilih: ";
        cin >> pil;

        if (pil == 1 || pil == 2) {
            cout << "Masukkan ID Divisi: ";
            cin >> id;
            cout << "Masukkan Nama Divisi: ";
            cin>>nama ;
            P = createElmDivisi(nama, id);
            if (pil == 1) insertFirstDivisi(L, P);
            else insertLastDivisi(L, P);
            cout << "Divisi berhasil ditambahkan!" << endl;
        } else if (pil == 3) {
            deleteFirstDivisi(L, P);
            cout << "Divisi pertama dihapus." << endl;
        } else if (pil == 4) {
            deleteLastDivisi(L, P);
            cout << "Divisi terakhir dihapus." << endl;
        } else if (pil == 5) {
            cout << "Masukkan ID yang dicari: "; cin >> id;
            P = searchDivisi(L, id);
            if (P != nullptr) {
                cout << "Ditemukan: " << P->infoP.namaDivisi << endl;
            } else {
                cout << "Divisi tidak ditemukan." << endl;
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

    cout << "Masukkan ID Divisi tempat Pegawai berada: "; cin >> idDiv;
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
            deleteFirstPegawai(PDiv, Q);
            cout << "Pegawai pertama dihapus." << endl;
        } else if (pil == 3) {
            deleteLastPegawai(PDiv, Q);
            cout << "Pegawai terakhir dihapus." << endl;
        }
    }
}

void menuAdmin(listDivisi &L) {
    int pilihan = -1;
    while (pilihan != 0) {
        cout << "\n======= MENU ATMIN =======" << endl;
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
                pilihanMenuPegawai(L);
                break;
            case 3:
                viewAll(L);
                break;
            case 0:
                cout << "Keluar dari mode Atmin" << endl;
                break;
            default:
                cout << "Pilihan salah." << endl;
        }
    }
}
