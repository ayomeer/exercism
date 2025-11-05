#include "power_of_troy.h"

namespace troy {


// Loose function implementations
void give_new_artifact(human& human, std::string artifact_name){
    human.possession = std::make_unique<artifact>(artifact_name);
}

void exchange_artifacts(
    std::unique_ptr<artifact>& possession1, 
    std::unique_ptr<artifact>& possession2
){
    possession1.swap(possession2);
}

/// Create new power and give to human
void manifest_power(human& human, std::string power_effect){
    human.own_power = std::make_shared<power>(power_effect);
}

/// Use power on target human, updating their influenced_by attribute
void use_power(human& human_caster, human& human_target){
    human_target.influenced_by = human_caster.own_power;
}

/// Returns power intesity of human's power depending on number of affected targets
/// power_intensity = affected humans + 1 (number of pointers pointing to this power)
int power_intensity(human& human_caster){
    return human_caster.own_power.use_count(); // returns 0, if nullptr
}

}  // namespace troy
