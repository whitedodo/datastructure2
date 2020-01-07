
/// Bubble Sort

template <>
void Sort<std::string>::BubbleSort(std::string* data, const int n){

	int i, j;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (data[j].compare(data[j + 1]) == 1)
				Swap(data, j, j + 1);

			j++;
		} // end of while

		i++;
	} // end of while

}

template <>
void Sort<double>::BubbleSort(double* data, const int n){

	int i, j;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (CompareDoubleAbsoulte(data[j], data[j + 1]) == 1)
				Swap(data, j, j + 1);

			j++;
		} // end of while

		i++;
	} // end of while

}

template <typename T>
void Sort<T>::BubbleSort(T* data, const int n){

	int i, j;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (data[j] > data[j + 1])
				Swap(data, j, j + 1);

			j++;
		} // end of while

		i++;
	} // end of while

}

// End of Bubble Sort

/// Selection Sort


template <>
void Sort<std::string>::SelectionSort(std::string* data, const int n){

	int i, j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (data[i].compare(data[j]) == 1)
				Swap(data, i, j);

			j++;
		} // end of while

		i++;
	} // end of while

}

template <>
void Sort<double>::SelectionSort(double* data, const int n){

	int i, j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (CompareDoubleAbsoulte(data[i], data[j]) == 1)
				Swap(data, i, j);

			j++;
		} // end of while

		i++;
	} // end of while

}

template <typename T>
void Sort<T>::SelectionSort(T* data, const int n){

	int i, j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (data[i] > data[j])
				Swap(data, i, j);

			j++;
		} // end of while

		i++;
	} // end of while

}
// End of Selection Sort

