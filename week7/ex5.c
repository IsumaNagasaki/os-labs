#include "stdio.h"
#include "stdlib.h"

int main() {
    char *s;
    char foo[] = "Hello World";
    s = foo;
    printf("s is %s\n",s);

    // Not sure why this line was put here in the first place
    // But okay, will live it here, it will cast pointer to the array to char
    // and put it into the first character of the string
    // on each run of the program it will print different values
    // but there will be no segmentation faults :)
    s[0] = foo; 

    printf("s[0] is %c\n",s[0]);
    return(0);
}