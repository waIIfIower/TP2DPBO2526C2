#pragma once
#include <iomanip>
#include "Hardware.cpp"
using namespace std;

// Derived Class (Level 3): Kelas turunan akhir spesifik untuk Laptop
class Laptop : public Hardware {
private:
    string jenisProsesor;
    string kapasitasRam;
    string ukuranLayar;

public:
    // OPTIMASI LOGIKA: Kategori di-hardcode menjadi "Laptop" ke kelas Hardware 
    // sehingga user tidak perlu menginputkan kategori yang sudah pasti
    Laptop(string id, string m, long long h, string ns, int tr, string jp, string kr, string ul) 
        : Hardware(id, m, h, "Laptop", ns, tr) {
        this->jenisProsesor = jp;
        this->kapasitasRam = kr;
        this->ukuranLayar = ul;
    }
    
    ~Laptop() {}

    // Accessor Methods spesifik Laptop
    string getJenisProsesor() { return jenisProsesor; }
    void setJenisProsesor(string jp) { this->jenisProsesor = jp; }

    string getKapasitasRam() { return kapasitasRam; }
    void setKapasitasRam(string kr) { this->kapasitasRam = kr; }

    string getUkuranLayar() { return ukuranLayar; }
    void setUkuranLayar(string ul) { this->ukuranLayar = ul; }

    // Metode pencetakan baris dengan padding dinamis menerima array lebar 'w'
    void printRow(int w[]) {
        cout << "| " << left << setw(w[0]) << getIdProduk() 
             << " | " << setw(w[1]) << getMerk() 
             << " | " << setw(w[2]) << getHargaDasar() 
             << " | " << setw(w[3]) << getKategori() 
             << " | " << setw(w[4]) << getNomorSeri() 
             << " | " << setw(w[5]) << getTahunRilis() 
             << " | " << setw(w[6]) << jenisProsesor 
             << " | " << setw(w[7]) << kapasitasRam 
             << " | " << setw(w[8]) << ukuranLayar << " |" << endl;
    }
};