// реализацию множества set (на основе массива с
// сортировкой) для хранения только уникальных элементов

#include <cstdlib>
#include <cstring>

template<typename T>
class MySet {
public:
    MySet(){
        this->m_arr = nullptr;
        this->m_size = 0;
    }

    MySet(const MySet &ref_MySetObj) {
        if(!this->m_arr = calloc(this->m_size, sizeof(T)))
            throw std::bad_alloc();
        this->m_size = ref_MySetObj.m_size;
        memcpy(this->m_arr, ref_MySetObj, this->m_size);
    }

    MySet(const std::initializer_list<T> items) {
        this->m_arr = (T*)calloc(items.size() * sizeof(T), sizeof(T));
        if(!this->m_arr)
            throw std::bad_alloc();
        this->m_size = items.size();
        int i = 0;
        for(auto it = items.begin(); i < items.size();it++, i++) {
            if(!this->find((T&)*it))
                this->m_arr[i] = (T&)*it;
        }
    }

    void insert(const T& value) {
        int index = this->binarySearch(value);
        if(index == -1) {
            if (!this->m_arr = realloc(this->m_arr, sizeof(T) * (this->m_size + 1)))
                throw std::bad_alloc();
            this->m_size++;
            int i = this->m_size - 1, temp;
            while (this->m_arr[i] < this->m_arr[i-1]){
                temp = this->m_arr[i];
                this->m_arr[i] = this->m_arr[i-1];
                this->m_arr[i-1] = temp;
                i--;
            }
        }
    }

    void erase(const T& value) {
        int index = this->binarySearch(value);
        if(index != -1) {
            for(; index < this->size() - 1; index++)
                this->m_arr[index] = this->m_arr[index + 1];
            if (!this->m_arr = realloc(this->m_arr, sizeof(T) * (this->m_size - 1)))
                throw std::bad_alloc();
            this->m_size--;
        }
    } // (бросает исключение на пустом множестве)

    bool find(const T& value) const {
        if(!this->size())
            throw "Empty list!";
        return binarySearch(value) > -1 ? 1 : 0;
    }

    unsigned int size() const{
        return this->m_size;
    }

    void clear() {
        free(this->m_arr);
        this->m_arr = nullptr;
        this->m_size = 0;
    }

    T& operator[] (const int index) const {
        return this->m_arr[index];
    }

    //    friend std::ostream& operator<< (std::ostream &out, const MySet &obj);

//    ~MySet(){
//        free(this->m_arr);
//    }

private:
    T *m_arr;
    unsigned int m_size{};

    int binarySearch(T value) const {
        T low = this->m_arr[0], middle, high = this->m_arr[this->m_size];
        while (low<= high){
            middle = (low + high) / 2;
            if (value < this->m_arr[middle])
                high = middle - 1;
            else if (value > this->m_arr[middle])
                low = middle + 1;
            else
                return middle;
        }
        return -1;
    }
};
