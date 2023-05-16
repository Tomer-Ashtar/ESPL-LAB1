#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 int f(char a){
     return a;
 }
 char my_get(char c){
/* Ignores c, reads and returns a character from stdin using fgetc. */
    char e=fgetc(stdin);
    return e;
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
printf("the val of c in hexa is: %x\n",c);
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
int base_len = 5;
char arr1[base_len];
char* arr2 = map(arr1, base_len, my_get);
char* arr3 = map(arr2, base_len, cprt);
char* arr4 = map(arr3, base_len, xprt);
char* arr5 = map(arr4, base_len, encrypt);
char* arr6 = map(arr5, base_len, decrypt);
free(arr2);
free(arr3);
free(arr4);
free(arr5);
free(arr6);
  /* TODO: Test your code */
  char a[]={'C','s'};
  char* b=map(a,2,f);
  printf("%s ",b);
  printf("%c      ",xprt('r'));
  int c=8;
  printf("%d",f(c));
}

