const btns = document.querySelectorAll(".caculator button");
const input = document.querySelector(".input");

btns.forEach((el) => {
  el.addEventListener("click", () => {
    let text = el.textContent;
    if (text === "C") {
      input.value = input.value.slice(0, -1);
    } else if (text === "CE") {
      input.value = "";
    } else if (text === "+/-") {
      input.value = "";
    } else if (text === "=") {
      input.value = eval(input.value);
    } else {
      input.value += text;
    }
  });
});
