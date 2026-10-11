#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    bool insert(int value);
    bool erase(int value);
    bool contains(int value) const;

    int& min();
    int& max();

    int size() const;
    bool empty() const;

    int height() const;

    void clear();

    void printInorder() const;
    void printPreorder() const;
    void printPostorder() const;

private:
    struct Node {
        int value;
        Node* left;
        Node* right;
    };

    Node* root;
    int current_size;

    Node* findNode(int value) const;
    Node* findMinNode(Node* node) const;
    Node* findMaxNode(Node* node) const;

    Node* insertNode(Node* node, int value, bool& inserted);
    Node* eraseNode(Node* node, int value, bool& erased);

    void clearNode(Node* node);

    int heightNode(Node* node) const;

    void inorder(Node* node) const;
    void preorder(Node* node) const;
    void postorder(Node* node) const;
};

BinarySearchTree::BinarySearchTree() : root(nullptr), current_size(0) {}
BinarySearchTree::~BinarySearchTree() {
    clear();
}

bool BinarySearchTree::insert(int value) {
    bool inserted = false;
    root = insertNode(root, value, inserted);
    if (inserted) current_size++;
    return inserted;
}
bool BinarySearchTree::erase(int value) {
    bool erased = false;
    root = eraseNode(root, value, erased);
    if (erased) current_size--;
    return erased;
}
bool BinarySearchTree::contains(int value) const {
    return findNode(value) != nullptr;
}

int& BinarySearchTree::min() {
    if (current_size == 0) throw out_of_range("BST is empty");

    return findMinNode(root)->value;
}
int& BinarySearchTree::max() {
    if (current_size == 0) throw out_of_range("BST is empty");

    return findMaxNode(root)->value;
}

int BinarySearchTree::size() const {
    return current_size;
}
bool BinarySearchTree::empty() const {
    return current_size == 0;
}

int BinarySearchTree::height() const {
    return heightNode(root);
}

void BinarySearchTree::clear() {
    clearNode(root);
    root = nullptr;
    current_size = 0;
}

void BinarySearchTree::printInorder() const {
    inorder(root);
    cout << '\n';
}
void BinarySearchTree::printPreorder() const {
    preorder(root);
    cout << '\n';
}
void BinarySearchTree::printPostorder() const {
    postorder(root);
    cout << '\n';
}

BinarySearchTree::Node* BinarySearchTree::findNode(int value) const {
    Node *ptr = root;
    while(ptr != nullptr) {
        if (ptr->value < value) {
            ptr = ptr->right;
        } else if (ptr->value > value) {
            ptr = ptr->left;
        } else {
            break;
        }
    }

    return ptr;
}
BinarySearchTree::Node* BinarySearchTree::findMinNode(Node* node) const {
    Node *ptr = node;
    while(ptr->left != nullptr) {
        ptr = ptr->left;
    }
    return ptr;
}
BinarySearchTree::Node* BinarySearchTree::findMaxNode(Node* node) const {
    Node *ptr = node;
    while(ptr->right != nullptr) {
        ptr = ptr->right;
    }
    return ptr;
}

BinarySearchTree::Node* BinarySearchTree::insertNode(Node* node, int value, bool& inserted) {
    if (node == nullptr) {
        Node *newNode = new Node{value, nullptr, nullptr};
        inserted = true;
        return newNode;
    }

    if (node->value < value) {
        node->right = insertNode(node->right, value, inserted);
    } else if (node->value > value) {
        node->left = insertNode(node->left, value, inserted);
    }

    return node;
}
BinarySearchTree::Node* BinarySearchTree::eraseNode(Node* node, int value, bool& erased) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->value < value) {
        node->right = eraseNode(node->right, value, erased);
    } else if (node->value > value) {
        node->left = eraseNode(node->left, value, erased);
    } else {
        erased = true;
        if (node->left == nullptr && node->right != nullptr) {
            Node *rightChild = node->right;
            delete node;
            return rightChild;
        } else if (node->left != nullptr && node->right == nullptr) {
            Node *leftChild = node->left;
            delete node;
            return leftChild;
        } else if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else {
            Node *minNode = findMinNode(node->right);
            int minVal = minNode->value;
            node->value = minVal;
            bool temp = false;
            node->right = eraseNode(node->right, minVal, temp);
        }
    }
    return node;
}

void BinarySearchTree::clearNode(Node* node) {
    if (node == nullptr) return;

    clearNode(node->left);
    clearNode(node->right);
    delete node;
}

int BinarySearchTree::heightNode(Node* node) const {
    if (node == nullptr) {
        return -1;
    }
    int right = heightNode(node->right);
    int left = heightNode(node->left);

    return 1 + std::max(right, left);
}

void BinarySearchTree::inorder(Node* node) const {
    if (node == nullptr) return;

    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}
void BinarySearchTree::preorder(Node* node) const {
    if (node == nullptr) return;

    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}
void BinarySearchTree::postorder(Node* node) const {
    if (node == nullptr) return;

    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";

}
int main() {
    BinarySearchTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);
    tree.insert(6);
    tree.insert(8);

    cout << "Inorder: ";
    tree.printInorder();

    cout << "Preorder: ";
    tree.printPreorder();

    cout << "Postorder: ";
    tree.printPostorder();

    cout << "size: " << tree.size() << '\n';
    cout << "height: " << tree.height() << '\n';
    cout << "min: " << tree.min() << '\n';
    cout << "max: " << tree.max() << '\n';

    cout << boolalpha;
    cout << "contains 7: " << tree.contains(7) << '\n';
    cout << "contains 100: " << tree.contains(100) << '\n';

    cout << "\nerase leaf 3\n";
    tree.erase(3);
    tree.printInorder();

    cout << "\nerase node with one child 5\n";
    tree.erase(5);
    tree.printInorder();

    cout << "\nerase node with two children 10\n";
    tree.erase(10);
    tree.printInorder();

    cout << "\nsize: " << tree.size() << '\n';
    cout << "height: " << tree.height() << '\n';

    tree.clear();

    cout << "empty after clear: " << tree.empty() << '\n';

    return 0;
}