/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    Node front,rear;
    Codechef(){
        this.front=null;
        this.rear=null;
    }
    static class Node{
        int data;
        Node next;
        Node(int x){
            data=x;
            next=null;
        }
    }
  public void enqueue(int x){
      Node node=new Node(x);
      if(rear==null){
          front=rear=node;
          return;
      }
      rear.next=node;
      rear=node;
  }
  public void dequeue(){
      if(front==null){
          System.out.println("queue is empty");
          return;
      }
      front=front.next;
      if(front==null){
          rear=null;
      }
  }
  
    public  void print(){
        if(front==null){
            System.out.println("queue is empty");
        }
        Node temp=front;
        while(temp!=null){
            System.out.print(temp.data+" ");
            temp=temp.next;
        }
         System.out.println();
    }
	public static void main (String[] args) throws java.lang.Exception
	{
	 Codechef list=new Codechef();

	 list.enqueue(1);
	 list.enqueue(2);
	 list.enqueue(3);
list.print();
	 list.dequeue();
	 list.dequeue();
	 list.print();
	 list.dequeue();
	 list.print();


	}
}
