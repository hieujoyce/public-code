console.log("Hello Hiếu Joyce");
const data = [
  {
    hoTen: "Hoàng Thị Thảo",
    ngaySinh: "23/6/1990",
    gioiTinh: "Nữ",
  },
  {
    hoTen: "Ngô Mạnh Quân",
    ngaySinh: "14/4/1992",
    gioiTinh: "Nam",
  },
  {
    hoTen: "Nguyễn Thanh Tùng",
    ngaySinh: "27/9/1991",
    gioiTinh: "Nam",
  },
  {
    hoTen: "Hoàng Thị Ngân",
    ngaySinh: "12/12/1992",
    gioiTinh: "Nữ",
  },
];

const table = document.querySelector("#table");
const tableBody = table.querySelector("tbody");

function renderTableBody(checks) {
  let content = "";
  content = data
    .map((el, index) => {
      let bg = index % 2 === 0 ? "900" : "800";
      return `<tr
        class="bg-white border-b ${
          checks[index] ? "dark:bg-yellow-600" : `dark:bg-gray-${bg}`
        } dark:border-gray-700 cursor-pointer hover:dark:bg-green-600 ease-in-out duration-200 text-white"
    >
        <td class="py-4 px-6">
            <input
                ${checks[index] ? "checked" : ""}
                id="checked-checkbox-${index}"
                type="checkbox"
                value=""
                class="w-4 h-4 text-blue-600 bg-gray-100 rounded border-gray-300 focus:ring-blue-500 dark:focus:ring-blue-600 dark:ring-offset-gray-800 focus:ring-2 dark:bg-gray-700 dark:border-gray-600"
            />
        </td>
        <td class="py-4 px-6">${el.hoTen}</td>
        <td class="py-4 px-6">${el.ngaySinh}</td>
        <td class="py-4 px-6">${el.gioiTinh}</td>
    </tr>`;
    })
    .join("");
  tableBody.innerHTML = content;

  tableBody.querySelectorAll("tr").forEach((el, index) => {
    el.querySelector("input[type='checkbox']").addEventListener(
      "change",
      (e) => {
        checks[index] = !!e.currentTarget.checked;
        checkedCheckbox.checked = !checks.some((el1) => el1 === false);
        renderTableBody(checks);
      }
    );
  });
}
const checkedCheckbox = document.querySelector("#checked-checkbox");
let checks = new Array(data.length).fill(false);

renderTableBody(checks);

checkedCheckbox.addEventListener("change", (e) => {
  checks.fill(!!e.currentTarget.checked);
  renderTableBody(checks);
});
