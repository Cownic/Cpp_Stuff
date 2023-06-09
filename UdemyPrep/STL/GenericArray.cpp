#include <iostream>
#include <string>
#include <array>
#include <vector>

template <typename T, int N>
class Array{
    int size{N};
    T values[N];

    friend std::ostream &operator<<(std::ostream &os , const Array<T,N> &arr){
        os << "[";
        for (const auto &ar: arr.values)
        {
            os << ar << " ";
        }
        os << "]" << std::endl;

        return os;
    }

    public:
        Array(){
            for (auto &item:values){
                item = 0;
            }
        };
        Array(T init_val){
            for (auto &item:values){
                item = init_val;
            }
        }
        void fill(T val)
        {
            for (auto &item:values)
            {
                item = val;
            }
        }
        int get_size() const
        {
            return size;
        }

        T &operator[](int index) // to allow me to have easy access to my elements in the array
        {
            return values[index];
        }
};

int main()
{
    std::array<int , 4> arr{};
    Array<int ,5> nums;
    std::cout << "The size of num is " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums[0] = 100;
    std::cout << nums << std::endl;

    Array<double , 20> nums2{1.5};
    std::cout << nums2 << std::endl;
}