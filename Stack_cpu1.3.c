/*
 * Tushin Kirill  
 * Stack_cpu.c
 */


#include <stdio.h>
#include <assert.h>
#include <string.h> 
#include <stdlib.h>
#include "FUNCTION.fun"

#define INIT_SIZE 50 //начальный размер массива

#define MULTIPLIER 2	//при недстатке памяти увечличиваем ее в MULTIPLIER раз



#define IF_CPU(l)\
		if(p == l){\
			if(Mass[l].arg)\
				fscanf(mf, "%d", &g);\
		&Mass[l].func;}\
			
typedef struct Stack_tag 
{
    int* data;		//указатель на данные
    unsigned size;	//размер стека
    unsigned top;	//число элементов
} Stack_t;


Stack_t* createStack()				//создаем стек
{
    Stack_t* out = NULL;
    out = malloc(sizeof(Stack_t));
    if (out == NULL) 
    {
        assert(0);
    }
    out->size = INIT_SIZE;
    out->data = malloc(out->size * sizeof(int));
    if (out->data == NULL)
    {
        free(out);
		assert(0);
    }
    out->top = 0;
    return out;
}

void deleteStack(Stack_t **stack)		//удаляем стек
{
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resize(Stack_t *stack)			//изменяем размер стека если не хватает места
{
    stack->size *= MULTIPLIER;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
    if (stack->data == NULL) 
    {
        assert(0);
    }
}

void push(Stack_t *stack, int value) {		//PUSH
    if (stack->top >= stack->size) {
        resize(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
}

int pop(Stack_t *stack) {			//POP
    if (stack->top == 0) {
       assert(0);
    }
    stack->top--;
    return stack->data[stack->top];
}


int main() 
{
    char c;
    int a = 0;
	
    Stack_t *stack = createStack();
	
	FILE *mf;
	
	mf = fopen ("my.forcpu","r");
	
	while(1)
	{
		c = fgetc(mf);
		if(c == EOF)
			break;
		if(c == ' ')
			a++;
	}
	fclose(mf);
		
	int t = 0;
	
	mf = fopen ("my.forcpu","r");
	
	while(t < a)
	{
		int g = 0;
		int p;
		fscanf(mf, "%d", &p);
		if(p == cmd_Push) 
			PUSH;
		if(p == cmd_Pop)
			POP;
		if(p == cmd_Add)
			ADD;
		if(p == cmd_Sub)
			SUB;
		if(p == cmd_Mul)
			MUL;
		if(p == cmd_Div)
			DIV;

		t++;
	}
	printf("%d ", POP);
	deleteStack(&stack);		//удаляем стек
    
    return 0;
}
