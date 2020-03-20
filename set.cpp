template<class T>
class Set {
private:
	T *arr;
	int size;
	int currentPosition;
public:
	// default constructor
	Set<T>() {
		arr = NULL;
		size = 0;
		currentPosition = 0;
	}
	// parameterized constructor by the default size of 100
	Set<T>(int size = 100) {
		if (size == 0) {
			size = size + 1;
		}
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			arr[i] = "\0";
		}
		this->size = size;
		currentPosition = 0;
	}
	// function to check whether the set is empty or not
	bool isEmpty() {
		if (currentPosition == 0) {
			return true;
		}
		return false;
	}
	// function for adding the new item in the set.
	
	void addItem(T item) {
		if (currentPosition == size) {

			T *tempArr = new T[size];
			for (int i = 0; i < size; i++) {
				tempArr[i] = arr[i];
			}
			delete[] arr;
			arr = new T[size * 2];
			for (int i = 0; i < size; i++) {
				arr[i] = tempArr[i];
			}
			delete[] tempArr;
			arr[currentPosition] = item;
			currentPosition++;
			size = size * 2;
		} else {
			arr[currentPosition] = item;
			currentPosition++;
		}
	}
	// function used to get to know about the presence of the element in the set
	bool isAlreadyInSet(T item) {
		if (!isEmpty()) {
			for (int i = 0; i < currentPosition; i++) {
				if (arr[i] == item) {
					return true;
				}
			}
		}
		return false;
	}
	// returns current size of the set
	int getSize() const {
		return size;
	}

	int getCurrentPosition() const {
		return currentPosition;
	}
	void ascendingOrder() {
		for (int i = 0; i < currentPosition; i++) {
			for (int j = 0; j < currentPosition; j++) {
				if (arr[i] < arr[j]) {
					T temp;
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	// function to print the set and has been used while testing
	void Print() {
		for (int i = 0; i < currentPosition; i++) {
			cout << arr[i] << " ";
		}
	}
};
