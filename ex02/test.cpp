#include <iostream>
#include <bitset>

typedef int u32;

int test(int a, int b)
{
    while (b)
    {
        int carry = a & b;
        a = b ^ a;
        b = carry << 1;
    }
    return a;
}

u32 graycode(u32 n)
{
    std::cout << "n : " << n << ", bitset : \t" << std::bitset<16>(n) << std::endl;
    u32 test = (n >> 1);
    std::cout << "test : " << test << ", bitset : \t" << std::bitset<16>(test) << std::endl;
    u32 return_value = n ^ (n >> 1);
    std::cout << "return : " << return_value << ", bitset : \t" << std::bitset<16>(return_value) << std::endl;
    return return_value;
}

int main(int ac, char **av)
{
    {
        if (ac != 2)
        {
            std::cout << "error arg\n";
            return 1;
        }
        u32 a = std::atoi(av[1]);
        std::cout << graycode(a) << std::endl;
    }
}
