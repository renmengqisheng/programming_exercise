class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> v;
        if(num.empty()) return v;
        deque<int> dq;
        int l = 0;
        int r = 0;
        while(r < num.size())
        {
            while(!dq.empty() && num[dq.back()] < num[r]) dq.pop_back();
            dq.push_back(r);
            if(dq.front()+size == r) dq.pop_front();
            if(r-l+1 == size) v.push_back(num[dq.front()]), l++;
            r++;
        }
        return v;
    }
};
