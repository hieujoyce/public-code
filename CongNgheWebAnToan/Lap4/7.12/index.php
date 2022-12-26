<?php 
  session_start();
  if(!isset($_SESSION["lang"])) {
    $lang = "english";
  } else {
    $lang = $_SESSION["lang"];
  }
  require_once("./lang/".$lang.".php");
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(!empty($_POST["lang"])) {
      $_SESSION["lang"] = $_POST["lang"];
      if(!empty($_GET['page'])) {
        header("location: index.php?page=".$_GET['page']."");
      } else {
        header("location: index.php");
      }
    }
  }
?>

<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <link rel="stylesheet" href="./style.css">
  <script src="./main.js" defer></script>
</head>

<body>
  <header>
    <nav>
      <form id="formLang" action="" method="post" style="margin-right: 50px;">
        <input id="inputLang" hidden type="text" name="lang">
        <button data-page="vietnamese" type="button">Vietnamese</button>
        <button data-page="english" type="button">English</button>
      </form>
      <form id="form" action="" method="get">
        <input id="input" hidden type="text" name="page">
        <button data-page="home" type="button"><?php echo HOME ?></button>
        <button data-page="contact" type="button"><?php echo CONTACT ?></button>
      </form>
    </nav>
  </header>
  <main>
    <div class="left">
      Left
    </div>
    <div class="right">
      <div style="margin-bottom: 50px;"></div>
      <?php
        if(!empty($_GET['page'])) {
          switch($_GET['page']) {
            case "home":
              include_once("./pages/home.php");
              break;
            case "contact":
              include_once("./pages/contact.php");
              break; 
          }
        } else {
          echo "No page";
        }
      ?>
    </div>
  </main>
</body>

</html>