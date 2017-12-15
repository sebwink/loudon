#include <stdlib.h>
#include <string.h>

#include <loudon/cdlist.h>

void cdlist_init(CDList *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    return;
}

void cdlist_destroy(CDList *list) {
    void *data;
    while (cdlist_size(list) > 0)
	if (cdlist_remove(list, cdlist_tail(list), (void **)&data) == 0 && list->destroy != NULL)
	    list->destroy(data);
    memset(list, 0, sizeof(CDList));
    return;    
}

int cdlist_ins_next(CDList *list, CDListElmt *element, const void *data) {
    CDListElmt *new_element;
    if ((new_element = (CDListElmt *)malloc(sizeof(CDListElmt))) == NULL)
        return -1;
    new_element->data = (void *)data;
    if (cdlist_size(list) == 0) {
	list->head = new_element;
	list->head->prev = new_element;
	list->head->next = new_element;
    }
    else {
	if (element == NULL) {
	    new_element->prev = list->head->prev;
	    new_element->next = list->head;
	    new_element->prev->next = new_element;
	    new_element->next->prev = new_element;
	    list->head = new_element;
	}
	else {
	    new_element->next = element->next;
	    new_element->prev = element;
	    element->next = new_element;
	    new_element->next->prev = new_element;
	}
    }
    list->size++;
    return 0;
}

int cdlist_ins_prev(CDList *list, CDListElmt *element, const void *data) {
    CDListElmt *new_element;
    if ((new_element = (CDListElmt *)malloc(sizeof(CDListElmt))) == NULL)
        return -1;
    new_element->data = (void *)data;
    if (cdlist_size(list) == 0) {
	list->head = new_element;
	list->head->prev = new_element;
	list->head->next = new_element;
    }
    else {
        if (element == NULL) {
	    new_element->prev = list->head->prev;
	    new_element->next = list->head;
	    new_element->prev->next = new_element;
	    new_element->next->prev = new_element;
	    list->head = new_element;
	}
	else {
	    new_element->next = element;
	    new_element->prev = element->prev;
	    element->prev = new_element;
	    new_element->prev->next = new_element;
	}
    }
    list->size++;
    return 0;
}

int cdlist_remove(CDList *list, CDListElmt *element, void **data) {
    if (element == NULL || cdlist_size(list) == 0)
	return -1;
    *data = element->data;
    if (element == list->head) {
	list->head = element->next;
        if (element->next == element)
	    list->head = NULL;
	else {
	    element->next->prev = element->prev;
            element->prev->next = element->next;
	}
    }
    else {
	element->prev->next = element->next;
	element->next->prev = element->prev;
    }
    free(element);
    list->size--;
    return 0;
}
