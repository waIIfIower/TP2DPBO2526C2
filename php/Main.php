<?php
// Memulai Session untuk menyimpan state/data agar tabel dinamis persisten
session_start();
require_once 'Laptop.php';

// Inisiasi 5 objek awal hanya terjadi jika session belum terbentuk
if (!isset($_SESSION['daftar_laptop'])) {
    $_SESSION['daftar_laptop'] = [
        new Laptop("L01", "Apple", 15000000, "img/apple.png", "Laptop", "SN01", 2024, "M3", "8GB", "13.6"),
        new Laptop("L02", "Lenovo", 12000000, "img/lenovo.png", "Laptop", "SN02", 2023, "Ryzen5", "16GB", "14.0"),
        new Laptop("L03", "Asus", 18000000, "img/asus.png", "Laptop", "SN03", 2024, "Intel-i7", "16GB", "15.6"),
        new Laptop("L04", "HP", 10000000, "img/hp.png", "Laptop", "SN04", 2022, "Intel-i5", "8GB", "14.0"),
        new Laptop("L05", "Acer", 9500000, "img/acer.png", "Laptop", "SN05", 2023, "Ryzen3", "8GB", "14.0")
    ];
}

// Blok logika untuk menangkap form submission POST dari user
if (isset($_POST['submit'])) {
    // Instansiasi objek baru berdasarkan data array $_POST
    $laptopBaru = new Laptop(
        $_POST['id'], $_POST['merk'], $_POST['harga'], $_POST['foto'],
        $_POST['kategori'], $_POST['seri'], $_POST['tahun'],
        $_POST['pros'], $_POST['ram'], $_POST['layar']
    );
    // Push objek baru ke dalam array list yang ada di session
    array_push($_SESSION['daftar_laptop'], $laptopBaru);
}
?>
<!DOCTYPE html>
<html>
<head><title>Data Laptop Ter-Enkapsulasi</title></head>
<body>
    <!-- User Interface untuk Form -->
    <h2>Form Tambah Laptop</h2>
    <form method="post" action="">
        ID: <input type="text" name="id" required> | 
        Merk: <input type="text" name="merk" required> | 
        Harga: <input type="number" name="harga" required> | 
        Link Foto: <input type="text" name="foto" required><br><br>
        Kategori: <input type="text" name="kategori" required> | 
        No Seri: <input type="text" name="seri" required> | 
        Tahun: <input type="number" name="tahun" required><br><br>
        Prosesor: <input type="text" name="pros" required> | 
        RAM: <input type="text" name="ram" required> | 
        Layar: <input type="text" name="layar" required><br><br>
        <button type="submit" name="submit">Tambah Data</button>
    </form>

    <hr>
    <!-- View untuk Tabel Dinamis -->
    <h2>Daftar Spesifikasi Laptop</h2>
    <table border="1" cellpadding="10" cellspacing="0">
        <tr>
            <th>ID</th><th>Foto</th><th>Merk</th><th>Harga</th>
            <th>Kategori</th><th>No. Seri</th><th>Tahun</th>
            <th>Prosesor</th><th>RAM</th><th>Layar</th>
        </tr>
        <?php
        // Iterasi foreach untuk mem-parsing setiap objek Laptop dan memanggil getRow
        foreach ($_SESSION['daftar_laptop'] as $laptop) {
            echo $laptop->getRow();
        }
        ?>
    </table>
</body>
</html>
<?php
// MANUAL GARBAGE COLLECTION PHP:
// Menghapus variabel temporary untuk melepaskan referensi di memori. 
// Zend Engine (Core PHP) akan mendeteksinya dan melakukan pembersihan.
if (isset($laptopBaru)) {
    unset($laptopBaru);
}
?>