<div>Edit</div>

<?php 
  $name = $birthday = $address = $image = $class = "";
  if(!empty($_GET["id"])) {
    $id = (int)$_GET["id"];
    $fp = fopen("pages/student.txt", "r");
    $i = 0;
    while(!feof($fp)) {
      $i++;
      if(ceil($i / 5) == (int)$_GET["id"]) {
        if($i % 5 == 1) {
          $name = fgets($fp);
        } else if ($i % 5 == 2) {
          $birthday = fgets($fp);
        } else if ($i % 5 == 3) {
          $address = fgets($fp);
        } else if ($i % 5 == 4) {
          $image = fgets($fp);
        } else if ($i % 5 == 0) {
          $class = fgets($fp);
        }
      } else {
        fgets($fp);
      }
    }
    fclose($fp);
  } else {
    echo "No id params";
  }
?>

<form action="" method="post" enctype="multipart/form-data">
  <b>Edit thanh vien</b>
  <div>
    <label for="">Full name:</label>
    <input type="text" name="name" value="<?php echo $name ?>">
  </div>
  <div>
    <label for="">Birthday:</label>
    <input type="text" name="birthday" value="<?php echo $birthday ?>">
  </div>
  <div>
    <label for="">Address:</label>
    <input type="text" name="address" value="<?php echo $address ?>">
  </div>
  <div>
    <label for="">Image:</label>
    <input type="file" name="image">
  </div>
  <div>
    <label for="">Class:</label>
    <input type="text" name="class" value="<?php echo $class ?>">
  </div>
  <div>
    <button type="reset">Nhap lai</button>
    <button type="submit">Luu</button>
  </div>
</form>

<?php
  //

  $index = 0;
  $content = "";
  function myEdit($i, $ctx) {
    global $index, $content;
    $index = $i;
    $content = $ctx;
    $data = file('pages/student.txt');
    $data = array_map(function ($data, $i) {
      global $index, $content;
      return $index == $i + 1 ? $content."\n" : $data;
    },$data, array_keys($data));
    
    file_put_contents('pages/student.txt', $data);
  }
  function check() {
    global $name, $birthday, $address, $class;
    if(empty($_POST["name"]) || empty($_POST["birthday"]) || empty($_POST["address"]) || empty($_POST["class"])) {
      return 0;
    }
    if(
      $_POST["name"] == $name &&
      $_POST["birthday"] == $birthday &&
      $_POST["address"] == $address &&
      $_POST["class"] == $class && 
      $_FILES["image"]['size'] == 0
    ) {
      return 0;
    }
    return 1;
  }
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(check() == 1) {
      if($_FILES["image"]['size'] != 0) {
        $el = "image";
        $target_dir = "images/";
        $target_file = $target_dir . basename($_FILES[$el]["name"]);
        move_uploaded_file($_FILES[$el]["tmp_name"], $target_file);
      }
      $y = ($id - 1) * 5;
      if($_POST["name"] != $name) {
        myEdit($y + 1, $_POST["name"]);
      }
      if($_POST["birthday"] != $birthday) {
        myEdit($y + 2, $_POST["birthday"]);
      }
      if($_POST["address"] != $address) {
        myEdit($y + 3, $_POST["address"]);
      }
      if($_FILES["image"]['size'] != 0) {
        myEdit($y + 4, basename($_FILES["image"]["name"]));
      }
      if($_POST["class"] != $class) {
        myEdit($y + 5, $_POST["class"]);
      }
      echo "Sua thanh cong.";
      header("Location: index.php?page=list");
    } else {
      echo "<p style='color: red'>Cac truong khong duoc de trong hoac phai thay doi</p>";
    }

  }
?>