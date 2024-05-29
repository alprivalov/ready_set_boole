#include <iostream>
#include <bitset>

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

int main(int ac, char **av)
{
    {
        if (ac != 3)
        {
            std::cout << "error arg\n";
            return 1;
        }
        int a = std::atoi(av[1]);
        int b = std::atoi(av[2]);
        int result = 0;
        int expectedValue = a * b;
        for (int i = 0; i < 16; i++)
        {
            int valuetargeted = b >> i;
            if ((b >> i) & (1 == 1))
                result = test(result, a);
            a = a << 1;
        }
        std::cout << "value : " << expectedValue << ", bitset : \t" << std::bitset<16>(expectedValue) << std::endl;
        std::cout << "avalue : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
    }
}
