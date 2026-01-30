class Solution {
public:

/*
Here i will be using two poiters approch 
1. put the two pointers in start and end 
2. go to check char and send it to a function to check if its a normal char or non -alpha , 
3. if the char is a non-alpha on any poiters then move that pointers and ignore this char 
4. we will onlly check (i=j) when both pointers are on a valid char 
5. convert both char in lower case for safty 


## in this a better aproch than string reversal as 
time : O(n)
space O(1)
where as in string reversal 
time: O(n)
space : O(n)----- > extra space for the reversal 

*/


bool check_alpha(char c){
     

   
     if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
     {
return true;

     }
     else{
        return false;
     }


   }




    bool isPalindrome(string s) {
        
        int left=0;
        int right=s.size()-1;

   


        while(left<right){

         

         if(!check_alpha(s[left])){
            left++;

         }
         else if(!check_alpha(s[right])){
            right--;
         }
         else{
// tolower ensures 'A' == 'a'
  if(tolower(s[left]) != tolower(s[right])) {
            return false;
          }

           left++;
           right--;
         }


        }


return true;
    }
};