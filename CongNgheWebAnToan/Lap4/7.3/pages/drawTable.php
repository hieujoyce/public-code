<div>Trang Draw Table</div>
<form id="formVe" action="" method="POST">
  <p>Form ve bang</p>
  <div>
    <label for="soDong">So dong: </label>
    <input type="text" name="soDong">
  </div>
  <div>
    <label for="soCot">So cot: </label>
    <input type="text" name="soCot">
  </div>
  <div>
    <button type="reset">Nhap lai</button>
    <button type="submit">Ve</button>
  </div>
</form>

<?php 
  if( !empty($_POST['soDong']) && !empty($_POST['soCot']) ) {
    echo "<table style='width:100%';>";
    for ($i = 0; $i < (int)$_POST['soDong']; $i++) {
      echo "<tr>";
      for ($j = 0; $j < (int)$_POST['soCot']; $j++) {
        echo "<td>",$j + 1,"</td>";
      }
      echo "</tr>";
    }

    echo "</table>";
  }
?>