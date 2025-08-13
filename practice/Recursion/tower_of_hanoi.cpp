#include<iostream>
using namespace std;
void tower_of_hanoi(int n, char source, char destination, char auxilary) {
    if(n==0) {
        return;
    }
    tower_of_hanoi(n-1, source, auxilary, destination);
    cout<<"Move disk " << n << " from " << source << " to " << destination << endl;
    tower_of_hanoi(n-1, auxilary, destination, source); 
}
int main() {
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    cout<<"The sequence of moves involved in the Tower of Hanoi are: " << endl;
    tower_of_hanoi(n, 'A', 'C', 'B'); 
    cout<<endl;
    return 0;
    
}