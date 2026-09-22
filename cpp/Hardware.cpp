#pragma once
#include "ProdukIT.cpp"

// Intermediary Class: Mewarisi ProdukIT, memperluas sifat produk fisik (Level 2)
class Hardware : public ProdukIT {
private:
    string kategori;
    string nomorSeri;
    int tahunRilis;

public:
    // Konstruktor Hardware juga memanggil konstruktor ProdukIT (Parent) 
    // untuk memastikan atribut dasar ikut terinisialisasi
    Hardware(string id, string m, int h, string k, string ns, int tr) 
        : ProdukIT(id, m, h) {
        this->kategori = k;
        this->nomorSeri = ns;
        this->tahunRilis = tr;
    }
    
    // Destruktor untuk membersihkan instance Hardware
    ~Hardware() {}

    // Getters
    string getKategori() { return kategori; }
    string getNomorSeri() { return nomorSeri; }
    int getTahunRilis() { return tahunRilis; }

    // Setters
    void setKategori(string k) { this->kategori = k; }
    void setNomorSeri(string ns) { this->nomorSeri = ns; }
    void setTahunRilis(int tr) { this->tahunRilis = tr; }
};