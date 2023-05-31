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
int main()
{
    //Setup
    srand(time(nullptr));
    double time = 0;
    std::chrono::duration<double> time1;
    int n = 1000;
    int *MatrixA = new int [n];
    for (int i = 0; i < n; i++)
        MatrixA[i] = rand();

    //Bubble Sorting
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
    std::cout << "Worst average time for Bubble Sort = " << (time/10) << std::endl;

    //Cleanup
    time = 0;

    //Comb sorting
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
    std::cout << "Worst average time for Comb Sort = " << (time/10);

    delete[] MatrixA;
    return 0;
}