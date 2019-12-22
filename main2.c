#include <stdio.h>
#include "txtfind.h"

int main(){
	
	char text;
	char o;
	char w [WORD];
	int i=0;
	char x;

	while ((text = getc(stdin))!=' '){
		w[i] = text;
		i++;
	}
	w[i] = '\0';
	while ((text = getc(stdin))!='\n'){
		if (text == 'a')
			o = 'a';
		else if (text == 'b')
			o = 'b';
	}

	scanf ("%c",&x);

	switch (o){
		case 'a':
			print_lines (w);
			break;
		case 'b':
			print_similar_words (w);
			break;
		default:
			printf ("Error \n");
		}
	return 0;
}

