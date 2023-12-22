// Write a function that sorts these books based on
// their category and arrange them in that array. 
// Your sorting algorithm should have the complexity O (NlogN) 
// void Sort (Book book [], int N); 
// b) Write a function that searches a book
// from the array based on name of the book. 
// Your searching algorithm should have the complexity O (log N) 
// void Search (Book book [], int N, string search);

// class Book
// {
// 	private:
// 		string name;
// 		int key;
// 		string cat;
// 		float price;
		
// 	public:
		
// 		Book()
// 		{
			
// 		};
		
// 		Book(string name, int key, string cat, float price)
// 		{
// 			this->name = name;
// 			this->key = key;
// 			this->cat = cat;
// 			this->price = price;
// 		}
		
// 		void shellsort(Book book[], int size)
// 		{
// 			for(int gap = size / 2; gap >= 0; gap /= 2)
// 			{
// 				for(int i = gap; i < size; i++)
// 				{
// 					Book temp = book[i];
					
// 					int j;
					
// 					for(j = i; j >= gap && book[j - gap].cat > temp.cat; j -= gap)
// 					{
// 						book[j] = book[j - gap];
// 					}
					
// 					book[j] = temp;
// 				}
// 			}
// 		}
		
// 		int binarysearch(Book book[], int size, string search)
// 		{
// 			int l = 0, h = size - 1;
			
// 			while(l <= h)
// 			{
// 				int c = l + (h - 1) / 2;
				
// 				if(book[c].cat == search)
// 				{
// 					return c;
// 				}
// 				else if(book[c].cat > search)
// 				{
// 					h = c - 1;
// 				}
// 				else if(book[c].cat < search)
// 				{
// 					l = c + 1;
// 				}
// 			}
// 			return -1;
// 		}
// };

// The academic department of FAST University holds
// the batch-wise record of their students. Each 
// record consists of student_roll_number and CGPA. 
// Note that, roll number as well as CGPA
// (Assuption: CGPA is unique in this case) cannot be repeated.
// Your task is to implement a data structure through which
// a user can get the record of a student with minimum CGPA in constant time.
// Following is the list of mandatory operations:
//     insert ()
//     delete ()
//     getMinCGPA() 
// Example: 
// Student ob = new Student (); 
// ob.insert(1234,2.5); 
// ob.insert (1435,3.25); 
// ob.insert(1123,2.75); 
// ob.getMinCGPA(); // returns 2.5

// class Node
// {
// 	public:
// 		int roll;
// 		float cgpa;
	
// 		Node()
// 		{
			
// 		};
		
// 		Node(int roll, float cgpa)
// 		{
// 			this->roll = roll;
// 			this->cgpa = cgpa;
// 		}
// };

// class HashTable
// {
// 	public:
// 		Node ** Table;
// 		float mincgpa;
		
// 		HashTable()
// 		{
// 			Table = new Node* [40];
// 			mincgpa = 4.00;		
// 		};
		
// 		int HashFormula(float cgpa)
// 		{
// 			return ((cgpa * 10) - 10);	
// 		}
		
// 		void insert(int roll, float cgpa)
// 		{
// 			Node * n = new Node(roll, cgpa);
			
// 			if(mincgpa > cgpa)
// 			{
// 				mincgpa = cgpa;
// 			}
			
// 			int index = HashFormula(cgpa);
			
// 			Table[index] = n;
// 		}			
		
// 		void deletedata(int roll, float cgpa)
// 		{
// 			int index = HashFormula(cgpa);
			
// 			Table[index] = NULL;
// 		}
		
// 		float findmin()
// 		{
// 			int index = HashFormula(mincgpa);
			
// 			return Table[index]->cgpa;
// 		}
// };

// A better approach could be the store all the data in a
// priority queue since we can get the data of least cgpa
// in constant time

// a) We are inserting N nodes into an AVL tree. 
//Will this insertion procedure take O (log n) 
// rotations? Answer with Yes or No and briefly justify your answer.

// Even in the worst case senario the time complexity will be 0(log N)
// Since Each insertion requires constant number of rotations to maintain
// the balance of the tree

// b) We want to insert the keys from the set {1, 2, 3, 4, 5, 6, 7}
//into an initially empty AVL tree. 
// What should be the order of insertion such that 
//we do not have to perform any rotations? 

//                              4
//                             / \
//                            2   6
//                           / \ / \
//                          1  3 5  7

// Some FAST-NUCES students want to develop an ASCII
// code-based dictionary app for their Final Year Project.  
// This app should allow the users to perform the following operations: 
// a) Add_Record () 
// This function will take a string input from user
// and add into the dictionary. For adding the string user
// will use a unique hash function k MOD 100
// (table size must be 100, for k user will
// calculate the SUM of ASCII character of that word). 
// b) Word_Search ()  
// User will only pass a single string.
// If string is not available then generate an error message. 
// c) Print_Dictionary () 
// Users can also display the complete dictionary. 
// Note: Use Separate Chaining in case of collisions. 

// class Node
// {
// 	public:
// 		string input;
// 		Node * next;
		
// 		Node()
// 		{
// 			next = NULL;
// 		};
		
// 		Node (string input)
// 		{
// 			this->input = input;
// 			next = NULL;
// 		}
// };

// class HashTable
// {
// 	public:
// 		Node ** Table;
	
// 		HashTable()
// 		{
// 			Table = new Node* [100];	
// 		}		
		
// 		int hashing(string input)
// 		{
// 			int sum = 0;
			
// 			for(int i = 0; i < input.length(); i++)
// 			{
// 				sum += input[i];
// 			}
			
// 			return sum % 100;
// 		}

// 		void add_record(string input)
// 		{
// 			Node * n = new Node(input);
			
// 			int index = hashing(input);
			
// 			if(Table[index] == NULL)
// 			{
// 				Table[index] = n;
				
// 				return;
// 			}
			
// 			Node * temp = Table[index];
			
// 			while(temp->next != NULL)
// 			{
// 				temp = temp->next;
// 			}
			
// 			temp->next = n;
// 		}

// 		void word_search(string input)
// 		{
// 			int index = hashing(input);
			
// 			if(Table[index] == NULL)
// 			{
// 				cerr << "String doesn't Exist " << endl;
				
// 				return;
// 			}
			
// 			Node * temp = Table[index];
			
// 			while(temp != NULL)
// 			{
// 				if(temp->input == input)
// 				{
// 					cout << "String Found" << endl;
					
// 					return;
// 				}
// 				temp = temp->next;
// 			}
			
// 			cerr << "String doesn't Exist " << endl;
// 		}

// 		void print_dictionary()
// 		{
// 			for(int i = 0; i < 100; i++)
// 			{
// 				Node * temp = Table[i];
				
// 				cout << i << ": " << endl;
				
// 				if(temp != NULL)
// 				{
// 					while(temp != NULL)
// 					{
// 						cout << temp->input << " ";
						
// 						temp = temp->next;
// 					}
// 				}
				
// 				cout << endl;
// 			}
// 		}
// };

// Given a binary matrix where 0 represents water and 1 represents land
// and connected ones form an island, write a function to 
// count the total number of islands. For example, the figure given below 
// is a 10X10 binary matrix with total of five islands numbered 1 to 5.

// void issafe(int **array, int row, int col, int rows, int cols) 
// {
//     if (row >= 0 && col >= 0 && row < rows && col < cols && array[row][col] == 1) 
// 	{
//         array[row][col] = 0;
//         issafe(array, row + 1, col, rows, cols);
//         issafe(array, row - 1, col, rows, cols);
//         issafe(array, row, col + 1, rows, cols);
//         issafe(array, row, col - 1, rows, cols);
//         issafe(array, row + 1, col - 1, rows, cols);
//         issafe(array, row - 1, col + 1, rows, cols);
//         issafe(array, row + 1, col + 1, rows, cols);
//         issafe(array, row - 1, col - 1, rows, cols);
//     }
// }

// int islands(int **array, int rows, int cols) 
// {
//     int count = 0;

//     for (int i = 0; i < rows; i++) 
// 	{
//         for (int j = 0; j < cols; j++) 
// 		{
//             if (array[i][j] == 1) 
// 			{
//                 count++;
//                 issafe(array, i, j, rows, cols);
//             }
//         }
//     }

//     return count;
// }

// An imperfect binary min heap is one that is a valid 
// min heap but only till a certain height. For example, 
// the following imperfect min heap is
// a valid min heap till its height is 3.

// class Node
// {
// 	public:
// 		int data;
// 		Node * left;
// 		Node * right;
		
// 		Node()
// 		{
// 			left = NULL;
// 			right = NULL;
// 		}
		
// 		Node(int data)
// 		{
// 			this->data = data;
// 			left = NULL;
// 			right = NULL;
// 		}
// };

// class BT
// {
// 	public:
// 		Node * root;
		
// 		int Q6(Node * root, int currentheight)
// 		{
// 			if(root == NULL)
// 			{
// 				return 0;
// 			}
			
// 			int count = 0;
			
// 			if(root->left != NULL && root->right != NULL)
// 			{
// 				count = 1;
// 			}
			
// 			count += Q6(root->left, currentheight + 1);
// 			count += Q6(root->right, currentheight + 1);
			
// 			return count;
// 		}
// };

// Write a function that receives an integer value k and 
// reference to root of a binary tree and calculate 
// the number of routes in that binary tree whose sum of 
// node values is equal to k. The nodes can also 
// contain negative values. Note that the route does
// not necessarily have to start with the root. 

// class Node
// {
// 	public:
// 		int data;
// 		Node * left;
// 		Node * right;
		
// 		Node()
// 		{
// 			left = nullptr;
// 			right = nullptr;
// 		};
		
// 		Node(int data)
// 		{
// 			this->data = data;
// 			left = nullptr;
// 			right = nullptr;
// 		};
// };

// class BT
// {
// 	public:
// 		Node * root;
		
// 		int Q4(Node * head, int k)
// 		{
// 			if(head == NULL)
// 			{
// 				return 0;
// 			}
			
// 			int ans = 0;
			
// 			ans += Q4(head->left, k - head->data);
// 			ans += Q4(head->right, k - head->data);
			
// 			if(head->data == k)
// 			{
// 				ans += 1;
// 			}
			
// 			ans += Q4(head->left, k);
// 			ans += Q4(head->right, k);
			
// 			return ans;
// 		}	
// };