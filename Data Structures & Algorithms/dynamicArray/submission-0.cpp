class DynamicArray {
public:
    vector<int> arr;
    DynamicArray(int capacity) {
        arr.reserve(capacity);
    }

    int get(int i) {
        return arr.at(i);
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        arr.push_back(n);
    }

    int popback() {
        int n = arr.back();
        arr.pop_back();
        return n;
    }

    void resize() {

    }

    int getSize() {
        return arr.size();
    }

    int getCapacity() {
        return arr.capacity();
    }
};
