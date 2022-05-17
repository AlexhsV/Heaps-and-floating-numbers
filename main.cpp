#include "Heaps.hpp"    
#include <iostream>
#include <random>
#include <functional>
#include <cmath>
using namespace std;

bool compare_float(float x, float y, float epsilon = 0.01f){
   if(fabs(x - y) < epsilon) //check if the absolute value of the difference of SumMax and SumMin is less than epsilon, where epsilon is the least positive number defined as 0.01
      return true; //they are same
      return false; //they are not same
}


int main(){

    int N; 
    cout << "Enter the size of the array named: heap_min: ";
    cin >> N;
    while (N <= 0){                //sto telos prepei na allaxtei gia N > 10.000.000
         cout << "Invalid size, please try again!\n" << "TIP: (the size of the array must be an integer greater than 0): ";
         cin >> N;
         cout << endl;
    }

    default_random_engine generator;
    chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = bind(my_distribution, generator);
   
    float* heap_min = new float[N+1]; //create dynamic array 
    for (int i = 1; i < N+1; i++) {           
        heap_min[i] = random_num() * 10000.0;
        //cout << heap_min[i] << endl;
    }

    cout << "--------------------------------------------------------- "<< endl;

    float* heap_max = new float[N+1]; //create dynamic array 
    for (int i = 1; i < N+1; i++) {         
        heap_max[i] = heap_min[i];
    }


    MaxHeap<float> maximumHeap;        //declare  MaxHeap
    MinHeap<float> minimumHeap;        //declare MinHeap
    maximumHeap.Initialize(heap_max, N, N);     
    minimumHeap.Initialize(heap_min, N, N);

    float tempMin1,tempMin2,SumMin;
    while (true){             

        minimumHeap.DeleteMin(tempMin1);    //assigns the min element to tempMin1 | deletes the min element | restructs the heap
        minimumHeap.DeleteMin(tempMin2);    //assigns the min element to tempMin2 | deletes the min element | restructs the heap
        
        SumMin = tempMin1 + tempMin2;    //calculates the sum of the 2 elements which were deleted

        minimumHeap.Insert(SumMin);     //inserts SumMin to the appropriate spot in the heap

        if (minimumHeap.Size() == 1){   //if there is only one element in the heap

            minimumHeap.DeleteMin(SumMin);   //extraction of last element which has the sum of the min heap

            cout << fixed;
            cout << SumMin <<", is the sum of the Min Heap" << endl;
            break;                //breaks the loop
        }
    }


    float tempMax1,tempMax2,SumMax;
    while (true){

        maximumHeap.DeleteMax(tempMax1);    //assigns the max element to tempMax1 | deletes the max element | restructs the heap
        maximumHeap.DeleteMax(tempMax2);    //assigns the max element to tempMax2 | deletes the max element | restructs the heap
            
        SumMax = tempMax1 + tempMax2;      //calculates the sum of the 2 elements which were deleted

        maximumHeap.Insert(SumMax);         //inserts SumMax to the appropriate spot in the heap

        if (maximumHeap.Size() == 1){       //if there is only one element in the heap  
                
            maximumHeap.DeleteMax(SumMax);   //assigns the last element to SumMax | deletes the last element

            //cout << fixed;
            cout << SumMax <<", is the sum of the Max Heap" << endl;
            cout << endl;
            break;                 //breaks the loop
        }
    }

    if(compare_float(SumMin, SumMax, 0.001f)){
        cout << "They are equivalent." << endl;
    } else {
        cout << "They are not equivalent." << endl;
    }

    delete [] heap_min;
    delete [] heap_max;

    return 0;
}