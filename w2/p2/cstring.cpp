
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include "cstring.h"

using namespace std;
namespace sdds
{
    cstring cs;
    char* cstring::strCpy(char* des, const char* src)
    {
        int i;
        for (i = 0; src[i]; i++)
        {
            des[i] = src[i];
        }
        des[i] = char(0);
        return des;
    }

    char* cstring::strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        while (i < len - 1 && src[i])
        {
            des[i] = src[i];
            i++;
        }
        des[i] = src[i];

        return des;
    }

    int cstring::strCmp(const char* s1, const char* s2)
    {
        int i;
        for (i = 0; i < s1[i] && s2[i] && s1[i] == s2[i]; i++) // find the s1 and s2 length
        {
            ;
        }
        return s1[i] - s2[i]; // s1-s2= 0, s1-s2 >0 reture >0 , s1 -s2 < 0 return <0
    }

    int cstring::strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i])
        {
            i++; /* code */
        }

        return s1[i] - s2[i];
    }

    int cstring::strLen(const char* s)
    {
        if (!s)
        {
            return 0;
        }

        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }
        return i;
    }

    const char* cstring::strStr(const char* str1, const char* str2)
    {
        const char* address = nullptr;
        if (*str2 == '\0')
        {
            address = str1; // find empty string2, return string1 as a match
        }
        while (*str1 != '\0')
        {
            const char* p1 = str1;
            const char* p2 = str2;
            while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
            {
                p1++;
                p2++;
            }
            if (*p2 == '\0')
            {
                address = str1; // Match found
            }

            str1++;
        }
        return address; // No match found
    }

    char* cstring::strCat(char* des, const char* src)
    {
        int len = cs.strLen(des);
        int i = 0;
        while (src[i]) {
            des[i + len] = src[i];
            i++;
        }
        des[i + len] = char(0);
        return des;
    }
    char* cstring::getDynStr(std::istream& is)
    {
        char* m_str{};
        std::string stri;
        if (getline(is, stri))
        {
            cs.cpyConstr(m_str, stri.c_str());
        }
        return m_str;
    }

    void cstring::cpyConstr(char*& des, const char* src)
    {
        
        if (src && src[0])
        {
            des = new char[strlen(src) + 1];
            strcpy(des, src);
        }

    }


    void cstring::aloMey(char*& des, const char* src)
    {
        des = nullptr;
        if (src)
        {
            des = new char[strlen(src) + 1];
            des = nullptr;
        }

    }
}