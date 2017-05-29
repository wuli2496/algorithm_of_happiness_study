#include <iostream>
#include "myAtoi.h"
#include "numToChinese.h"
#include "chineseToNum.h"

using namespace std;

int main()
{
    chineseToNum solver;
    string s;


    while (cin >> s)
    {
        //cout << "myAtoi(" << s << ") = " << solver.myAtoi(s) << endl;
        unsigned int num = solver.chiToNum(s);
        cout << "chiToNum(" << s << ")=" << num << endl;
    }
    return 0;
}
