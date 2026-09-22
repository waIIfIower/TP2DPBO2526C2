<?php
// Base Class (Level 1)
class ProdukIT {
    // Modifier private membatasi visibilitas dari luar maupun class anak
    private $idProduk;
    private $merk;
    private $hargaDasar;
    private $fotoProduk; // Sesuai syarat khusus PDF untuk bahasa PHP

    // Konstruktor PHP
    public function __construct($idProduk, $merk, $hargaDasar, $fotoProduk) {
        $this->idProduk = $idProduk;
        $this->merk = $merk;
        $this->hargaDasar = $hargaDasar;
        $this->fotoProduk = $fotoProduk;
    }

    // Getters
    public function getIdProduk() { return $this->idProduk; }
    public function getMerk() { return $this->merk; }
    public function getHargaDasar() { return $this->hargaDasar; }
    public function getFotoProduk() { return $this->fotoProduk; }

    // Setters
    public function setIdProduk($idProduk) { $this->idProduk = $idProduk; }
    public function setMerk($merk) { $this->merk = $merk; }
    public function setHargaDasar($hargaDasar) { $this->hargaDasar = $hargaDasar; }
    public function setFotoProduk($fotoProduk) { $this->fotoProduk = $fotoProduk; }
}
?>