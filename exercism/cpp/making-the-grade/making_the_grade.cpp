#include <array>
#include <string>
#include <vector>

// Global variables
const int maxFailScore{40};
const int minPassScore{41};

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> roundedDown;
    roundedDown.reserve(student_scores.size()); // make sure memory doesn't have to be re-allocated a bunch as it grows on heap

    for(double score : student_scores){ // ~python: for score in student_scores
        roundedDown.emplace_back(static_cast<int>(score));
    }
    return roundedDown;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    
    int failCount{0};
    for(int score : student_scores){
        if(score <= maxFailScore){ failCount++; }
    }

    return failCount;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    
    const int gradeDistance = (highest_score - maxFailScore) / 4;

    std::array<int, 4>thresholds{
        minPassScore,
        minPassScore + 1*gradeDistance,
        minPassScore + 2*gradeDistance,
        minPassScore + 3*gradeDistance
    };
    return thresholds;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, 
    std::vector<std::string> student_names
){
    std::vector<std::string> organizedVector;
    organizedVector.reserve(student_names.size());

    int i{0};
    for(std::string name : student_names){
        organizedVector.emplace_back( 
            std::to_string(i+1) + ". " +            // Rank
            name + ": " +                           // Name
            std::to_string(student_scores.at(i))    // Score
        );
        i++;
    }
    return organizedVector;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(
    std::vector<int> student_scores,
    std::vector<std::string> student_names
){
    std::string nameFirstPerfect{""};

    int i{0};
    for(int score : student_scores){
        std::string outp{std::to_string(score)};

        if(score == 100){
            nameFirstPerfect = student_names.at(i);
            break;
        }
        i++;
    }

    return nameFirstPerfect;
}
