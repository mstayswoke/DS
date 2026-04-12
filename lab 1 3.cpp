#include<iostream>
using namespace std;

template <class T>
int linearSearch(T arr[], int size, T key) {

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

template <class T>
void printSearchResult(int index, T key) {

    if (index != -1) {
        cout << key << " found at index: " << index << endl;
    }
    else {
        cout << key << " not found" << endl;
    }
}

int main() {

    // Integer test
    int intArray[5] = { 64, 25, 12, 22, 11 };
    int intKey = 12;

    int intIndex = linearSearch(intArray, 5, intKey);
    printSearchResult(intIndex, intKey);


    // Float test
    float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
    float floatKey = 1.62;

    int floatIndex = linearSearch(floatArray, 4, floatKey);
    printSearchResult(floatIndex, floatKey);


    // String test
    string stringArray[4] = { "apple", "orange", "banana", "grape" };
    string stringKey = "banana";

    int stringIndex = linearSearch(stringArray, 4, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}