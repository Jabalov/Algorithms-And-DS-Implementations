class Node:
    def __str__(self):
        return ("name: " + self.name +  " department: "+self.dep + " Grades : " + str(self.grades) + " GPA: " + str(self.gpa))
    def __init__(self, name, dep, grades):
        self.name = name
        self.dep = dep
        self.grades = list(grades)
        self.gpa = sum(grades)/len(grades) * 10
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def add_student(self, name, dep, grades):
        new = Node(name, dep, grades)
        new.next = self.head
        self.head = new

    def max_gpa():
        tmp = Node()
        tmp.next = self.head
        mx = 0
        while(tmp.next != None):
            if(tmp.gpa > mx):
                mx = tmp.gpa
            tmp = tmp.next
        return tmp.name

    def min_gpa():
        tmp = Node()
        tmp.next = self.head
        mn = 0
        while(tmp.next != None):
            if(tmp.gpa < mn):
                mn = tmp.gpa
            tmp = tmp.next
        return tmp.name

    def find_student(name):
        tmp = Node()
        tmp.next = tmp.head


        while(tmp.next != None):
            if(tmp.name == name):
                break
            tmp = tmp.next
        if tmp == None:

            print("cant find student")
        return tmp

    def find_by_dep(dep):
        tmp = Node()
        tmp.next = self.head

        while(tmp.next != None):
            if(tmp.dep == dep):
                print(tmp)
            tmp = tmp.next

def selection_sort(linked_list):
    flag = True
    cur = linked_list.head
    precur = None
    while flag:
        min_node = cur
        min_prev = None
        nxt = min_node.next
        prev = cur
        flag = False
        while nxt != None:
            if nxt.gpa < min_node.gpa:
                min_prev = prev
                min_node = nxt
                flag = True
            if nxt.next != None and nxt.gpa > nxt.next.gpa:
                flag = True
            prev = nxt
            nxt = nxt.next
        cur_nxt = cur.next
        min_nxt = min_node.next
        precur = cur
        cur = cur.next

class Queue:
    def __init__(self, students_list=None):
        self.head = students_list

    def push(self, new):
        new.next = self.head
        self.head = new

    def pop(self):
        tail = self.head
        ret = None
        if tail is None :
            return None
        if tail.next is None:
            ret = self.head
            self.head = None
            return ret

        while(tail.next != None):
            if tail.next.next == None:
                ret = tail.next
                tail.next = None
                break
            tail = tail.next
        return ret

class BST_Node:
    def __init__(self, gpa):
        self.gpa = gpa
        sef.left = None
        self.right =None



class BST:
    def __init__(self, students_list):
        self.students_list = students_list
        size = 0
        root = None
        fillBST()

    def add(self, root, gpa):
        if root == None:
            root = BST_Node(gpa)
            self.size = self.size + 1
            return
        if root.gpa > gpa:
            root.left = add(root.left , gpa)
        else if root.gpa < gpa:
            root.right = add(root.right, gpa)
        else:
            return root


    def fillBST(self):
        node = self.students_list

        while(node != None):
            if(node.gpa):
                add(self.root, gpa)
            node = node.next
