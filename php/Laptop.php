<?php
require_once 'Hardware.php';

// Derived Class (Level 3)
class Laptop extends Hardware {
    private $jenisProsesor;
    private $kapasitasRam;
    private $ukuranLayar;

    public function __construct($idProduk, $merk, $hargaDasar, $fotoProduk, $kategori, $nomorSeri, $tahunRilis, $jenisProsesor, $kapasitasRam, $ukuranLayar) {
        // Pemanggilan konstruktor berantai ke kelas Hardware
        parent::__construct($idProduk, $merk, $hargaDasar, $fotoProduk, $kategori, $nomorSeri, $tahunRilis);
        $this->jenisProsesor = $jenisProsesor;
        $this->kapasitasRam = $kapasitasRam;
        $this->ukuranLayar = $ukuranLayar;
    }

    // Getters
    public function getJenisProsesor() { return $this->jenisProsesor; }
    public function getKapasitasRam() { return $this->kapasitasRam; }
    public function getUkuranLayar() { return $this->ukuranLayar; }

    // Setters
    public function setJenisProsesor($jenisProsesor) { $this->jenisProsesor = $jenisProsesor; }
    public function setKapasitasRam($kapasitasRam) { $this->kapasitasRam = $kapasitasRam; }
    public function setUkuranLayar($ukuranLayar) { $this->ukuranLayar = $ukuranLayar; }

    // Metode pengembalian string HTML <tr> untuk dinamisasi tabel web
    public function getRow() {
        return "<tr>
            <td>{$this->getIdProduk()}</td>
            <td><img src='{$this->getFotoProduk()}' width='50' alt='foto'></td>
            <td>{$this->getMerk()}</td>
            <td>Rp " . number_format($this->getHargaDasar(), 0, ',', '.') . "</td>
            <td>{$this->getKategori()}</td>
            <td>{$this->getNomorSeri()}</td>
            <td>{$this->getTahunRilis()}</td>
            <td>{$this->getJenisProsesor()}</td>
            <td>{$this->getKapasitasRam()}</td>
            <td>{$this->getUkuranLayar()}</td>
        </tr>";
    }
}
?>