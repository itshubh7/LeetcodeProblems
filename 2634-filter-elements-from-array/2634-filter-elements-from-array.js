var filter = function(arr, fn) {
    const filteredArr = []
    arr.forEach((item, index) => fn(item, index) && filteredArr.push(item))
    return filteredArr;
};