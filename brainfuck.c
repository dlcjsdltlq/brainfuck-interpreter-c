#include <stdio.h>

char mem[32768] = { 0, };

void interpret(char** cmd, char** ptr);

void loop(char** cmd, char** ptr);

int main(void) 
{
  char* cmd = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++++++++++++++.------------.<<+++++++++++++++.>.+++.------.--------.>+.";
  char* ptr = mem;
  while (*cmd) 
  {
    interpret(&cmd, &ptr);
    cmd++;
  }
  return 0;
}

void loop(char** cmd, char** ptr)
{
  char* t_ptr = *ptr;
  char* s_cmd = (*cmd)++;
  char* e_cmd;
  while(*t_ptr)
  {
    interpret(cmd, ptr);
    if (**cmd == ']')
    {
      e_cmd = *cmd;
      *cmd = s_cmd;
    }
    (*cmd)++;
  }
  *cmd = e_cmd;
}

void interpret(char** cmd, char** ptr)
{
  switch (**cmd)
  {
    case '+':
      (**ptr)++;
      break;
    case '-':
      (**ptr)--;
      break;
    case '>':
      (*ptr)++;
      break;
    case '<':
      (*ptr)--;
      break;
    case '.':
      putchar(**ptr);
      break;
    case ',':
      **ptr = getchar();
      break;
    case '[':
      loop(cmd, ptr);
      break;
  }
}
