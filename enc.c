#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
void encrypt(FILE *secret_file, FILE *encripted_file, FILE *key_file){
   int c;
   while((c = fgetc(secret_file)) != EOF){
    int key = rand();
    int encryptd_c = c ^ key;
    fputc(key, key_file);
    fputc(encryptd_c, encripted_file);
}  
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Provide the file to be encripted\n");
  }
  else {
    char *secret_file_name = argv[1];
    FILE *secret_file = fopen(secret_file_name, "r");
    FILE *encripted_file = fopen("crypt.out", "w");
    FILE *key_file = fopen("key.out", "w");
    // calling function for encripting file
    encrypt(secret_file, encripted_file, key_file);
    fclose(secret_file);
    fclose(encripted_file);
    fclose(key_file);
}
  return 0;
}
