class Solution {
  public:
  void rec(int n){
      if(n==1){
          cout<<n<<" ";
          return;
      }
      cout<<n<<" ";
      rec(n-1);
     }
    void printNos(int n) {
        // code here
        rec(n);
    }
};