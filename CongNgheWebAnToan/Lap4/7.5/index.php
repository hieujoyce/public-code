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
      <form id="form" action="" method="get">
        <input id="input" hidden type="text" name="page">
        <button data-page="ar1Chieu" type="button">ar1Chieu</button>
        <button data-page="associateArray" type="button">associateArray</button>
        <button data-page="uploadFile" type="button">uploadFile</button>
      </form>
    </nav>
  </header>
  <main>
    <div class="left">
      Left
    </div>
    <div class="right">
      <div style="margin-bottom: 50px;">Moi page duoc chay tren nen trang Index.php</div>
      <?php
        if(!empty($_GET['page'])) {
          switch($_GET['page']) {
            case "ar1Chieu":
              include_once("./pages/ar1Chieu.php");
              break;
            case "associateArray":
              include_once("./pages/associateArray.php");
              break;
            case "uploadFile":
              include_once("./pages/uploadFile.php");
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