const form = document.querySelector("#form");

form.addEventListener("keydown", (e) => {
    if (e.key === "Enter" || e.keyCode === 13) e.preventDefault();
});

form.addEventListener("submit", (e) => {
    e.preventDefault();
    checkInputs();
});

const els = {};

const arrEl = [
    {
        name: "hoTen",
        type: "text",
        label: "Họ tên",
        placeholder: "Nguyễn Trung Hiếu",
        require: true,
    },
    {
        name: "diaChi",
        type: "text",
        label: "Địa chỉ",
        placeholder: "Địa chỉ",
        require: false,
    },
    {
        name: "gioiTinh",
        type: "radio",
        label: "Giới tính",
        value: ["Nam", "Nữ"],
        defaultValueIndex: 0,
    },
    {
        name: "ngaySinh",
        type: "text",
        label: "Ngày sinh",
        placeholder: "06/06/2001",
        require: true,
    },
    {
        name: "email",
        type: "text",
        label: "Email",
        placeholder: "hieujoycedev@gmail.com",
        require: true,
    },
    {
        name: "matKhau",
        type: "password",
        label: "Mật khẩu",
        placeholder: "•••••••••",
        require: true,
    },
    {
        name: "matKhauXacNhan",
        type: "password",
        label: "Xác nhận mật khẩu",
        placeholder: "•••••••••",
        require: true,
    },
];
renderForm();

arrEl.forEach((el) => {
    els[el.name] = document.querySelector(`#${el.name}`);
    if (el.type === "text" || el.type === "password")
        els[el.name].addEventListener("focus", (e) => {
            resetErrorFor(e.target, el.require);
        });
});
els[arrEl[0].name].focus();

els.hoTen.addEventListener("focusout", (e) => {
    e.target.value = covertHoTen(e.target.value);
});

let ngaySinhTmp = "";
els.ngaySinh.addEventListener("keydown", (e) => {
    e.preventDefault();
    if (e.keyCode === 8) {
        if (ngaySinhTmp.length === 3 || ngaySinhTmp.length === 6) {
            ngaySinhTmp = ngaySinhTmp.slice(0, -2);
        } else {
            ngaySinhTmp = ngaySinhTmp.slice(0, -1);
        }
    } else if (
        (e.keyCode >= 48 && e.keyCode <= 57) ||
        (e.keyCode >= 96 && e.keyCode <= 105)
    ) {
        if (ngaySinhTmp.length < 10) {
            ngaySinhTmp += e.key;
            if (
                ngaySinhTmp.length === 10 &&
                Number(ngaySinhTmp.slice(-4)) >= new Date().getFullYear()
            ) {
                ngaySinhTmp = `${ngaySinhTmp.slice(0, -4)}${
                    new Date().getFullYear() - 1
                }`;
            } else if (
                ngaySinhTmp.length === 10 &&
                Number(ngaySinhTmp.slice(-4)) < new Date().getFullYear() - 100
            ) {
                ngaySinhTmp = `${ngaySinhTmp.slice(0, -4)}${
                    new Date().getFullYear() - 100
                }`;
            }

            if (ngaySinhTmp.length === 10) {
                let maxDay = getDaysInMonth(
                    Number(ngaySinhTmp.slice(-4)),
                    ngaySinhTmp.slice(3, 5)
                );
                if (ngaySinhTmp.slice(0, 2) > maxDay) {
                    ngaySinhTmp = `${maxDay}${ngaySinhTmp.slice(2)}`;
                }
            }
        }
        if (ngaySinhTmp.length === 2 || ngaySinhTmp.length === 5) {
            if (ngaySinhTmp.length === 2 && Number(ngaySinhTmp) > 31) {
                ngaySinhTmp = "31";
            } else if (ngaySinhTmp.length === 2 && Number(ngaySinhTmp) == 0) {
                ngaySinhTmp = "01";
            }
            if (
                ngaySinhTmp.length === 5 &&
                Number(ngaySinhTmp.slice(-2)) > 12
            ) {
                ngaySinhTmp = `${ngaySinhTmp.slice(0, -2)}12`;
            } else if (
                ngaySinhTmp.length === 5 &&
                Number(ngaySinhTmp.slice(-2)) == 0
            ) {
                ngaySinhTmp = `${ngaySinhTmp.slice(0, -2)}01`;
            }
            ngaySinhTmp += "/";
        }
    }
    e.target.value = ngaySinhTmp;
});

arrEl.forEach((el, i) => {
    if (el.type === "text" || el.type === "password") {
        if (findIndexInputText(i) !== -1) {
            els[el.name].addEventListener("keyup", (e) => {
                if (e.key === "Enter" || e.keyCode === 13) {
                    els[arrEl[findIndexInputText(i)].name].focus();
                    if (el.name === "hoTen") {
                        e.target.value = covertHoTen(e.target.value);
                    }
                }
            });
        } else {
            els[el.name].addEventListener("keyup", (e) => {
                if (e.key === "Enter" || e.keyCode === 13) {
                    document.querySelector("button[type='submit']").click();
                }
            });
        }
    }
});

function covertHoTen(value) {
    return value
        .split(" ")
        .map((el) => el.charAt(0).toUpperCase() + el.slice(1))
        .join(" ");
}

function findIndexInputText(index) {
    for (let i = index + 1; i < arrEl.length; i++) {
        if (arrEl[i].type === "text" || arrEl[i].type === "password") return i;
    }
    return -1;
}

function renderForm() {
    let content = arrEl
        .map((e) => {
            if (e.type === "text" || e.type === "password") {
                return renderInputText(
                    e.type,
                    e.name,
                    e.placeholder,
                    e.label,
                    e.require
                );
            } else if (e.type === "radio") {
                return renderInputRadio(e.name, e.label, e.value);
            } else return "";
        })
        .join("");

    content += `
    <div class="flex items-start mb-6">
        <div class="flex items-center h-5">
            <input
                id="remember"
                type="checkbox"
                value=""
                class="w-4 h-4 bg-gray-50 rounded border border-gray-300 focus:ring-3 focus:ring-blue-300 dark:bg-gray-700 dark:border-gray-600 dark:focus:ring-blue-600 dark:ring-offset-gray-800"
            />
        </div>
        <label
            for="remember"
            class="ml-2 text-sm font-medium text-gray-900 dark:text-gray-300"
            >Remember me</label
        >
    </div>
    <button
        type="submit"
        class="text-white bg-blue-700 hover:bg-blue-800 focus:ring-4 focus:outline-none focus:ring-blue-300 font-medium rounded-lg text-sm w-full px-5 py-2.5 text-center dark:bg-blue-600 dark:hover:bg-blue-700 dark:focus:ring-blue-800"
    >
        Submit
    </button>
    `;
    form.innerHTML = content;
}

function renderInputText(type, name, placeholder, label, require = false) {
    return `
    <div class="mb-6">
        <label
            for="${name}"
            class="block mb-2 text-sm font-medium text-gray-900 dark:text-gray-300"
            >${label}</label
        >
        <input
            type="${type}"
            id="${name}"
            ${type === "text" ? "" : `autocomplete="on"`}
            class="bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 ${
                require ? "dark:bg-teal-600" : "dark:bg-gray-700"
            } dark:border-gray-600 ${
        require ? "dark:placeholder-gray-300" : "dark:placeholder-gray-400"
    } dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500"
            placeholder="${placeholder}"
        />
        <p class="mt-2 text-sm text-red-600 dark:text-red-500"></p>
    </div>
    `;
}

function renderInputRadio(name, label, value) {
    return `
    <div class="mb-6">
        <label
            for="${name}"
            class="block mb-2 text-sm font-medium text-gray-900 dark:text-gray-300"
            >${label}</label
        >
        <div class="flex flex-wrap">
            ${value
                .map(
                    (e, i) =>
                        `<div class="flex items-center mr-4">
                            <input
                                type="radio"
                                value="${e}"
                                name="${name}"
                                ${i === 0 ? "checked" : ""}
                                class="w-4 h-4 text-red-600 bg-gray-100 border-gray-300 focus:ring-red-500 dark:focus:ring-red-600 dark:ring-offset-gray-800 focus:ring-2 dark:bg-gray-700 dark:border-gray-600"
                            />
                            <label
                                for="red-radio"
                                class="ml-2 text-sm font-medium text-gray-900 dark:text-gray-300"
                                >${e}</label
                            >
                        </div>`
                )
                .join("")}
            
        </div>
    </div>
    `;
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

function resetErrorFor(el, require) {
    let classLabelReset =
        "block mb-2 text-sm font-medium text-gray-900 dark:text-gray-300";
    let classInputReset = `bg-gray-50 border border-gray-300 text-gray-900 text-sm rounded-lg focus:ring-blue-500 focus:border-blue-500 block w-full p-2.5 ${
        require ? "dark:bg-teal-600" : "dark:bg-gray-700"
    } dark:border-gray-600 ${
        require ? "dark:placeholder-gray-300" : "dark:placeholder-gray-400"
    } dark:text-white dark:focus:ring-blue-500 dark:focus:border-blue-500`;

    const formControl = el.parentElement;
    formControl.querySelector("label").className = classLabelReset;
    formControl.querySelector("input").classList = classInputReset;
    formControl.querySelector("p").innerText = "";
}

function checkInputs() {
    const [
        hoTenValue,
        diaChiValue,
        gioiTinhValue,
        ngaySinhValue,
        emailValue,
        matKhauValue,
        matKhauXacNhanValue,
    ] = arrEl.map((el) => {
        if (el.type !== "radio") return els[el.name].value.trim();
        return document.querySelector(`input[name="${el.name}"]:checked`).value;
    });

    const errForm = arrEl.reduce((pre, cur) => {
        pre[`${cur.name}Err`] = "";
        return pre;
    }, {});
    if (hoTenValue === "") {
        errForm.hoTenErr = "Họ tên không được để trống";
    }
    if (ngaySinhValue === "") {
        errForm.ngaySinhErr = "Ngày sinh không được để trống";
    }
    if (emailValue === "") {
        errForm.emailErr = "Email không được để trống";
    } else if (!validateEmail(emailValue)) {
        errForm.emailErr = "Email không đúng định dạng";
    }
    if (matKhauValue === "") {
        errForm.matKhauErr = "Mật khẩu không được để trống";
    }
    if (matKhauXacNhanValue === "") {
        errForm.matKhauXacNhanErr = "Mật khẩu xác nhận không được để trống";
    } else if (matKhauXacNhanValue !== matKhauValue) {
        errForm.matKhauXacNhanErr = "Mật khẩu xác nhận không chính xác";
    }

    for (const key in errForm) {
        if (errForm[key] !== "") {
            setErrorFor(`#${key.slice(0, -3)}`, errForm[key]);
        }
    }
}

const validateEmail = (email) => {
    return String(email)
        .toLowerCase()
        .match(
            /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/
        );
};

function getDaysInMonth(year, month) {
    return new Date(year, month, 0).getDate();
}
