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
        <button data-page="listClass" type="button">listClass</button>
      </form>
    </nav>
  </header>
  <main>
    <div class="left">
      Left
    </div>
    <div class="right">
      <div style="margin-bottom: 50px;">HOME</div>
      <?php
        if(!empty($_GET['page'])) {
          switch($_GET['page']) {
            case "listClass":
              include_once("./pages/listClass.php");
              break;
            case "listStdInClass":
              include_once("./pages/listStdInClass.php");
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