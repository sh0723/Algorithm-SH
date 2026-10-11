#include <cassert>
#include <iostream>
#include <stdexcept>
using namespace std;
class CircularQueue {
    public:
        CircularQueue();
        ~CircularQueue();

        void push(int value);
        void pop();

        int& front();
        int& back();

        int size() const;
        int capacity() const;
        bool empty() const;
        void clear();
        void reserve(int newCapacity);

    private:
        int* data;
        int front_index;
        int rear_index;
        int current_size;
        int current_capacity;

};

CircularQueue::CircularQueue(): data(nullptr),front_index(0), rear_index(0), current_size(0), current_capacity(0) {}

CircularQueue::~CircularQueue() {
    delete[] data;
}

void CircularQueue::push(int value) {
    if(current_size == current_capacity) {
        reserve(current_capacity==0 ? 1 : current_capacity*2);
    }

    data[rear_index] = value;
    rear_index = (rear_index + 1) % current_capacity;
    current_size++;
}

void CircularQueue::pop() {
    if (current_size == 0) return;

    front_index = (front_index + 1) % current_capacity;
    current_size--;
}


int& CircularQueue::front() {
    if(current_size == 0) {
        throw out_of_range("quque is empty");
    }

    return data[front_index];
}
int& CircularQueue::back() {
    if(current_size == 0) {
        throw out_of_range("quque is empty");
    }

    int back_index = (rear_index - 1 + current_capacity) % current_capacity;
    return data[back_index];
}

int CircularQueue::size() const{
    return current_size;
}
int CircularQueue::capacity() const{
    return current_capacity;
}
bool CircularQueue::empty() const{
    return current_size == 0;
}
void CircularQueue::clear(){
    current_size = 0;
    front_index = 0;
    rear_index = 0;
}
void CircularQueue::reserve(int newCapacity){
    if (newCapacity <= current_capacity) {
        return;
    }

    int* newData = new int[newCapacity];
    for (int i=0; i<current_size; i++) {
        newData[i] = data[(front_index+i)%current_capacity];
    }
    delete[] data;
    data = newData;
    current_capacity = newCapacity;
    front_index = 0;
    rear_index = current_size;
}


int main() {

    CircularQueue queue;

    // 1. 초기 상태

    assert(queue.empty());

    assert(queue.size() == 0);

    assert(queue.capacity() == 0);

    // 2. 첫 push

    queue.push(10);

    assert(!queue.empty());

    assert(queue.size() == 1);

    assert(queue.capacity() == 1);

    assert(queue.front() == 10);

    assert(queue.back() == 10);

    // 3. capacity 확장

    queue.push(20);

    assert(queue.size() == 2);

    assert(queue.capacity() == 2);

    assert(queue.front() == 10);

    assert(queue.back() == 20);

    queue.push(30);

    assert(queue.size() == 3);

    assert(queue.capacity() == 4);

    assert(queue.front() == 10);

    assert(queue.back() == 30);

    // 현재 논리적 순서: 10, 20, 30

    // 4. pop

    queue.pop();

    assert(queue.size() == 2);

    assert(queue.front() == 20);

    assert(queue.back() == 30);

    // 현재 논리적 순서: 20, 30

    // 5. rear_index 순환 확인

    queue.push(40);

    queue.push(50);

    assert(queue.size() == 4);

    assert(queue.capacity() == 4);

    assert(queue.front() == 20);

    assert(queue.back() == 50);

    // 내부 배열은 순환했을 수 있음

    // 논리적 순서: 20, 30, 40, 50

    // 6. 다시 pop 후 push

    queue.pop();

    queue.pop();

    assert(queue.size() == 2);

    assert(queue.front() == 40);

    assert(queue.back() == 50);

    queue.push(60);

    queue.push(70);

    assert(queue.size() == 4);

    assert(queue.capacity() == 4);

    assert(queue.front() == 40);

    assert(queue.back() == 70);

    // 논리적 순서: 40, 50, 60, 70

    // 7. 꽉 찬 상태에서 push하여 reserve 발생

    queue.push(80);

    assert(queue.size() == 5);

    assert(queue.capacity() == 8);

    assert(queue.front() == 40);

    assert(queue.back() == 80);

    // reserve 후 논리적 순서 유지 확인

    assert(queue.front() == 40);

    // 8. front/back 참조 반환 확인

    queue.front() = 400;

    queue.back() = 800;

    assert(queue.front() == 400);

    assert(queue.back() == 800);

    // 9. reserve 직접 호출

    int oldSize = queue.size();

    queue.reserve(20);

    assert(queue.capacity() == 20);

    assert(queue.size() == oldSize);

    assert(queue.front() == 400);

    assert(queue.back() == 800);

    // 더 작은 reserve는 무시

    queue.reserve(10);

    assert(queue.capacity() == 20);

    assert(queue.size() == oldSize);

    // 10. 전부 pop

    while (!queue.empty()) {

        queue.pop();

    }

    assert(queue.empty());

    assert(queue.size() == 0);

    assert(queue.capacity() == 20);

    // 빈 큐 pop은 아무 일도 하지 않음

    queue.pop();

    assert(queue.size() == 0);

    // 11. 빈 큐 front 예외

    bool exceptionThrown = false;

    try {

        queue.front();

    } catch (const out_of_range&) {

        exceptionThrown = true;

    }

    assert(exceptionThrown);

    // 12. 빈 큐 back 예외

    exceptionThrown = false;

    try {

        queue.back();

    } catch (const out_of_range&) {

        exceptionThrown = true;

    }

    assert(exceptionThrown);

    // 13. clear 후 재사용

    queue.push(1);

    queue.push(2);

    queue.push(3);

    assert(queue.size() == 3);

    assert(queue.front() == 1);

    assert(queue.back() == 3);

    int previousCapacity = queue.capacity();

    queue.clear();

    assert(queue.empty());

    assert(queue.size() == 0);

    assert(queue.capacity() == previousCapacity);

    queue.push(100);

    queue.push(200);

    assert(queue.size() == 2);

    assert(queue.front() == 100);

    assert(queue.back() == 200);

    cout << "ALL TESTS PASSED\n";

    return 0;

}