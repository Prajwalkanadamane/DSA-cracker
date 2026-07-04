#include<iostream>
using namespace std;

int main(){

   int arr[] = {2, 5, 6,8 ,7, 9};

   int find = 7;
   bool status = false;

   for(int i=0; i<=5;i++){
    if(arr[i]==find){
        cout<<"element found at index: "<< i << endl;
        status = true;
    } 
   } 

   if (status == false){
    cout << "Invalid elem." << endl;
   }

}