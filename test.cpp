#include "libBignum/include/Bignum.hpp"

int main()
{
    BigNum a, b;
    std::string num_a, num_b;

    std::cin >> num_a >> num_b;
    a.setNum(num_a);
    b.setNum(num_b);

    // a.print();
    // b.print();

    BigNum c;
    c = a + b;

    c.print();

    return 0;
}