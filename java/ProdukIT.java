// Base Class (Level 1)
public class ProdukIT {
    // Access modifier private memastikan data tidak bisa diubah langsung dari luar class
    private String idProduk;
    private String merk;
    private int hargaDasar;

    // Konstruktor utama untuk ProdukIT
    public ProdukIT(String idProduk, String merk, int hargaDasar) {
        this.idProduk = idProduk;
        this.merk = merk;
        this.hargaDasar = hargaDasar;
    }

    // Getters and Setters: Pintu akses resmi untuk manipulasi atribut
    public String getIdProduk() { return idProduk; }
    public void setIdProduk(String idProduk) { this.idProduk = idProduk; }

    public String getMerk() { return merk; }
    public void setMerk(String merk) { this.merk = merk; }

    public int getHargaDasar() { return hargaDasar; }
    public void setHargaDasar(int hargaDasar) { this.hargaDasar = hargaDasar; }
}