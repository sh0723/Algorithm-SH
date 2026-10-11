#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;
class IntDeque {
public:
    IntDeque();
    IntDeque(int *data, int size, int capacity);
    ~IntDeque();

    void pushFront(int value);
    void pushBack(int value);

    void popFront();
    void popBack();

    int& front();
    int& back();
    int& at(int index);
    int& operator[](int index);

    int size() const;
    int capacity() const;
    bool empty() const;

    void clear();
    void reserve(int newCapacity);

private:
    int* data;

    int current_size;
    int current_capacity;

    int front_index;
    int rear_index;
};
// 12:14시작
IntDeque::IntDeque(int *dt, int size, int capacity) {
    data = dt;
    current_size = size;
    current_capacity = capacity;
}
IntDeque::IntDeque() : data(nullptr), current_size(0), current_capacity(0), front_index(0), rear_index(0) {}
IntDeque::~IntDeque() {
    clear();
    delete[] data;
    current_capacity = 0;
}

void IntDeque::pushFront(int value) {
    if (current_size == current_capacity) {
        reserve(current_capacity == 0 ? 1 : current_capacity * 2);
    }

    front_index = (front_index - 1 + current_capacity) % current_capacity;
    data[front_index] = value;
    current_size++;
}
void IntDeque::pushBack(int value) {
    if (current_size == current_capacity) {
        reserve(current_capacity == 0 ? 1 : current_capacity * 2);
    }

    rear_index = (rear_index+1) % current_capacity;
    data[rear_index] = value;
    current_size++;
}

void IntDeque::popFront(){
    if (current_size == 0) return;
    front_index = (front_index + 1) % current_capacity;
    current_size--;
}
void IntDeque::popBack() {
    if (current_size == 0) return;
    rear_index = (rear_index - 1 + current_capacity) % current_capacity;
    current_size--;
}

int& IntDeque::front() {
    if(current_size == 0) throw out_of_range("deque is empty");

    return data[front_index];
}
int& IntDeque::back() {
    if(current_size == 0) throw out_of_range("deque is empty");

    return data[rear_index];
}
int& IntDeque::at(int index) {
    if (index < 0 || index >= current_size) throw out_of_range("index out of range");

    return data[(front_index + index % current_capacity)];
}
int& IntDeque::operator[](int index) {
    if (index < 0 || index >= current_size) throw out_of_range("index out of range");

    return at(index);
}

int IntDeque::size() const {
    return current_size;
}
int IntDeque::capacity() const {
    return current_capacity;
}
bool IntDeque::empty() const {
    return current_size == 0;
}

void IntDeque::clear() {
    current_size = 0;
    front_index = 0;
    rear_index = 0;
}
void IntDeque::reserve(int newCapacity) {
    if (newCapacity < 0 || newCapacity <= current_capacity) return;

    int *newData = new int[newCapacity];
    for (int i=0; i<current_size; i++) {
        newData[i] = data[(front_index + i) % current_capacity];
    }
    current_capacity = newCapacity;
    delete[] data;
    data = newData;
    front_index = 0;
    rear_index = current_size-1;
}
int main() {
    IntDeque deque;

    // 1. 초기 상태
    assert(deque.empty());
    assert(deque.size() == 0);
    assert(deque.capacity() == 0);

    // 2. pushBack
    deque.pushBack(10);

    assert(!deque.empty());
    assert(deque.size() == 1);
    assert(deque.capacity() == 1);
    assert(deque.front() == 10);
    assert(deque.back() == 10);

    deque.pushBack(20);

    assert(deque.size() == 2);
    assert(deque.capacity() == 2);
    assert(deque.front() == 10);
    assert(deque.back() == 20);

    deque.pushBack(30);

    assert(deque.size() == 3);
    assert(deque.capacity() == 4);
    assert(deque.front() == 10);
    assert(deque.back() == 30);

    // 논리적 순서: 10, 20, 30

    // 3. pushFront
    deque.pushFront(5);

    assert(deque.size() == 4);
    assert(deque.capacity() == 4);
    assert(deque.front() == 5);
    assert(deque.back() == 30);

    // 논리적 순서: 5, 10, 20, 30

    deque.pushFront(1);

    assert(deque.size() == 5);
    assert(deque.capacity() == 8);
    assert(deque.front() == 1);
    assert(deque.back() == 30);

    // 논리적 순서: 1, 5, 10, 20, 30

    // 4. 참조 반환 확인
    deque.front() = 100;
    deque.back() = 300;

    assert(deque.front() == 100);
    assert(deque.back() == 300);

    // 논리적 순서: 100, 5, 10, 20, 300

    // 5. popFront
    deque.popFront();

    assert(deque.size() == 4);
    assert(deque.front() == 5);
    assert(deque.back() == 300);

    // 논리적 순서: 5, 10, 20, 300

    // 6. popBack
    deque.popBack();

    assert(deque.size() == 3);
    assert(deque.front() == 5);
    assert(deque.back() == 20);

    // 논리적 순서: 5, 10, 20

    // 7. 앞뒤 삽입 반복
    deque.pushFront(1);
    deque.pushBack(30);
    deque.pushFront(0);
    deque.pushBack(40);

    assert(deque.size() == 7);
    assert(deque.front() == 0);
    assert(deque.back() == 40);

    // 논리적 순서: 0, 1, 5, 10, 20, 30, 40

    // 8. 원형 인덱스 순환 유도
    deque.popFront();
    deque.popFront();
    deque.popFront();

    assert(deque.size() == 4);
    assert(deque.front() == 10);
    assert(deque.back() == 40);

    // 논리적 순서: 10, 20, 30, 40

    deque.pushBack(50);
    deque.pushBack(60);
    deque.pushBack(70);

    assert(deque.size() == 7);
    assert(deque.capacity() == 8);
    assert(deque.front() == 10);
    assert(deque.back() == 70);

    // 원형으로 꼬인 상태일 가능성이 높음
    // 논리적 순서: 10, 20, 30, 40, 50, 60, 70

    // 9. 꽉 찬 상태 만들기
    deque.pushFront(5);

    assert(deque.size() == 8);
    assert(deque.capacity() == 8);
    assert(deque.front() == 5);
    assert(deque.back() == 70);

    // 논리적 순서: 5, 10, 20, 30, 40, 50, 60, 70

    // 10. 꽉 찬 상태에서 reserve 발생
    deque.pushBack(80);

    assert(deque.size() == 9);
    assert(deque.capacity() == 16);
    assert(deque.front() == 5);
    assert(deque.back() == 80);

    // reserve 후 논리 순서가 유지돼야 함

    // 11. reserve 직접 호출
    int oldSize = deque.size();

    deque.reserve(30);

    assert(deque.capacity() == 30);
    assert(deque.size() == oldSize);
    assert(deque.front() == 5);
    assert(deque.back() == 80);

    // 더 작은 capacity 요청은 무시
    deque.reserve(10);

    assert(deque.capacity() == 30);
    assert(deque.size() == oldSize);

    // 12. 양쪽에서 번갈아 삭제
    deque.popFront(); // 5 삭제
    deque.popBack();  // 80 삭제

    assert(deque.size() == 7);
    assert(deque.front() == 10);
    assert(deque.back() == 70);

    deque.popFront(); // 10 삭제
    deque.popBack();  // 70 삭제

    assert(deque.size() == 5);
    assert(deque.front() == 20);
    assert(deque.back() == 60);

    // 13. 전부 제거
    while (!deque.empty()) {
        deque.popFront();
    }

    assert(deque.empty());
    assert(deque.size() == 0);
    assert(deque.capacity() == 30);

    // 빈 덱 pop은 아무 작업도 하지 않아야 함
    deque.popFront();
    deque.popBack();

    assert(deque.size() == 0);

    // 14. 빈 덱 front 예외
    bool exceptionThrown = false;

    try {
        deque.front();
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 15. 빈 덱 back 예외
    exceptionThrown = false;

    try {
        deque.back();
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 16. 빈 상태에서 재사용
    deque.pushFront(20);
    deque.pushFront(10);
    deque.pushBack(30);
    deque.pushBack(40);

    assert(deque.size() == 4);
    assert(deque.front() == 10);
    assert(deque.back() == 40);

    // 논리적 순서: 10, 20, 30, 40

    // 17. clear
    int previousCapacity = deque.capacity();

    deque.clear();

    assert(deque.empty());
    assert(deque.size() == 0);
    assert(deque.capacity() == previousCapacity);

    // clear 후 재사용
    deque.pushBack(100);
    deque.pushFront(50);
    deque.pushBack(150);

    assert(deque.size() == 3);
    assert(deque.front() == 50);
    assert(deque.back() == 150);

    cout << "ALL TESTS PASSED\n";

    return 0;
}