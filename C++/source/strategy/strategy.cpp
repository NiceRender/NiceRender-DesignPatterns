#include <iostream>
#include <string>
#include <vector>

class SortingAlgorithm
{
    public:    
        virtual ~SortingAlgorithm();
        virtual void sort( std::vector<double>& arr ) = 0;
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
        for (ulong j = 0; j < i; j++)
            if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
}

class ShakerSort : public SortingAlgorithm
{
    public:
        void sort(std::vector<double>& arr);
};

void ShakerSort::sort(std::vector<double>& arr)
{
    ulong n = arr.size();
    for (ulong left_idx = 0, right_idx = n - 1; left_idx < right_idx;)
    {
        for (ulong idx = left_idx; idx < right_idx; idx++)
            if (arr[idx + 1] < arr[idx]) std::swap(arr[idx], arr[idx + 1]);
        right_idx--;
        for (ulong idx = right_idx; idx > left_idx; idx--)
            if (arr[idx - 1] >  arr[idx]) std::swap(arr[idx - 1], arr[idx]);
        left_idx++;
    }
}

class Sorter 
{
    public:
        Sorter( SortingAlgorithm* alg): m_alg(alg) {}
        ~Sorter() { delete m_alg; }
        void sort(std::vector<double>& arr) { m_alg->sort(arr); }
        
    private:
        SortingAlgorithm* m_alg;
};
  
  
int main()
{
    std::vector<double> arr = { 3, 2, 4, 1, 5 };
    
    std::cout << "Original: { ";
    for (auto &el: arr) std::cout << el << " ";
    std::cout << "}\n";
    
    Sorter* sorter = new Sorter(new BubbleSort);
    sorter->sort(arr);
    delete sorter;
    
    std::cout << "Sorted: { ";
    for (auto &el: arr) std::cout << el << " ";
    std::cout << "}\n";
}
