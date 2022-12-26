<div>Delete</div>

<?php
  if(!empty($_GET["id"])) {
    include "connectdb.php";
    $sql = "DELETE FROM LOP WHERE MALOP='".$_GET["id"]."'";
    if ($conn->query($sql) === TRUE) {
      echo "Record deleted successfully";
    } else {
      echo "Error deleting record: " . $conn->error;
    }
    $conn->close();
  }
  header("Location: lop.php?page=list");
?>