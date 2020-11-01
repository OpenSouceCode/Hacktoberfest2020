/*
Class based implementation of MaxHeap.
In main we have compared it with a priority Queue.
It will run 5000 different test cases with random numbers to ensure that the implementation is correct.
*/


#include <bits/stdc++.h>
using namespace std;

class Heap{
    private:
        int *H;
        int size = 0;
        int cap;

    private:
        void swap(int i, int j){
            int temp = H[i];
            H[i] = H[j];
            H[j] = temp;
        }
        
         int parent(int i){
            return (i-1)/2;
        }

        int leftChild(int i){
            return 2*i+1;
        }

        int rightChild(int i){
            return 2*i+2;
        }

    public:
        Heap(int k){
            cap = k;
            H = new int[cap];
            size = 0;
        }
        
        int getSize(){
            return size;
        }

        void shiftUp(int i){
            while(i > 0 && H[parent(i)] < H[i]){
                swap(i, parent(i));
                i = parent(i);
            }
        }

        void insert(int k){
            if(size+1 == cap){
                cout << "Heap Overflow";
                return;
            }
            size++;
            int i = size-1;
            H[i] = k;
            shiftUp(i);
        }

        void shiftDown(int i){
            if(i >= size)
                return; 
            int maxIndex = i;
            int l = leftChild(i);
            if(l < size && H[maxIndex] < H[l])
                maxIndex = l;
            int r = rightChild(i);
            if(r < size && H[maxIndex] < H[r])
                maxIndex = r;

            if(maxIndex != i){
                swap(i, maxIndex);
                shiftDown(maxIndex);
            }
        }

        int extractMax(){
            if(size ==0){
                cout << "Heap Underflow" << endl;
                return -1;
            }
            int result = H[0];
            H[0] = H[size-1];
            size--;
            shiftDown(0);
            return result;
        }
};

int main()
{
    int t = 5000;
    while(t--){
        cout << endl << endl << endl << "Running test number" << t << endl;
        int n = random() % 100000 + 109;
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i] = random() % 500000 + 1201;
        }
        Heap hp(n+1);
        for(int i=0; i<n; i++){
            hp.insert(arr[i]);
        }

        priority_queue<int> pq;

        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }

        int a1, a2;
        int i=n;
        while(i--){
            a1 = hp.extractMax();
            a2 = pq.top(); pq.pop();

            if(a1 != a2){
                cout << "Heap : " << a1 << " || " << "priority queue : " << a2 << " || " << "Elements left " << i;
                return 0;
            } 
        }
    }
    cout << "Sucess" << endl;
    return 0;
}