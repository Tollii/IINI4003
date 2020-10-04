#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
    enum class Color {
        WHITE,
        BLACK
    };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

        virtual string short_name() const = 0;
    };

    class King : public Piece {
    public:
        explicit King(Color color) : Piece(color) {}

         std::string type() const override {
            return Piece::color_string() + " king";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return (abs(from_x - to_x) <= 1 && abs(from_y - to_y) <= 1);
        }

        string short_name() const override {
            if (color_string() == "white") {
                return "WKi";
            } else {
                return "BKi";
            }
        }


    };

    class Knight : public Piece {
    public:
        explicit Knight(Color color) : Piece(color) {}

        std::string type() const override {
            return Piece::color_string() + " knight";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            bool move_1 = abs(from_x-to_x) == 2 && abs(from_y-to_y) == 1;
            bool move_2 = abs(from_x-to_x) == 1 && abs(from_y-to_y) == 2;
            return (move_1 || move_2);
        }

        string short_name() const override {
            if (color_string() == "white") {
                return "WKn";
            } else {
                return "BKn";
            }
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    // Lambda functions
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &to)> on_remove_piece;
    function<void(const Piece &piece)> on_loss;
    function<void(const Piece &piece, const string &from, const string &to)> on_move_error;
    function<void(const vector<vector<unique_ptr<Piece>>> &squares, size_t grid_length)> after_piece_move;


    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                on_piece_move(*piece_from, from, to);
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        on_remove_piece(*piece_from, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get()))
                            on_loss(*king);
                    } else {
                        // piece in the from square has the same color as the piece in the to square
                        on_move_error(*piece_from, from, to);
                        return false;
                    }
                }
                piece_to = move(piece_from);
                after_piece_move(squares, 8);
                return true;
            } else {
                on_move_error(*piece_from, from, to);
                return false;
            }
        } else {
            cout << "no piece at " << from << endl;
            return false;
        }
    }


};


class ChessBoardPrint {
    ChessBoard &chessboard;
public:
    explicit ChessBoardPrint(ChessBoard &chessboard_) : chessboard(chessboard_) {
      chessboard.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
          cout << piece.type() << " is moving from " << from << " to " << to << endl;
      };

      chessboard.on_remove_piece = [](const ChessBoard::Piece &piece, const string &to) {
          cout << piece.type() << " is removed from " << to << endl;
      };

      chessboard.on_loss = [](const ChessBoard::Piece &piece) {
          cout << piece.color_string() << " lost the game." << endl;
      };

      chessboard.on_move_error = [](const ChessBoard::Piece &piece, const string &from, const string &to) {
          cout << "Could not move " << piece.type() << "from " << from << " to " << to << endl;
      };

      chessboard.after_piece_move = [](const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares, size_t grid_length) {

          cout << "\n\n   ";
          size_t grid_char = 'A';
          for(size_t c = 0; c < grid_length; ++c) {
              cout  << (char)grid_char << "   ";
              grid_char += 1;

          }
          cout << endl;

          for(size_t i = 0; i < grid_length; ++i) {
            for(size_t j = 0; j < grid_length; ++j) {
                cout << "-----";
            }
            cout << endl;
            cout << i + 1;
            for(size_t k = 0; k < grid_length; ++k) {
                auto &piece_from = squares[k][i];
                if (piece_from) {
                    cout <<  "|" << piece_from->short_name();
                } else {
                    cout << "|   ";
                }

                if (k == grid_length - 1) {
                    cout << "|";
                }
            }
            cout << endl;
            if (i == grid_length - 1) {
                for(size_t x = 0; x < grid_length; ++x) {
                    cout << "-----";
                }
                cout << endl;
            }
          }
      };
    };
};


int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}