#include <cassert>
#include <iostream>
#include <stdexcept>
using namespace std;
class CircularLinkedList {
public:
    CircularLinkedList();
    ~CircularLinkedList();

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

CircularLinkedList::CircularLinkedList(): head(nullptr), tail(nullptr), current_size(0){}
CircularLinkedList::~CircularLinkedList(){
    clear();
}

void CircularLinkedList::pushFront(int value){
    Node *newNode = new Node{value, nullptr};
    if (current_size == 0) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    } else {
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    current_size++;
}
void CircularLinkedList::pushBack(int value){
    Node *newNode = new Node{value, nullptr};

    if (current_size == 0) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    } else {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    current_size++;
}

void CircularLinkedList::popFront(){
    if (current_size == 0) return;

    if (current_size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *target = head;
        tail->next = head->next;
        head = head->next;
        delete target;
    }
    current_size--;
}
void CircularLinkedList::popBack(){
    if (current_size == 0) return;

    if (current_size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *next_tail = head;
        while (next_tail->next != tail) {
            next_tail = next_tail->next;
        }

        next_tail->next = head;
        delete tail;
        tail = next_tail;
    }
    current_size--;
}

void CircularLinkedList::insert(int index, int value){
    if (index < 0 || index > current_size)
        throw out_of_range("index out of range");
    if (index == 0) {
        pushFront(value);
    } else if (index == current_size) {
        pushBack(value);
    } else {
        Node* newNode = new Node{value, nullptr};
        Node *ptr = head;
        for (int i=0; i<index-1; i++){
            ptr = ptr->next;
        }

        newNode->next = ptr->next;
        ptr->next = newNode;

        current_size++;
    }

}
void CircularLinkedList::erase(int index){
    if (index < 0 || index >= current_size)
        throw out_of_range("index out of range");

    if (index == 0) {
        popFront();
    } else if (index == current_size-1) {
        popBack();
    } else {
        Node *ptr = head;
        for (int i=0; i<index-1; i++) {
            ptr = ptr->next;
        }
        Node* target = ptr->next;
        ptr->next = ptr->next->next;
        delete target;
        current_size--;
    }
}

int& CircularLinkedList::front(){
    if (current_size == 0)
        throw out_of_range("List is Empty.");

    return head->value;
}
int& CircularLinkedList::back(){
    if (current_size == 0)
        throw out_of_range("List is Empty.");

    return tail->value;
}
int& CircularLinkedList::at(int index){
    if (index < 0 || index >= current_size)
        throw out_of_range("index out of range");

    Node *ptr = head;
    for (int i=0; i<index; i++) {
        ptr = ptr->next;
    }

    return ptr->value;
}

int CircularLinkedList::size() const{
    return current_size;
}
bool CircularLinkedList::empty() const{
    return current_size == 0;
}

void CircularLinkedList::clear(){

    Node *ptr = head;
    for (int i=0; i<current_size; i++) {
        Node *target = ptr;
        ptr = ptr->next;
        delete target;
    }

    head = nullptr;
    tail = nullptr;
    current_size = 0;
}
int main() {
    CircularLinkedList list;

    // 1. 초기 상태
    assert(list.empty());
    assert(list.size() == 0);

    // 2. 빈 리스트 pop
    list.popFront();
    list.popBack();

    assert(list.empty());
    assert(list.size() == 0);

    // 3. 빈 리스트 예외
    bool exceptionThrown = false;

    try {
        list.front();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.back();
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.at(0);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 4. pushBack
    list.pushBack(10);

    assert(!list.empty());
    assert(list.size() == 1);
    assert(list.front() == 10);
    assert(list.back() == 10);
    assert(list.at(0) == 10);

    list.pushBack(20);
    list.pushBack(30);

    assert(list.size() == 3);
    assert(list.front() == 10);
    assert(list.back() == 30);

    assert(list.at(0) == 10);
    assert(list.at(1) == 20);
    assert(list.at(2) == 30);

    // 현재: 10, 20, 30

    // 5. pushFront
    list.pushFront(5);

    assert(list.size() == 4);
    assert(list.front() == 5);
    assert(list.back() == 30);

    assert(list.at(0) == 5);
    assert(list.at(1) == 10);
    assert(list.at(2) == 20);
    assert(list.at(3) == 30);

    // 현재: 5, 10, 20, 30

    // 6. 참조 반환 확인
    list.front() = 50;
    list.back() = 300;
    list.at(1) = 100;

    assert(list.at(0) == 50);
    assert(list.at(1) == 100);
    assert(list.at(2) == 20);
    assert(list.at(3) == 300);

    // 현재: 50, 100, 20, 300

    // 7. insert 맨 앞
    list.insert(0, 1);

    assert(list.size() == 5);
    assert(list.front() == 1);
    assert(list.back() == 300);

    assert(list.at(0) == 1);
    assert(list.at(1) == 50);
    assert(list.at(2) == 100);
    assert(list.at(3) == 20);
    assert(list.at(4) == 300);

    // 8. insert 중간
    list.insert(2, 75);

    assert(list.size() == 6);

    assert(list.at(0) == 1);
    assert(list.at(1) == 50);
    assert(list.at(2) == 75);
    assert(list.at(3) == 100);
    assert(list.at(4) == 20);
    assert(list.at(5) == 300);

    // 9. insert 맨 뒤
    list.insert(list.size(), 400);

    assert(list.size() == 7);
    assert(list.back() == 400);
    assert(list.at(6) == 400);

    // 현재:
    // 1, 50, 75, 100, 20, 300, 400

    // 10. erase 맨 앞
    list.erase(0);

    assert(list.size() == 6);
    assert(list.front() == 50);

    // 현재:
    // 50, 75, 100, 20, 300, 400

    // 11. erase 중간
    list.erase(2);

    assert(list.size() == 5);

    assert(list.at(0) == 50);
    assert(list.at(1) == 75);
    assert(list.at(2) == 20);
    assert(list.at(3) == 300);
    assert(list.at(4) == 400);

    // 현재:
    // 50, 75, 20, 300, 400

    // 12. erase 맨 뒤
    list.erase(list.size() - 1);

    assert(list.size() == 4);
    assert(list.back() == 300);

    assert(list.at(0) == 50);
    assert(list.at(1) == 75);
    assert(list.at(2) == 20);
    assert(list.at(3) == 300);

    // 13. popFront
    list.popFront();

    assert(list.size() == 3);
    assert(list.front() == 75);
    assert(list.back() == 300);

    // 현재: 75, 20, 300

    // 14. popBack
    list.popBack();

    assert(list.size() == 2);
    assert(list.front() == 75);
    assert(list.back() == 20);

    // 현재: 75, 20

    // 15. 노드 두 개에서 popBack
    list.popBack();

    assert(list.size() == 1);
    assert(list.front() == 75);
    assert(list.back() == 75);

    // 16. 노드 하나에서 popFront
    list.popFront();

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

    // clear 여러 번 호출
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

    // 20. 잘못된 at 인덱스
    exceptionThrown = false;

    try {
        list.at(-1);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.at(list.size());
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 21. 잘못된 insert 인덱스
    exceptionThrown = false;

    try {
        list.insert(-1, 10);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.insert(list.size() + 1, 10);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 22. 잘못된 erase 인덱스
    exceptionThrown = false;

    try {
        list.erase(-1);
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    exceptionThrown = false;

    try {
        list.erase(list.size());
    } catch (const std::out_of_range&) {
        exceptionThrown = true;
    }

    assert(exceptionThrown);

    // 23. 반복 삽입/삭제
    list.clear();

    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0) {
            list.pushFront(i);
        } else {
            list.pushBack(i);
        }
    }

    assert(list.size() == 100);

    for (int i = 0; i < 25; i++) {
        list.popFront();
        list.popBack();
    }

    assert(list.size() == 50);

    // 24. 전부 삭제
    while (!list.empty()) {
        list.popFront();
    }

    assert(list.empty());
    assert(list.size() == 0);

    cout << "ALL TESTS PASSED\n";

    return 0;
}