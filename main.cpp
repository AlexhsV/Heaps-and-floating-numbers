#include "Heaps.hpp"    
#include <iostream>
#include <random>
#include <functional>
using namespace std;

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
        cout << heap_min[i] << endl;
    }

    cout << "----------------- "<< endl;

    float* heap_max = new float[N+1]; //create dynamic array
    for (int i = 1; i < N+1; i++) {         
        heap_max[i] = heap_min[i];
    }


    MaxHeap<float> maximumHeap;
    MinHeap<float> minimumHeap;
    maximumHeap.Initialize(heap_max, N, N);
    minimumHeap.Initialize(heap_min, N, N);

    float tempMin1,tempMin2,tempSumMin;
    while (true){

        cout << minimumHeap.heap2_0() << " heap0" << endl;
        cout << minimumHeap.heap2_1() << " heap1" << endl;
        cout << minimumHeap.heap2_2() << " heap2" << endl;
        cout << minimumHeap.heap2_3() << " heap3" << endl;
        cout << minimumHeap.heap2_4() << " heap4" << endl;
        cout << minimumHeap.Size() << " : size " << endl;
        minimumHeap.DeleteMin(tempMin1);

        minimumHeap.DeleteMin(tempMin2);
        

        cout << minimumHeap.heap2_0() << " heap0" << endl;

        cout << tempMin1 << ": tempMin1" << endl;
        cout << tempMin2 << ": tempMin2" << endl;

        tempSumMin = tempMin1 + tempMin2;

        cout << fixed;
        cout << tempSumMin << endl;

        minimumHeap.Insert(tempSumMin);


        cout << minimumHeap.heap2_0() << " heap0" << endl;
        cout << minimumHeap.heap2_1() << " heap1" << endl;
        cout << minimumHeap.heap2_2() << " heap2" << endl;
        cout << minimumHeap.heap2_3() << " heap3" << endl;
        cout << minimumHeap.heap2_4() << " heap4" << endl;


        cout << minimumHeap.Size() << " : size " << endl;

        if (minimumHeap.Size() == 1){
       //     float sumFromMinHeap = tempSumMin;
             cout << minimumHeap.Size() << " : size " << endl;
            minimumHeap.DeleteMin(tempSumMin);
            cout << minimumHeap.Size() << " : size " << endl;
            cout << fixed;
            cout << tempSumMin << endl;
     //       cout << fixed;
    //        cout << sumFromMinHeap << endl;
            break;
        }
    }


    float tempMax1,tempMax2,tempSumMax;
        while (true){

            maximumHeap.DeleteMax(tempMax1);

            maximumHeap.DeleteMax(tempMax2);
            
            tempSumMax = tempMax1 + tempMax2;

            maximumHeap.Insert(tempSumMax);

            if (maximumHeap.Size() == 1){
                float sumFromMaxHeap = tempSumMax;
                cout << fixed;
                cout << sumFromMaxHeap << endl;
                break;
            }
        }





    delete [] heap_min;
    delete [] heap_max;



    return 0;
}