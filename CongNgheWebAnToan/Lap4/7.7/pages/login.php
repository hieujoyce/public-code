<form action="" method="post">
  <h3>Dang nhap</h3>
  <div>
    <label for="username">
      Username:
    </label>
    <input type="text" name="username">
  </div>
  <div>
    <label for="password">
      Password:
    </label>
    <input type="password" name="password">
  </div>
  <div>
    <button type="reset">Nhap lai</button>
    <button type="submit">Dang nhap</button>
  </div>
</form>

<?php 
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(!empty($_POST["username"]) && !empty($_POST["password"])) {
      if($_POST["username"] == "admin" && $_POST["password"] =="admin") {
        session_start();
        $_SESSION["username"] = "admin";
        header("location: admin/index.php");
      } else {
        echo "<p style='color: red;'>Ten dang nhap hoac mat khau khong chinh xac</p>";
      }
    }
  }
?>