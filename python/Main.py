from Laptop import Laptop

def print_table(laptops):
    w = [2, 4, 5, 8, 8, 5, 8, 3, 5]
    
    for l in laptops:
        w[0] = max(w[0], len(l.get_id_produk()))
        w[1] = max(w[1], len(l.get_merk()))
        w[2] = max(w[2], len(str(l.get_harga_dasar())))
        w[3] = max(w[3], len(l.get_kategori()))
        w[4] = max(w[4], len(l.get_nomor_seri()))
        w[5] = max(w[5], len(str(l.get_tahun_rilis())))
        w[6] = max(w[6], len(l.get_jenis_prosesor()))
        w[7] = max(w[7], len(l.get_kapasitas_ram()))
        w[8] = max(w[8], len(l.get_ukuran_layar()))
        
    separator = "-" * (sum(w) + 28)
    header = f"| {'ID':<{w[0]}} | {'Merk':<{w[1]}} | {'Harga':<{w[2]}} | {'Kategori':<{w[3]}} | {'No. Seri':<{w[4]}} | {'Tahun':<{w[5]}} | {'Prosesor':<{w[6]}} | {'RAM':<{w[7]}} | {'Layar':<{w[8]}} |"
    
    print(f"\n{separator}\n{header}\n{separator}")
    for l in laptops:
        print(l.get_row(w))
    print(separator)

def main():
    daftar_laptop = [
        Laptop("L01", "Apple", 15000000, "SN01", 2024, "M3", "8GB", "13.6"),
        Laptop("L02", "Lenovo", 12000000, "SN02", 2023, "Ryzen5", "16GB", "14.0"),
        Laptop("L03", "Asus", 18000000, "SN03", 2024, "Intel-i7", "16GB", "15.6"),
        Laptop("L04", "HP", 10000000, "SN04", 2022, "Intel-i5", "8GB", "14.0"),
        Laptop("L05", "Acer", 9500000, "SN05", 2023, "Ryzen3", "8GB", "14.0")
    ]

    while True:
        try:
            n = int(input("Masukkan jumlah data tambahan (0 untuk skip): "))
            break 
        except ValueError:
            print("input salah")

    for i in range(n):
        print(f"\nData ke-{i+1}")
        id_p = input("ID: ")
        
        # Validasi Merk: Menolak input jika isdigit() bernilai True
        while True:
            merk = input("Merk: ")
            if merk.isdigit():
                print("input salah")
            else:
                break
        
        # Validasi Harga: Int Python aman mengelola angka besar
        while True:
            try:
                harga = int(input("Harga: "))
                break 
            except ValueError:
                print("input salah") 
                
        ns = input("No Seri: ")
        
        while True:
            try:
                thn = int(input("Tahun: "))
                break
            except ValueError:
                print("input salah")
                
        pros = input("Prosesor: ")
        ram = input("RAM: ")
        lyr = input("Layar: ")
        
        daftar_laptop.append(Laptop(id_p, merk, harga, ns, thn, pros, ram, lyr))

    print_table(daftar_laptop)
    del daftar_laptop

if __name__ == "__main__":
    main()