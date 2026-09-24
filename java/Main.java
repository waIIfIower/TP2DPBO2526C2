import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    // Fungsi komputasi lebar kolom dan pencetakan tabel
    public static void printTable(ArrayList<Laptop> list) {
        int[] w = {2, 4, 5, 8, 8, 5, 8, 3, 5};
        
        for (Laptop l : list) {
            w[0] = Math.max(w[0], l.getIdProduk().length());
            w[1] = Math.max(w[1], l.getMerk().length());
            w[2] = Math.max(w[2], String.valueOf(l.getHargaDasar()).length());
            w[3] = Math.max(w[3], l.getKategori().length());
            w[4] = Math.max(w[4], l.getNomorSeri().length());
            w[5] = Math.max(w[5], String.valueOf(l.getTahunRilis()).length());
            w[6] = Math.max(w[6], l.getJenisProsesor().length());
            w[7] = Math.max(w[7], l.getKapasitasRam().length());
            w[8] = Math.max(w[8], l.getUkuranLayar().length());
        }

        int totalW = 0; 
        for (int width : w) { totalW += width; }
        String separator = "-".repeat(totalW + 28);
        String format = "| %-" + w[0] + "s | %-" + w[1] + "s | %-" + w[2] + "s | %-" + w[3] + "s | %-" + w[4] + "s | %-" + w[5] + "s | %-" + w[6] + "s | %-" + w[7] + "s | %-" + w[8] + "s |\n";

        System.out.println(separator);
        System.out.printf(format, "ID", "Merk", "Harga", "Kategori", "No. Seri", "Tahun", "Prosesor", "RAM", "Layar");
        System.out.println(separator);
        for (Laptop l : list) { l.printRow(w); }
        System.out.println(separator);
    }

    public static void main(String[] args) {
        ArrayList<Laptop> daftarLaptop = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        daftarLaptop.add(new Laptop("L01", "Apple", 15000000L, "SN01", 2024, "M3", "8GB", "13.6"));
        daftarLaptop.add(new Laptop("L02", "Lenovo", 12000000L, "SN02", 2023, "Ryzen5", "16GB", "14.0"));
        daftarLaptop.add(new Laptop("L03", "Asus", 18000000L, "SN03", 2024, "Intel-i7", "16GB", "15.6"));
        daftarLaptop.add(new Laptop("L04", "HP", 10000000L, "SN04", 2022, "Intel-i5", "8GB", "14.0"));
        daftarLaptop.add(new Laptop("L05", "Acer", 9500000L, "SN05", 2023, "Ryzen3", "8GB", "14.0"));

        int n = 0;
        while (true) {
            try {
                System.out.print("Masukkan jumlah data tambahan (0 jika tidak ada): ");
                n = sc.nextInt();
                sc.nextLine(); 
                break;
            } catch (InputMismatchException e) {
                System.out.println("input salah");
                sc.nextLine(); 
            }
        }
        
        for (int i = 0; i < n; i++) {
            System.out.println("\nData ke-" + (i + 1));
            System.out.print("ID: "); String id = sc.nextLine();
            
            String merk = "";
            // Validasi Merk: Menolak jika bisa di-parse penuh menjadi Integer
            while (true) {
                System.out.print("Merk: ");
                merk = sc.nextLine();
                try {
                    Integer.parseInt(merk);
                    System.out.println("input salah");
                } catch (NumberFormatException e) {
                    break; 
                }
            }
            
            long harga = 0L;
            // Validasi Harga: Try-catch nextLong()
            while (true) {
                try {
                    System.out.print("Harga: ");
                    harga = sc.nextLong();
                    sc.nextLine();
                    break;
                } catch (InputMismatchException e) {
                    System.out.println("input salah"); 
                    sc.nextLine(); 
                }
            }
            
            System.out.print("No Seri: "); String seri = sc.nextLine();
            
            int tahun = 0;
            // Validasi Tahun: Try-catch nextInt()
            while (true) {
                try {
                    System.out.print("Tahun: ");
                    tahun = sc.nextInt();
                    sc.nextLine();
                    break;
                } catch (InputMismatchException e) {
                    System.out.println("input salah"); 
                    sc.nextLine(); 
                }
            }
            
            System.out.print("Prosesor: "); String pros = sc.nextLine();
            System.out.print("RAM: "); String ram = sc.nextLine();
            System.out.print("Layar: "); String layar = sc.nextLine();
            
            daftarLaptop.add(new Laptop(id, merk, harga, seri, tahun, pros, ram, layar));
        }

        printTable(daftarLaptop);
        sc.close();

        daftarLaptop.clear();
        daftarLaptop = null;
        System.gc();
    }
}