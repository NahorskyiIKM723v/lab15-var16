#include <iostream>
#include <Windows.h>
using namespace std;

void bubbleSort(double* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(double* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void sortEvenOddIndices(double* array, int size) {
    int evenCount = size / 2;
    int oddCount = (size + 1) / 2;

    double* evenIndices = new double[evenCount];
    double* oddIndices = new double[oddCount];

    int evenIndex = 0, oddIndex = 0;

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            oddIndices[oddIndex++] = array[i];
        }
        else {
            evenIndices[evenIndex++] = array[i];
        }
    }

    selectionSort(evenIndices, evenCount);

    bubbleSort(oddIndices, oddCount);

    cout << "Відсортовані непарні індекси (бульбашка): ";
    for (int i = 0; i < oddCount; ++i) {
        cout << oddIndices[i] << " ";
    }
    cout << endl;

    cout << "Відсортовані парні індекси (вибір): ";
    for (int i = 0; i < evenCount; ++i) {
        cout << evenIndices[i] << " ";
    }
    cout << endl;

    evenIndex = 0;
    oddIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            array[i] = oddIndices[oddIndex++];
        }
        else {
            array[i] = evenIndices[evenIndex++];
        }
    }

    delete[] evenIndices;
    delete[] oddIndices;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    double* array = new double[n];

    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    cout << "Початковий масив: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    sortEvenOddIndices(array, n);

    cout << "Відсортований масив: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    return 0;
}
