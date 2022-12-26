const form = document.querySelector("#form");

const els = {};

const arrEl = [
    "mhs",
    "className",
    "name",
    "diaChi",
    "ngaySinh",
    "diemToan",
    "diemLy",
    "diemHoa",
];

arrEl.forEach((selectId) => {
    els[selectId] = document.getElementById(selectId);
    els[selectId].addEventListener("focus", (e) => {
        resetErrorFor(e.target);
    });
});

form.addEventListener("submit", (e) => {
    e.preventDefault();
    checkInputs();
});

function checkInputs() {
    const [
        mhsValue,
        classNameValue,
        nameValue,
        diaChiValue,
        ngaySinhValue,
        diemToanValue,
        diemLyValue,
        diemHoaValue,
    ] = arrEl.map((selectId) => els[selectId].value.trim());

    const errForm = arrEl.reduce((pre, cur) => {
        pre[`${cur}Err`] = "";
        return pre;
    }, {});
    if (mhsValue === "") {
        errForm.mhsErr = "Mã hs không được để trống";
    } else if (mhsValue.length > 8) {
        errForm.mhsErr = "Mã hs không được vượt quá 8 kí tự";
    }
    if (classNameValue === "") {
        errForm.classNameErr = "Tên lớp không được để trống";
    } else if (classNameValue.length > 6) {
        errForm.classNameErr = "Tên lớp không được vượt quá 6 kí tự";
    }
    if (nameValue === "") {
        errForm.nameErr = "Họ tên không được để trống";
    } else if (nameValue.length > 50) {
        errForm.nameErr = "Họ tên không được vượt quá 50 kí tự";
    }
    if (diaChiValue === "") {
        errForm.diaChiErr = "Địa chỉ không được để trống";
    } else if (diaChiValue.length > 150) {
        errForm.diaChiErr = "Địa chỉ không được vượt quá 150 kí tự";
    }
    if (diemToanValue === "") {
        errForm.diemToanErr = "Điểm toán không được để trống";
    } else if (isNaN(diemToanValue)) {
        errForm.diemToanErr = "Điểm toán phải là kiểu số";
    }
    if (diemLyValue === "") {
        errForm.diemLyErr = "Điểm lý không được để trống";
    } else if (isNaN(diemLyValue)) {
        errForm.diemLyErr = "Điểm lý phải là kiểu số";
    }
    if (diemHoaValue === "") {
        errForm.diemHoaErr = "Điểm hóa không được để trống";
    } else if (isNaN(diemHoaValue)) {
        errForm.diemHoaErr = "Điểm hóa phải là kiểu số";
    }
    if (ngaySinhValue === "") {
        errForm.ngaySinhErr = "Ngày sinh không được để trống";
    } else if (
        !/^(0[1-9]|1[0-2])\/(0[1-9]|1\d|2\d|3[01])\/(19|20)\d{2}$/.test(
            ngaySinhValue
        )
    ) {
        errForm.ngaySinhErr = "Ngày sinh phải là kiểu date";
    }

    for (const key in errForm) {
        if (errForm[key] !== "") {
            setErrorFor(`#${key.slice(0, -3)}`, errForm[key]);
        }
    }
}

function setErrorFor(select, message) {
    let classLabelErr =
        "block mb-2 text-sm font-medium text-red-700 dark:text-red-500";
    let classInputErr =
        "bg-red-50 border border-red-500 text-red-900 placeholder-red-700 text-sm rounded-lg focus:ring-red-500 focus:border-red-500 block w-full p-2.5 dark:bg-red-100 dark:border-red-400";
    const formControl = document.querySelector(select).parentElement;
    formControl.querySelector("label").className = classLabelErr;
    formControl.querySelector("input").classList = classInputErr;
    formControl.querySelector("p").innerText = message;
}

function resetErrorFor(el) {
    let classLabelReset =
        "block mb-2 text-sm font-medium text-gray-900 dark:text-gray-300";
    let classInputReset =
        "bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 dark:bg-gray-700 dark:border-gray-600 dark:placeholder-gray-400 dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500";
    const formControl = el.parentElement;
    formControl.querySelector("label").className = classLabelReset;
    formControl.querySelector("input").classList = classInputReset;
    formControl.querySelector("p").innerText = "";
}
