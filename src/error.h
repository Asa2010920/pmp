#pragma once

enum {
  SUCCESS = 0,
  ERR_TOO_MUCH_ARGS = -1,
  ERR_NO_ARGS
};

static int errcode = SUCCESS;
