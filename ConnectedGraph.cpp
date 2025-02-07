#include <string>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <ctime>
//template <class t>
//class list


int factorial(int factMe)
{
    int total = 1;
    for (; factMe > 0; factMe--)
    {
        total *= factMe;
    }
    return total;
}

int nChoose(int n, int k)//combination
{
    return factorial(n)/(factorial(k)*factorial(n-k));
}

int nChooseTwo(int n) //combination of 2
{
    return nChoose(n,2);
}

int permutation(int n, int k)
{
    return factorial(n)/factorial(n-k);
}

int permutationTwo(int n)
{
    return permutation(n,2);
}


std::string randomGraph(int maxSize)
{
    srand(time(NULL));
    std::string graph = "{";
    if(maxSize > 0)
    {
        int numNodes = rand()%maxSize + 1; 
        for(int i = 0; i<numNodes; i++)
        {
            graph += std::to_string(i) + ", ";
        }
        if(numNodes>1)
        {
            int numEdges = rand()%nChooseTwo(numNodes) + 1;
            for(int i = 0; i<numEdges; i++)
            {
                graph += "<" + std::to_string(rand()%numNodes) + "," + std::to_string(rand()%numNodes) + ">" + ", ";
            }
        }
            graph.pop_back();
            graph.pop_back();
    }
    graph += "}";
    return graph;
}

std::string nodesString(int nodes)
{
    std::string graph;
    for(int i = 0; i<nodes; i++)
    {
        graph += std::to_string(i) + ", ";
    }
    return graph;
}

std::string edgesStringDirectedWithRepeats(int nodes)
{
    std::string graph;
    if(nodes>1)
    {
        int numEdges = rand()%permutationTwo(nodes) + 1;
        for(int i = 0; i<numEdges; i++)
        {
            graph += "<" + std::to_string(rand()%nodes) + "," + std::to_string(rand()%nodes) + ">" + ", ";
        }
    }
    return graph;
}

std::string randomDirectedGraphWithRepeats(int maxSize)
{
    srand(time(NULL));
    std::string graph = "{";
    if(maxSize > 0)
    {
        int numNodes = rand()%maxSize + 1; 
        graph += nodesString(numNodes);
        graph += edgesStringDirectedWithRepeats(numNodes);
        graph.pop_back();
        graph.pop_back();
    }
    graph += "}";
    return graph;
}
int main(void)
{


    std::string graph;
    std::cout << randomDirectedGraphWithRepeats(5) << std::endl;
    //std::cout << randomGraph(1) << std::endl;






}