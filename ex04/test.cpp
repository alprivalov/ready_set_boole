#include <iostream>
#include <bitset>
#include <stack>
#include <cmath>
#include <vector>
#include  <algorithm>
typedef int u32;

int addition(int a, int b)
{
    while (b)
    {
        int carry = a & b;
        a = b ^ a;
        b = carry << 1;
    }
    return a;
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
        else if (str[i] == '1')
            stack.push(true);
        else if (str[i] == '&' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            stack.push(a & b);
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        else if (str[i] == '|' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            stack.push(a | b);
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        else if (str[i] == '^' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            stack.push(a ^ b);
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        else if (str[i] == '>' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            if (a >= b)
                stack.push(true);
            else
                stack.push(false);
            
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        else if (str[i] == '=' && stack.size() >= 2)
        {
            bool a = stack.top();
            stack.pop();
            bool b = stack.top();
            stack.pop();
            if (a == b)
                stack.push(true);
            else
                stack.push(false);
            // std::cout << "result : " << result << ", bitset : \t" << std::bitset<16>(result) << std::endl;
        }
        else if (str[i] == '!' && stack.size() >= 1)
        {
            bool a = !stack.top();
            stack.pop();
            stack.push(a);
        }
    }
    return stack.top();
}

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

void print_Head_Table(std::vector<char> values)
{
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << "| " << values[i];
        std::cout << " ";
    }
    std::cout << "| = |" << std::endl;
    for (int i = 0; i < values.size() + 1; i++)
    {
        std::cout << "|---";
    }
    std::cout << "|" << std::endl;
}

void printTable(std::vector<std::string> table, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << table[i];
    }
}
int getIndex(std::vector<char> values,char c){
    for (int i = 0; i < values.size();i++){
        if (c == values[i])
            return i;
    }
    return 0;
}

std::string stringConvertor(std::string test, std::string &str, int size,std::vector<char> values)
{
    std::string output;
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z'){
            j = getIndex(values, str[i]);
            output += test[j];
        }
        else {
            output += str[i];
        }
    }
    return output;
}

#include <set>

void deleteDuplicate(std::vector<char> &vecObj){
    std::set<int> indices;
    // Iterate over all elements of vector, and store indices
    // of duplicate elements in a set
    for(int i = 0; i < vecObj.size(); i++)
    {
        for(int j = i+1; j < vecObj.size(); j++)
        {
            if (vecObj[i] == vecObj[j])
            {
                indices.insert(j);
            }
        }
    }
    // Iterate over the set of indices in reverse order and
    // delete element at that index in vector
    for (auto rit = indices.rbegin(); rit != indices.rend(); rit++)
    {
        // Remove element at the given index
        vecObj.erase(vecObj.begin() + *rit);
    }
    // print all elements of vector

}
void print_truth_table(std::string &str)
{
    std::vector<std::string> table;
    std::vector<char> values;
    for (int i = str.size(); i >= 0; i--)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            values.push_back(str[i]);
    }
    std::sort(values.begin(),values.end());
    deleteDuplicate(values);
    print_Head_Table(values);
    int size = values.size();
    int nbCalcul = pow(2, size);
    int result = 0;
    for (int i = 0; i < nbCalcul; i++)
    {
        std::string test;
        for (int t = 0; t < size; t++)
        {
            if (result >> (size - t - 1) & 1)
                test += '1';
            else
                test += '0';
        }
        for(int i = 0;i < test.size();i++){
            std::cout << "| " << test[i]<< " ";
        }
            std::cout << "| ";
        

        std::string out(stringConvertor(test, str, size,values));
        
        std::cout << eval_formula(out) << " |" << std::endl;
        result++;
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
        print_truth_table(avOne);
    }
}
