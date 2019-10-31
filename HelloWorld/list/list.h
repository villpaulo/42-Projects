#ifndef list_h

#define list_h

#include <string.h>

typedef struct        s_list { 
  void                *data; 
  struct s_list       *next;
  struct s_list       *begin_list; 
  struct s_list       *end_of_list; 
  size_t              data_size; 
}                     t_list;

#endif

