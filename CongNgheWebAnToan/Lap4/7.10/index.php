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
        <button data-page="home" type="button">Home</button>
        <button data-page="listStudent" type="button">List Student</button>
        <button data-page="addStudent" type="button">Add Student</button>
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
            case "listStudent":
              include_once("./pages/listStudent.php");
              break;
            case "addStudent":
              include_once("./pages/addStudent.php");
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