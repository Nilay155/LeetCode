/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    
    const toBe = (num) => {
        if(num === val) return true;
        else throw new Error("Not Equal");
    }
    const notToBe = (num) => {
        if(num !== val) return true;
        else throw new Error("Equal");
    }

    const object = {
        toBe,
        notToBe
    }
    return object;
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */