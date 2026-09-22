#pragma once
#include "Hardware.cpp"

// Derived Class: Mewarisi Hardware, entitas paling spesifik (Level 3)
class Laptop : public Hardware
{
private:
    string jenisProsesor;
    string kapasitasRam;
    string ukuranLayar;

public:
    // Konstruktor Laptop mendelegasikan inisialisasi dasar ke Hardware (Parent)
    Laptop(string id, string m, int h, string k, string ns, int tr, string jp, string kr, string ul)
        : Hardware(id, m, h, k, ns, tr)
    {
        this->jenisProsesor = jp;
        this->kapasitasRam = kr;
        this->ukuranLayar = ul;
    }

    // Destruktor untuk membebaskan objek Laptop
    ~Laptop() {}

    // Getters & Setters spesifik Laptop
    string getJenisProsesor() { return jenisProsesor; }
    void setJenisProsesor(string jp) { this->jenisProsesor = jp; }

    string getKapasitasRam() { return kapasitasRam; }
    void setKapasitasRam(string kr) { this->kapasitasRam = kr; }

    string getUkuranLayar() { return ukuranLayar; }
    void setUkuranLayar(string ul) { this->ukuranLayar = ul; }

    // Method untuk merender data objek ini ke dalam format baris tabel
    void printRow()
    {
        cout << "| " << getIdProduk() << "\t| " << getMerk() << "\t| " << getHargaDasar() << "\t| "
             << getKategori() << "\t| " << getNomorSeri() << "\t| " << getTahunRilis() << "\t| "
             << jenisProsesor << "\t| " << kapasitasRam << "\t| " << ukuranLayar << " |" << endl;
    }
};