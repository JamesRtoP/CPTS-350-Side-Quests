#include <string>
#include <iostream>
#include <ctime>

class comparer
{
private:
    int size;
    char *grid;
    int *array;
    int comparisons;
    void shuffle(void)
    {
        for(int i = size; i > 0;i--)
        {
            int swapIndex = rand() % i;
            int temp = array[swapIndex];
            array[swapIndex] = array[i-1];
            array[i-1] = temp;
        }
    }

    std::string getDisplayString(char key, int i, int j)
    {
        std::string returnMe;
        switch(key)
        {
        case '\0':
        {
            returnMe = "  X  ";
            break;
        }
        case '<':
        {
            returnMe = "a" + std::to_string(i) + "<" + "a" + std::to_string(j);
            break;
        }
        case '>':
        {
            returnMe = "a" + std::to_string(i) + ">" + "a" + std::to_string(j);
            break;
        }
        case '=':
        {
            returnMe = "a" + std::to_string(i) + "=" + "a" + std::to_string(j);
            break;
        }
        }
        return returnMe;
    }

    char compareInts(int num1, int num2)//return the relation char between two ints
    {
        char returnChar = '\0';
        if(num1 > num2)
        {
            returnChar = '>';
        }
        else if (num2 > num1)
        {
            returnChar = '<';
        }
        else
        {
            returnChar = '=';
        }
        return returnChar;
    }

    char flipComparisson(char flipMe)//flips < to > or keeps = as =
    {
        char returnChar = '\0';
        switch(flipMe)
        {
        case('<'):
        {
            returnChar = '>';
            break;
        }
        case('>'):
        {
            returnChar = '<';
            break;
        }
        case('='):
        {
            returnChar = '=';
            break;
        }
        }
        return returnChar;
    }

    void compareOneToAll(int index)
    {
        for(int i = 0; i <this->size; i++)
        {
            if(i!=index)
            {
                this->compareIndex(index, i);
            }
        }
    }
    void setArrays(void)
    {
        for (int i = 0; i < size;i++)//set both arrays states
        {
            array[i] = i;
            for(int j = 0; j < size; j++)
            {
                if(i!=j)
                {
                    grid[i*size + j] = '\0';
                }
                else
                {
                    grid[i*size + j] = '='; 
                }
            }
        }
    }
public:
    
    comparer():comparer(5)
    {
    }
    comparer(int newSize)
    {
        this->size = newSize;
        this->grid = new char[this->size*this->size];
        this->array = new int[this->size];
        this->comparisons = 0;
        this->setArrays();
        this->shuffle();
    }
    ~comparer()
    {
        delete this->grid;
        delete this->array;
    }

    int getComparisons(void)
    {
        return this->comparisons;
    }

    void printArray()
    {
        for(int i = 0; i<this->size; i++)
        {
            std::cout << array[i] << ",";
        }
        std::cout << std::endl;
    }

    void printGrid ()
    {
        for (int i = 0; i < this->size;i++)
        {
            std::cout <<"|";
            for(int j = 0; j < this->size; j++)
            {
                
                std::cout << getDisplayString(this->grid[i*this->size+j],i,j);
                std::cout << "|";
            }
            std::cout << std::endl;
        }
    }

    void compareIndex(int i1, int i2)
    {
        char oneCompareTwo = this->compareInts(this->array[i1], this->array[i2]);
        this->grid[i1*this->size + i2] = oneCompareTwo;
        this->grid[i2*this->size + i1] = this->flipComparisson(oneCompareTwo);
        this->comparisons++;
    }

    bool isFullyCompared(void)
    {
        bool allCompared = true;
        for (int i = 0; i < this->size;i++)
        {
            for(int j = 0; j < this->size; j++)
            {
                if(this->grid[i*this->size+j] == '\0')
                {
                    allCompared = false;
                }
            }
        }
        return allCompared;
    }
    
};
int main(void)
{
    srand(time(NULL));

    comparer cme;
    cme.compareIndex(0,3);
    cme.printArray();
    cme.printGrid();
    std::cout << cme.getComparisons();

}