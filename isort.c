#include <stdio.h>
#include "isort.h"

void shift_element (int* arr, int i){
	int t = i;
	int k = *(arr+i);
	for (int j=0;j<=i;j++){
		*(arr+t) = *(arr+t-1);
		k--;
	}
	*arr = k;
}

void insertion_sort (int* arr, int len){
	int j,k;
	for (int i=1;i<len;i++){
		k = *(arr+i);
		j = i-1;
		while (j>=0&&*(arr+j)>k){
			*(arr+j+1) = *(arr+j);
			j--;
		}
		*(arr+j+1) = k;
	}
}

void print_arr (int* arr, int x){
	for (int i=0;i<x;i++){
		if (i == x-1)
			printf("%d/n", *(arr+i));
		else
			printf("%d, ", *(arr+i));
	}
}

