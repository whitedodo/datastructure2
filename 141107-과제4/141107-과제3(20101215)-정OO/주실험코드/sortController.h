
/// [Generalize] - Template

template <typename T>
Sort<T>::Sort()
{
}

template <typename T>
Sort<T>::~Sort()
{
}

template <>
Sort<int>::Sort()
{
}

template <>
Sort<int>::~Sort()
{
}


/// Swap
template <typename T>
void Sort<T>::Swap(T* data, int left, int right){

	T Temp = data[left];
	data[left] = data[right];
	data[right] = Temp;

}
// End of Swap
