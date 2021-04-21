class Array<E> {
    private static final int DEFAULT_CAPACITY = 10;
    private int size;
    private Object[] elements;

    public Array() {
        elements = new Object[DEFAULT_CAPACITY];
        size = 0;
    }

    public void insert(E e, int pos){
        if (pos < 0 || pos > size)
            return;
        for (int i = size ; i >= pos ; i--)
            elements[i+1] = elements[i];
        elements[pos] = e;
        size++;
    }

    public void delete(int pos){
        if (pos < 0 || pos > size)
            return;
        for (int i = pos ; i <= size ; i++)
            elements[i] = elements[i+1];
        size--;
    }

    public boolean search(E e){
        for (int i = 0 ; i < size ; i++)
            if (elements[i] == e)
                return true;
        return false;
    }

    public void printArray(){
        System.out.print("[ ");
        for (int i = 0 ; i < size ; i++)
            System.out.print(elements[i] + " ");
        System.out.print("]\n");
    }

    public static void main(String[] args) {
        Array<Integer> array = new Array<>();
        array.insert(5, 0);
        array.insert(10, 1);
        array.insert(15, 2);
        array.insert(20, 3);
        array.delete(3);
        System.out.println(array.search(15));
        System.out.println(array.search(20));
        array.printArray();
    }
}
