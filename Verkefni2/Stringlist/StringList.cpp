#include "StringList.h"

using namespace std;

StringList::StringList()
{
    head = new StringNode("H", NULL, NULL);     //head bendir hvergi
    tail = new StringNode("T", NULL, head);     //tail bendir á head
    head->next = tail;                          // head bnir á tail
    curr = tail;                                // curr bendir á tail
    sise = 0;                                   // stærð er 0 og staðsetning er 0
    cPos = 0;
}

StringList::~StringList()
{
    clear();                                    // eyði innihaldi listans
    delete head;                                // eyði haus listans
    delete tail;                                // eyði tail istans
}

    // Clear contents from the list, to make it empty.
    // Worst-case time complexity: Linear
void StringList::clear()
{
    move_to_start();                            //  set curr fremst
    while(sise != 0)                            // meðan eithvað er í lisatanum
    {
        remove();                               // er hreinsað næsta stak úr listanum
    }
}

    // Insert an element at the current location.
    // item: The element to be inserted
    // Worst-case time complexity: Constant
void StringList::insert(const string& item)
{
    StringNode *node = new StringNode(item, curr, curr->prev);
                                                // nýtt node komið fyrir framan curr
    curr->prev->next = node;                    // stakið sem var fyrir framan curr bendir nú á nýja
    curr->prev = node;                          // stakið sem curr var að benda á bendir nú á nýja
    curr = node;                                // curr bendir nú á nýja
    sise++;                                     // listi hefur stækkað um eitt stak
}

    // Append an element at the end of the list.
    // item: The element to be appended.
    // Worst-case time complexity: Constant
void StringList::append(const string& item)
{
    StringNode *node = new StringNode(item, tail, tail->prev);
                                                // nýja stakið er fyrir framan tail
    tail->prev->next = node;                    // það sem var fyrir framan tail bendir nú á nýja
    tail->prev = node;                          // og tail bendir líka á nýja
    sise++;                                     // fylki hefur stækkað um 1

    if(curr == tail)                            // ef curr var að benda á tail
    {
        curr = tail->prev;                      // þá bendir það nú á nýja stakið
    }
}

    // Remove and return the current element.
    // Return: the element that was removed.
    // Worst-case time complexity: Constant
    // Throws InvalidPositionException if current position is
    // behind the last element
string StringList::remove()
{
    if(cPos >= sise || sise == 0)               // ef fylkið er 0 stórt eða curr er komið á tail
    {
        throw InvalidPositionException();       // er kastað villu um ólöglega stöðu
    }
    else
    {
        string text = curr->data;               // breyta geymir textan úr stakinu sem skal fjarlægja
        StringNode *ptr = curr;                 // nýr bendir bendir á sama og ccurr bendirinn bendir á..... bendir

        ptr->prev->next = ptr->next;            // nóðurnar sitthvoru megin við stakið sem skal eyða
        ptr->next->prev = ptr->prev;            // benda nú á hvor aðra.

        curr = curr->next;                      // curr fær gyldið á nóðunni sem var fyrir framan hana

        delete ptr;                             // eyði út gyldinu sme átti að eyða
        sise--;                                 // listinn hefur nú minnkað í stærð
        return text;                            // og textanum skilað til main, eða hvert sem hann átti að fara
    }
    return "";
}

    // Set the current position to the start of the list
    // Worst-case time complexity: Constant
void StringList::move_to_start()
{
    cPos = 0;                                   // staðsetning curr er núna fremst
    curr = head->next;                          // þeas beint fyrir framan head
}

    // Set the current position to the end of the list
    // Worst-case time complexity: Constant
void StringList::move_to_end()
{
    cPos = sise;                                // staðsetning curr er núna aftast
    curr = tail;                                // þeas á tail
}

    // Move the current position one step left. No change
    // if already at beginning.
    // Worst-case time complexity: Constant
void StringList::prev()
{
    if(cPos > 0)
    {                                           // ef curr kemst framar
        curr = curr->prev;                      // er curr fært framar
        cPos--;                                 // og staðsetning uppfærð
    }
}

    // Move the current position one step right. No change
    // if already at end.
    // Worst-case time complexity: Constant
void StringList::next()
{
    if(cPos < sise)                             // ef curr kemst aftar
    {                                           // er curr fært aftar
        curr = curr->next;                      // og staðsetning uppfærð
        cPos++;

    }
}

    // Return: The number of elements in the list.
    // Worst-case time complexity: Constant
int StringList::length() const
{
    return sise;               // skilar fjölda hlekkja í listanum (að head og tail utanskyldum)
}

    // Return: The position of the current element.
    // Worst-case time complexity: Constant
int StringList::curr_pos() const
{
    return cPos;                                // skila staðsetningu á curr bendinum
}

    // Set current position.
    // pos: The position to make current.
    // Worst-case time complexity: Linear
    // Throws InvalidPositionException if 'pos' is not a valid position
void StringList::move_to_pos(int pos)
{
    if(pos > sise || pos < 0)
    {                                           // ef pos er utan listans
        throw InvalidPositionException();       // er kastað villu um ólöglega staðsetningu
    }
    else
    {
        while(pos > cPos)                       // ef pos er ofar en staðsetning curr
        {                                       // er færrt curr upp þangað til þeir
            next();                             // eru orðnir jafnir
        }
        while(pos < cPos)                       // ef pos er neðar en staðsetning curr
        {                                       // er fært curr niðurþangað til þeir
            prev();                             // eru orðnir jafnir
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
    {                                           // ef curr er í tail
        throw InvalidPositionException();       // er kastað villu um ólöglega staðsetningu
        return NULL;                            // og engu skilað
    }
    return curr->data;                          // annars er skilað gögnunum úr nóðunni curr bendir á

}

    // Outputs the elements of 'lis' to the stream 'outs', separated
    // by a single space.
ostream& operator <<(ostream& outs, const StringList& lis)
{
    if(lis.sise > 0){                           // ef eithvað er á annaðborð í listanum
        StringNode *ptr;                        // er núr bendir sentur í haus listans
        ptr = lis.head;

        while(ptr->next->next != NULL)          // á meðan hann er tveimur frá tail
        {
            ptr = ptr->next;                    // er hann færður einn áfram
            outs << ptr->data << " ";           // og svo prentað út stakið úr honum með bili á eftir
        }
    }
    return outs;                                // cout á þá að geta prentað það út
}
