#pragma once

#include <string>
#include <memory>

namespace troy {

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

class Human{
    public:
    // possession: smart pointer to artifact (exclusive), default: nullptr
    std::unique_ptr<artifact> possession{nullptr};

    // own_power: smart pointer to power (non-exclusive), default: nullptr
    std::shared_ptr<power> own_power{nullptr};

    // influenced_by: smart pointers to powers, default: nullptr
    std::shared_ptr<power> influenced_by{nullptr};
};

}  // namespace troy
