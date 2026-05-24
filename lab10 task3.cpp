//#include <iostream>
//using namespace std;
//
//int findMax(int arr[], int size) {
//    if (size == 1) {
//        return arr[0];
//    }
//    int maxOfRest = findMax(arr, size - 1);
//    if (arr[size - 1] > maxOfRest) {
//        return arr[size - 1];
//    }
//    return maxOfRest;
//}
//
//int main() {
//    int arr[] = { 12, 5, 18, 7, 3 };
//    int size = 5;
//
//    cout << "Maximum element: " << findMax(arr, size) << endl;
//    return 0;
//}