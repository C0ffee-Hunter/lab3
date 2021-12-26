#include "pch.h"
#include "CppUnitTest.h"
#include "../../lab3-2/lab3-2/Tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForLab3
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(STACK)
		{
			Stack<int> stack;
			stack.Stack_push(22);
			stack.Stack_pop();

			bool check = 1;
			try
			{
				stack.Stack_pop();
			}
			catch (std::runtime_error)
			{
				check = 0;
			}
			Assert::IsFalse(check);


			for (int i = 1; i < 11; i++) {
				stack.Stack_push(i);
			}
			Assert::IsFalse(stack.Stack_isEmpty());

			for (int i = 10; i >= 1; i--) {
				Assert::AreEqual(i, stack.peek());
				stack.Stack_pop();
			}
			Assert::IsTrue(stack.Stack_isEmpty());

		}

		TEST_METHOD(QUEUE) {
			Queue<int> queue;
			queue.enqueue(22);
			queue.dequeue();
			bool check = true;
			try
			{
				queue.dequeue();
			}
			catch (std::runtime_error)
			{
				check = false;
			}
			Assert::IsFalse(check);

			for (int i = 1; i < 11; i++) {
				queue.enqueue(i);
			}
			Assert::IsFalse(queue.Queue_isEmpty());
			for (int i = 10; i >= 1; i--) {
				Assert::AreEqual(11 - i, queue.front());
				queue.dequeue();
			}

			Assert::IsTrue(queue.Queue_isEmpty());


		}


		TEST_METHOD(INSERT_REMOVE_CONTAINS) {

			Binary_Heap Heap(11);
			Iterator* dfs, * bfs;
			Heap.insert(10);
			Heap.insert(9);
			Heap.insert(8);
			Heap.insert(7);
			Heap.insert(6);
			Heap.insert(5);
			Heap.insert(4);
			Heap.insert(3);
			Assert::IsFalse(Heap.contains(22));
			Assert::IsTrue(Heap.contains(11));
			Heap.insert(22);
			Assert::IsTrue(Heap.contains(22));
			Heap.remove(3);
			Assert::IsFalse(Heap.contains(3));
			Heap.remove(22);
			Assert::IsFalse(Heap.contains(22));


		}


		TEST_METHOD(DFT_BFT_Iterators) {
			Binary_Heap Heap(11);
			Iterator* dft;
			Heap.insert(10);
			Heap.insert(9);
			Heap.insert(8);
			Heap.insert(7);
			Heap.insert(6);
			Heap.insert(5);
			Heap.insert(4);
			Heap.insert(3);
			int arr1[9], i = 0;
			dft = Heap.constructor_DFT();

			if (dft->has_next()) {
				while (dft->has_next()) { arr1[i++] = dft->next(); }
			}

			Assert::AreEqual(11, arr1[0]);
			Assert::AreEqual(10, arr1[1]);
			Assert::AreEqual(8, arr1[2]);
			Assert::AreEqual(4, arr1[3]);
			Assert::AreEqual(3, arr1[4]);
			Assert::AreEqual(7, arr1[5]);
			Assert::AreEqual(9, arr1[6]);
			Assert::AreEqual(6, arr1[7]);
			Assert::AreEqual(5, arr1[8]);
			delete dft;



			Binary_Heap heap(0);
			Iterator* bft;
			int Arr2[9];

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
				while (bft->has_next()) {
					Arr2[i++] = bft->next();
				}
			}
			i = 0;

			Assert::AreEqual(8, Arr2[i++]);
			Assert::AreEqual(5, Arr2[i++]);
			Assert::AreEqual(7, Arr2[i++]);
			Assert::AreEqual(4, Arr2[i++]);
			Assert::AreEqual(2, Arr2[i++]);
			Assert::AreEqual(1, Arr2[i++]);
			Assert::AreEqual(6, Arr2[i++]);
			Assert::AreEqual(0, Arr2[i++]);
			Assert::AreEqual(3, Arr2[i++]);
			delete bft;

		}


	};

}
