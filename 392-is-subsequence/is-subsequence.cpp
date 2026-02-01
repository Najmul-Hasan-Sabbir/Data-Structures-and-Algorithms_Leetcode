class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        bool found=false;

     if(s.empty() && t.empty()){
        return true;
     }

     for(int i=0,j=0; i<t.length(); i++){
      
      if( s[j]==t[i]){
        j++;
      }

      if(j==s.length()){

        found=true;
         return true;
      }
     


     }


return found;
    }
};