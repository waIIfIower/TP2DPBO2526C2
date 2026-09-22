// Derived Class (Level 3) - Turunan paling spesifik dari Hardware
public class Laptop extends Hardware {
    private String jenisProsesor;
    private String kapasitasRam;
    private String ukuranLayar;

    public Laptop(String idProduk, String merk, int hargaDasar, String kategori, String nomorSeri, int tahunRilis, String jenisProsesor, String kapasitasRam, String ukuranLayar) {
        // Memanggil konstruktor Hardware
        super(idProduk, merk, hargaDasar, kategori, nomorSeri, tahunRilis);
        this.jenisProsesor = jenisProsesor;
        this.kapasitasRam = kapasitasRam;
        this.ukuranLayar = ukuranLayar;
    }

    // Getters and Setters
    public String getJenisProsesor() { return jenisProsesor; }
    public void setJenisProsesor(String jenisProsesor) { this.jenisProsesor = jenisProsesor; }

    public String getKapasitasRam() { return kapasitasRam; }
    public void setKapasitasRam(String kapasitasRam) { this.kapasitasRam = kapasitasRam; }

    public String getUkuranLayar() { return ukuranLayar; }
    public void setUkuranLayar(String ukuranLayar) { this.ukuranLayar = ukuranLayar; }

    // Method untuk mencetak format baris tabel menggunakan System.out.printf
    public void printRow() {
        System.out.printf("| %-5s | %-10s | %-10d | %-10s | %-10s | %-6d | %-12s | %-5s | %-6s |\n",
                getIdProduk(), getMerk(), getHargaDasar(), getKategori(), getNomorSeri(), getTahunRilis(), getJenisProsesor(), getKapasitasRam(), getUkuranLayar());
    }
}