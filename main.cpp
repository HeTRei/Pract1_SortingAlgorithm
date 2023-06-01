#include <iostream>
#include <chrono>

void BubbleAscending(int *list, int NumberOfElements)
{
    for (int i = 0; i < NumberOfElements; i++)
        for (int j = i + 1; j < NumberOfElements; j++)
        {
            if (list[j] < list[i])
            {
                std::swap(list[j], list[i]);
            }
        }
}
void BubbleDescending(int *list, int NumberOfElements)
{
    for (int i = 0; i < NumberOfElements; i++)
        for (int j = i + 1; j < NumberOfElements; j++)
        {
            if (list[j] > list[i])
            {
                std::swap(list[j], list[i]);
            }
        }
}
void CombAscending(int *list, int NumberOfElements)
{
    int gap = NumberOfElements;
    double shrink = 1.3;
    bool swapped = true;
    while (gap != 1 || !swapped)
    {
        gap = gap/shrink;
        swapped = false;
        for (int i = 0; i < NumberOfElements - gap; i++)
            if (list[i] > list[i + gap])
            {
                std::swap(list[i], list[i + gap]);
                swapped = true;
            }
    }
}
void CombDescending(int *list, int NumberOfElements)
{
    int gap = NumberOfElements;
    double shrink = 1.3;
    bool swapped = true;
    while (gap != 1 || !swapped)
    {
        gap = gap/shrink;
        swapped = false;
        for (int i = 0; i < NumberOfElements - gap; i++)
            if (list[i] < list[i + gap])
            {
                std::swap(list[i], list[i + gap]);
                swapped = true;
            }
    }
}
void LinearSearch(const long long *list, const long long NumberOfElements, long long ValueToFind)
{
    for (long long i = 0; i < NumberOfElements; i++)
        if (list[i] == ValueToFind)
            return;
}
void BinarySearch(const long long *list, const long long NumberOfElements, long long ValueToFind)
{
    long long MinIndex = 0;
    long long MaxIndex = (NumberOfElements) - 1;
    while (MinIndex < MaxIndex)
    {
        long long MidIndex = MinIndex + (MaxIndex - MinIndex)/2;
        if (list[MidIndex] == ValueToFind)
            return;
        else if (list[MidIndex] < ValueToFind)
            MinIndex = MidIndex + 1;
        else
            MaxIndex = MidIndex - 1;
    }


}

int main()
{
    //Setup
    srand(time(nullptr));
    double time = 0;
    std::chrono::duration<double> time1;

    //Sorting
    int n = 1000;
    int *MatrixA = new int [n];
    for (int i = 0; i < n; i++)
        MatrixA[i] = rand();

    //Bubble Sort
    for (int i = 0; i < 10; i++)
    {
        if (i%2==0)
        {
            auto start1 = std::chrono::steady_clock::now();
            BubbleAscending(MatrixA, n);
            auto end1 = std::chrono::steady_clock::now();
            time1 = end1 - start1;
            time+=time1.count();
        }
        else
        {
            auto start1 = std::chrono::steady_clock::now();
            BubbleDescending(MatrixA, n);
            auto end1 = std::chrono::steady_clock::now();
            time1 = end1 - start1;
            time+=time1.count();
        }

    }
    std::cout << "Worst average time for Bubble sort = " << (time/10) << std::endl;
    time = 0;

    //Comb sort
    for (int i = 0; i < 10; i++)
    {
        if (i%2==0)
        {
            auto start1 = std::chrono::steady_clock::now();
            CombAscending(MatrixA, n);
            auto end1 = std::chrono::steady_clock::now();
            time1 = end1 - start1;
            time+=time1.count();
        }
        else
        {
            auto start1 = std::chrono::steady_clock::now();
            CombDescending(MatrixA, n);
            auto end1 = std::chrono::steady_clock::now();
            time1 = end1 - start1;
            time+=time1.count();
        }

    }
    std::cout << "Worst average time for Comb sort = " << (time/10) << std::endl;
    time = 0;

    //Search
    auto* D = new long long[1000000];;
    for (long long i = 0; i < 1000000; i++)
        D[i] = i+1;
    long long ValueToFind = 387235;

    //Linear search
    for (int i = 0; i < 10; i++)
    {
        auto start1 = std::chrono::steady_clock::now();
        LinearSearch(D, 1000000, ValueToFind);
        auto end1 = std::chrono::steady_clock::now();
        time1 = end1 - start1;
        time += time1.count();
    }
    std::cout << "Worst average time for Linear search = " << (time/10) << std::endl;
    time = 0;

    //Binary search
    for (int i = 0; i < 10; i++)
    {
        auto start1 = std::chrono::steady_clock::now();
        BinarySearch(D, 1000000, ValueToFind);
        auto end1 = std::chrono::steady_clock::now();
        time1 = end1 - start1;
        time += time1.count();
    }
    std::cout << "Worst average time for Binary search = " << (time/10);

    delete[] MatrixA;
    delete[] D;
    return 0;
}