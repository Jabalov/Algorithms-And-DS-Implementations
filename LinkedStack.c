#include <stdlb.h>

typedef struct stacknode {
  StackEntry entry;
  struct stacknode *next;
}Stacknode;

typedef struct stack {
  Stacknode *top;
}Stack;

void CreateStack(Stack *ps) {
  ps -> top = NULL;
}

void Push(StackEntry e, Stack *ps) {
  Stacknode *pn = (Stacknode *)malloc(sizeof(Stacknode));
  pn -> entry = e;
  pn -> next = ps -> top;
  ps -> top = pn;
}

void main() {
  Stack s;
  StackEntry e;

  CreateStack(&s);
  Push(&s, e)









  /* code */
  return 0;
}
