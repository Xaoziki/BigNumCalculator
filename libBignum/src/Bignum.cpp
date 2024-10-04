#include "libBignum/include/Bignum.hpp"

void BigNum::pop(char num)
{
    m_num = num + m_num;
}

std::istream &operator>>(std::istream &input, BigNum &bignum)
{
    input >> bignum.m_num;
    return input;
}

std::ostream &operator<<(std::ostream &output, BigNum &bignum)
{
    output << bignum.m_num;
    return output;
}

BigNum BigNum::operator=(BigNum bignum)
{
    this->m_num = bignum.m_num;
    return *this;
}

BigNum operator+(BigNum bignum_a, BigNum bignum_b)
{
    BigNum result;

    int max_length = std::max(bignum_a.m_num.length(), bignum_b.m_num.length());
    for (int i = bignum_a.m_num.length(); i < max_length; i++)
    {
        bignum_a.pop('0');
    }
    for (int i = bignum_b.m_num.length(); i < max_length; i++)
    {
        bignum_b.pop('0');
    }

    int front = 0;
    for (int i = 0; i < max_length; i++)
    {
        int a = bignum_a.m_num[bignum_a.m_num.length() - i - 1] - '0';
        int b = bignum_b.m_num[bignum_b.m_num.length() - i - 1] - '0';

        if (a + b + front > 9)
        {
            result.pop(a + b - 10 + front + '0');
            front = 1;
        }
        else
        {
            result.pop(a + b + front + '0');
            front = 0;
        }
    }
    
    if (front == 1)
    {
        result.pop('1');
    }

    return result;
}
