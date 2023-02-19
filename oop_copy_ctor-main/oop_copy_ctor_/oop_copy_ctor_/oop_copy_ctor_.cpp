#include <iostream>
#include <array>
#include <ctime>
using namespace std;

class Array {
private:
    long* arr;
    int size;

    void Copy(const Array& other)
    {
        this->size = other.size;
        this->arr = new long[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

public:
    Array(long* arr, int size) : arr(nullptr), size(size) {
        this->arr = arr;
        this->size = size;
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
    }
    
    void fillZero() {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    void Show() {
        cout << "\n\t---Array---\n\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void fillRnd() {
        srand(unsigned(time(0)));
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }

    void addNewElem(long elem) {

        long* temp = new long[size+ 1];

        for (size_t i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = elem;

        delete[] arr;
        arr = temp;

        ++size;
    }

    void delElem(long ind) {


        long* temp = new long[size - 1];

        for (size_t i = 0; i < size; i++)
        {
            if (i < ind) {
                temp[i] = arr[i];
            }
            if (i > ind) {
                temp[i - 1] = arr[i];
            }
        }
        delete[] arr;
        arr = temp;
        --size;
    }

    void sortArr() {

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < (size-1);j++) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }

    }

    void minVal() {
        long min = LONG_MAX;

        for (int i = 0; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        
        cout << "\nMin value in array = " << min << endl;
    }

    void Clear()
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
    }

};

int main()
{
    const int SIZE = 10;
    const int SIZE1 = 15;
    //int arr[SIZE]{};

    Array arr{ new long[SIZE], SIZE };

   
    arr.fillZero();
    arr.Show();
    
    arr.fillRnd();
    arr.Show();

    arr.addNewElem(99);
    arr.Show();

    arr.delElem(1);
    arr.Show();

    arr.sortArr();
    arr.Show();

    arr.minVal();

    arr.Clear();

}