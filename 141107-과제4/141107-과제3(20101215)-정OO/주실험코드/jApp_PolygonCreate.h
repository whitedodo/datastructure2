

template <typename T>
JPolygonList<T>* JApp<T>::PolyCreateList(const int valuetype, const int size){

	srand((unsigned int)time(NULL)); // Seed 값 사용

	int x = NULL, y = NULL;
	float num_x, num_y;
	float multi_x, multi_y;
	float result_x, result_y;

	// 생성(Create)
	JPolygonList<T>* pArr = new JPolygonList<T>[size + 1];

	// 데이터 할당
	for (int index = 0; index < size; index++)
	{
		JVector<T>* newNode = new JVector<T>();

		// value 구분
		switch (valuetype)
		{

		case WIZARD_INCREASE:
			result_x = (float)index;
			result_y = (float)index;

			newNode->SetVector((T)result_x, (T)result_y);

			break;

		case WIZARD_DECREASE:

			result_x = (float)(size - index);
			result_y = (float)(size - index);

			newNode->SetVector((T)result_x, (T)result_y);
			break;

		case WIZARD_RANDOM:

			num_x = (float)RandBox(TYPE_RAND_MID);
			num_y = (float)RandBox(TYPE_RAND_MID);

			multi_x = pow((float)RandBox(TYPE_RAND_MID), -1); // float Random
			result_x = multi_x * (float)num_x;

			multi_y = pow((float)RandBox(TYPE_RAND_MID), -1); // float Random
			result_y = multi_y * (float)num_y;

			newNode->SetVector((T)result_x, (T)result_y);

			break;

		} // end of switch

		// 노드 삽입
		pArr[index].position = newNode;
		pArr[index].index = index;

	}

	return pArr; // 반환(Polygon List)

}

template <typename T>
T* JApp<T>::PolyCreateView(JPolygonList<T>* data, const int critictype, const int size){

	T* pArr = new T[size + 1];
	JVector<T>* ptrvec;

	for (int i = 0; i < size; i++){

		ptrvec = data[i].position;

		switch (critictype)
		{
		case POLY_TYPE_X:
			pArr[i] = ptrvec->GetX();
			break;

		case POLY_TYPE_Y:
			pArr[i] = ptrvec->GetY();
			break;

		case POLY_TYPE_WEIGHT:
			pArr[i] = ptrvec->GetX() * ptrvec->GetY();
			break;

		default:
			break;

		} // end of switch

	} // end of for

	return pArr;
}


template <>
void JApp<double>::IndexToMerge(int* Arr, double* OriData, double* ChgData, const int n){

	int i, j;
	int index = 0;

	double NumX;
	double NumY;

	i = 0;
	while (i < n)
	{
		NumX = ChgData[i];

		j = 0;
		while (j < n)
		{
			NumY = OriData[j];

			if (CompareDoubleAbsoulte(NumX, NumY) == 0){
				Arr[index++] = j;
				break;
			}
			j++;
		}
		i++;
	}

}

template <typename T>
void JApp<T>::IndexToMerge(int* Arr, T* OriData, T* ChgData, const int n){

	int i, j;
	int index = 0;

	T NumX = NULL;
	T NumY = NULL;

	i = 0;
	while (i <= n)
	{
		NumX = ChgData[i];

		j = 0;
		while (j <= n)
		{
			NumY = OriData[j];

			if (NumX == NumY){
				Arr[index++] = j;
				break;
			}
			j++;
		}
		i++;
	}

}