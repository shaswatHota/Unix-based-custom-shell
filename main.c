#include <stdio.h>
#include <string.h>
#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
/*
A shell life cycle :	1) Initialize: reads and executes its config file
			2) Interpret : reads commands from stdin and executes them
			3) Terminate : After the execution of the command ,it executes shut down commands and frees up memory
*/

//the shell loop function ----------------
void lash_loop(void){
char *line;
chat **args;
int status;

do{
printf("> ");
line = lsh_read_line()
args = lsh_split_line(line);
status = lsh_execute(args);

free(line);
free(args);
}while(status);

}
//Read line function - could have used getline but manuel way is  good for learning -------------
char *lsh_read_line(void){
char buffersize = LSH_RL_BUFSIZE;
int position = 0 ;
char *buffer = malloc(sizeof(char) * buffersize);
if(!buffer){
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
int c;


while(1){
if(c == EOF || c == '\n'){
buffer[position]='\0';
return buffer;
}
else{
buffer[position]=c;
}
position++ ;

if(position >= buffersize){
buffersize += LSH_RL_BUFSIZE;
buffer = realloc(buffer , buffersize);
if(!buffer){
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
}
}
}

//split function-------------------------
char **lsh_split_line(char *line){
int buffersize = LSH_TOK_BUFSIZE,position=0;
char **tokens = malloc(sizeof(char *)* buffersize );
char *token;

if(!tokens){
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
token=strtok(line,LSH_TOK_DELIM);
while(token != NULL){
tokens[position]=token;
position++;
if(position>= buffersize){
buffersize += LSH_TOK_BUFSIZE;
tokens= realloc(tokens,bufsize*sizeof(char*));
if(!tokens){
fprintf(stderr, "lsh: allocation error\n");
exit(EXIT_FAILURE);
}
}
token=strtok(NULL,LSH_TOK_DELIM);
}
tokens[position]=NULL;
return tokens;
}


int main(int argc, char **argv){
lsh_loop();


return EXIT_SUCCESS;


}
