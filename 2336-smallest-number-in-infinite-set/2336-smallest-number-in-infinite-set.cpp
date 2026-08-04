class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> inPQ;
    int next = 1;

public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (!pq.empty()) {
            int smallest = pq.top();
            pq.pop();
            inPQ.erase(smallest);
            return smallest;
        }
        return next++;
    }

    void addBack(int num) {
        if (num < next && !inPQ.count(num)) {
            pq.push(num);
            inPQ.insert(num);
        }
    }
};