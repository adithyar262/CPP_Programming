/*
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int arrSize = nums.size();
        if(arrSize == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        int start = 0, end = nums.size() - 1;
        while(start < end) {
            int mid = start + ((end - start) / 2);
            if(nums[mid] > nums[start]) { 
                if(nums[mid] < nums[end]) { // 4 5 6 7 8 9 10
                    if(nums[mid] > target) { // target = 4, 5, 6
                        if(target > nums[start]) { // target = 5, 6
                            end = mid;
                        } else if (target == nums[start]) { // target = 4
                            return start;
                        } else { // target = 3
                            return -1;
                        }
                    } else if(nums[mid] < target) { // target = 8, 9, 10
                        if(target < nums[end]) { // target = 8, 9
                            start = mid + 1;
                        } else if (target == nums[end]) {  // target = 10
                            return end;
                        } else {  // target = 11
                            return -1;
                        }
                    } else { // target = 7
                        return mid;
                    }
                } else { // 4 5 6 7 8 1 2
                    if(nums[mid] > target) { // target = 1, 2, 4, 5, 6
                        if(target > nums[end]) { // target = 4, 5, 6
                            if(target > nums[start]) // target = 5, 6
                                end = mid;
                            else if(target == nums[start]) // target = 4
                                return start;
                            else // target = 3
                                return -1;
                        } else if (target < nums[end]) { // target = 1
                            start = mid + 1;
                        } else { // target = 2
                            return end;
                        }
                    } else if(nums[mid] < target) { // target = 8
                        if(target < nums[end]) { // target = 8, 9
                            return -1;
                        } else if (target == nums[end]) {  // target = 10
                            return end;
                        } else {  // target = 11
                            start = mid + 1;
                        }
                    } else { // target = 7
                        return mid;
                    }
                }
            } else if(nums[mid] < nums[start]) { // 7 8 9 0 1 2 3
                if(nums[mid] < nums[end]) { // 7 8 0 1 2 3 4
                    if(nums[mid] > target) { // target = 0
                        if(target > nums[start]) { // target = 5, 6
                            return -1;
                        } else if (target == nums[start]) { // target = 4
                            return start;
                        } else { // target = 3
                            end = mid;
                        }
                    } else if(nums[mid] < target) { // target = 2, 3, 4
                        if(target < nums[end]) { // target = 2, 3
                            start = mid + 1;
                        } else if (target == nums[end]) {  // target = 4
                            return end;
                        } else if (target < nums[start]) {  // target = 4
                            return -1;
                        } else if (target == nums[start]) {  // target = 4
                            return start;
                        } else {  // target = 11
                            end = mid;
                        }
                    } else { // target = 7
                        return mid;
                    }
                } else { // 4 5 6 7 8 1 2
                    return -1;
                }
            } else {
                if(target == nums[start])
                    return start;
                else if(target == nums[end])
                    return end;
                else
                    return -1;
            }
        }
        return -1;
    }
};
