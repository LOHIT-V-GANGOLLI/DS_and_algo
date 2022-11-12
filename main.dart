import 'dart:io';

// function to read input
dynamic readFunc(datatype) {
  String? _input = stdin.readLineSync();
  if (_input != null) {
    switch (datatype) {
      case int:
        int result = int.parse(_input);
        return result;
      case double:
        double result = double.parse(_input);
        return result;
      case String:
        String result = _input;
        return result;
      default:
        break;
    }
  }
}

// class for the stack
class Stack {
  List<dynamic> stack = []; // initialised empty stack
  int? capacity;
  int top = -1;

  bool isFull() {
    bool result;
    if (capacity == top) {
      result = true;
    } else {
      result = false;
    }
    return result;
  }

  bool isEmpty() {
    bool result;
    if (top == -1) {
      result = true;
    } else {
      result = false;
    }
    return result;
  }

  void push(dynamic data) {
    if (isFull()) {
      print("Stack Overflow");
    } else {
      top++;
      stack.add(data);
      print("$data added at the top of the stack");
    }
  }

  void pop() {
    if (isEmpty()) {
      print("Stack Underflow");
    } else {
      print("The popped element is ${stack[top]}");

      stack.removeAt(top);
      top--;
    }
  }

  void printStack() {
    for (var i in stack) {
      stdout.write("$i<-");
    }
  }
}

void main() {
  Stack node = new Stack();
  while (true) {
    print(
        "\n**Menu\n\n1. To push into the stack\n2. To pop out of the stack\n3. To display the items of the stack\n4. Exit the program");
    int choice = readFunc(int);
    switch (choice) {
      case 1:
        print("Enter the data to push into the stack");
        var data = readFunc(int);
        node.push(data);
        break;
      case 2:
        node.pop();
        break;
      case 3:
        node.printStack();
        break;
      case 4:
        exit(0);
      default:
        print("Invalid option");
    }
  }
}
