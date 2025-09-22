#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void printPair(const unordered_map<string , int> &map){
    cout<<"Current List: "<<endl;
    for(const auto &x:map){
        cout<<"-"<<x.first<<":"<<x.second<<endl;
    }
    cout<<"----------------"<<endl;
}
int main(){
    unordered_map<string,int> mylist;
    cout<<"An empty map has been declared."<<endl;
    mylist["apples"]=50;
    mylist["oranges"]=25;
    mylist["Bananas"]=20;
    printPair(mylist);
//accesing a value by its key
cout<<"Accessing the number of apples:"<<endl;
int apple_count=mylist["apples"];
cout<<"Found "<<apple_count<<" apples"<<endl;
cout<<"------------"<<endl;

// Checking if the key exists
cout<<"Checking if banana exists:"<<endl;
if(mylist.count("Bananas")){
    cout<<"Yes,Bananas Exsits in list"<<endl;
}
if(!mylist.count("Cherries")){
    cout<<"No, cherries does not exist in the list"<<endl;
}
cout<<"---------------"<<endl;
cout<<"Deleting oranges:"<<endl;
mylist.erase("oranges");
printPair(mylist);
return 0;



}