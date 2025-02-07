/**
 * @param {number} limit
 * @param {number[][]} queries
 * @return {number[]}
 */
var queryResults = function(limit, queries) {
    
    const colorMap = {
        "totalColors" : 0,
    };
    const ballMap = {};
    const result = [];

    for(let i = 0 ; i < queries.length ; i++) {
        const xi = JSON.stringify(queries[i][0]);
        const yi = JSON.stringify(queries[i][1]);

        if(xi in ballMap) {
            colorMap[ballMap[xi]]--;
            if(colorMap[ballMap[xi]] === 0) {
                delete colorMap[ballMap[xi]];
                colorMap["totalColors"]--;
            }

            if(yi in colorMap) {
                colorMap[yi]++;
                ballMap[xi] = yi;
            } else {
                colorMap[yi] = 1;
                ballMap[xi] = yi;
                colorMap["totalColors"]++;
            }

        } else {
            if(yi in colorMap) {
                colorMap[yi]++;
                ballMap[xi] = yi;
            } else {
                colorMap[yi] = 1;
                ballMap[xi] = yi;
                colorMap["totalColors"]++;
            }
        }
        result.push(colorMap["totalColors"]);
    }
    return result;
};