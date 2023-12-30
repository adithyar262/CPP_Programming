/*
371. Sum of Two Integers
https://leetcode.com/problems/sum-of-two-integers/

Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
*/

class Solution {
public:
    int getSum(int a, int b) {
        bool carry = false;
        int sum = 0;
        for(int i = 0; i < sizeof(int) * 8; ++i) {
            bool tempA = (a & (1 << i));
            bool tempB = (b & (1 << i));
            bool tempSum = tempA ^ tempB ^ carry;
            carry = (tempA & tempB) | (tempB & carry) | (tempA & carry);
            sum = sum | (tempSum << i);
        }
        return sum;
    }
};
