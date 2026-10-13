/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if (s.length <= 1) return s.length;
    const charSet = new Set();
    let left = 0;
    let maxCount = 0;
    for(let right = 0; right < s.length; right++){
        while(charSet.has(s[right])){
            charSet.delete(s[left++]);
        }
        maxCount  = Math.max(maxCount, right - left + 1);
        charSet.add(s[right]);
    }
    return maxCount;
};