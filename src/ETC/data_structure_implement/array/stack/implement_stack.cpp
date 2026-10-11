#include <bits/stdc++.h>
using namespace std;
class IntStack {
public:
    IntStack();
    ~IntStack();
    void push(int num);
    void pop();

    int& top();
    int size() const;
    int capacity() const;

    bool empty() const;
    void clear();
    void reserve(int new_capacity);
private:
    int *data;
    int curr_capacity;
    int curr_size;
};

IntStack::IntStack() : data(nullptr), curr_size(0), curr_capacity(0){}

IntStack::~IntStack() {
    delete[] data;
}

void IntStack::push(int num) {
    if (curr_capacity == curr_size) {
        if (curr_capacity == 0) {
            reserve(1);
        } else {
            reserve(curr_capacity * 2);
        }
    }

    data[curr_size] = num;
    curr_size++;
}

void IntStack::pop() {
    if (curr_size == 0) return;

    curr_size--;
}

int& IntStack::top() {
    if (curr_size == 0) {
        throw out_of_range("stack is empty");
    }

    return data[curr_size-1];
}

int IntStack::size() const{
    return curr_size;
}

int IntStack::capacity() const{
    return curr_capacity;
}

bool IntStack::empty() const{
    return curr_size == 0;
}

void IntStack::clear() {
    curr_size = 0;
}

void IntStack::reserve(int new_capacity) {
    if (new_capacity <= curr_capacity) return;

    int *new_data = new int[new_capacity];

    for (int i=0; i<curr_size; i++) {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    curr_capacity = new_capacity;
}
int main() {
    IntStack stack;

    assert(stack.empty());
    assert(stack.size() == 0);
    assert(stack.capacity() == 0);

    stack.push(10);

    assert(!stack.empty());
    assert(stack.size() == 1);
    assert(stack.capacity() == 1);
    assert(stack.top() == 10);

    stack.push(20);

    assert(stack.size() == 2);
    assert(stack.capacity() == 2);
    assert(stack.top() == 20);

    stack.push(30);

    assert(stack.size() == 3);
    assert(stack.capacity() == 4);
    assert(stack.top() == 30);

    // top이 참조를 반환하는지 확인
    stack.top() = 300;

    assert(stack.top() == 300);
    assert(stack.size() == 3);

    stack.pop();

    assert(stack.size() == 2);
    assert(stack.top() == 20);

    stack.pop();

    assert(stack.size() == 1);
    assert(stack.top() == 10);

    // reserve가 기존 값과 size를 유지하는지 확인
    stack.reserve(20);

    assert(stack.capacity() == 20);
    assert(stack.size() == 1);
    assert(stack.top() == 10);

    // 더 작은 reserve는 무시
    stack.reserve(5);

    assert(stack.capacity() == 20);
    assert(stack.size() == 1);

    // clear는 capacity를 유지
    stack.clear();

    assert(stack.empty());
    assert(stack.size() == 0);
    assert(stack.capacity() == 20);

    // 빈 스택 pop은 아무 일도 하지 않음
    stack.pop();

    assert(stack.size() == 0);

    // 빈 스택 top은 예외
    bool exceptionThrown = false;

    try {
        stack.top();
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // clear 이후 재사용
    stack.push(100);
    stack.push(200);

    assert(stack.size() == 2);
    assert(stack.capacity() == 20);
    assert(stack.top() == 200);

    cout << "ALL TESTS PASSED\n";

    return 0;
}