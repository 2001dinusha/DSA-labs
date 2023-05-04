#include <iostream>
#include<vector>
#include <sstream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;  // assume root is the largest
    int left = 2 * root + 1;  // left child index
    int right = 2 * root + 2;  // right child index
  
    // check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
  
    // check if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    // if largest is not root, swap the elements and heapify the affected sub-tree
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    // extracting elements from heap one by one and heapifying the remaining heap
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{

    string input; // string to store user input
    vector<int> num_vect; // vector to store numbers
    int num;
    

    cout << "Enter a set of space-separated numbers: ";
    getline(cin, input); // read entire line of user input

    istringstream iss(input); // create a string stream from the input string

    // read integers from the string stream and store them in the vector
    while (iss >> num) {
        num_vect.push_back(num);
    }
    int n = num_vect.size();
    int heap_arr[n];
   copy(num_vect.begin(), num_vect.end(), heap_arr); //copy the elements in the vector to an array

   cout<<"Input array:"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
   cout<<endl;
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}