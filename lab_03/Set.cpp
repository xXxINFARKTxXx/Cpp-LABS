#include<iostream>
#include<assert.h>

struct node
{
    int data;
    node* next;
    node() :data(0), next(nullptr) {}
    node(int d) :data(d), next(nullptr) {}
};

//forward declaration
class MyList;

class MyListIterator
{
private:
    node* _ptr;
    friend class MyList;
    explicit MyListIterator(node* n) : _ptr(n) {}
public:
    int& operator*() const {
        return _ptr->data;
    }
    //overload pre increment operator
    MyListIterator& operator++() {
        _ptr = _ptr->next;
        return *this;
    }
    // overload post increment operator
    MyListIterator operator++(int) {
        MyListIterator ret = *this;
        ++* (this);
        return ret;
    }

    bool operator==(const MyListIterator& iter) const {
        return this->_ptr == iter._ptr;
    }

    bool operator!=(const MyListIterator& iter) const {
        return this->_ptr != iter._ptr;
    }
};

class MyList
{
private:
    node* _head;
    node* _tail;
    size_t _size;
public:
    MyList() : _head(nullptr), _tail(nullptr), _size(0) {};

    void push_back(int d) {
        node* newTail = new node(d);
        if (_tail != nullptr) {
            _tail->next = newTail;
        }
        else {
            _head = newTail;
        }
        _tail = newTail;
        _size++;
    }

    int& operator[](size_t i) {
        if (i >= _size)
            throw std::out_of_range("MyList");
        node * p = _head;
        for (size_t j = 0; j < i; j++) {
            p = p->next;
        }
        return p->data;
    }

    void remove(int d) {
        if (_head == nullptr)
            return;
        node * p = _head;
        node * prev = p;
        while ((p != nullptr) && (p->data != d)) {
            prev = p;
            p = p->next;
        }
        if (p != nullptr) {
            if (p == _head)
                _head = p->next;
            else
                prev->next = p->next;
            delete p;
            _size--;
        }
    }

    size_t size() const {
        return _size;
    }

    ~MyList() {
        node* next = nullptr;
        for (node* p = _head; p != nullptr; p = next) {
            next = p->next;
            delete p;
        }
    }
    using iterator = MyListIterator;
    iterator begin() { return iterator(_head); }
    iterator end() { return iterator(_tail->next); }
};

int main1()
{

    MyList mylist;
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(3);
    int count = 1;
    //pre increment
    for (MyListIterator it = mylist.begin(); it != mylist.end(); ++it)
        assert(*it == count++);
    count = 1;
    //post increment
    for (MyListIterator it = mylist.begin(); it != mylist.end(); it++)
        assert(*it == count++);
    for (size_t i = 0; i < 3; i++)
        assert(mylist[i] == i + 1);

    mylist.remove(2);
    assert(mylist[0] == 1);
    assert(mylist[1] == 3);
    assert(mylist.size() ==2);

    mylist.remove(1);
    mylist.remove(3);
    assert(mylist.size() == 0);

}