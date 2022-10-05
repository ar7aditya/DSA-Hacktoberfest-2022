/*
DIFFICULTY : EASY
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

//SOLUTION : 1
var twoSum = function(nums, target) {
    for(var i = 0; i< nums.length; i++){
		// work out the complement
		// eg. nums[i] === 3, target === 7, the complement will be 4
        var complement = target - nums[i];
		
		// Iterate the rest of the number and check if the complement of nums[i] exists
		// This part takes a lot of time
        var found = nums.indexOf(complement, i + 1);
        if(found !== -1){
            return [i, found];
        }
    }
    return [0, 0];
};


//SOLUTION : 2
/**
Two-pass Hash Table

eg. nums = [3,5,9,12,15], target = 21

const hashTable = {
	3: 0,
	5: 1,
	9: 2,
	12: 3,
	15: 4
}

1. Create a hashTable
2. Iterate nums
	2.1 Find the complement of nums[i] in the hashTable by checking the key of the hashTable object. In this way, the iteration time will be significantly reduced. If found, return [i, found]
3. If not found, return [0,0]

*/
var twoSum = function(nums, target) {
    if (nums.length === 2) return [0, 1];
    const len = nums.length;
    let hashTable = {};
	for(let i = 0; i < len; i++){
		// Add a new obj to the hashTable where key = nums[i] and value = i
		hashTable[nums[i]] = i;
	}
	
    for(let i = 0; i < len; i++) {
        let complement = target - nums[i];
        let found = hashTable[complement]; // Determine whether the complement exist in the hashTable
        if(found !== undefined && found != i) return [i, found];
	}
	return [0,0];
}


//SOLUTION : 3
//Much faster and efficient
var twoSum = function(nums, target) {
    if (nums.length === 2) return [0, 1];
    const len = nums.length;
    let map = {};
    for(let i = 0; i < len; i++) {
        let n = target - nums[i];
        let find = map[n];
        if(find !== undefined) return [find, i];
        else map[nums[i]] = i;
    }
};