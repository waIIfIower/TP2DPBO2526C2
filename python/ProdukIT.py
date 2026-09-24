# Base Class (Level 1)
class ProdukIT:
    def __init__(self, id_produk, merk, harga_dasar):
        # Name mangling (__): Properti privat
        self.__id_produk = id_produk
        self.__merk = merk
        self.__harga_dasar = harga_dasar

    def get_id_produk(self): return self.__id_produk
    def set_id_produk(self, id_produk): self.__id_produk = id_produk

    def get_merk(self): return self.__merk
    def set_merk(self, merk): self.__merk = merk

    def get_harga_dasar(self): return self.__harga_dasar
    def set_harga_dasar(self, harga_dasar): self.__harga_dasar = harga_dasar