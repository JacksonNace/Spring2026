#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>
using namespace std;

struct info_from_main{
  string *message;
  char ch;
  unsigned int frequency;
};

void * frequency_counter(void * void_ptr) {
  info_from_main * ptr = (info_from_main*) void_ptr;
  ptr->frequency = 0;
  for (char c : *(ptr->message)){
    if (c == ptr->ch)
      (ptr->frequency)++;
  }
  return nullptr;
}

int main() {
  string original_message = "COSC 3360 SPRING 2026 CARLOS RINCON CASTRO";
  string alphabet = "CO3 2";
  int size = alphabet.size();
  vector<unsigned int> freq(size);
  vector<pthread_t> tid(size);
  info_from_main result;
  
  for (int i=0;i<size;i++) {
    result.message = &original_message;
    result.ch = alphabet.at(i);
    if(pthread_create(&tid.at(i),nullptr,frequency_counter,(void *)&result) != 0)
    {
      cerr << "Error creating the thread" << std::endl;
      exit(0);
    }
  }
  for (int i=0;i<size;i++){
    pthread_join(tid.at(i),nullptr);
  }
  for (int i=0;i<size;i++){
    std::cout << "Frequency for " << alphabet.at(i) << " = " << freq.at(i) << std::endl;
  }
  return 0;
}