#include <iostream>
#include "StringList.h"

using namespace std;

int main()
{
    StringList listi;

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    listi.append("first");

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    listi.append("second");

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    listi.append("third");

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;


    listi.insert("fourth");

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    listi.insert("fifth");

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    listi.insert("sixth");

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    cout << listi << endl;

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

  //  listi.next();

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    //listi.next();

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    //listi.prev();

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    cout << listi.remove() << endl;

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;

    cout << listi << endl;

        cout<< "pos >" << listi.curr_pos() << " .len >" << listi.length() << endl;



    return 0;
}
