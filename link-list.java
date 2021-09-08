// we can do it also;;;
// class Node{
// 		int data;
// 		Node next;
// 		Node(int d){
// 			data=d;
// 			next=null;
// 		}
// }
// public class Linkedlist{
//     Node head;
//     public static void main(String [] args){
//         Linkedlist list=new Linkedlist();
//         list.head=new Node(1);
//         Node second=new Node(2);
//         Node third=new Node(3);
//         list.head.next=second;
//         second.next=third;
//         while(list.head!=null){
//             System.out.print(list.head.data);
//             list.head=list.head.next;
//         }
//     }
// }
class Linkedlist{
	Node head;
	static class Node{
		int data;
		Node next;
		Node(int d){
			data=d;
			next=null;
		}
	}
	public static void main(String[] args) {
		Linkedlist list=new Linkedlist();
		list.head=new Node(1);
		Node second=new Node(2);
		Node third=new Node(3);
		list.head.next=second;
		second.next=third;

		while(list.head!=null){
			System.out.print(list.head.data);
			list.head=list.head.next;
		}
	}
}
