#include "design_patterns/command.h"
#include <memory>

int main() {
    design_patterns::ChessGame chessGame;
    design_patterns::CommandManager commandManager;
    auto moveCommand1 = std::make_unique<design_patterns::ChessMoveCommand>(
        chessGame, design_patterns::ChessMove{"white pawn", "a2", "a4"});

    auto moveCommand2 = std::make_unique<design_patterns::ChessMoveCommand>(
        chessGame, design_patterns::ChessMove{"black knight", "b8", "c6"});

    commandManager.execute(std::move(moveCommand1));
    commandManager.execute(std::move(moveCommand2));
    commandManager.undo();
    commandManager.undo();
    commandManager.redo();
}