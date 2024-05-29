#include <iostream>
#include <bitset>

int main(int ac, char **av)
{
    // &(bitwise AND)
    // | (bitwise OR)
    // ^ (bitwise XOR)
    // << (left shift)
    // >> (right shift)
    // = (assignment)
    {
        if (ac != 3)
        {
            std::cout << "error arg\n";
            return 1;
        }
        std::cout << "##################### a << b #######################" << std::endl;
        int a = std::atoi(av[1]);
        int b = std::atoi(av[2]);
        int c = a << b;
        std::cout << "a = " << a << ", bitset : \t" << std::bitset<16>(a) << std::endl;
        std::cout << "b = " << b << ", bitset : \t" << std::bitset<16>(b) << std::endl;
        std::cout << "c = " << c << ", bitset : \t" << std::bitset<16>(c) << std::endl;
    }
    {
        if (ac != 3)
        {
            std::cout << "error arg\n";
            return 1;
        }
        std::cout << "###################### c = a >> b ######################" << std::endl;
        int a = std::atoi(av[1]);
        int b = std::atoi(av[2]);
        int c = a >> b;
        std::cout << "a = " << a << ", bitset : \t" << std::bitset<16>(a) << std::endl;
        std::cout << "b = " << b << ", bitset : \t" << std::bitset<16>(b) << std::endl;
        std::cout << "c = " << c << ", bitset : \t" << std::bitset<16>(c) << std::endl;
    }
    {
        if (ac != 3)
        {
            std::cout << "error arg\n";
            return 1;
        }
        std::cout << "###################### c = a & b ######################" << std::endl;
        int a = std::atoi(av[1]);
        int b = std::atoi(av[2]);
        int c = a & b;
        std::cout << "a = " << a << ", bitset : \t" << std::bitset<16>(a) << std::endl;
        std::cout << "b = " << b << ", bitset : \t" << std::bitset<16>(b) << std::endl;
        std::cout << "c = " << c << ", bitset : \t" << std::bitset<16>(c) << std::endl;
    }
    {
        if (ac != 3)
        {
            std::cout << "error arg\n";
            return 1;
        }
        std::cout << "######################\t c = a | b ######################" << std::endl;
        int a = std::atoi(av[1]);
        int b = std::atoi(av[2]);
        int c = a | b;
        std::cout << "a = " << a << ", bitset : \t" << std::bitset<16>(a) << std::endl;
        std::cout << "b = " << b << ", bitset : \t" << std::bitset<16>(b) << std::endl;
        std::cout << "c = " << c << ", bitset : \t" << std::bitset<16>(c) << std::endl;
    }
    {
        if (ac != 3)
        {
            std::cout << "error arg\n";
            return 1;
        }
        std::cout << "###################### c = a ^ b ######################" << std::endl;
        int a = std::atoi(av[1]);
        int b = std::atoi(av[2]);
        int c = a ^ b;
        std::cout << "a = " << a << ", bitset : \t" << std::bitset<16>(a) << std::endl;
        std::cout << "b = " << b << ", bitset : \t" << std::bitset<16>(b) << std::endl;
        std::cout << "c = " << c << ", bitset : \t" << std::bitset<16>(c) << std::endl;
    }

    {
        if (ac != 3)
        {
            std::cout << "error arg\n";
            return 1;
        }
        std::cout << "###################### c = a ^ b ######################" << std::endl;
        int a = std::atoi(av[1]);
        int b = std::atoi(av[2]);
        int expectedValue = a + b;
        std::cout << "a = " << a << ", bitset : \t" << std::bitset<16>(a) << std::endl;
        std::cout << "b = " << b << ", bitset : \t" << std::bitset<16>(b) << std::endl;
        while (b)
        {
            int carry = a & b;
            a = b ^ a;
            b = carry << 1;
            std::cout << "carry = " << carry << ", bitset : \t" << std::bitset<16>(carry) << std::endl << std::endl;
            std::cout << "a = " << a << ", bitset : \t" << std::bitset<16>(a) << std::endl;
            std::cout << "b = " << b << ", bitset : \t" << std::bitset<16>(b) << std::endl;
        }
        std::cout << "value : " << expectedValue << ", bitset : \t" << std::bitset<16>(expectedValue) << std::endl;
    }
}