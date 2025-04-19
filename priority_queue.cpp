#include <iostream>
#include <vector>

//min heap implementation
class PriorityQueue {
public:
  PriorityQueue() {}
  void insert(int ele) {
    heap.push_back(ele);
    bubbleUp();
  }
  int peek() {
    if (heap.empty()) {
      std::cout << "error peeking: heap is empty!\n";
      return -1;
    }
    return heap[0];
  }
  int pop() {
    if (empty()) {
      std::cout << "error popping: empty heap" << std::endl;
      return -1;
    }
    int tmp = heap[0];
    heap[0] = heap.back();
    heap[heap.size() - 1] = tmp;
    heap.pop_back();
    bubbleDown(0);
    return tmp;
  }

  bool empty() { return heap.size() == 0; }
  void heapToString() {
    using std::cout;
    cout << "[ ";
    for (int e : heap) {
      cout << e << ", ";
    }
    cout << ']' << std::endl;
  }

private:
  /*
  left child is 2i + 1
  right child is 2i + 2
  parent is (i-1) / 2
  */
  std::vector<int> heap;
  void bubbleUp() {
    int idx = heap.size() - 1;
    while (idx > 0) {
      int parent = heap[(idx - 1) / 2];
      if (parent > heap[idx]) {
        heap[((idx - 1) / 2)] = heap[idx];
        heap[idx] = parent;
      } else {
        break;
      }
      idx = (idx - 1) / 2;
    }
  }
  void bubbleDown(int idx) {
    int size = heap.size();
    while (true) {
      int left = idx * 2 + 1;
      int right = idx * 2 + 2;
      int smallest = idx;

      if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
      }
      if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
      }
      if (smallest != idx) {
        std::swap(heap[idx], heap[smallest]);
        idx = smallest;
      } else {
        break;
      }
    }
  }
};

int main() {
  using std::cout;
  PriorityQueue pq = PriorityQueue();
  // pq.peek();
  pq.insert(3);
  pq.insert(10);
  pq.insert(7);
  pq.insert(14);
  pq.insert(5);
  pq.insert(12);
  pq.insert(2);
  while (!pq.empty()) {
    int top = pq.pop();
    cout << "top popped " << top << std::endl;
    pq.heapToString();
  }
}