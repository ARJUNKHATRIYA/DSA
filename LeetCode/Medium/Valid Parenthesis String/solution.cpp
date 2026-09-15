class Solution {
public:
    bool checkValidString(string s) {
        int right=0;
        
        int star=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                right++;
            }else if(s[i]==')'){
                if(right>0){
                    right--;
                }else if(star>0){
                    star--;
                }else {
                    return false;
                }
                
            }else{
                star++;
            }
        }
        right=0;
        star=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                right++;
            }else if(s[i]=='('){
                if(right>0){
                    right--;
                }else if(star>0){
                    star--;
                }else {
                    return false;
                }
                
            }else{
                star++;
            }
        }
       
            
        return true;
    }
};