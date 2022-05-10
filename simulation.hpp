
#include "solarsystem.hpp"

enum SimulationMode
{
    VelocityVerlet,
};

class Simulation {

    public:
        Simulation();
        ~Simulation();

        void runSimulation();

        inline void setSolarSystem(SolarSystem new_system)      { system_ = new_system; };
        inline void setTimeStep( double new_dt )                { dt_ = new_dt; };
        inline void setSimulatedTime( double new_time )         { simulated_time_ = new_time; };
        inline void setSteps( int new_steps )                   { steps_ = new_steps; };
        inline void setWriteInterval( int new_interval )        { write_interval_ = new_interval; };
        inline void setPrintInterval( int new_interval )        { print_interval_ = new_interval; };
        inline void setSimulationMode( SimulationMode new_mode) { mode_ = new_mode; };

    private:
        SolarSystem     system_;
        double          dt_ = 10.0;
        double          simulated_time_; // years? check this
        int             steps_ = 6155815;
        int             write_interval_ = 1000;
        int             print_interval_ = 10000;
        SimulationMode  mode_ = SimulationMode::VelocityVerlet;
};