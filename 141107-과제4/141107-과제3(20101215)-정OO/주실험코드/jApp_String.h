
template <typename T>
int JApp<T>::IsFileLoading(){

	if (!IsFileExist(GetTypeOfFilename(TYPE_FAMILY_NAME)))
		return false;

	if (!IsFileExist(GetTypeOfFilename(TYPE_FULL_NAME)))
		return false;

	return true;
}