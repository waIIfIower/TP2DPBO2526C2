#pragma once
#include <iostream>
#include <string>
using namespace std;

// Base Class (Level 1): Kelas induk utama yang merepresentasikan entitas produk umum
class ProdukIT {
private:
    // Enkapsulasi: Properti bersifat private agar tidak dapat diakses langsung dari luar
    string idProduk;
    string merk;
    long long hargaDasar; // Menggunakan long long untuk mencegah integer overflow (dukungan >2 miliar)

public:
    // Konstruktor utama untuk mengalokasikan dan menginisialisasi properti dasar
    ProdukIT(string id, string m, long long h) {
        this->idProduk = id;
        this->merk = m;
        this->hargaDasar = h;
    }
    
    // Virtual Destructor: Menjamin pelepasan memori kelas induk saat objek turunan dihapus
    virtual ~ProdukIT() {}

    // Accessor Methods (Getters & Setters)
    string getIdProduk() { return idProduk; }
    void setIdProduk(string id) { this->idProduk = id; }

    string getMerk() { return merk; }
    void setMerk(string m) { this->merk = m; }

    long long getHargaDasar() { return hargaDasar; }
    void setHargaDasar(long long h) { this->hargaDasar = h; }
};