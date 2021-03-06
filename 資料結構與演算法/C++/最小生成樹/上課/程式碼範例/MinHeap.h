#ifndef MINHEAP_H
#define MINHEAP_H
#include <cassert>
using namespace std;
template <class Item>
class MinHeap {
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k) {
        while (k > 1 && data[k / 2] > data[k]) {
            swap(data[k / 2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;
            if (j + 1 <= count && data[j + 1] < data[j]) {
                j++;
            }

            if (data[k] <= data[j]) {
                break;
            }

            swap(data[k], data[j]);
            k = j;
        }
    }

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        count = 0;
        data = new Item[capacity + 1];
    }

    MinHeap(Item arr[], int n) {
        data = new Item[n + 1];
        capacity = n;
        for (int i = 0; i < n; i++) {
            data[i + 1] = arr[i];
        }
        count = n;
        //Heapify
        for (int i = count / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }

    ~MinHeap() {
        delete[] data;
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Item item) {
        assert(count + 1 <= capacity);
        data[count + 1] = item;
        shiftUp(count + 1);
        count++;
    }

    Item extractMin() {
        assert(count > 0);
        Item item = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return item;
    }

    Item getMin() {
        assert(count > 0);
        return data[1];
    }
};
#endif