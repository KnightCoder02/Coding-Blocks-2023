#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }

        for(auto &x : mp){
            if(x.second != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
}