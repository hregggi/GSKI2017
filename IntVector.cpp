#include <cmath>
#include "IntVector.h"

using namespace std;

// Constructors

IntVector::IntVector() {
    // TODO: Implement
    array = new int[INITIAL_CAPACITY];
    capacity = INITIAL_CAPACITY;
}

IntVector::IntVector(int size, int value) {
    // TODO: Implement
    capacity=INITIAL_CAPACITY;

    for(int i=0; i<size; i++){
        push_back(value);
    }
}

IntVector::IntVector(const IntVector& vec)
    : capacity(vec.capacity), count(vec.count) {
    array = new int[capacity];

    for(int i = 0; i < count; i++) {
        array[i] = vec.array[i];
    }
}


IntVector::~IntVector() {
    // TODO: Implement
}

// Public member functions

void IntVector::push_back(int elem) {
    count++;
    array[count-1]=elem;
}

void IntVector::insert(int index, int elem) {
    if(index<0 || index>count){

        throw IndexOutOfRangeException();

    }else{

        for(int i=count; i>index; i--){
            push_back(array[i]);
        }

    }
    return;
}

int IntVector::at(int index) const {
    if(index<0 || index>count){
        throw IndexOutOfRangeException();
        return 0;
    }
    return array[index];
}

void IntVector::set_value_at(int index, int elem) {
    array[index] = elem;
}

int IntVector::size() const {
    return count;
}

bool IntVector::empty() const {
    if (count==0)
        return true;

    return false;
}

void IntVector::remove_at(int index) {
    // TODO: Implement
}

int IntVector::pop_back() {
    // TODO: Implement
    return 0;
}

void IntVector::clear() {
    // TODO: Implement
}

// Overloaded operators

void IntVector::operator=(const IntVector& vec) {
    if(capacity < vec.capacity) {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++) {
        array[i] = vec.array[i];
    }
}

int& IntVector::operator[] (int index) {
    // TODO: Throw exception if index is out of range.
    return array[index];
}

ostream& operator<< (ostream& out, const IntVector& rhs) {
    for(int i = 0; i < rhs.size(); i++) {
		if(i > 0) {
			out << " ";
		}
        out << rhs.at(i);
    }
    return out;
}
