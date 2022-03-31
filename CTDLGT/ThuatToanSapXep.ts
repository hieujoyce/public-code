/**
 *
 * @param {number} length
 * @param {number} min
 * @param {number} max
 * @returns {Array}
 */

function randomArr(length, min, max) {
    let arr = [];
    for (let i = 0; i < length; i++) {
        let tmp = Math.floor(min + Math.random() * max);
        arr.push(tmp);
    }
    return arr;
}

// **********************bubbleSort******************************

/**
 * @param {Function} callBack
 * @param {Array} arr
 */

function bubbleSort(arr, callBack) {
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[i] > arr[j]) {
                [arr[i], arr[j]] = [arr[j], arr[i]];
            }
        }
    }
}

// **********************bubbleSortEnd***************************

// **********************insertSort******************************

/**
 *
 * @param {Array} arr
 */

function insertSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        let tmp = arr[i],
            j = i - 1;
        while (j >= 0) {
            if (tmp < arr[j]) arr[j + 1] = arr[j];
            else break;
            j--;
        }
        arr[j + 1] = tmp;
    }
}

// **********************insertSortEnd***************************

// **********************quickSort*******************************
/**
 *
 * @param {Array} arr
 */
function partition(arr, left, right) {
    let pivot = arr[left];
    let l = left + 1,
        r = right;
    do {
        while (arr[l] <= pivot) {
            l++;
        }
        while (arr[r] > pivot) {
            r--;
        }
        if (l < r) {
            [arr[l], arr[r]] = [arr[r], arr[l]];
            l++;
            r--;
        }
    } while (l <= r);
    [arr[left], arr[r]] = [arr[r], arr[left]];
    return r;
}

/**
 *
 * @param {Array} arr
 */

function quickSort(arr, left, right) {
    if (left < right) {
        let indexPivot = partition(arr, left, right);
        quickSort(arr, left, indexPivot - 1);
        quickSort(arr, indexPivot + 1, right);
    }
}

// **********************quickSortEnd****************************

// **********************mergeSort*******************************

function merge(arr, cloneArr, start, mid, end) {
    let i = start,
        j = mid + 1,
        t = start;
    while (i !== mid + 1 && j !== end + 1) {
        cloneArr[t++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    if (i === mid + 1) {
        for (; j < end + 1; j++) {
            cloneArr[t++] = arr[j];
        }
    } else if (j === end + 1) {
        for (; i < mid + 1; i++) {
            cloneArr[t++] = arr[i];
        }
    }
}

/**
 *
 * @param {Array} arr
 * @param {Array} cloneArr
 * @param {Number} h
 */

function mPass(arr, cloneArr, h) {
    let i = 0;
    while (i + 2 * h <= arr.length) {
        merge(arr, cloneArr, i, i + h - 1, i + 2 * h - 1);
        i += 2 * h;
    }
    if (i + h < arr.length) {
        merge(arr, cloneArr, i, i + h - 1, arr.length - 1);
    } else {
        for (; i < arr.length; i++) {
            cloneArr[i] = arr[i];
        }
    }
}

function mergeSort(arr) {
    let cloneArr = [...arr];
    let h = 1;
    while (h < arr.length) {
        mPass(arr, cloneArr, h);
        mPass(cloneArr, arr, 2 * h);
        h *= 4;
    }
}

// **********************mergeSortEnd***************************

(function test() {
    let arr = randomArr(17, 0, 100);
    //let arr = [52, 32, 66, 71, 71, 52, 24, 0, 73, 84];
    //let arr = [13, 42, 39, 74, 3, 46, 10, 45, 35, 78];
    let cloneArr = [...arr];
    //let arr = [7, 9];
    console.log(arr);
    //quickSort(arr, 0, 9);
    //console.log(arr);
    //console.log();
    //merge(arr, cloneArr, 0, 3, 7);
    //mPass(arr, cloneArr, 2);
    mergeSort(arr);
    console.log(arr);
})();

/* Ngày 1 End */
