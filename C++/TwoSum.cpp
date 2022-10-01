#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
  Two Sum
  Given an array of integers nums and an integer target,
  return indices of the two numbers such that they add up to target.
  You may assume that each input would have exactly one solution,
  and you may not use the same element twice.
  You can return the answer in any order.
*/

vector<int> twoSum(vector<int> &nums, int target)
{
  // Map to store the num and its index
  unordered_map<int, int> m;

  for (int i = 0; i < nums.size(); i++)
  {
    // Check if we have seen the target - nums[i] before,
    // then simply return the index of pre from map and current index
    if (m.count(target - nums[i]) != 0)
    {
      return {m[target - nums[i]], i};
    }

    // Storing the current num with its index
    m[nums[i]] = i;
  }

  // If no solution return -1, -1
  return {-1, -1};
}

int main()
{
  vector<int> nums = {3, 2, 4};
  int target = 6;

  vector<int> result = twoSum(nums, target);
  cout << "Indexes: " << result[0] << ", " << result[1] << endl;

  return 0;
};