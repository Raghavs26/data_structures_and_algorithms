#include <bits/stdc++.h>
using namespace std;

class CustomStack {
   private:
    vector<int> st;
    vector<int> incrementTracker;

   public:
    CustomStack(int maxSize) {
        incrementTracker = vector<int>(maxSize, 0);
    }

    void push(int x) {
        if (st.size() >= incrementTracker.size()) return;
        st.push_back(x);
    }

    int pop() {
        if (st.empty()) return -1;

        int index = st.size() - 1;
        int poppedElement = st[index];
        poppedElement += incrementTracker[index];
        if (index > 0) {
            incrementTracker[index - 1] += incrementTracker[index];
        }
        incrementTracker[index] = 0;
        st.pop_back();
        return poppedElement;
    }

    void increment(int k, int val) {
        int index = min(k, (int)st.size()) - 1;
        if (index >= 0) {
            incrementTracker[index] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {
    return 0;
}