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
	node->prev = &(list->head);

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

int add_to_index_list(List *list, Node *node, int index) {

	if (index <= list->size && index > -1) {

		if (index == list->size) {
			
			node->next = &(list->tail);
			node->prev = list->tail.prev;

			list->tail.prev->next = node;
			list->tail.prev = node;
		}
		else if(index == 0) {

			node->next = list->head.next;
			node->prev = &(list->head);

			list->head.next = node;
			node->next->prev = node;
		}
		//Start at end
		else if (index > (list->size / 2)) {

			Node *it = &(list->tail);
			int i = list->size;
			for (; it != &(list->head); it = it->prev, i--) {

				if (i == index) {

					node->next = it;
					node->prev = it->prev;

					it->prev->next = node;
					it->prev = node;
				}
			}
		}
		//Start at beginning
		else {

			Node *it = &(list->head);
			int i = 0;
			for (; it != &(list->head); it = it->next, i++) {

				if (i == index) {

					node->next = it->next;
					node->prev = it;

					it->next->prev = node;
					it->next = node;
				}
			}
		}

		list->size++;

		return 1;
	}

	return 0;
}

Node* get_at_index_list(List *list, int index) {

	if (index < list->size && index > -1) {

		if(index == 0) {

			return &list->head;
		}
		//Start at end
		else if (index > (list->size / 2)) {

			Node *it = &list->tail;
			int i = list->size - 1;
			for (; it != &list->head; it = it->prev, i--) {

				if (i == index) {

					return it;
				}
			}
		}
		//Start at beginning
		else {

			Node *it = &list->head;
			int i = 0;
			for (; it != &list->head; it = it->next, i++) {

				if (i == index) {

					return it;
				}
			}
		}
	}

	return NULL;
}

//Pops the element at the front of the list off and returns it
//Return the removed node if successful
//Return NULL if the List is empty
Node* remove_front_list(List *list) {

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

		list->size--;

		return temp;
	}
}

Node* remove_list(List *list, Node *node) {

	Node *it = &list->head;
	for (; it != &list->head; it = it->next) {

		if (it == node) {

			return node;
		}
	}

	return NULL;
}

Node* remove_end_list(List *list) {

	if (is_empty(list) == 0) {

		return NULL;	
	}
	else {

		Node *temp = list->head.next;

		list->tail.prev = list->tail.prev->prev;
		list->tail.prev->next = &(list->head);

		temp->prev = NULL;
		temp->next = NULL;

		list->size--;

		return temp;
	}
}

int size(List *list) {
	return list->size;
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
