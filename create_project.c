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

//Include required libraries
/*
Function Implementations
*/
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


}

void create_project(char *arg)
{

int direxists; //if 1 we need to create the directory

direxists = DirectoryExists(arg);

if(DirectoryExists == 0)
{
exit(-1); //folder exists abort
}
else
{
printf("Running create_project.\n");int DirectoryExists(char arg[]);
int hasinvalidChacters(char arg[]);
void create_project(char *arg);

char command[MAX_COMMAND_CHARS] = "git init;touch .gitkeep;git add .; mkdir ";
strcat(command,arg);
printf("DEBUG1:Command is %s\n", command);
system(command); //run command to create the directory locally
command[0] = '\0';
//clear command we neeed to change directory now 
strcat(command,"git add ");
strcat(command,arg);
printf("DEBUG2:Command is %s\n", command);
system(command); //run command to create structure
command[0] = '\0'; //clear command buffer
strcat(command,"cd ");
strcat(command,arg);
printf("DEBUG3:Command is %s\n", command);
system(command); //run command to create structure
command[0] = '\0'; //clear command buffer
chdir(arg); //go to new folder
strcat(command,"git init;touch .gitkeep;mkdir bin;touch bin/.gitkeep;mkdir docs;touch docs/.gitkeep;mkdir lib;touch lib/.gitkeep;mkdir src;touch src/.gitkeep;mkdir tests;touch tests/.gitkeep;git add .;");
printf("DEBUG4:Command is %s\n", command);
system(command); //run command to create structure
command[0] = '\0'; //clear command buffer
system("pwd");
chdir(arg);//need to go baack up before we add
strcat(command,"git add /");
strcat(command,arg); //need the folder name so git add -A folder name
system("pwd");
system("git commit -m \"commit\"");
strcat(command,"/"); //need extra slash for directories
printf("DEBUG5:Command is %s\n", command);
system(command); //run command to set branch
command[0] = '\0'; //clear command buffer
chdir(".."); // need to switch to root folder to me able to commiit folder
printf("where are we\n");
system("pwd");
strcat(command,"git add -A;git commit -m \"commit\"");
printf("DEBUG6:Command is %s\n", command);
system(command); //run command to set git -m message
command[0] = '\0'; //clear command buffer
strcat(command,"git branch -M master");
printf("DEBUG7:Command is %s\n", command);
system(command); //run command to switch to master branch
command[0] = '\0'; //clear command buffer
strcat(command,"git remote add origin ");
strcat(command,GIT_URL);
printf("DEBUG8:Command is %s\n", command);
system(command); //run command remote add all files
command[0] = '\0'; //clear command buffer
strcat(command,"git push -f -u origin master");
printf("DEBUG9:Command is %s\n", command);
system(command); //run command to push things to git
return;
}
}
int main(int argc, char *argv[]) //Main entry point with arguments since we will need to enter arguaments
{
//0 = program like pm 1 = arg1 like create_project 2 = projecct name like newproject 
char *arg1 = argv[1];
char *arg2 = argv[2]; 
//We need to check if arguments have been provided nad if we have the correct number of arguments. Then we need to handle the argumets
printf("argc in myproject was = %d",argc);
if( argc == 3 ) {
      printf("The argument supplied is %s\n", argv[2]);
      //check for invalid characters
      int invalidchar = hasinvalidChacters(arg2);
      if(invalidchar==1){
       printf("Bad Characters in folder name\n");
       
      }
      else //number of args is okay we need to check which function we want to run
      {
      if(strcmp(arg1,"create_project")==0){ //0 means the string are the same so is a valid function
      create_project(arg2);
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