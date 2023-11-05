function checkSpecialNumber(n){
    var a = new Array();
    var size = n.length;
    console.log(n);
    while(n >= 0) {
        var value = n%10;
        a.push(value);
        n = n - Math.pow(10, size - 1);
    }

    a.sort();
    var len = a.length;

    for (var i = 0; i < len; i++) {
        console.log(a[i]);
    }
    
    if (len == 0) {
        return false;
    }
    if (len == 1) {
        return true;
    }
    for (var i = 1; i < len; i++) {
        if (a[i] == a[i-1]) {
            return false;
        }
    }
    return true;
}

//var n = 122;
var n = 123;
console.log(checkSpecialNumber(n));