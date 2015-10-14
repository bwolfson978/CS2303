/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Function prototype(s):
char *mystrdup(const char* src);

char *mystrndup(const char *s, size_t n);

size_t mystrlen(const char *src);

char *mystrcpy(char *dest, const char *src);

char *mystrncpy(char *dest, const char *src, size_t n);

char *mystrcat(char *dest, const char *src);

char *mystrncat(char *dest, const char *src, size_t n);


