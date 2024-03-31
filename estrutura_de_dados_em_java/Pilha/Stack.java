package Pilha;

public class Stack {

    //attributes
    private Node top;
    private int size;
    private int  indexCounter;

    public Stack(){
        this.top = null;
        this.size = 0;
        this.indexCounter = 0;
    }

    //class node to store the data
    public class Node{
        //attributes
        private String data;
        private Node next;
        private int index;
        public Node(String data) {
            this.data = data;
            this.next = null;
            //add one more to each node created
            this.index = indexCounter++;
        }
    }

    //checks if the stack is empty
    public boolean isEmpty(){
        return (top==null);
    }

    //method for adding an element
    public  void addStack(String data){
        Node newNode = new Node(data);
        newNode.next = top;
        top = newNode;
        size++;
    }

    //edit data
    public void edit(String data,String newElement){
        if(isEmpty()){
            System.out.println("A lista está vazia");
        }else{
            Node current = top;
            while(current!=null){
                if(current.data.equals(data)){
                    current.data = newElement;
                    return;
                }
                current = current.next;
            }
        }
    }

    //unstack an element
    public void unstack(){
        if(isEmpty()){
            System.out.println("A lista está vazia");
        }else {
            top = top.next;
            size--;
        }
    }

    //get data
    public String getTop(){
        if(isEmpty()){
            System.out.println("A lista está vazia");
            return "";
        }else {
            return top.data;
        }
    }

    //print
    public void print(){
        if(isEmpty()){
            System.out.println("A lista está vazia");
        }else {
            System.out.println("Elementos da pilha:");
            Node current = top;
            while (null != current) {
                System.out.println("Index = " + current.index + " data = " + current.data);
                current = current.next;
            }
        }
    }
}
