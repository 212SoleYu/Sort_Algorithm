#include"function.h"
#include<random>
#include<stack>
#include<queue>
//show function
void show(const vector<int>& array)
{
	for (auto c : array)
	{
		printf("%d ", c);
	}
	printf("\n");
}

//Insert Sort
void InsertSort(vector<int>& array, int n)
{
	//set the sentry at the end of the array,n means the array has n numbers.the array is n+1 with the sentry.
	array.push_back(0);//set the sentry 0
	for (int i = 1; i < n; i++)
	{
		if (array[i - 1] <= array[i])
			continue;
		else
		{
			array[n] = array[i];//save the value
			int j;
			for (j = i-1;j>=0 && array[j] > array[n]; j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = array[n];
		}
	}
	array.pop_back();
}
void HalfInsertSort(vector<int>& array, int n)
{
	array.push_back(0);
	for (int i = 1; i < n; i++)
	{
		array[n] = array[i];
		if (array[i - 1] < array[i])
			continue;
		else
		{
			int start = 0; int end = i - 1; int mid;
			while (start <= end)
			{
				mid = (start + end) >> 1;
				if (array[mid] > array[n])
					end = mid - 1;
				else
					start = mid + 1;
			}
			int j;
			for (j = i - 1; j >= end + 1; j--)
				array[j + 1] = array[j];
			array[end + 1] = array[n];
		}
	}
	array.pop_back();
}
void ShellSort(vector<int>& array, int n)
{
	array.push_back(0);
	for (int dk = n / 2; dk >= 1; dk = dk / 2)
	{
		for (int i = dk; i < n; i++)
		{
			array[n] = array[i];
			if (array[i] < array[i - dk])
			{
				int j;
				for (j = i - dk; j >= 0 && array[n] < array[j]; j -= dk)
					array[j + dk] = array[j];
				array[j + dk] = array[n];
			}
		}
	}
	array.pop_back();
}

//Swap Sort 
void BubbleSort(vector<int> & array)
{
	int size = array.size();
	for (int i = 0; i < size-1; i++)
	{
		int flag = false;
		for (int j = size-1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				int temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				flag = true;
			}
		}
		if (flag == false)
			return;
	}
}
void DoubleBubbleSort(vector<int>&array)
{
	int size = array.size();
	int left = 0; int right = size - 1;
	bool flag = true;
	while (left < right && true)
	{
		flag = false;
		int temp;
		//backward bubble
		for (int i = left; i < right; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				flag = true;
			}
		}
		right--;
		//forward
		for (int i = right; i > left; i--)
		{
			if (array[i] < array[i - 1])
			{
				temp = array[i];
				array[i] = array[i-1];
				array[i-1] = temp;
				flag = true;
			}
		}
		left++;
	}
}
int Partition(vector<int>& array, int left, int right,int pattern)
{
	//part the array and return the position
	int pivot;
	if (pattern == 0) pivot = left;
	else if (pattern == 1)pivot = (left + right) >> 1;
	else if (pattern == 2) pivot = (rand() % (right - left + 1)) + left;
	int val = array[pivot];
	while (pivot < right && array[right] >= val) right--;
	array[pivot] = array[right];
	while (left < right)
	{
		while (left < right && array[left] <= val) left++;
		array[right] = array[left];
		while (left < right && array[right] >= val) right--;
		array[left] = array[right];
	}
	array[left] = val;
	return left;
}
void QuickSort_rev(vector<int>& array, int start, int end, int pattern)
{
	if (start < end)
	{
		/*(int left = start; int right = end;
		int pivot;
		if (pattern == 0) pivot = start;
		else if (pattern == 1) pivot = (start + end) >> 1;
		int temp = array[pivot];
		while (start < end && array[end] >= array[pivot])
			end--;
		array[pivot]=array[end];
		while (start < end)
		{
			while (start < end && array[start] <= temp) start++;
			array[end] = array[start];
			while (start < end && array[end] >= temp) end--;
			array[start] = array[end];
		}
		array[end] = temp;*/
		int bound = Partition(array, start, end, pattern);
		QuickSort_rev(array, start, bound - 1, pattern);
		QuickSort_rev(array, bound + 1, end, pattern);
	}
}
void QuickSort(vector<int>& array)
{
	//use stack to record the sequence , the same thing by queue
	int start = 0;
	int end = array.size() - 1;
	stack<pair<int, int>> s;
	pair<int, int> init(start, end);
	s.push(init);
	while (!s.empty())
	{
		int left = s.top().first;
		int right = s.top().second;
		s.pop();
		int bound = Partition(array, left, right, 0);
		if (bound - 1 > left)
		{
			pair<int, int> leftarray(left, bound - 1);
			s.push(leftarray);
		}
		if (bound + 1 < right)
		{
			pair<int, int> rightarray(bound + 1, right);
			s.push(rightarray);
		}
	}
}
int kth_elem(vector<int>& array, int left, int right, int k)
{
		int index = Partition(array, left, right, 0);
		if (index == k - 1) return array[index];
		else if (index > k - 1) return kth_elem(array, left, index - 1, k);
		else if (index < k - 1) return kth_elem(array, index + 1, right, k);
		return -1;
}
void DutchFlag(vector<int>& array)
{
	int left = 0; int right = array.size() - 1; int p = 0;
	while (p < right)
	{
		if (array[p] == 0)
		{
			int temp = array[left];
			array[left] = array[p];
			array[p] = temp;
			left++; p++; continue;
		}
		else if (array[p] == 2)
		{
			int temp = array[right];
			array[right] = array[p];
			array[p] = temp;
			right--;
			continue;
		}
		else if (array[p] == 1)
		{
			p++; continue;
		}
	}
}

//SelectSort
void SimpleSelectSort(vector<int>&array)
{
	int size = array.size();
	int min; int index;
	for (int i = 0; i < size - 1; i++)
	{
		min = INT_MAX;
		//search the min index
		for (int j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j]; index = j;
			}
		}
		array[index] = array[i];
		array[i] = min;
	}
}
void HeapAdjustUP(vector<int>& array, int k)
{
	//function adjust the max heap 
	//add the node k,up shift until the heap stand
	while (k > 0)
	{
		int parent = (k - 1) / 2;
		if (array[parent] < array[k])
		{
			int temp = array[parent];
			array[parent] = array[k];
			array[k] = temp;
			k = parent;
		}
		else
			break;
	}
	return;
}
void UpBuildMaxHeap(vector<int>& array)
{
	int size = array.size();
	for (int i = 0; i < size; i++)
	{
		HeapAdjustUP(array, i);
	}
}
void HeapAdjustDown(vector<int>& array, int HeapBound)
{
	//the array[0] is the new node updated from the bottom of the heap
	//just put it down
	int index = 0; int left = 1; int right = 2;
	while (right <= HeapBound)
	{
		if (array[index] < array[left] || array[index] < array[right])
		{
			int bigchild = array[right] > array[left] ? right : left;
			int temp = array[index];
			array[index] = array[bigchild];
			array[bigchild] = temp;
			//reset the index
			index = bigchild;
			left = 2 * bigchild + 1;
			right = 2 * bigchild + 2;
		}
		else break;
	}
	if (left <= HeapBound && array[index] < array[left])
	{
		int temp = array[index];
		array[index] = array[left];
		array[left] = temp;
	}
}
void HeapSort(vector<int>&array)
{
	UpBuildMaxHeap(array);
	int size = array.size();
	for (int i = size - 1; i > 0; i--)
	{
		int temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		HeapAdjustDown(array, i - 1);
	}
}

//Merge Sort
void MergeSort(vector<int>& array, int low, int high)
{
	if (low < high)
	{
		vector<int>b(array.size(), 0);
		int mid = (low + high) >> 1;
		MergeSort(array, low, mid);
		MergeSort(array, mid + 1, high);
		Merge(array, low, mid, high, b);
	}
}
void Merge(vector<int>&array, int low, int mid, int high, vector<int>b)
{
	int i, j, k;
	for (int k = low; k <= high; k++)
	{
		b[k] = array[k];
	}
	for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
	{
		if (b[i] <= b[j])
			array[k] = b[i++];
		else
			array[k] = b[j++];
	}
	while (i <= mid) array[k++] = b[i++];
	while (j <= high) array[k++] = b[j++];
}

//Radix Sort
void RadixSort(vector<int>&array, int round, int base)
{
	vector<queue<int>> qt(base);
	for (int i = 0; i < round; i++)
	{
		int size = array.size();
		for (int j = 0; j < size; j++)
		{
			int time = 0; int temp = array[j];
			while (time < i)
			{
				temp /= base;
				time++;
			}
			temp %= base;
			qt[temp].push(array[j]);
		}
		int qindex = 0; int nindex = 0;
		while (nindex < size && qindex < base)
		{
			if (!qt[qindex].empty())
			{
				array[nindex] = qt[qindex].front();
				qt[qindex].pop();
				nindex++;
			}
			else
			{
				qindex++;
			}
		}
	}
}

//Counting Sort
void CountingSort(vector<int>&array)
{
	int size = array.size();
	vector<int> count(size, 0);
	vector<int> temp(size, 0);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] <= array[j]) count[j]++;
			else count[i]++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		temp[count[i]] = array[i];
	}
	for (int i = 0; i < size; i++)
	{
		array[i]=temp[i];
	}
}