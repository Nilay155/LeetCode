/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    // functions -> array of functions
    return function(x) {
        for(let i = functions.length-1 ; i >= 0 ; i--) {
            const func = functions[i];
            x = func(x);
        }
        return x;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */