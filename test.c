 #include <sys/types.h> 
     #include <sys/wait.h>  
     #include <stdio.h>     
     #include <stdlib.h>   
     #include <unistd.h>   
int main(){
    fork();
    printf("hello");
    return 0;
}