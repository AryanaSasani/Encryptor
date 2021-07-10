

#include <iostream>
#include <stdio.h>

#define MAX_FILE_SIZE (1024*1024*5) //5MB memory

int main(int argc, char* argv[])
{
	

	if (argc <= 2)
	{
		puts("");
		printf("You must enter the <file-name & password} that you want to encrypt ! \n enter --help for more information \n");
		return 0;
	}
	printf("cheking inputs...\n");
	for (int argIndex = 1; argIndex < argc; argIndex++)
	{
		
		char*  holdArgument= argv[argIndex];
		
		if (strcmp(argv[argIndex], "--help") == 0)
		{
			/*printf("arguments:\n --password : encrypting password or how to encrypt \n --file : enter your filename u want  to encrypt\n");*/
			printf("filename.extention Password \n password -> how to encrypt or decrypt file\n");
			return 0;
		}
	}


	int errnum;


	FILE* fptr;
	printf("%s is being edited ", argv[1]);
	char data[MAX_FILE_SIZE];
	char* file = argv[1];
	int password = (int)strtol(argv[2] , NULL, 0);
		
		
		
	

	fptr = fopen(argv[1], "rb");
	// error handeling :>>
	if (fptr == NULL) {
		puts("");
		puts("error!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

		errnum = errno;
		fprintf(stderr, "value of errno: %d\n", errno);
		perror("error printed by perror");
		fprintf(stderr, "error opening file: %s\n", strerror(errnum));
	}
	else {
		
		int i = 0;
		//reading file
		while (!feof(fptr))
			data[i++] = fgetc(fptr);
		fclose(fptr);
		printf("\n almost done ");

		//encrypting file
		fptr = fopen(argv[1], "wb");
		printf("%d", password);
		for (int j = 0; j < i - 1; j++)
			fputc((data[j] ^ password), fptr);
		fclose(fptr);
		printf("\n Done");

		fclose(fptr);
		
	}
		



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
