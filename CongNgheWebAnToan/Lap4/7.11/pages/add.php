<div>Add</div>

<form action="" method="post" enctype="multipart/form-data">
  <b>Them thanh vien moi</b>
  <div>
    <label for="">Full name:</label>
    <input type="text" name="name">
  </div>
  <div>
    <label for="">Birthday:</label>
    <input type="text" name="birthday">
  </div>
  <div>
    <label for="">Address:</label>
    <input type="text" name="address">
  </div>
  <div>
    <label for="">Image:</label>
    <input type="file" name="image">
  </div>
  <div>
    <label for="">Class:</label>
    <input type="text" name="class">
  </div>
  <div>
    <button type="reset">Nhap lai</button>
    <button type="submit">Luu</button>
  </div>
</form>

<?php
  function check() {
    if(empty($_POST["name"]) || empty($_POST["birthday"]) || empty($_POST["address"]) || empty($_POST["class"]) || $_FILES["image"]['size'] == 0) {
      return 0;
    }
    return 1;
  }
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(check() == 1) {
      $el = "image";
      $target_dir = "images/";
      $target_file = $target_dir . basename($_FILES[$el]["name"]);
      move_uploaded_file($_FILES[$el]["tmp_name"], $target_file);

      $fp = fopen('pages/student.txt', 'a');
      fputs($fp, "\n".$_POST["name"]);
      fputs($fp, "\n".$_POST["birthday"]);
      fputs($fp, "\n".$_POST["address"]);
      fputs($fp, "\n".basename($_FILES[$el]["name"]));
      fputs($fp, "\n".$_POST["class"]);
      fclose($fp);
      echo "Ghi thanh cong.";

    } else {
      echo "<p style='color: red'>Cac truong khong duoc de trong</p>";
    }

  }
?>