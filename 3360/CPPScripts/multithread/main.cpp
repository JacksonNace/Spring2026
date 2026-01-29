
#include <iostream>
#include <vector>
#include <unistd.h>    // For fork(), getpid(), sleep()
#include <sys/wait.h>  // For wait(), waitpid()
#include <sys/types.h> // For pid_t
#include <pthread.h>
#include <string>

using namespace std;



int main() {
  string original_message = "message here";
  string alphabet= "co3 2";
  int size = alphabet.size();
  vector<unsigned int> freq(size);
  vector<pthreat_t> tid(size);
  return 0;
}