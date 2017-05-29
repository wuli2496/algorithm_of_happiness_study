#ifndef CHINESETONUM_H
#define CHINESETONUM_H

#include <string>

using namespace std;

class chineseToNum
{
    public:
        chineseToNum();
        virtual ~chineseToNum();
        unsigned int chiToNum(string s);


    protected:

    private:
        class unitValue;

        static const char* numChar[];
        static unitValue values[];


    private:
        int wordToNum(string s);
        unitValue checkUnitValue(string s);

};

#endif // CHINESETONUM_H
