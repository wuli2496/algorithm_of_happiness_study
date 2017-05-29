#include "numToChinese.h"

const char* NumToChinese::sectionUnitChar[] = {"", "万", "亿", "万亿"};
const char* NumToChinese::chUnitChar[] = {"", "十", "百", "千"};
const char* NumToChinese::numChar[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};

void NumToChinese::numToChinese(unsigned int num, string& str)
{
    int pos = 0;
    string s;
    bool needZero = false;

    if (num == 0)
    {
        str = numChar[0];
    }

    while (num > 0)
    {
        unsigned int section = num % 10000;
        if (needZero)
        {
            str.insert(0, numChar[0]);
        }
        s = "";
        sectionToChinese(section, s);
        s += (section != 0) ? sectionUnitChar[pos] : sectionUnitChar[0];
        str.insert(0, s);

        needZero = (section > 0 && section < 1000);
        num /= 10000;
        pos++;
    }
}

void NumToChinese::sectionToChinese(unsigned int section, string& s)
{
    bool zero = true;
    int pos = 0;
    string tmp;

    while (section > 0)
    {
        int num = section % 10;

        if (num != 0)
        {
            zero = false;
            tmp = numChar[num];
            tmp += chUnitChar[pos];
            s.insert(0, tmp);
        }
        else
        {
            if (!zero)
            {
                zero = true;
                s.insert(0, numChar[0]);
            }
        }
        section /= 10;
        pos++;
    }
}

