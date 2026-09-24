// Intermediary Class (Level 2)
public class Hardware extends ProdukIT {
    private String kategori;
    private String nomorSeri;
    private int tahunRilis;

    public Hardware(String idProduk, String merk, long hargaDasar, String kategori, String nomorSeri, int tahunRilis) {
        super(idProduk, merk, hargaDasar);
        this.kategori = kategori;
        this.nomorSeri = nomorSeri;
        this.tahunRilis = tahunRilis;
    }

    public String getKategori() { return kategori; }
    public void setKategori(String kategori) { this.kategori = kategori; }

    public String getNomorSeri() { return nomorSeri; }
    public void setNomorSeri(String nomorSeri) { this.nomorSeri = nomorSeri; }

    public int getTahunRilis() { return tahunRilis; }
    public void setTahunRilis(int tahunRilis) { this.tahunRilis = tahunRilis; }
}