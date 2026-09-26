<?php
// agar PHP mengenali struktur objek saat menarik data dari memori browser.
require_once 'Laptop.php';
session_start(); 

// 1. BASE DATA: Selalu diinisiasi ulang dan dijamin selalu muncul
$base_laptop = [
    new Laptop("L01", "Apple", 15000000, "img/apple.png", "SN01", 2024, "M3", "8GB", "13.6'"),
    new Laptop("L02", "Lenovo", 12000000, "img/lenovo.png", "SN02", 2023, "Ryzen5", "16GB", "14.0'"),
    new Laptop("L03", "Asus", 18000000, "img/asus.png", "SN03", 2024, "Intel-i7", "16GB", "15.6'"),
    new Laptop("L04", "HP", 10000000, "img/hp.png", "SN04", 2022, "Intel-i5", "8GB", "14.0'"),
    new Laptop("L05", "Acer", 9500000, "img/acer.png", "SN05", 2023, "Ryzen3", "8GB", "14.0'")
];

// 2. DATA TAMBAHAN: Menyiapkan wadah jika user belum pernah menambah data
if (!isset($_SESSION['data_tambahan'])) {
    $_SESSION['data_tambahan'] = [];
}

$errorMessage = "";

// Controller Logic: Menangkap Input Form
if (isset($_POST['submit'])) {
    // Validasi Error Handling Spesifik
    if (is_numeric($_POST['merk'])) {
        $errorMessage = "(Error: Menolak angka murni pada atribut merk)";
    } elseif (!is_numeric($_POST['harga'])) {
        $errorMessage = "(Error: Menolak kehadiran huruf pada harga)";
    } elseif (!is_numeric($_POST['tahun'])) {
        $errorMessage = "(Error: Menolak kehadiran huruf pada tahun)";
    } else {
        // Objek baru diciptakan berdasarkan input form
        $laptopBaru = new Laptop(
            $_POST['id'], 
            $_POST['merk'], 
            $_POST['harga'], 
            $_POST['foto'],
            $_POST['seri'], 
            (int)$_POST['tahun'], 
            $_POST['pros'], 
            $_POST['ram'], 
            $_POST['layar'] 
        );
        // Memasukkan data baru ke dalam session secara permanen
        array_push($_SESSION['data_tambahan'], $laptopBaru);
    }
}

// 3. PENGGABUNGAN DATA: Menyatukan 5 Base Data dengan Data Tambahan user
$semua_laptop = array_merge($base_laptop, $_SESSION['data_tambahan']);
?>
<!DOCTYPE html>
<html>
<head><title>Data Laptop</title></head>
<body>
    <h2>Form Tambah Laptop</h2>
    
    <!-- Render Error Label Form yang Spesifik -->
    <?php if ($errorMessage != ""): ?>
        <div style="color: red; font-weight: bold; margin-bottom: 15px;">
            <?php echo $errorMessage; ?>
        </div>
    <?php endif; ?>

    <form method="post" action="">
        ID: <input type="text" name="id" required> | 
        Merk: <input type="text" name="merk" required> | 
        Harga: <input type="text" name="harga" required> | 
        Link Foto: <input type="text" name="foto" required><br><br>
        No Seri: <input type="text" name="seri" required> | 
        Tahun: <input type="text" name="tahun" required><br><br>
        Prosesor: <input type="text" name="pros" required> | 
        RAM: <input type="text" name="ram" required> | 
        Ukuran Layar: <input type="text" name="layar" required><br><br>
        <button type="submit" name="submit">Tambah Data</button>
    </form>

    <hr>
    <h2>Daftar Spesifikasi Laptop</h2>
    <table border="1" cellpadding="10" cellspacing="0">
        <tr>
            <th>ID</th><th>Foto</th><th>Merk</th><th>Harga</th>
            <th>Kategori</th><th>No. Seri</th><th>Tahun</th>
            <th>Prosesor</th><th>RAM</th><th>Ukuran Layar</th>
        </tr>
        <?php
        // Melakukan iterasi dari gabungan data dasar dan data tambahan
        foreach ($semua_laptop as $laptop) {
            echo $laptop->getRow();
        }
        ?>
    </table>
</body>
</html>
<?php
// Pelepasan objek sementara dari memori saat runtime selesai
if (isset($laptopBaru)) { unset($laptopBaru); }
?>