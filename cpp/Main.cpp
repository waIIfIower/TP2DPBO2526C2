#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <string>
#include "Laptop.cpp"
using namespace std;

// Sub-rutin perenderan tabel ke konsol CLI
void printTable(const vector<Laptop*>& list) {
    // Array padding kolom (mengikuti panjang teks Header Tabel)
    int w[9] = {2, 4, 5, 8, 8, 5, 8, 3, 12}; // Index 8 adalah Ukuran Layar

    // Pencarian string terpanjang pada koleksi data
    for (size_t i = 0; i < list.size(); i++) {
        w[0] = max(w[0], (int)list[i]->getIdProduk().length());
        w[1] = max(w[1], (int)list[i]->getMerk().length());
        w[2] = max(w[2], (int)to_string(list[i]->getHargaDasar()).length());
        w[3] = max(w[3], (int)list[i]->getKategori().length());
        w[4] = max(w[4], (int)list[i]->getNomorSeri().length());
        w[5] = max(w[5], (int)to_string(list[i]->getTahunRilis()).length());
        w[6] = max(w[6], (int)list[i]->getJenisProsesor().length());
        w[7] = max(w[7], (int)list[i]->getKapasitasRam().length());
        w[8] = max(w[8], (int)list[i]->getUkuranLayar().length());
    }

    int totalWidth = w[0]+w[1]+w[2]+w[3]+w[4]+w[5]+w[6]+w[7]+w[8] + 28;
    string separator(totalWidth, '-');

    cout << "\n" << separator << "\n";
    cout << "| " << left << setw(w[0]) << "ID"
         << " | " << setw(w[1]) << "Merk"
         << " | " << setw(w[2]) << "Harga"
         << " | " << setw(w[3]) << "Kategori"
         << " | " << setw(w[4]) << "No. Seri"
         << " | " << setw(w[5]) << "Tahun"
         << " | " << setw(w[6]) << "Prosesor"
         << " | " << setw(w[7]) << "RAM"
         << " | " << setw(w[8]) << "Ukuran Layar" << " |\n"; // Header disesuaikan
    cout << separator << "\n";
    
    for (size_t i = 0; i < list.size(); i++) {
        list[i]->printRow(w);
    }
    cout << separator << "\n";
}

int main() {
    vector<Laptop*> daftarLaptop;
    
    // Inisiasi 5 objek dengan hardcode simbol inch (') pada atribut ukuranLayar
    daftarLaptop.push_back(new Laptop("L01", "Apple", 15000000LL, "SN01", 2024, "M3", "8GB", "13.6'"));
    daftarLaptop.push_back(new Laptop("L02", "Lenovo", 12000000LL, "SN02", 2023, "Ryzen5", "16GB", "14.0'"));
    daftarLaptop.push_back(new Laptop("L03", "Asus", 18000000LL, "SN03", 2024, "Intel-i7", "16GB", "15.6'"));
    daftarLaptop.push_back(new Laptop("L04", "HP", 10000000LL, "SN04", 2022, "Intel-i5", "8GB", "14.0'"));
    daftarLaptop.push_back(new Laptop("L05", "Acer", 9500000LL, "SN05", 2023, "Ryzen3", "8GB", "14.0'"));

    int n = 0;
    
    // Validasi input awal (Jumlah n data)
    while (true) {
        cout << "Masukkan jumlah data tambahan (0 jika skip): ";
        cin >> n;
        if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
            cout << "(Error: Menolak huruf pada variabel integer)\n"; // Error spesifik
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        string id, merk, seri, pros, ram, layar;
        long long harga;
        int tahun;
        
        cout << "\nData ke-" << i + 1 << endl;
        cout << "ID: "; cin >> id; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Validasi Merk
        while (true) {
            cout << "Merk: "; 
            cin >> merk;
            bool isAllDigits = true;
            for (char c : merk) {
                if (!isdigit(c)) {
                    isAllDigits = false;
                    break;
                }
            }
            if (isAllDigits) {
                cout << "(Error: Menolak angka murni pada atribut merk)\n"; // Error spesifik
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        
        // Validasi Harga (Pencegahan karakter non-numerik)
        while (true) {
            cout << "Harga: "; 
            cin >> harga;
            if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
                cout << "(Error: Menolak kehadiran huruf pada harga)\n"; // Error spesifik
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        
        cout << "No Seri: "; cin >> seri; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Validasi Tahun (Pencegahan karakter non-numerik)
        while (true) {
            cout << "Tahun: "; 
            cin >> tahun;
            if (cin.fail() || (cin.peek() != '\n' && cin.peek() != ' ')) {
                cout << "(Error: Menolak kehadiran huruf pada tahun)\n"; // Error spesifik
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }
        
        cout << "Prosesor: "; cin >> pros; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "RAM: "; cin >> ram; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Penyesuaian nama prompt antarmuka
        cout << "Ukuran Layar: "; cin >> layar; cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        daftarLaptop.push_back(new Laptop(id, merk, harga, seri, tahun, pros, ram, layar));
    }

    printTable(daftarLaptop);

    // Explicit Garbage Collection untuk membersihkan alokasi HEAP memory
    for (size_t i = 0; i < daftarLaptop.size(); i++) {
        delete daftarLaptop[i];
    }
    daftarLaptop.clear();
    
    return 0;
}