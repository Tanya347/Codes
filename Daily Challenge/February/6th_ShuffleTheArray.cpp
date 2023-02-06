/******************************************************************* QUESTION *******************************************************************************/

/*

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
 

Constraints:

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3

*/

/******************************************************************* MY CODE *******************************************************************************/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int j = 1;
        for(int i = n; i < 2*n; i++) {
            int element = nums[i];
            nums.erase(nums.begin() + i);
            nums.insert(nums.begin() + j, element);
            j = j + 2;
        }

        return nums;
    }
};

/******************************************************************* BIT MANIPULATION *******************************************************************************/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        // storing pairs in the numbers from n to 2n - 1
        // as the limit is upto 1000 which has 10 bits in binary representation
        // we can store two such numbers in one 32 bit integer

        for(int i = n, j = 0; i < 2*n, j < n; i++, j++) {

            // left shift by 10 to create space 
            nums[i] = nums[i] << 10;

            // or operation with zeroes sets the right bits and stores the numbers
            nums[i] |= nums[j];
        }

        // now with two variables i (0 -> n - 1) and j (n -> 2 * n)
        // i and i + 1 will be converted to numbers stored in jth element
        // i will be updated by 2 and j will be updated by 1

        for(int i = 0, j = n; i < 2*n - 1, j < 2*n; i += 2, j++) {
            
            // 1023 is 1111111111 i.e. 10 bit number with all 1s
            // hence when we perform and with 1023 the number stored in last 10 bits
            // is restored and number stored before becomes 0
            nums[i] = nums[j] & 1023;

            // now right shift by 10 to restore original number
            nums[i + 1] = nums[j] >> 10;
        }

        return nums;
    }
};

