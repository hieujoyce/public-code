<?php 
  require_once("libs/math.php");
?>
<p>Thao tac tren mang 1 chieu</p>
<p>Bai toan: nhap vao chuoi so, tinh tong cac so, gia tri trung binh, tim min, max, trung binh cong</p>
<form id="ar1Chieu" action="" method="post">
  <div style="display: flex;">
    <?php 
      for ($i=0; $i < 10; $i++) { 
        echo "<input name='input-",$i,"' type='text'>";
      }
    ?>
  </div>
  <div style="display: flex; justify-content: flex-end;">
    <button type="reset">Reset</button>
    <button type="submit">Calculate</button>
  </div>
</form>
<!-- <input type="text"> -->
<?php
  function check() {
    for ($i=0; $i < 10; $i++) {
      $el = "input-".$i;
      if(empty($_POST[$el])) {
        return 0;
      }
    }
    return 1;
  }
  $tong = $tb = $min = $max = 0;
  if ($_SERVER["REQUEST_METHOD"] == "POST" && check() == 1) {
    $tong = mySum("input-");
    $min = myMin("input-");
    $max = myMax("input-");
    $tb = myAvg($tong, 10);
  }
?>

<h3>KET QUA:</h3>
<p>Tong: <?php echo $tong ?></p>
<p>Trung binh: <?php echo $tb ?></p>
<p>Min: <?php echo $min ?></p>
<p>Max: <?php echo $max ?></p>