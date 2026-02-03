class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        int max_altitude=0;
         int curr_altitude=0;
        for(int i=0; i<gain.size(); i++){
            
            curr_altitude+=gain[i];
            if(curr_altitude>max_altitude) {
                max_altitude=curr_altitude;
            }

        }


return max_altitude;

    }
};