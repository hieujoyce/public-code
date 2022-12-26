<div>Add</div>

<form action="" method="post" enctype="multipart/form-data">
  <b>Them thanh vien moi</b>
  <div>
    <label for="">Ma lop:</label>
    <input type="text" name="maLop">
  </div>
  <div>
    <label for="">Ten lop:</label>
    <input type="text" name="tenLop">
  </div>
  <div>
    <label for="">Khoa hoc:</label>
    <input type="text" name="khoaHoc">
  </div>
  <div>
    <label for="">GVCN:</label>
    <input type="text" name="gvcn">
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
      empty($_POST["maLop"]) || 
      empty($_POST["tenLop"]) || 
      empty($_POST["khoaHoc"]) || 
      empty($_POST["gvcn"])
    ) {
      return 0;
    }
    return 1;
  }
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(check() == 1) {
      $sql = "INSERT INTO LOP (MALOP, TENLOP, KHOAHOC, GVCN)
      VALUES ('".$_POST["maLop"]."', '".$_POST["tenLop"]."', '".$_POST["khoaHoc"]."', '".$_POST["gvcn"]."')";

      if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
      } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
      }
      $conn->close();
      header("location: lop.php?page=list");
    } else {
      echo "<p style='color: red'>Cac truong phai du thong tin</p>";
    }
  }
?>