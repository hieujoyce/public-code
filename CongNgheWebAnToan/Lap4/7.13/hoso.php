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
        <button data-page="add" type="button">Add</button>
        <button data-page="list" type="button">List</button>
      </form>
    </nav>
  </header>
  <main>
    <div class="left">
      <a href="./index.php">Trang chu</a>
    </div>
    <div class="right">
      <div style="margin-bottom: 50px;"></div>
      <?php
        if(!empty($_GET['page'])) {
          switch($_GET['page']) {
            case "add":
              include_once("./pages/hoSo/add.php");
              break;
            case "list":
              include_once("./pages/hoSo/list.php");
              break; 
            case "detail":
              include_once("./pages/hoSo/detail.php");
              break;
            case "edit":
              include_once("./pages/hoSo/edit.php");
              break;
            case "delete":
              include_once("./pages/hoSo/delete.php");
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