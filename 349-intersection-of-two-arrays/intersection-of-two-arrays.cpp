class Solution {
public:

// this is the brute force approch , im just testing the logic 
// after that i will use the Two poiters or Hash map solution 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      
 // Step 1: Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
vector<int> result;

        int i = 0; // pointer for nums1
        int j = 0; // pointer for num

        while(i<nums1.size()&& j<nums2.size()){

      
      if(nums1[i]==nums2[j]){
        // To ensure uniqueness in result
if(result.empty()|| result.back()!=nums1[i]){

    result.push_back(nums1[i]);
}



        i++;
        j++;
      }
       // If nums1 element is smaller, move i
      else if(nums1[i]<nums2[j]){
        i++;
      }
        // If nums2 element is smaller, move j
      else{
        j++;
      }


        }


return result;
    }
};