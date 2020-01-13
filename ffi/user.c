#include <stdlib.h>
#include <stdio.h>
#include "user.h"

User * create_user(int id, char *name) {
  User *user = calloc(1, sizeof(User));
  user->id = id;
  user->name = name;
  return user;
}
char * get_user_name(User *user) {
  return user->name;
}
void free_user(User *user) {
  puts("free_c");
  free(user);
}
