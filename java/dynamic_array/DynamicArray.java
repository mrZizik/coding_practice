class DynamicArray {
	
	private final int MIN_CAPACITY = 4;
	private final int GROWTH_FACTOR = 2;

	int arr[];

	int size = 0;
	
	public DynamicArray(int capacity) {
		arr = new int[calculateCapacity(capacity)];
	}

	//Get number of elements stored
	public int getSize() {
		return size;
	}

	//Get capacity of dynamic array
	public int getCapacity() {
		return arr.length;
	}

	public int calculateCapacity(int capacity) {
		if (capacity < 1) {
			System.exit(1);
		}

		int newCapacity = MIN_CAPACITY;

		while(capacity > newCapacity/GROWTH_FACTOR) {
			newCapacity *= GROWTH_FACTOR;
		}

		return newCapacity;
	}

	public void pushElement(int element) {
		resizeIfNeeded(getSize()+1);
		arr[size] = element;
		size++;
	}

	public int getElement(int index) {
		checkIndex(index);
		return arr[index];
	}

	public void setElement(int index, int value) {
		checkIndex(index);
		arr[index] = value;
	}

	public void remove(int index) {
		checkIndex(index);
		
		for (int i = index + 1; i < size; i++) {
			setElement(i-1, getElement(i));
		}

		size--;
	}

	private void checkIndex(int index) {
		if ((index < 0) || (index >= getSize())) {
			System.exit(1);
		}
	}

	public void resizeIfNeeded(int newSize) {
		if (getCapacity() <= newSize) {
			upsize();
		}
	}

	public void upsize() {
		int oldCapacity = getCapacity();
		int newCapacity = calculateCapacity(oldCapacity);

		int newArray[] = new int[newCapacity];

		for (int i = 0; i < size; i++) {
			newArray[i] = getElement(i);
		}

		arr = newArray;
	}

	public void print() {
		System.out.println("Size: " + getSize());
		System.out.println("Capacity: " + getCapacity());
		System.out.println("Items:");
		System.out.println("\tIndex: Value");
		for (int i = 0; i < size; i++) {
			System.out.println("\t" + i + ": " + getElement(i));
		}
	}
 }