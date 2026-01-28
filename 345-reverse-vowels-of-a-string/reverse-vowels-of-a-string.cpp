class Solution {
public:

// in this function we are checking if the char is vowel or not and returning true or false 
     bool is_vowel(char c){


        c=tolower(c);
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
     }



    string reverseVowels(string s) {
        
    int left=0;
    int right=s.length()-1;

    
    while(left<right){

     
     if(!is_vowel(s[left])){
        left++;
     }
     else if(!is_vowel(s[right])){

        right--;
     }
     // if both are vowels 
     else{
       char c=s[left];
        s[left]=s[right];
        s[right]=c;
        left++;
        right--;
     }


    }


return s;
    }
};