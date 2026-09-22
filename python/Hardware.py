from ProdukIT import ProdukIT

# Intermediary Class (Level 2) - Mewarisi kelas ProdukIT
class Hardware(ProdukIT):
    def __init__(self, id_produk, merk, harga_dasar, kategori, nomor_seri, tahun_rilis):
        # super() digunakan untuk memanggil fungsi __init__ dari kelas induk
        super().__init__(id_produk, merk, harga_dasar)
        self.__kategori = kategori
        self.__nomor_seri = nomor_seri
        self.__tahun_rilis = tahun_rilis

    # Getters
    def get_kategori(self):
        return self.__kategori
    def get_nomor_seri(self):
        return self.__nomor_seri
    def get_tahun_rilis(self):
        return self.__tahun_rilis

    # Setters
    def set_kategori(self, kategori):
        self.__kategori = kategori
    def set_nomor_seri(self, nomor_seri):
        self.__nomor_seri = nomor_seri
    def set_tahun_rilis(self, tahun_rilis):
        self.__tahun_rilis = tahun_rilis