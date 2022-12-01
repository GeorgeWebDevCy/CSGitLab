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


/*
Function Implementations
*/

int FileExists(char arg[])
{
    FILE *fp = fopen(".pm_tag", "r"); //we know thhe file is always clled .pm_tag
    int exist = 0; //set 0 initially aka doesn't exist
    if (fp != NULL)
    {
        exist = 1; // file exists because it opened
        fclose(fp); // close the file
    }
    return exist;

}


int hasinvalidChacters(char arg[])
{


  int found = 0; // we set our flag to zero since we haven't checked for the bad character yet
  if(strchr(arg, ' ') == NULL) //if strchr return null the means that we didn't find a space somewhere
  {
    found = 0;
  }


}

void add_tag(char *arg)
{

int hastagfile; //need to see if .pm_tag file exists

hastagfile = FileExists(arg);
if(hastagfile == 1)
{
printf("Already a tag for this folder.\n");
system("cat .pm_tag");
exit(0); //file exists so stop
}
else
{
printf("Running find_tag.\n");
char command[MAX_COMMAND_CHARS] =  "find . -name '*.pm_tag' -exec grep -Fx ";
strcat(command,"'");
strcat(command,arg);
strcat(command,"'");
strcat(command," {} ");
strcat(command,"\\; -print | cut -d: -f1");
//printf("DEBUG0:Command is %s\n", command);
system(command); //run command to create the .pm_tag file locally
command[0] = '\0';
return;
}
}

int main(int argc, char *argv[]) //Main entry point with arguments since we will need to enter arguaments
{
//0 = program like pm 1 = arg1 like create_project 2 = projecct name like newproject 
char *arg1 = argv[1];
char *arg2 = argv[2]; 
//We need to check if arguments have been provided nad if we have the correct number of arguments. Then we need to handle the argumets
//printf("argc was = %d",argc);
if( argc == 3 ) {
      //printf("The argument supplied is %s\n", argv[2]);
      //check for invalid characters
      int invalidchar = hasinvalidChacters(arg2);
      if(invalidchar==1){
       printf("Bad Characters in folder name\n");
       
      }
      else //number of args is okay we need to check which function we want to run
      {
      if(strcmp(arg1,"find_tag")==0){ //0 means the string are the same so is a valid function
      add_tag(arg2);
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
   else if( argc > 3 ) {
      printf("Wrong number of parameters, should be pm command arg \n");
      exit(-1);
      
   }
   else {
      printf(" At least one argument expected.\n");
      exit(-1);
   }

       

return 0; //Need to return control to the OS
}