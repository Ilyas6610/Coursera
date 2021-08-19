#include "../../week1/red1/test_runner.h"

#include <vector>
#include <array>
#include <string_view>
using namespace std;

template <typename T>
class LinkedList {
public:
    struct Node {
    T value;
    Node* next = nullptr;
    };

    ~LinkedList(){
        auto node = GetHead();
        if( node == nullptr ){
            delete node;
            return;
        }
        if( node->next == nullptr ){
            delete node;
            return;
        }
        Node* p = node->next;
        while( node->next != nullptr ){
            delete node;
            node = p;
            p = node->next;
        }
        delete node;
    };

    void PushFront(const T& value){
        Node* next = new Node;
        next->value = value;
        next->next = head;
        head = next;
    }
    void InsertAfter(Node* node, const T& value){
        if(node == nullptr)
            PushFront(value);
        else{
            Node* node_ = new Node;
            node_->value = value;
            node_->next = node->next;
            node->next = node_;
        }
    }

    void PopFront(){
        if( head == nullptr ){
            return;
        }
        Node* r = head;
        head = head->next;
        delete r;
    }

    void RemoveAfter(Node* node){
        if(node == nullptr)
            PopFront();
        else{
            if( node->next != nullptr){
                Node* r = node->next;
                node->next = node->next->next;
                delete r;
            }else{
                return;
            }
        }
    }


    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};

template <typename T>
vector<T> ToVector(const LinkedList<T>& list) {
  vector<T> result;
  for (auto node = list.GetHead(); node; node = node->next) {
    result.push_back(node->value);
  }
  return result;
}

void TestPushFront() {
  LinkedList<int> list;

  list.PushFront(1);
  ASSERT_EQUAL(list.GetHead()->value, 1);
  list.PushFront(2);
  ASSERT_EQUAL(list.GetHead()->value, 2);
  list.PushFront(3);
  ASSERT_EQUAL(list.GetHead()->value, 3);

  const vector<int> expected = {3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);
}

void TestInsertAfter() {
  LinkedList<string> list;

  list.PushFront("a");
  auto head = list.GetHead();
  ASSERT(head);
  ASSERT_EQUAL(head->value, "a");

  list.InsertAfter(head, "b");
  const vector<string> expected1 = {"a", "b"};
  ASSERT_EQUAL(ToVector(list), expected1);

  list.InsertAfter(head, "c");
  const vector<string> expected2 = {"a", "c", "b"};
  ASSERT_EQUAL(ToVector(list), expected2);
}

void TestRemoveAfter() {
  LinkedList<int> list;
  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }

  const vector<int> expected = {5, 4, 3, 2, 1};
  ASSERT_EQUAL(ToVector(list), expected);

  auto next_to_head = list.GetHead()->next;
  list.RemoveAfter(next_to_head); // СѓРґР°Р»СЏРµРј 3
  list.RemoveAfter(next_to_head); // СѓРґР°Р»СЏРµРј 2

  const vector<int> expected1 = {5, 4, 1};
  ASSERT_EQUAL(ToVector(list), expected1);

  while (list.GetHead()->next) {
    list.RemoveAfter(list.GetHead());
  }
  ASSERT_EQUAL(list.GetHead()->value, 5);
}

void TestPopFront() {
  LinkedList<int> list;

  for (int i = 1; i <= 5; ++i) {
    list.PushFront(i);
  }
  for (int i = 1; i <= 5; ++i) {
    list.PopFront();
  }
  ASSERT(list.GetHead() == nullptr);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestPushFront);
  RUN_TEST(tr, TestInsertAfter);
  RUN_TEST(tr, TestRemoveAfter);
  RUN_TEST(tr, TestPopFront);

  array<char, 10> c;
  c[0] = c[1] = c[2] = 's';
  string_view s(&c[0], c.size());
  return 0;
}
