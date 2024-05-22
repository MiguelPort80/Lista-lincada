#include <iostream>

struct Node {
    int data;
    struct Node * next;
};

class LinkedList{
    private:
	Node *head;
	Node *tail;

    public:
	LinkedList(){
	    head = nullptr;
	    tail = nullptr;
	}
	void createNode(int value){
	    //Apenas cria um node, apenas usar para inserir nodes ou inserir no final
	    Node* temp = new Node; //aloca o node temp na heap
	    temp->data = value;
	    temp->next = nullptr;

	    if (head == nullptr){
		head = temp;
		tail = temp;
	    }else{
		tail->next = temp;
		tail = temp;
	    }
	}
	void pushNode(int value){
	    Node* new_node = new Node;
	    new_node->data = value;
	    new_node->next = head;

	    head = new_node;
	}

	int pop(){
	    int retval = 0;
	    Node* next_node = nullptr;
	    next_node = head->next;
	    retval = head->data;
	    delete head;
	    head = next_node;

	    return retval;
	}

	int removeLast(){
	    int retval = 0;
	    //verifica se só tem um elemento na lista
	    if(head->next == nullptr){
		retval = head->data;
		delete head;
		return retval;
	    }
	    //vai até o penúltimo elemento
	    Node* current = head;
	    while(current->next->next != nullptr){
		current = current->next;
	    }

	    retval = current->next->data;

	    delete current->next;
	    current->next = nullptr;
	    return retval;
	}
	
	int removeByIndex(int index){
	    int retval = -1;
	    Node* current = head;
	    Node* temp_node = nullptr;

	    if(index == 0){
		return pop();
	    }

	    for(int i = 0; i < index-1; i++){
		if(current->next == nullptr){
		    return -1;
		}
		current = current->next;

	    }

	    temp_node = current->next;
	    retval = temp_node->data;
	    current->next = temp_node->next;
	    delete temp_node;

	    return retval;
	}

	int removeByData(int value){
	    int retval = -1;
	    Node* current = head;
	    Node* temp_node = nullptr;

	    

	    while(current->data != value){
		if(current->next == nullptr){
		    removeLast();
		}
		current = current->next;

	    }

	    temp_node = current->next;
	    retval = temp_node->data;
	    current->next = temp_node->next;
	    delete temp_node;

	    return retval;
	}
	void printList(){
	    Node* current = head;

	    while(current != nullptr){
		std::cout << current->data << std::endl;
		current = current->next;
	    }
	}
};
