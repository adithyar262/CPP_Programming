/*
152. Maximum Product Subarray
https://leetcode.com/problems/maximum-product-subarray/
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], minProduct = nums[0], product = nums[0];
        int arrSize = nums.size();
        for(int i = 1; i < arrSize; ++i) {
            int tempMaxProduct = maxProduct * nums[i];
            int tempMinProduct = minProduct * nums[i];
            maxProduct = max({tempMaxProduct, tempMinProduct, nums[i]});
            minProduct = min({tempMaxProduct, tempMinProduct, nums[i]});
            product = (product > maxProduct) ? product : maxProduct;
        }
        
        return product;
    }
};
