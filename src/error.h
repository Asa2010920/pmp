#pragma once

#include <stdio.h>

enum {
  SUCCESS = 0,
  ERR_TOO_MUCH_ARGS = -1,
  ERR_NO_ARGS,
  ERR_UNKNOWN_OPTION
};

#define CHECK if(errcode != SUCCESS) return errcode
#define ERROR(msg) fprintf(stderr, "%s", msg)
#define ERROR_FMT(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#define ERROR_RETURN(code, msg) ERROR(msg); return code
#define ERROR_FMT_RETURN(code, fmt, ...) ERROR_FMT(fmt, __VA_ARGS__); return code

static int errcode = SUCCESS;
