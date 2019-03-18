#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <climits>
using namespace std;
class Solution {
public:
    int binS(int l,int r,vector<int>&nums){
        if(r-l==1){
            if(nums[r]>nums[l]) return l;
            else return r;
        }
        int au=nums[(l+r)/2]>nums[0];
        if(au==1){
            return binS((l+r)/2,r,nums);
        }
        else{
            return binS(l,(l+r)/2,nums);
        }
    }
    int findMin(vector<int>& nums) {
        int o=INT_MAX;
        int a;
        if(nums.size()==1) return nums[0];
        a= binS(0,nums.size()-1,nums);
        if(a!=nums.size()-1){
            o=nums[a+1];
        }
        if(o>nums[a])o=nums[a];
        if(o>nums[nums.size()-1]) o=nums[nums.size()-1];
        if(o<nums[0]) return o;
        return nums[0];
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMin(nums);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
