class Solution {
public:
    int sum(int &num){
        int s =0;
        while(num!=0){
            s+=num%10;
            num/=10;
        }
        return s;
    }
    int smallestIndex(vector<int>& nums) {
        int n =nums.size();
       
        for(int i=0;i<n;i++){
            int num = nums[i];
            int t = sum(num);
            if(t==i){
                return i;
            }
        }
        return -1;
    }
};