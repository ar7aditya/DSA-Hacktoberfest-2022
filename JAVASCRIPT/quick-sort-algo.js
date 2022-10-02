

function quick_sort(nums){
	function divide(nums){
		if(nums.length == 0)
			return [];
		else if(nums.length == 1)
			return nums;
		let left = [];
		let right = [];
		let pivot = nums[nums.length-1];
		
		for(let i = 0;i < nums.length-1; i++)		{
			if(nums[i] >= pivot)
				right.push(nums[i]);
			else
				left.push(nums[i]);
		}
		return divide(left).concat([pivot]).concat(divide(right));
	}
	return divide(nums)
}


array = [10, 1, 10, 7, 9, 6, 100, 3];
array = quick_sort(array);

console.log(array);