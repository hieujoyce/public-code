<div>Detail</div>

<b>Chi tiet Sinh vien</b>
<?php 
  if(!empty($_GET["id"])) {
    $name = $birthday = $address = $image = $class = "";
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

    echo "
    <div class='detail'>
      <div><img src='images/".$image."'></div>
      <div>
        <p>".$name."</p>
        <p>".$birthday."</p>
        <p>".$address."</p>
        <p>".$class."</p>
      </div>
    </div>
    ";
    fclose($fp);
  } else {
    echo "No id params";
  }
?>