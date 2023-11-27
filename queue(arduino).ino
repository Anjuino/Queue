#define MAX_SIZE 5    // Максимальный размер очереди

int queue[MAX_SIZE];   // Массив для хранения элементов очереди
int front = -1;        // Индекс начала очереди
int rear = -1;         // Индекс конца очереди

// Функция для добавления элемента в очередь
void enqueue(int x) {
  if ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1))) {
    // Проверка на переполнение
    Serial.println("Очередь переполнена!");
    return;
  }
  else if (front == -1 && rear == -1) {
    // Если очередь пуста, установка начала и конца на 0
    front = rear = 0;
  }
  else if (rear == MAX_SIZE - 1 && front != 0) {
    // Если конец очереди достигает конца массива и есть место в начале
    rear = 0;
  }
  else {
    // Увеличение конца очереди
    rear++;
  }
  
  // Добавление элемента в очередь
  queue[rear] = x;
}

// Функция для удаления элемента из очереди
int dequeue() {
  if (front == -1 && rear == -1) {
    // Проверка на пустоту очереди
    Serial.println("Очередь пуста!");
    return -1;
  }

  int element = queue[front];  // Получение элемента для удаления
  if (front == rear) {
    // Если в очереди только один элемент, сброс начала и конца очереди
    front = rear = -1;
  }
  else if (front == MAX_SIZE - 1) {
    // Если начало очереди достигает конца массива, установка начала на 0
    front = 0;
  }
  else {
    // Увеличение начала очереди
    front++;
  }

  return element;
}

// Функция для отображения элементов в очереди
void displayQueue() {
  Serial.print("Очередь: ");
  
  if (front == -1) {
    // Если очередь пуста
    Serial.println("Пусто");
    return;
  }
  else if (rear >= front) {
    // Если конец не достиг конца массива
    for (int i = front; i <= rear; i++) {
      Serial.print(queue[i]);
      Serial.print(" ");
    }
  }
  else {
    // Если конец достиг конца массива и есть место в начале
    for (int i = front; i < MAX_SIZE; i++) {
      Serial.print(queue[i]);
      Serial.print(" ");
    }
    for (int i = 0; i <= rear; i++) {
      Serial.print(queue[i]);
      Serial.print(" ");
    }
  }
  
  Serial.println(); // перенос строки
}

void setup() {
  Serial.begin(9600);
  enqueue(10);
  enqueue(20);
  enqueue(30);
  displayQueue();  // Должно вывести "Очередь: 10 20 30"
  dequeue();
  displayQueue();  // Должно вывести "Очередь: 20 30"
  enqueue(40);
  enqueue(50);
  enqueue(100);
  enqueue(200);
  displayQueue();  // Должно вывести "Очередь: 20 30 40 50"
}

void loop() {
  
}


