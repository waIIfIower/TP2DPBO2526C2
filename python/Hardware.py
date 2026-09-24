from ProdukIT import ProdukIT

# Intermediary Class (Level 2)
class Hardware(ProdukIT):
    def __init__(self, id_produk, merk, harga_dasar, kategori, nomor_seri, tahun_rilis):
        super().__init__(id_produk, merk, harga_dasar)
        self.__kategori = kategori
        self.__nomor_seri = nomor_seri
        self.__tahun_rilis = tahun_rilis

    def get_kategori(self): return self.__kategori
    def set_kategori(self, kategori): self.__kategori = kategori

    def get_nomor_seri(self): return self.__nomor_seri
    def set_nomor_seri(self, nomor_seri): self.__nomor_seri = nomor_seri

    def get_tahun_rilis(self): return self.__tahun_rilis
    def set_tahun_rilis(self, tahun_rilis): self.__tahun_rilis = tahun_rilis