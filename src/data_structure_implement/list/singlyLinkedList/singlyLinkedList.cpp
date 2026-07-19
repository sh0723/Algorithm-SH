#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;
class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void pushFront(int value);
    void pushBack(int value);

    void popFront();
    void popBack();

    void insert(int index, int value);
    void erase(int index);

    int& front();
    int& back();
    int& at(int index);

    int size() const;
    bool empty() const;

    void clear();

private:
    struct Node {
        int value;
        Node* next;
    };

    Node* head;
    Node* tail;
    int current_size;
};
SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), current_size(0) {}
SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList::pushFront(int value){
    Node* newNode = new Node{value, head};
    head = newNode;
    if (current_size == 0) tail = newNode;

    current_size++;
}
void SinglyLinkedList::pushBack(int value){
    Node* newNode = new Node{value, nullptr};

    if (current_size == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    current_size++;
}

void SinglyLinkedList::popFront(){
    if (current_size == 0) return;

    Node *next_head = head->next;
    delete head;
    head = next_head;
    current_size--;

    if (current_size == 0) tail = nullptr;
}
void SinglyLinkedList::popBack(){
    if (current_size == 0) return;

    if (current_size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        current_size = 0;
        return;
    }

    Node *next_tail = head;
    while(next_tail->next != tail) {
        next_tail = next_tail->next;
    }

    delete tail;
    tail = next_tail;
    tail->next = nullptr;
    current_size--;

}

void SinglyLinkedList::insert(int index, int value){
    if (index < 0 || index > current_size)
        throw out_of_range("index out of range");

    if (index == 0) {
        pushFront(value);
    } else if (index == current_size) {
        pushBack(value);
    } else {
        Node* newNode = new Node{value, nullptr};
        Node *prev = head;
        for (int i=0; i<index-1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;
        current_size++;
    }
}
void SinglyLinkedList::erase(int index){
    if (current_size == 0 || index < 0 || index >= current_size)
        throw out_of_range("index out of range");

    if (index == 0) {
        popFront();
    } else if (index == current_size-1) {
        popBack();
    } else {
        Node *prev = head;
        for (int i=0; i<index-1; i++) {
            prev = prev->next;
        }
        Node *target = prev->next;
        prev->next = prev->next->next;
        delete target;
        current_size--;
    }
}

int& SinglyLinkedList::front(){
    if (current_size == 0)
        throw out_of_range("list is empty");

    return head->value;
}
int& SinglyLinkedList::back(){
    if (current_size == 0)
        throw out_of_range("list is empty");
    return tail->value;
}
int& SinglyLinkedList::at(int index){
    if (current_size == 0 || index < 0 || index >= current_size)
        throw out_of_range("index out of range");

    Node *target = head;
    for (int i=0; i<index; i++) {
        target = target->next;
    }

    return target->value;
}

int SinglyLinkedList::size() const{
    return current_size;
}
bool SinglyLinkedList::empty() const{
    return current_size == 0;
}

void SinglyLinkedList::clear(){
    Node *ptr = head;
    while (ptr != nullptr) {
        Node *next = ptr->next;
        delete ptr;
        ptr = next;
    }

    head = nullptr;
    tail = nullptr;
    current_size=0;
}
int main() {
    SinglyLinkedList list;

    // 1. 초기 상태
    assert(list.empty());
    assert(list.size() == 0);

    // 2. 빈 리스트 pop
    list.popFront();
    list.popBack();

    assert(list.empty());
    assert(list.size() == 0);

    // 3. 빈 리스트 front/back/at 예외
    bool exceptionThrown = false;

    try {
        list.front();
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.back();
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.at(0);
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 4. pushFront
    list.pushFront(20);

    assert(!list.empty());
    assert(list.size() == 1);
    assert(list.front() == 20);
    assert(list.back() == 20);
    assert(list.at(0) == 20);

    list.pushFront(10);

    assert(list.size() == 2);
    assert(list.front() == 10);
    assert(list.back() == 20);
    assert(list.at(0) == 10);
    assert(list.at(1) == 20);

    // 현재: 10, 20

    // 5. pushBack
    list.pushBack(30);
    list.pushBack(40);

    assert(list.size() == 4);
    assert(list.front() == 10);
    assert(list.back() == 40);

    assert(list.at(0) == 10);
    assert(list.at(1) == 20);
    assert(list.at(2) == 30);
    assert(list.at(3) == 40);

    // 현재: 10, 20, 30, 40

    // 6. 참조 반환 확인
    list.front() = 100;
    list.back() = 400;
    list.at(1) = 200;

    assert(list.at(0) == 100);
    assert(list.at(1) == 200);
    assert(list.at(2) == 30);
    assert(list.at(3) == 400);

    // 현재: 100, 200, 30, 400

    // 7. insert 맨 앞
    list.insert(0, 50);

    assert(list.size() == 5);
    assert(list.front() == 50);
    assert(list.back() == 400);

    assert(list.at(0) == 50);
    assert(list.at(1) == 100);
    assert(list.at(2) == 200);
    assert(list.at(3) == 30);
    assert(list.at(4) == 400);

    // 8. insert 중간
    list.insert(2, 150);

    assert(list.size() == 6);

    assert(list.at(0) == 50);
    assert(list.at(1) == 100);
    assert(list.at(2) == 150);
    assert(list.at(3) == 200);
    assert(list.at(4) == 30);
    assert(list.at(5) == 400);

    // 9. insert 맨 뒤
    list.insert(list.size(), 500);

    assert(list.size() == 7);
    assert(list.back() == 500);

    assert(list.at(6) == 500);

    // 현재:
    // 50, 100, 150, 200, 30, 400, 500

    // 10. erase 맨 앞
    list.erase(0);

    assert(list.size() == 6);
    assert(list.front() == 100);

    // 현재:
    // 100, 150, 200, 30, 400, 500

    // 11. erase 중간
    list.erase(2);

    assert(list.size() == 5);

    assert(list.at(0) == 100);
    assert(list.at(1) == 150);
    assert(list.at(2) == 30);
    assert(list.at(3) == 400);
    assert(list.at(4) == 500);

    // 현재:
    // 100, 150, 30, 400, 500

    // 12. erase 맨 뒤
    list.erase(list.size() - 1);

    assert(list.size() == 4);
    assert(list.back() == 400);

    assert(list.at(0) == 100);
    assert(list.at(1) == 150);
    assert(list.at(2) == 30);
    assert(list.at(3) == 400);

    // 13. popFront
    list.popFront();

    assert(list.size() == 3);
    assert(list.front() == 150);
    assert(list.back() == 400);

    // 현재: 150, 30, 400

    // 14. popBack
    list.popBack();

    assert(list.size() == 2);
    assert(list.front() == 150);
    assert(list.back() == 30);

    // 현재: 150, 30

    // 15. 노드 두 개에서 popBack
    list.popBack();

    assert(list.size() == 1);
    assert(list.front() == 150);
    assert(list.back() == 150);

    // 16. 노드 하나에서 popBack
    list.popBack();

    assert(list.empty());
    assert(list.size() == 0);

    // 17. 비운 뒤 재사용
    list.pushBack(10);
    list.pushBack(20);
    list.pushFront(5);

    assert(list.size() == 3);
    assert(list.front() == 5);
    assert(list.back() == 20);

    assert(list.at(0) == 5);
    assert(list.at(1) == 10);
    assert(list.at(2) == 20);

    // 18. clear
    list.clear();

    assert(list.empty());
    assert(list.size() == 0);

    // clear를 여러 번 호출해도 안전해야 함
    list.clear();
    list.clear();

    assert(list.empty());
    assert(list.size() == 0);

    // 19. clear 후 재사용
    list.pushFront(2);
    list.pushFront(1);
    list.pushBack(3);

    assert(list.size() == 3);
    assert(list.at(0) == 1);
    assert(list.at(1) == 2);
    assert(list.at(2) == 3);

    // 20. at 범위 예외
    exceptionThrown = false;

    try {
        list.at(-1);
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.at(list.size());
    } catch (const out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    cout << "ALL TESTS PASSED\n";

    return 0;
}