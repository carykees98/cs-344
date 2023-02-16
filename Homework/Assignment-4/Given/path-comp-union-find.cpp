#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

class UF
{
private:
	int *id;	 // access to component id
	int size;	 // Number of nodes
	int counter; // number of components
	int *sz;	 // size of component for roots
	// int *rank; // longest path in tree for roots
	// int *height;
	int get_height(int p);

public:
	UF(int n);
	int count() { return counter; }
	bool connected(int p, int q) { return find(p) == find(q); }
	int find(int p);
	void unions(int p, int q);
	void print();
	// void print_ranks();
	int max_height();
	~UF() { delete[] id; }
};

UF::UF(int n)
{
	counter = n;
	size = n;
	id = new int[n];
	for (int i = 0; i < n; i++)
		id[i] = i;
	sz = new int[n];
	for (int i = 0; i < n; i++)
		sz[i] = 1;
	// rank = new int[n];
	// for (int i=0; i<n; i++)
	//     rank[i] = 0;
}

int UF::find(int p)
{
	// follow links to find root
	if (p != id[p])
	{
		id[p] = find(id[p]);
		return id[p];
	}
	else
		return p;
}

void UF::unions(int p, int q)
{
	// put p and q in the same component
	int i = find(p);
	int j = find(q);

	// check if p and q are already in the same component
	if (i == j)
		return;

	// make smaller root point to larger one
	if (sz[i] < sz[j])
	{
		id[i] = j;
		sz[j] += sz[i];
		// if (rank[i] >= rank[j])
		//     rank[j] = rank[i] + 1;
	}
	else
	{
		id[j] = i;
		sz[i] += sz[j];
		// if (rank[j] >= rank[i])
		//     rank[i] = rank[j] + 1;
	}

	counter--;
}

void UF::print()
{
	for (int i = 0; i < size; i++)
		cout << i << " points to " << id[i] << endl;
}

// void UF::print_ranks()
//{
//     cout << "Ranks: ";
//     for (int i=0; i<size; i++)
//         if (id[i] == i)
//             cout << rank[i] << " ";
//     cout << endl;
// }

int UF::get_height(int p)
{
	int h = 0;
	for (int q = p; id[q] != q; q = id[q])
		h++;
	return h;
}

int UF::max_height()
{
	int h = 0;
	int p_height;
	for (int p = 0; p < size; p++)
	{
		p_height = get_height(p);
		if (p_height > h)
			h = p_height;
	}
	return h;
}

int main()
{
	int N;
	cout << "How many? ";
	cin >> N;
	UF uf(N);

	for (int i = 0; i < 12; i++)
	{
		int p, q;
		cin >> p;
		cin >> q;
		if (uf.connected(p, q))
			continue;
		uf.unions(p, q);
		// cout << "(" << p << "," << q << ") ";
	}
	// cout << endl;
	cout << "There are " << uf.count() << " components" << endl;
	cout << "The maximum height is " << uf.max_height() << endl;
	uf.print();

	return 0;
}