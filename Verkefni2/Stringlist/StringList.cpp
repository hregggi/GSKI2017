#include "StringList.h"

using namespace std;

StringList::StringList()
{
    head = new StringNode("H", NULL, NULL);     //head bendir hvergi
    tail = new StringNode("T", NULL, head);     //tail bendir � head
    head->next = tail;                          // head bnir � tail
    curr = tail;                                // curr bendir � tail
    sise = 0;                                   // st�r� er 0 og sta�setning er 0
    cPos = 0;
}

StringList::~StringList()
{
    clear();                                    // ey�i innihaldi listans
    delete head;                                // ey�i haus listans
    delete tail;                                // ey�i tail istans
}

    // Clear contents from the list, to make it empty.
    // Worst-case time complexity: Linear
void StringList::clear()
{
    move_to_start();                            //  set curr fremst
    while(sise != 0)                            // me�an eithva� er � lisatanum
    {
        remove();                               // er hreinsa� n�sta stak �r listanum
    }
}

    // Insert an element at the current location.
    // item: The element to be inserted
    // Worst-case time complexity: Constant
void StringList::insert(const string& item)
{
    StringNode *node = new StringNode(item, curr, curr->prev);
                                                // n�tt node komi� fyrir framan curr
    curr->prev->next = node;                    // staki� sem var fyrir framan curr bendir n� � n�ja
    curr->prev = node;                          // staki� sem curr var a� benda � bendir n� � n�ja
    curr = node;                                // curr bendir n� � n�ja
    sise++;                                     // listi hefur st�kka� um eitt stak
}

    // Append an element at the end of the list.
    // item: The element to be appended.
    // Worst-case time complexity: Constant
void StringList::append(const string& item)
{
    StringNode *node = new StringNode(item, tail, tail->prev);
                                                // n�ja staki� er fyrir framan tail
    tail->prev->next = node;                    // �a� sem var fyrir framan tail bendir n� � n�ja
    tail->prev = node;                          // og tail bendir l�ka � n�ja
    sise++;                                     // fylki hefur st�kka� um 1

    if(curr == tail)                            // ef curr var a� benda � tail
    {
        curr = tail->prev;                      // �� bendir �a� n� � n�ja staki�
    }
}

    // Remove and return the current element.
    // Return: the element that was removed.
    // Worst-case time complexity: Constant
    // Throws InvalidPositionException if current position is
    // behind the last element
string StringList::remove()
{
    if(cPos >= sise || sise == 0)               // ef fylki� er 0 st�rt e�a curr er komi� � tail
    {
        throw InvalidPositionException();       // er kasta� villu um �l�glega st��u
    }
    else
    {
        string text = curr->data;               // breyta geymir textan �r stakinu sem skal fjarl�gja
        StringNode *ptr = curr;                 // n�r bendir bendir � sama og ccurr bendirinn bendir �..... bendir

        ptr->prev->next = ptr->next;            // n��urnar sitthvoru megin vi� staki� sem skal ey�a
        ptr->next->prev = ptr->prev;            // benda n� � hvor a�ra.

        curr = curr->next;                      // curr f�r gyldi� � n��unni sem var fyrir framan hana

        delete ptr;                             // ey�i �t gyldinu sme �tti a� ey�a
        sise--;                                 // listinn hefur n� minnka� � st�r�
        return text;                            // og textanum skila� til main, e�a hvert sem hann �tti a� fara
    }
    return "";
}

    // Set the current position to the start of the list
    // Worst-case time complexity: Constant
void StringList::move_to_start()
{
    cPos = 0;                                   // sta�setning curr er n�na fremst
    curr = head->next;                          // �eas beint fyrir framan head
}

    // Set the current position to the end of the list
    // Worst-case time complexity: Constant
void StringList::move_to_end()
{
    cPos = sise;                                // sta�setning curr er n�na aftast
    curr = tail;                                // �eas � tail
}

    // Move the current position one step left. No change
    // if already at beginning.
    // Worst-case time complexity: Constant
void StringList::prev()
{
    if(cPos > 0)
    {                                           // ef curr kemst framar
        curr = curr->prev;                      // er curr f�rt framar
        cPos--;                                 // og sta�setning uppf�r�
    }
}

    // Move the current position one step right. No change
    // if already at end.
    // Worst-case time complexity: Constant
void StringList::next()
{
    if(cPos < sise)                             // ef curr kemst aftar
    {                                           // er curr f�rt aftar
        curr = curr->next;                      // og sta�setning uppf�r�
        cPos++;

    }
}

    // Return: The number of elements in the list.
    // Worst-case time complexity: Constant
int StringList::length() const
{
    return sise;               // skilar fj�lda hlekkja � listanum (a� head og tail utanskyldum)
}

    // Return: The position of the current element.
    // Worst-case time complexity: Constant
int StringList::curr_pos() const
{
    return cPos;                                // skila sta�setningu � curr bendinum
}

    // Set current position.
    // pos: The position to make current.
    // Worst-case time complexity: Linear
    // Throws InvalidPositionException if 'pos' is not a valid position
void StringList::move_to_pos(int pos)
{
    if(pos > sise || pos < 0)
    {                                           // ef pos er utan listans
        throw InvalidPositionException();       // er kasta� villu um �l�glega sta�setningu
    }
    else
    {
        while(pos > cPos)                       // ef pos er ofar en sta�setning curr
        {                                       // er f�rrt curr upp �anga� til �eir
            next();                             // eru or�nir jafnir
        }
        while(pos < cPos)                       // ef pos er ne�ar en sta�setning curr
        {                                       // er f�rt curr ni�ur�anga� til �eir
            prev();                             // eru or�nir jafnir
        }
    }
}

    // Return: The current element.
    // Worst-case time complexity: Constant
    // Throws InvalidPositionException if current position is
    // behind the last element
const string& StringList::get_value() const
{
    if(curr == tail)
    {                                           // ef curr er � tail
        throw InvalidPositionException();       // er kasta� villu um �l�glega sta�setningu
        return NULL;                            // og engu skila�
    }
    return curr->data;                          // annars er skila� g�gnunum �r n��unni curr bendir �

}

    // Outputs the elements of 'lis' to the stream 'outs', separated
    // by a single space.
ostream& operator <<(ostream& outs, const StringList& lis)
{
    if(lis.sise > 0){                           // ef eithva� er � anna�bor� � listanum
        StringNode *ptr;                        // er n�r bendir sentur � haus listans
        ptr = lis.head;

        while(ptr->next->next != NULL)          // � me�an hann er tveimur fr� tail
        {
            ptr = ptr->next;                    // er hann f�r�ur einn �fram
            outs << ptr->data << " ";           // og svo prenta� �t staki� �r honum me� bili � eftir
        }
    }
    return outs;                                // cout � �� a� geta prenta� �a� �t
}
