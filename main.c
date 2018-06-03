#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack
{
unsigned capacity;
int top;
int *array;
};

// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack =
		(struct Stack*) malloc(sizeof(struct Stack));
	stack -> capacity = capacity;
	stack -> top = -1;
	stack -> array =
		(int*) malloc(stack -> capacity * sizeof(int));
	return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
return (stack->top == stack->capacity - 1);
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
return (stack->top == -1);
}

void push(struct Stack *stack, int item)
{
	if (isFull(stack))
		return;
	stack -> array[++stack -> top] = item;
}

// Function to remove an item from stack. It
// decreases top by 1
int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack -> array[stack -> top--];
}

// Function to implement legal movement between
// two plates
void moveSlicesBetweenTwoPlates(struct Stack *src,
			struct Stack *dest, char s, char d)

int main()
{
	// Input: number of slices
	int num_of_slices;

    time_t t;

    srand((unsigned) time(&t));

    num_of_slices = rand() %10;

    printf("The number of disks is %d \n", num_of_slices);

	return 0;
}

