#define MAX_TABLE 256

#include <stdio.h>
#include <stdlib.h>

int* preprocess(char *pattern, int length) {
	int *table = (int*) malloc(MAX_TABLE*sizeof(int));
	for(int i = 0; i < MAX_TABLE; table[i++] = length);

	for(int i = 0; i < length; i++) {
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
		printf("skip: %d\n", skip);
		printf("Skip letter: %c\n", str[skip+pLen-1]);
		skip += table[str[skip + pLen - 1]];
	}
	return -1;
}

int main() {
	char *haystack = "test is a tit";
	char *needle = "tit";

	printf("%d\n", search(haystack, 13, needle, 3));
}
