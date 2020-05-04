#include <iostream>
#include <string>
#include <vector>
#include <memory>

class SortingAlgorithm
{
    public:
        virtual ~SortingAlgorithm();
        virtual void sort(std::vector<double>& arr) = 0;
};

SortingAlgorithm::~SortingAlgorithm() {}

class BubbleSort : public SortingAlgorithm
{
    public:
        void sort(std::vector<double>& arr);
};

void BubbleSort::sort(std::vector<double>& arr)
{
    ulong n = arr.size();
    for (ulong i = n - 1; i > 0; i--)
    {
        for (ulong j = 0; j < i; j++)
            if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
    }
}

class ShakerSort : public SortingAlgorithm
{
    public:
        void sort(std::vector<double>& arr);
};

void ShakerSort::sort(std::vector<double>& arr)
{
    ulong n = arr.size();
    for (ulong leftIdx = 0, rightIdx = n - 1; leftIdx < rightIdx;)
    {
        for (ulong idx = leftIdx; idx < rightIdx; idx++)
            if (arr[idx + 1] < arr[idx]) std::swap(arr[idx], arr[idx + 1]);
        rightIdx--;
        for (ulong idx = rightIdx; idx > leftIdx; idx--)
            if (arr[idx - 1] >  arr[idx]) std::swap(arr[idx - 1], arr[idx]);
        leftIdx++;
    }
}

class Sorter
{
    public:
        void setSorter(std::shared_ptr<SortingAlgorithm> alg) { m_alg = alg; }
        void sort(std::vector<double>& arr) { m_alg->sort(arr); }

    private:
        std::shared_ptr<SortingAlgorithm> m_alg;
};

void printArr(const std::vector<double>& arr, const std::string& str)
{
    std::cout << str << " = { ";
    for (auto &el: arr) std::cout << el << " ";
    std::cout << "}\n";
}

int main()
{
    Sorter sorter;
    std::vector<double> arr1 = { 3.1, 2.2, 4.3, 1.4, 5.5 };
    std::vector<double> arr2 = arr1;

    printArr(arr1, "arr1");
    printArr(arr2, "arr2");

    sorter.setSorter(std::make_shared<BubbleSort>());
    std::cout << "BubbleSort...\n";
    sorter.sort(arr1);
    sorter.setSorter(std::make_shared<ShakerSort>());
    std::cout << "ShakerSort...\n";
    sorter.sort(arr2);
    std::cout << "Done!\n";

    printArr(arr1, "arr1");
    printArr(arr2, "arr2");



}
