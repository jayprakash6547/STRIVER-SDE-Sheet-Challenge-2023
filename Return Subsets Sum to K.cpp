



void generateSubsetSumtok(int index,int sum,int k,vector<int>&nums,vector<vector<int>>&st,vector<int>&v){
    if(index==nums.size()){
        if(sum==k)st.push_back(v);
        return;
    }
    generateSubsetSumtok( index+1, sum, k, nums, st, v);
    v.push_back(nums[index]);
    generateSubsetSumtok(index+1,sum+nums[index],k,nums,st,v);
    v.pop_back();
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
   vector<vector<int>>st;
   vector<int>v;
   generateSubsetSumtok(0,0,k,arr,st,v);
   return st;
}