// Derived Class (Level 3)
public class Laptop extends Hardware {
    private String jenisProsesor;
    private String kapasitasRam;
    private String ukuranLayar;

    // Parameter kategori dicabut, digantikan hardcode "Laptop" pada super()
    public Laptop(String idProduk, String merk, long hargaDasar, String nomorSeri, int tahunRilis, String jenisProsesor, String kapasitasRam, String ukuranLayar) {
        super(idProduk, merk, hargaDasar, "Laptop", nomorSeri, tahunRilis);
        this.jenisProsesor = jenisProsesor;
        this.kapasitasRam = kapasitasRam;
        this.ukuranLayar = ukuranLayar;
    }

    public String getJenisProsesor() { return jenisProsesor; }
    public void setJenisProsesor(String jenisProsesor) { this.jenisProsesor = jenisProsesor; }

    public String getKapasitasRam() { return kapasitasRam; }
    public void setKapasitasRam(String kapasitasRam) { this.kapasitasRam = kapasitasRam; }

    public String getUkuranLayar() { return ukuranLayar; }
    public void setUkuranLayar(String ukuranLayar) { this.ukuranLayar = ukuranLayar; }

    // Output baris berformat dinamis
    public void printRow(int[] w) {
        String format = "| %-" + w[0] + "s | %-" + w[1] + "s | %-" + w[2] + "d | %-" + w[3] + "s | %-" + w[4] + "s | %-" + w[5] + "d | %-" + w[6] + "s | %-" + w[7] + "s | %-" + w[8] + "s |\n";
        System.out.printf(format, getIdProduk(), getMerk(), getHargaDasar(), getKategori(), getNomorSeri(), getTahunRilis(), getJenisProsesor(), getKapasitasRam(), getUkuranLayar());
    }
}