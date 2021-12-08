#ifndef SIMPLELIST_L
#define SIMPLELIST_L

#include <stdio.h>
#include <stdlib.h>

#define GROWTH_FACTOR 5
template<typename T>
class SimpleList {
public:
	SimpleList(int initial){
		init(initial, GROWTH_FACTOR);
	}
	SimpleList(){
		init(GROWTH_FACTOR, GROWTH_FACTOR);
	}
	SimpleList(int initial, int growth_factor){
		init(initial, growth_factor);
	}
	
	SimpleList(const SimpleList<T> &old_list){
		init(old_list.pointer, old_list.growth_factor);
		for (int i=0; i<old_list.pointer; i++){
			add(old_list.data[i]);
		}
	}
	~SimpleList(){
		deallocator();
	}

	T& operator[](int index){
		return get(index);
	}

	SimpleList<T>& operator = (const SimpleList<T>& old_list){
		if (old_list == this){
			return this;
		}
		deallocator();
		init(old_list.pointer, old_list.growth_factor);
		for (int i=0; i<old_list.pointer; i++){
			add(old_list.data[i]);
		}
	}

	void put(int index, T t){
		if (index > this->array_size - 1){
			this->resize_to(index + this->growth_factor);
		}
		this->data[index] = t;
		if (this->pointer <= index){
			this->pointer = index + 1;
		}
	}
	
	void clear(){
		resize_to(0);
		resize_to(GROWTH_FACTOR);
	}

	void add(T t){
		put(this->pointer, t);
	}
	void remove(int index){
		if (index >= this -> pointer){
			return;
		}
		for (int i = index + 1; i < this -> pointer; i++){
			this -> data [i - 1] = this -> data[i];
		}
		this -> pointer --;
	}
	T pop(){
		if (this->pointer < 1){
			this->pointer = 1;
		}
		return this->data[--this->pointer];
	}

	T get(int index){
		return this->data[index];
	}

	int get_size(){
		return this->pointer;
	}

	int get_array_size(){
		return this->array_size;
	}

	int index_of(T t){
		for(int i=0; i < this->pointer; i++){
			if (this->data[i] == t){
				return i;
			}
		}
		return -1;
	}

	void resize_to(int size){
		int min = this->pointer;
		if (min > size){
			min = size;
		}
		T* tmp = allocator(size);;
		for (int i=0; i<min; i++){
			tmp[i] = this->data[i];
		}
		deallocator();

		this->data = tmp;
		this->array_size = size;
		if (this->pointer >= size){
			this->pointer = size;
		}
	}
private:
	T * allocator(int size){
		return (T *) malloc(sizeof(T) * size);
	}
	void deallocator(){
		if (this->data){
			free(this->data);
		}
	}
	void init(int initial, int growth_factor){
		this->array_size = initial;
		this->growth_factor = growth_factor;
		this->data = allocator(initial);
	}
	int array_size = 0;
	int pointer = 0;
	int growth_factor = 0;
	T* data;
};

#endif
