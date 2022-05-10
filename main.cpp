#include "Heaps.hpp"    
#include <iostream>
#include <random>
#include <functional>
#include <cmath>
using namespace std;

bool compare_float(float x, float y, float epsilon = 0.01f){
   if(fabs(x - y) < epsilon)
      return true; //they are same
      return false; //they are not same
}

int main(){

    int N; 
    do {
        cout << "Enter the size of the array named: heap_min: ";
        cin >> N;
        if (N <= 0){
            cout << "Invalid size, please try again!\n" << "TIP: (the size of the array must be an integer greater than 0)\n \n";
        }
    } while (N <= 0);       //sto telos prepei na allaxtei gia N > 10.000.000

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


    MaxHeap<float> maximumHeap;
    MinHeap<float> minimumHeap;
    maximumHeap.Initialize(heap_max, N, N);
    minimumHeap.Initialize(heap_min, N, N);

    float tempMin1,tempMin2,SumMin;
    while (true){

        minimumHeap.DeleteMin(tempMin1);
        minimumHeap.DeleteMin(tempMin2);
        
        SumMin = tempMin1 + tempMin2;

        minimumHeap.Insert(SumMin);

        if (minimumHeap.Size() == 1){

            minimumHeap.DeleteMin(SumMin);          //extraction of last element which has the sum of the heap

            //cout << fixed;
            cout << SumMin <<", is the sum of the Max Heap" << endl;
            break;
        }
    }


    float tempMax1,tempMax2,SumMax;
    while (true){

        maximumHeap.DeleteMax(tempMax1);
        maximumHeap.DeleteMax(tempMax2);
            
        SumMax = tempMax1 + tempMax2;

        maximumHeap.Insert(SumMax);

        if (maximumHeap.Size() == 1){
                
            maximumHeap.DeleteMax(SumMax);

            //cout << fixed;
            cout << SumMax <<", is the sum of the Min Heap" << endl;
            cout << endl;
            break;
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