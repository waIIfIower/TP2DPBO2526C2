<?php
// Memastikan file kelas parent diload
require_once 'ProdukIT.php';

// Intermediary Class (Level 2)
class Hardware extends ProdukIT {
    private $kategori;
    private $nomorSeri;
    private $tahunRilis;

    public function __construct($idProduk, $merk, $hargaDasar, $fotoProduk, $kategori, $nomorSeri, $tahunRilis) {
        // parent::__construct memanggil konstruktor dari ProdukIT
        parent::__construct($idProduk, $merk, $hargaDasar, $fotoProduk);
        $this->kategori = $kategori;
        $this->nomorSeri = $nomorSeri;
        $this->tahunRilis = $tahunRilis;
    }

    // Getters
    public function getKategori() { return $this->kategori; }
    public function getNomorSeri() { return $this->nomorSeri; }
    public function getTahunRilis() { return $this->tahunRilis; }

    // Setters
    public function setKategori($kategori) { $this->kategori = $kategori; }
    public function setNomorSeri($nomorSeri) { $this->nomorSeri = $nomorSeri; }
    public function setTahunRilis($tahunRilis) { $this->tahunRilis = $tahunRilis; }
}
?>