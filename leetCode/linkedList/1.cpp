class MyLinkedList {
private:
  struct node {
    int val;
    struct node *next;
  }
  struct node *head;

public:
  MyLinkedList() {
    head = NULL;
  }

  int get(int index) {
    struct node *tmp;
    tmp = head;
    int cnt(0);

    while(tmp != NULL){
      if(cnt == index){
        return tmp -> val;
      } else {
        tmp = tmp -> next;
      }
      cnt ++;
    }
    return -1;
  }

  void addAtHead(int data) {
    struct node *tmp = new node;
    tmp -> val = data;
    tmp -> next = head;
    head = tmp;
  }

  void addAtTail(int data) {
    struct node *tmp;
    tmp = head;

    struct node *new = new node;
    new -> val = data;
    new -> next = NULL;

    while(tmp -> next != NULL) {
      tmp = tmp -> next;
    }
      tmp -> next = new;
  }

  void addAtIndex(int index, int data){
    int cnt(0);
    struct node *new = new node;
    struct node *itr;

    new -> val = data;
    new -> next = NULL;
    itr = head;

    if(head == NULL && index == 0) {
      head = new; return;
    }
    if(index == 0) {
      new -> next = head;
      head = new;
      return;
    }
    while(cnt + 1 != index) {
      itr = itr -> next;
      if(itr == NULL) return;
      cnt ++;
    }

    if(itr == NULL) return;
    new -> next = itr -> next;
    itr -> next = new;
    return;
  }

  void deleteAtIndex(int index) {
    struct node *tmp, *dup;
    int cnt(0);
    tmp = head;
    if(head == NULL) retun;

    while(cnt + 1 != index) {
      tmp = tmp -> next;
      if(tmp == NULL) return;
      cnt ++;
    }

    dup = tmp -> next;
    if(dup == NULL) {
      temp->next = NULL;
      return;
    }
    tmp->next = dup->next;
    delete(dup);
    return;
  }
}
