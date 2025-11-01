#include "power_of_troy.h"

namespace troy {


// Loose function implementations
void give_new_artifact(Human& human, std::string artifact_name){
    human.possession = std::make_unique<artifact>(artifact_name);
}

void exchange_artifacts(
    std::unique_ptr<artifact>& possession1, 
    std::unique_ptr<artifact>& possession2
){
    possession1.swap(possession2);
}

}  // namespace troy
