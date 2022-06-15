function doing1(length, arr, k) {
    let obj = {};
    for (let i = 0; i < length; i++) {
        obj[arr[i]] ? obj[arr[i]]++ : (obj[arr[i]] = 1);
    }
    let arr1 = [];
    for (el in obj) {
        if (!arr1.includes(obj[el])) arr1.push(obj[el]);
    }
    arr1.sort((a, b) => b - a);
    if (!arr1[k - 1]) return 0;
    let arr2 = [];
    for (el in obj) {
        if (obj[el] === arr1[k - 1]) arr2.push(+el);
    }
    let result = Math.min(arr2);
    return result;
}

// console.log(doing(9, [1, 2, 6, 3, 4, 2, 3, 0, 3], 2));

function doing2(length, grid) {
    let gridX = new Array(length).fill(0);
    let gridY = new Array(length).fill(0);
    for (let i = 0; i < length; i++) {
        for (let j = 0; j < length; j++) {
            if (grid[i][j] === 1) {
                gridX[i]++;
                gridY[j]++;
            }
        }
    }
    let a = gridX.map((el) => (el - 1) * 2).reduce((el1, el2) => el1 + el2, 0);
    let b = gridX.map((el) => (el - 1) * 2).reduce((el1, el2) => el1 + el2, 0);
    return a + b;
}

let grid = [
    [0, 0, 0, 0, 1],
    [1, 0, 1, 0, 1],
    [0, 0, 0, 0, 0],
    [1, 0, 0, 0, 1],
    [0, 1, 0, 1, 0],
];

console.log(doing2(5, grid));
