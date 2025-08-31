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
  size_t n = sizeof(options) / sizeof(options[0]);
  
  for(size_t i = 0; i < n; i++){
    if(!strcmp(name, options[n])){
      return 0;
    }
  }
  return 1;
}
