#include <iostream>

int main() {
#if defined(__clang__)
    std::cout << "Clang version: " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__ << "\n";
#elif defined(__GNUC__) || defined(__GNUG__)
    std::cout << "GCC version: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << "\n";
#elif defined(_MSC_VER)
    std::cout << "MSVC version: " << _MSC_VER << "\n";
#else
    std::cout << "Unknown compiler\n";
#endif
    return 0;
}
