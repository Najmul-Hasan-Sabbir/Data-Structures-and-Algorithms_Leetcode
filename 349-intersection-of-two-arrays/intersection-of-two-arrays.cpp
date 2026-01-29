class Solution {
public:

// this is the brute force approch , im just testing the logic 
// after that i will use the Two poiters or Hash map solution 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        for(int i=0; i<nums1.size();i++){

        for(int j=0; j<nums2.size(); j++){

         if(nums1[i]==nums2[j]){

            if(find(result.begin(), result.end(), nums1[i]) == result.end()){
                result.push_back(nums1[i]);
            }
         }

        }

        }


return result;

    }
};