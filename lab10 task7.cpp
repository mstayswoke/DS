//#include <iostream>
//using namespace std;
//
//bool isSubsetSum(int arr[], int size, int target) {
//    if (target == 0) {
//        return true;
//    }
//    if (size == 0) {
//        return false;
//    }
//    if (arr[size - 1] > target) {
//        return isSubsetSum(arr, size - 1, target);
//    }
//    return isSubsetSum(arr, size - 1, target) || isSubsetSum(arr, size - 1, target - arr[size - 1]);
//}
//
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
//void removeElement(int arr[], int& size, int index) {
//    for (int i = index; i < size - 1; i++) {
//        arr[i] = arr[i + 1];
//    }
//    size--;
//}
//
//int findMagicNumber(int arr[], int size) {
//    if (size == 0) {
//        return -1;
//    }
//
//    int largestIdx = findLargestIndex(arr, size);
//    int largest = arr[largestIdx];
//
//    int temp[100];
//    int tempSize = 0;
//    for (int i = 0; i < size; i++) {
//        if (i != largestIdx) {
//            temp[tempSize] = arr[i];
//            tempSize++;
//        }
//    }
//
//    if (isSubsetSum(temp, tempSize, largest)) {
//        return largest;
//    }
//
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
//    else {
//        cout << "-1" << endl;
//    }
//
//    return 0;
//}