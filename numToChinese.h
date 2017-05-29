#ifndef NUMTOCHINESE_H_INCLUDED
#define NUMTOCHINESE_H_INCLUDED

#include <string>

using namespace std;

class NumToChinese
{
public:
    void numToChinese(unsigned int num, string &str);

private:
    void sectionToChinese(unsigned int section, string& s);

private:
    static const char* sectionUnitChar[] ;
    static const char* chUnitChar[];
    static const char* numChar[];

};

#endif // NUMTOCHINESE_H_INCLUDED
