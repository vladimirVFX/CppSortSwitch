#include <iostream>
#include <functional>

enum type {less, greater};

template <typename T, type e>
void SortSwitch(T arr[], int n) {   //SortFunction
    int passages = 0;
    std::function<bool(T, T)> predicate;

    switch (e) {
        case greater:
            predicate = [](T x, T y) {return x < y ? true : false; };
        break;
        case less:
            predicate = [](T x, T y) {return x > y ? true : false; };
        break;
    }

    for (int i = 0; i < n - 1; i++) {
        int el = i;
        for (int j = i + 1; j < n; j++) {
            if (predicate(arr[j], arr[el]))
                el = j;
            passages++;
        }
        if (el != i)
            std::swap(arr[i], arr[el]);
        passages++;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << "(" << passages << ")" << std::endl;
}

int main()
{
    {
        int arr[] = { 41,58,32,64,85,73,20 };
        SortSwitch<int, greater>(arr, 7);
    }
    {
        int arr[] = { 35,58,32,45,85,73,827 };
        SortSwitch<int, greater>(arr, 7);
    }
    {
        int arr[] = { 41,58,32,64,85,73,20 };
        SortSwitch<int, less>(arr, 7);
    }
    {
        int arr[] = { 35,58,32,45,85,73,827 };
        SortSwitch<int, less>(arr, 7);
    }

}
