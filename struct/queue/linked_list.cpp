#include<iostream>
using namespace std;
//链式队列
struct Node{
 int data;
 Node *next;
 Node(int x){
  data = x;
  next = NULL;
 }
};

class Queue{ //定义队列的类 
private:
 Node *front; //首结点 
 Node *rear;  //尾结点 
public:
 Queue(){
  front = rear = NULL; //初始化 
 }
 
 ~Queue(){  //析构函数做一个delete 
  Node *tmp;
  while(front){
   tmp = front;
   front = front->next; 
   delete tmp;
  } 
 }
 
 bool isEmpty(){   //判断是否为空 
  return front == NULL;
 } 
 
 void enQueue(int x){ //入队操作 
  Node *tmp;
  tmp = new Node(x);
  if(isEmpty()){
   front = rear = tmp;
  }
  else{
   rear->next = tmp;
   rear = tmp;
  }
 } 
 
 bool deQueue(int *px){ //出队操作 
  if(isEmpty()) return false;
  else{
   *px = front->data;
   Node *tmp;
   tmp = front;
   front = front->next;
   delete tmp;
   if (front == NULL) rear == NULL;
   return true;
  }
 }
 
};

int main()
{ Queue q;
 q.enQueue(11);
 q.enQueue(22);
 q.enQueue(33);
 q.enQueue(44);
 int x;
 q.deQueue(&x);
 cout << x <<endl;
 q.deQueue(&x);
 cout << x <<endl;
 q.deQueue(&x);
 cout << x <<endl;
 q.deQueue(&x);
 cout << x <<endl;
 q.deQueue(&x);
 cout << x <<endl;
 return 0;
 }