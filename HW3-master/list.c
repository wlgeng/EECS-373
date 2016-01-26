#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	if (head->index > new_element->index){
		new_element->next = head;
		head = new_element;
	}

	else{
		list_t *ptr = head;
		while ((ptr->next != NULL) && (ptr->next->index < new_element->index)) ptr = ptr->next;
		new_element->next = ptr->next;
		ptr->next = new_element;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
static list_t* reverse_help(list_t* current, list_t* prev){
	if (current == NULL) return prev;
	else{
		list_t *next = current->next;
		current->next = prev;
		return reverse_help(next, current);
	}
}

list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t *next = head->next;
	head->next = NULL;
	return reverse_help(next, head);
}

