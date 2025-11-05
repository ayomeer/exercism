#pragma once

#include <string>
#include <memory>

namespace troy {

// struct data classes, whose objects are going to be created on the heap 
// and pointed to by Human member variables
struct artifact {
    // constructors needed until C++20 (so smart pointer can forward construction arguments to it)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed until C++20 (so smart pointer can forward construction arguments to it)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

// Human class
class human{
    public:
    // possession: smart pointer to artifact (exclusive), default: nullptr
    std::unique_ptr<artifact> possession{nullptr};

    // own_power: smart pointer to power (non-exclusive), default: nullptr
    std::shared_ptr<power> own_power{nullptr};

    // influenced_by: smart pointers to powers, default: nullptr
    std::shared_ptr<power> influenced_by{nullptr};
};

// Loose functions
void give_new_artifact(human& human, std::string artifact_name);
void exchange_artifacts(
    std::unique_ptr<artifact>& artifact1, 
    std::unique_ptr<artifact>& artifact2
);
void manifest_power(human& human, std::string power_effect);
void use_power(human& human_caster, human& human_target);
int power_intensity(human& human_caster);

}  // namespace troy
