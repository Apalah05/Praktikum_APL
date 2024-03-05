#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double USD_ke_IDR = 14450.0;
    const double EUR_ke_IDR = 17200.0;
    const double JPY_ke_IDR = 130.0;
    const double USD_ke_EUR = 0.85;
    const double USD_ke_JPY = 113.0;
    const double EUR_ke_USD = 1.18;
    const double EUR_ke_JPY = 133.0;
    const double JPY_ke_USD = 0.0088;
    const double JPY_ke_EUR = 0.0075;

    string nama, nim;
    int attempt = 0;

    // cek Login
    do {
        cout << "=== Login ===" << endl;
        cout << "Nama: ";
        getline(cin, nama);
        cout << "NIM: ";
        getline(cin, nim);

        // Check login
        if ((nama != "nanda") || (nim != "2309106022")) {
            attempt++;
            cout << "Login gagal. Kesempatan mencoba: " << 3 - attempt << " kali" << endl;
            if (attempt == 3) {
                cout << "Anda telah melebihi batas percobaan. Program berhenti." << endl;
                return 0;
            }
        } else {
            break;
        }
    } while (true);

    // Menu konversi
    while (true) {
        cout << "\n=== Menu Konversi Mata Uang ===" << endl;
        cout << "1. Konversi Rupiah ke (Dollar, Euro, Yen)" << endl;
        cout << "2. Konversi Dollar ke (Rupiah, Euro, Yen)" << endl;
        cout << "3. Konversi Euro ke (Rupiah, Dollar, Yen)" << endl;
        cout << "4. Konversi Yen ke (Rupiah, Dollar, Euro)" << endl;
        cout << "5. Keluar" << endl;

        int pilihan;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        double nominal;

        switch (pilihan) {
            case 1:
                cout << "Masukkan jumlah Rupiah: ";
                cin >> nominal;

                cout << fixed << setprecision(2);
                cout << "Konversi ke Dollar: $" << nominal / USD_ke_IDR << endl;
                cout << "Konversi ke Euro: €" << nominal / EUR_ke_IDR << endl;
                cout << "Konversi ke Yen: ¥" << nominal / JPY_ke_IDR << endl;
                break;

            case 2:
                cout << "Masukkan jumlah Dollar: $";
                cin >> nominal;

                cout << fixed << setprecision(2);
                cout << "Konversi ke Rupiah: Rp" << nominal * USD_ke_IDR << endl;
                cout << "Konversi ke Euro: €" << nominal * USD_ke_EUR << endl;
                cout << "Konversi ke Yen: ¥" << nominal * USD_ke_JPY << endl;
                break;

            case 3:
                cout << "Masukkan jumlah Euro: €";
                cin >> nominal;

                cout << fixed << setprecision(2);
                cout << "Konversi ke Rupiah: Rp" << nominal * EUR_ke_IDR << endl;
                cout << "Konversi ke Dollar: $" << nominal * EUR_ke_USD << endl;
                cout << "Konversi ke Yen: ¥" << nominal * EUR_ke_JPY << endl;
                break;

            case 4:
                cout << "Masukkan jumlah Yen: ¥";
                cin >> nominal;

                cout << fixed << setprecision(2);
                cout << "Konversi ke Rupiah: Rp" << nominal * JPY_ke_IDR << endl;
                cout << "Konversi ke Dollar: $" << nominal * JPY_ke_USD << endl;
                cout << "Konversi ke Euro: €" << nominal * JPY_ke_EUR << endl;
                break;

            case 5:
                cout << "Terima kasih telah menggunakan program. Sampai jumpa!" << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }
    }

    return 0;
}
