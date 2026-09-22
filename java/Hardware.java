// Intermediary Class (Level 2) - Keyword 'extends' merepresentasikan pewarisan
public class Hardware extends ProdukIT {
    private String kategori;
    private String nomorSeri;
    private int tahunRilis;

    public Hardware(String idProduk, String merk, int hargaDasar, String kategori, String nomorSeri, int tahunRilis) {
        // Keyword 'super' wajib diletakkan di baris pertama konstruktor 
        // untuk memanggil konstruktor class induk (ProdukIT)
        super(idProduk, merk, hargaDasar);
        this.kategori = kategori;
        this.nomorSeri = nomorSeri;
        this.tahunRilis = tahunRilis;
    }

    // Getters and Setters
    public String getKategori() { return kategori; }
    public void setKategori(String kategori) { this.kategori = kategori; }

    public String getNomorSeri() { return nomorSeri; }
    public void setNomorSeri(String nomorSeri) { this.nomorSeri = nomorSeri; }

    public int getTahunRilis() { return tahunRilis; }
    public void setTahunRilis(int tahunRilis) { this.tahunRilis = tahunRilis; }
}