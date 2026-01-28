class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

/*

# ------ Wrong thinking ------------# we should not use stack in here as there is no Undo or nested think 
1. another approach can be using stack as here we have to remember our next or previous step so we can use stack such as , we will insert the val and while check it if the current top is 0 and next/current val is also 0 then , n-- and if n becomes 0 then return true or false



# ------ Right thinking ------------# Use the Greedy approach 

*/


int count=0;
for(int i=0;i<flowerbed.size(); i++){

if(flowerbed[i]==0){



bool left=(i==0)|| (flowerbed[i-1]==0);

bool right=(i==flowerbed.size()-1)|| (flowerbed[i+1]==0);

if(left&&right){

    flowerbed[i]=1;
    count++;

}


if(count>=n){
    return true;
}
}



}


return count>=n;
    }
};