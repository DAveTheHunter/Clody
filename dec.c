#include <stdio.h>
#include <stdlib.h>

void decript(FILE *encripted_file, FILE *key, FILE* decripted_file){
   int enc_c;
   while((enc_c = fgetc(encripted_file)) != EOF){
     int key_c = fgetc(key);
     int dec_c = enc_c ^ key_c;
     fputc(dec_c, decripted_file);
   }
}


int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("please provide essential arguments\n");
  }else {
    FILE* encripted_file = fopen(argv[1], "r");
    FILE* key = fopen(argv[2], "r");
    FILE* decripted_file = fopen("decripted_file", "w");
    decript(encripted_file, key, decripted_file);  
    fclose(encripted_file);
    fclose(key);
    fclose(decripted_file);
  }
  
return EXIT_SUCCESS;
}
