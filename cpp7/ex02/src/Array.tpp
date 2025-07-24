///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
template<typename T>
Array<T>::Array() :_size(0), _array(NULL) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) {}

template<typename T>
Array<T>::Array(const Array &other) : _size(other._size) {
	if (this != &other) {
		_array = new T[other._size];
		for (size_t i = 0; i < other._size; i++)
			_array[i] = other._array[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	delete[] _array;
	_size = other._size;
	_array = new T[other._size];
	for (size_t i = 0; i < other._size; i++)
		_array[i] = other._array[i];

	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete[] _array;
}
///////////////////////////////////////////////////////////////////////////////]
template<typename T>
size_t Array<T>::size( void ) const {
	return _size;
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= _size)
		throw Array<T>::OutOfBounds();
	return _array[index];
}

template<typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= _size)
		throw Array<T>::OutOfBounds();
	return _array[index];
}

template<typename T>
const char* Array<T>::OutOfBounds::what() const throw() {
	return ERR2 "Trying to access element out of bounds" RESET;
}