<div>List Student</div>
<table>
  <tr>
    <th>STT</th>
    <th>Ten</th>
    <th>Dia chi</th>
    <th>Tuoi</th>
  </tr>
  <?php 
    $fp = fopen("student.txt", "r");
    $i = 0;
    while(! feof($fp)) {
      $i++;
      if($i % 3 == 1) {
        echo "<tr><td>".ceil($i / 3)."</td>";
      }
      echo "<td>".fgets($fp)."</td>";
      if($i %3 == 0) {
        echo "</tr>";
      }
    }
    
    fclose($fp);
  ?>
</table>