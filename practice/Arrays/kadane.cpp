#include<iostream>
#include<vector>
using namespace std;
int kadaneAlgorithm(vector<int> &arr) {
    int n = arr.size();
    if(n <= 0) return 0;
    int maxSum = arr[0];
    int currentSum = 0;
    for(int i = 0; i < n; i++) {
        currentSum+= arr[i];
        maxSum = max(maxSum, currentSum);
        if(currentSum< 0) {
            currentSum=0;
        }
    }
    return maxSum;
}
int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    if(n <= 0) {
        cout << "Enter a valid size greater than 0." << endl;
        return 0;
    } else {
        vector<int> arr(n);
        cout << "Enter the elements of the array: ";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int result = kadaneAlgorithm(arr);
        cout << "Maximum subarray sum using Kadane's algorithm is: " << result << endl;
        return 0;
    }
}