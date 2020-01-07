

/// Heap Sort

template <>
void Sort<std::string>::HeapSort(std::string* data, const int n)
{
	int i = n / 2;
	while (i >= 1)
	{
		Adjust(data, i, n);
		i--;
	} // end of while

	i = n - 1;
	while (i >= 1)
	{
		Swap(data, 1, i + 1);
		Adjust(data, 1, i);

		i--;
	} // end of while

}

template <>
void Sort<double>::HeapSort(double* data, const int n)
{
	int i = n / 2;
	while (i >= 1)
	{
		Adjust(data, i, n);
		i--;
	} // end of while

	i = n - 1;
	while (i >= 1)
	{
		Swap(data, 1, i + 1);
		Adjust(data, 1, i);

		i--;
	} // end of while

}

template <typename T>
void Sort<T>::HeapSort(T* data, const int n)
{
	int i = n / 2;
	while (i >= 1)
	{
		Adjust(data, i, n);
		i--;
	} // end of while

	i = n - 1;
	while (i >= 1)
	{
		Swap(data, 1, i + 1);
		Adjust(data, 1, i);

		i--;
	} // end of while

}
// End of Heap Sort

/// Adjust

template <>
void Sort<std::string>::Adjust(std::string* data, const int root, const int n)
{
	int i;
	std::string element = data[root];

	i = 2 * root;

	while (i <= n)
	{
		if (i < n && data[i].compare(data[i + 1]) == -1)
			i++;

		if (data[i] <= element)
			break;

		data[i / 2] = data[i];

		i = i * 2;

	} // end of while

	data[i / 2] = element;

}

template <>
void Sort<double>::Adjust(double* data, const int root, const int n)
{
	int i;
	double element = data[root];

	i = 2 * root;

	while (i <= n)
	{
		if (i < n && CompareDoubleAbsoulte(data[i], data[i + 1]) == -1)
			i++;

		if (CompareDoubleAbsoulte(data[i], element) <= 0)
			break;

		data[i / 2] = data[i];

		i = i * 2;

	} // end of while

	data[i / 2] = element;

}

template <typename T>
void Sort<T>::Adjust(T* data, const int root, const int n)
{
	int i;
	T element = data[root];

	i = 2 * root;
	
	while (i <= n)
	{
		if (i < n && data[i] < data[i + 1])
			i++;

		if (data[i] <= element)
			break;

		data[i / 2] = data[i];

		i = i * 2;

	} // end of while

	data[i / 2] = element;

}
// end of Adjust
