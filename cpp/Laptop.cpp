#pragma once
#include <iomanip>
#include "Hardware.cpp"
using namespace std;

// Derived Class (Level 3): Klasifikasi spesifik untuk perangkat Laptop
class Laptop : public Hardware {
private:
    string jenisProsesor;
    string kapasitasRam;
    string ukuranLayar; // Atribut untuk menyimpan dimensi ukuran layar

public:
    // Konstruktor meneruskan string "Laptop" langsung ke kelas Hardware
    Laptop(string id, string m, long long h, string ns, int tr, string jp, string kr, string ul) 
        : Hardware(id, m, h, "Laptop", ns, tr) {
        this->jenisProsesor = jp;
        this->kapasitasRam = kr;
        this->ukuranLayar = ul;
    }
    
    ~Laptop() {}

    // Accessor Methods
    string getJenisProsesor() { return jenisProsesor; }
    void setJenisProsesor(string jp) { this->jenisProsesor = jp; }

    string getKapasitasRam() { return kapasitasRam; }
    void setKapasitasRam(string kr) { this->kapasitasRam = kr; }

    string getUkuranLayar() { return ukuranLayar; }
    void setUkuranLayar(string ul) { this->ukuranLayar = ul; }

    // Mencetak baris tabel dengan formating padding yang dinamis (w)
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