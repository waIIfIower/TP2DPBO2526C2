#pragma once
#include <iostream>
#include <string>
using namespace std;

// Base Class: Mewakili entitas produk secara umum (Level 1)
class ProdukIT {
private:
    // Enkapsulasi ketat: Atribut hanya bisa diakses dari dalam class ini
    string idProduk;
    string merk;
    int hargaDasar;

public:
    // Konstruktor untuk menginisialisasi state awal objek ProdukIT
    ProdukIT(string id, string m, int h) {
        this->idProduk = id;
        this->merk = m;
        this->hargaDasar = h;
    }
    
    // Virtual Destructor: Sangat krusial dalam C++ OOP agar saat objek 
    // turunan dihapus (delete), memori class induk juga ikut terbebaskan
    virtual ~ProdukIT() {}

    // Getters: Mengambil nilai atribut private
    string getIdProduk() { return idProduk; }
    string getMerk() { return merk; }
    int getHargaDasar() { return hargaDasar; }

    // Setters: Memodifikasi nilai atribut private dengan aman
    void setIdProduk(string id) { this->idProduk = id; }
    void setMerk(string m) { this->merk = m; }
    void setHargaDasar(int h) { this->hargaDasar = h; }
};