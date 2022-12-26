const data = [
  {
    id: "SP001",
    name: "Máy giặt",
  },
  {
    id: "SP002",
    name: "Bếp Đa Năng",
  },
  {
    id: "SP003",
    name: "Lò sưởi",
  },
  {
    id: "SP004",
    name: "Điều hòa nhiệt độ",
  },
  {
    id: "SP005",
    name: "Tủ lạnh",
  },
];
let replace = "";
const table = document.querySelector("#table");
const input = document.querySelector("#input");
input.addEventListener("input", (e) => {
  console.log("Hiếu Joyce");
  replace = `${e.target.value}`;
  let re = new RegExp(replace, "g");
  let data1 = data.filter((el) => el.id.match(re) || el.name.match(re));
  render(data1, thIdSort, thNameSort, replace);
});

let thIdSort = 1,
  thNameSort = 1;

function render(data, thIdSort, thNameSort, replace) {
  let content = `
    <tr>
      <th>TT</th>
      <th id="id">${thIdSort === -1 ? "&darr;" : "&uarr;"} Mã sản phẩm</th>
      <th id="name">${thNameSort === -1 ? "&darr;" : "&uarr;"} Tên sản phẩm</th>
    </tr>
  `;
  content += data
    .map((el, index) => {
      return `
      <tr>
        <td>${index + 1}</td>
        <td>${replace ? hightlightText(el.id, replace) : el.id}</td>
        <td>${replace ? hightlightText(el.name, replace) : el.name}</td>
      </tr>
    `;
    })
    .join("");

  table.innerHTML = content;
  const thId = table.querySelector("th#id");
  const thName = table.querySelector("th#name");
  thId.addEventListener("click", () => {
    thIdSort = thIdSort === -1 ? 1 : -1;
    let data1 = data.sort(
      (a, b) => (+a.id.slice(-3) - +b.id.slice(-3)) * thIdSort
    );
    render(data1, thIdSort, thNameSort, replace);
  });
  thName.addEventListener("click", () => {
    thNameSort = thNameSort === -1 ? 1 : -1;
    let data1 = data.sort((a, b) => {
      return a.name.localeCompare(b.name) * thNameSort;
    });
    render(data1, thIdSort, thNameSort, replace);
  });
}

render(data, thIdSort, thNameSort, replace);

function hightlightText(str, replace) {
  let re = new RegExp(replace, "g");
  return str.replace(re, `<mark>${replace}</mark>`);
}
