#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

template <typename Container, typename Iterator>
void merge(Iterator first, Iterator mid, Iterator last)
{
    Container merged(std::distance(first, last));
    Iterator left = first, right = mid;
    Iterator merged_it = merged.begin();

    while (left != mid && right != last)
    {
        if (*left < *right)
        {
            *merged_it = *left;
            ++left;
        }
        else
        {
            *merged_it = *right;
            ++right;
        }
        ++merged_it;
    }

    while (left != mid)
    {
        *merged_it = *left;
        ++left;
        ++merged_it;
    }

    while (right != last)
    {
        *merged_it = *right;
        ++right;
        ++merged_it;
    }

    std::copy(merged.begin(), merged.end(), first);
}

template <typename Container, typename Iterator>
void insertionSort(Iterator first, Iterator last)
{
    for (Iterator i = first + 1; i != last; ++i)
    {
        int key = *i;
        Iterator j = i - 1;
        while (j >= first && key < *j)
        {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

template <typename Container, typename Iterator>
void fordJohnsonSort(Iterator first, Iterator last)
{
    size_t size = std::distance(first, last);
    if (size < 16)
    {
        insertionSort<Container>(first, last);
    }
    else
    {
        Iterator mid = first + size / 2;

        fordJohnsonSort<Container>(first, mid);
        fordJohnsonSort<Container>(mid, last);

        merge<Container>(first, mid, last);
    }
}

template <typename Container>
void printContainer(const Container &container)
{
    typename Container::const_iterator it;
    for (it = container.begin(); it != container.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
        std::vector<int> vec;
        std::deque<int> dq;
        for (int i = 1; i < argc; ++i)
        {

            int value = strtol(argv[i], NULL, 10);
            if (value < 1)
            {
                std::cerr << "Error: Invalid input value \"" << argv[i] << "\". Only positive integers are allowed." << std::endl;
                exit(EXIT_FAILURE);
            }
            vec.push_back(value);
            dq.push_back(value);
        }
        srand(time(NULL));
        std::cout << "Before: ";
        printContainer(vec);

        clock_t start1 = clock();
        fordJohnsonSort< std::vector<int> >(vec.begin(), vec.end());
        clock_t end1 = clock();
        double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

        clock_t start2 = clock();
        fordJohnsonSort< std::deque<int> >(dq.begin(), dq.end());
        clock_t end2 = clock();
        double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

        std::cout << "After: ";
        printContainer(vec);
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector container: " << time1 << " μs" << std::endl;
        std::cout << "Time to process a range of " << dq.size() << " elements with std::deque container: " << time2 << " μs" << std::endl;
        if (vec == std::vector<int>(dq.begin(), dq.end()))
            std::cout << "The sorted sequences are equal." << std::endl;
        else
            std::cout << "The sorted sequences are not equal." << std::endl;
    }
    else
        std::cerr << "Error: Sequence is not given!" << std::endl;
    return 0;
}
