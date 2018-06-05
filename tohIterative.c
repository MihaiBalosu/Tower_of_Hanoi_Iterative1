#include "tohIterative.h"

//Function to implement TOH puzzle
void tohIterative(int num_of_slices, struct Stack
			*src, struct Stack *aux,
			struct Stack *dest)
{
	int i, total_num_of_moves;
	char a = 'A', b = 'B', c = 'C';

	//If number of slices is even, then interchange
	//destination plate and auxiliary plate
	if (num_of_slices % 2 == 0)
	{
		char temp = b;
		b = c;
		c = temp;
	}
	total_num_of_moves = pow(2, num_of_slices) - 1;

	//Larger slice will be pushed first
	for (i = num_of_slices; i >= 1; i--)
		push(src, i);

	for (i = 1; i <= total_num_of_moves; i++)
	{
		if (i % 3 == 1)
		moveSlicesBetweenTwoPlates(src, dest, a, c);

		else if (i % 3 == 2)
		moveSlicesBetweenTwoPlates(src, aux, a, b);

		else if (i % 3 == 0)
		moveSlicesBetweenTwoPlates(aux, dest, b, c);
	}
}
