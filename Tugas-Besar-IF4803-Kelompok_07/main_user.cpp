 #include <iostream>
 #include "header.h"

using namespace std;

void menuUser(listDivisi L) {
    int pilihan = -1;
    int rerata;
    string idDiv, nik;
    adrDivisi P;
    adrPegawai Q;
/*
    P = createElmDivisi("IT", "001");
    insertLastDivisi(L, P);

        Q = createElmPegawai("Budi_Setiawan", "Project_Manager", "L", 25, "1001");
        insertLastPegawai(P, Q);

        Q = createElmPegawai("Usep_Jalaludin", "Frontend_Dev", "L", 27, "1002");
        insertLastPegawai(P, Q);

        Q = createElmPegawai("Verrel_Bray", "Backend_Dev", "L", 27, "1003");
        insertLastPegawai(P, Q);

        Q = createElmPegawai("Ailsa_Nur", "UI/UX", "P", 24, "1004");
        insertLastPegawai(P, Q);

    P = createElmDivisi("Keuangan", "002");
    insertLastDivisi(L, P);

        Q = createElmPegawai("Citra_Kirana", "Manager", "P", 30, "2001");
        insertLastPegawai(P, Q);

        Q = createElmPegawai("Karin_Sukma", "Analyst", "P", 25, "2002");
        insertLastPegawai(P, Q);

        Q = createElmPegawai("Emi_Lia", "Akuntan", "P", 29, "2003");
        insertLastPegawai(P, Q);


    P = createElmDivisi("HR", "003");
    insertLastDivisi(L, P);

        Q = createElmPegawai("Eko_Patriot", "Recruiter", "L", 29, "3001");
        insertLastPegawai(P, Q);

        Q = createElmPegawai("Surya_Sekunder", "Manager", "L", 35, "3002");
        insertLastPegawai(P, Q);
*/
    while (pilihan != 0) {
        cout << "\n======= MENU USER =======" << endl;
        cout << "1. Tampilkan Seluruh Divisi Perusahaan" << endl;
        cout << "2. Tampilkan Seluruh Data Perusahaan" << endl;
        cout << "3. Tampilkan Data Per Divisi Tertentu" << endl;
        cout << "4. Cari Pegawai berdasarkan NIK" << endl;
        cout << "5. Total Pegawai dalam Suatu Divisi" << endl;
        cout << "6. Rata-rata Pegawai per Divisi" << endl;
        cout << "0. Logout / Kembali" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                viewDivisi(L);
                break;
            case 2:
                viewAll(L);
                break;
            case 3:
                if (L.first == nullptr){
                    cout<< "Tidak ada Divisi. "<< endl ;
                }else {
                    cout << "Masukkan ID Divisi: ";
                cin >> idDiv;

                P = searchDivisi(L, idDiv);
                if (P != nullptr) {
                    cout << "\nDivisi: " << P->infoP.namaDivisi << endl;

                    Q = P->firstChild;
                    if (Q == nullptr ) {
                        cout << "Tidak ada pegawai." << endl;
                    } else {
                        cout << "\nDaftar Pegawai: " << endl;
                        while (Q != nullptr) {
                        viewPegawai(Q);
                        cout << endl;
                        Q = Q->next;
                        }
                    }
                } else {
                    cout << "Divisi tidak ditemukan." << endl;
                }
                }

                break;
            case 4:
                {
                    if (L.first != nullptr){
                        cout << "Masukkan NIK: ";
                    cin >> nik;
                    bool found = false;
                    P = L.first;
                    while (P != nullptr && !found) {
                        Q = searchPegawai(P, nik);
                        if (Q != nullptr) {
                            cout << "\nDitemukan di Divisi " << P->infoP.namaDivisi << endl;
                            viewPegawai(Q);
                            cout << endl;
                            found = true;
                        }
                        P = P->next;
                    }
                    if (!found) {
                       cout << "\nPegawai dengan NIK tersebut tidak ditemukan." << endl;
                    }
                    } else {
                        cout << "Tidak ada Pegawai." << endl;
                    }

                }
                break;
            case 5:
                if (L.first == nullptr){
                    cout<<"Tidak ada Divisi."<<endl ;
                } else {
                cout << "Masukkan ID Divisi untuk hitung total: ";
                cin >> idDiv;
                P = searchDivisi(L, idDiv);
                if (P != nullptr) {
                    int total = hitungtotalpegawai(P);
                    if (total == 0 ) {
                        cout<<"Tidak ada Pegawai."<<endl ;
                    }else{
                    cout << "Total Pegawai di " << P->infoP.namaDivisi << ": " << total << endl;
                    }
                } else {
                    cout << "Divisi tidak ditemukan." << endl;
                }
                }

                break;
            case 6:
                if (L.first == nullptr){
                    cout << ("Belum ada Divisi.") << endl;
                } else {
                    rerata = rataPerDivisi(P, L);
                    if (rerata == 0){
                        cout << "Belum ada Pegawai dalam Divisi" << endl;
                    } else {
                        cout << "Rata-rata Pegawai per Divisi adalah: " << rerata << endl;
                    }
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
