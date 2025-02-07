#include <string>
#include <iostream>
#include <ctime>



// void shuffle(int* pArr, int const size)
// {
//     for(int i = size; i > 0;i--)
//     {
//         int swapIndex = rand() % i;
//         int temp = pArr[swapIndex];
//         pArr[swapIndex] = pArr[i-1];
//         pArr[i-1] = temp;
//     }
// }

// void printArray(int* arr, int size)
// {
//     for(int i = 0; i<size; i++)
//     {
//         std::cout << arr[i] << ",";
//     }
//     std::cout << std::endl;
// }

// std::string getDisplayString(char key, int i, int j)
// {
//     std::string returnMe;
//     switch(key)
//     {
//     case '\0':
//     {
//         returnMe = "  X  ";
//         break;
//     }
//     case '<':
//     {
//         returnMe = "a" + std::to_string(i) + "<" + "a" + std::to_string(j);
//         break;
//     }
//     case '>':
//     {
//         returnMe = "a" + std::to_string(i) + ">" + "a" + std::to_string(j);
//         break;
//     }
//     }
//     return returnMe;
// }

// void printGrid (char* grid, int size)
// {
//     for (int i = 0; i < size;i++)
//     {
//         std::cout <<"|";
//         for(int j = 0; j < size; j++)
//         {
            
//             std::cout << getDisplayString(grid[i*size+j],i,j);
//             std::cout << "|";
//         }
//         std::cout << std::endl;
//     }
// }

// void compare(char*grid, int* orderMe,int comparisons)
// {

// }
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
public:
    comparer():comparer(5)
    {
    }
    comparer(int newSize)
    {
        this->size = newSize;
        this->grid = new char[this->size*this->size];
        this->array = new int[this->size];
        for (int i = 0; i < size;i++)//set both arrays states
        {
            array[i] = i;
            for(int j = 0; j < size; j++)
            {
                grid[i*size + j] = '\0';
            }
        }
        this->shuffle();
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
        this->compareInts(this->array[i1], this->array[i2]);
    }


    
};
int main(void)
{
    srand(time(NULL));

    comparer cme;
    cme.printArray();
    cme.printGrid();
    // int const size = 5;
    // char grid [size*size];
    // int orderMe[size];
    // int comparisons;

    // for (int i = 0; i < size;i++)//set both arrays states
    // {
    //     orderMe[i] = i;
    //     for(int j = 0; j < size; j++)
    //     {
    //         grid[i*size + j] = '\0';
    //     }
    // }

    // grid [3*5] = '<';
    // shuffle(orderMe, size);
    // printArray(orderMe, size);
    // printGrid(grid, size);
}