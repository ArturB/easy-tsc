#include "easytsc.h"

__inline__ unsigned long long Tsc::rdtsc( void )
{
    unsigned hi, lo;
    __asm__ __volatile__( "rdtsc" : "=a"( lo ), "=d"( hi ) );
    return ( static_cast<unsigned long long>( lo ) ) | ( ( static_cast<unsigned long long>( hi ) ) << 32 );
}

void Tsc::start_calibrate()
{
    calibrate_ = __LONG_LONG_MAX__;
    t_ = rdtsc();
}

void Tsc::stop_calibrate()
{
    t_ = rdtsc() - t_;
    if( t_ < calibrate_ )
        calibrate_ = t_;
}

Tsc::Tsc()
    : t_( 0 )
    , time_( 0 )
{
    usleep( 10000 );
    for( unsigned i = 0; i < 10000000; ++i ) {
        start_calibrate();
        stop_calibrate();
    }
}

void Tsc::start()
{
    time_ = __LONG_LONG_MAX__;
    t_ = rdtsc();
}

void Tsc::stop()
{
    t_ = rdtsc() - t_;
    if( t_ < time_ )
        time_ = t_;
}

std::ostream& operator<<( std::ostream& os, const Tsc& tt )
{
    if( tt.time_ == 0 ) {
        os << 0;
    } else {
        os << tt.time_ - tt.calibrate_;
    }
    return os;
}
