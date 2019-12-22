#include <stdio.h>
#include "isort.h"

int main (){
	int a[size] = {0};
	for (int i=0;i<size;i++)
		scanf ("%d", (a+i));
	insertion_sort (a,size);
	print_arr (a,size);

	return 0;
}

