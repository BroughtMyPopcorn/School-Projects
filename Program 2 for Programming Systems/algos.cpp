#include "node.h"
#include "algos.h"

algos::algos()
{
    bigO = NULL;
}

algos::~algos()
{
    if (bigO)
        delete[] bigO;
}

algos::algos(int new_subject, char *new_info, char *new_ds, int new_difficulty, char *new_bigO, int new_reference) : questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{

    bigO = new char[strlen(new_bigO) + 1];
    strcpy(bigO, new_bigO);
}

algos::algos(const algos &src)
{
    bigO = new char[strlen(src.bigO) + 1];
    strcpy(bigO, src.bigO);
}

void algos::display()
{
    std::cout << "For algorithms" << std::endl;
    std::cout << "The question is: " << info << std::endl;
    std::cout << "The data structure: " << ds << std::endl;
    std::cout << "The difficulty /5 is: " << difficulty << std::endl;
    std::cout << "The big O is" << bigO << std::endl;
    std::cout << "The reference number is: " << reference << std::endl;
}

void algos::readin()
{

    std::cout << "The subject is algorithms" << std::endl;
    std::cout << "Enter a number to associate the question with" << std::endl;
    std::cin >> reference;
    std::cin.ignore();

    std::cout << "Enter the question" << std::endl;
    info = new char[1000];
    std::cin.get(info, 1000, '\n');
    std::cin.ignore(1000, '\n');

    std::cout << "Enter the data structure that would work the best" << std::endl;
    ds = new char[1000];
    std::cin.get(ds, 1000, '\n');
    std::cin.ignore(1000, '\n');

    std::cout << "Enter in the diffculty out of 5" << std::endl;
    std::cin >> difficulty;
    std::cin.ignore();

    std::cout << "What is the bigO for this algo?" << std::endl;
    bigO = new char[1000];
    std::cin.get(bigO, 1000, '\n');
    std::cin.ignore(1000, '\n');
}
