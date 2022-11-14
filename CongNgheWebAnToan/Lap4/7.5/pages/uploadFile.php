<div>Up load file</div>
<form action="" method="post" enctype="multipart/form-data">
  <?php 
      for ($i=0; $i < 10; $i++) {
        echo "<div>"; 
        echo "<label for=''>File ".$i.": </label>";
        echo "<input type='file' name='file-".$i."'>";
        echo "</div>";
      }
  ?>
  <div>
    <button type="reset">Reset</button>
    <button type="submit">Upload</button>
  </div>
</form>

<div style="margin-top: 20px;">
  <?php 
  function check() {
    for ($i=0; $i < 10; $i++) { 
      $el = "file-".$i;
      if ($_FILES[$el]['size'] == 0) {
        return 0;
      }
    }
    return 1;
  }

  if ($_SERVER["REQUEST_METHOD"] == "POST" && check() == 1) {
    for ($i=0; $i < 10; $i++) { 
      $el = "file-".$i;
      $target_dir = "uploads/";
      $target_file = $target_dir . basename($_FILES[$el]["name"]);
      
      move_uploaded_file($_FILES[$el]["tmp_name"], $target_file);

      echo "<a style='display: block;' href=?page=uploadFile&file=".basename($_FILES[$el]["name"])." >Download file: ".basename($_FILES[$el]["name"])."</a>";
    }
  }
?>
</div>

<?php 
  if(!empty($_GET["file"])) {
    $fileName = basename($_GET["file"]);
    $target_file = "uploads/".$fileName;
    if(!empty($fileName) && file_exists($target_file)) {
      header('Content-Description: File Transfer');
      header('Content-Type: application/octet-stream');
      header("Content-Disposition: attachment; filename=$fileName");
      header('Expires: 0');
      header('Cache-Control: must-revalidate');
      header('Pragma: public');
      header('Content-Length: ' . filesize($target_file));

      readfile(($target_file));
      exit;
    } else {
      echo "file not exit";
    }
  }
?>