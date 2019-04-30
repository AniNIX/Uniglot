#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 0

/* This is a library for a singly-linked list with O(n) searchtime.
   It is intended to be used for small, changing datasets in the bot
*/

//The struct specification
typedef struct {
  char * data;
  void * next;
} LLElem;

/* Print the list */
void ll_printall(LLElem * root) {
  if (DEBUG) printf("printing\n");
  while (root != NULL) {
    printf("%s\n",root->data);
    root = root->next;
  }
  putchar('\n');
}

/* Returns 1 on true, 0 on false */
int ll_contains(char * data, LLElem * root) {
  if (data == NULL) return 0;
  while (root != NULL) {
    if (!strcmp(root->data,data)) {
      return 1;
    }
    root = root->next;
  }
  return 0;
}

/* Add an element and return the new tree */
LLElem * ll_add(char * new_data, LLElem * root) {
  char * newString = calloc(strlen(new_data),1);
  strncpy(newString,new_data,strlen(new_data));
  if (root == NULL) {
    root = calloc(sizeof(LLElem),1);
    root->data = newString;
    root->next = NULL;
    if (DEBUG) printf("Creating root %d with:\n%s\n:done\n\n",root,newString);
    if (DEBUG) ll_printall(root);
    return root;
  } else {
    if (!ll_contains(new_data,root)) {
      LLElem * curr = root;
      while (curr->next != NULL) {
	curr = (LLElem *) curr->next;
      }
      curr->next = calloc(sizeof(LLElem),1);
      curr = (LLElem *) curr->next;
      curr->data = newString;
      curr->next = NULL;
      if (DEBUG) printf("Appending to %d:\n%s\n:done\n\n",root,newString);
      if (DEBUG) ll_printall(root);
      return root;
    }
  }
  return NULL;
}


/* Remove an element */
LLElem * ll_remove(char * old_data, LLElem * root) {
  LLElem * tmp;
  //TODO paused here -- need to rewrite.
  return NULL;
}

/* Delete and free the contents of a list */
void ll_removeall(LLElem * root) {
  while (root != NULL) {
    root = ll_remove(root->data,root);
  }
}

/* read the contents of a file, comma-delimited, into a file */
LLElem * ll_read(char * filename, int * count) {
  FILE * fd = fopen(filename,"r");
  if (fd == NULL) {
    if (DEBUG) printf("No file found.\n");
    return NULL;
  } else { 
    if (DEBUG) printf("File opened.\n");
  }
  char * buffer, * tmp;
  int fcount = 0;
  fseek(fd,0,SEEK_END);
  size_t size = ftell(fd);
  fseek(fd,0,SEEK_SET);
  buffer=calloc(size,1);
  fread(buffer,size,1,fd);
  char entry[size]; //create a buffer with the maximum size
  bzero(entry,size);//zero the buffer
  int ccount=0;     //ccount is the current character location.
  int tmpsize=0;    //tmpsize will be the size of the buffer
  LLElem * root = NULL;
  while (ccount < size) {
    if (buffer[ccount]==10) {
      entry[tmpsize]=0;
      //if (DEBUG) printf("%s -> --%s--\n",entry,buffer);
      if (entry != NULL && strlen(entry)) { 
	fcount++;
	root = ll_add(entry,root);
	//if (DEBUG) printf("Added --%s--\n\n",entry);
	tmpsize=0;
      }

    } else {
      entry[tmpsize] = buffer[ccount];
      tmpsize++;
    }
    ccount++;
  }
  if (count != NULL) *count=fcount;
  return root;
}

/* Print the list */
char * ll_get(int num,LLElem * root) {
  if (DEBUG) printf("printing\n");
  while (num-- && root != NULL) {
    if (DEBUG) printf("%s,",root->data);
    root = root->next;
  }
  if (num && root != NULL) return root->data;
  return NULL;
}
