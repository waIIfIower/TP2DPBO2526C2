import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Fungsi untuk mem-parsing dan mencetak seluruh isi ArrayList
    public static void printTable(ArrayList<Laptop> list) {
        System.out.println("-".repeat(105));
        System.out.printf("| %-5s | %-10s | %-10s | %-10s | %-10s | %-6s | %-12s | %-5s | %-6s |\n",
                "ID", "Merk", "Harga", "Kategori", "No. Seri", "Tahun", "Prosesor", "RAM", "Layar");
        System.out.println("-".repeat(105));
        
        // For-each loop untuk memanggil method cetak per baris
        for (Laptop l : list) {
            l.printRow();
        }
        System.out.println("-".repeat(105));
    }

    public static void main(String[] args) {
        // ArrayList bertindak sebagai Collection dinamis penampung objek
        ArrayList<Laptop> daftarLaptop = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        // 5 Objek statis awal
        daftarLaptop.add(new Laptop("L01", "Apple", 15000000, "Laptop", "SN01", 2024, "M3", "8GB", "13.6"));
        daftarLaptop.add(new Laptop("L02", "Lenovo", 12000000, "Laptop", "SN02", 2023, "Ryzen5", "16GB", "14.0"));
        daftarLaptop.add(new Laptop("L03", "Asus", 18000000, "Laptop", "SN03", 2024, "Intel-i7", "16GB", "15.6"));
        daftarLaptop.add(new Laptop("L04", "HP", 10000000, "Laptop", "SN04", 2022, "Intel-i5", "8GB", "14.0"));
        daftarLaptop.add(new Laptop("L05", "Acer", 9500000, "Laptop", "SN05", 2023, "Ryzen3", "8GB", "14.0"));

        System.out.print("Masukkan jumlah data tambahan (0 jika tidak ada): ");
        int n = sc.nextInt();
        
        // Menerima masukan dari user
        for (int i = 0; i < n; i++) {
            System.out.println("\nData ke-" + (i + 1));
            System.out.print("ID: "); String id = sc.next();
            System.out.print("Merk: "); String merk = sc.next();
            System.out.print("Harga: "); int harga = sc.nextInt();
            System.out.print("Kategori: "); String kat = sc.next();
            System.out.print("No Seri: "); String seri = sc.next();
            System.out.print("Tahun: "); int tahun = sc.nextInt();
            System.out.print("Prosesor: "); String pros = sc.next();
            System.out.print("RAM: "); String ram = sc.next();
            System.out.print("Layar: "); String layar = sc.next();
            
            // Instansiasi objek baru langsung dimasukkan ke dalam ArrayList
            daftarLaptop.add(new Laptop(id, merk, harga, kat, seri, tahun, pros, ram, layar));
        }

        printTable(daftarLaptop);
        sc.close();

        // MANUAL TRIGGER GARBAGE COLLECTION (BEST PRACTICE):
        // JVM secara otomatis mengelola memori, namun melepaskan referensi 
        // secara eksplisit membantu GC bekerja lebih cepat dan efisien.
        daftarLaptop.clear();
        daftarLaptop = null;
        System.gc(); // Mengirimkan saran kepada JVM untuk mengeksekusi Garbage Collector
        System.out.println("\n[System] Garbage Collection hints sent.");
    }
}