/*
Problem Statement

Given a circular integer array A, return the next greater element for every element in A. 
The next greater element for an element x is the first element greater than x that we 
come across while traversing the array in a clockwise manner. 
If it doesn’t exist, return -1 for this element.
*/

# include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
	stack<int>Stack;

	// since the array is circular we push the elements after last element as present
	// in the circular array in the stack
	for (int i = nums.size() - 2; i >= 0; i--)
		Stack.push(nums[i]);

	vector<int>ans(nums.size(), 0);

	// keep the track of the next greater element to the current element by popping the
	// elements which are smaller than or equal to the current element and maintaining 
	// greater element at the top 
	for (int i = nums.size() - 1; i >= 0; i--) {
		while (!Stack.empty() && Stack.top() <= nums[i])
			Stack.pop();

		if (Stack.empty()) ans[i] = -1;
		else
			ans[i] = Stack.top();
		Stack.push(nums[i]);
	}

	return ans;
}
int main() {

	// taking input
	int n;
	cin >> n;

	vector<int>nums(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	vector<int>ans = nextGreaterElements(nums);

	// output
	for (auto it : ans)
		cout << it << " ";

	return 0;
}