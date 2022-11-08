const form = document.querySelector("#form");
const classId = document.getElementById("classId");
const className = document.getElementById("className");
const khoaHoc = document.getElementById("khoaHoc");
const gvcn = document.getElementById("gvcn");

["classId", "className", "khoaHoc", "gvcn"].forEach((selectId) => {
    document.getElementById(selectId).addEventListener("focus", (e) => {
        resetErrorFor(e.target);
    });
});

form.addEventListener("submit", (e) => {
    e.preventDefault();
    checkInputs();
});

function checkInputs() {
    const classIdValue = classId.value.trim();
    const classNameValue = className.value.trim();
    const khoaHocValue = khoaHoc.value.trim();
    const gvcnValue = gvcn.value.trim();

    const errForm = {
        classIdErr: "",
        classNameErr: "",
        khoaHocErr: "",
        gvcnErr: "",
    };

    if (classIdValue === "") {
        errForm.classIdErr = "Mã lớp không được để trống";
    } else if (classIdValue.length > 6) {
        errForm.classIdErr = "Mã lớp không được vượt quá 6 kí tự";
    }
    if (classNameValue === "") {
        errForm.classNameErr = "Tên lớp không được để trống";
    } else if (classNameValue.length > 50) {
        errForm.classNameErr = "Tên lớp không được vượt quá 50 kí tự";
    }
    if (khoaHocValue === "") {
        errForm.khoaHocErr = "Khóa học không được để trống";
    } else if (isNaN(khoaHocValue) || !Number.isInteger(khoaHocValue)) {
        errForm.khoaHocErr = "Khóa học phải là kiểu số nguyên";
    }
    if (gvcnValue === "") {
        errForm.gvcnErr = "Tên GVCN không được để trống";
    } else if (gvcnValue.length > 50) {
        errForm.gvcnErr = "Tên GVCN không được vượt quá 50 kí tự";
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
