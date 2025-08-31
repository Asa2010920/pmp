#pragma once

typedef enum {
  HELP,
  VERSION,
  INSTALL,
  REMOVE,
  LIST
} Option;

typedef struct global {
  Option option;
} Global;

extern const char *options[];
extern Global global;

int is_option(const char *name);
