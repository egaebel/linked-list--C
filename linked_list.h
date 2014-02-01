#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

//Preprocessor macro which converts a AdjNode to the structure the AdjNode is IN (Duct tape style!)
#define LIST_ENTRY(NODE, STRUCT, MEMBER) 					\
	((STRUCT *)((uint8_t*)(NODE) - offsetof(STRUCT, MEMBER)))

//struct definitions----------------------------------
//linked node struct holding prev and next linked_node ptrs
struct linked_node {

	struct linked_node *prev;
	struct linked_node *next;
};

//linked list struct containing head and tail linked_nodes
struct linked_list {

	struct linked_node head;
	struct linked_node tail;
	int size;
};

//TypeDefs---------------------------------------------
typedef struct linked_node Node;
typedef struct linked_list List;

//Prototypes------------------------------------------------------
void init_list(List *q);
void init_node(Node *node);
List* create_list();

void add_to_front_list(List *list, Node *node);
void add_to_end_list(List *list, Node *node);
int add_to_index_list(List *list, Node *node, int index);

Node* get_at_index_list(List *list, int index);

Node* remove_front_list(List *list);
Node* remove_end_list(List *list);

int is_empty (List *q);

#endif
