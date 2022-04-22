#include <iostream>

class BigNum
{
public:
    BigNum() {}

    friend std::istream &operator>>(std::istream &input, BigNum &bignum);
    friend std::ostream &operator<<(std::ostream &output, BigNum &bignum);
    BigNum operator=(BigNum num);
    friend BigNum operator+(const BigNum& bignum_a, const BigNum& bignum_b);

private:
    void pop(char num);

    std::string m_num;
};
