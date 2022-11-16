#pragma once

// реализацию множества set (на основе массива с
// сортировкой) для хранения только уникальных элементов

using namespace std;

template<typename T>
class MySet {
public:
    MySet() {
        this->m_arr = nullptr;
        this->m_size = 0;
    }

    MySet(const MySet<T>* obj) {
        this->m_arr = new T[obj->m_size];
        if (!this->m_arr) throw bad_alloc();

        this->m_size = obj->m_size;

        for(int i = 0; i < this->m_size; i++)
            this->m_arr[i] = obj->m_arr[i];
    }

    MySet(const std::initializer_list<T> items) {
        this->m_size = items.size();

        this->m_arr = new T[this->m_size];
        if (!this->m_arr) throw bad_alloc();

        copy(items.begin(), items.end(), this->m_arr);
        insertionSort(this->m_arr, this->m_size);
    }

    void insert(const T& value) {
        int index = this->search(value);
        if(index < 0) {
            T *newArr = new T[this->m_size + 1];
            if(!newArr) throw bad_alloc();

            for(int i = 0; i < this->m_size; i++){
                newArr[i] = this->m_arr[i];
            }
            newArr[this->m_size] = value;
            this->insertionSort(newArr, this->m_size+1);

            delete this->m_arr;
            this->m_arr = newArr;
            this->m_size++;
        }
    }

    void erase(const T& value) {
        if(!this->m_size) throw "Empty list!";

        if(this->search(value) > -1) {
            T *newArr = new T[this->m_size + 1];
            if(!newArr) throw bad_alloc();

            for (int i = 0, j = 0; i < this->m_size; i++)
                if(this->m_arr[i] != value) newArr[j++] = this->m_arr[i];

            delete this->m_arr;
            this->m_arr = newArr;
            this->m_size--;
        }
    } // (бросает исключение на пустом множестве)

    bool find(const T& value) const {
        if(!this->size) throw "Empty list!";
        
        return search(value) > -1 ? 1 : 0;
    }

    unsigned int getSize() const {
        return this->m_size;
    }

    void clear() {
        delete(this->m_arr);
        this->m_arr = nullptr;
        this->m_size = 0;
    }

    T& operator[] (const int index) const {
        return this->m_arr[index];
    }

    friend std::ostream& operator<< (std::ostream &out, const MySet &obj) {
        if(!obj.m_size){
            cout << "Empty set!";
        }
        for(int i = 0; i < obj.m_size; i++)
            cout << obj.m_arr[i] << ' ';
        return out;
    }

    MySet & operator=(const MySet& a) {
        return *this;
    }

    ~MySet(){
        delete(this->m_arr);
    }

private:
    T *m_arr;
    int m_size;

    int search(const T& value) const {
        for(int i = 0; i < this->m_size; i++)
            if(this->m_arr[i] == value) return i;
        return -1;
    }

    void insertionSort(T array[], int size) {
        for (int step = 1; step < size; step++) {
            T key = array[step];
            int j = step - 1;
            while (key < array[j] && j >= 0) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = key;
        }
    }
};
