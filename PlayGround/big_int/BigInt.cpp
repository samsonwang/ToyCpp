
#include "BigInt.h"

BigInt::BigInt(int val)
{
    m_bPositive = val >= 0;

    m_nDigitCount = 0;
    int temp1 = val;
    do
    {
        m_nDigitCount += 1;
        temp1 = temp1 / 10;
    } while (temp1);

    m_pContent = new unsigned char[m_nDigitCount];

    int temp2 = val;

    for (unsigned i = 0; i < m_nDigitCount; ++i)
    {
        m_pContent[i] = temp2 % 10;
        temp2 = temp2 / 10;
    }
}

BigInt::BigInt(const string& text)
{
    m_bPositive = true;
    m_nDigitCount = 0;
    m_pContent = nullptr;

    unsigned nTextLen = (unsigned)text.length();
    if (nTextLen == 0)
    {
        return;
    }

    char chSign = text.front();
    switch (chSign)
    {
    case '-':
        m_bPositive = false;
        m_nDigitCount = nTextLen - 1;
        break;
    case '+':
        m_bPositive = true;
        m_nDigitCount = nTextLen - 1;
        break;
    default:
        m_bPositive = true;
        m_nDigitCount = nTextLen;
        break;
    }

    m_pContent = new unsigned char[m_nDigitCount];

    for (unsigned i = 0; i < m_nDigitCount; ++i)
    {
        m_pContent[i] = text[nTextLen - i - 1] - '0';
    }
}

BigInt::BigInt(const BigInt& copy)
{
    m_bPositive = copy.m_bPositive;
    m_nDigitCount = copy.m_nDigitCount;
    m_pContent = new unsigned char[copy.m_nDigitCount];

    for (unsigned i = 0; i < m_nDigitCount; ++i)
    {
        m_pContent[i] = copy.m_pContent[i];
    }
}

BigInt BigInt::operator+(const BigInt& val) const
{
    BigInt objResult(0);

    if (m_bPositive == val.m_bPositive)
    {
        // m_bPositive
        unsigned nResultSpace = m_nDigitCount > val.m_nDigitCount
            ? m_nDigitCount + 1 : val.m_nDigitCount + 1;

        unsigned char* pContent = new unsigned char[nResultSpace];

        int nCarry = 0;
        int nDigitCount = 0;
        for (unsigned i = 0; i < nResultSpace; ++i)
        {
            int n1 = i < m_nDigitCount ? m_pContent[i] : 0;
            int n2 = i < val.m_nDigitCount ? val.m_pContent[i] : 0;

            int nTemp = n1 + n2 + nCarry;

            if (nTemp >= 10)
            {
                pContent[i] = nTemp - 10;
                nCarry = 1;
            }
            else
            {
                pContent[i] = nTemp;
                nCarry = 0;
            }
        }

        objResult.m_bPositive = m_bPositive;

        for (unsigned i = 0; i < nResultSpace; ++i)
        {
            if (pContent[nResultSpace - i - 1] != 0)
            {
                objResult.m_nDigitCount = nResultSpace - i;
                break;
            }
        }

        if (objResult.m_pContent)
        {
            delete[] objResult.m_pContent;
        }
        objResult.m_pContent = pContent;
    }
    else
    {
        bool bSmaller = true;

        if (m_bPositive)
        {
            BigInt objTemp(val);
            objTemp.m_bPositive = true;
            bSmaller = *this < objTemp;
        }
        else
        {
            BigInt objTemp(*this);
            objTemp.m_bPositive = true;
            bSmaller = objTemp < val;
        }

        unsigned nResultSpace = 0;

        if (bSmaller)
        {
            objResult.m_bPositive = val.m_bPositive;
            nResultSpace = val.m_nDigitCount;
        }
        else
        {
            objResult.m_bPositive = m_bPositive;
            nResultSpace = m_nDigitCount;
        }

        unsigned char* pContent = new unsigned char[nResultSpace];
        for (unsigned i = 0; i < nResultSpace; ++i)
        {
            pContent[i] = 0;
        }

        int nBorrow = 0;

        for (unsigned i = 0; i < nResultSpace; ++i)
        {
            int n1 = i < m_nDigitCount ? m_pContent[i] : 0;
            int n2 = i < val.m_nDigitCount ? val.m_pContent[i] : 0;

            int nTemp = 0;

            if (bSmaller)
            {
                nTemp = n2 - n1 - nBorrow;
            }
            else
            {
                nTemp = n1 - n2 - nBorrow;
            }

            if (nTemp >= 0)
            {
                pContent[i] = nTemp;
                nBorrow = 0;
            }
            else
            {
                pContent[i] = 10 + nTemp;
                nBorrow = 1;
            }
        }

        for (unsigned i = 0; i < nResultSpace; ++i)
        {
            if (pContent[nResultSpace - i - 1] != 0)
            {
                objResult.m_nDigitCount = nResultSpace - i;
                break;
            }
        }

        if (objResult.m_pContent)
        {
            delete[] objResult.m_pContent;
        }

        objResult.m_pContent = pContent;
    }

    return objResult;
}

BigInt BigInt::operator+(int val) const
{
    return *this + BigInt(val);
}

BigInt BigInt::operator-(const BigInt& val) const
{
    BigInt obj(val);
    obj.m_bPositive = !obj.m_bPositive;
    return *this + obj;
}

BigInt BigInt::operator-(int val) const
{
    return *this - BigInt(val);
}

BigInt BigInt::operator*(const BigInt& val) const
{
    BigInt objResult;
    objResult.m_bPositive = !(m_bPositive ^ val.m_bPositive);

    unsigned nResultSpace = m_nDigitCount + val.m_nDigitCount;

    unsigned char* pContent = new unsigned char[nResultSpace];
    for (unsigned i = 0; i < nResultSpace; ++i)
    {
        pContent[i] = 0;
    }

    for (unsigned i = 0; i < m_nDigitCount; ++i)
    {
        int n1 = i < m_nDigitCount ? m_pContent[i] : 0;

        // int nCarry = 0;

        for (unsigned j = 0; j < val.m_nDigitCount; ++j)
        {
            int n2 = j < val.m_nDigitCount ? val.m_pContent[j] : 0;

            int nTemp1 = n1 * n2;
            int nTemp2 = pContent[j + i];

            pContent[j + i] = (nTemp1 + nTemp2) % 10;
            pContent[j + i + 1] += (nTemp1 + nTemp2) / 10;
        }
    }

    for (unsigned i = 0; i < nResultSpace; ++i)
    {
        if (pContent[nResultSpace - i - 1] != 0)
        {
            objResult.m_nDigitCount = nResultSpace - i;
            break;
        }
    }

    if (objResult.m_pContent)
    {
        delete[] objResult.m_pContent;
    }

    objResult.m_pContent = pContent;

    return objResult;
}

BigInt BigInt::operator*=(const BigInt& rhs)
{
    *this = *this * rhs;
    return *this;
}

bool BigInt::operator<(const BigInt& val) const
{
    if (m_bPositive && val.m_bPositive)
    {
        if (m_nDigitCount != val.m_nDigitCount)
        {
            return m_nDigitCount < val.m_nDigitCount;
        }
        else
        {
            for (unsigned i = 0; i < m_nDigitCount; ++i)
            {
                if (m_pContent[m_nDigitCount - i] < val.m_pContent[m_nDigitCount - 1])
                {
                    return true;
                }
            }

            return false;
        }
    }
    else if (!m_bPositive && !val.m_bPositive)
    {
        if (m_nDigitCount != val.m_nDigitCount)
        {
            return m_nDigitCount > val.m_nDigitCount;
        }
        else
        {
            for (unsigned i = 0; i < m_nDigitCount; ++i)
            {
                if (m_pContent[m_nDigitCount - i] > val.m_pContent[m_nDigitCount - 1])
                {
                    return true;
                }
            }

            return false;
        }
    }
    else if (m_bPositive && !val.m_bPositive)
    {
        return false;
    }
    else if (!m_bPositive && val.m_bPositive)
    {
        return true;
    }

    return true;
}

bool BigInt::operator<=(const BigInt& val) const
{
    return *this < val || *this == val;
}

bool BigInt::operator>(const BigInt& val) const
{
    return val < *this;
}

bool BigInt::operator>=(const BigInt& val) const
{
    return *this > val || *this == val;
}

BigInt& BigInt::operator++()
{
    *this += 1;
    return *this;
}

BigInt BigInt::operator++(int)
{
    BigInt old = *this;
    *this += 1;
    return old;
}

BigInt& BigInt::operator--()
{
    *this -= 1;
    return *this;
}

BigInt BigInt::operator--(int)
{
    BigInt old = *this;
    *this -= 1;
    return *this;
}

BigInt::operator string()
{
    return toString();
}

BigInt::operator int()
{
    return 0;
}

string BigInt::toString() const
{
    string strResult;

    if (m_bPositive == false)
    {
        strResult.push_back('-');
    }

    for (unsigned i = 0; i < m_nDigitCount; ++i)
    {
        strResult.push_back(m_pContent[m_nDigitCount - i - 1] + '0');
    }

    return strResult;
}

BigInt& BigInt::operator=(const BigInt& val)
{
    m_bPositive = val.m_bPositive;
    m_nDigitCount = val.m_nDigitCount;

    if (m_pContent)
    {
        delete[] m_pContent;
    }

    m_pContent = new unsigned char[val.m_nDigitCount];

    for (unsigned i = 0; i < m_nDigitCount; ++i)
    {
        m_pContent[i] = val.m_pContent[i];
    }

    return *this;
}

BigInt::~BigInt()
{
     if (m_pContent)
     {
         delete[] m_pContent;
         m_pContent = nullptr;
     }
}

bool BigInt::operator!=(const BigInt& val) const
{
    return !(*this == val);
}

bool BigInt::operator==(const char* val) const
{
    return *this == BigInt(val);
}

bool BigInt::operator==(const BigInt& val) const
{
    if (m_bPositive != val.m_bPositive)
    {
        return false;
    }
    else if (m_nDigitCount != val.m_nDigitCount)
    {
        return false;
    }
    else
    {
        for (unsigned i = 0; i < m_nDigitCount; ++i)
        {
            if (m_pContent[i] != val.m_pContent[i])
            {
                return false;
            }
        }
    }

    return true;
}

BigInt BigInt::operator-=(const BigInt& rhs)
{
    *this = *this - rhs;
    return *this;
}

BigInt BigInt::operator+=(const BigInt& rhs)
{
    *this = *this + rhs;
    return *this;
}

ostream& operator<<(ostream& output, const BigInt& val)
{
    output << val.toString();
    return output;
}

istream& operator>>(istream& input, BigInt& val)
{
    std::string str;
    input >> str;

    val = BigInt(str);
    return input;
}
