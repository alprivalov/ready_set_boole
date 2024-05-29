#include <iostream>
#include <bitset>
#include <stack>
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

void printStack(std::stack<bool> stack)
{
    int size = stack.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << stack.top() << ", i = " << i << std::endl;
        stack.pop();
    }
}

bool eval_formula(std::string &str)
{
    bool result;
    std::stack<bool> stack;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            stack.push(false);
        if (str[i] == '1')
            stack.push(true);
        if (str[i] == '&' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            result = a & b;
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        if (str[i] == '|' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            result = a | b;
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        if (str[i] == '^' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            result = a ^ b;
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        if (str[i] == '>' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            if (a >= b)
                result = true;
            else
                result = false;
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        if (str[i] == '=' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            if (a == b)
                result = true;
            else
                result = false;
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        if (str[i] == '!' && stack.size() >= 2)
        {
            result = !result;
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
    }
    if (stack.size() == 0)
        return result;
    else
    {
        std::cerr << "error wrong nb arg" << std::endl; 
        return false;
    }
}
int main(int ac, char **av)
{
    {
        if (ac != 2)
        {
            std::cout << "error arg\n";
            return 1;
        }
        std::string avOne(av[1]);
        std::cout << "eval_formula : " << eval_formula(avOne) << std::endl;
    }
}
