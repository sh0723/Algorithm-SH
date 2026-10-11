#include <cassert>
#include <iostream>
#include <stdexcept>
using namespace std;
class MinHeap {
public:
    MinHeap();
    ~MinHeap();

    void push(int value);
    void pop();

    int& top();

    int size() const;
    int capacity() const;
    bool empty() const;

    void clear();
    void reserve(int newCapacity);

private:
    int* data;
    int current_size;
    int current_capacity;

    void siftUp(int index);
    void siftDown(int index);
};
 // 10:50 시작
MinHeap::MinHeap(): data(nullptr), current_size(0), current_capacity(0) {}
MinHeap::~MinHeap() {
    clear();
    delete[] data;
}

void MinHeap::push(int value) {
    if (current_capacity == current_size) {
        reserve(current_capacity == 0 ? 1 : current_capacity * 2);
    }

    data[current_size] = value;
    current_size++;
    siftUp(current_size-1);
}
void MinHeap::pop() {
    if (current_size == 0) return;

    data[0] = data[--current_size];
    if (current_size == 0) return;

    siftDown(0);
}

int& MinHeap::top() {
    if (current_size == 0) throw out_of_range("Heap is Empty.");

    return data[0];
}

int MinHeap::size() const {
    return current_size;
}
int MinHeap::capacity() const {
    return current_capacity;
}
bool MinHeap::empty() const {
    return current_size == 0;
}

void MinHeap::clear() {
    current_size = 0;
}
void MinHeap::reserve(int newCapacity) {
    if (newCapacity <= 0 || newCapacity <= current_capacity) return;

    int *newData = new int[newCapacity];
    for (int i=0; i<current_size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    current_capacity = newCapacity;
}
void MinHeap::siftUp(int index) {
    while(index > 0) {
        int parent = (index-1) / 2;
        if (data[parent] < data[index]) break;
        swap(data[parent], data[index]);
        index = parent;
    }
}
void MinHeap::siftDown(int index) {
    while(index < current_size) {
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int smallest = index;

        if (left < current_size && data[left] < data[smallest]) {
            smallest = left;
        }

        if (right < current_size && data[right] < data[smallest]) {
            smallest = right;
        }

        if (smallest == index) break;

        swap(data[index], data[smallest]);
        index = smallest;
    }
}
int main() {
    MinHeap heap;

    // 1. 초기 상태
    assert(heap.empty());
    assert(heap.size() == 0);
    assert(heap.capacity() == 0);

    // 2. 빈 힙 pop
    heap.pop();

    assert(heap.empty());
    assert(heap.size() == 0);

    // 3. 빈 힙 top 예외
    bool exceptionThrown = false;

    try {
        heap.top();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 4. 첫 push
    heap.push(30);

    assert(!heap.empty());
    assert(heap.size() == 1);
    assert(heap.capacity() == 1);
    assert(heap.top() == 30);

    // 5. siftUp 확인
    heap.push(20);

    assert(heap.size() == 2);
    assert(heap.capacity() == 2);
    assert(heap.top() == 20);

    heap.push(10);

    assert(heap.size() == 3);
    assert(heap.capacity() == 4);
    assert(heap.top() == 10);

    heap.push(40);
    heap.push(5);

    assert(heap.size() == 5);
    assert(heap.capacity() == 8);
    assert(heap.top() == 5);

    // 현재 값:
    // 30, 20, 10, 40, 5
    // 최소 힙 top은 5

    // 6. 중복값 삽입
    heap.push(5);
    heap.push(10);

    assert(heap.size() == 7);
    assert(heap.top() == 5);

    // 7. top 참조 반환 확인
    // 주의: top 값을 직접 수정하면 힙 조건이 깨질 수 있음
    int& topRef = heap.top();
    assert(topRef == 5);

    // 8. pop 순서 확인
    int expected1[] = {5, 5, 10, 10, 20, 30, 40};

    for (int value : expected1) {
        assert(!heap.empty());
        assert(heap.top() == value);
        heap.pop();
    }

    assert(heap.empty());
    assert(heap.size() == 0);
    assert(heap.capacity() == 8);

    // 9. pop 이후 재사용
    heap.push(100);
    heap.push(50);
    heap.push(75);
    heap.push(25);

    assert(heap.size() == 4);
    assert(heap.top() == 25);

    int expected2[] = {25, 50, 75, 100};

    for (int value : expected2) {
        assert(heap.top() == value);
        heap.pop();
    }

    assert(heap.empty());

    // 10. reserve 직접 호출
    heap.reserve(20);

    assert(heap.capacity() == 20);
    assert(heap.size() == 0);

    heap.push(8);
    heap.push(3);
    heap.push(6);
    heap.push(1);
    heap.push(7);

    assert(heap.size() == 5);
    assert(heap.capacity() == 20);
    assert(heap.top() == 1);

    // 작은 reserve는 무시
    heap.reserve(10);

    assert(heap.capacity() == 20);
    assert(heap.size() == 5);
    assert(heap.top() == 1);

    // 같은 capacity도 무시
    heap.reserve(20);

    assert(heap.capacity() == 20);
    assert(heap.size() == 5);

    // 11. clear
    int previousCapacity = heap.capacity();

    heap.clear();

    assert(heap.empty());
    assert(heap.size() == 0);
    assert(heap.capacity() == previousCapacity);

    // clear 후 재사용
    heap.push(4);
    heap.push(2);
    heap.push(9);
    heap.push(1);

    assert(heap.size() == 4);
    assert(heap.top() == 1);
    assert(heap.capacity() == previousCapacity);

    // 12. 오름차순 pop 검증
    int expected3[] = {1, 2, 4, 9};

    for (int value : expected3) {
        assert(heap.top() == value);
        heap.pop();
    }

    assert(heap.empty());

    // 13. 내림차순 삽입
    for (int i = 100; i >= 1; i--) {
        heap.push(i);
    }

    assert(heap.size() == 100);
    assert(heap.top() == 1);

    for (int expected = 1; expected <= 100; expected++) {
        assert(heap.top() == expected);
        heap.pop();
    }

    assert(heap.empty());
    assert(heap.size() == 0);

    // 14. 오름차순 삽입
    for (int i = 1; i <= 100; i++) {
        heap.push(i);
    }

    assert(heap.size() == 100);
    assert(heap.top() == 1);

    for (int expected = 1; expected <= 100; expected++) {
        assert(heap.top() == expected);
        heap.pop();
    }

    assert(heap.empty());

    // 15. 음수와 중복값
    int values[] = {
        0, -10, 5, -3, -10, 8, 2, -1
    };

    for (int value : values) {
        heap.push(value);
    }

    int expected4[] = {
        -10, -10, -3, -1, 0, 2, 5, 8
    };

    for (int value : expected4) {
        assert(heap.top() == value);
        heap.pop();
    }

    assert(heap.empty());

    // 16. 원소 하나에서 pop
    heap.push(42);

    assert(heap.size() == 1);
    assert(heap.top() == 42);

    heap.pop();

    assert(heap.empty());
    assert(heap.size() == 0);

    // 빈 상태에서 여러 번 pop
    heap.pop();
    heap.pop();

    assert(heap.empty());

    cout << "ALL TESTS PASSED\n";

    return 0;
}