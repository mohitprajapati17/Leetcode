class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int x=0;
        int sum=0;
        for(auto& it: requests ){
            sum+=abs(x-it);
            x=it;
        }
        return sum;
    }
};