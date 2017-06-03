#include "drivercomm.hpp"

using namespace std;

Driver::Driver() :
        counter(0),
        ok(true)
{
        reader = thread(&Driver::reader_thread, this);
}

Driver::~Driver(){
        ok = false;
        reader.join();
}

void Driver::reader_thread(){
        while(ok == true) {
                counter++;

                if(counter == 20)
                        cv.notify_one();

                this_thread::sleep_for(chrono::milliseconds(100));
        }
}

int Driver::getCount(){
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk);

        return counter;
}
