class Main {
	public static void main(String[] args) {
		DynamicArray dynamicArray = new DynamicArray(2);
		dynamicArray.pushElement(1);
		dynamicArray.pushElement(2);
		dynamicArray.print();
		dynamicArray.pushElement(3);
		dynamicArray.pushElement(4);
		dynamicArray.print();

		dynamicArray.setElement(0, 125);
		dynamicArray.print();

		dynamicArray.remove(0);
		dynamicArray.print();
	}
}