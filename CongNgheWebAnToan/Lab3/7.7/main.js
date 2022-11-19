const data = [
  "Quản lý cán bộ (Đăng ký thông tin)",
  "Phân quyền",
  "Cổng thông tin đào tào và người học",
  "Quản lý văn bản và hồ sơ công việc",
  "Hành chính công",
  "Hệ thống thông tin báo cáo",
];

let activeIndex = 0;
const list = document.querySelector("#list");

function renderList() {
  let ctx = data
    .map(
      (el, index) =>
        `<li class="${
          activeIndex === index ? "active" : ""
        }" >&raquo ${el}</li>`
    )
    .join("");
  list.innerHTML = ctx;
  document.querySelector("#content").innerHTML = `&raquo ${data[activeIndex]}`;
  document.querySelectorAll("#list li").forEach((el, index) => {
    el.addEventListener("click", () => {
      activeIndex = index;
      renderList();
    });
  });
}

renderList();
