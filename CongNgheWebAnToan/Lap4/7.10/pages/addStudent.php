<div>Add Student</div>
<form action="" id="form1" method="post">
  <b>Them sinh vien moi</b>
  <div>
    <label for="">Ten:</label>
    <input type="text" name="ten">
  </div>
  <div>
    <label for="">Dia chi:</label>
    <input type="text" name="diaChi">
  </div>
  <div>
    <label for="">Tuoi:</label>
    <input type="text" name="tuoi">
  </div>
  <div>
    <button type="reset">Nhap lai</button>
    <button type="submit">Ghi</button>
  </div>
</form>

<?php 
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(empty($_POST["ten"]) || empty($_POST["diaChi"]) || empty($_POST["tuoi"])) {
      echo "<p style='color: red'>Cac truong ko duoc de thieu</p>";
    } else {
      $fp = fopen('student.txt', 'a');
      fputs($fp, "\n".$_POST["ten"]);
      fputs($fp, "\n".$_POST["diaChi"]);
      fputs($fp, "\n".$_POST["tuoi"]);
      fclose($fp);
      echo "Ghi thanh cong.";
    }
  }
?>