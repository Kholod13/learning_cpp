#include <iostream>
#include <exception>
using namespace std;

class ArrayException : public exception {
public:
    virtual const char* what() const throw() {
        return "Array Exception";
    }
};

class Array {
private:
    long* arr;
    int size;

public:
    Array(long* arr, int size) : arr(nullptr), size(size) {
        if (size <= 0) {
            throw ArrayException();
        }
        this->arr = arr;
        this->size = size;
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
    }

    void fillZero() {
        if (size <= 0) {
            throw ArrayException();
        }
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

    void Copy(const Array& other) {
        if (size != other.size) {
            throw ArrayException();
        }
        for (size_t i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    void fillRnd() {
        if (size <= 0) {
            throw ArrayException();
        }
        srand(unsigned(time(0)));
        for (size_t i = 0; i < size; i++) {
            arr[i] = rand() % 100;
        }
    }

    void PlusOne() {
        if (size <= 0) {
            throw ArrayException();
        }
        for (int i = 0; i < size; i++) {
            arr[i]++;
        }
    }

    void Opposite() {
        if (size <= 0) {
            throw ArrayException();
        }
        int temp;
        for (int i = 0; i < size; i++) {
            temp = arr[i] * 2;
            arr[i] = arr[i] - temp;
        }
    }

    void Cin() {
        if (size <= 0) {
            throw ArrayException();
        }
        for (int i = 0; i < size; i++) {
            cout << "\nInput val" << i + 1 << " >> ";
            cin >> arr[i];
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw ArrayException();
            }
        }
    }

    ~Array() {
        delete[] arr;
    }
};

int main() {
    const int SIZE = 10;

    try {
        Array arr{ new long[SIZE], SIZE };
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

        Array arr1{ new long[SIZE], SIZE };
        arr.Copy(arr1);

        arr.Show();
    }
    catch (ArrayException& e) {
        cout << "Caught an ArrayException: " << e.what() << endl;
    }
    catch (exception& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}