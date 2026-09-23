#include <iostream>
#include <vector>
#include <limits> // Library untuk memanipulasi buffer stream memori
#include "Laptop.cpp"
using namespace std;

// Fungsi terpisah untuk mencetak tabel dinamis
void printTable(const vector<Laptop*>& list) {
    cout << "\n----------------------------------------------------------------------------------------------------------\n";
    cout << "| ID\t| Merk\t| Harga\t\t| Kategori\t| No. Seri\t| Tahun\t| Prosesor\t| RAM\t| Layar\t |\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
    for (size_t i = 0; i < list.size(); i++) {
        list[i]->printRow();
    }
    cout << "----------------------------------------------------------------------------------------------------------\n";
}

int main() {
    // Koleksi dinamis untuk menampung objek (Pointer untuk efisiensi memori)
    vector<Laptop*> daftarLaptop;
    
    // Inisialisasi 5 objek statis (Sesuai Syarat TP)
    daftarLaptop.push_back(new Laptop("L01", "Apple", 15000000, "Laptop", "SN01", 2024, "M3", "8GB", "13.6"));
    daftarLaptop.push_back(new Laptop("L02", "Lenovo", 12000000, "Laptop", "SN02", 2023, "Ryzen5", "16GB", "14.0"));
    daftarLaptop.push_back(new Laptop("L03", "Asus", 18000000, "Laptop", "SN03", 2024, "Intel-i7", "16GB", "15.6"));
    daftarLaptop.push_back(new Laptop("L04", "HP", 10000000, "Laptop", "SN04", 2022, "Intel-i5", "8GB", "14.0"));
    daftarLaptop.push_back(new Laptop("L05", "Acer", 9500000, "Laptop", "SN05", 2023, "Ryzen3", "8GB", "14.0"));

    int n = 0;
    
    // Error Handling: Validasi Jumlah Data Baru
    while (true) {
        cout << "Masukkan jumlah data baru yang ingin ditambahkan (0 jika skip): ";
        // Jika cin berhasil membaca integer, keluar dari loop
        if (cin >> n) {
            break; 
        } else {
            // Jika gagal (misal user mengetik huruf), cetak error dan bersihkan buffer
            cout << "input salah\n";
            cin.clear(); // Mereset state error pada cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membuang karakter sampah di memori
        }
    }

    // Perulangan untuk input data baru
    for (int i = 0; i < n; i++) {
        string id, merk, kat, seri, pros, ram, layar;
        int harga, tahun;
        
        cout << "\nData ke-" << i + 1 << endl;
        cout << "ID: "; cin >> id;
        cout << "Merk: "; cin >> merk;
        
        // Error Handling: Memastikan Harga adalah Integer
        while (true) {
            cout << "Harga: "; 
            if (cin >> harga) {
                break;
            } else {
                cout << "input salah\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        cout << "Kategori: "; cin >> kat;
        cout << "No Seri: "; cin >> seri;
        
        // Error Handling: Memastikan Tahun adalah Integer
        while (true) {
            cout << "Tahun: "; 
            if (cin >> tahun) {
                break;
            } else {
                cout << "input salah\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        
        cout << "Prosesor: "; cin >> pros;
        cout << "RAM: "; cin >> ram;
        cout << "Layar: "; cin >> layar;
        
        // Memasukkan instance objek baru ke dalam vector
        daftarLaptop.push_back(new Laptop(id, merk, harga, kat, seri, tahun, pros, ram, layar));
    }

    // Merender tabel secara keseluruhan
    printTable(daftarLaptop);

    // Manual Garbage Collection C++: Menghapus alokasi pointer di memori heap
    for (size_t i = 0; i < daftarLaptop.size(); i++) {
        delete daftarLaptop[i];
    }
    daftarLaptop.clear();
    cout << "\n[System] Garbage Collection executed. Memory cleared.\n";

    return 0;
}