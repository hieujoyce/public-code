<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <link rel="stylesheet" href="../style.css">
  <script src="../main.js" defer></script>
</head>

<body>
  <header>
    <nav></nav>
  </header>
  <main>
    <div class="left">
      <form id="form" action="" method="get" style="display: flex; flex-direction: column; padding: 10px; gap: 10px;">
        <input id="input" hidden type="text" name="page">
        <a href="../index.php?page=home">Return Home</a>
        <button data-page="home" type="button">Admin Home</button>
        <button data-page="logout" type="button">Logout</button>
        <button data-page="upload" type="button">Upload</button>
      </form>
    </div>
    <div class="right">
      <div style="margin-bottom: 50px;">Moi page duoc chay tren nen trang Index.php</div>
      <?php
        session_start(); 
        if(!empty($_SESSION["username"]) && $_SESSION["username"] == "admin") {
          if(!empty($_GET['page'])) {
            switch($_GET['page']) {
              case "home":
                include_once("./pages/home.php");
                break;
              case "logout":
                include_once("./pages/logout.php");
                break;  
              case "upload":
                include_once("./pages/upload.php");
                break;  
            }
          } else {
            echo "No page";
          }  
        } else {
          echo "Ban phai dang nhap tai khoan admin";
        }
      ?>
    </div>
  </main>
</body>

</html>