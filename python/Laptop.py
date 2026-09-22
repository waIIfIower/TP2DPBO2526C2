from Hardware import Hardware

# Derived Class (Level 3)
class Laptop(Hardware):
    def __init__(self, id_produk, merk, harga_dasar, kategori, nomor_seri, tahun_rilis, jenis_prosesor, kapasitas_ram, ukuran_layar):
        # Delegasi ke kelas Hardware
        super().__init__(id_produk, merk, harga_dasar, kategori, nomor_seri, tahun_rilis)
        self.__jenis_prosesor = jenis_prosesor
        self.__kapasitas_ram = kapasitas_ram
        self.__ukuran_layar = ukuran_layar
        
    # Getters
    def get_jenis_prosesor(self):
        return self.__jenis_prosesor
    def get_kapasitas_ram(self):
        return self.__kapasitas_ram
    def get_ukuran_layar(self):
        return self.__ukuran_layar

    # Setters
    def set_jenis_prosesor(self, jenis_prosesor):
        self.__jenis_prosesor = jenis_prosesor
    def set_kapasitas_ram(self, kapasitas_ram):
        self.__kapasitas_ram = kapasitas_ram
    def set_ukuran_layar(self, ukuran_layar):
        self.__ukuran_layar = ukuran_layar
        
    # Fungsi pembantu untuk mengembalikan string data berformat tabel
    def get_row(self):
        return f"| {self.get_id_produk():<5} | {self.get_merk():<10} | {self.get_harga_dasar():<10} | {self.get_kategori():<10} | {self.get_nomor_seri():<10} | {self.get_tahun_rilis():<6} | {self.get_jenis_prosesor():<10} | {self.get_kapasitas_ram():<5} | {self.get_ukuran_layar():<6} |"