#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef char element;
typedef struct QueNode {
	element data;
	struct QueNode* link;
}QueNode;

typedef struct {
	QueNode* front, * rear;
}LinkedQueType;

void init(LinkedQueType* q) {
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueType* q) {
	return (q->front == NULL);
}

int is_full(LinkedQueType* q) {
	return 0;
}
void add_rear(LinkedQueType* q, element item) {
	QueNode* temp = (QueNode*)malloc(sizeof(QueNode));
	temp->data = item;
	temp->link = NULL;
	if (is_empty(q))
		q->front = temp;
		
	else 
		q->rear->link = temp;

	q->rear = temp;
	q->rear->link = q->front;
			
	
}
void add_front(LinkedQueType* q, element item) {
	QueNode* temp = (QueNode*)malloc(sizeof(QueNode));
	temp->data = item;
	temp->link = NULL;
	if (is_empty(q))
		q->front = temp;
	else {
		temp->link = q->rear->link;
		q->rear->link = temp;
		q->front = temp;
	}


	
}
int delete_rear(LinkedQueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 공백\n");
		exit(1);
	}
	int value;
	if (q->front == q->rear) {
		value = q->rear->data;
		free(q->rear);
		q->front = NULL;
		q->rear = NULL;
	}
	else {
		QueNode* temp = q->front;
		QueNode* curr = q->rear;
		while (temp->link != q->front) {
			if (temp->link == curr) {
				temp->link = curr->link;
				value = curr->data;
				free(curr);
				q->rear = temp;
			}
			temp = temp->link;
		}
       
		
	}
	return value;
}
int delete_front(LinkedQueType* q) {
	if (is_empty(q)) {
		fprintf(stderr,"큐가 공백\n");
		exit(1);
	}
	
	int value;
	if (q->front == q->rear) {
		value = q->front->data;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		QueNode* temp = q->front;
		value = temp->data;
		q->front = q->front->link;
		q->rear->link = q->front;
		free(temp);
	}
	return value;
}




void print_list(LinkedQueType* queue) {
	QueNode* p;
	if (queue == NULL) return;
	p = queue->front;

	while (p->link!=queue->front) {
		printf("%c->", p->data);
		p = p->link;
	}
	printf("%c\n", p->data);

}
void get_front(LinkedQueType* queue) {
	if (is_empty(queue)) {
		fprintf(stderr, "큐가 공백\n");
		exit(1);
	}

	else
		printf("%c\n", queue->front->data);
}
void get_rear(LinkedQueType* queue) {
	if (is_empty(queue)) {
		fprintf(stderr, "큐가 공백\n");
		exit(1);
	}

	else
		printf("%c\n", queue->rear->data);
}

void get_exp(char* exp)
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n') {
		if (c == ' ')
			continue;
		else {
			*(exp + i) = c;
			i++;

		}

	}
	*(exp + i) = '\0';
}

LinkedQueType  q(LinkedQueType* q, char* ex) {
	for (int i = 0; i < strlen(ex); i++) {
		add_rear(q, ex[i]);
		
	}
	return *q;
}

const char* check_str(LinkedQueType* q, char* ex) {
	int len = strlen(ex);
	
	for (int i = 0; i < len / 2; i++) {
		
		if (delete_front(q) != delete_rear(q)) {
		
			return "false";
		}
		

	}

	return "true";




}


int main(void) {
	LinkedQueType queue;
init(&queue);

char ex[50] = "";

get_exp(ex);
queue = q(&queue, ex);

print_list(&queue);
printf("%s", check_str(&queue, ex));
}
