<?php 
  $nameErr = $classErr = $m1Err = $m2Err = $m3Err = "";

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(empty($_POST["name"])) {
      $nameErr = "Truong nay ko duoc de trong";
    }
    if(empty($_POST["class"])) {
      $classErr = "Truong nay ko duoc de trong";
    }
    if(empty($_POST["m1"])) {
      $m1Err = "Truong nay ko duoc de trong";
    } else if (is_numeric($_POST["m1"]) != 1) {
      $m1Err = "Truong nay phai la kieu so";
    }
    if(empty($_POST["m2"])) {
      $m2Err = "Truong nay ko duoc de trong";
    } else if (is_numeric($_POST["m2"]) != 1) {
      $m2Err = "Truong nay phai la kieu so";
    }
    if(empty($_POST["m3"])) {
      $m3Err = "Truong nay ko duoc de trong";
    } else if (is_numeric($_POST["m3"]) != 1) {
      $m3Err = "Truong nay phai la kieu so";
    }
  }
?>

<form action="" method="post">
  <div>
    <label for="name">Ho va ten</label>
    <input type="text" name="name">
    <small style="color: red;"><?php echo $nameErr ?></small>
  </div>
  <div>
    <label for="class">Lop</label>
    <input type="text" name="class">
    <small style="color: red;"><?php echo $classErr ?></small>
  </div>
  <div>
    <label for="m1">Diem M1</label>
    <input type="text" name="m1">
    <small style="color: red;"><?php echo $m1Err ?></small>
  </div>
  <div>
    <label for="m2">Diem M2</label>
    <input type="text" name="m2">
    <small style="color: red;"><?php echo $m2Err ?></small>
  </div>
  <div>
    <label for="m3">Diem M3</label>
    <input type="text" name="m3">
    <small style="color: red;"><?php echo $m3Err ?></small>
  </div>
  <div>
    <label for="tongDiem">Tong diem</label>
    <input type="text" name="tongDiem" readonly>
  </div>

  <div>
    <button type="submit">Ok</button>
    <button type="reset" style="margin-left: 15px;">Cancel</button>
  </div>
</form>

<?php 
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(empty($nameErr) && empty($classErr) && empty($m1Err) && empty($m2Err) && empty($m3Err)) {
      echo "Tong la ", (int)($_POST["m1"]) + (int)($_POST["m2"]) + (int)($_POST["m3"]);
    }
  }
?>