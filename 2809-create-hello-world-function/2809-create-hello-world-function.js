/**
 * @return {Function}
 */
var createHelloWorld = function() {
    return function() {
        return "Hello World";
    };
};

/**
 * const f = createHelloWorld();
 * console.log(f()); // "Hello World"
 */
