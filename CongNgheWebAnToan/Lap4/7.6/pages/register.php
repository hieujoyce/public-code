<div style="margin-top: 10px;">
  <?php 
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    echo "<p> Username: ".$_POST["username"]."</p>";
    echo "<p> Password: ".$_POST["password"]."</p>";
    echo "<p> Gender: ".$_POST["gender"]."</p>";
    echo "<p> Address: ";
    if(!empty($_POST["address"])) {
      foreach ($_POST["address"] as $value) {
        echo $value.", ";
      }
    }
    echo "</p>";
    echo "<p> Enble Programming Language: ";
    if(!empty($_POST["epl"])) {
      foreach ($_POST["epl"] as $value) {
        echo $value.", ";
      }
    }
    echo "</p>";
    echo "<p> Skill: ".$_POST["skill"]."</p>";
    echo "<p> Note: ".$_POST["note"]."</p>";
    echo "<p> Marriage status: ". ((empty($_POST["ms"]) == 1) ? 'Chua ket hon' : 'Da ket hon')."</p>";
  } else {
    echo '<form action="" name="form1" method="post">
    <h3>Form Dang ki</h3>
    <div>
      <label for="username">Username: </label>
      <input type="text" name="username">
    </div>
    <div>
      <label for="password">Password: </label>
      <input type="password" name="password">
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
      <label for="epl[]">Enble Programming Language: </label>
      <div>
        <input type="checkbox" name="epl[]" value="PHP">
        <label for="PHP">PHP</label>
        <input type="checkbox" name="epl[]" value="C#">
        <label for="C#">C#</label>
        <input type="checkbox" name="epl[]" value="Java">
        <label for="Java">Java</label>
        <input type="checkbox" name="epl[]" value="C++">
        <label for="C++">C++</label>
      </div>
    </div>
    <div style="display: flex;">
      <label for="skill">Skill: </label>
      <div>
        <input type="radio" name="skill" value="Nonmal" checked>
        <label for="skill">Nonmal</label><br>
        <input type="radio" name="skill" value="Good">
        <label for="skill">Good</label><br>
        <input type="radio" name="skill" value="Very Good">
        <label for="skill">Very Good</label><br>
        <input type="radio" name="skill" value="Excellent">
        <label for="skill">Excellent</label>
      </div>
    </div>
    <div style="display: flex;">
      <label for="note">Note: </label>
      <textarea name="note" id="" cols="50" rows="4"></textarea>
    </div>
    <div style="display: flex;">
      <label for="ms">Marriage Status: </label>
      <div>
        <input type="checkbox" name="ms" value="ms">
      </div>
    </div>
    <div>
      <button type="reset">Reset</button>
      <button type="submit">Register</button>
    </div>
  </form>';
  }
?>
</div>