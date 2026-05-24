//#include <iostream>
//using namespace std;
//
//// checking if target can get from subset of arr elements
//bool isSubsetSum(int arr[], int size, int target) {
//    // base case target reached
//    if (target == 0) {
//        return true;
//    }
//    // no elements left
//    if (size == 0) {
//        return false;
//    }
//    // skip if element is too big
//    if (arr[size - 1] > target) {
//        return isSubsetSum(arr, size - 1, target);
//    }
//    // try including or excluding last element
//    return isSubsetSum(arr, size - 1, target) || isSubsetSum(arr, size - 1, target - arr[size - 1]);
//}
//
//// finds index of largest element
//int findLargestIndex(int arr[], int size) {
//    int maxIdx = 0;
//    for (int i = 1; i < size; i++) {
//        if (arr[i] > arr[maxIdx]) {
//            maxIdx = i;
//        }
//    }
//    return maxIdx;
//}
//
//// shifts elements left to remove one at index
//void removeElement(int arr[], int& size, int index) {
//    for (int i = index; i < size - 1; i++) {
//        arr[i] = arr[i + 1];
//    }
//    size--;
//}
//
//// to find magic number
//int findMagicNumber(int arr[], int size) {
//    if (size == 0) {
//        return -1;
//    }
//
//    // get largest number
//    int largestIdx = findLargestIndex(arr, size);
//    int largest = arr[largestIdx];
//
//    // make temp array without the largest element
//    int temp[100];
//    int tempSize = 0;
//    for (int i = 0; i < size; i++) {
//        if (i != largestIdx) {
//            temp[tempSize] = arr[i];
//            tempSize++;
//        }
//    }
//
//    // check if largest can be sum of subset of remaining
//    if (isSubsetSum(temp, tempSize, largest)) {
//        return largest;
//    }
//
//    // if not found then remove largest and try again from start
//    removeElement(arr, size, largestIdx);
//    findMagicNumber(arr, size);
//}
//
//int main() {
//    int arr[] = { 2, 3, 5, 8, 13 };
//    int size = 5;
//
//    int result = findMagicNumber(arr, size);
//
//    if (result != -1) {
//        cout << result << endl;
//    }
//
//    return 0;
//}