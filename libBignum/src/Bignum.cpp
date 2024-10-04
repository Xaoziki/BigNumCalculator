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

BigNum operator+(const BigNum& bignum_a, const BigNum& bignum_b)
{
    BigNum num_a = bignum_a;
    BigNum num_b = bignum_b;
    BigNum result;

    int max_length = std::max(num_a.m_num.length(), num_b.m_num.length());
    for (int i = num_a.m_num.length(); i < max_length; i++)
    {
        num_a.pop('0');
    }
    for (int i = num_b.m_num.length(); i < max_length; i++)
    {
        num_b.pop('0');
    }

    // num_a.print();
    // num_b.print();

    int front = 0;
    for (int i = 0; i < max_length; i++)
    {
        int a = num_a.m_num[num_a.m_num.length() - i - 1] - '0';
        int b = num_b.m_num[num_b.m_num.length() - i - 1] - '0';

        // std::cout << i << " " << a << " " << b << std::endl;

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
