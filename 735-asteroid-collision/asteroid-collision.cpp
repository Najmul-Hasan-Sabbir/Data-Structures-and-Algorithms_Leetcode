class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // We use a vector to act as our 'space' (stack)
        vector<int> st;

        for (int ast : asteroids) {
            // 'alive' acts like a shield. If it's true, the asteroid is still moving.
            bool alive = true;

            /* The "Battle" Loop: 
               A collision only happens if:
               1. The current asteroid is moving LEFT (ast < 0)
               2. The asteroid in front of it is moving RIGHT (st.back() > 0)
            */
            while (alive && !st.empty() && ast < 0 && st.back() > 0) {
                
                // Case 1: The newcomer is bigger
                if (abs(ast) > st.back()) {
                    // The asteroid on the stack explodes.
                    st.pop_back(); 
                    // 'alive' stays true because the newcomer keeps moving.
                } 
                // Case 2: They are equally strong
                else if (abs(ast) == st.back()) {
                    // Both go boom. Remove the one on stack and mark current as dead.
                    st.pop_back();
                    alive = false; 
                } 
                // Case 3: The newcomer is smaller
                else {
                    // The current asteroid explodes. Stop the loop.
                    alive = false;
                }
            }

            // If the asteroid survived the battles (or had no one to fight), add it to space
            if (alive) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};