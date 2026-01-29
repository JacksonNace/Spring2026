// fork() - > how we create multithreading
// #include <sys.waith> -> kill old processes, call wait(nullptr)

#include <iostream>
#include <vector>
#include <unistd.h>    // For fork(), getpid(), sleep()
#include <sys/wait.h>  // For wait(), waitpid()
#include <sys/types.h> // For pid_t

using namespace std;

int main() {
  cout << "Process ID: " << getpid() << endl;
  return 0;
}