#include <iostream>
#include <bitset>
#include <stack>
#include <cmath>
#include <vector>
typedef int u32;

std::stack<char> tmp;

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

void printStack(std::stack<char> stack)
{
    int stackSize = stack.size();
    if (stackSize)
    {
        char a = stack.top();
        stack.pop();
        printStack(stack);
        std::cout << a;
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
        else{
            std::cerr << "Error nb arg" << std::endl;
            exit(1);
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

void negationBool(std::stack<char> stack)
{
    int stackSize = stack.size();
    if (stackSize)
    {
        char a = stack.top();
        stack.pop();
        negationBool(stack);
        if (a >= 'A' && a <= 'Z')
        {
            tmp.push(a);
            tmp.push('!');
        }
        else
            tmp.push(a);
    }
}

int elementFound;
std::string buffer;


void extractFromStack(std::string &test, std::stack<char> stack)
{

    int size = stack.size();
    if (size > 0)
    {
        char a = stack.top();
        stack.pop();
        extractFromStack(test, stack);
        test += a;
    }
}

void MaterialConditionBool(std::stack<char> stack)
{
    int stackSize = stack.size();
    if (stackSize != 0)
    {
        char a = stack.top();
        stack.pop();
        if (a >= 'A' && a <= 'Z')
            elementFound++;

        MaterialConditionBool(stack);
        if(a >= 'A' && a <= 'Z')
            elementFound--;
        if (a >= 'A' && a <= 'Z' && elementFound == 1)
        {
            tmp.push(a);
            tmp.push('!');
        }
        else if (a >= 'A' && a <= 'Z' && elementFound == 0)
        {
            tmp.push(a);
            tmp.push('|');
        }
        else
            tmp.push(a);
    }
}

void cancelNegation(std::stack<char> stack)
{
    int size = stack.size();
    if (size > 0)
    {
        char a = stack.top();
        stack.pop();
        cancelNegation(stack);
        buffer += a;
    }
}

std::stack<char> clearedStack()
{
    std::stack<char> tmp;

    std::string toFind = "!!";
    size_t found = buffer.find(toFind);

    while (found != std::string::npos)
    {
        buffer.erase(found, toFind.length());
        found = buffer.find(toFind);
    }

    for (int i = 0; i < buffer.size(); i++)
    {
        tmp.push(buffer[i]);
    }
    return tmp;
}

std::stack<char> negation_normal_form(std::string &str)
{
    bool result;
    std::stack<char> stack;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            stack.push(str[i]);
        }
        else if (str[i] == '&')
        {
            stack.push('|');
        }
        else if (str[i] == '|')
        {
            stack.push('&');
        }
        else if (str[i] == '>')
        {
            elementFound = 0;
            std::stack<char> newStack;
            tmp = newStack;
            MaterialConditionBool(stack);
            stack = tmp;
        }
        else if (str[i] == '=')
        {
        }
        else if (str[i] == '!' && stack.size() >= 1)
        {
            std::stack<char> newStack;
            tmp = newStack;
            negationBool(stack);
            stack = tmp;
        }
        buffer.clear();
        cancelNegation(stack);
        stack = clearedStack();
    }
    return stack;
}

int main(int ac, char **av)
{
    {

        std::string Entry("AB|C&!");
        std::string result("A!B!&C!|");
        std::string out;
        std::stack<char> test = negation_normal_form(Entry);
        printStack(test);
    std::cout << std::endl;

        extractFromStack(out, test);
        print_truth_table(out);
        std::cout << std::endl;
        print_truth_table(result);
    }
}