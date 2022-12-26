<div>List</div>


<table>
  <tr>
    <th>MALOP</th>
    <th>TENLOP</th>
    <th>KHOAHOC</th>
    <th>GVCN</th>
    <th>Thao tac</th>
  </tr>
  <?php
    include "connectdb.php";
    $sql = "SELECT * FROM LOP";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
      // output data of each row
      $index = 0;
      while($row = $result->fetch_assoc()) {
        $hosoList[$index] = $row;
        $index++;
      }
    } else {
      echo "0 results";
    } 
    foreach($hosoList as $key=>$value) {
      echo "<tr>";
      foreach($value as $key1=>$value1) {
        echo "<td>";
        echo $value1;
        echo "</td>";
      }
      echo "<td>
          <a href='lop.php?page=edit&id=".$value["MALOP"]."'>Edit</a>
          <a href='lop.php?page=delete&id=".$value["MALOP"]."'>Delete</a>
        </td></tr>";
      echo "</tr>";
    }
  ?>
</table>