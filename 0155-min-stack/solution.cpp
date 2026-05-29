class MinStack {
public:
    vector<int> arr;
    int topIdx;
    int mini;

    MinStack() {
        arr.resize(100000);
        topIdx = -1;
        mini = INT_MAX;
    }

    void push(int val) {
        mini = min(mini, val);

        arr[++topIdx] = val;
        arr[++topIdx] = mini;
    }

    void pop() {
        if (topIdx == -1) return;

        topIdx -= 2;

        if (topIdx != -1)
            mini = arr[topIdx];
        else
            mini = INT_MAX;
    }

    int top() {
        return arr[topIdx - 1];
    }

    int getMin() {
        return arr[topIdx];
    }
};
