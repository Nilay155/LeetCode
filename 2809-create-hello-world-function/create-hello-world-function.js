/**
 * @return {Function}
 */
var createHelloWorld = function() {
    const helloWorldFunction = (...args) => "Hello World";
    return helloWorldFunction;
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */