#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;
//create a bubble sort function that sorts an array of integers
void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++) //n-i-1
		{
			if (arr[j] > arr[j + 1]) //if the first number is greater than the second number
			{
				std::swap(arr[j], arr[j + 1]); //swap the two numbers
				swapped = true;
			}
		}
		if (swapped == false) //if the numbers are already sorted
			break;
	}
};
//create an insertion sort function that sorts an array of integers
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) //start at the second element
	{
		key = arr[i]; //set the key to the second element
		j = i - 1; //set j to the first element
		while (j >= 0 && arr[j] > key) //while j is greater than or equal to 0 and the first element is greater than the second element
		{
			arr[j + 1] = arr[j]; //set the second element to the first element
			j = j - 1; //decrement j
		}
		arr[j + 1] = key; //set the first element to the key
	}
};
//create a merge sort function that sorts an array of integers
void mergeSort(int arr[], int size)
{
	int i, j, k;
	int n1 = size/2; //size of the left array
	int n2 = size/2; //size of the right array
	int L[100], R[100]; //create two temporary arrays
	for (i = 0; i < n1; i++) //copy the data to the left array
		L[i] = arr[0 + i];
	for (j = 0; j < n2; j++) //copy the data to the right array
		R[j] = arr[size/2 + 1 + j];
	i = 0; //initial index of the left array
	j = 0; //initial index of the right array
	k = 0; //initial index of the merged array
	while (i < n1 && j < n2) //while i is less than the size of the left array and j is less than the size of the right array
	{
		if (L[i] <= R[j]) //if the left array is less than or equal to the right array
		{
			arr[k] = L[i]; //set the merged array to the left array
			i++; //increment i
		}
		else //if the right array is less than the left array
		{
			arr[k] = R[j]; //set the merged array to the right array
			j++; //increment j
		}
		k++; //increment k
	}
	while (i < n1) //while i is less than the size of the left array
	{
		arr[k] = L[i]; //set the merged array to the left array
		i++; //increment i
		k++; //increment k
	}
	while (j < n2) //while j is less than the size of the right array
	{
		arr[k] = R[j]; //set the merged array to the right array
		j++; //increment j
		k++; //increment k
	}
};
//create a partition function that sorts an array of integers
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; //set the pivot to the last element
	int i = (low - 1); //set the index of the smaller element
	for (int j = low; j <= high - 1; j++) //for each element in the array
	{
		if (arr[j] <= pivot) //if the element is less than or equal to the pivot
		{
			i++; //increment the index of the smaller element
			std::swap(arr[i], arr[j]); //swap the two elements
		}
	}
	std::swap(arr[i + 1], arr[high]); //swap the two elements
	return (i + 1); //return the index of the smaller element
};
//create a quicksort function that sorts an array of integers
void quickSort(int arr[], int low, int high)
{
	if (low < high) //if the low index is less than the high index
	{
		int pi = partition(arr, low, high); //set the partition index to the partition function
		quickSort(arr, low, pi - 1); //sort the left side of the partition
		quickSort(arr, pi + 1, high); //sort the right side of the partition
	}
};
//create a counting sort function that sorts an array of integers
void countingSort(int arr[], int n)
{
	int output[100]; //create an output array
	int count[100]; //create a count array
	int max = arr[0]; //set the max to the first element
	for (int i = 1; i < n; i++) //for each element in the array
	{
		if (arr[i] > max) //if the element is greater than the max
			max = arr[i]; //set the max to the element
	}
	for (int i = 0; i <= max; ++i) //for each element in the array
		count[i] = 0; //set the count to 0
	for (int i = 0; i < n; i++) //for each element in the array
		count[arr[i]]++; //increment the count
	for (int i = 1; i <= max; i++) //for each element in the array
		count[i] += count[i - 1]; //add the count to the previous count
	for (int i = n - 1; i >= 0; i--) //for each element in the array
	{
		output[count[arr[i]] - 1] = arr[i]; //set the output to the element
		count[arr[i]]--; //decrement the count
	}
	for (int i = 0; i < n; i++) //for each element in the array
		arr[i] = output[i]; //set the element to the output
};
//create a count sort function that sorts an array with the parameters array and int size
void countSort(int arr[], int size)
{
	int output[100]; //create an output array
	int count[100]; //create a count array
	int max = arr[0]; //set the max to the first element
	for (int i = 1; i < size; i++) //for each element in the array
	{
		if (arr[i] > max) //if the element is greater than the max
			max = arr[i]; //set the max to the element
	}
	for (int i = 0; i <= max; ++i) //for each element in the array
		count[i] = 0; //set the count to 0
	for (int i = 0; i < size; i++) //for each element in the array
		count[arr[i]]++; //increment the count
	for (int i = 1; i <= max; i++) //for each element in the array
		count[i] += count[i - 1]; //add the count to the previous count
	for (int i = size - 1; i >= 0; i--) //for each element in the array
	{
		output[count[arr[i]] - 1] = arr[i]; //set the output to the element
		count[arr[i]]--; //decrement the count
	}
	for (int i = 0; i < size; i++) //for each element in the array
		arr[i] = output[i]; //set the element to the output
};
int getMax(int arr[], int n)
{
	int mx = arr[0]; //set the max to the first element
	for (int i = 1; i < n; i++) //for each element in the array
		if (arr[i] > mx) //if the element is greater than the max
			mx = arr[i]; //set the max to the element
	return mx; //return the max
};
//create a countSort function that sorts an array of integers
void countSort2(int arr[], int n, int exp)
{
	int output[100]; //create an output array
	int i, count[10] = { 0 }; //create a count array
	for (i = 0; i < n; i++) //for each element in the array
		count[(arr[i] / exp) % 10]++; //increment the count
	for (i = 1; i < 10; i++) //for each element in the array
		count[i] += count[i - 1]; //add the count to the previous count
	for (i = n - 1; i >= 0; i--) //for each element in the array
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; //set the output to the element
		count[(arr[i] / exp) % 10]--; //decrement the count
	}
	for (i = 0; i < n; i++) //for each element in the array
		arr[i] = output[i]; //set the element to the output
};
//create a radix sort function that sorts an array of integers
void radixSort(int arr[], int n)
{
	int m = getMax(arr, n); //set the max to the getMax function
	for (int exp = 1; m / exp > 0; exp *= 10) //for each element in the array
		countSort2(arr, n, exp); //set the countSort to the element
};
//create a heapify function that sorts an array of integers
void heapify(int arr[], int n, int i)
{
	int largest = i; //set the largest to the element
	int l = 2 * i + 1; //set the left to the element
	int r = 2 * i + 2; //set the right to the element
	if (l < n && arr[l] > arr[largest]) //if the left is less than the element
		largest = l; //set the largest to the left
	if (r < n && arr[r] > arr[largest]) //if the right is less than the element
		largest = r; //set the largest to the right
	if (largest != i) //if the largest is not the element
	{
		std::swap(arr[i], arr[largest]); //swap the two elements
		heapify(arr, n, largest); //set the heapify to the element
	}
};
//create a heapSort function that sorts an array of integers
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) //for each element in the array
		heapify(arr, n, i); //set the heapify to the element
	for (int i = n - 1; i >= 0; i--) //for each element in the array
	{
		std::swap(arr[0], arr[i]); //swap the two elements
		heapify(arr, i, 0); //set the heapify to the element
	}
};
//create a printArray function that prints an array of integers
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i) //for each element in the array
		std::cout << arr[i] << " "; //print the element
	std::cout << "\n"; //print a new line
};
/*Create a program that generate an array of sizes n= 10, 100, 500, 5000, 25,000, and
100,000 items. Your program should populate those arrays with randomly generated
integers with a value between 0 and the 2n where n is the size of the array. Create an
implementation for the following sort operations.
a. Bubble sort
b. Insertion sort
c. Merge-sort
d. Quicksort
e. Counting sort
f. Radix-sort
g. Heap-sort
2. Test each of the sort operations and record the time the sort takes to complete. You
should test each on the same unsorted array to get the best comparison. You should do
this for each array size (from requirement 1) a minimum of 10 times. Your test should
use the chrono library’s high_resolution_clock class. The following example of how to
do this in nanoseconds is found on Stack Overflow. Only the time in the 7 sort functions
should be measured*/

int main()
{
	const int n = 10; //set the size of the array
	int arr[n]; //create an array
	srand(time(NULL)); //seed the random number generator
	for (int i = 0; i < n; i++) //for each element in the array
		arr[i] = rand() % (2*n); //set the element to a random number
	int arr_size = sizeof(arr) / sizeof(arr[0]); //set the size of the array

	auto timeStart = Clock::now(); //set the start time
	bubbleSort(arr, arr_size); //set the bubbleSort to the array
	auto timeStop = Clock::now(); //set the stop time
	int duration = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop - timeStart).count(); //set the duration
	std::cout << "Time taken by bubble sort: " << duration << " nanoseconds" << std::endl; //print the duration

	timeStart = Clock::now(); //set the start time
	insertionSort(arr, arr_size); //set the insertionSort to the array
	timeStop = Clock::now(); //set the stop time
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop - timeStart).count(); //set the duration
	std::cout << "Time taken by insertion sort: " << duration << " nanoseconds" << std::endl; //print the duration

	timeStart = Clock::now(); //set the start time
	mergeSort(arr, arr_size - 1); //set the mergeSort to the array
	timeStop = Clock::now(); //set the stop time
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop - timeStart).count(); //set the duration
	std::cout << "Time taken by merge sort: " << duration << " nanoseconds" << std::endl; //print the duration

	timeStart = Clock::now(); //set the start time
	quickSort(arr, 0, arr_size - 1); //set the quickSort to the array
	timeStop = Clock::now(); //set the stop time
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop - timeStart).count(); //set the duration
	std::cout << "Time taken by quick sort: " << duration << " nanoseconds" << std::endl; //print the duration

	timeStart = Clock::now(); //set the start time
	countSort(arr, arr_size);
	timeStop = Clock::now(); //set the stop time
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop - timeStart).count(); //set the duration
	std::cout << "Time taken by count sort: " << duration << " nanoseconds" << std::endl; //print the duration

	timeStart = Clock::now(); //set the start time
	radixSort(arr, arr_size);
	timeStop = Clock::now(); //set the stop time
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop - timeStart).count(); //set the duration
	std::cout << "Time taken by radix sort: " << duration << " nanoseconds" << std::endl; //print the duration

	timeStart = Clock::now(); //set the start time
	heapSort(arr, arr_size);
	timeStop = Clock::now(); //set the stop time
	duration = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop - timeStart).count(); //set the duration
	std::cout << "Time taken by heap sort: " << duration << " nanoseconds" << std::endl; //print the duration
}


/*create a program that generate an array of sizes n = 10, 100, 500, 5000, 25, 000, and
100, 000 items.Your program should populate those arrays with randomly generated
integers with a value between 0 and the 2n where n is the size of the array.Create an
implementation for the following sort operations.
a.Bubble sort
b.Insertion sort
c.Merge - sort
d.Quicksort
e.Counting sort
f.Radix - sort
g.Heap - sort
int main()
{
	int n = 100000; //set the size of the array
	int arr[n]; //create an array
	srand(time(NULL)); //seed the random number generator
	for (int i = 0; i < n; i++) //for each element in the array
		arr[i] = rand() % n; //set the element to a random number
	int arr_size = sizeof(arr) / sizeof(arr[0]); //set the size of the array
	clock_t start, end; //create a clock
	start = clock(); //start the clock
	bubbleSort(arr, arr_size); //set the bubbleSort to the array
	end = clock(); //end the clock
	cout << "Bubble Sort: " << endl; //print the bubble sort
	cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl; //print the time
	start = clock(); //start the clock
	insertionSort(arr, arr_size); //set the insertionSort to the array
	end = clock(); //end the clock
	cout << "Insertion Sort: " << endl; //print the insertion sort
	cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl; //print the time
	start = clock(); //start the clock
	mergeSort(arr, 0, arr_size - 1); //set the mergeSort to the array
	end = clock(); //end the clock
	cout << "Merge Sort: " << endl; //print the merge sort
	cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl; //print the time
	start = clock(); //start the clock
	quickSort(arr, 0, arr_size - 1); //set the quickSort to the array
	end = clock(); //end the clock
	cout << "Quick Sort: " << endl; //print the quick sort
	cout << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << endl; //print the time
	start = clock(); //start the clock
	countingSort(arr, arr_size); //set the countingSort to the array
	end = clock(); //end the clock
	cout << "Counting Sort: " << endl; //print the counting sort
	cout << "Time:"
}
*/