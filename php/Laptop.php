<?php
require_once 'Hardware.php';

// Derived Class (Level 3)
class Laptop extends Hardware {
    private $jenisProsesor;
    private $kapasitasRam;
    private $ukuranLayar;

    public function __construct($idProduk, $merk, $hargaDasar, $fotoProduk, $nomorSeri, $tahunRilis, $jenisProsesor, $kapasitasRam, $ukuranLayar) {
        parent::__construct($idProduk, $merk, $hargaDasar, $fotoProduk, "Laptop", $nomorSeri, $tahunRilis);
        $this->jenisProsesor = $jenisProsesor;
        $this->kapasitasRam = $kapasitasRam;
        $this->ukuranLayar = $ukuranLayar;
    }

    public function getJenisProsesor() { return $this->jenisProsesor; }
    public function setJenisProsesor($jenisProsesor) { $this->jenisProsesor = $jenisProsesor; }

    public function getKapasitasRam() { return $this->kapasitasRam; }
    public function setKapasitasRam($kapasitasRam) { $this->kapasitasRam = $kapasitasRam; }

    public function getUkuranLayar() { return $this->ukuranLayar; }
    public function setUkuranLayar($ukuranLayar) { $this->ukuranLayar = $ukuranLayar; }

    public function getRow() {
        return "<tr>
            <td>{$this->getIdProduk()}</td>
            <td><img src='{$this->getFotoProduk()}' width='50' alt='foto'></td>
            <td>{$this->getMerk()}</td>
            <td>Rp " . number_format((float)$this->getHargaDasar(), 0, ',', '.') . "</td>
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