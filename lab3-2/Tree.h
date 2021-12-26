#pragma once
#include <iostream>

class Iterator {
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
	virtual ~Iterator() {};
};


template <class T>

class Stack {
private:

	class Stack_For_elements {
	private:
		T data;
		Stack_For_elements* next;

	public:

		Stack_For_elements(T  data = 0, Stack_For_elements* next = NULL) : next(next), data(data)
		{ }
		~Stack_For_elements() = default;

		void NewNext(Stack_For_elements* newnext) {
			this->next = newnext;
		}


		void NewData(T newdata) {
			this->data = newdata;
		}


		Stack_For_elements* getNext() {
			return this->next;
		}

		T getElemdata() {
			return this->data;
		}

		T getNextdata() {
			if (this->next == NULL) {
				return 0;
			}
			else
				return this->next->data;
		}

		Stack_For_elements* toNULL() {
			return this->next = NULL;
		}




	};

	Stack_For_elements* head, * last;

public:

	Stack()
	{
		head = NULL;
	}

	~Stack()
	{
		while (!Stack_isEmpty()) {
			Stack_pop();
		}
	}

	void Stack_pop() {
		if (head == NULL) {
			throw std::runtime_error("The list NULL\n");
		}
		else {
			Stack_For_elements* cur = head;
			head = head->getNext();
			delete cur;
		}
	};

	void Stack_push(T data) {
		if (head == NULL) {

			Stack_For_elements* cur = new Stack_For_elements(data);
			head = cur;
			last = head;

		}
		else {
			Stack_For_elements* tmp = new Stack_For_elements(data);
			Stack_For_elements* cur = head;
			this->head = tmp;
			this->head->NewNext(cur);
		}
	};

	bool Stack_isEmpty() { 
		if (head == NULL) { 
			return 1;
		}
		else {
			return 0;
		}
	};

	T peek() {

		if (Stack_isEmpty()) {
			throw std::out_of_range("error not found");
		}
		else {
			return head->getElemdata();
		}

	};
};

template <class T>

class Queue {
private:
	class Queue_For_elements {


	public:
		T data;;
		Queue_For_elements* next;
		Queue_For_elements* head, * last;
		Queue_For_elements(T data = 0, Queue_For_elements* next = NULL, Queue_For_elements* last = NULL, Queue_For_elements* head = NULL) : next(next), data(data), last(last), head(head)
		{ }
		~Queue_For_elements() = default;

		void NewNext(Queue_For_elements* newnext) {
			this->next = newnext;
		}


		void NewData(T newdata) {
			this->data = newdata;
		}


		Queue_For_elements* getNext() {
			return this->next;
		}


		T getdata() {
			return this->data;
		}

		T getNextdata() {
			if (this->next == NULL) {
				return 0;
			}
			else
				return this->next->data;
		}

		Queue_For_elements* toNULL() {
			return this->next = NULL;
		}

		T haveHead() {

			return head->data;
		}
	};
	Queue_For_elements* head, * last;

public:
	Queue()
	{
		head = NULL;
		last = NULL;
	}

	~Queue()
	{
		while (!Queue_isEmpty()) {
			dequeue();
		}
	}

	void dequeue() {
		if (head == NULL) {
			throw std::runtime_error("The list NULL\n");
		}
		else {
			Queue_For_elements* cur = head;
			head = head->next;
			delete cur;
		}
	}

	void enqueue(T data) {
		if (head == NULL) {

			Queue_For_elements* cur = new Queue_For_elements(data);
			head = cur;
			last = head;

		}
		else {
			Queue_For_elements* cur = new Queue_For_elements(data);

			last->next = cur;
			last = cur;
		}
	}

	bool Queue_isEmpty() { 
		if (head == NULL) { 
			return 1;
		}
		else {
			return 0;
		}
	}

	T front() {
		if (Queue_isEmpty()) {
			throw std::out_of_range("The list NULL\n");

		}
		else {

			//Queue_For_elements* haveHead();

			return head->data;
		}
	}
};

class Tree_Element {
private:


public:

	int data;
	Tree_Element* left_Element, * parent_of_Element, * right_Element;
	Tree_Element(int data = 0, Tree_Element* left_Element = NULL, Tree_Element* right_Element = NULL, Tree_Element* parent_of_Element = NULL) : data(data), left_Element(left_Element), right_Element(right_Element), parent_of_Element(parent_of_Element) {}
	~Tree_Element() = default;


};

class Binary_Heap {
private:
	Tree_Element* root_of_heap;

public:
	int hight_of_heap, quantity_Last_el;
	Iterator* constructor_DFT() {
		return new DFT_iterator(root_of_heap);
	}

	Iterator* constructor_BFT() {
		BFT_iterator* new_bft_iterator = new BFT_iterator(root_of_heap);
		new_bft_iterator->queue->enqueue(root_of_heap);
		return new_bft_iterator;
	}

	class DFT_iterator : public Iterator
	{
	public:

		friend class Heap;

		DFT_iterator(Tree_Element*);

		~DFT_iterator();

		bool has_next() override;

		int next() override;

		Stack<Tree_Element*>* stack;

		Tree_Element* cur;
	};

	class BFT_iterator : public Iterator
	{
	public:
		friend class Heap;

		BFT_iterator(Tree_Element*);

		~BFT_iterator();

		bool has_next() override;

		int next() override;

		Queue<Tree_Element*>* queue;
		Tree_Element* cur;
	};

	size_t Size = 1;

	Binary_Heap() { 
		this->root_of_heap = NULL;

	}

	Binary_Heap(int data) { 
		Tree_Element* Element = new Tree_Element(data);
		this->root_of_heap = Element;
		hight_of_heap = 1; 
		quantity_Last_el = 1;

	}

	void swapSift(Tree_Element* cur, Tree_Element* next) {
		int tmp = cur->data;
		cur->data = next->data;
		next->data = tmp;
	}

	Tree_Element* parent_search(int tmp) {

		Tree_Element* ending_parent = root_of_heap;

		int tmp_lay = tmp;
		int tmp_Last = this->quantity_Last_el;

		if (this->quantity_Last_el > tmp) {
			tmp_lay = tmp_lay * 2;
		}

		while (tmp_lay != 2) {
			if (tmp_Last <= (tmp_lay / 2)) {

				ending_parent = ending_parent->left_Element;
				tmp_lay = tmp_lay / 2;
			}
			else {
				ending_parent = ending_parent->right_Element;
				tmp_Last = tmp_Last - tmp_lay / 2;
				tmp_lay = tmp_lay / 2;
			}
		}

		return ending_parent;
	}

	Tree_Element* findElem(int data) {
		Tree_Element* Elem = NULL;

		DFT_iterator* new_It;
		new_It = new DFT_iterator(root_of_heap);

		while (new_It->has_next()) {
			Elem = new_It->cur;
			if (new_It->next() == data) {
				delete new_It;
				return Elem;
			}
		}


		delete new_It;
		throw std::invalid_argument("error not found");
	}

	void siftDown(Tree_Element* tmp) {

		Tree_Element* wrong = tmp;


		if ((tmp->left_Element != NULL) && (tmp->right_Element != NULL)) {

			if ((tmp->data < tmp->right_Element->data) || (tmp->data < tmp->left_Element->data)) {

				if ((tmp->left_Element->data) > (tmp->right_Element->data)) {
					wrong = tmp->left_Element;
				}
				else {
					wrong = tmp->right_Element;
				}


			}
			else {
				return;
			}

		}
		else {
			if ((tmp->right_Element == NULL) && (tmp->left_Element != NULL)) {
				if (tmp->data < tmp->left_Element->data) {
					wrong = tmp->left_Element;
				}
				else {
					return;
				}
			}

			return;
		}

		swapSift(tmp, wrong);
		siftDown(wrong);

	}

	void siftUp(Tree_Element* tmp) {
		if (tmp->parent_of_Element == NULL) {
			return;
		}
		else {
			if (tmp->data > tmp->parent_of_Element->data) {
				swapSift(tmp, tmp->parent_of_Element);
				siftUp(tmp->parent_of_Element);
			}
			else {
				return;
			}
		}
	}

	void Heapify(Tree_Element* tmp) {
		if (tmp->parent_of_Element == NULL) {
			siftDown(tmp);
		}
		else
			if ((tmp->data) > (tmp->parent_of_Element->data)) {
				siftUp(tmp);
			}
			else {
				siftDown(tmp);
			}
	}

	void insert(int key)
	{

		if (root_of_heap == NULL) { 
			Tree_Element* elem = new Tree_Element(key);
			this->root_of_heap = elem;
			this->quantity_Last_el = 1;
			this->hight_of_heap = 1;

		}
		else {
			Tree_Element* tmp = new Tree_Element(key);
			Tree_Element* cur = root_of_heap;

			int last_layer = 1;
			this->quantity_Last_el++;

			for (int index = 0; index < hight_of_heap - 1; index++) {
				last_layer = last_layer * 2;
			}

			if (last_layer < this->quantity_Last_el) {
				this->quantity_Last_el = 1;
				this->hight_of_heap++;
				last_layer = last_layer * 2;
			}

			cur = parent_search(last_layer);

			if (cur->left_Element == NULL) {
				cur->left_Element = tmp;
				tmp->parent_of_Element = cur;
			}
			else {
				cur->right_Element = tmp;
				tmp->parent_of_Element = cur;
			}

			Heapify(tmp);
			Size++;
		}
	}

	void remove(int key) {

		Tree_Element* delete_elem = findElem(key);


		if (root_of_heap->left_Element == NULL && root_of_heap->right_Element == NULL) {
			delete root_of_heap;
			root_of_heap = NULL;
			hight_of_heap = 0; quantity_Last_el = 0;
		}

		int last_layer = 1;

		for (int index = 0; index < hight_of_heap - 1; index++) {
			last_layer = last_layer * 2;
		}

		Tree_Element* last_elem = parent_search(last_layer);

		if (last_elem->right_Element != NULL) {
			last_elem = last_elem->right_Element;
			last_elem->parent_of_Element->right_Element = NULL;
			quantity_Last_el--;
		}
		else {
			last_elem = last_elem->left_Element;
			last_elem->parent_of_Element->left_Element = NULL;
			quantity_Last_el--;
		}




		if (quantity_Last_el == 0) {
			quantity_Last_el = 1;
			hight_of_heap--;
			for (int index = 0; index < hight_of_heap - 1; index++) {
				quantity_Last_el = quantity_Last_el * 2;
			}

		}
		if (delete_elem == last_elem) { delete last_elem; }
		else {


			swapSift(last_elem, delete_elem);
			delete last_elem;
			Heapify(delete_elem);
			Size--;
		}

	}

	bool contains(int data) {
		try {
			findElem(data);
			return true;
		}
		catch (std::invalid_argument) {
			return false;
		}
	}

	size_t get_size()
	{
		return Size;
	}
};

Binary_Heap::DFT_iterator::DFT_iterator(Tree_Element* root_of_heap) {
	cur = root_of_heap;
	stack = new Stack<Tree_Element*>();
}

bool Binary_Heap::DFT_iterator::has_next() {
	return cur != NULL;
}

int Binary_Heap::DFT_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("error not found");
	}

	int tmp = cur->data;

	if (cur->right_Element != NULL) {
		stack->Stack_push(cur->right_Element);
	}

	if (cur->left_Element != NULL) {
		cur = cur->left_Element;
	}
	else {
		try {
			cur = stack->peek();
			stack->Stack_pop();
		}
		catch (std::out_of_range) {
			cur = NULL;
		}
	}

	return tmp;
}

Binary_Heap::DFT_iterator::~DFT_iterator() {
	delete stack;
}

Binary_Heap::BFT_iterator::BFT_iterator(Tree_Element* root_of_heap) {
	cur = root_of_heap;
	queue = new Queue<Tree_Element*>();
}

bool Binary_Heap::BFT_iterator::has_next() {
	return cur != NULL;
}

int Binary_Heap::BFT_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("error not found");
	}

	int tmp = cur->data;

	if (cur->left_Element != NULL) {
		queue->enqueue(cur->left_Element);
	}

	if (cur->right_Element != NULL) {
		queue->enqueue(cur->right_Element);
	}

	queue->dequeue();

	try {
		cur = queue->front();


	}
	catch (std::out_of_range) {
		cur = NULL;
	}

	return tmp;
}

Binary_Heap::BFT_iterator::~BFT_iterator() {
	delete queue;
}
