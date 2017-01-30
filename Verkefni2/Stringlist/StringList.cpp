#include "StringList.h"

using namespace std;

StringList::StringList()
{
    head = new StringNode("H",NULL,NULL);    //head bendir hvergi
    tail = new StringNode("T",NULL,head);    //tail bendir hvergi
    head->prev = tail;
    curr = tail;
    sise = 0;
    cPos = 0;
}

StringList::~StringList()
{
    StringNode *node = head;        // bý til tímabundna breytu
    while(node != NULL)             // meðan hún er ekki komin á enda
    {
        head = node;                // fer í gegnum listan frá head til tail
        node = node->next;          // og eyði hverju staki fyrir sig.
        delete head;
    }
    head = NULL;
    tail = NULL;
}

    // Clear contents from the list, to make it empty.
    // Worst-case time complexity: Linear
void StringList::clear()
{

}

    // Insert an element at the current location.
    // item: The element to be inserted
    // Worst-case time complexity: Constant
void StringList::insert(const string& item)
{
    StringNode *node = new StringNode(item, curr, curr->prev);
    curr->prev->next = node;
    curr->prev = node;
    sise++;
    cPos++;
}

    // Append an element at the end of the list.
    // item: The element to be appended.
    // Worst-case time complexity: Constant
void StringList::append(const string& item)
{
    StringNode *node = new StringNode(item, tail, NULL);

    tail->prev->next = node;
    node->prev = tail->prev;
    tail->prev = node;
    sise++;
}

    // Remove and return the current element.
    // Return: the element that was removed.
    // Worst-case time complexity: Constant
    // Throws InvalidPositionException if current position is
    // behind the last element
string StringList::remove()
{
    if(curr == tail)
    {
        throw InvalidPositionException();
    }
    else if (cPos <= 0)
    {

    }
    else
    {
    string text = curr->data;
    StringNode *ptr = curr->prev;

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete &curr;

    curr = ptr;

    sise--;
    cPos--;

    return text;
    }
    return "";
}

    // Set the current position to the start of the list
    // Worst-case time complexity: Constant
void StringList::move_to_start()
{
    curr = head;
    cPos = 0;
}

    // Set the current position to the end of the list
    // Worst-case time complexity: Constant
void StringList::move_to_end()
{
    curr = tail;
    cPos = sise;
}

    // Move the current position one step left. No change
    // if already at beginning.
    // Worst-case time complexity: Constant
void StringList::prev()
{
    if(curr != head)
    {                               // ef curr kemst framar
        curr = curr->prev;          // er curr fært framar
        cPos--;                     // og staðsetning uppfærð
    }
}

    // Move the current position one step right. No change
    // if already at end.
    // Worst-case time complexity: Constant
void StringList::next()
{
    if(curr != tail)                // ef curr kemst aftar
    {                               // er curr fært aftar
        curr = curr->next;          // og staðsetning uppfærð
        cPos++;
    }
}

    // Return: The number of elements in the list.
    // Worst-case time complexity: Constant
int StringList::length() const
{
    return sise;
}

    // Return: The position of the current element.
    // Worst-case time complexity: Constant
int StringList::curr_pos() const
{
    return cPos;
}

    // Set current position.
    // pos: The position to make current.
    // Worst-case time complexity: Linear
    // Throws InvalidPositionException if 'pos' is not a valid position
void StringList::move_to_pos(int pos)
{
    while(pos > cPos)           // ef pos er ofar en staðsetning curr
    {                           // er færrt curr upp þangað til þeir
        next();                 // eru orðnir jafnir
    }
    while(pos < cPos)           // ef pos er neðar en staðsetning curr
    {                           // er fært curr niðurþangað til þeir
        prev();                 // eru orðnir jafnir
    }
}

    // Return: The current element.
    // Worst-case time complexity: Constant
    // Throws InvalidPositionException if current position is
    // behind the last element
const string& StringList::get_value() const
{
    if(curr == tail)
    {
        throw InvalidPositionException();
        return NULL;
    }
    return curr->data;

}

    // Outputs the elements of 'lis' to the stream 'outs', separated
    // by a single space.
ostream& operator <<(ostream& outs, const StringList& lis)
{
    StringNode *ptr;
    ptr = lis.head;

    while(ptr->next->next != NULL)
    {
        ptr = ptr->next;
        outs << ptr->data << " ";
    }

    return outs;
}
