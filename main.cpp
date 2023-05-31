#include <iostream>
#include <chrono>
#include <iomanip>


void BubbleAscending(int *list, int NumberOfElements)
{
    int buffer = 0;
    for (int i = 0; i < NumberOfElements; i++)
        for (int j = i + 1; j < NumberOfElements; j++)
        {
            if (list[j] > list[i])
            {
                buffer = list[j];
                list[j] = list[i];
                list[i] = buffer;
            }
        }
    for (int i = 0; i < NumberOfElements; i++)
    {
        std::cout << std::setw(3) << list[i] << " ";
    }
    std::cout << std::endl;
}
void BubbleDescending(int *list, int NumberOfElements)
{
    int buffer;
    for (int i = 0; i < NumberOfElements; i++)
        for (int j = i + 1; j < NumberOfElements; j++)
        {
            if (list[j] < list[i])
            {
                buffer = list[j];
                list[j] = list[i];
                list[i] = buffer;
            }
        }
    for (int i = 0; i < NumberOfElements; i++)
    {
        std::cout << std::setw(3) << list[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "ua");
    srand(time(nullptr));
    double time = 0;
    std::chrono::duration<double> time1;
    int n = 1000;
    int *MatrixA = new int [n];
    for (int i = 0; i < n; i++)
    {
            MatrixA[i] = rand();
            std::cout << std::setw(3) << MatrixA[i] << " ";
    }
    

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
    std::cout << "Найгірший середній час для бульбашки = " << (time/10);


    delete[] MatrixA;
    return 0;
}