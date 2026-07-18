#include <cassert>
#include <iostream>
#include <stdexcept>
using namespace std;
class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();

    void pushBack(int value);
    void popBack();

    int& at(int index);
    int& operator[](int index);

    int size() const;
    int capacity() const;
    bool empty() const;
    void clear();
    void reserve(int newCapacity);
    void insert(int index, int value);
    void erase(int index);
    int& front();
    int& back();
    void resize(int newSize);

private:
    int *data;
    int current_size;
    int current_capacity;

};

DynamicArray::DynamicArray() {
    data = nullptr;
    current_size = 0;
    current_capacity = 0;
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::pushBack(int value) {
    if (current_size == current_capacity) {
        int newCapacity;
        if (current_capacity == 0) {
            newCapacity = 1;
        } else {
            newCapacity = current_capacity * 2;
        }
        reserve(newCapacity);
    }

    data[current_size] = value;
    current_size++;
}

void DynamicArray::popBack() {
    if (empty()) {
        return;
    }
    current_size--;
}

int& DynamicArray::at(int index) {
    if (index < 0 || index >= current_size) {
        throw out_of_range("index out of range");
    }
    return data[index];
}

int& DynamicArray::operator[](int index) {
    return data[index];
}

int DynamicArray::size() const {
    return current_size;
}

int DynamicArray::capacity() const {
    return current_capacity;
}

bool DynamicArray::empty() const {
    return current_size == 0;
}

void DynamicArray::clear() {
    current_size= 0;
}

void DynamicArray::reserve(int newCapacity) {
    if (newCapacity < 0) return;

    if(current_capacity >= newCapacity) return;

    int* newData = new int[newCapacity];
    for (int i=0; i<current_size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    current_capacity = newCapacity;
}

void DynamicArray::insert(int index, int value) {
    if (index > current_size || index < 0) {
        throw out_of_range("index out of range");
    }

    if (current_size == current_capacity) {
        int newCapacity;
        if (current_capacity == 0) {
            newCapacity = 1;
        } else {
            newCapacity = current_capacity * 2;
        }
        reserve(newCapacity);
    }

    for (int i=current_size; i>index; i--) {
        data[i] = data[i-1];
    }
    data[index] = value;
    current_size++;
}

void DynamicArray::erase(int index) {
    if (index >= current_size || index < 0) {
        throw out_of_range("index out of range");
    }

    for (int i=index; i<current_size-1; i++) {
        data[i] = data[i+1];
    }
    current_size--;
}

int& DynamicArray::front() {
    if (current_size == 0) {
        throw out_of_range("index out of range");
    }

    return data[0];
}

int& DynamicArray::back() {
    if (current_size == 0) {
        throw out_of_range("index out of range");
    }

    return data[current_size-1];
}

void DynamicArray::resize(int newSize) {
    if (newSize < 0) {
        throw invalid_argument("size cannot be negative");
    }

    if (newSize > current_capacity) {
        reserve(newSize);
    }

    if (newSize > current_capacity) {
        reserve(newSize);
    }

    if (newSize > current_size) {
        for (int i=current_size; i<newSize; i++) {
            data[i] = 0;
        }
    }

    current_size = newSize;
}
int main() {
    DynamicArray arr;

    // 1. 초기 상태
    assert(arr.size() == 0);
    assert(arr.capacity() == 0);
    assert(arr.empty());

    // 2. pushBack 및 capacity 증가
    arr.pushBack(10);

    assert(arr.size() == 1);
    assert(arr.capacity() == 1);
    assert(arr[0] == 10);

    arr.pushBack(20);

    assert(arr.size() == 2);
    assert(arr.capacity() == 2);
    assert(arr[1] == 20);

    arr.pushBack(30);

    assert(arr.size() == 3);
    assert(arr.capacity() == 4);
    assert(arr[2] == 30);

    // 현재 상태: [10, 20, 30]

    // 3. front, back
    assert(arr.front() == 10);
    assert(arr.back() == 30);

    // 참조 반환 확인
    arr.front() = 100;
    arr.back() = 300;

    assert(arr[0] == 100);
    assert(arr[2] == 300);

    // 현재 상태: [100, 20, 300]

    // 4. 중간 삽입
    arr.insert(1, 15);

    assert(arr.size() == 4);
    assert(arr[0] == 100);
    assert(arr[1] == 15);
    assert(arr[2] == 20);
    assert(arr[3] == 300);

    // 현재 상태: [100, 15, 20, 300]

    // 5. 맨 앞 삽입
    arr.insert(0, 5);

    assert(arr.size() == 5);
    assert(arr.capacity() == 8);
    assert(arr[0] == 5);
    assert(arr[1] == 100);

    // 현재 상태: [5, 100, 15, 20, 300]

    // 6. 맨 뒤 삽입
    arr.insert(arr.size(), 400);

    assert(arr.size() == 6);
    assert(arr.back() == 400);

    // 현재 상태: [5, 100, 15, 20, 300, 400]

    // 7. erase 중간 삭제
    arr.erase(2);

    assert(arr.size() == 5);
    assert(arr[0] == 5);
    assert(arr[1] == 100);
    assert(arr[2] == 20);
    assert(arr[3] == 300);
    assert(arr[4] == 400);

    // 현재 상태: [5, 100, 20, 300, 400]

    // 8. 맨 앞 삭제
    arr.erase(0);

    assert(arr.size() == 4);
    assert(arr.front() == 100);

    // 현재 상태: [100, 20, 300, 400]

    // 9. 맨 뒤 삭제
    arr.erase(arr.size() - 1);

    assert(arr.size() == 3);
    assert(arr.back() == 300);

    // 현재 상태: [100, 20, 300]

    // 10. popBack
    arr.popBack();

    assert(arr.size() == 2);
    assert(arr.back() == 20);

    // 현재 상태: [100, 20]

    // 11. reserve
    int oldSize = arr.size();

    arr.reserve(20);

    assert(arr.size() == oldSize);
    assert(arr.capacity() == 20);
    assert(arr[0] == 100);
    assert(arr[1] == 20);

    // 작은 capacity 요청은 무시
    arr.reserve(10);

    assert(arr.capacity() == 20);

    // 12. resize 확장
    arr.resize(5);

    assert(arr.size() == 5);
    assert(arr.capacity() == 20);
    assert(arr[0] == 100);
    assert(arr[1] == 20);
    assert(arr[2] == 0);
    assert(arr[3] == 0);
    assert(arr[4] == 0);

    // 13. resize 축소
    arr[2] = 200;
    arr[3] = 300;
    arr[4] = 400;

    arr.resize(2);

    assert(arr.size() == 2);
    assert(arr.capacity() == 20);
    assert(arr[0] == 100);
    assert(arr[1] == 20);

    // 다시 확장하면 새 원소는 0이어야 함
    arr.resize(5);

    assert(arr.size() == 5);
    assert(arr[2] == 0);
    assert(arr[3] == 0);
    assert(arr[4] == 0);

    // 14. at 정상 접근 및 수정
    assert(arr.at(0) == 100);

    arr.at(0) = 999;

    assert(arr[0] == 999);

    // 15. at 예외 검사
    bool exceptionThrown = false;

    try {
        arr.at(-1);
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        arr.at(arr.size());
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 16. insert 예외 검사
    exceptionThrown = false;

    try {
        arr.insert(arr.size() + 1, 10);
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 17. erase 예외 검사
    exceptionThrown = false;

    try {
        arr.erase(arr.size());
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 18. clear
    int previousCapacity = arr.capacity();

    arr.clear();

    assert(arr.size() == 0);
    assert(arr.capacity() == previousCapacity);
    assert(arr.empty());

    // 19. 빈 배열 front, back 예외
    exceptionThrown = false;

    try {
        arr.front();
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        arr.back();
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 20. 빈 배열 popBack 동작 확인
    // popBack을 빈 배열에서 예외 없이 return하도록 구현했다는 전제
    arr.popBack();

    assert(arr.size() == 0);

    // 21. 음수 resize 예외
    exceptionThrown = false;

    try {
        arr.resize(-1);
    } catch (const invalid_argument&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    cout << "ALL TESTS PASSED\n";

    return 0;
}