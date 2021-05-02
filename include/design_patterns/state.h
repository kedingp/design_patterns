#include <iostream>
#include <optional>
#include <variant>

namespace design_patterns {

class PushOnOffButton {};
class PushCokeButton {};

using Event = std::variant<PushOnOffButton, PushCokeButton>;

// States
class Off {};
class Idle {};
class ServingCoke {};

using State = std::variant<Off, Idle, ServingCoke>;

// Tranistion
class Transitions {
  public:
    std::optional<State> operator()(const Off &, const PushOnOffButton &);

    std::optional<State> operator()(const Idle &, const PushCokeButton &);

    std::optional<State> operator()(const Idle &, const PushOnOffButton &);

    std::optional<State> operator()(const ServingCoke &,
                                    const PushCokeButton &);

    template <typename State_t, typename Event_t>
    std::optional<State> operator()(const State_t &, const Event_t &) const {
        std::cout << "Can not be handled ...\n";
        return std::nullopt;
    }
};

template <class StateVariant, class EventVariant, class TransitionsVariant>
class CokeDispenser {
  public:
    void dispatch(const EventVariant &event) {
        std::optional<State> newState =
            std::visit(TransitionsVariant{}, m_currentState, event);
        if (newState) {
            m_currentState = *std::move(newState);
        }
    }

  private:
    StateVariant m_currentState;
};
} // namespace design_patterns