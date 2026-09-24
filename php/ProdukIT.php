<?php
// Base Class (Level 1)
class ProdukIT {
    private $idProduk;
    private $merk;
    private $hargaDasar;
    private $fotoProduk; 

    public function __construct($idProduk, $merk, $hargaDasar, $fotoProduk) {
        $this->idProduk = $idProduk;
        $this->merk = $merk;
        $this->hargaDasar = $hargaDasar;
        $this->fotoProduk = $fotoProduk;
    }

    public function getIdProduk() { return $this->idProduk; }
    public function setIdProduk($idProduk) { $this->idProduk = $idProduk; }

    public function getMerk() { return $this->merk; }
    public function setMerk($merk) { $this->merk = $merk; }

    public function getHargaDasar() { return $this->hargaDasar; }
    public function setHargaDasar($hargaDasar) { $this->hargaDasar = $hargaDasar; }

    public function getFotoProduk() { return $this->fotoProduk; }
    public function setFotoProduk($fotoProduk) { $this->fotoProduk = $fotoProduk; }
}
?>