<div>List Class</div>

<?php 
  include("libs/connectdb.php");
  $sql = "SELECT * FROM CLASSES";
  $result = $conn->query($sql);
  
  if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
      echo "<div><a href='index.php?page=listStdInClass&id=".$row["ID"]."'>".$row["CLASSNAME"]."</a></div>";
    }
  } else {
    echo "0 results";
  }
  $conn->close();
?>