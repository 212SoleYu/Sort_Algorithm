#include<iostream>
#include"function.h"
using namespace std;


int main()
{
	vector<int> test = { 49,38,65,97,76,13,27,49 };
	printf("Insert Sort:\n");
	InsertSort(test,test.size());
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89};
	printf("Half-Insert Sort:\n");
	HalfInsertSort(test, test.size());
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	printf("Shell Sort:\n");
	ShellSort(test, test.size());
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	printf("Bubble Sort:\n");
	BubbleSort(test);
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	DoubleBubbleSort(test);
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	printf("Quick Sort reverse:\n");
	QuickSort_rev(test, 0, test.size() - 1, 0);
	show(test);
	test = { 49,38,65,13,76,23,27,67,97,47,89 };
	QuickSort_rev(test, 0, test.size() - 1, 1); 
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	QuickSort_rev(test, 0, test.size() - 1, 2);
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	printf("Quick Sort:\n");
	QuickSort(test);
	show(test);
	for (int i = 0; i <11; i++)
	{
		test = { 49,38,65,97,76,13,27,67,23,47,89 };
		printf("%d ", kth_elem(test, 0, 10, i+1));
	}
	printf("\n");
	test = { 1,2,2,1,0,0,2,1,2,0,0 };
	printf("Dutch Flag:\n");
	DutchFlag(test);
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	printf("Simple Select Sort:\n");
	SimpleSelectSort(test);
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	HeapSort(test);
	printf("Max Heap Sort:\n");
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	MergeSort(test,0,test.size()-1);
	printf("Merge Sort:\n");
	show(test);
	test = { 49,38,65,97,76,13,27,67,23,47,89 };
	RadixSort(test, 2, 10);
	printf("Radix Sort:\n");
	show(test);
	test = { 30,44,8,6,3,20,60,18,9,62,68,85 };
	CountingSort(test);
	printf("Counting Sort:\n");
	show(test);
}