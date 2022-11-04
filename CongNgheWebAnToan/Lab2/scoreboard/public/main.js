let data = [
    {
        tenHocPhan: "Chính trị",
        hocKy: 1,
        dytt: 6,
        dhpL1: null,
        dhp: 7.9,
    },
    {
        tenHocPhan: "Lý thuyết Hạc Kế toán",
        hocKy: 1,
        dytt: 4,
        dhpL1: null,
        dhp: 7.5,
    },
    {
        tenHocPhan: "Luật Kinh tế",
        hocKy: 1,
        dytt: 2,
        dhpL1: null,
        dhp: 5.5,
    },
    {
        tenHocPhan: "Anh văn cơ bản",
        hocKy: 1,
        dytt: 4,
        dhpL1: null,
        dhp: "Đạt",
    },
    {
        tenHocPhan: "Tin học Văn phòng và Internet",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Giáo dục thể chất 1",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Quản trị doanh nghiệp",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Kinh tế chính trị",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Giáo dục thể chất 2",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Anh Văn chuyên ngành",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Thống kê Doanh nghiệp",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Kế toán Tài chính trong Doanh nghiệp 1",
        hocKy: 1,
        dytt: 5,
        dhpL1: 4.7,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Hệ quản trị CSDL MS Access",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
    {
        tenHocPhan: "Tài chính Doanh nghiệp",
        hocKy: 1,
        dytt: 5,
        dhpL1: null,
        dhp: 5.8,
    },
];

let table1 = document.querySelector("#table1 tbody");
let tb = Number(
    data.reduce((a, b) => a + (typeof b.dhp === "number" ? b.dhp : 8), 0) /
        data.length
).toFixed(1);
let content = data
    .map(
        (el, i) => `
    <tr>
        <td class="text-center">${i}</td>
        <td>${el.tenHocPhan}</td>
        <td class="text-center">${el.hocKy}</td>
        <td class="text-center">${el.dytt}</td>
        <td class="text-center">${el.dhpL1 || ""}</td>
        <td class="text-center">${el.dhp}</td>
    </tr>
`
    )
    .join("");

content += `<tr><td class="text-center" colspan="5">Điểm trung bình chung cả năm</td><td class="text-center">${tb}</td></tr>`;
table1.innerHTML = content;
