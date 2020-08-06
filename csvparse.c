#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* compile with mingw or any other C compiler: */
/* gcc.exe -o a.exe csvparse.c */

/* Declaration of Global Variables Used */
typedef struct _BILL {
	char col1[100];
	char col2[100];
	char col3[100];
	char col4[100];
	char col5[100];
	char col6[100];
	char col7[100];
}BILL;

void CsvParse(int row, char* filename, BILL** data)
{
	FILE *file;
	file = fopen(filename, "r");

	int i = 0;
	char line[4098];
	while (fgets(line, 4098, file) && (i < row))
	{
		int j = 0;
		const char* tok;
		for (tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, ",\n"))
		{
			if( j == 0) {
				strncpy(data[i]->col1, tok, sizeof(data[i]->col1) - 1);
				data[i]->col1[(sizeof(data[i]->col1) - 1)] = 0;
				printf("%s\t", data[i]->col1);
			}
			else if( j == 1) {
				strncpy(data[i]->col2, tok, sizeof(data[i]->col2) - 1);
				data[i]->col2[(sizeof(data[i]->col2) - 1)] = 0;
				printf("%s\t", data[i]->col2);
			}
			else if( j == 2) {
				strncpy(data[i]->col3, tok, sizeof(data[i]->col3) - 1);
				data[i]->col3[(sizeof(data[i]->col3) - 1)] = 0;
				printf("%s\t", data[i]->col3);
			}
			else if( j == 3) {
				strncpy(data[i]->col4, tok, sizeof(data[i]->col4) - 1);
				data[i]->col4[(sizeof(data[i]->col4) - 1)] = 0;
				printf("%s\t", data[i]->col4);
			}
			else if( j == 4) {
				strncpy(data[i]->col5, tok, sizeof(data[i]->col5) - 1);
				data[i]->col5[(sizeof(data[i]->col5) - 1)] = 0;
				printf("%s\t", data[i]->col5);
			}
			else if( j == 5) {
				strncpy(data[i]->col6, tok, sizeof(data[i]->col6) - 1);
				data[i]->col6[(sizeof(data[i]->col6) - 1)] = 0;
				printf("%s\t", data[i]->col6);
			}
			else if( j == 6) {
				strncpy(data[i]->col7, tok, sizeof(data[i]->col7) - 1);
				data[i]->col7[(sizeof(data[i]->col7) - 1)] = 0;
				printf("%s\t", data[i]->col7);
			}
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char const *argv[])
{
	if (argc < 3){
		printf("Please specify no. of rows and the CSV file as an input.\n");
		exit(0);
	}

	int row = atoi(argv[1]);
	char fname[256];
	strcpy(fname, argv[2]);

	BILL **data;

	data = (BILL**) malloc(row * sizeof(BILL));
	
	for (int i = 0; i < row; ++i){
		data[i] = (BILL*) malloc(sizeof(BILL));
	}

	CsvParse(row, fname, data);
	printf("\n\nSize of data pointer: %d bytes\n", sizeof(data));
	printf(" Size of BILL Struct : %d bytes\n", sizeof(BILL));
	printf(" Size of BILL Struct Array data[n] : %d bytes\n", sizeof(BILL) * row);

	free(data);
	return 0;
}

