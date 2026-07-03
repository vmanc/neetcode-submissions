#include <vector>
struct ListNode {
    int value;
    ListNode* nextNode;
    ListNode(int v) : value(v), nextNode(nullptr) {}    
};

class LinkedList {
public:
    ~LinkedList(){
        ListNode* node = head_;
        while(node != nullptr){
             ListNode* tempNode = node->nextNode;
            delete node;
            node = tempNode;
        }
    }
    int get(int index) {
        int pos = 0;
        ListNode* node = head_;
        while (node != nullptr){
            if (pos == index){
                return node->value;
            }
            node = node->nextNode;
            pos++;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode* new_node = new ListNode(val);
        if (head_ != nullptr){
            new_node->nextNode = head_;
            head_ = new_node;
        } else {
            head_ = new_node;
            tail_ = new_node;
        }
    }
    
    void insertTail(int val) {
        ListNode* new_node = new ListNode(val);
        if (head_ == nullptr){
            head_ = new_node;
            tail_ = new_node;
        } else {
            tail_->nextNode = new_node;
            tail_ = new_node;
        }
    }

    bool remove(int index) {
        if (head_ == nullptr){
            return false;
        }
        int pos = 0;
        ListNode* node = head_;
        if (index == 0){
            ListNode* tempNode = node;
            head_= node->nextNode;
            if (tempNode == tail_){tail_ = nullptr;}
            delete tempNode;
            return true;
        }
        while (node != nullptr && pos < index-1){
            node = node->nextNode;
            pos++;
        } 
        if (node == nullptr || node->nextNode == nullptr){return false;}
        if (node->nextNode->nextNode == nullptr){
            ListNode* tempNode = node->nextNode;
            node->nextNode = nullptr;
            delete tempNode;
            tail_ = node;
            return true;
        } else {
            ListNode* tempNode = node->nextNode;
            node->nextNode = node->nextNode->nextNode;
            delete tempNode;
            return true;    
        }
        return false;   
    }

    vector<int> getValues() {
        ListNode* node = head_;
        vector<int> values;
        while (node != nullptr){
            values.push_back(node->value);
            node = node->nextNode;
        }
        return values;
    }
private:
    ListNode* head_ = nullptr;
    ListNode* tail_ = nullptr;
};
