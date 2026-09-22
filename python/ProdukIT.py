# Base Class (Level 1)
class ProdukIT:
    def __init__(self, id_produk, merk, harga_dasar):
        # Name Mangling (__): Cara Python mensimulasikan modifier 'private' 
        # agar atribut tidak secara langsung terlihat dari luar kelas
        self.__id_produk = id_produk
        self.__merk = merk
        self.__harga_dasar = harga_dasar

    # Getters: Metode khusus mengambil data private
    def get_id_produk(self):
        return self.__id_produk
    def get_merk(self):
        return self.__merk
    def get_harga_dasar(self):
        return self.__harga_dasar

    # Setters: Metode khusus memodifikasi data private
    def set_id_produk(self, id_produk):
        self.__id_produk = id_produk
    def set_merk(self, merk):
        self.__merk = merk
    def set_harga_dasar(self, harga_dasar):
        self.__harga_dasar = harga_dasar