const data = ["Tab 1", "Tab 2", "Tab 3", "Tab 4"];

let activeIndex = 0;
const list = document.querySelector("#list");

function renderList() {
  let ctx = data
    .map(
      (el, index) =>
        `<li class="${activeIndex === index ? "active" : ""}" >${el}</li>`
    )
    .join("");
  list.innerHTML = ctx;
  document.querySelector("#content").innerHTML = `Web ${data[activeIndex]}`;
  document.querySelectorAll("#list li").forEach((el, index) => {
    el.addEventListener("click", () => {
      activeIndex = index;
      renderList();
    });
  });
}

renderList();
