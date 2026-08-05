class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
       int n=tasks.size();
       vector<long long> pref(n,0);
       pref[0]=tasks[0];
       vector<int> ans;
       for(int  i=1;i<n;i++) pref[i]=pref[i-1]+tasks[i];

       long sh=0;
       for(int  i=0;i<shifts.size();i++){
          sh+=shifts[i];
          auto it = upper_bound(pref.begin(), pref.end(), sh);
          int x = it - pref.begin();
          ans.push_back(n-x);
          if(ans[i]==0) sh=0;
       }
       return ans;

    }
};