#ifndef MYATOI_H_INCLUDED
#define MYATOI_H_INCLUDED

#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int ans = 0;
        bool sign = true;
        size_t i;
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ') break;
        }

        if (i < s.length())
        {
            if (s[i] == '+') sign = true, i++;
            else if (s[i] == '-') sign = false, i++;
        }

        for (; i < s.length(); i++)
        {
            int num = s[i] - '0';
            if (sign)
            {
                if ((INT_MAX - num) / 10 > ans)
                {
                    ans = ans * 10 + num;
                }
                else
                {
                    return INT_MAX;
                }
            }
            else
            {
                if ((INT_MIN + num) / 10 > -ans)
                {
                    return INT_MIN;
                }
                else
                {
                    ans = ans * 10 + num;
                }
            }

        }

        return ans * (sign ? 1 : -1);
    }
};

#endif // MYATOI_H_INCLUDED
