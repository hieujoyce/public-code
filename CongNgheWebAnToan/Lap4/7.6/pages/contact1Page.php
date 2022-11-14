<div style="margin-top: 10px;">
  <?php 
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    echo "<p> Username: ".$_POST["username"]."</p>";
    echo "<p> Gender: ".$_POST["gender"]."</p>";
    echo "<p> Address: ";
    if(!empty($_POST["address"])) {
      foreach ($_POST["address"] as $value) {
        echo $value.", ";
      }
    }
    echo "</p>";  
    echo "<p> Note: ".$_POST["note"]."</p>";
  } else {
    echo '<form action="" name="form1" method="post">
    <h3>Form Lien he</h3>
    <div>
      <label for="username">Username: </label>
      <input type="text" name="username">
    </div>
    <div style="display: flex;">
      <label for="gender">Gender: </label>
  
      <div>
        <input type="radio" id="html" name="gender" value="male" checked>
        <label for="male">Male</label><br>
        <input type="radio" id="css" name="gender" value="female">
        <label for="female">Female</label><br>
      </div>
    </div>
    <div style="display: flex;">
      <label for="address[]">Address: </label>
      <select name="address[]" id="cars" multiple>
        <option value="Ha Noi">Ha Noi</option>
        <option value="TP.HCM">TP.HCM</option>
        <option value="Hue">Hue</option>
        <option value="Da Nang">Da Nang</option>
      </select>
    </div>
    <div style="display: flex;">
      <label for="note">Note: </label>
      <textarea name="note" id="" cols="50" rows="4"></textarea>
    </div>
    <div>
      <button type="reset">Reset</button>
      <button type="submit">Contact</button>
    </div>
  </form>';
  }
  ?>
</div>