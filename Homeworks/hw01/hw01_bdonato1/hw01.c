#include <stdio.h>
#include <string.h>

int fib(int n);
int diffSq(int a, int b);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("Please invoke as %s <input-ID>\n",argv[0]);
		printf("  %s will then open a file called <input-ID>.txt,\n",argv[0]);
		printf("  perform the requested operations, and write the results to\n");
		printf("  a file called <input-ID>_results.txt\n");
		return 1;
	}

	char inFileName[100] = {'\0'};
	strcat(inFileName,argv[1]);
	strcat(inFileName,".txt");
	char outFileName[100]={'\0'};
	strcat(outFileName,argv[1]);
	strcat(outFileName,"_results.txt");

	FILE *inFile=NULL;
	inFile=fopen(inFileName,"r");
	if (inFile==NULL) {
		printf("Unable to open input file %s... quitting.\n",inFileName);
		return 1;
	}

	FILE *outFile=NULL;
	outFile=fopen(outFileName,"w");
	if (outFile==NULL) {
		printf("Unable to open output file %s... quitting.\n",outFileName);
		fclose(inFile);
		return 1;
	}

	int a;
	int b;
	int result;
	while(!feof(inFile)) {
		if (1==fscanf(inFile," fib %d ",&a)) {
			result=fib(a);
			fprintf(outFile,"fib(%d) = %d\n",a,result);
		}
		else if (2==fscanf(inFile," diffSq %d %d ",&a,&b)) {
			result = diffSq(a,b);
			fprintf(outFile,"diffSq(%d,%d) = %d\n",a,b,result);
		} else {
			char unrecognized[256];
			fscanf(inFile," %256s",unrecognized);
			printf("The following word from the input file is not recognized: %s\n",unrecognized);
		}
	}
	fclose(inFile);
	fclose(outFile);
	return 0;
}

int fib(int n) {
	/* Write the code to return the nth fibonacci number here */
	int i;
	int num1 = 0;
	int num2 = 1;
	int next = 0;	
	for(i = 1; i <= n; i++){
		next = num1 + num2;
		num1 = num2;
		num2 = next; 
	}
	return num1;
}

int diffSq(int a, int b) {
	/* Write the code to return the difference between the square of a and square of b here */
	return ((a*a) - (b*b));
}
