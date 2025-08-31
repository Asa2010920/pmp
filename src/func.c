#include "func.h"
#include "error.h"
#include "global.h" 

void help(void){

}

void version(void){

}

int install(const char *pkg){
  (void)pkg;
  return SUCCESS;
}

int remove(const char *pkg){
  (void)pkg;
  return SUCCESS;
}

int list(void){
  return SUCCESS;
}

int push(const char *pkg){
  (void)pkg;
  return SUCCESS;
}

int handle_mode(int argc, char **argv){
  int err = SUCCESS;

  switch(global.option){
    
    case HELP: help(); break;
    
    case VERSION: version(); break;

    case INSTALL: {
      if(argc == 2){
        ERROR_RETURN(ERR_NO_ARGS, "No pkg specified.\n");
      }
      
      for(int i = 2; i < argc; i++){
        err = install(argv[i]);
        if(!err)
          return err;
      }
      break;
    } 

    case REMOVE: {
      if(argc == 2){
        ERROR_RETURN(ERR_NO_ARGS, "No pkg specified.\n");
      }
      
      for(int i = 2; i < argc; i++){
        err = remove(argv[i]);
        if(!err)
          return err;
      }
      break;
    } 

    case LIST: {
      if(argc != 2){
        ERROR_RETURN(ERR_TOO_MUCH_ARGS, "Use only `pmp list`\n");
      }
      err = list();
      break;
    }

    case PUSH: {
      if(argc == 2){
        ERROR_RETURN(ERR_NO_ARGS, "No pkg specified.\n");
      }
      
      for(int i = 2; i < argc; i++){
        err = push(argv[i]);
        if(!err)
          return err;
      }
      break;
    } 
    
  }
  return err;
}
