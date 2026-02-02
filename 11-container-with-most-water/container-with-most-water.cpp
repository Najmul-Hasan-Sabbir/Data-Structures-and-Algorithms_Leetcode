class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_val = 0;
int n = height.size();
   int left=0; 
   int right=n-1;
    int max_water=0;
   while(left<right){

// 1. Calculating the current width
   int weidth=right-left;
// 2. The water level is limited by the shorter stick
   int curr_height=min(height[left],height[right]);
   
   int area=curr_height*weidth;

   if(area>max_water){
    max_water=area;
   }


// 4. Move the pointer pointing to the shorter stick
            // (Looking for a taller wall to offset the loss in width)

   if(height[left]<height[right]){
  
  left++;


   }
else{
    right--;
}



   }

return max_water;
    }
    
};