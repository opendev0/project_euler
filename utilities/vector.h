#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#if defined(__cplusplus) && __cplusplus >= 201103
#include <initializer_list>
#endif

template<typename T>
class vector
{
public:
	explicit vector(std::size_t const size = 0) : _size(size)
	{
		this->_capacity = (size == 0) ? vector::_defCapacity : this->_size;
		this->_data = new T[this->_capacity];
	}
	
	vector(vector const &v)
	{
		this->_size = v._size;
		this->_capacity = v._capacity;
		this->_data = new T[v._capacity];
		
		this->copy_data(this->_data, v._data, this->_capacity);
	}
	
	vector(std::size_t const size, T &value) : _size(size)
	{
		if (size > 0) {
			this->_capacity = size;
			this->_data = new T[this->_capacity];
			
			for (size_t i = 0; i < size; ++i) {
				this->_data[i] = value;
			}
		} else {
			this->_capacity = vector::_defCapacity;
			this->_data = new T[vector::_defCapacity];
		}
	}
	
#if defined(__cplusplus) && __cplusplus >= 201103
	vector(std::initializer_list<T> const &list)
	{
		this->_size = this._capacity = list.size();
		this->_data = new T[this->capacity];
		
		unsigned int i = 0;
		for (T value : list) {
			this->_data[i++] = value;
		}
	}
#endif
	
	~vector()
	{
		delete[] this->_data;
	}
	
	vector &operator=(vector const &rhs)
	{		
		if (this != &rhs) {
			delete[] this->_data;
			
			this->_capacity = rhs._capacity;
			this->_size = rhs._size;
			this->_data = new T[this->_capacity];
			this->copy_data(this->_data, rhs._data, rhs._size);
		}
		
		return *this;
	}
	
	void push_back(T const &value)
	{
		if (this->_size == this->_capacity) {
			this->_capacity *= 2;
			T *tmp = new T[this->_capacity];
			
			this->copy_data(tmp, this->_data, this->_size);
			
			delete[] this->_data;
			this->_data = tmp;
		}
		
		this->_data[this->_size++] = value;
	}
	
	T pop_back()
	{
		return this->_data[--this->_size];
	}
	
	T &back()
	{
		return this->_data[this->_size - 1];
	}
	
	T const &back() const
	{
		return this->_data[this->_size - 1];
	}
	
	void resize(size_t const n, T const &value=T())
	{
		if (n == this->_size) return;
		
		T *tmp = new T[n];
		
		if (n < this->_size) {
			this->copy_data(tmp, this->_data, n);
		} else {			
			this->copy_data(tmp, this->_data, this->_size);
			
			for (int i = this->_size; i < n; ++i) {
				tmp[i] = value;
			}
		}
		
		delete[] this->_data;
		this->_data = tmp;
		this->_size = this->_capacity = n;
	}
	
	inline std::size_t size() const
	{
		return this->_size;
	}
	
	inline std::size_t capacity() const
	{
		return this->_capacity;
	}
	
	void clear()
	{
		delete[] this->_data;
		this->_data = new T[this->_defCapacity];
		
		this->_size = 0;
		this->_capacity = this->_defCapacity;
	}
	
	inline bool operator==(vector const &b) const
	{
		if (this->_size != b._size) return false;
		
		for (unsigned int i = 0; i < this->_size; ++i) {
			if (this->_data[i] != b._data[i]) return false;
		}
		
		return true;
	}
	
	T& operator[](std::size_t const index)
	{
		// TODO: Return first/last element? Enable exceptions?
		return this->_data[index];
	}
	
	T const &operator[](std::size_t const index) const
	{
		// TODO: Return first/last element? Enable exceptions?
		return this->_data[index];
	}

private:
	T *_data;
	std::size_t _size;
	std::size_t _capacity;
	
	static std::size_t const _defCapacity = 1;
	
	void copy_data(T *destination, T *source, size_t num)
	{
		for (size_t i = 0; i < num; ++i) {
			destination[i] = source[i];
		}
	}
};

#endif