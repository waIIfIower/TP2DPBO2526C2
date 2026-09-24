<?php
require_once 'ProdukIT.php';

// Intermediary Class (Level 2)
class Hardware extends ProdukIT {
    private $kategori;
    private $nomorSeri;
    private $tahunRilis;

    public function __construct($idProduk, $merk, $hargaDasar, $fotoProduk, $kategori, $nomorSeri, $tahunRilis) {
        parent::__construct($idProduk, $merk, $hargaDasar, $fotoProduk);
        $this->kategori = $kategori;
        $this->nomorSeri = $nomorSeri;
        $this->tahunRilis = $tahunRilis;
    }

    public function getKategori() { return $this->kategori; }
    public function setKategori($kategori) { $this->kategori = $kategori; }

    public function getNomorSeri() { return $this->nomorSeri; }
    public function setNomorSeri($nomorSeri) { $this->nomorSeri = $nomorSeri; }

    public function getTahunRilis() { return $this->tahunRilis; }
    public function setTahunRilis($tahunRilis) { $this->tahunRilis = $tahunRilis; }
}
?>