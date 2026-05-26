//Work Still in progress ,It is give segmentation fault currently

#include <stdio.h>
#include <string.h>

int main(){
//experiment on string buffer
//int buffersize = 1024;
//char **tokens = malloc(sizeof(char*)* buffersize);
char *token[] = {"\"hello","world\"", "is","this","\"the\"","world"};
int length=sizeof(token)/sizeof(token[0]);
printf("%d\n",length);
for(int i=0 ;i<length; i++){
int lengthStr=strlen(token[i]);
if(token[i][0] == '"' && token[i][lengthStr-1]=='"'){
if(lengthStr>=2){
memmove(token[i],token[i]+1,lengthStr-1);
token[i][lengthStr-2]='\0';
}else if (lengthStr == 1){
token[i][0]='\0';
}
}
else if(token[i][0] == '"'){
if(lengthStr>0){
memmove(token[i],token[i]+1,lengthStr-1);
}
}
else if(token[i][lengthStr-1]== '"'){
if(lengthStr>0){
token[i][lengthStr-2]='\0';
}
}
printf("%s",token[i]);

}

return 0;
}
