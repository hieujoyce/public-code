<div>Add</div>

<form action="" method="post">
  <b>Them thanh vien moi</b>
  <div>
    <label for="">MA HS:</label>
    <input type="text" name="mahs">
  </div>
  <div>
    <label for="">Ho ten:</label>
    <input type="text" name="hoTen">
  </div>
  <div>
    <label for="">Ngay sinh:</label>
    <input type="text" name="ngaySinh">
  </div>
  <div>
    <label for="">Dia chi:</label>
    <input type="text" name="diaChi">
  </div>
  <div>
    <label for="">lop:</label>
    <input type="text" name="lop">
  </div>
  <div>
    <label for="">Diem Toan:</label>
    <input type="text" name="diemToan">
  </div>
  <div>
    <label for="">Diem Ly:</label>
    <input type="text" name="diemLy">
  </div>
  <div>
    <label for="">Diem Hoa:</label>
    <input type="text" name="diemHoa">
  </div>
  <div>
    <button type="reset">Reset</button>
    <button type="submit">Submit</button>
  </div>
</form>

<?php
  include "connectdb.php";
  function check() {
    if(
      empty($_POST["mahs"]) || 
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
      $sql = "INSERT INTO HOSO (MAHS, HOTEN, NGAYSINH, DIACHI, LOP, DIEMTOAN, DIEMLY, DIEMHOA)
      VALUES ('".$_POST["mahs"]."', '".$_POST["hoTen"]."', '".$_POST["ngaySinh"]."', '".$_POST["diaChi"]."', '".$_POST["lop"]."', '".$_POST["diemToan"]."', '".$_POST["diemLy"]."', '".$_POST["diemHoa"]."')";

      if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
      } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
      }
      $conn->close();
      header("location: hoso.php?page=list");
    } else {
      echo "<p style='color: red'>Cac truong phai du thong tin</p>";
    }
  }
?>