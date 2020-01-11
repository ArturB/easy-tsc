#include <iostream>
#include <limits>
#include <unistd.h>

class Tsc
{
  private:
    unsigned long long calibrate_; // Time of measuring process itself
    unsigned long long t_;         // Temporary measure
    unsigned long long time_;      // Min of measures made

    static __inline__ unsigned long long rdtsc( void )
    {
        unsigned hi, lo;
        __asm__ __volatile__( "rdtsc" : "=a"( lo ), "=d"( hi ) );
        return ( static_cast<unsigned long long>( lo ) ) | ( ( static_cast<unsigned long long>( hi ) ) << 32 );
    }

    void start_calibrate()
    {
        calibrate_ = __LONG_LONG_MAX__;
        t_ = rdtsc();
    }

    void stop_calibrate()
    {
        t_ = rdtsc() - t_;
        if( t_ < calibrate_ )
            calibrate_ = t_;
    }

  public:
    Tsc()
        : t_(0), time_( 0 )
    {
        usleep(10000);
        for( unsigned i = 0; i < 10000000; ++i ) {
            start_calibrate();
            stop_calibrate();
        }
    }

    void start()
    {
        time_ = __LONG_LONG_MAX__;
        t_ = rdtsc();
    }

    void stop()
    {
        t_ = rdtsc() - t_;
        if( t_ < time_ )
            time_ = t_;
    }

    friend std::ostream& operator<<( std::ostream& os, const Tsc& tt )
    {
        if(tt.time_ == 0) {
            os << 0;
        }
        else {
            os << tt.time_ - tt.calibrate_;
        }
        return os;
    }
};
