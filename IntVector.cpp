#include <cmath>
#include "IntVector.h"

using namespace std;

// Constructors

IntVector::IntVector()
{
    array = new int[INITIAL_CAPACITY];
    count = 0;
    capacity = INITIAL_CAPACITY;
}

IntVector::IntVector(int size, int value)
{
    if(size < 0)
    {
        size = 0;
    }
    capacity = INITIAL_CAPACITY;
    array = new int[INITIAL_CAPACITY];
    count = 0;

    for(int i = 0; i < size; i++)
    {
        push_back(value);
    }
}

IntVector::IntVector(const IntVector& vec)
    : capacity(vec.capacity), count(vec.count)
{
    array = new int[capacity];

    for(int i = 0; i < count; i++)
    {
        array[i] = vec.array[i];
    }
}


IntVector::~IntVector()
{
    delete[] array;
    array = NULL;
}

// Public member functions ///////////////////////////////////

void IntVector::push_back(int elem)
{
    array[count] = elem;
    count++;

    checkSize();
}

void IntVector::insert(int index, int elem)
{

    if(index < 0 || index > count)
    {
        throw IndexOutOfRangeException();

    }
    else
    {

        if(count > 0)
        {
            push_back(array[count - 1]);

            for(int i = count - 2; i > index; i--)
            {
                array[i] = array[i - 1];
            }
        }
        else
        {
            count++;
        }
        array[index] = elem;
    }
}

int IntVector::at(int index) const
{
    if(index < 0 || index >= count)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        return array[index];
    }
}

void IntVector::set_value_at(int index, int elem)
{
    if(index < 0 || index >= count)
    {
        throw IndexOutOfRangeException();
    }
    else
    {
        array[index] = elem;
    }
}

int IntVector::size() const
{
    return count;
}

bool IntVector::empty() const
{
    if (count == 0)
    {
        return true;
    }
    return false;
}

void IntVector::remove_at(int index)
{
    if(index < 0 || index >= count)
    {
        throw IndexOutOfRangeException();
        return;
    }
    for(int i = index; i<count; i++)
    {
        array[i] = array[i + 1];
    }
    count--;
    return;
}

int IntVector::pop_back()
{
    if(empty())
    {
        throw EmptyException();
    }
    else
    {
        count--;
        return array[count];
    }
}

void IntVector::clear()
{
    count = 0;
    return;
}

void IntVector::checkSize()
{
    if(count >= capacity)
    {
        capacity = capacity * 2;

        int* tmp;
        tmp = new int[capacity];

        for(int i = 0; i < count; i++)
        {
            tmp[i] = array[i];
        }

        delete[] array;
        array = NULL;

        array = tmp;
    }
}


// Overloaded operators ///////////////////////////////////

void IntVector::operator = (const IntVector& vec)
{
    if(capacity < vec.capacity)
    {
        delete [] array;
        array = new int[vec.capacity];
    }

    capacity = vec.capacity;
    count = vec.count;

    for(int i = 0; i != count; i++)
    {
        array[i] = vec.array[i];
    }
}

int& IntVector::operator[] (int index)
{
    if(index < 0 || index >= count)
    {
        throw IndexOutOfRangeException();
    }

    return array[index];
}

ostream& operator << (ostream& out, const IntVector& rhs)
{
    for(int i = 0; i < rhs.size(); i++)
    {
        if(i > 0)
        {
            out << " ";
        }
        out << rhs.at(i);
    }
    return out;
}

