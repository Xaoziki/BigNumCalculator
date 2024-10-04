#include "libBignum/include/Bignum.hpp"

int main()
{
    BigNum a, b;

    std::cin >> a >> b;

    BigNum c;
    c = a + b;

    std::cout << c << std::endl;

    return 0;
}