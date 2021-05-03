#include <memory>
#include <string>
#include <vector>

namespace design_patterns {
class Command {
  public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void unexecute() = 0;
    virtual bool isReversible() const = 0;
};

class CommandManager {
  public:
    void execute(std::unique_ptr<Command> command);
    void undo();
    void redo();

  private:
    std::vector<std::unique_ptr<Command>> historyCommands;
    std::vector<std::unique_ptr<Command>> redoCommands;
};

struct ChessMove {
    std::string piece;
    std::string fromSquare;
    std::string toSquare;
};

class ChessGame {
  public:
    void move(ChessMove chessMove);
    void moveBack(ChessMove chessMove);

  private:
    int m_moveNumber{0};
};

class ChessMoveCommand : public Command {
  public:
    ChessMoveCommand(ChessGame &chessGame, ChessMove chessMove);
    void execute() override;
    void unexecute() override;
    bool isReversible() const override;

  private:
    ChessGame &m_chessGame;
    ChessMove m_chessMove;
};
} // namespace design_patterns