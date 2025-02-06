/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let value = init;
    let refValue = init;
    const Counter = {
        value,
        refValue,
        increment : function() {
            Counter.value += 1;
            return Counter.value;
        },
        decrement : function() {
            Counter.value -= 1;
            return Counter.value;
        },
        reset : function() {
            Counter.value = Counter.refValue;
            return Counter.value;
        }
    }
    return Counter;
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */