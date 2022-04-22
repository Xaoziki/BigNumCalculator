#include <iostream>

class BigNum
{
public:
    BigNum() {}
    BigNum(std::string num);

    void setNum(std::string num);
    void print();
    void pop(char num);

    BigNum operator=(BigNum num);
    friend BigNum operator+(const BigNum& bignum_a, const BigNum& bignum_b);

private:
    std::string m_num;
};
