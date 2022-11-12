<form action="" method="post">
  <table>
    <tr>
      <td>a</td>
      <td><input type="text" name="a"></td>
    </tr>
    <tr>
      <td>b</td>
      <td><input type="text" name="b"></td>
    </tr>
    <tr>
      <td>phep tinh</td>
      <td style="display: flex; gap: 10px">
        <input type="radio" name="phepTinh" value="+" checked>
        <label for="html">+</label><br>
        <input type="radio" name="phepTinh" value="-">
        <label for="css">-</label><br>
        <input type="radio" name="phepTinh" value="*">
        <label for="javascript">*</label>
        <input type="radio" name="phepTinh" value="/">
        <label for="javascript">/</label>
      </td>
    </tr>
    <tr>
      <td></td>
      <td><button>Caculate</button></td>
    </tr>
  </table>
</form>

<?php 
  if( !empty($_POST['a']) && !empty($_POST['b']) && !empty($_POST['phepTinh'])) {
    echo $_POST['a']," ",$_POST['phepTinh']," ",$_POST['b']," = ";
    $a = (int)$_POST['a'];
    $b = (int)$_POST['b'];
    switch($_POST['phepTinh']) {
      case "+":
        echo $a + $b;
        break;
      case "-":
        echo $a - $b;
        break;
      case "*":
        echo $a * $b;
        break;
      case "/":
        echo $a / $b;
        break;
    }
  }
?>