/**
 * @param {number[]} cards
 * @return {number}
 */
var minimumCardPickup = function(cards) {
    const lastIndex = new Map();
    let result = Number.MAX_SAFE_INTEGER;
    for(let i = 0; i < cards.length; i++){
        if(lastIndex.has(cards[i])){
            let index = lastIndex.get(cards[i]);
            result = Math.min(result, Math.abs(index - i)+1);
        }
        lastIndex.set(cards[i], i);
    }
    return result != Number.MAX_SAFE_INTEGER ? result : -1;
};