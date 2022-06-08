#define MAX_SIZE 1000

class Deque {
  private: 
  
  void *array; 
  int size, front, rear, t_size; 
  
  void memCpy(void*, void*, unsigned long);
  public: 
  //consturctors
  Deque(int, int); //default constructor
  Deque(const Deque &); //copy constructor
  ~Deque(); 

  
  /*       --check if queue is full or not--       */ 
  bool isFull();
  bool isEmpty();
  /*       --check if queue is full or not--       */
  
  /*            --inserting functions--            */
  void insertfront(void *);
  void insertrear(void *);
  /*            --inserting functions--            */
  
  /*            --deleting  functions--            */
  void deletefront();
  void deleterear();
  /*            --deleting  functions--            */
  
  /* --returning value of the array at the index-- */
  void * at(int);
  void * operator[](int); 
  /* --returning value of the array at the index-- */
  
  /*        --operator overloads at here--         */
  void operator= (const Deque&); 
  bool operator==(const Deque&); 
  bool operator!=(const Deque&); 
  /*        --operator overloads at here--         */
  
  /*    --return the front value or rear value--   */
  void * getFront();
  void * getRear();
  /*    --return the front value or rear value--   */ 
};




