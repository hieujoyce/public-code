<div>List</div>

<table>
  <tr>
    <th>STT</th>
    <th>Ten</th>
    <th>Ngay sinh</th>
    <th>Dia chi</th>
    <th>Anh</th>
    <th>Lop</th>
    <th>Thao tac</th>
  </tr>
  <?php 
    $fp = fopen("pages/student.txt", "r");
    $i = 0;
    while(!feof($fp)) {
      $i++;
      $a = fgets($fp);
      if($a != "") {
        if($i % 5 == 1) {
          echo "<tr><td>".ceil($i / 5)."</td>";
        }
        if($i % 5 == 4) {
          echo "<td><img src='images/".$a."'></td>";
        } else {
          echo "<td>".$a."</td>";
        }
        if($i % 5 == 0) {
          echo "<td>
          <a href='index.php?page=detail&id=".ceil($i / 5)."'>Detail</a>
          <a href='index.php?page=edit&id=".ceil($i / 5)."'>Edit</a>
          <a href='index.php?page=delete&id=".ceil($i / 5)."'>Delete</a>
        </td></tr>";
        }
      }
    }
    
    fclose($fp);
  ?>
</table>