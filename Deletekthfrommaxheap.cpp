/* Delete Kth element from max heap */

#include<bits/stdc++.h>
using namespace std;

// Heapify the array

void max_heapify (int a[], int n, int i) {
	
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if (n > left && a[left] > a[largest]) {
		largest = left;
	}
	
	if (n > right && a[right] > a[largest]) {
		largest = right;
	}
	
	if (largest != i) {
		
		swap (a[largest], a[i]);
		max_heapify (a, n, largest);
	}
}

void build_heap (int a[], int n) {
	
	for (int i = (n - 2) / 2; i >= 0; i--) {
		max_heapify(a, n, i);
	}
}

void delete_kth (int a[], int *n, int k) {
	
	int r = a[k];
	a[k] = a[*n-1];
	
	(*n)--;
	
	if (a[k] > a[(k - 1) / 2]) {
		max_heapify (a, *n, (k - 1) / 2);
	}
	
	else{
		max_heapify(a, *n, k);
	}
}

int main() {
	int n, k;
	
	cout << "Enter size of the array : ";
	cin >> n;
	
	int a[n];
	
	cout << "\nEnter elements of the array : ";
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// Calling Function to create a max heap
	
	build_heap(a, n);
	
	cout << "\nMax heap : ";
	
	// Print max heap
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	cout << "\nEnter the index of the element which you want to delete : ";
	cin >> k;
	
	// Calling function to delete kth element
	
	delete_kth(a, &n, k);
	
	cout << "\nAfter deleting " << k << "th index element ,new heap is : ";
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
