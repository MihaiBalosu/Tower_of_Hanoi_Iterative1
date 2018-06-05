#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h
#include "tohIterative.h"

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

// Function to add an item to stack. It increases
// top by 1
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
{
	int plate1TopSlice = pop(src);
	int plate2TopSlice = pop(dest);

	// When plate 1 is empty
	if (plate1TopSlice == INT_MIN)
	{
		push(src, plate2TopSlice);
		moveSlice(d, s, plate2TopSlice);
	}

	// When plate 2 is empty
	else if (plate2TopSlice == INT_MIN)
	{
		push(dest, plate1TopSlice);
		moveSlice(s, d, plate1TopSlice);
	}

	// When top slice of plate1 > top slice of plate2
	else if (plate1TopSlice > plate2TopSlice)
	{
		push(src, plate1TopSlice);
		push(src, plate2TopSlice);
		moveSlice(d, s, plate2TopSlice);
	}

	// When top slice of plate1 < top slice of plate2
	else
	{
		push(dest, plate2TopSlice);
		push(dest, plate1TopSlice);
		moveSlice(s, d, plate1TopSlice);
	}
}

//Function to show the movement of slices
void moveSlice(char fromPlate, char toPlate, int slice)
{
	printf("Move the slice %d from plate \'%c\' to plate \'%c\'\n",
		slice, fromPlate, toPlate);
}

// Driver Program
int main()
{
	// Input: number of slices
	int num_of_slices;

    time_t t;

    srand((unsigned) time(&t));

    num_of_slices =rand() %20;

    printf( "A is the bronze plate \n" );
    printf( "B is the silver plate \n" );
    printf( "C is the golden plate \n" );
    printf( "The number of slices is %d \n", num_of_slices );

	struct Stack *src, *dest, *aux;

	// Create three stacks of size 'num_of_slices'
	// to hold the slices
	src = createStack(num_of_slices);
	aux = createStack(num_of_slices);
	dest = createStack(num_of_slices);

	tohIterative(num_of_slices, src, aux, dest);
	return 0;
}
