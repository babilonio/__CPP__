#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
#include <atomic>

class Driver {
private:
/* data */
unsigned long int counter;
std::thread reader;

std::mutex m;
std::condition_variable cv;
std::atomic<bool> ok;

void reader_thread();

public:
Driver ();
~Driver ();

int getCount();
};

#endif // DRIVER_HPP
