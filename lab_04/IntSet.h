#pragma once
#define MIN_SIZE 10
#include <cmath>

class IntSet
{
    public:

    // Constructors :)
    IntSet(int s = MIN_SIZE) {
        size = s;
        array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = 0;
    }

    IntSet(int s, int arr[]) {
        size = s;
        array = new int[size];
        for (int i=0; i < size; i++)
            array[i] = arr[i];
    }
    
    // Getters & Setters :)
    int getSize(){return size;};
    int* getArr(){return array;};
    void setSize(int n){this->size = n;};
    void setArr(int* arr[]);
    

    // Overwriting methods :)
    IntSet operator = (IntSet newSet){
        return IntSet(newSet.size, newSet.array);
    }

    IntSet operator * (IntSet anotherSet){
        int newSize = size * anotherSet.size;
        int newArr[newSize] = {};
        int index = 0;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < anotherSet.size; j++){
                newArr[index] = array[i] * anotherSet.array[j];
                index++;
            } 
        }
        return IntSet(newSize, newArr);
    }

// Закоментированная перегрузка, которая не соответствует условию уникальностм значений

    // IntSet operator + (IntSet anotherSet){
    //     int newSetSize = size + anotherSet.size;
    //     int newArr[newSetSize] = {};
    //     for (int i=0; i < newSetSize; i++){
    //         while(i < size){
    //             newArr[i] = array[i];
    //             i++;
    //         }
    //         newArr[i] = anotherSet.array[i-size];
    //     }
    //     return IntSet(newSetSize, newArr);
    // }

    IntSet operator + (IntSet anotherSet){
        int diff = 0;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < anotherSet.size; j++){
                if (array[i] == anotherSet.array[j]){diff++;}
            } 
        }
        if(diff == 0){return IntSet(size, array);}
        int newSize = (size + anotherSet.size) - diff;
        int newArr[newSize] = {};
        for (int i = 0; i < newSize; i++){
            for (int j = 0; j < anotherSet.size; j++){
                while (i < size){
                    if (array[i] == anotherSet.array[j]){break;}
                    else{newArr[i] = array[i];}
                    i++;
                }
                newArr[i] = anotherSet.array[j]; // тут что-то не так
            } 
        }
        return IntSet(newSize, newArr);
    }

// неправильно работает
    IntSet operator - (IntSet anotherSet){
        int diff = 0;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < anotherSet.size; j++){
                if (array[i] == anotherSet.array[j]){diff++;}
            } 
        }
        if(diff == 0){return IntSet(size, array);}
        int newSize = size - diff;
        int newArr[newSize] = {};
        for (int i = 0; i < size; i++){
            for (int j = 0; j < anotherSet.size; j++){
                if (array[i] == anotherSet.array[j]){break;}
                else{newArr[i] = array[i];}
            } 
        }
        return IntSet(newSize, newArr);
    }
    
    IntSet operator + (int n){
        for(int i = 0; i < size; i++){
            if (array[i] == n){
                return IntSet(size, array);     // If our set contains 'n' value, then returning set
            }
        }
        int newArr[size + 1] = {};
        for (int i=0; i < (size); i++){
            newArr[i] = array[i];
        }
        newArr[size]=n;
        return IntSet(size+1, newArr);
    }

    IntSet operator - (int n){
        // for(int i = 0; i < this->size; i++){
        //     if (this->array[i] == n){
        //         int index = i;
        //         int* newArr[this->size - 1];
        //         for (int i=0; i < (this->size); i++){
        //             if (i == index) {}
        //             newArr[i] = this->array[i];
        //         }
        //         return IntSet(this->size+1, newArr);     
        //     }
        // }
        return IntSet(size, array);     // If our set does not contain 'n' value, then returning set
    }

    bool operator ==(IntSet anotherSet){
        if(size == anotherSet.size){
            for (int i=0; i < (size); i++){
            if(array[i]!=anotherSet.array[i]){return false;}
            }
            return true;   
        }
        return false;
    }
    
    bool operator !=(IntSet anotherSet){
        if(size != anotherSet.size){return true;}
        for (int i=0; i < size; i++){
            if(array[i]!=anotherSet.array[i]){
                return true;
            }
        }
        return false;
    }

    bool operator >(IntSet anotherSet) {
        return size > anotherSet.size;
    }

    bool operator <(IntSet anotherSet) {
        return size < anotherSet.size;
    }

    bool operator >=(IntSet anotherSet) {
        return size >= anotherSet.size;
    }

    bool operator <=(IntSet anotherSet) {
        return size <= anotherSet.size;
    }

private:
    unsigned int size;
    int* array;
};