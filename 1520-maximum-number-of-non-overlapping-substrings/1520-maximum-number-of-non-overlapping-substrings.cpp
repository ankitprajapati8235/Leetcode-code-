class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int>first(26, n);
        vector<int>last(26, -1);

        for(int i=0; i<n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals;

        for(int c=0; c<26; c++) {

            if(last[c] == -1) 
            continue;

            int left = first[c];
            int right = last[c];
            bool valid = true;

            for(int i=left; i<=right; i++) {
                int ch = s[i] - 'a';

                if(first[ch] < left) {
                    valid = false;
                    break;
                }
                right = max(right, last[ch]);
            }
            if(valid) {
                intervals.push_back({left, right});
            }
        }

        sort(intervals.begin(), intervals.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                if(a.second == b.second)
                return a.first > b.first;
                return a.second < b.second;
            });

        vector<string> ans;
        int end = -1;

        for(auto[left, right] : intervals) {
            if(left > end) {
                ans.push_back(s.substr(left, right - left + 1));
                end = right;
            }
        }
        return ans;
    }
};