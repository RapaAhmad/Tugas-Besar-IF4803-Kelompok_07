 #include <iostream>
 #include "header.h"

using namespace std;

int main() {
    listDivisi L;
    adrDivisi P;
    adrPegawai Q;
    int pilihanUtama = -1;

    createListDivisi(L);

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

        Q = createElmPegawai("Surya_Sekunder", "Manager", "P", 35, "3002");
        insertLastPegawai(P, Q);

    while (pilihanUtama != 0) {
        cout << "\n==============================================================" << endl;
        cout << " SISTEM MANAJEMEN PEGAWAI PERUSAHAAN PT. Makmur Jaya Althajir " << endl;
        cout << "==============================================================" << endl;
        cout << "1. Login sebagai ADMIN " << endl;
        cout << "2. Login sebagai USER " << endl;
        cout << "0. Keluar Aplikasi" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihanUtama;

        switch(pilihanUtama) {
            case 1:
                menuAdmin(L);
                break;
            case 2:
                menuUser(L);
                break;
            case 0:
                cout << "Terima kasih ^_^ " << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}


