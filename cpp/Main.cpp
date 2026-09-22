#include <iostream>
#include <vector>
#include "Laptop.cpp"
using namespace std;

// Fungsi terpisah untuk mencetak seluruh isi vector ke dalam format tabel dinamis
void printTable(const vector<Laptop*>& list) {
    cout << "\n----------------------------------------------------------------------------------------------------------\n";
    cout << "| ID\t| Merk\t| Harga\t\t| Kategori\t| No. Seri\t| Tahun\t| Prosesor\t| RAM\t| Layar\t |\n";
    cout << "----------------------------------------------------------------------------------------------------------\n";
    // Iterasi memanggil method printRow dari masing-masing objek Laptop
    for (size_t i = 0; i < list.size(); i++) {
        list[i]->printRow();
    }
    cout << "----------------------------------------------------------------------------------------------------------\n";
}

int main() {
    // Menggunakan Vector of Pointers untuk mensimulasikan alokasi memori dinamis
    vector<Laptop*> daftarLaptop;
    
    // 5 Objek statis awal sesuai instruksi TP
    daftarLaptop.push_back(new Laptop("L01", "Apple", 15000000, "Laptop", "SN01", 2024, "M3", "8GB", "13.6"));
    daftarLaptop.push_back(new Laptop("L02", "Lenovo", 12000000, "Laptop", "SN02", 2023, "Ryzen5", "16GB", "14.0"));
    daftarLaptop.push_back(new Laptop("L03", "Asus", 18000000, "Laptop", "SN03", 2024, "Intel-i7", "16GB", "15.6"));
    daftarLaptop.push_back(new Laptop("L04", "HP", 10000000, "Laptop", "SN04", 2022, "Intel-i5", "8GB", "14.0"));
    daftarLaptop.push_back(new Laptop("L05", "Acer", 9500000, "Laptop", "SN05", 2023, "Ryzen3", "8GB", "14.0"));

    int n;
    cout << "Masukkan jumlah data baru yang ingin ditambahkan (0 jika skip): ";
    cin >> n;

    // Loop untuk menerima input dinamis dari user
    for (int i = 0; i < n; i++) {
        string id, merk, kat, seri, pros, ram, layar;
        int harga, tahun;
        
        cout << "\nData ke-" << i + 1 << endl;
        cout << "ID: "; cin >> id;
        cout << "Merk: "; cin >> merk;
        cout << "Harga: "; cin >> harga;
        cout << "Kategori: "; cin >> kat;
        cout << "No Seri: "; cin >> seri;
        cout << "Tahun: "; cin >> tahun;
        cout << "Prosesor: "; cin >> pros;
        cout << "RAM: "; cin >> ram;
        cout << "Layar: "; cin >> layar;
        
        // Alokasi memori baru untuk objek yang diinputkan user
        daftarLaptop.push_back(new Laptop(id, merk, harga, kat, seri, tahun, pros, ram, layar));
    }

    printTable(daftarLaptop);

    // MANUAL GARBAGE COLLECTION:
    // Di C++, memori yang dialokasikan dengan 'new' harus dibebaskan dengan 'delete'
    // untuk mencegah memory leak.
    for (size_t i = 0; i < daftarLaptop.size(); i++) {
        delete daftarLaptop[i];
    }
    daftarLaptop.clear(); // Mengosongkan kapasitas vector
    cout << "\n[System] Garbage Collection executed. Memory cleared.\n";

    return 0;
}