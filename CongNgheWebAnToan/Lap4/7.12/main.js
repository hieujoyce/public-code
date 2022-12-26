const form = document.querySelector("#form");
input = form.querySelector("#input");
const btns = form.querySelectorAll("button[type=button]");
btns.forEach((el) => {
  el.addEventListener("click", (e) => {
    input.value = e.target.getAttribute("data-page");
    form.submit();
  });
});

const formLang = document.querySelector("#formLang");
inputLang = formLang.querySelector("#inputLang");
const btnsLang = formLang.querySelectorAll("button[type=button]");
btnsLang.forEach((el) => {
  el.addEventListener("click", (e) => {
    inputLang.value = e.target.getAttribute("data-page");
    formLang.submit();
  });
});
