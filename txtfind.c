#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "txtfind.h"

int getLine (char s[]){
	char c = getc (stdin);
	int i=0;
	while (i<LINE && c!='\n' && c!=EOF){
		s[i] = c;
		c = getc (stdin);
		i++;
	}
	s[i] = c;
	return i;
}

int getword (char w[]){
	char c = getc (stdin);
	int i=0;
	while (i<WORD && c!='\n' && c!= '\t' && c!= ' ' && c!=EOF){
		w[i] = c;
		c = getc (stdin);
		i++;
	}
	w[i] = '\0';
	return i;
}

int substring (char* str1, char* str2){
	int i=0;
	int j=0;
	int wl;
	while (*(str1+i)!='\0')
		i++;
	wl = i;
	i = 0;
	while (*(str1+i)!='\0' && *(str2+j)!='\0'){
		if (*(str1+i)==*(str2+j))
			i++;
		else
			i=0;
		if (i==wl)
			return 1;
		j++;
	}
	return 0;
}

int get_length (char* s){
	int c = 0;
	while (*(s+c)!='\0')
		c++;
	return c;
}

int similar (char* s, char* t, int n){
	int i=0;
	int j=0;
	int sl = get_length (s);
	int tl = get_length (t);
	if (tl-sl>n)
		return 0;
	while (*(t+i)!='\0'){
		if ((*(s+j)==*(t+i)))
			j++;
		if ((*(s+j)=='\0'))
			return 1;
		if (i>j+n)
			return 0;
		i++;
	}
	return 0;
}

void print_lines (char* str){
	int len = 1;
	while (len){
		char line [LINE] = {'\0'};
	        len = getLine (line);
		for (int i=0;i<LINE;i++){
			int j = 0;
			char word [WORD] = {'\0'};
			while (j<WORD && line[i]!='\n' && line[i]!=' ' && line[i]!='\t'){
				word [j] = line[i];
				i++;
				j++;
			}
			word [j] = '\0';
			if (substring (str,word)){
				printf ("%s", line);
				break;
			}
		}
	}
}

void print_similar_words (char* str){
	int len = 1;
	while (len){
		char word [WORD] ={'\0'};
		len = getword (word);
		if (similar (str,word,1) || similar (str,word,0))
			printf ("%s \n", word);
	}
}


















































