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

		if ((ch == '.') || (ch == '!') || (ch == '?')) {	//Checking whether the sentence has ended
			sentenceEnd = 1;
			putc(ch, outfile);
		} else if (sentenceEnd && ((ch >= 97) && (ch <= 122))) {	//Checking whether the starting letter of a sentence is lowercase
			pos = ch - 97;
			putc(alphabet[(26 + pos - key) % 26] - 32, outfile);
			sentenceEnd = 0;
		} else if (sentenceEnd && ((ch >= 65) && (ch <= 90))) {		//Checking whether the starting letter of a sentence is uppercase
			pos = ch - 65;
			putc(alphabet[(26 + pos - key) % 26] - 32, outfile);
			sentenceEnd = 0;
		} else if (!sentenceEnd && ((ch >= 97) && (ch <= 122))) {	//Checking whether the sentence letter is lowercase
			pos = ch - 97;
			putc(alphabet[(26 + pos - key) % 26], outfile);
		} else if (!sentenceEnd && ((ch >= 65) && (ch <= 90))) {	//Checking whether the sentence letter is uppercase
			pos = ch - 65;
			putc(alphabet[(26 + pos - key) % 26] - 32, outfile);
		} else {													//Printing other characters
			if (ch != EOF) {
				putc(ch, outfile);
			}
		}
	} while (!feof(infile));
}