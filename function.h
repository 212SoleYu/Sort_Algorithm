#pragma once
#include<vector>
using namespace std;

//all the array uses vector
//show function 
void show(const vector<int>& array);


//Insert Sort
void InsertSort(vector<int>& array, int n);
void HalfInsertSort(vector<int>& array, int n);
void ShellSort(vector<int>& array, int n);

//Swap Sort 
void BubbleSort(vector<int> & array);
void DoubleBubbleSort(vector<int>&array);
void QuickSort_rev(vector<int>& array, int start, int end, int pattern);
void QuickSort(vector<int>& array);
int kth_elem(vector<int>& array, int left, int right, int k);
void DutchFlag(vector<int>& array);

//Select Sort
void SimpleSelectSort(vector<int>&array);
void HeapAdjustUP(vector<int>& array, int k);
void HeapAdjustDown(vector<int>& array, int HeapBound);
void UpBuildMaxHeap(vector<int>& array);
void HeapSort(vector<int>&array);

//Merge Sort
void Merge(vector<int>&array, int low, int mid, int high, vector<int>b);
void MergeSort(vector<int>& array, int low, int high);

//Radix Sort
void RadixSort(vector<int>&array, int round, int base = 10);

//Counting Sort
void CountingSort(vector<int>&array);