#include <iostream>
#include <string>

bool isPalindrome(std::string palindrome)
{
    int i = 0;
    char *p = &(palindrome.front());
    char *q = &(palindrome.back());

    while(*p++ == *q-- && p<q)
    {
        i++;
    }
    return i;
}

void isPalindromeTester(void)
{
    std::string palindrome;
    std::cout << "Enter a string: ";
    std::cin >> palindrome;
    if(isPalindrome(palindrome))
    {
        std::cout << "That is a palindrome" << std::endl;
    }
    else
    {
        std::cout << "That is not a palindrome" << std::endl;
    }
}

int main(void)
{
    isPalindromeTester();
    return 14;
}