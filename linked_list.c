#include "linked_list.h"

//init_list, init_node, add(from rear), remove(from front), isEmpty

//Functions--------------------------------------
//Initializes a List struct's sentinal nodes
void init_list(List *list) {

	list->head.next = &(list->tail);
	list->tail.prev = &(list->head);

	list->head.prev = NULL;
	list->tail.next = NULL;

	list->size = 0;
}

//Returns an initialized List struct
List* create_list() {

	List *list = malloc(sizeof(List));
	init_list(list);

	return list;
}

//Initializes a Node to have all NULL ptrs
void init_node(Node *node) {

	node->next = NULL;
	node->prev = NULL;
}

void add_to_front_list(List *list, Node *node) {

	node->next = list->head.next;
	node->prev = &(list->prev);

	list->head.next = node;
	node->next->prev = node;

	list->size++;
}

//Adds the passed in node to the END of the passed in List
void add_to_end_list(List *list, Node *node) {

	node->next = &(list->tail);
	node->prev = list->tail.prev;

	list->tail.prev->next = node;
	list->tail.prev = node;

	list->size++;
}

Node* get_at_index_list(List *list, int index) {

}

bool add_to_index_list(List *list, Node *node, int index) {

	if (index <= list->size && index > -1) {

		if (index == size) {
			
			node->next = &(list->tail);
			node->prev = list->tail.prev;

			list->tail.prev->next = node;
			list->tail.prev = node;
		}
		else if(index == 0) {

		}
		//Start at end
		else if (index > (list->size / 2)) {

			Node *it = &list.tail;
			for (int i = list->size - 1; it != &list.head; it = it->prev; i--) {


			}
		}
		//Start at beginning
		else {

		}

		list->size++;

		return true;
	}

	return false;
}


//Pops the element at the front of the list off and returns it
//Return the removed node if successful
//Return NULL if the List is empty
Node* remove_list(List *list) {

	//if list is empty
	if (is_empty(list) == 0) {

		//ERROR
		return NULL;
	}
	else {

		Node *temp = list->head.next;

		//new linkage
		list->head.next = list->head.next->next;
		list->head.next->prev = &(list->head);

		//kill temp's access to the list
		temp->prev = NULL;
		temp->next = NULL;

		return temp;
	}
}

//Takes in a List, returns if its empty
//Return 0 if empty
//Return 1 if NOT empty
int is_empty (List *list) {

	//if the head's next points to the tail
	if (list->head.next == &(list->tail)) {

		return 0;
	}

	return 1;
}