<div>Delete</div>

<?php
  function myDelete($index) {
    $data = file('pages/student.txt');
    array_splice($data, $index, 1);
    file_put_contents('pages/student.txt', $data);
  }
  if(!empty($_GET["id"])) {
    $id = ((int)$_GET["id"] - 1) * 5;
    for ($i=0; $i < 5; $i++) { 
      myDelete($id);
    }
  }
  header("Location: index.php?page=list");
?>