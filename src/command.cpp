#include "design_patterns/command.h"
#include <iostream>

namespace design_patterns {
void CommandManager::execute(std::unique_ptr<Command> command) {
    command->execute();
    if (command->isReversible()) {
        historyCommands.push_back(std::move(command));
    }
    redoCommands.clear();
}
void CommandManager::undo() {
    if (historyCommands.size() > 0) {
        auto command = std::move(historyCommands.back());
        historyCommands.pop_back();
        command->unexecute();
        redoCommands.push_back(std::move(command));
    }
}
void CommandManager::redo() {
    if (redoCommands.size() > 0) {
        auto command = std::move(redoCommands.back());
        redoCommands.pop_back();
        command->execute();
        historyCommands.push_back(std::move(command));
    }
}

void ChessGame::move(ChessMove chessMove) {
    std::cout << "In move " << ++m_moveNumber << ", move " << chessMove.piece
              << " from " << chessMove.fromSquare << " to "
              << chessMove.toSquare << '\n';
}
void ChessGame::moveBack(ChessMove chessMove) {
    if (m_moveNumber > 0) {

        std::cout << "Undo move " << m_moveNumber-- << ". Move "
                  << chessMove.piece << " from " << chessMove.toSquare
                  << " back to " << chessMove.fromSquare << '\n';
    }
}

ChessMoveCommand::ChessMoveCommand(ChessGame &chessGame, ChessMove chessMove)
    : m_chessGame(chessGame), m_chessMove(chessMove) {}

void ChessMoveCommand::execute() { m_chessGame.move(m_chessMove); }
void ChessMoveCommand::unexecute() { m_chessGame.moveBack(m_chessMove); }
bool ChessMoveCommand::isReversible() const { return true; };
} // namespace design_patterns