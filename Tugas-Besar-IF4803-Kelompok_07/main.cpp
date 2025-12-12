 #include <iostream>
 #include "header.h"

using namespace std;

int main() {
    listDivisi L;
    int pilihanUtama = -1;

    createListDivisi(L);

    while (pilihanUtama != 0) {
        cout << "\n=============================================" << endl;
        cout << " SISTEM MANAJEMEN PEGAWAI PERUSAHAAN PT. FuFa " << endl;
        cout << "=============================================" << endl;
        cout << "1. Login sebagai ATMIN " << endl;
        cout << "2. Login sebagai PEGAWAI " << endl;
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


