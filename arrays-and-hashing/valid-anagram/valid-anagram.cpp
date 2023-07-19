#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
    // Input: two strings
    // Output: boolean t/f
    // Info: anagrams are words that will contain all letters exactly once - end up being the same length array, will match when sorted
    // Core Issue: Hard to tell anagrams without checking all of the characters 
    // Brute Force: Nested for loops to check for exact match
    // Core Solution: Use 2 hash maps - keep count of the letters and compare hashmaps with each other, this gives O(n) TC
    std::unordered_map<char, int> hmap_s, hmap_t;
    for(const auto it_s : s)
    {
        hmap_s[it_s]++;
    }

    for(const auto it_t : t)
    {
        hmap_t[it_t]++;
    }
    // we have the two strings in the hmaps - now to compare them

    for(auto pair: hmap_s)
    {
        if (hmap_t[pair.first] != pair.second)
        {
            return false;
        }
    }
    return true;
}


int main() {
    // Test cases
    vector<pair<string, string>> test_cases = {
        {"anagram", "nagaram"},  // true
        {"listen", "silent"},  // true
        {"hello", "world"},  // false
        {"aaabbb", "bbaaab"},  // true
        {"", ""},  // true
        {"aab", "abb"}  // false
    };

    for (const auto& test_case : test_cases) {
        const string& s = test_case.first;
        const string& t = test_case.second;
        cout << "isAnagram(" << s << ", " << t << ") = " << (isAnagram(s, t) ? "true" : "false") << endl;
    }

    return 0;
}