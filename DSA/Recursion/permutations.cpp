#include <vector>
using namespace std;

void perm(vector<int> bal, vector<int> tn, vector<vector<int>>& ans){
  if(bal.size()==0){
    ans.push_back(tn);
    return;
  }
  for(int i=0;i<bal.size();i++){
    tn.push_back(bal[i]);
    vector<int> na;
    for(int j=0;j<bal.size();j++){
      if(j!=i) na.push_back(bal[j]);
    }
    perm(na,tn,ans);
    tn.pop_back();
  }
}
vector<vector<int>> getPermutations(vector<int> array) {
  if(array.size()==0) return {};
  vector<vector<int>> ans;
  vector<int> arr;
  perm(array, arr, ans);
  return ans;
}
