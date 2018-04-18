#define MAX_TABLE 256

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
	return a > b ? a:b;
}

int* preprocess(char *pattern, int length) {
	int *table = (int*) malloc(MAX_TABLE*sizeof(int));
	for(int i = 0; i < MAX_TABLE; table[i++] = length);

	for(int i = 0; i < length-1; i++) {
		table[pattern[i]] = length - (i + 1);
	}

	return table;
}

int search(char *str, int sLen, char *pattern, int pLen ) {
	int *table = preprocess(pattern, pLen);
	int skip = 0;

	while(sLen - skip >= pLen) {
		int i = pLen - 1;

		while(str[skip + i] == pattern[i]) {
			if(i == 0) return skip;
			i--;
		}
		skip += table[str[skip + pLen - 1]];
	}
	return -1;
}

int main() {
	char *haystack = "test it a tit";
	char *needle = "tit";

	printf("%d\n", search(haystack, 13, needle, 3));
}
