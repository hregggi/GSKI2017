#include <iostream>
#include "StringList.h"

using namespace std;

int main()
{

    cout << "creating list" << endl;
        StringList listi;

        listi.clear();
        listi.insert("stuff");






    cout << "inserting first | " << listi.curr_pos() << " " << listi.length() <<endl;
        listi.insert("first");
    cout << listi << endl;
    cout << "inserting second | " << listi.curr_pos() << " " << listi.length() <<endl;
        listi.insert("second");
    cout << listi << endl;
    cout << "calling next five times | " << listi.curr_pos() << " " << listi.length() <<endl;
        listi.next();
        listi.next();
        listi.next();
        listi.next();
        listi.next();

    string what = "what";
    for(int i = 0; i < 10; i++)
    {
        listi.append(what);
    }
    cout << listi << endl;
    cout << "hreinsa lista | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.clear();
    cout << "prenta tomann lista | "<< listi.curr_pos() << " " << listi.length()<< endl;
    cout << listi << endl;
    listi.insert("ins1");
    listi.append("app1");
    cout << listi << endl;
    listi.insert("ins2");
    listi.append("app2");
    cout << listi << endl;

    listi.clear();
    listi.clear();
    cout << "prenta toman lista | " << listi.curr_pos() << " " << listi.length() << endl;
    cout << listi;
    cout << "baeti fullt af stokum | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.insert("app1");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.append("app2");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.append("app3");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.append("app4");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.insert("ins1");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.insert("ins2");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.insert("ins3");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;
    listi.insert("ins4");
    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;

    cout << listi << " | " << listi.curr_pos() << " " << listi.length() << endl;


    listi.remove();
    listi.remove();
    listi.remove();
    listi.remove();

    StringList thessigaur;
    cout << thessigaur << " bjo hann til | " << thessigaur.curr_pos() << " " << thessigaur.length() << endl;
    thessigaur.move_to_start();
    cout << thessigaur << " move to start | " << thessigaur.curr_pos() << " " << thessigaur.length() << endl;
    thessigaur.clear();
    cout << thessigaur << " cleared | " << thessigaur.curr_pos() << " " << thessigaur.length() << endl;
    thessigaur.insert("lol");
    cout << thessigaur << " inserted | " << thessigaur.curr_pos() << " " << thessigaur.length() << endl;


    return 0;
}
