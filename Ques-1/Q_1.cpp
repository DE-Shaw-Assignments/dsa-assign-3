class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int l=str.length();
        if(l<2){
            return l;
        }
        int left=0;
        int right=1;
        int count=1;
        set<char>s;
        s.insert(str[left]);
        while(right< str.size()){
            if(s.find(str[right]) != s.end()) {
                s.erase(str[left]);
                left++;
            }
            else{
                s.insert(str[right]);
                count = max(count, (int)s.size());
                right++;
            }
        }

        return count;
    }
};