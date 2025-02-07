#include <cstdlib>
#include <ctime>
#include <iostream>

//template <class t>
class Deck
{
public:
    int deckSize;
    int deck[10];
    Deck(void)
    {
        deckSize = 10;
        for (int i =0; i <deckSize; i++)
        {
            deck[i] = i;
        }
    }
    void FischerYatesShuffle(void)
    {
        for(int i = deckSize; i > 0;i--)
        {
            int swapIndex = rand() % i;
            int temp = this->deck[swapIndex];
            this->deck[swapIndex] = this->deck[i-1];
            this->deck[i-1] = temp;
        }
    }
    void print (void)
    {
        for (int i =0; i <deckSize; i++)
        {
            std::cout << deck[i] << ", ";
        }
    }
    
};

int main(void)
{
    srand(time(NULL));
    Deck testMe;
    testMe.FischerYatesShuffle();
    testMe.print();
    return 14;
}