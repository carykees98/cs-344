#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// In case you want to check what the function is doing
void print_array(int A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Inserts an integer into a sorted array of integers
void insert(int A[], int n, int num)
{
	int i;
	for (i = 0; i < n && A[i] <= num; i++)
		;
	for (; i < n; i++)
	{
		int temp = A[i];
		A[i] = num;
		num = temp;
	}
	A[i] = num;
}

// Sorts an array
void insertionSort(int A[], int n)
{
	for (int i = 0; i < n; i++)
		insert(A, i, A[i]);
}

// Removes an integer from a sorted array of integers
int remove(int A[], int n, int num)
{
	int i;
	for (i = 0; i < n && A[i] < num; i++)
		;
	if (A[i] > num)
		return n;
	for (i++; i < n; i++)
	{
		A[i - 1] = A[i];
	}
	return i - 1;
}

// Finds index where key occurs in a sorted array, or returns -1 if not there
int indexOf_iter(int a[], int lo, int hi, int key)
{
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		if (key < a[mid])
			hi = mid - 1;
		else if (key > a[mid])
			lo = mid + 1;
		else
			return mid;
	}
	return -1;
}

// Sorts an array of integers
void selectionSort(int A[], int n)
{
	for (int j = n - 1; j > 0; j--)
	{
		int m = 0;
		for (int i = 0; i <= j; i++)
			if (A[m] < A[i])
				m = i;
		if (m != j)
		{
			int temp = A[m];
			A[m] = A[j];
			A[j] = temp;
		}
	}
}

// Searches for all the elements in a sorted array, one by one
// If it ever doesn't find one, it returns a message
// Of course it finds them all, because it searches for things that are there
// So this function is worthless
void binSearches(int A[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (indexOf_iter(A, 0, n - 1, A[i]) == -1)
		{
			count++;
		}
	if (count > 0)
		cout << "That is weird " << endl;
}

// Removes all the zeroes from a sorted array
// In a slow way
int rmzeroes(int A[], int n)
{
	for (int i = n; i >= 0; i--)
	{
		if (indexOf_iter(A, 0, n - 1, 0) == -1)
			return n;
		n = remove(A, n, 0);
	}
	return n;
}

// Continually doubles the first element of an array
// After each time it resorts the array
void keepDoubling(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		A[0] *= 2;
		selectionSort(A, n);
	}
}

// Partitions array around the first element
// Smaller elements to the left
// Larger elements to the right
void partition(int A[], int n)
{
	int p = A[0];
	int lo = 0, hi = n - 1;
	while (lo < hi)
	{
		while (A[lo + 1] <= p)
		{
			A[lo] = A[lo + 1];
			lo++;
		}
		while (A[hi] > p)
		{
			hi--;
		}
		if (lo + 1 < hi)
		{
			A[lo] = A[hi];
			A[hi] = A[lo + 1];
			lo++;
			hi--;
		}
	}
	A[lo] = p;
}

// Merges two sorted arrays into one sorted array
void merge(int A[], int B[], int C[], int n)
{
	int i = 0, j = 0, k = 0;
	while (i < n && j < n)
	{
		if (A[i] <= B[j])
		{
			C[k] = A[i];
			i++;
		}
		else
		{
			C[k] = B[j];
			j++;
		}
		k++;
	}
	while (i < n)
	{
		C[k] = A[i];
		i++;
		k++;
	}
	while (j < n)
	{
		C[k] = B[j];
		j++;
		k++;
	}
}

float run_function(string funcname, int num_num)
{
	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();

	unsigned seed = system_clock::now().time_since_epoch().count();
	uniform_int_distribution<int> u(0, 100);
	// uniform_int_distribution<int> u(0, INT_MAX-1);
	default_random_engine e(seed); // generates unsigned random integers

	int *A = new int[num_num];
	for (int i = 0; i < num_num; i++)
		A[i] = u(e);

	if (funcname == "insert")
	{
		int x = u(e);
		sort(A, A + num_num);
		start = high_resolution_clock::now();
		insert(A, num_num, x);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "insertionSort")
	{
		start = high_resolution_clock::now();
		insertionSort(A, num_num);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "remove")
	{
		int x = A[0];
		sort(A, A + num_num);
		start = high_resolution_clock::now();
		remove(A, num_num, x);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "indexOf_iter")
	{
		int x = u(e);
		sort(A, A + num_num);
		start = high_resolution_clock::now();
		indexOf_iter(A, 0, num_num - 1, x);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "selectionSort")
	{
		start = high_resolution_clock::now();
		selectionSort(A, num_num);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "binSearches")
	{
		sort(A, A + num_num);
		start = high_resolution_clock::now();
		binSearches(A, num_num);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "rmzeroes")
	{
		sort(A, A + num_num);
		for (int i = 0; i < num_num / 2; i++)
			A[i] = 0;
		start = high_resolution_clock::now();
		rmzeroes(A, num_num);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "keepDoubling")
	{
		for (int i = 0; i < num_num; i++)
			A[i] = A[i] / 2;
		start = high_resolution_clock::now();
		keepDoubling(A, num_num);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "partition")
	{
		start = high_resolution_clock::now();
		partition(A, num_num);
		stop = high_resolution_clock::now();
	}
	else if (funcname == "merge")
	{
		int *B = new int[num_num];
		int *C = new int[2 * num_num];
		for (int i = 0; i < num_num; i++)
			B[i] = u(e);
		sort(A, A + num_num);
		sort(B, B + num_num);
		start = high_resolution_clock::now();
		merge(A, B, C, num_num);
		stop = high_resolution_clock::now();
		delete[] B;
		delete[] C;
	}
	else
	{
		cout << "No such function " << endl;
		return -1;
	}

	delete[] A;
	auto duration = duration_cast<microseconds>(stop - start);
	float dur = duration.count();
	return dur;
}

int main()
{
	int num_iter;	 // Number of iterations
	int num_num;	 // Number of numbers in array
	string funcname; // Which function the user wants to run
	float dur, old_dur = 1, ratio;
	cout << "How many iterations? ";
	cin >> num_iter;
	cout << "How many numbers to start with? ";
	cin >> num_num;
	cout << "Which function are you running? ";
	cin >> funcname;

	for (int i = 0; i < num_iter; i++)
	{
		dur = run_function(funcname, num_num);
		if (dur == -1)
			return 0;
		ratio = dur / old_dur;
		cout << "Numbers: " << num_num << ", "
			 << "Time: " << dur / 1000000 << ",  "
			 << "Ratio: " << ratio << endl;
		old_dur = dur;
		num_num = 2 * num_num;
	}
	return 0;
}
