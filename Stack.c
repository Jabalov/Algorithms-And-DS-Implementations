typedef struct stack {
  int top;
  StackEntry entry[MAXSTACK];
} Stack;

int isEmpty(Stack *ps) {
  return ps -> top == 0;
}

int isFull(Stack *ps) {
  return (ps -> top == MAXSTACK);
}

void Pop(StackEntry *pe, Stack *ps) {
    *pe = ps -> entry[-- ps -> top];
}

void Push(StackEntry element, Stack *ps ) {
    ps -> entry[ps -> top ++] = e, return 1;
}

void StackTop(StackEntry *pe, Stack *ps) {
  *pe = ps -> entry[ps -> top -1];
}
int Size(Stack *ps) {
    return ps -> top;
}

void ClearStack(Stack *ps) {
  ps -> top = 0;
}
void CreateStack(Stack *ps) {
  ps -> top = 0;
}

void Display(StackEntry e) {
  printf("e is: %d\n", e );
}

void TraverseStack(Stack *ps, void(*pf)(StackEntry)) {
  for (int i = p->top; i > 0; i--) {
    (*pf)(ps -> entry[i-1]);
  }
}

void main(int argc, char const *argv[]) {
  StackEntry e;
  Stack s;
  CreateStack(&s);

  if(!isFull(&s))
    Push(element, &s);

  if(!isEmpty(&s))
    Pop(&e, &s);

  StackTop(&e, s);

  int x = Size(&s);

  ClearStack(&s);
  return 0;
}
