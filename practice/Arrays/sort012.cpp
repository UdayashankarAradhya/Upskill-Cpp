#include<iostream>
#include<vector>
using namespace std;
void sort012(vector<int> &arr) {
    int low=0, mid=0;
    int high= arr.size()-1;
    while(mid<=high) {
            switch(arr[mid]){
                case 0:
                swap(arr[mid], arr[low]);
                mid++;
                low++;
                break;
                case 1:
                mid++;
                break;
                case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
            }
        }
    }


int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    if(n <= 0) {
        cout << "Enter a valid size greater than 0." << endl;
        return 0;
    }
    vector<int> arr(n);
    cout << "Enter the elements of the array (0s, 1s, and 2s only): ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort012(arr);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}