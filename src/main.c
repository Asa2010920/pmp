#include "error.h"
#include "global.h"

int handle_args(int argc, char **argv){
  if(argc == 1){
    global.option = HELP;
    return SUCCESS;
  }else if(argc == 2){
    if(!is_option(argv[1])){
      ERROR_FMT_RETURN(ERR_UNKNOWN_OPTION, "Unknown option `%s`\n", argv[1]);
    }
    set_option(argv[1]); 
    return SUCCESS;
  }else {
    if(!is_option(argv[1])){
      ERROR_FMT_RETURN(ERR_UNKNOWN_OPTION, "Unknown option `%s`\n", argv[1]);
    }
    set_option(argv[1]); 
  } 
  return SUCCESS;
}

int main(int argc, char **argv){

  errcode = handle_args(argc, argv);
  CHECK;


  return errcode;
}
