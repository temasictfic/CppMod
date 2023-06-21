#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>


template <typename T>
void display(const T& container)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void mergeInsertSort(const T& container)
{
    typename T::iterator it1, it2;
    for (it1 = container.begin() + 1; it1 != container.end(); ++it1)
    {
        int temp = *it1;
        it2 = it1;
        while (it2 != container.begin() && *(std::prev(it2)) > temp)
        {
            *it2 = *(std::prev(it2));
            std::advance(it2, -1);
        }
        *it2 = temp;
    }
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        std::vector<int> vec;
        std::list<int> list;
        for (int i = 1; i < argc; ++i)
        {
            
            int value = strtol(argv[i], NULL, 10);
            if (value < 1)
            {
                std::cerr << "Error: Invalid input value \"" << argv[i] << "\". Only positive integers are allowed." << std::endl;
                exit(1);
            }
            vec.push_back(value);
            list.push_back(value);
        }
        srand(time(NULL));
        std::cout << "Before: ";
        display(vec);

        clock_t start1 = clock();
        mergeInsertSort(vec);
        clock_t end1 = clock();
        double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

        clock_t start2 = clock();
        mergeInsertSort(list);
        clock_t end2 = clock();
        double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

        std::cout << "After: ";
        display(vec);
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector container: " << time1 << " us" << std::endl;
        std::cout << "Time to process a range of " << list.size() << " elements with std::list container: " << time2 << " us" << std::endl;
        if (vec == std::vector<int>(vec.begin(), vec.end()))
            std::cout << "The sorted sequences are equal." << std::endl;
        else
            std::cout << "The sorted sequences are not equal." << std::endl;

    }
    else
        std::cerr << "Error: Sequence is not given!" << std::endl;
    return 0;

}
   

