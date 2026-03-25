#include <iostream>
#include <thread>

//add // infront of /* to uncomment code example wanted



//mutex example, used for locking thread and protecting shared var, or when working with async lambdas like dpp (ai made)

/*

#include <mutex>
#include <condition_variable>
#include <atomic>

// Pass all shared resources by reference
void child_thread_task(std::atomic<bool> &ready, int &shared_result, std::mutex &mtx, std::condition_variable &cv) {
    //work here since main is just waiting for the later return 
    int calculated_value = 42; 
    {
        // Use a scope block to ensure the lock is released quickly
        std::lock_guard<std::mutex> lock(mtx);
        //dont work here, its just for updating the passed var
        shared_result = calculated_value;
        ready = true; 
    } // lock released here

    // Notify the main thread
    cv.notify_one();
}

int main() {
    std::mutex mtx;
    std::condition_variable cv;
    int shared_result = 0;
    std::atomic<bool> ready(false);

    std::cout << "Main thread: Starting child thread...\n";

    // Pass the function and arguments. Use std::ref for references. not &
    std::thread t(child_thread_task, std::ref(ready), std::ref(shared_result), std::ref(mtx), std::ref(cv));

    // Main thread waits for the result
    //single mutex object used just accessed by unique lock here, not lock guard as it allows for checking
    std::unique_lock<std::mutex> lock(mtx);
    
    // Wait until the 'ready' flag is true. 
    // This handles "spurious wakeups" automatically.
    cv.wait(lock, [&ready]{ return ready.load(); }); 
    lock.unlock(); 
    t.join();

    std::cout << "Main thread: Child thread returned value: " << shared_result << '\n';
    
    return 0;
}

//*/



//join example, main simply waits because of t.join()

/*

std::string child_task(std::string &example_arg){
    //work here while main waits
    example_arg="returned";
    return example_arg;
}

int main(){
    std::cout<<"Main thread: Starting child thread...\n";

    // Pass the function and arguments. Use std::ref for references. not &
    std::string arg="passed";
    std::cout<<"Initial value: "<<arg<<'\n';

    std::thread t(child_task, std::ref(arg)); 
    t.join();//makes main wait

    //does not cause data race as main was forced to wait
    std::cout<<"Main thread: Child thread returned value: "<<arg<<'\n';

    return 0;
}

//*/
