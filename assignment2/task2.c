#include <stdio.h>

int main(void) {
	FILE *infile = fopen("cipher.txt", "r");
	FILE *outfile = fopen("plain.txt", "w");

	int pos, key = 3;
	const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char ch;
	_Bool sentenceEnd = 1;

	do {
		ch = getc(infile);

		if ((ch == '.') || (ch == '!') || (ch == '?')) {
			sentenceEnd = 1;
			printf("%c", ch);
			putc(ch, outfile);
		} else if (sentenceEnd && ((ch >= 97) && (ch <= 122))) {
			pos = ch - 97;
			printf("%c", alphabet[(26 + pos - key) % 26] - 32);
			putc(alphabet[(26 + pos - key) % 26] - 32, outfile);
			sentenceEnd = 0;
		} else if (sentenceEnd && ((ch >= 65) && (ch <= 90))) {
			pos = ch - 65;
			printf("%c", alphabet[(26 + pos - key) % 26] - 32);
			putc(alphabet[(26 + pos - key) % 26] - 32, outfile);
			sentenceEnd = 0;
		} else if (!sentenceEnd && ((ch >= 97) && (ch <= 122))) {
			pos = ch - 97;
			printf("%c", alphabet[(26 + pos - key) % 26]);
			putc(alphabet[(26 + pos - key) % 26], outfile);
		} else if (!sentenceEnd && ((ch >= 65) && (ch <= 90))) {
			pos = ch - 65;
			printf("%c", alphabet[(26 + pos - key) % 26] - 32);
			putc(alphabet[(26 + pos - key) % 26] - 32, outfile);
		} else {
			printf("%c", ch);
			if (ch != EOF) {
				putc(ch, outfile);
			}
		}
	} while (!feof(infile));
}