#pragma once
#define MIN_SIZE 10
#include <cmath>
#include <new>

using namespace std;

class IntSet
{
public:

    // конструкторы
    IntSet(unsigned int size = MIN_SIZE); // по умолчанию
    IntSet(unsigned int size, int arr[]); // обычный
    IntSet(const initializer_list<int> list); // braced-init-list ({}) конструктор
    IntSet(const IntSet& anotherSet); // копирования

    //геттеры и сеттеры
    [[nodiscard]] unsigned int getSize() const;
    [[nodiscard]] int* getArr() const;
    void setSize(int n);
    void setArr(int* arr[]);

    // добавление удаление элемента в множество
    // если элемента нет при удалении или есть при добавлении
    // возвращает неизмененное множество
    friend IntSet operator +(const IntSet &anotherSet, int num);
    friend IntSet operator -(const IntSet &leftSet, int num);
    IntSet& operator +=(const int &right);
    IntSet& operator -=(const int &right);

    // ввод вывод
    friend ostream& operator <<(ostream &out, const IntSet &anotherSet);
    friend istream& operator >>(istream &in, IntSet &anotherSet);

    // логические операции над множествами
    friend IntSet operator +(const IntSet &set1, const IntSet &set2); // логисческое сложение (объединение)
    friend IntSet operator *(const IntSet &set1, const IntSet &set2); // логисческое умножение (пересечение)
    friend IntSet operator -(const IntSet &left, const IntSet &right); // логисческое вычитание (дополнение)
    IntSet& operator =(const IntSet &right);
    IntSet& operator +=(const IntSet &right);
    IntSet& operator -=(const IntSet &right);
    IntSet& operator *=(const IntSet &right);

    // проверка отношений между множествами
    friend bool operator ==(const IntSet &left, const IntSet &right); // равны
    friend bool operator !=(const IntSet &left, const IntSet &right); // не равны
    friend bool operator >(const IntSet &left, const IntSet &right); // левое содержит правое
    friend bool operator <(const IntSet &left, const IntSet &right); // левое содержится в правом
    friend bool operator >=(const IntSet &left, const IntSet &right); // левое содержит правое или равны
    friend bool operator <=(const IntSet &left, const IntSet &right); // левое содержится в правом или равны

    // деструктор
    ~IntSet();

private:
    unsigned int m_size;
    int* m_arr;

    [[nodiscard]] bool contains(const int value) const;
    void sort();
};




// конструкторы
IntSet::IntSet(unsigned int size) {
    this->m_arr = new int[MIN_SIZE];
    if(!this->m_arr) throw bad_alloc();

    this->m_size = size;

    for (int i = 0; i < this->m_size; i++)
        this->m_arr[i] = i;
}
// по умолчанию

IntSet::IntSet(unsigned int size, int arr[]) {
    this->m_arr = new int[this->m_size];
    if(!this->m_arr) throw bad_alloc();

    this->m_size = size;

    for (int i=0; i < this->m_size; i++)
        this->m_arr[i] = arr[i];
}
// обычный

IntSet::IntSet(const initializer_list<int> list) {
    this->m_arr = new int[this->m_size];
    if(!this->m_arr) throw bad_alloc();

    this->m_size = list.size();

    int i = 0;
    for (auto& item: list)
        this->m_arr[i++] = item;
}
// braced-init-list({}) конструктор

IntSet::IntSet(const IntSet& anotherSet){
    this->m_arr = new int[anotherSet.m_size];
    if(!this->m_arr) throw bad_alloc();

    this->m_size = anotherSet.m_size;

    for (int i=0; i < this->m_size; i++)
        this->m_arr[i] = anotherSet.m_arr[i];
}
// копирования

[[nodiscard]] unsigned int IntSet::getSize() const {
    return this->m_size;
} // геттеры

[[nodiscard]] int* IntSet::getArr() const {
    return this->m_arr;
}

void IntSet::setSize(int n) {
    this->m_size = n;
} // сеттеры (хз зачем они нужны вообще)

void IntSet::setArr(int* arr[]) {
    this->m_arr;
}

IntSet& IntSet::operator=(const IntSet &right) {
    this->~IntSet();
    this->m_size = right.m_size;
    this->m_arr = right.m_arr;
    return *this;
} // присваивание

IntSet operator+(const IntSet &anotherSet, const int num) {
    IntSet newSet;
    if(!(anotherSet.contains(num))) {
        newSet = IntSet(anotherSet.m_size + 1);

        for(int i = 0; i < anotherSet.m_size; i++) {
            newSet.m_arr[i] = anotherSet.m_arr[i];
        }

        newSet.m_arr[anotherSet.m_size] = num;
        newSet.sort();
    } else {
        newSet = IntSet(anotherSet);
    }
    return newSet;
}
// a = { 1,2,3 }; a + 4 = a{ 1,2,3,4 }; a + 2 = { 1,2,3,4 }; // добавление элемента в множество

IntSet operator-(const IntSet &leftSet, const int num) {
    IntSet newSet;
    if(leftSet.contains(num)) {
        newSet = IntSet(leftSet.m_size - 1);

        for(int i = 0, j = 0; i < leftSet.m_size; i++) {
            if(leftSet.m_arr[i] != num)
                newSet.m_arr[j++] = leftSet.m_arr[i];
        }
    } else {
        newSet = IntSet(leftSet);
    }
    return newSet;
}
// a = { 1,2,3 }; a - 4 = a{ 1,2,3 }; a - 2 = { 1,3 }; // удаление элемента из множества

IntSet operator+(const IntSet &set1, const IntSet &set2) {
    IntSet newSet = IntSet(0);

    for(int i = 0; i < set1.m_size; i++)
        newSet = newSet + set1.m_arr[i];
    for(int i = 0; i < set2.m_size; i++)
        newSet = newSet + set2.m_arr[i];

    return newSet;

} // объединение множеств

IntSet operator*(const IntSet &set1, const IntSet &set2) {
    IntSet newSet = IntSet(0);

    for(int i = 0; i < set2.m_size; i++)
        if(set1.contains(set2.m_arr[i]))
            newSet = newSet + set2.m_arr[i];

    return newSet;

} // перечечение множеств

IntSet operator-(const IntSet &left, const IntSet &right) {
    IntSet newSet = IntSet(0);
    IntSet intersectionOfSets = left * right;

    for(int i = 0; i < left.m_size; i++)
        if(!(intersectionOfSets.contains(left.m_arr[i])))
            newSet = newSet + left.m_arr[i];

    return newSet;
} // дополнение множества right до множества left

IntSet& IntSet::operator+=(const int &right) {
    *this = *this + right;
    return *this;
} // присваивание с прибавлением числа

IntSet& IntSet::operator-=(const int &right) {
    *this = *this - right;
    return *this;
} // присваивание с вычитанием числа

IntSet& IntSet::operator+=(const IntSet &right) {
    *this = *this + right;
    return *this;
} // присваивание с объединением множества

IntSet& IntSet::operator-=(const IntSet &right) {
    *this = *this - right;
    return *this;
} // присваивание с дополнением множества

IntSet& IntSet::operator*=(const IntSet &right) {
    *this = *this * right;
    return *this;
} // присваивание с пересечением множества

bool operator>(const IntSet &left, const IntSet &right) {
    for(int i = 0; i < right.m_size; i++)
        if(!left.contains(right.m_arr[i]))
            return false;
    return true;
} // левое множество содержит правое

bool operator<(const IntSet &left, const IntSet &right) {
    for(int i = 0; i < left.m_size; i++)
        if(!right.contains(left.m_arr[i]))
            return false;
    return true;
} // левое множество подмножество правого

bool operator==(const IntSet &left, const IntSet &right) {
    return left < right && right > left;
} // правое множество равно левому

bool operator!=(const IntSet &left, const IntSet &right) {
    return !(left == right);
} // правое множество не равно левому

bool operator>=(const IntSet &left, const IntSet &right) {
    return left > right || left == right;
} // левое множество содержит правое или равно ему

bool operator<=(const IntSet &left, const IntSet &right) {
    return left < right || left == right;
} // левое множество подмножество правого или равно ему

ostream& operator<<(ostream &out, const IntSet &anotherSet) {
    out << "{ ";
    for(int i = 0; i < anotherSet.m_size; i++)
        i != (anotherSet.m_size - 1) ? out << anotherSet.m_arr[i] << ',' : out << anotherSet.m_arr[i];
    out << " }";
    return out;
} // вывод

istream& operator>>(istream &in, IntSet &anotherSet) {
    for(int i = 0; i < anotherSet.m_size; i++)
        in >> anotherSet.m_arr[i];
    anotherSet.sort();
    return in;
} // ввод

IntSet::~IntSet() {
    delete (this->m_arr);
    this->m_arr = nullptr;
} // деструктор

[[nodiscard]] bool IntSet::contains(const int value) const {
    for(int i = 0; i < this->m_size; i++)
        if(this->m_arr[i] == value) return true;
    return false;
} // проверка принадлежности элемента

void IntSet::sort() {
    int* array = this->m_arr;
    int size = this->m_size;
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
} // сортировка
