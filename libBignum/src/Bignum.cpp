#include "libBignum/include/Bignum.hpp"

BigNum::BigNum(std::string num)
{
    setNum(num);
}

void BigNum::setNum(std::string num)
{
    m_num = num;
}

void BigNum::print()
{
    std::cout << m_num << std::endl;
}

void BigNum::pop(char num)
{
    m_num = num + m_num;
}

BigNum BigNum::operator=(BigNum bignum)
{
    m_num = bignum.m_num;
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
