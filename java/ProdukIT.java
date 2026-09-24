// Base Class (Level 1)
public class ProdukIT {
    private String idProduk;
    private String merk;
    private long hargaDasar; // Tipe long untuk menampung nominal angka besar

    public ProdukIT(String idProduk, String merk, long hargaDasar) {
        this.idProduk = idProduk;
        this.merk = merk;
        this.hargaDasar = hargaDasar;
    }

    // Accessor Methods
    public String getIdProduk() { return idProduk; }
    public void setIdProduk(String idProduk) { this.idProduk = idProduk; }

    public String getMerk() { return merk; }
    public void setMerk(String merk) { this.merk = merk; }

    public long getHargaDasar() { return hargaDasar; }
    public void setHargaDasar(long hargaDasar) { this.hargaDasar = hargaDasar; }
}