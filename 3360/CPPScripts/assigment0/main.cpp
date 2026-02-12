// Complete the C++ template file presented below to write a multithreaded program to transform numbers from decimal to binary. The input for the program is a list of n positive integer values. You must complete the following tasks:
// Create n child threads. Each child thread will receive a value from the input numbers.
// Write the child thread function that receives the positive integer and the location to store the binary number (std::string).
// Make sure the parent thread waits for all child threads to end before printing the output.
// Notes:

// You can safely assume that the input is always valid.
// Use the comments in the provided template file to complete your solution.
// Not using POSIX threads will translate into a penalty of 100%.



#include <pthread.h>
#include <iostream>
#include <string>
#include <vector>
// ::vector
struct arguments
{
	int value;
	std::string binCode;
};

// Write the child thread function here
void * dec_2_bin (void * void_ptr){
    arguments *ptr = (arguments *) void_ptr;
    int value = ptr->value;
    do{
        ptr->binCode = std::to_string(value % 2) + ptr->binCode;
        value = value/2;
    }
    while(value > 0);
    return nullptr;
}


int main()
{
    std::vector<arguments> arg;
    arguments tempHolder;
    tempHolder.binCode = "";
	while (std::cin >> tempHolder.value)
    {
        arg.push_back(tempHolder);
    }
    int nValues = arg.size();
 	pthread_t *tid = new pthread_t[nValues];
        
	for(int i=0;i<nValues;i++)
	{
        
		if(pthread_create(&tid[i], nullptr, dec_2_bin, (void *)&arg.at(i)) != 0) 
		{
			std::cerr << "Error creating thread" << std::endl;
			return 1;

		}		
	}
	
	// Wait for the other threads to finish.
    // Call pthread_join here
    for(int i=0; i<nValues;i++){
        pthread_join(tid[i], nullptr);
    }
    
    for (int i = 0; i < nValues; i++){
        std::cout << arg[i].value << " base 10 is equal to " << arg[i].binCode << std::endl;
    }
    if (tid!=nullptr)
        delete[] tid;
    return 0;
}