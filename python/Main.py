from Laptop import Laptop

# Fungsi untuk mengeksekusi print tabel dinamis
def print_table(laptops):
    header = f"| {'ID':<5} | {'Merk':<10} | {'Harga':<10} | {'Kategori':<10} | {'No. Seri':<10} | {'Tahun':<6} | {'Prosesor':<10} | {'RAM':<5} | {'Layar':<6} |"
    separator = "-" * len(header)
    print(f"\n{separator}\n{header}\n{separator}")
    for laptop in laptops:
        print(laptop.get_row())
    print(separator)

def main():
    # Pembuatan struktur data List sebagai penyimpan objek
    daftar_laptop = [
        Laptop("L01", "Apple", 15000000, "Laptop", "SN01", 2024, "M3", "8GB", "13.6"),
        Laptop("L02", "Lenovo", 12000000, "Laptop", "SN02", 2023, "Ryzen5", "16GB", "14.0"),
        Laptop("L03", "Asus", 18000000, "Laptop", "SN03", 2024, "Intel-i7", "16GB", "15.6"),
        Laptop("L04", "HP", 10000000, "Laptop", "SN04", 2022, "Intel-i5", "8GB", "14.0"),
        Laptop("L05", "Acer", 9500000, "Laptop", "SN05", 2023, "Ryzen3", "8GB", "14.0")
    ]

    # Input User dinamis
    n = int(input("Masukkan jumlah data tambahan (0 untuk skip): "))
    for i in range(n):
        print(f"\nData ke-{i+1}")
        id_p = input("ID: ")
        merk = input("Merk: ")
        harga = int(input("Harga: "))
        kat = input("Kategori: ")
        ns = input("No Seri: ")
        thn = int(input("Tahun: "))
        pros = input("Prosesor: ")
        ram = input("RAM: ")
        lyr = input("Layar: ")
        daftar_laptop.append(Laptop(id_p, merk, harga, kat, ns, thn, pros, ram, lyr))

    print_table(daftar_laptop)

    # EXPLICIT GARBAGE COLLECTION:
    # Menggunakan perintah 'del' untuk menurunkan nilai reference count objek ke 0.
    # Python GC akan membebaskan memori dengan sendirinya setelah reference hilang.
    del daftar_laptop
    print("\n[System] Garbage Collection complete. Objects destroyed.")

if __name__ == "__main__":
    main()