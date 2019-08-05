class Node:
    def __str__(self):
        return (
        "name: " + self.name + " department: " + self.dep + " Grades : " + str(self.grades) + " GPA: " + str(self.gpa))

    def __init__(self, name="", dep="", grades=[]):
        if len(grades) > 0:
            self.name = name
            self.dep = dep
            self.grades = (grades)
            self.gpa = sum(grades * 4) / (len(grades) * 100)
            self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def add_student(self, name, dep, grades):
        new = Node(name, dep, grades)
        new.next = self.head
        self.head = new

    def max_gpa(self):
        tmp = self.head
        mx = 0
        while (tmp != None):
            if (tmp.gpa > mx):
                mx = tmp.gpa
                ret = tmp
            tmp = tmp.next
        return ret

    def min_gpa(self):

        tmp = self.head
        mn = 4511981981958196881819
        ret= None
        while (tmp != None):
            if (tmp.gpa < mn):
                mn = tmp.gpa
                ret = tmp
            tmp = tmp.next
        return ret

    def find_student(self, name):

        tmp = self.head
        while (tmp.next != None):
            if (tmp.name == name):
                break
            tmp = tmp.next
        if tmp == None:
            print("cant find student")
        return tmp

    def find_by_dep(self,dep):
        tmp = self.head
        while (tmp != None):
            if (tmp.dep == dep):
                print(tmp)
            tmp = tmp.next

    def delete_student(self, name):
        node = self.head
        if node == None:
            return False
        if node.name == name:
            self.head = self.head.next
            return True
        while node.next is not None:
            if node.next.name == name:
                node.next = node.next.next
                break
            node = node.next

        return node.next is not None

    def display(self):
        node = self.head

        while node is not None:
            print(node)
            node = node.next
    def sort(self):
        node = self.head

        while node != None:
            snode = node.next
            while snode != None:
                if snode.gpa < node.gpa:
                    snode.gpa, node.gpa = node.gpa , snode.gpa
                snode = snode.next
            node = node.next

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
        if tail is None:
            return None
        if tail.next is None:
            ret = self.head
            self.head = None
            return ret

        while (tail.next != None):
            if tail.next.next == None:
                ret = tail.next
                tail.next = None
                break
            tail = tail.next
        return ret


class BST_Node:
    def __init__(self, gpa):
        self.gpa = gpa
        self.left = None
        self.right = None


class BST:
    def __init__(self, students_list=None):
        self.students_list = students_list
        size = 0
        root = None
        self.fillBST()

    def add(self, root, gpa):
        if root == None:
            root = BST_Node(gpa)
            self.size = self.size + 1
            return
        if root.gpa > gpa:
            root.left = self.add(root.left, gpa)
        elif root.gpa < gpa:
            root.right = self.add(root.right, gpa)
        else:
            return root

    def fillBST(self):
        node = self.students_list

        while (node != None):
            if (node.gpa):
                self.add(self.root, node.gpa)
            node = node.next


def run():
    students_list = LinkedList()
    queue = Queue()
    binarySearchTree = BST()
    while True:
        choice = input("-----------------------------------------------------------------------------------------\n\
Operations Menu of linked list of students\n \
-----------------------------------------------------------------------------------------\n\
1. Add a Student \n\
\
2. Delete a student\n\
\
3. Calculate and display the GPA of students\n\
\
4. Show student having the maximum GPA\n\
5. Show student having the minimum GPA\n\
\
6. Find a student\n\
7. Print all students\n\
8. Print the students of a given department\n\
9. Sort the list using the GPA field\n\
10. Store the students of CS department in a queue Q\n\
11. Store all GPA in a binary search tree BST\n\
12. Exit\n\
")
        while choice.isdigit() == False or (choice.isdigit() == True and (1 <= float(choice) <= 12) == False):
            choice = input("Enter a number in range 1-12: ")
        choice = float(choice)
        if choice == 1:
            print("Please enter Studet Details")
            name = input("Name: ")
            deb = input("Department: ")
            grades = list(input("Grades (seperated by space): ").split())
            ok = True
            for i in range(len(grades)):
                if grades[i].isdigit() == False:
                    print("Grades has to be numbers, error")
                    ok = False
                    break
                grades[i] = float(grades[i])
            if ok:
                students_list.add_student(name, deb, grades)
        elif choice == 2:
            name = input("Name of the student to delete: ")
            ret = students_list.delete_student(name)
            if ret:
                print("Student Deleted")
            else:
                print("Student was not found in the list")
        elif choice == 3:
            name = input("Student name: ")
            ret = students_list.find_student(name)
            if ret is None:
                print("Student Not found")
            else:
                print(name + "'s GPA = " + str(ret.gpa))
        elif choice == 4:
            ret = students_list.max_gpa()
            if ret is None:
                print("Student Not found")
            else:
                print(ret)

        elif choice == 5:
            ret = students_list.min_gpa()
            if ret is None:
                print("Student Not found")
            else:
                print(ret)

        elif choice == 6:
            name = input("Student name: ")
            ret = students_list.find_student(name)
            if ret is None:
                print("Student Not found")
            else:
                print(ret)
        elif choice == 7:
            students_list.display()
        elif choice == 8:
            deb = input("Department: ")
            students_list.find_by_dep(deb)
        elif choice == 9:
            students_list.sort()
            print("List Sorted")
        elif choice == 10:
            queue = Queue(students_list)
            print("added to the queue")
        elif choice == 11:
            binarySearchTree = binarySearchTree(students_list)
            print("added to the BST")

        elif choice == 12:
            return


run()
