#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_

#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

//Preprocessor macro which converts a AdjNode to the structure the AdjNode is IN (Duct tape style!)
#define QUEUE_ENTRY(NODE, STRUCT, MEMBER) 					\
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
void init_qnode(Node *node);
List* create_list();

void add_list(List *q, Node *node);
Node* remove_list(List *q);

int is_empty (List *q);

#endif