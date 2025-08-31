#pragma once

void help(void);

void version(void);

int install(const char *pkg);

int remove(const char *pkg);

int list(void);

int push(const char *pkg);


int handle_mode(int argc, char **argv);
