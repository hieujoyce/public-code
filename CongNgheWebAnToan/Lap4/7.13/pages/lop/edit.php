<div>Edit</div>

<?php 
  $tenLop = $khoaHoc = $gvcn = "";
  include "connectdb.php";
  if(!empty($_GET["id"])) {
    $sql = "Select * FROM LOP WHERE MALOP='".$_GET["id"]."'";
    $result = $conn->query($sql);
    if ($result->num_rows > 0) {
      $row = $result->fetch_assoc();
      $tenLop = $row["TENLOP"];
      $khoaHoc = $row["KHOAHOC"];
      $gvcn = $row["GVCN"];
    }
  }
?>

<form action="" method="post">
  <b>Chinh sua</b>
  <div>
    <label for="">Ten lop:</label>
    <input type="text" name="tenLop" value="<?php echo $tenLop ?>">
  </div>
  <div>
    <label for="">Khoa hoc:</label>
    <input type="text" name="khoaHoc" value="<?php echo $khoaHoc ?>">
  </div>
  <div>
    <label for="">GVCN:</label>
    <input type="text" name="gvcn" value="<?php echo $gvcn ?>">
  </div>
  <div>
    <button type="reset">Reset</button>
    <button type="submit">Submit</button>
  </div>
</form>

<?php
  function check() {
    if(
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
      $sql = "UPDATE LOP SET 
      TENLOP='".$_POST["tenLop"]."', 
      KHOAHOC='".$_POST["khoaHoc"]."', 
      GVCN='".$_POST["gvcn"]."'
      WHERE MALOP='".$_GET["id"]."'";

      if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
      } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
      }
      header("location: lop.php?page=list");
    } else {
      echo "<p style='color: red'>Cac truong phai du thong tin</p>";
    }
  }
  $conn->close();
?>