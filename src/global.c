#include "global.h"
#include <stddef.h>
#include <string.h>

const char *options[] = {
  "--help", "-h", "--version", 
  "-v", "install", "remove",
  "list", "push", NULL
};

Global global;

int is_option(const char *name){

  if(strcmp(name, "--help")) return 1;
  else if(!strcmp(name, "--version"))return 1;
  else if(!strcmp(name, "install"))return 1;
  else if(!strcmp(name, "remove"))return 1;
  else if(!strcmp(name, "list"))return 1;
  else if(!strcmp(name, "push"))return 1;

  return 0;
}

void set_option(const char *option){
  if(!strcmp(option, "--help"))
    global.option = HELP;
  else if(!strcmp(option, "--version"))
    global.option = VERSION;
  else if(!strcmp(option, "install"))
    global.option = INSTALL;
  else if(!strcmp(option, "remove"))
    global.option = REMOVE;
  else if(!strcmp(option, "list"))
    global.option = LIST;
  else if(!strcmp(option, "push"))
    global.option = PUSH;
}
