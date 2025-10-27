// Enter your code below the lines of the families' information

// -- Secret knowledge of the ZHANG family ----------------------------------------------
namespace zhang {
int bank_number_part(int secret_modifier) {
    int zhang_part{8'541};
    return (zhang_part * secret_modifier) % 10000;
}

namespace red {
int code_fragment() { return 512; }
}  // namespace red

namespace blue {
int code_fragment() { return 677; }
}  // namespace blue

}  // namespace zhang

// -- Secret knowledge of the KHAN family ----------------------------------------------
namespace khan {
int bank_number_part(int secret_modifier) {
    int khan_part{4'142};
    return (khan_part * secret_modifier) % 10000;
}

namespace red {
int code_fragment() { return 148; }
}  // namespace red

namespace blue {
int code_fragment() { return 875; }
}  // namespace blue
}  // namespace khan

// -- Secret knowledge of the GARCIA family --------------------------------------------
namespace garcia {
int bank_number_part(int secret_modifier) {
    int garcia_part{4'023};
    return (garcia_part * secret_modifier) % 10000;
}
namespace red {
int code_fragment() { return 118; }
}  // namespace red

namespace blue {
int code_fragment() { return 923; }
}  // namespace blue
}  // namespace garcia

// Enter your code below

// -- Estate Executor -------------------------------------------------------------------
namespace estate_executor {

// Sum up bank_number_part from each family to get account number.
int assemble_account_number(int secret_modifier){
    int sum{0};
    sum +=  zhang::bank_number_part(secret_modifier);
    sum +=   khan::bank_number_part(secret_modifier);
    sum += garcia::bank_number_part(secret_modifier);
    return sum;
}

// Sum up red and blue codes and multiply results to get code.
int assemble_code(){
    int redSum{
         zhang::red::code_fragment() +
          khan::red::code_fragment() +
        garcia::red::code_fragment()
    };
    int blueSum{
         zhang::blue::code_fragment() +
          khan::blue::code_fragment() +
        garcia::blue::code_fragment()
    };
    int code = redSum * blueSum;
    return code;
}

} // namespace estate_executor