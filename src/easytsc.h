#ifndef EASY_TSC_H
#define EASY_TSC_H

#include <iostream>
#include <limits>
#include <unistd.h>

class Tsc
{
  private:
    unsigned long long calibrate_; // Time of TSC process itself
    unsigned long long t_;         // Temporary measure
    unsigned long long time_;      // Minimum value of measures made

    static __inline__ unsigned long long rdtsc( void );
    void start_calibrate();
    void stop_calibrate();

  public:
    Tsc();
    void start();
    void stop();
    friend std::ostream& operator<<( std::ostream& os, const Tsc& tt );
};

#endif // EASY_TSC_H
