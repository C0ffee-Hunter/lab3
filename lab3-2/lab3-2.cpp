#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Binary_Heap Heap(11);
	Iterator* dft;
	int arr1[100000], arr2[100000], i = 0, Size;

	Heap.insert(10);
	Heap.insert(9);
	Heap.insert(8);
	Heap.insert(7);
	Heap.insert(1);
	Heap.insert(6);
	Heap.insert(5);
	Heap.insert(4);
	Heap.insert(3);

	dft = Heap.constructor_DFT();
	cout << "First Heap " << "\n";
	if (dft->has_next()) {
		while (dft->has_next()) arr1[i++] = dft->next();
	}

	Size = Heap.get_size();
	cout << Size << "\n";
	for (i = 0; i < Size; i++) {
		cout << arr1[i] << " | ";
	}

	cout << "\n\n\n"<< "Second Heap" << "\n";
	Binary_Heap heap(0);
	Iterator* bft;

	heap.insert(1);
	heap.insert(6);
	heap.insert(2);
	heap.insert(3);
	heap.insert(8);
	heap.insert(7);
	heap.insert(4);
	heap.insert(5);

	i = 0;
	bft = heap.constructor_BFT();
	if (bft->has_next()) {
		while (bft->has_next()) arr2[i++] = bft->next();
	}
	for (i = 0; i < 9; i++) cout << arr2[i] << " | ";

	heap.remove(5);
	heap.contains(5);

	return 0;
}