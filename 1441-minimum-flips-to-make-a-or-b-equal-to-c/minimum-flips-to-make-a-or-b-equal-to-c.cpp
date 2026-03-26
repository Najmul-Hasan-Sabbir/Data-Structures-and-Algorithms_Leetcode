class Solution {
public:
    int minFlips(int a, int b, int c) {
        
/*
My intuition:
STEP 1 → dont convert to binary string
         use right shift >> to access each bit directly
         use & 1 to check if that bit is 0 or 1

STEP 2 → loop through all 32 bit positions
         at each position extract bitA , bitB , bitC

STEP 3 → ask what does c WANT at this position?

         c wants 1 →
              both a=0 and b=0 → +1 flip
              else → already fine , 0 flips

         c wants 0 →
              each 1 in a or b is a problem
              
              




*/



     
     int flips=0;

     for(int i=0; i<32; i++){

       int bitA=(a>>i)&1;
       int bitB=(b>>i)&1;
       int bitC=(c>>i)&1;




       if(bitC==1){

        if(bitA==0 && bitB==0){
            flips+=1;
        }

       }
       else{
        if(bitA==1 && bitB==1){
            flips+=2;
        }
        else if(bitA==0 && bitB==0){

        }
        else{
            flips+=1;
        }

        
       }


     }





return flips;
    }
};