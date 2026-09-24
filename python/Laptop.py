from Hardware import Hardware

# Derived Class (Level 3)
class Laptop(Hardware):
    def __init__(self, id_produk, merk, harga_dasar, nomor_seri, tahun_rilis, jenis_prosesor, kapasitas_ram, ukuran_layar):
        # Meneruskan string "Laptop" secara otomatis ke konstruktor Hardware
        super().__init__(id_produk, merk, harga_dasar, "Laptop", nomor_seri, tahun_rilis)
        self.__jenis_prosesor = jenis_prosesor
        self.__kapasitas_ram = kapasitas_ram
        self.__ukuran_layar = ukuran_layar
        
    def get_jenis_prosesor(self): return self.__jenis_prosesor
    def set_jenis_prosesor(self, jenis_prosesor): self.__jenis_prosesor = jenis_prosesor

    def get_kapasitas_ram(self): return self.__kapasitas_ram
    def set_kapasitas_ram(self, kapasitas_ram): self.__kapasitas_ram = kapasitas_ram

    def get_ukuran_layar(self): return self.__ukuran_layar
    def set_ukuran_layar(self, ukuran_layar): self.__ukuran_layar = ukuran_layar
        
    def get_row(self, w):
        return f"| {self.get_id_produk():<{w[0]}} | {self.get_merk():<{w[1]}} | {self.get_harga_dasar():<{w[2]}} | {self.get_kategori():<{w[3]}} | {self.get_nomor_seri():<{w[4]}} | {self.get_tahun_rilis():<{w[5]}} | {self.get_jenis_prosesor():<{w[6]}} | {self.get_kapasitas_ram():<{w[7]}} | {self.get_ukuran_layar():<{w[8]}} |"