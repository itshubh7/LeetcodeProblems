class SmallestInfiniteSet {
public:
    unordered_map<int,int> m;  // Keeps track of popped elements
    int count = 1;             // Tracks the next smallest available number
    
    SmallestInfiniteSet() {
        count = 1;
    }
    
    // Pops the smallest element
    int popSmallest() {
        // Skip over numbers that have been popped (present in the map)
        while (m.find(count) != m.end()) {
            count++;
        }
        // Mark the number as popped and return it
        m[count]++;
        return count;
    }
    
    // Adds a number back into the set
    void addBack(int num) {
        auto it = m.find(num);
        // If the number was previously popped, remove it from the map
        if (it != m.end()) {
            m.erase(it);
        }
        // Reset `count` to the added back number if it's smaller than the current `count`
        if (num < count) {
            count = num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */