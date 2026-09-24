<?php
session_start();
require_once 'Laptop.php';

if (!isset($_SESSION['daftar_laptop'])) {
    $_SESSION['daftar_laptop'] = [
        new Laptop("L01", "Apple", 15000000, "img/apple.png", "SN01", 2024, "M3", "8GB", "13.6"),
        new Laptop("L02", "Lenovo", 12000000, "img/lenovo.png", "SN02", 2023, "Ryzen5", "16GB", "14.0"),
        new Laptop("L03", "Asus", 18000000, "img/asus.png", "SN03", 2024, "Intel-i7", "16GB", "15.6"),
        new Laptop("L04", "HP", 10000000, "img/hp.png", "SN04", 2022, "Intel-i5", "8GB", "14.0"),
        new Laptop("L05", "Acer", 9500000, "img/acer.png", "SN05", 2023, "Ryzen3", "8GB", "14.0")
    ];
}

$errorMessage = "";

if (isset($_POST['submit'])) {
    // Validasi:
    // 1. !is_numeric($_POST['harga']) -> Harga harus angka
    // 2. !is_numeric($_POST['tahun']) -> Tahun harus angka
    // 3. is_numeric($_POST['merk']) -> Merk TIDAK boleh angka murni
    if (!is_numeric($_POST['harga']) || !is_numeric($_POST['tahun']) || is_numeric($_POST['merk'])) {
        $errorMessage = "input salah";
    } else {
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
        array_push($_SESSION['daftar_laptop'], $laptopBaru);
    }
}
?>
<!DOCTYPE html>
<html>
<head><title>Data Laptop</title></head>
<body>
    <h2>Form Tambah Laptop</h2>
    
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
        Layar: <input type="text" name="layar" required><br><br>
        <button type="submit" name="submit">Tambah Data</button>
    </form>

    <hr>
    <h2>Daftar Spesifikasi Laptop</h2>
    <table border="1" cellpadding="10" cellspacing="0">
        <tr>
            <th>ID</th><th>Foto</th><th>Merk</th><th>Harga</th>
            <th>Kategori</th><th>No. Seri</th><th>Tahun</th>
            <th>Prosesor</th><th>RAM</th><th>Layar</th>
        </tr>
        <?php
        foreach ($_SESSION['daftar_laptop'] as $laptop) {
            echo $laptop->getRow();
        }
        ?>
    </table>
</body>
</html>
<?php
if (isset($laptopBaru)) { unset($laptopBaru); }
?>