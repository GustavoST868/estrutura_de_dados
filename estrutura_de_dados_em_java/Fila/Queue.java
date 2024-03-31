package Fila;

//class to build the queue structure
public class Queue {
    //class to build the node structure
    public static class Node{
        //node attributes
        String data;
        Node next;

        //constructor
        public Node(String data){
            this.data = data;
            this.next = null;
        }
    }

    //queue attributes
    private Node front;
    private Node back;

    //queue costructor
    public Queue(){
        this.front = null;
        this.back = null;
    }

    //check if the queue is empty
    public boolean isEmpty(){
        return front == null;
    }

    //function to add an element to the queue
    public void add_queue(String data){
        Node newNode = new Node(data);

        //if the queue is empty
        if(isEmpty()){
            front = newNode;
            back = newNode;
        }else{
            back.next = newNode;
            back = newNode;
        }
    }

    //function to dequeue an element from the list
    public void dequeue(){
        //if the queue is empty
        if(isEmpty()){
            System.out.println("A fila  vazia");
        }else{
            String  dataRemoved = front.data;
            if(front == back){
                front = null;
                back = null;
            }else{
                front = front.next;
            }
        }
    }

    //function to show the queue
    public void print(){
        //if the queue is empty
        if(isEmpty()){
            System.out.println("Fila vazia");
        }
        Node current = front;
        System.out.println("Fila:");

        //loop to traverse the queue and display the data
        while(current!=null){
            System.out.println(current.data);
            current = current.next;
        }
    }
}
