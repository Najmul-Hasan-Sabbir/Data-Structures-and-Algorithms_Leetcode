class Solution {
public:
/*
1. Here i wil be using the sliding window approach as there is fixed window size k 
2. I will make a is_vowel func to check if its vowel or not 
3. then i will first find the first window val 
4. then for the rest we will go one by one and check what max val can we get 



*/


      bool is_vowel(char c){

      
      if((c=='a')||(c=='e') ||(c=='i')||(c=='o')||(c=='u')){
        
        return true;

      }
      return false;

      }

    int maxVowels(string s, int k) {
        
     int curr_count=0;
     int max_count=0;

      for(int i=0; i<k; i++){

        if(is_vowel(s[i])){
            curr_count++;
        }
      }
      max_count=curr_count;

      for(int i=k; i<s.length(); i++){
     
       if(is_vowel(s[i-k])){
        curr_count=curr_count-1;
       }
        
            if(is_vowel(s[i])){
                curr_count++;
            }
        
        if(curr_count>max_count){
            max_count=curr_count;
        }

      }

return max_count;
    }
};