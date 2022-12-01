/**
 * Project managment System
 * */


//Include required libraries
#include <stdio.h> // Standard i/O system library for stuff like printf,scanf,fopen etc.
#include <stdlib.h> //Required library to run the system functions like the git command
#include <string.h> //Required library to run the string related functions like the strcat command
#include <dirent.h> //Required library to run the string related functions like the opendir to see if a directory exists
#include <errno.h> //Required to detect errors when look for directory existance for example
#include <unistd.h>//chdir to change directory 
/*
 Constant definitions 
*/
#define MAX_COMMAND_CHARS 1000
#define GIT_URL "https://github.com/developerspal/CSGitLab.git"

int DirectoryExists(char arg[]);
int hasinvalidChacters(char arg[]);
/*
Function Implementations
*/
/**/
int DirectoryExists(char arg[])
{
DIR* dir = opendir(arg); //get directory from main args parameter
if (dir) {
    /* Directory exists. */
    closedir(dir); //close dir because it exists
    printf("A folder of that name already exists.  Aborting.\n");
       exit(0); //die gracefully no need to do more we are aborting since dir exists
} else if (ENOENT == errno) {
    /* Directory does not exist. */
    return 1; //return 1 to main so we know we need to greate the directory
} else {
    /* opendir() failed for some other reason. */
    printf("Directory exists funtion Failed for other reasons.\n");
    exit(-1); //die with error no need to do more we are aborting since we encountered an error
}

}

int hasinvalidChacters(char arg[])
{


  int found = 0; // we set our flag to zero since we haven't checked for the bad character yet
  if(strchr(arg, ' ') == NULL) //if strchr return null the means that we didn't find a space somewhere
  {
    found = 0;
  }
  


//we found a space so it will return the position of where it found the space so 0,1,2,3......etc but we don't care we set it to 1 mean an invalid character was found
else 
{
    found = 1;
}
//printf("found = %d\n", found);
return found;
}
 
char * getCurrentDirectory()
{
char *cwd;
cwd=(char *)malloc(100*sizeof(char));
getcwd(cwd,100);
return cwd;
}
int main(int argc, char *argv[]) //Main entry point with arguments since we will need to enter arguaments
{
//0 = program like pm 1 = arg1 like create_project 2 = projecct name like newproject 
char *arg1 = argv[1];
char *arg2 = argv[2];
char *arg3 = argv[3];
char *path_to_programs=getCurrentDirectory();
//We need to check if arguments have been provided nad if we have the correct number of arguments. Then we need to handle the argumets
printf("argc was from pm  = %d",argc);
if( argc == 3  ||  argc == 4 ) {
      //printf("The argument supplied is %s\n", argv[2]);
      //check for invalid characters
      int invalidchar = hasinvalidChacters(arg2);
      if(invalidchar==1){
       printf("Bad Characters in folder name\n");
       
      }
      else //number of args is okay we need to check which function we want to run
      {
      if(strcmp(arg1,"create_project")==0){ //0 means the string are the same so is a valid function

      char *path_to_use = strcat(path_to_programs,"/programs/create_project");
      //printf("DEBUG_PATH: = %s\n",path_to_use);
      //printf("DEBUG_ARG1_SENT: = %s\n",arg1);
      //printf("DEBUG_ARG2_SENT: = %s\n",arg2);
      execlp(path_to_use, path_to_use, arg1,arg2, NULL);
      path_to_use='\0'; // make it NULL we need to make sure it's empty to reuse it
      }
      else if(strcmp(arg1,"add_feature")==0){
      
      char *path_to_use = strcat(path_to_programs,"/programs/add_feature");
      //printf("DEBUG_PATH: = %s\n",path_to_use);
      //printf("DEBUG_ARG1_SENT: = %s\n",arg1);
      //printf("DEBUG_ARG2_SENT: = %s\n",arg2);
      execlp(path_to_use, path_to_use, arg1,arg2, NULL);
      path_to_use='\0'; // make it NULL we need to make sure it's empty to reuse it
      }
      else if(strcmp(arg1,"add_tag")==0){
      char *path_to_use = strcat(path_to_programs,"/programs/add_tag");
      //printf("DEBUG_PATH: = %s\n",path_to_use);
      //printf("DEBUG_ARG1_SENT: = %s\n",arg1);
      //printf("DEBUG_ARG2_SENT: = %s\n",arg2);
      execlp(path_to_use, path_to_use, arg1,arg2, NULL);
      path_to_use='\0'; // make it NULL we need to make sure it's empty to reuse it
      }
      else if(strcmp(arg1,"find_tag")==0){
      char *path_to_use = strcat(path_to_programs,"/programs/find_tag");
      printf("DEBUG_PATH: = %s\n",path_to_use);
      printf("DEBUG_ARG1_SENT: = %s\n",arg1);
      printf("DEBUG_ARG2_SENT: = %s\n",arg2);
      printf("DEBUG_ARG3_SENT: = %s\n",arg2);
      execlp(path_to_use, path_to_use, arg1,arg2, NULL);
      path_to_use='\0'; // make it NULL we need to make sure it's empty to reuse it
      }
      
      else if(strcmp(arg1,"move_by_tag")==0){
      char *path_to_use = strcat(path_to_programs,"/programs/move_by_tag");
      printf("DEBUG_PATH: = %s\n",path_to_use);
      printf("DEBUG_ARG1_SENT: = %s\n",arg1);
      printf("DEBUG_ARG2_SENT: = %s\n",arg2);
      execlp(path_to_use, path_to_use, arg1,arg2,arg3, NULL);
      path_to_use='\0'; // make it NULL we need to make sure it's empty to reuse it
    
      }
      else 
      {
        printf("\nThe argument %s is invalid.\n",arg1);
        printf("\nUsage\n");
        printf("\n=====\n");
        printf("\n create_project\n");
        printf("\n add_feature\n");
        printf("\n add_tag\n");
        printf("\n find_tag\n");
        printf("\n move_by_tag\n");
      }
      }
   }
   else if( argc > 4 ) {
      printf("Wrong number of parameters, should be pm command arg \n");
      exit(-1);
      
   }
   else {
      printf(" At least one argument expected.\n");
      exit(-1);
   }

       

return 0; //Need to return control to the OS
}