#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 4

char* strnsub (char *p, int n);


int main()
{
    char line[] = "His textbook was bought from that bookstore";  
    char *p1, *p2;

	p1 = line;
	//set p1 to the beginning of string line;;
    while (*p1 != line[(sizeof(line)/sizeof(char))]) 	
    {
        p2 = p1 + sizeof(char);
	//set p2 to the position immediately after p1
		
        while (*p2 != line[(sizeof(line)/sizeof(char))])	
        {

            if(strncmp(p1, p2, LEN) == 0)
            {
                printf("The original string is:\n%s\n", line);
                printf("The first substring:  %s\n", (strnsub(p1, LEN)));
                printf("The second substring: %s\n", (strnsub(p2, LEN)));
                return 0;
            }

		p2 = p2 + sizeof(char);
        }
         p1 = p1 + sizeof(char);
    }
    printf("No repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);
    
    return 0;
}


// returns a string with the first n characters of string p
char* strnsub (char *p, int n)
{
	//char* newString = malloc(sizeof(char) * n);
	char newString[n];
	int i;
	for(i = 0; i < n; i++){
		newString[i] = p[i];
	}
	p = newString;
	return p;
}
