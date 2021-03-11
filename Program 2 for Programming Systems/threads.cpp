#include "node.h"
#include "threads.h"

threads::threads()
{
    tc = 0;
}

threads::~threads()
{
}

threads::threads(int new_subject, char *new_info, char *new_ds, int new_difficulty, int new_reference, int new_tc) : questions(new_subject, new_info, new_ds, new_difficulty, new_reference)
{
    tc = new_tc;
}

threads::threads(const threads &src)
{

    tc = src.tc;
}

void threads::display()
{
    std::cout << "For threads" << std::endl;
    std::cout << "The question is: " << info << std::endl;
    std::cout << "The data structure: " << ds << std::endl;
    std::cout << "The difficulty /5 is: " << difficulty << std::endl;
    std::cout << "The thread count is: " << std::endl;
    std::cout << "The reference number is: " << reference << std::endl;
}

void threads::readin()
{
    std::cout << "The subject is threads" << std::endl;

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

    std::cout << "How many threads does it have?" << std::endl;
    std::cin >> tc;
    std::cin.ignore();
}
