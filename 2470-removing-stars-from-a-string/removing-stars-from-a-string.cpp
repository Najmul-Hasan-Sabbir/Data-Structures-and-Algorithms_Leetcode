class Solution {
public:
/*
My Intuition:
1. When i was that when i see a * i have to remove the previous char it seems like a undo feature or similar to the valid parenthesis problem 
2. To solve this we need to use stack , we will push if we get normal char but if we get any star char then we will pop() the last val 
3. As we know we can use string as a stack and here we need to return a string that why i will use string as a stack.




*/
    string removeStars(string s) {
        
       string st;

        for(int i:s){
           
           if(i=='*' ){
            if(st.empty()) return " ";
              st.pop_back();

           }
           else{
            st.push_back(i);
           }

        }



return st;
    }
};