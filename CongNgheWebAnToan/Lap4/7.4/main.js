const form = document.querySelector("#form");
input = form.querySelector("#input");
const btns = form.querySelectorAll("button[type=button]");
btns.forEach((el) => {
  el.addEventListener("click", (e) => {
    input.value = e.target.getAttribute("data-page");
    form.submit();
  });
});