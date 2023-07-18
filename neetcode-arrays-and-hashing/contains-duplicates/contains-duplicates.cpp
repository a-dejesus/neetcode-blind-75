#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) 
{
        // Input nums[1, 2, 3, 1]
        // Output TRUE if a value in the array is duplicated, false if every element is unique
        // Core issue: we need to cycle through these values and keep track of them to determine the SUCCESS case
        // Brute force: use a for loop for each of the numbers to look through the array but this gives O(n^2) time complexity
        // Core solution: use a hash set(which is a hash map that just cares about the value and not the key)
        // Recipe:  Declare an int hash set -> cycle through the array and load the values into the hash set and check if we have seen 
        //          the value before -> if not, add the value to the hash set
        std::unordered_set<int> hset;

        for(auto num : nums)
        {
            if (const auto it = hset.find(num); it != hset.end())
            {
                return true;
            } 
            hset.insert(num);
        } 
        return false;
    
}

int main() {
    // Test case 1
    std::vector<int> nums1 = {1, 2, 3, 1};
    bool result1 = containsDuplicate(nums1);
    std::cout << "Test case 1: " << (result1 ? "true" : "false") << std::endl;

    // Test case 2
    std::vector<int> nums2 = {1, 2, 3, 4};
    bool result2 = containsDuplicate(nums2);
    std::cout << "Test case 2: " << (result2 ? "true" : "false") << std::endl;

    // Test case 3
    std::vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    bool result3 = containsDuplicate(nums3);
    std::cout << "Test case 3: " << (result3 ? "true" : "false") << std::endl;

    return 0;
}