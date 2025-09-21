**Theory**
[https://leetcode.com/problems/binary-subarrays-with-sum/](https://leetcode.com/problems/binary-subarrays-with-sum/)

class Solution {
public:
    int f(vector<int>& nums , int goal){
        int n = nums.size(); 
        if(goal < 0) return 0;
        int l = 0, r = 0;
        int ans = 0, sum = 0;

        while(r < n){
            sum += nums[r];
            while(sum > goal){ // let's start shrinking
                sum -= nums[l++];
            }
            // this shrinking while loop is making sure that your condition (sum <= goal) is not violated.
            ans = ans + (r - l + 1); 
            // no of subarrays ending at r(b/w l & r) having prefix sum <= goal is f(goal)
            r++;
        }
        return ans;
    } 

    int numSubarraysWithSum(vector<int>& nums, int goal) {
         return (f(nums, goal) - f(nums, goal - 1));
    }

    // 1+2+3+4+5 = 5*(5+1)/2 - we can figure out all subarrays like this by summing all subarray ending at i
    // f(goal) => no of subarrays having sum <= goal (sum = 0,1,2)
    // f(goal) - f(goal-1) = no of subarrays having sum = goal

    /*
    Example:
    f(2) - no of subarrays such that sum <= 2 
    f(1) - no of subarrays such that sum <= 1

    f(2) = 1+2+3+4+4 = 14
    f(1) = 1+2+2+3+2 = 10

    sum=0 => {0}, {0} - 2
    sum=1 => {1}, {1,0}, {0,1}, {0,1,0}, {1}, {1,0}, {0,1}, {1} - 8
    sum=2 => {1,0,1}, {1,0,1,0}, {0,1,0,1}, {1,0,1} - 4

    f(2) = 14
    f(1) = 10
    */

    /*
    Subarray breakdown:
    1       - All the subarrays ending at this 1 -> 1
    1,0     - All the subarrays ending at this 0 -> 2
    1,0,1   - All the subarrays ending at this 1 -> 3 (101, 01, 1)
    1,0,1,0 - All the subarrays ending at this 0 -> 4
    0,1,0,1 - All the subarrays ending at this 1 -> 4
    */

    /***********************************************************
    Sliding window technique:
    Two ways to explore all subarrays of a problem:
    1. All the subarrays ending at indices i -> (r-l+1) approach
    2. All the subarrays starting at indices i -> (n-r) approach
    ************************************************************/
};

/*
---------------------------------------------------------------
Second solution - Map method
---------------------------------------------------------------

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        mp[sum] = 1;
        int count = 0;

        for(auto i : nums){
            sum += i;
            if(mp.find(sum-k) != mp.end()){
                count += mp[sum-k];
            }
            mp[sum]++;
        }
        return count;  
    }
};
*/


*****************************************************************************************************************

**Theory - Articles**

[https://www.scaler.com/topics/sliding-window-algorithm/](https://www.scaler.com/topics/sliding-window-algorithm/)

[https://www.geeksforgeeks.org/window-sliding-technique/](https://www.geeksforgeeks.org/window-sliding-technique/)

**Questions -**

[https://www.geeksforgeeks.org/smallest-subarray-containing-minimum-and-maximum-values/](https://www.geeksforgeeks.org/smallest-subarray-containing-minimum-and-maximum-values/)

[https://stackoverflow.com/questions/37194842/find-minimum-length-subarray-that-has-all-numbers](https://stackoverflow.com/questions/37194842/find-minimum-length-subarray-that-has-all-numbers)

[https://leetcode.com/problems/max-consecutive-ones-iii/description/](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

[https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-ii/)

[https://leetcode.com/problems/longest-substring-without-repeating-characters/description/](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)

[https://leetcode.com/problems/permutation-in-string/description/](https://leetcode.com/problems/permutation-in-string/description/)

[https://leetcode.com/problems/longest-repeating-character-replacement/description/](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

[https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/)

[https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template/](https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template/)

**Posts -**

[https://leetcode.com/discuss/post/136523/sliding-window-algorithm-template-to-sol-i4az/](https://leetcode.com/discuss/post/136523/sliding-window-algorithm-template-to-sol-i4az/)

[https://leetcode.com/discuss/post/5831547/sliding-window-cheat-sheet-by-monika_15f-01kw/](https://leetcode.com/discuss/post/5831547/sliding-window-cheat-sheet-by-monika_15f-01kw/)

[https://leetcode.com/discuss/post/490184/sliding-window-understanding-the-pattern-gffb/](https://leetcode.com/discuss/post/490184/sliding-window-understanding-the-pattern-gffb/)


**92 Medium level problems -**

[https://leetcode.com/problem-list/sliding-window/](https://leetcode.com/problem-list/sliding-window/)

- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)

- [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/description/)

- [Count Number of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays)

- [Contiguous Array](https://leetcode.com/problems/contiguous-array/description/)

- [Count Subarrays Where Max Element Appears at Least K Times](https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/)

- [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/)

- [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/)

- [Number of Sub-arrays of Size K and Average Greater Than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/)

- [Longest Subarray of 1s After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/)

- [Count Complete Subarrays in an Array](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)

- [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/)

- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/description/)

- [Count the Number of Good Subarrays](https://leetcode.com/problems/count-the-number-of-good-subarrays/description)

- [Find all anagrams in a string](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)
