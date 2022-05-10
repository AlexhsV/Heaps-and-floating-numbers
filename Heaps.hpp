#include <iostream>
using namespace std;

template<class T>
class MaxHeap;

template<class T>
class MinHeap;

template<class T>
class MaxHeap{
    public:
        MaxHeap(int MaxHeapSize = 10);
        ~MaxHeap() {delete [] heap;}
        int Size() const {return CurrentSize;}
        T Max() {if (CurrentSize == 0)
                    throw out_of_range("Error");
                return heap[1];}
        MaxHeap<T>& Insert(const T& x);
        MaxHeap<T>& DeleteMax(T& x);
        void Initialize(T a[], int size, int ArraySize);
        void Deactive() {heap = 0;};
    private:
        int CurrentSize, MaxSize;
        T *heap;   //element array
};

//elaxistwn
template<class T>
class MinHeap{
    public:
        MinHeap(int MinHeapSize = 10);
        ~MinHeap() {delete [] heap2;}
        int Size() const {return CurrentSize;}
        T Min() {if (CurrentSize == 0)
                    throw out_of_range("Error");
                return heap2[1];}
        T heap2_0() {return heap2[0];}
        T heap2_1() {return heap2[1];}
        T heap2_2() {return heap2[2];}
        T heap2_3() {return heap2[3];}
        T heap2_4() {return heap2[4];}
        MinHeap<T>& Insert(const T& x);
        MinHeap<T>& DeleteMin(T& x);        
        void Initialize(T a[], int size, int ArraySize);
        void Deactive() {heap2 = 0;};
    private:
        int CurrentSize, MaxSize;
        T *heap2;   //element array
};



template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{//  Max heap constructor.
    MaxSize = MaxHeapSize;
    heap = new T[MaxSize+1];
    CurrentSize = 0;
}

//elaxistwn
template<class T>
MinHeap<T>::MinHeap(int MinHeapSize)
{//  Min heap constructor.
    MaxSize = MinHeapSize;
    heap2 = new T[MaxSize+1];
    CurrentSize = 0;
}



template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x)
{// Insert x into the max heap.
    if (CurrentSize == MaxSize)
        throw out_of_range("No space"); // no space

    // find place for x
    // i starts at new leaf and moves up tree
    int i = ++CurrentSize;
    while (i != 1 && x > heap[i/2]) {
        // cannot put x in heap[i]
        heap[i] = heap[i/2]; // move element down
        i /= 2;             // move to parent
        }

    heap[i] = x;
    return *this;
}


//elaxistwn
template<class T>
MinHeap<T>& MinHeap<T>::Insert(const T& x)
{// Insert x into the max heap2.
    if (CurrentSize == MaxSize)
        throw out_of_range("No space"); // no space

    // find place for x
    // i starts at new leaf and moves up tree
    int i = ++CurrentSize;
    while (i != 1 && x < heap2[i/2]) {
        // cannot put x in heap2[i]
        heap2[i] = heap2[i/2]; // move element down
        i /= 2;             // move to parent
    }

    heap2[i] = x;
    return *this;
}



template<class T>
void MaxHeap<T>::Initialize(T a[], int size, int ArraySize)
{// Initialize max heap to array a.
    delete [] heap;
    heap = a;
    CurrentSize = size;
    MaxSize = ArraySize;

    // make into a max heap
    for (int i = CurrentSize/2; i >= 1; i--) {
        T y = heap[i]; // root of subtree

        // find place to put y
        int c = 2*i; // parent of c is target
                     // location for y
        while (c <= CurrentSize) {
            // heap[c] should be larger sibling
            if (c < CurrentSize &&
            heap[c] < heap[c+1]) c++;

            // can we put y in heap[c/2]?
            if (y >= heap[c]) break; // yes

            // no
            heap[c/2] = heap[c];  // move child up
            c *= 2;               // move down a level
        }
    heap[c/2] = y;
    }

}


//elaxistwn
template<class T>
void MinHeap<T>::Initialize(T a[], int size, int ArraySize)
{// Initialize min heap2 to array a.
    delete [] heap2;
    heap2 = a;
    CurrentSize = size;
    MaxSize = ArraySize;

    // make into a min heap2
    for (int i = CurrentSize/2; i >= 1; i--) {
        T y = heap2[i]; // root of subtree               // to y exei tis times enw to i exeis thesi stoixeiwn px 1,2,3

        // find place to put y
        int c = 2*i; // parent of c is target
                     // location for y
        while (c <= CurrentSize) {
            // heap2[c] should be larger sibling
            if (c < CurrentSize &&
            heap2[c] > heap2[c+1]) c++;

            // can we put y in heap2[c/2]?
            if (y <= heap2[c]) break; // yes

            // no
            heap2[c/2] = heap2[c];  // move child up
            c *= 2;               // move down a level
        }
    heap2[c/2] = y;
    }
}


template<class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x)
{// Set x to max element and delete
  // max element from heap.
    // check if heap is empty
    if (CurrentSize == 0)
        throw out_of_range("Empty");; // empty

    x = heap[1]; // max element

    // restucture heap
    T y = heap[CurrentSize--]; // last element

    // find place for y starting at root
    int i = 1,  // current node of heap
        ci = 2; // child of i
    while (ci <= CurrentSize) {
        // heap[ci] should be largest child of i
        if (ci < CurrentSize && heap[ci] < heap[ci+1]) ci++;                //an to aristero paidi einai mirktotero tou deksiou , psakse apo to deksi kai katw gia na breis to megalutero

        // can we put y in heap[i]?
        if (y >= heap[ci]) break;   // yes                                 //an to teleutaio stoixeio einai

        // no
        heap[i] = heap[ci]; // move child up
        i = ci; ci *= 2;   // move down a level
        }
    heap[i] = y;

    return *this;
}



//elaxistwn
template<class T>
MinHeap<T>& MinHeap<T>::DeleteMin(T& x)
{// Set x to min element and delete
  // min element from heap2.
    // check if heap2 is empty
    if (CurrentSize == 0)
        throw out_of_range("Empty");; // empty

    x = heap2[1]; // min element

    // restucture heap2
    T y = heap2[CurrentSize--]; // last element

    // find place for y starting at root
    int i = 1,  // current node of heap2
        ci = 2; // child of i
    while (ci <= CurrentSize) {
        // heap2[ci] should be largest child of i
        if (ci < CurrentSize && heap2[ci] > heap2[ci+1]) ci++;                //an to aristero paidi einai mirktotero tou deksiou , psakse apo to deksi kai katw gia na breis to megalutero

        // can we put y in heap2[i]?
        if (y <= heap2[ci]) break;   // yes                                 //an to teleutaio stoixeio einai

        // no
        heap2[i] = heap2[ci]; // move child up
        i = ci; ci *= 2;   // move down a level
        }
    heap2[i] = y;

    return *this;
}
