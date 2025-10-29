#include "doctor_data.h"

using namespace heaven;

Vessel Vessel::replicate(std::string name){
    Vessel NewVessel{
        name=name,
        generation=this->generation+1,
    };
    return NewVessel;
}

void Vessel::make_buster(){
    this->busters += 1;
}

bool Vessel::shoot_buster(){
    if(this->busters > 0){
        this->busters -= 1;
        return true; // success
    }
    else{
        return false; // !success (no busters available)
    }
}

// Helper functions in same namespace
std::string heaven::get_older_bob(const Vessel &v1, const Vessel &v2){
    return (v1.generation < v2.generation) ? v1.name : v2.name;
}

bool heaven::in_the_same_system(const Vessel &v1, const Vessel &v2){
    return v1.current_system == v2.current_system;
}