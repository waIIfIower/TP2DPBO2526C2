#pragma once
#include "ProdukIT.cpp"

// Intermediary Class (Level 2): Turunan dari ProdukIT untuk kelompok perangkat keras
class Hardware : public ProdukIT {
private:
    string kategori;
    string nomorSeri;
    int tahunRilis;

public:
    // Konstruktor Hardware meneruskan atribut umum ke ProdukIT melalui initializer list
    Hardware(string id, string m, long long h, string k, string ns, int tr) 
        : ProdukIT(id, m, h) {
        this->kategori = k;
        this->nomorSeri = ns;
        this->tahunRilis = tr;
    }
    
    ~Hardware() {}

    // Accessor Methods
    string getKategori() { return kategori; }
    void setKategori(string k) { this->kategori = k; }

    string getNomorSeri() { return nomorSeri; }
    void setNomorSeri(string ns) { this->nomorSeri = ns; }

    int getTahunRilis() { return tahunRilis; }
    void setTahunRilis(int tr) { this->tahunRilis = tr; }
};