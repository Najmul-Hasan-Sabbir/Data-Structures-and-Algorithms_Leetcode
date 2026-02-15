/* My intuition:
1. Since I start with $0, if the first customer gives anything but $5, I can't give change.
2. I need to keep track of $5 and $10 bills because $20 bills are useless for giving change.
3. For a $20 bill, I greedily give a $10 and a $5 first. This is because $5 bills are more 
   "powerful"—they can change both $10s and $20s, so I want to save them as much as possible!
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int five_note = 0;
        int ten_note = 0;

        for (int i = 0; i < n; i++) {
            
            // Customer gives me $5, I just take it
            if (bills[i] == 5) {
                five_note++;
            }
            
            // Customer gives me $10, I MUST give back a $5.
            else if (bills[i] == 10) {
                if (five_note == 0) return false; // Oh no, I have no $5 to give back!
                
                ten_note++;  // Now I have a $10 in my pocket
                five_note--; // But I lost one $5
            }
            
            // Customer gives me $20, I need to give back $15.
            else if (bills[i] == 20) {
                // First, I'll try to get rid of my $10 bill and one $5 bill.
                if (five_note > 0 && ten_note > 0) {
                    five_note--;
                    ten_note--;
                }
                // If I don't have a $10, I check if I have three $5 bills.
                else if (five_note > 2) {
                    five_note -= 3;
                }
                // If I can't do either, I can't serve this customer.
                else {
                    return false;
                }
            }
        }

       
        return true;
    }
};