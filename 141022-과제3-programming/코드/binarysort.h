#ifndef _BINARY_SORT_H_
#define _BINARY_SORT_H_

/// Binary Insert Sort


template <>
void Sort<std::string>::BinaryInsertSort(std::string* data, const int n){

	int index = 0;
	std::string element;

	for (int i = 1; i < n; i++)
	{
		index = BinarySearch(data, data[i], i);

		if (index < i){

			element = data[i];
			memmove(data + index + 1, data + index, sizeof(std::string)* (i - index));
			data[index] = element;

		} // end of if

	} // end of for

}

template <>
void Sort<double>::BinaryInsertSort(double* data, const int n){

	int index = 0;
	double element;

	for (int i = 1; i < n; i++)
	{
		index = BinarySearch(data, data[i], i);

		if (index < i){

			element = data[i];
			memmove(data + index + 1, data + index, sizeof(double)* (i - index));
			data[index] = element;

		} // end of if

	} // end of for

}

template <typename T>
void Sort<T>::BinaryInsertSort(T* data, const int n){

	int index = 0;
	T element;

	for (int i = 1; i < n; i++)
	{
		index = BinarySearch(data, data[i], i);

		if (index < i){
		
			element = data[i];
			memmove(data + index + 1, data + index, sizeof(int)* (i - index));
			data[index] = element;
		
		} // end of if

	} // end of for

}


// End of Binary Insert Sort

/// Binary Search
template <>
int Sort<std::string>::BinarySearch(std::string* data, const std::string x, const int n){

	int left = 0;
	int right = n;
	int middle = n / 2;

	//	for (int i = 0; i < n; i++)
	//	cout << data[i] << " ";

	while (left < right)
	{
		middle = left + ((right - left) / 2);

		if (x.compare(data[middle]) == 1)
		{
			left = middle + 1;
		} // end of if  

		else if (x.compare(data[middle]) == 0)
		{
			return middle;
		}

		else
			right = middle;

		middle = left + ((right - left) / 2);

	} // end of while

	return middle;
}


template <>
int Sort<double>::BinarySearch(double* data, const double x, const int n){

	int left = 0;
	int right = n;
	int middle = n / 2;

	//	for (int i = 0; i < n; i++)
	//	cout << data[i] << " ";

	while (left < right)
	{
		middle = left + ((right - left) / 2);

		if (CompareDoubleAbsoulte(x, data[middle]) == 1)
		{
			left = middle + 1;
		} // end of if  

		else if (CompareDoubleAbsoulte(x, data[middle]) == 0)
		{
			return middle;
		}

		else
			right = middle;

		middle = left + ((right - left) / 2);

	} // end of while

	return middle;
}

template <typename T>
int Sort<T>::BinarySearch(T* data, const T x, const int n){

	int left = 0;
	int right = n;
	int middle = n / 2;

	//	for (int i = 0; i < n; i++)
	//	cout << data[i] << " ";

	while (left < right)
	{
		middle = left + ((right - left) / 2);

		if (x > data[middle])
		{
			left = middle + 1;
		} // end of if  

		else if (x == data[middle])
		{
			return middle;
		}

		else
			right = middle;

		middle = left + ((right - left) / 2);

	} // end of while

	return middle;
}

// End of Binary Search

#endif