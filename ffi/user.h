typedef struct {
  int id;
  char* name;
} User;

User * create_user(int id, char *name);
char * get_user_name(User *user);
void free_user(User *user);