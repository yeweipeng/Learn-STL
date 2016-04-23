#ifndef MYVECTOR_HPP_
#define MYVECTOR_HPP_
#include <stdexcept>

using namespace std;
template<class Type>
class MyVector {
public:
//--- Typedef -------------------------------------
	typedef size_t size_type;
//--- Constructor ---------------------------------
	MyVector(size_type n = 0): _len(n), _capacity(n), _data(NULL) {
		if (_len > 0) {
			_data = new Type[_len];
		}
	}
//--- Capacity -------------------------------------
	size_type size() {
		return _len;
	}
// 理论上的最大空间，但由于内存不足、栈空间不够大等的原因，在此之前分配也会失败
	size_type max_size() {
// 根据机器进程空间算出，全部都是Type的个数，不可能达到的
		return size_type(-1) / sizeof(Type);
	}
	size_type capacity() {
		return _capacity;
	}
	bool empty() {
		return _len == 0;
	}

//--- Element Access --------------------------------
	// 返回引用
	Type& operator [] (size_type n) {
		return _data[n];
	}

	Type& at(size_type n) {
		if (n >= 0 && n < _len) {
	// 内部使用重载符号
			return operator[](n);
		} else {
	// 标准异常
			throw out_of_range("[MyVector]access elemnt out of range");
		}
	}

	Type& front() {
		return operator[](0);
	}
	
	Type& back() {
		return operator[](_len - 1);
	}

//--- Modify ------------------------------------------
	void push_back(const Type& val) {
		if (_len + 1 > _capacity) { // more than
			_capacity *= 2;
			alloctor_new(_capacity);
		}
		operator[](_len++) = val;
	}

	void pop_back() {
		_len--;
	}

	void clear() {
		_len = 0;
	}

private:
//--- Memory ------------------------------------------
	void alloctor_new(size_type size) {
		if (size > _capacity) {
			Type* new_data = new Type[size];
			if (_data != NULL) {
				memcpy(new_data, _data, _len * sizeof(Type));
				delete _data;
			}
			_data = new_data;
		}
	}
private:
	Type* _data;
	size_type _len;
	size_type _capacity;
};

#endif
