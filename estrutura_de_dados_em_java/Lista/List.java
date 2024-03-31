package Lista;

import Pilha.Stack;

//ordered list on elements of type T
public class List {

    // class structure of the node
    private class Node {
        int  index;

        //given to generic T type
        String data;
        //node type
        Node next;
        Node(String data) {
            this.data = data;
            this.next = null;
            this.index = indexCounter++;
        }
    }

    //attributes
    private Node first;
    private Node last;
    private int size;
    int indexCounter;

    //constructor
    public List() {
        this.first = null;
        this.last = null;
        this.size = 0;
        this.indexCounter = 0;
    }


    //get the index based on the text
    public int getIndexText(String data){
        int index = 0;
        Node current = first;
        //loop to go through the nodes
        while (current != null) {
            if(data.equals(current.data)){
                break;
            }
            index++;
            current = current.next;
        }
        return index;
    }


    // function to add data at specific place
    public void addSpecificPlace(String data, int index) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Indice fora dos limites da lista");
        }
        if (index == 0) {
            Node newNode = new Node(data);
            newNode.next = first;
            first = newNode;
            if (size == 0) {
                last = newNode;
            }
        } else {
            Node newNode = new Node(data);
            Node before = getNode(index - 1);
            newNode.next = before.next;
            before.next = newNode;
        }
        size++;
    }

    // function to remove a node from the list
    public void remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Indice fora dos limites da lista");
        }
        if (index == 0) {
            first = first.next;
            if (first == null) {
                last = null;
            }

        } else {
            Node before = getNode(index - 1);
            before.next = before.next.next;
            if (before.next == null) {
                last = before;
            }
        }
        size--;
    }

    // get node
    public String get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Indice fora dos limites da lista");
        }
        return getNode(index).data;
    }

    //function to edit element
    public void edit(String data,String newElement){
        Node current = first;
        while (current!=null){
            if(current.data.equals(data)){
                current.data = newElement;
                return;
            }
            current = current.next;
        }
    }

    // check if the list is empty
    public boolean empty() {
        return size == 0;
    }
    // get list size
    public int sizeList() {
        return size;
    }

    // add data to list
    public void addData(String data) {
        Node newNode = new Node(data);
        if (first == null) {
            first = newNode;
            last = newNode;
        } else {
            last.next = newNode;
            last = newNode;
        }
        size++;
    }

    // clear the list
    public void clear() {
        first = null;
        last = null;
        size = 0;
    }

    //search data
    public boolean search(String data_search){
        Node current = first;
        //loop to go through the nodes
        while (current != null) {
            if(current.data.equals(data_search)){
                return true;
            }
            System.out.println("index:"+current.index+" data:"+current.data + "");
            current = current.next;
        }
        return false;
    }

    // main method to obtain the data
    private Node getNode(int index) {
        Node current = first;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current;
    }

    // print data
    public void print() {
        Node current = first;
        //loop to go through the nodes
        while (current != null) {
            System.out.println("index:"+current.index+" data:"+current.data + "");
            current = current.next;
        }
        System.out.println();
    }
}
