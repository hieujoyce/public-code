<div>Danh sach sinh vien trong lop</div>
<table>
  <tr>
    <th>Ten</th>
    <th>Dia chi</th>
    <th>Gioi tinh</th>
  </tr>
  <?php 
  include "libs/connectdb.php";
  $sql = "SELECT * FROM STUDENTS WHERE CLASSID='".$_GET["id"]."'";
  $result = $conn->query($sql);
  
  if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
      echo "<tr>";
      echo "<td>".$row["STUDENTNAME"]."</td><td>".$row["STUDENTADDRESS"]."</td><td>".$row["STUDENTGENDER"]."</td>";
      echo "</tr>";
    }
  } else {
    echo "0 results";
  }
  $conn->close();
?>

</table>