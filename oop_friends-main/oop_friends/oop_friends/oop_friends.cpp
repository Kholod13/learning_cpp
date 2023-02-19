#include <iostream>
using namespace std;

class Array {
private:
    long* arr;
    int size;

    

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

    void Copy(const Array& other)
    {
        this->size = other.size;
        this->arr = new long[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    void fillRnd() {
        srand(unsigned(time(0)));
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }

    void PlusOne() {

        for (int i = 0; i < size; i++) {
            arr[i]++;
        }

    }

    void Opposite() {
        int temp;
        for (int i = 0; i < size; i++) {
            temp = arr[i] * 2;
            arr[i] = arr[i] - temp;
        }

    }

    void Cin() {

        for (int i = 0; i < size; i++) {
            cout << "\nInput val" << i + 1 << " >> ";
            cin >> arr[i];
        }

    }
};

int main()
{
    const int SIZE = 10;

    Array arr{ new long[SIZE], SIZE };
    Array arr1{ new long[SIZE], SIZE };

    arr.fillZero();
    arr.Show();

    arr.fillRnd();
    arr.Show();

    arr.PlusOne();
    arr.Show();

    arr.Opposite();
    arr.Show();

    arr.Cin();
    arr.Show();
    
    arr.Show();

    arr.Copy(arr1);

    arr.Show();

}
