#include <string>
#include <iostream>
#include <ctime>


template <typename t>
void shuffleArr(t *array, int size)//fisher-yates shuffle to randomize order of numbers
{//my favorite algorithm
    for(int i = size; i > 0;i--)
    {
        int swapIndex = rand() % i;
        t temp = array[swapIndex];
        array[swapIndex] = array[i-1];
        array[i-1] = temp;
    }
}

struct comparison
{
    int i1;
    int i2;
};

std::ostream& operator<< (std::ostream& stream, const comparison& printME)
{
    std::cout << "(" << printME.i1 << "," << printME.i2 << ")";
    return stream;
}


template <typename t>
void printArr(t* array, int size)
{
    for(int i = 0; i<size; i++)
    {
        std::cout << array[i] << ",";
    }
    std::cout << std::endl;
}

class comparer
{
private:
    int size;//number of numbers being compared
    char *grid;//grid of comparisons that have been done
    int *array;//array of numbers being compared
    int comparisons;//number of comparisons done

//O(n)
    void shuffle(void)//fisher-yates shuffle to randomize order of numbers
    {//my favorite algorithm
        for(int i = size; i > 0;i--)
        {
            int swapIndex = rand() % i;
            int temp = array[swapIndex];
            array[swapIndex] = array[i-1];
            array[i-1] = temp;
        }
    }

//O(1)
    //arguments:
        //input a character from grid that describes the relationship between i and j
        //i and j are both indexes for two number in array
    //returns:
        //a string describing the relationship between i and j
        //for printing grid
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
    //compares two ints and returns the char describing their relationship
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

//O(1)
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

//O(n)
    //set both grid and array to their default state
        //for array it first places the numbers in order and then fisher-yates shuffles them
        //for grid sets all indexes as equal to themselves and the rest to unknowns
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
        this->shuffle();
    }

//O(1)
    //a boolean for whether two indexes have been compared
    bool isUncompared(int i1,int i2)
    {
        bool uncompared = true;
        if(this->grid[i1*this->size + i2] != '\0')
        {
            uncompared=false;
        }
        return uncompared;
    }

    
public:

//O(1)
    //default constructor is simply size 5
    comparer():comparer(5)
    {
    }

//O(1)
    //sets up grid and array for whatever size is specified
    comparer(int newSize)
    {
        this->size = newSize;
        this->grid = new char[this->size*this->size];
        this->array = new int[this->size];
        this->comparisons = 0;
        this->setArrays();
    }

//O(1)
    //free memory from grid and array
    ~comparer()
    {
        delete this->grid;
        delete this->array;
    }

//O(1)
    //returns the number of comparisons done
    int getComparisons(void)
    {
        return this->comparisons;
    }

//O(n)
    void printArray()
    {
        for(int i = 0; i<this->size; i++)
        {
            std::cout << array[i] << ",";
        }
        std::cout << std::endl;
    }

//O(n)
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

//O(n)
    //
    void impliedCompare(int i1,int i2, char oneCompareTwo)
    {
        int i1RowIndex = i1*this->size;//the start index for i1 in grid
        int nextRowIndex = (i1+1)*this->size;//index for the row after i1
        for(int i = 0; i +  i1RowIndex < nextRowIndex; i++)
        {
            if(i != i1 && (grid[i + i1RowIndex] == flipComparisson(oneCompareTwo) || grid[i + i1RowIndex] == '='))
            {//at this point i is the index of an 
                grid[i*this->size + i2] = oneCompareTwo;
                grid[i2*this->size + i] = flipComparisson(oneCompareTwo);
            }
        }
    }

    

//O(1)
    //compares two indexes and sets their relation Into Grid
    void compareIndex(int i1, int i2)
    {
        char oneCompareTwo = this->compareInts(this->array[i1], this->array[i2]);
        this->grid[i1*this->size + i2] = oneCompareTwo;
        this->grid[i2*this->size + i1] = this->flipComparisson(oneCompareTwo);
        this->comparisons++;
        this->impliedCompare(i1,i2,oneCompareTwo);
    }

//O(n)
    //checks if the numbers have been fully compared
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

//O(n)
    //compares one index to all the rest
    void compareOneToAll(int index)
    {
        for(int i = 0; i <this->size; i++)
        {
            if(i!=index && this->isUncompared(index,i))
            {
                this->compareIndex(index, i);
            }
        }
    }

//O(n^2)
    //compares all indexes one at a time to every other index
    void bruteForce(void)//for every number compare it to all other uncompared numbers
    {
        for(int i = 0; i < this->size; i++)
        {
            this->compareOneToAll(i);
        }
    }


//O(n^2)
    //selects 
    void randomForce(void)
    {
        int numberOfOneSidedComparisons = (this->size * (this->size - 1))/2;
        comparison* randomComparisons = new comparison[numberOfOneSidedComparisons];//every possible comparion, doesn't need to go both ways or compare with themselves
        int index = 0;
        for (int i = 0; i < this->size; i++)//one number from this->Array
        {
            for (int j = i+1; j < this->size; j++)//second number from this->array
            {
                randomComparisons[index].i1 = i;
                randomComparisons[index].i2 = j;
                index++;
            }
        }
        shuffleArr(randomComparisons,numberOfOneSidedComparisons);
        for(int i = 0; i < numberOfOneSidedComparisons; i++)
        {
            if(isUncompared(randomComparisons[i].i1,randomComparisons[i].i2))
            {
                this->compareIndex(randomComparisons[i].i1,randomComparisons[i].i2);
            }
        }
        delete randomComparisons;
    }

//O(n)
    //compare two items next to eachother for every item in the list
    //for odd list, last one is not compared
    void comparePairs(void)
    {
        for(int i = 0; i < this->size - 1; i+=2)
        {
            this->compareIndex(i, i + 1);
        }
    }
};



int main(void)
{
    srand(time(NULL));

    comparer cme(5);
    //cme.comparePairs();

    //cme.compareIndex(0,3);
    /*
    cme.printArray();
    cme.printGrid();
    std::cout << cme.getComparisons();
    */
    //cme.compareIndex(1,3);
    //cme.compareIndex(3,4);

    cme.randomForce();
    cme.printArray();
    cme.printGrid();
    std::cout << cme.getComparisons();

}