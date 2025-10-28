#include <string>
#include <vector>
#include <iostream>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    std::string name{};     // Name of the candidate
    int votes{};            // Number of votes the candidate has
};

// TODO: Task 1
// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(ElectionResult& election_result_ref){
    return election_result_ref.votes;
}


// TODO: Task 2
// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult& election_result_ref, int new_votes){
    election_result_ref.votes += new_votes;
}


// TODO: Task 3
// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.

ElectionResult& determine_result(std::vector<ElectionResult>& final_count){
  
    int highest_votes{0};
    int idx_highestVotes{0};

    int i{0};
    for (ElectionResult result : final_count){
        if(result.votes > highest_votes){
            idx_highestVotes = i;
            highest_votes = result.votes;
        }
        i++;
    }
    ElectionResult& refTo_winningResult{final_count.at(idx_highestVotes)};
    refTo_winningResult.name = std::string("President ") + refTo_winningResult.name;
    
    return refTo_winningResult;
}


}  // namespace election
