#include "chineseToNum.h"

#include <string>

using namespace std;

class chineseToNum::unitValue
{
public:
    const char *s;
    int unit;
    bool section;
};

const char* chineseToNum::numChar[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
chineseToNum::unitValue chineseToNum::values[] = {{"十", 10, false}, {"百", 100, false}, {"千", 1000, false}, {"万", 10000, true}, {"亿", 100000000, true}};


chineseToNum::chineseToNum()
{
    //ctor
}

chineseToNum::~chineseToNum()
{
    //dtor
}

unsigned int chineseToNum::chiToNum(string s)
{
    unsigned int ans = 0;
    unsigned int section = 0;
    unsigned int number = 0;

    string::size_type len = s.length(), i = 0;

    while (i < len)
    {
        string tmp = s.substr(i, 2);
        int num = wordToNum(tmp);
        if (num >= 0)
        {
            number = num;
            i += 2;
            if (i >= len)
            {
                section += number;
                ans += section;
                break;
            }
        }
        else
        {
            unitValue value = checkUnitValue(tmp);
            if (value.section)
            {
                section = (section + number) * value.unit;
                ans += section;
                section = 0;
            }
            else
            {
                section += (number * value.unit);
            }

            number = 0;
            i += 2;
            if (i >= len)
            {
                ans += section;
                break;
            }
        }

    }

    return ans;
}

int chineseToNum::wordToNum(string s)
{
    int ans = -1;
    int len = sizeof(numChar) / sizeof(numChar[0]);

    for (int i = 0; i < len; i++)
    {
        if (s == numChar[i])
        {
            return i;
        }
    }

    return ans;
}

chineseToNum::unitValue chineseToNum::checkUnitValue(string s)
{
    int len = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < len; i++)
    {
        if (s == values[i].s) return values[i];
    }
}


