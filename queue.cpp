#include "stdafx.h"
#include <iostream> 
using namespace std; 
 
class Queue {   
static const int SIZE=10; // размер очереди (массива)
int *queue; 
int head, tail; // голова и хвост очереди
public : // методы очереди
   Queue ();
   ~Queue (void); 
   void push ( int num ) ; // поместить в очередь элемент
   friend void out(Queue q); // вывести в консоль
   int size(); // вернуть размер очереди
   void pop(); // удалить элемент
   int front(); // получить голову очереди
   int back(); // получить хвост очереди

                            // Методы очереди //  
                            
//----------------
Queue::Queue() 
{
   queue = new int[SIZE]; // создаем объект, массив очереди
   head = tail = 0 ; // значение головы и хвоста
} 
//----------------

Queue::~Queue (void); // освобождаем память 
{
   delete [] queue;
} 
//----------------
void out(Queue q){ 
    for(int i=q.head+1;i<q.tail+1;i++)
    {
        cout<<" "<<q.queue[i]; // выводим элементы очереди
    }
}
//----------------
void Queue::push ( int num ) 
{ 
   if ( tail+1 ==head || ( tail+ 1 ==SIZE && !head )) { 
     cout << "очередь полна\n" ; 
     return ; 
   } // проверили очередь на заполненность
   tail++; 
   if ( tail==SIZE ) tail = 0 ;
   queue [ tail ] = num; // помещаем в очередь 
} 
//----------------
void Queue::pop() 
{ 
   if ( head == tail ) { 
     cout << "очередь пуста\n" ; 
     return ;
   } 
   head++; 
   if ( head==SIZE ) head = 0 ; 
  
} 
//----------------
int Queue::size()
{   int s=0;
    for(int i=head;i<tail;i++)
    {
        s++;
    }
    return s; // получаем размер очереди
}
//----------------
int Queue::back()
{
    return queue[tail]; // получили последний элемент очереди
}
//----------------
int Queue::front()
{
    return queue[head+1]; // получили первый элемент очереди
}

} ;
//---------------
int main () 
{
   setlocale(LC_ALL,"rus");
   Queue queue1, queue2; 
   int i; 
   for (i= 1 ; i <= 5 ; i++ ) 
   { 
        queue1.push ( i ) ;
   } 
   cout<<"Изначальная очередь ";
   out(queue1);
   cout<<endl;
   cout<<"введите еще элемент: ";
   int n;
   cin>>n;
   queue1.push(n);
   cout<<"теперь очередь имеет следующий вид"<<endl;
   out(queue1);
   cout<<endl;
   cout<<"Размер очереди:"<<endl;
   cout<<queue1.size();
   cout<<endl;
   cout<<"дальний элемент:"<<endl;
   cout<<queue1.back();
   cout<<endl;
   cout<<"ближний элемент"<<endl;
   cout<<queue1.front();
   cout<<endl;
   cout<<"удаление элемента";
   queue1.pop();
   cout<<endl;
   cout<<"текущие данные";
   out(queue1);
   cout<<endl;
   cout<<"еще одно добавление элемента";
   queue1.push(n);
   out(queue1);
   cout<<endl;
   system("pause");
   return 0 ; 
}