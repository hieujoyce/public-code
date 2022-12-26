<div>Edit</div>

<?php 
  $hoTen = $ngaySinh = $diaChi = $lop = $diemToan = $diemLy = $diemHoa = "";
  include "connectdb.php";
  if(!empty($_GET["id"])) {
    $sql = "Select * FROM HOSO WHERE MAHS='".$_GET["id"]."'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
      $row = $result->fetch_assoc();
      $hoTen = $row["HOTEN"];
      $ngaySinh = $row["NGAYSINH"];
      $diaChi = $row["DIACHI"];
      $lop = $row["LOP"];
      $diemToan = $row["DIEMTOAN"];
      $diemLy = $row["DIEMLY"];
      $diemHoa = $row["DIEMHOA"];
    }
  }
?>

<form action="" method="post">
  <b>Chinh sua thanh vien</b>
  <div>
    <label for="">Ho ten:</label>
    <input type="text" name="hoTen" value="<?php echo $hoTen ?>">
  </div>
  <div>
    <label for="">Ngay sinh:</label>
    <input type="text" name="ngaySinh" value="<?php echo $ngaySinh ?>">
  </div>
  <div>
    <label for="">Dia chi:</label>
    <input type="text" name="diaChi" value="<?php echo $diaChi ?>">
  </div>
  <div>
    <label for="">lop:</label>
    <input type="text" name="lop" value="<?php echo $lop ?>">
  </div>
  <div>
    <label for="">Diem Toan:</label>
    <input type="text" name="diemToan" value="<?php echo $diemToan ?>">
  </div>
  <div>
    <label for="">Diem Ly:</label>
    <input type="text" name="diemLy" value="<?php echo $diemLy ?>">
  </div>
  <div>
    <label for="">Diem Hoa:</label>
    <input type="text" name="diemHoa" value="<?php echo $diemHoa ?>">
  </div>
  <div>
    <button type="reset">Reset</button>
    <button type="submit">Submit</button>
  </div>
</form>

<?php 

  function check() {
    if(
      empty($_POST["hoTen"]) || 
      empty($_POST["ngaySinh"]) || 
      empty($_POST["diemToan"]) || 
      empty($_POST["diemLy"]) || 
      empty($_POST["diemHoa"]) || 
      empty($_POST["diaChi"]) ||
      empty($_POST["lop"])
    ) {
      return 0;
    }
    return 1;
  }
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(check() == 1) {
      $sql = "UPDATE HOSO SET 
      HOTEN='".$_POST["hoTen"]."', 
      NGAYSINH='".$_POST["ngaySinh"]."', 
      DIACHI='".$_POST["diaChi"]."', 
      LOP='".$_POST["lop"]."', 
      DIEMTOAN='".$_POST["diemToan"]."', 
      DIEMLY='".$_POST["diemLy"]."', 
      DIEMHOA='".$_POST["diemHoa"]."' 
      WHERE MAHS='".$_GET["id"]."'";

      if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
      } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
      }
      header("location: hoso.php?page=list");
    } else {
      echo "<p style='color: red'>Cac truong phai du thong tin</p>";
    }
  }
  $conn->close();
?>