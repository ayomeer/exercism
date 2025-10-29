#include <string>

#pragma once
namespace star_map {

enum class System{
    NA, 
    AlphaCentauri,
    BetaHydri, 
    DeltaEridani,
    EpsilonEridani, 
    Omicron2Eridani,
    Sol
};

}; // namespace star_map

namespace heaven {
class Vessel{
    // constructors & member functions
    public:     
        Vessel(std::string name, int gen): 
            name(name), generation(gen) {}
        Vessel(std::string name, int gen, star_map::System sys): 
            name(name), generation(gen), current_system(sys) {}
        Vessel replicate(std::string name);
        void make_buster();
        bool shoot_buster();
       
    // member variables
    public:
        std::string name{""};
        int generation{0};
        star_map::System current_system{star_map::System::Sol};
        int busters{0};

};

// Helper functions in same namespace
std::string get_older_bob(const Vessel &v1, const Vessel &v2);
bool in_the_same_system(const Vessel &v1, const Vessel &v2);

}; //namespace heaven

