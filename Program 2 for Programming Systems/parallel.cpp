#include "node.h"
#include "parallel.h"

parallel::parallel()
{
    cores = 0;
}

parallel::~parallel()
{
}

//copy constructor
parallel::parallel(const parallel &src)
{

    cores = src.cores;
}

//copies the parallel data members
parallel::parallel(int new_subject, char *new_info, char *new_ds, int new_difficulty, int new_cores, int new_reference) : questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{
    cores = new_cores;
}

//display the contents for parallel
void parallel::display()
{
    std::cout << "For parallel programming" << std::endl;
    std::cout << "The question is: " << info << std::endl;
    std::cout << "The data structure: " << ds << std::endl;
    std::cout << "The difficulty /5 is: " << difficulty << std::endl;
    std::cout << "It has " << cores << " cores" << std::endl;
    std::cout << "The reference number is: " << reference << std::endl;
}

//allows the user to insert the data
void parallel::readin()
{

    std::cout << "The subject is parallel programming" << std::endl;
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

    std::cout << "How many cores does it have" << std::endl;
    std::cin >> cores;
}
