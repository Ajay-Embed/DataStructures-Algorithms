// implementation of bracket checker program

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
	char item[SIZE];
	int top;
}Stack;

// function prototypes

// function for stack operations
void push(Stack *, char);
char pop(Stack *);
int isEmpty(Stack *);
char stacktop(Stack *);

// function required for this application
int isOpeningMatch(char, char);

// actual implementation of the algorithm
int checkExpr(char[]);


// push operation
void push(Stack *sp, char v){
	// checking overflow
	if (sp->top == SIZE-1){
		printf("Stack overflow, terminating program\n");
		exit(1);
	}
	// otherwise push
	sp->item[++sp->top] = v;
}
// Pop operation
char pop(Stack *sp){
	if (isEmpty(sp)){
		printf("Stack underflow, terminating program\n");
		exit(1);
	}
	return sp->item[sp->top--];
}

// returns 1 if the stack is empty, 0 otherwise
int isEmpty(Stack *sp){
	return sp->top == -1;
}

char stacktop(Stack *sp){
	if (isEmpty(sp)){
		printf("Stack underflow, terminating program\n");
		exit(1);
	}
	return sp->item[sp->top];
}

int isOpeningMatch(char left, char right){
	int match = 0;
	switch(left){
		case '(': if (right == ')')
					match = 1;
				  break;
		case '{': if (right == '}')
					match = 1;
				  break;
		case '[': if (right == ']')
					match = 1;
				  break;
		default: printf("Invalid symbol encountered, terminating program\n");
				 exit(1);
	}
	return match;
}

int checkExpr(char expr[]){
	Stack stack;
	stack.top = -1;

	int error = 0;
	int i = 0;
	while(expr[i]!='\0'){
		// get the next character from the expr
		char next_char = expr[i];
		if (next_char == '(' || next_char == '{' || next_char == '[')
			push(&stack, next_char);
		else if(next_char == ')' || next_char == '}' || next_char == ']'){
			if (isEmpty(&stack)){
				error = 1;
				break;
			}
			else if(isOpeningMatch(stacktop(&stack), next_char)){
				pop(&stack);
			}
			else{
				error = 1;
				break;
			}
		}
		++i;
	}
	if (!error && !isEmpty(&stack)){
		error = 1;
	}
	return error;
}



int main(){
	char expr[SIZE];
	printf("Input expression: ");
	scanf("%s", expr);

	if (checkExpr(expr)){
		printf("Does not contain well formed brackets\n");
	}
	else{
		printf("Contains well formed brackets\n");
	}
	return 0;
}
