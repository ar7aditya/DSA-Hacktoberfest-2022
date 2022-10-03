

class 3sum {
public List<List<Integer>> threeSum(int[] nums) {
	Arrays.sort(nums);
	var triplets = new ArrayList<List<Integer>>();
	var n = nums.length;

	for (var i = 0; i < n - 2; i++) {
		if (i != 0)
			while (i < n && nums[i] == nums[i - 1])
				i++;
		// if the smallest number is positive, all numbers of triplet will be positive, which can't sum to 0
		if (i < n && nums[i] > 0)  
			break;
		var j = i + 1;
		var k = n - 1;

		while (j < k) {
			var sum = nums[i] + nums[j] + nums[k];

			if (sum == 0) {
				triplets.add(List.of(nums[i], nums[j++], nums[k--]));
				
				while (j < k && nums[j] == nums[j - 1])
					j++;
				while (j < k && nums[k] == nums[k + 1])
					k--;
			} else if (sum < 0) { // sum too low, increase it
				j++;
			} else { // sum too high, decrease it
				k--;
			}
		}
	}
	return triplets;
}

}