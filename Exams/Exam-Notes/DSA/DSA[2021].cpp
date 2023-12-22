//Q-2
// You are given two singly linked lists L1 and L2. 
// Write a function to Delete from list L1, nodes 
// whose positions are to be found in an ordered list L2 possible empty.
// For instance, if L1 = (A B C D E) and L2 = (2 4 8), 
// then the second and the fourth nodes are to be deleted from list L1
// (the eighth node does not exist), and after deletion, L1= (A C E). 

// class Node
// {
// 	public:
// 		int data;
// 		Node * next;
		
// 		Node()
// 		{
// 			next = NULL;
// 		}
		
// 		Node(int data)
// 		{
// 			this->data = data;
// 			next = NULL;
// 		}
// };

// class LinkedList
// {
// 	public:
// 		Node * head;
		
// 		void append(int data)
// 		{
// 			Node * n = new Node(data);
			
// 			if(head == NULL)
// 			{
// 				head = n;
				
// 				return;
// 			}
			
// 			Node * temp = head;
			
// 			while(temp->next != NULL)
// 			{
// 				temp = temp->next;
// 			}
			
// 			temp->next = n;	
// 		}	
		
// 		void deletebyindex(int index)
// 		{
// 			int count = 0;
			
// 			if(head == NULL)
// 			{
// 				return;
// 			}
			
// 			Node * temp = head;
			
// 			while(temp->next != NULL)
// 			{
// 				if(count + 1 == index)
// 				{
// 					Node * t = temp;
					
// 					temp->next = temp->next->next;
					
// 					t = NULL;
					
// 					delete t;
// 				}
// 				temp = temp->next;
				
// 				count++;
// 			}
// 		}
		
// 		void deleteathead()
// 		{
// 			Node * del = head;
			
// 			head = head->next;
			
// 			del = NULL;
			
// 			delete del;
// 		}
		
// 		void display()
// 		{
// 			Node * temp = head;
			
// 			while(temp != NULL)
// 			{
// 				cout << temp->data << " ";
				
// 				temp = temp->next;
// 			}
			
// 			cout << endl;
// 		}
		
// 		void Q(LinkedList *& L1, LinkedList *& L2)
// 		{
// 			Node * temp = L2->head;
			
// 			while(temp != NULL)
// 			{
// 				L1->deletebyindex(temp->data);
				
// 				temp = temp->next;
// 			}
// 		}
// };

// int main()
// {
// 	LinkedList * L1 = new LinkedList();
	
// 	LinkedList * L2 = new LinkedList();
	
// 	L1->append(1);
// 	L1->append(2);
// 	L1->append(3);
// 	L1->append(4);
// 	L1->append(5);
// 	L1->append(6);
// 	L1->append(7);
// 	L1->append(8);
// 	L1->append(9);
// 	L1->append(10);
	
// 	L2->append(2);
// 	L2->append(5);
// 	L2->append(1);	
	
// 	L1->display();
	
// 	L1->Q(L1, L2);
	
// 	L1->display();
// }