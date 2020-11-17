#include<stdio.h>
#include<stdlib.h>
#define null 0

//defining a structure called Node with two properties
//one is data and other is the pointer of the next node
typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* head;//declering Linked list starting point
int length;

//intializing head and length of the linked list
void init(){
	head=null;
	length=0;
}

void insert_first(int item){
	//creating a new node
	Node* newNode=(Node*)malloc(sizeof(Node));
	// storing item in the new node's data property
	newNode->data = item;
	//pointing new node's next to the linked list's head
	newNode->next = head;
	//pointing head to the new node we just created
	head=newNode;
	length++;
	return;
}

void insert_last(int item){
	
	//creating a node called temp and intializing to the head
	Node* temp = head;
	
	//checking if the temp is null
	if(temp==null){
		// if temp node is null then we will call insert_first() fuction to insert the item and return
		insert_first(item);
		return;
	}
	
	//looping through from head to the last node(not to the end) of the linked list
	while(temp->next!=null){
		temp=temp->next;//after breaking the loop, temp will be the last node
	}
	//creating a new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	//storing item in new node's data
	newNode->data=item;
	//pointing temp's next to new node's next 
	newNode->next =temp->next;
	//pointing newNode to the temp's next
	temp->next=newNode;
	length++;
}



int insert_at(int item,int pos){
	
	//checking if the position is greater the length or less then 0
	if(pos<0 || pos>length) {
		//if the condition is true then return -1
        return -1;
    }
	//checking if the position is 0
	if(pos==0){
		//if positon is 0 we will use the insert_first function because of corner case and then return
		insert_first(item);
		return 1;
	}
	
	
	Node* temp=head;
	Node* prev;//creating a node pointer to store the previous node
	int i=0;//assignig i variable to track the position of the node
	
	// looping through all the nodes
	while(temp!=null){
		//when we the i is equal to positon we will break the loop
		if(i==pos){
			break;
		}
		//storing temp in prev to track the previous node of the given node positon 
		prev=temp;
		//pointing newNode to the temp's next
		temp=temp->next;//present node is assign to the next node by this
		i++;
	}
	
	//if the position is not there in the will loop then it will return -1
	if(i!=pos){
		return -1;
	}
	//else we found the position we will create a new node
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data = item;//storing item in the new node
	newNode->next = temp;//pointing new node's next to the temp
	prev->next = newNode;//pointing previous node's next to the new node
	length++;
	
	return 1;
	
}

int search(int key){
	Node* temp=head;
	int i=0;// declearing an Integer variable to track the node's index
	
	//looping through all the nodes
	while(temp!=null){
		
		//if the nodes data is equal to key then it will return the index positon 
		if(temp->data==key){
			return i;//returning the index of the node
		}
		
		temp=temp->next;//present node is assign to the next node by this
		i++;
	}
	//else it will return -1
	return -1;
}


Node* search_node(int key){
	Node* temp=head;
	
	while(temp!=null){
		// if the node's data id equal to key then it will return the whole index
		if(temp->data==key){
			return temp;
		}
		temp=temp->next;//present node is assign to the next node by this
	}
	//else it will return null
	return null;
}

void delete_first(){
	
	//checking if the node is empty, if empty then return
	if(head==null){
		return;
	}
	
	Node* temp=head;//assiging temp to the first node
	head=temp->next;//assinging head to the next node of the first node
	free(temp);//free the first node
	length--;//decrementing the length
}

void delete_last(){
	
	//checking if the node is empty, if empty then return
	if(head==null){
		return;
	}
	
	Node* temp=head;
	Node* prev;//creating a node pointer to store the previous node
	
	//looping through from head to the last node(not to the end) of the linked list
	while(temp->next!=null){
		//storing temp in prev to track the previous node of the current node positon 
		prev=temp;
		temp=temp->next;//present node is assign to the next node by this
	}
	
	//if there is only one item in the linked list then that block will execute
	if(temp==head){
		head=null;//assigning head to the null
		free(temp);// removing the only node of the linked list
		length--;
		return;
	}
	//else the previous node will point to the next node(NULL) of the last node
	prev->next= temp->next;
	free(temp);//then removeing the last node from memory
	length--;

}

void delete_at(int pos){
	
	//checking if the positon is greater or equal to length or less then 0
	//if it is true then return
	if(pos>=length || pos<0){
		return;
	}
	
	//if the positon is the first node then we will delete the first node by calling the delete_first fucntion and then return
	if(pos==0){
		delete_first();
		return;
	}
	
	Node* temp=head;
	Node* prev;//creating a node pointer to store the previous node
	int i=0;//creating an Integer variable to track the positon of the node
	
	//looping through from head to the last node(not to the end) of the linked list
	while(temp->next!=null){
		//if the i is euqal to position then break
		if(i==pos){
			break;
		}
		//storing temp in prev to track the previous node of the given node positon 
		prev=temp;
		temp=temp->next;//present node is assign to the next node by this
		i++;	
	}
	// previous node's next is now pointing to the next node of the current node
	prev->next= temp->next;
	free(temp);//then removeing the last node from memory
	length--;
}

void delete_item(int item){
	Node* temp=head;
	Node* prev;//creating a node pointer to store the previous node
	
	//checking if the item is exits by calling the search function, if not then return 
	if(search(item)==-1){
		return;
	}
	
	//checking if the item is the first item , if it is then delete the node by calling the delete_first function
	if(search(item)==0){
		delete_first();
		return;
	}
	
	//looping through all the nodes
	while(temp!=null){
		
		//if the current node's data is equal to item then loop will break
		if(temp->data==item){
			break;
		}
		//storing temp in prev to track the previous node of the current node positon 
		prev=temp;
		temp=temp->next;//present node is assign to the next node by this
	}
	
	// previous node's next is now pointing to the next node of the current node
	prev->next = temp->next;
	free(temp);//then removeing the last node from memory
	length--;
}

void insert_before(int old_item,int new_item){
	Node* temp=head;
	Node* prev;//creating a node pointer to store the previous node
	
	//checking if the old item is exits by calling the search function, if not then return 
	if(search(old_item)==-1){
		return;
	}
	
	//checking if the item is the first item, if it is we will use insert_first function to insert that item because of corner case
	if(search(old_item)==0){
		insert_first(new_item);
		return;
	}
	
	
	//looping through all the nodes
	while(temp!=null){
		//the current node data is equal to old item then this block will break 
		if(temp->data==old_item){
			break;
		}
		//storing temp in prev to track the previous node of the current node positon 
		prev=temp;
		temp=temp->next;//present node is assign to the next node by this
	}
	
	//creating a new node
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=new_item;// assign new item to the new node's data
	newNode->next=prev->next;// new node's next is now pointing to the next node of the previous node
	prev->next=newNode;// previous node's next is now pointing to the new node
	length++;
}

void insert_after(int old_item,int new_item){
	Node* temp=head;
	
	//checking if the old item is exits by calling the search function, if not then return 
	if(search(old_item)==-1){
		return;
	}
	
	//looping through all the nodes
	while(temp!=null){
		//if temp's data is equal old item then it will break the while loop
		if(temp->data==old_item){
			break;
		}
		temp=temp->next;//present node is assign to the next node by this
	}
	
	//creating a new node
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=new_item;//assiging item to new node's data
	newNode->next= temp->next;//new node's next is pointing to current node's next
	temp->next=newNode;//and current node's next is pointing to new node
	length++;
	
}

void print(){
	Node* temp=head;
	
	while(temp!=null){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	
	printf("\n");
}

int main(){
	init();
	
	printf("Insert First:\n");
	insert_first(30);
	insert_first(25);
	insert_first(20);
	print();
	printf("\n");
	
	printf("Insert Last\n");
	insert_last(35);
	insert_last(40);
	insert_last(45);
	print();
	printf("\n");
	
	printf("Insert At\n");
	insert_at(1,0);
	insert_at(5,1);
	insert_at(50,8);
	print();
	printf("\n");
	
	printf("Search\n");
	printf("%d\n",search(30));
	printf("%d\n",search(32));
	printf("\n");
	
	printf("Delete First\n");
	delete_first();
	print();
	printf("\n");
	
	printf("Delete Last\n");
	delete_last();
	print();
	printf("\n");
	
	printf("Delete At\n");
	delete_at(0);
	print();
	printf("\n");
	
	printf("Delete Item\n");
	delete_item(20);
	print();
	printf("\n");
	
	printf("Insert Before\n");
	insert_before(25,20);
	insert_before(45,40);
	print();
	printf("\n");
	
	printf("Insert After\n");
	insert_after(20,15);
	insert_after(45,50);
	print();
	printf("\n");
	
	printf("Linked list Length: %d\n",length);

}
