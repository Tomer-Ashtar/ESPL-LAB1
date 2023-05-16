#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct fun_desc {
char *name;
char (*fun)(char);
};
char my_get(char c){
/* Ignores c, reads and returns a character from stdin using fgetc. */
    char e=fgetc(stdin);
    return (e);
 }

char cprt(char c){
/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */
if(c>=0x20 && c<=0x7E)
    printf("%c\n",c);
else
     printf(".");
return c;
}
char encrypt(char c){
/* Gets a char c and returns its encrypted form by adding 1 to its value. If c is not between 0x20 and 0x7E it is returned unchanged */
if(c>=0x20 && c<=0x7E)
    return c+1;
else
    return c;
}
char decrypt(char c){
/* Gets a char c and returns its decrypted form by reducing 1 from its value. If c is not between 0x20 and 0x7E it is returned unchanged */
if(c>=0x20 && c<=0x7E)
    return c-1;
else
    return c;
}
char xprt(char c){
/* xprt prints the value of c in a hexadecimal representation followed by a new line, and returns c unchanged. */
if(c>=0x20 && c<=0x7E)
    printf("%x\n",c);
else 
    printf(".\n");
return c;
}
char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
  /* TODO: Complete during task 2.a */
  for(int i=0;i<array_length;i++){
     mapped_array[i]=f(*(array+i));
  }
  return mapped_array;
}
 
 
int main(int argc, char **argv){

char* carray=malloc(5*sizeof(char));


int bound=4;
 
struct fun_desc menu[] = {
		{"my_get", &my_get},
		{"cprt", &cprt},
		{"encrypt", &encrypt},
        {"decrypt", &decrypt},
        {"xprt", &xprt},
		{NULL, NULL}};
        char c[10];
        
        printf("Select operation from the following menu (Cntrl+D to end):\n");
        for(int i=0;i<5;i++)
            printf("%d:%s\n",i,(menu+i)->name);

 while(fgets(c,10,stdin)!=NULL){
            
            int userChoice=atoi(c);
           
            if(strlen(c)>2 || userChoice<0||userChoice>bound||(c[0]!=48 && userChoice==0)){
                printf("not within bounds\n");
                exit(0);
                }
            else{
                printf("within bounds\n");
                carray=map(carray,5,(menu+userChoice)->fun);
                
            }
        printf("Select operation from the following menu (Cntrl+D to end):\n");
        for(int i=0;i<5;i++)
            printf("%d:%s\n",i,(menu+i)->name);
    
        
     }

 

}

