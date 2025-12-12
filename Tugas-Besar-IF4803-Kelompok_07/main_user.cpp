 #include <iostream>
 #include "header.h"

using namespace std;

void menuUser(listDivisi L) {
    int pilihan = -1;
    string idDiv, nik;
    adrDivisi P;
    adrPegawai Q;

    while (pilihan != 0) {
        cout << "\n======= MENU PEGAWAI =======" << endl;
        cout << "1. Tampilkan Seluruh Data Perusahaan" << endl;
        cout << "2. Tampilkan Data Per Divisi Tertentu" << endl;
        cout << "3. Cari Pegawai berdasarkan NIK" << endl;
        cout << "4. Statistik (Total Pegawai dalam Divisi)" << endl;
        cout << "0. Logout / Kembali" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                viewAll(L);
                break;
            case 2:
                cout << "Masukkan ID Divisi: ";
                cin >> idDiv;
                P = searchDivisi(L, idDiv);
                if (P != nullptr) {
                    cout << "Divisi: " << P->infoP.namaDivisi << endl;
                    Q = P->firstChild;
                    if (Q == nullptr) cout << "Tidak ada pegawai." << endl;
                    while (Q != nullptr) {
                        viewPegawai(Q);
                        cout << endl;
                        Q = Q->next;
                    }
                } else {
                    cout << "Divisi tidak ditemukan." << endl;
                }
                break;
            case 3:

                {
                    cout << "Masukkan NIK: "; cin >> nik;
                    bool found = false;
                    P = L.first;
                    while (P != nullptr && !found) {
                        Q = searchPegawai(P, nik);
                        if (Q != nullptr) {
                            cout << "Ditemukan di Divisi " << P->infoP.namaDivisi << endl;
                            viewPegawai(Q);
                            cout << endl;
                            found = true;
                        }
                        P = P->next;
                    }
                    if (!found) {
                       cout << "Pegawai dengan NIK tersebut tidak ditemukan." << endl;
                    }
                }
                break;
            case 4:
                cout << "Masukkan ID Divisi untuk hitung total: ";
                cin >> idDiv;
                P = searchDivisi(L, idDiv);
                if (P != nullptr) {
                    int total = hitungtotalpegawai(P);
                    cout << "Total Pegawai di " << P->infoP.namaDivisi << ": " << total << endl;
                } else {
                    cout << "Divisi tidak ditemukan." << endl;
                }
                break;
            case 0:
                cout << "Keluar dari mode User" << endl;
                break;
            default:
                cout << "Pilihan salah." << endl;
        }
    }
}
