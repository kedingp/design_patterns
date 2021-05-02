#include "design_patterns/state.h"

namespace design_patterns {
std::optional<State> Transitions::operator()(const Off &, const PushOnOffButton &) {
    std::cout << "Turn-on machine ...\n";
    return Idle{};
}

std::optional<State> Transitions::operator()(const Idle &,
                                             const PushCokeButton &) {
    std::cout << "Start serving coke ...\n";
    return ServingCoke{};
}

std::optional<State> Transitions::operator()(const Idle &,
                                             const PushOnOffButton &) {
    std::cout << "Turn-off machine ...\n";
    return Off{};
}

std::optional<State> Transitions::operator()(const ServingCoke &,
                                             const PushCokeButton &) {
    std::cout << "Stop serving coke ...\n";
    return Idle{};
}
} // namespace design_patterns