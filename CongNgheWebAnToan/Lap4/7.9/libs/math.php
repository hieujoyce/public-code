<?php
  function myMin($name) {
    $min = $_POST[$name."0"];
    for ($i=0; $i < 10; $i++) {
      $el = $name.$i;
      if( (int)$_POST[$el] < $min) {
        $min = (int)$_POST[$el];
      };
    }
    return $min;
  }

  function myMax($name) {
    $max = $_POST[$name."0"];
    for ($i=0; $i < 10; $i++) {
      $el = $name.$i;
      if( (int)$_POST[$el] > $max) {
        $max = (int)$_POST[$el];
      };
    }
    return $max;
  }
  function mySum($name) {
    $tong = 0;
    for ($i=0; $i < 10; $i++) {
      $el = $name.$i;
      $tong += (int)$_POST[$el];
    }
    return $tong;
  }

  function myAvg($sum, $leng) {
    return $sum / $leng;
  }
?>