#include "Heaps.hpp"    
#include <iostream>
#include <random>
#include <functional>
using namespace std;

int main(){

    int N; 
    do {
        cout << "Enter the size of the array named, heap_min: ";
        cin >> N;
        if (N <= 0){
            cout << "Invalid size, please try again!\n" << "TIP: (the size of the array must be an integer greater than 0)\n \n";
        }
    } while (N <= 0);       //sto telos prepei na allaxtei gia N > 10.000.000

    default_random_engine generator;
    chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = bind(my_distribution, generator);
   
    float* heap_min = new float[N]; //create dynamic array 
    for (int i = 1; i < N+1; i++) {             // i=0; i< N prepei kanonika
        heap_min[i] = random_num() * 10000.0;
        cout << heap_min[i] << endl;
    }

    cout << "----------------- "<< endl;

    float* heap_max = new float[N]; //create dynamic array
    for (int i = 1; i < N+1; i++) {         // i=0; i< N prepei kanonika
        heap_max[i] = heap_min[i];
    }


    MaxHeap<float> maximumHeap;
    MinHeap<float> minimumHeap;
    maximumHeap.Initialize(heap_max, N, N);
    minimumHeap.Initialize(heap_min, N, N);


    float t1,t2,s1;
    for (int i = 0; i < N; i++){
        cout << maximumHeap.Size() << " : size " << endl;

        
        maximumHeap.DeleteMax(t1);
        maximumHeap.DeleteMax(t2);

        
        cout << t1 << ": t1" << endl;
        cout << t2 << ": t2" << endl;

        s1 = t1 + t2;

        cout << s1 << endl;

        maximumHeap.Insert(s1);
        
        cout << maximumHeap.Size() << " : size " << endl;
    }
 //  do{

 //   }while (maximumHeap.Size() > 1);
    



    delete [] heap_min;
    delete [] heap_max;










    return 0;
}