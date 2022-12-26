<div>List</div>


<table>
  <tr>
    <th>MAHS</th>
    <th>HOTEN</th>
    <th>NGAY SINH</th>
    <th>DIA CHI</th>
    <th>LOP</th>
    <th>DIEM TOAN</th>
    <th>DIEM LY</th>
    <th>DIEM HOA</th>
    <th>Thao tac</th>
  </tr>
  <?php
    include "connectdb.php";
    $sql = "SELECT * FROM HOSO";
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
          <a href='hoso.php?page=edit&id=".$value["MAHS"]."'>Edit</a>
          <a href='hoso.php?page=delete&id=".$value["MAHS"]."'>Delete</a>
        </td></tr>";
      echo "</tr>";
    }
    $conn->close();
  ?>
</table>