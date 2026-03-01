class RecentCounter {
public:

/*

My intuition:
1. we first make a Q and then when we get each ping 
2. we will push that ping in the queue 
3. then we will check the range by doing t -3000,t and then if any smaller val found then the t-3000 we will simply remove it 
4. then no need to count the nums of ping , just return the size of the queue as we have already removed if any val was smaller , in this way we no need to count it again



*/


    queue<int> q;

    RecentCounter() {}

    int ping(int t) {
        q.push(t);

        while (q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */