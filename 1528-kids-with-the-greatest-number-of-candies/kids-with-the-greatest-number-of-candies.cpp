class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
/*
1. first from the vector get the max val and store it
2. make a vector with bool in size n candies 
3. use loop where we will check every time child[i]+extraCandies>=max_val
then true or false 

*/
int n=candies.size();
vector<bool>result(n);

int max_val=*max_element(candies.begin(),candies.end());


for(int i=0; i<n; i++){

  if(candies[i]+extraCandies>=max_val){

    result[i]=true;
  }
  else{
    result[i]=false;
  }

}
return result;
    }
};