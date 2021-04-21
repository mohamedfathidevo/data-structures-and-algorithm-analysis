import java.util.Arrays;

class MyList<E> {
    private int size = 0;
    private static final int DEFAULT_CAPACITY = 10;
    private Object[] elements;

    public MyList() {
        elements = new Object[DEFAULT_CAPACITY];
    }

    public void add(E e) {
        if (size == elements.length) {
            ensureCapacity();
        }
        elements[size++] = e;
    }

    private void ensureCapacity() {
        int newSize = elements.length * 2;
        elements = Arrays.copyOf(elements, newSize);
    }

    @SuppressWarnings("unchecked")
    public E get(int i) {
        if (i >= size || i < 0)
            throw new IndexOutOfBoundsException("invalid index");
        return (E) elements[i];
    }

    public void remove(int pos) {
        if (pos >= size || pos < 0)
            throw new IndexOutOfBoundsException("invalid index");
        for (int i = pos; i < elements.length - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
    }

    public void printArrayList() {
        for (int i = 0; i < size; i++) {
            System.out.print(elements[i] + " ");
        }
    }

    public static void main(String[] args) {
        MyList<Integer> myList = new MyList<>();
        myList.add(5);
        myList.add(10);
        myList.add(15);
        myList.add(30);
        myList.printArrayList();
    }

}
