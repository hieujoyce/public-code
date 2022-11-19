const data = {
  name: "root",
  child: [
    {
      name: "Folder 1",
    },
    {
      name: "Folder 2",
      child: [
        {
          name: "Folder 2-1",
        },
        {
          name: "Folder 2-2",
          child: [
            {
              name: "Folder 2-2-1",
              child: [
                {
                  name: "Folder 2-2-1-1",
                },
                {
                  name: "Folder 2-2-1-2",
                },
              ],
            },
            {
              name: "Folder 2-2-2",
            },
          ],
        },
        {
          name: "Folder 2-3",
        },
      ],
    },
    {
      name: "Folder 3",
    },
    {
      name: "Folder 4",
      child: [
        {
          name: "Folder 4-1",
        },
        {
          name: "Folder 4-2",
        },
      ],
    },
    {
      name: "Folder 5",
    },
  ],
};

let container = document.querySelector(".container");

function eachRecursive(obj) {
  let div = document.createElement("div");
  div.className = "folder";
  if (obj.name) {
    let div1 = document.createElement("div");
    div1.className = "header";
    div1.innerHTML = `
      <div class="icon ${obj.child ? "" : "hidden"}">-</div>
      <div class="img">
        <img src="./imgs/folder.png" alt="" />
      </div>
      <div class="name">${obj.name}</div>
    `;
    div.appendChild(div1);
  }
  if (obj.child && Array.isArray(obj.child)) {
    let div2 = document.createElement("div");
    div2.className = "child";
    obj.child.forEach((el) => {
      div2.appendChild(eachRecursive(el));
    });
    div.appendChild(div2);
  }

  return div;
}
container.appendChild(eachRecursive(data));

const icons = document.querySelectorAll(".icon");
icons.forEach((el) => {
  el.addEventListener("click", () => {
    console.log("Hieu Joyce");
    console.log(el.classList.contains("none"));
    let parentNode = el.parentNode.parentNode;
    parentNode.lastElementChild.classList.toggle("none");
    el.innerText = `${
      parentNode.lastElementChild.classList.contains("none") ? "+" : "-"
    }`;
  });
});
