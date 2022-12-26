let btnJump = document.querySelector("#jump");
let btnStop = document.querySelector("#stop");
let imgs = document.querySelectorAll(".img img");

let index = 0;
changeImgs(index);
let intervalId;

btnJump.addEventListener("click", () => {
  intervalId = setInterval(() => {
    index++;
    index = index === 4 ? 0 : index;
    changeImgs(index);
  }, 500);
});

btnStop.addEventListener("click", () => {
  if (intervalId) clearInterval(intervalId);
});

function changeImgs(i) {
  imgs.forEach((el, id) => {
    if (id === i) el.classList.remove("none");
    else el.classList.add("none");
  });
}
