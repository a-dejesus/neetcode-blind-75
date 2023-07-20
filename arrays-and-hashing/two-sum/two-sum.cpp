#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
            // Input: array[2,7,11,15]
        // Output: array[0, 1] indeces that add up to target
        // Brute Force: nested for loop, O(n^2)
        // Efficient Solution: Put array into hash map, complement is found with target - i 

        std::unordered_map<int, int> map;

        auto complement = 0;

        for(auto i = 0; i < nums.size(); i++)
        {
            complement = target - nums[i];

            for (auto it = map.find(complement); it != map.end();)
            {
                return {it->second , i};
                //return the array
            }

            map.insert({nums[i], i});
        }
        return {};
}


int main() {
    // Test case
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    // Print the result
    cout << "Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}